// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "D3D11InputAssemblerPipelineStage.h"

#include "D3D11Asynchronous.h"
#include "D3D11DepthStencilView.h"
#include "D3D11RenderTargetView.h"
#include "D3D11UnorderedAccessView.h"
#include "D3D11Resource.h"
#include "D3D11Buffer.h"
#include "D3D11SamplerState.h"
#include "D3D11ComputeShader.h"
#include "D3D11ClassInstance.h"
#include "D3D11ShaderResourceView.h"
#include "D3D11DomainShader.h"
#include "D3D11CommandList.h"
#include "D3D11Predicate.h"
#include "D3D11GeometryShader.h"
#include "D3D11HullShader.h"
#include "D3D11InputLayout.h"
#include "D3D11BlendState.h"
#include "D3D11DepthStencilState.h"
#include "D3D11PixelShader.h"
#include "D3D11RasterizerState.h"
#include "D3D11VertexShader.h"

using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D11;

D3DBuffer^ InputAssemblerPipelineStage::GetIndexBuffer([Runtime::InteropServices::Out] Format %outFormat, [Runtime::InteropServices::Out] UInt32 %outOffset)
{
    System::Diagnostics::Debug::Assert(Parent->NativeID3D11DeviceContext != NULL);

    ID3D11Buffer* tempoutIndexBuffer;
    DXGI_FORMAT tempoutFormat;
    UINT tempoutOffset;
    
    Parent->NativeID3D11DeviceContext->IAGetIndexBuffer(&tempoutIndexBuffer, &tempoutFormat, &tempoutOffset);
        
    outFormat = safe_cast<Format>(tempoutFormat);
    outOffset = safe_cast<UInt32>(tempoutOffset);

    return tempoutIndexBuffer == NULL ? nullptr : gcnew D3DBuffer(tempoutIndexBuffer);
}

InputLayout^ InputAssemblerPipelineStage::GetInputLayout()
{
    System::Diagnostics::Debug::Assert(Parent->NativeID3D11DeviceContext != NULL);

    ID3D11InputLayout* tempoutInputLayout;
    Parent->NativeID3D11DeviceContext->IAGetInputLayout(&tempoutInputLayout);

    return tempoutInputLayout == NULL ? nullptr : gcnew InputLayout(tempoutInputLayout);
}

PrimitiveTopology InputAssemblerPipelineStage::GetPrimitiveTopology()
{
    System::Diagnostics::Debug::Assert(Parent->NativeID3D11DeviceContext != NULL);

    D3D11_PRIMITIVE_TOPOLOGY tempoutTopology;
    Parent->NativeID3D11DeviceContext->IAGetPrimitiveTopology(&tempoutTopology);
    
    return safe_cast<PrimitiveTopology>(tempoutTopology);
}

 Collection<D3DBuffer^>^ InputAssemblerPipelineStage::GetVertexBuffers(UInt32 startSlot, UInt32 numBuffers, [Runtime::InteropServices::Out] array<UInt32>^ %outStrides, [Runtime::InteropServices::Out] array<UInt32>^ %outOffsets)
{
    System::Diagnostics::Debug::Assert(Parent->NativeID3D11DeviceContext != NULL);


    vector<ID3D11Buffer*> buffers(numBuffers);
    vector<UInt32> strides(numBuffers);
    vector<UInt32> offsets(numBuffers);

    Parent->NativeID3D11DeviceContext->IAGetVertexBuffers(
        safe_cast<UINT>(startSlot), 
        safe_cast<UINT>(numBuffers), 
        numBuffers > 0 ? &buffers[0] : NULL,
        numBuffers > 0 ? &strides[0] : NULL, 
        numBuffers > 0 ? &offsets[0] : NULL);

    outStrides = gcnew array<UInt32>(numBuffers); 
    outOffsets = gcnew array<UInt32>(numBuffers); 

    if (numBuffers > 0)
    {
        pin_ptr<UINT> pinStrides = &outStrides[0];
        memcpy(pinStrides, &strides[0], sizeof(UINT) * numBuffers);

        pin_ptr<UINT> pinOffsets = &outOffsets[0];
        memcpy(pinOffsets, &offsets[0], sizeof(UINT) * numBuffers);
    }
    
    return GetList<D3DBuffer, ID3D11Buffer>(numBuffers, buffers);
}

void InputAssemblerPipelineStage::SetIndexBuffer(D3DBuffer^ indexBuffer, Format format, UInt32 offset)
{
    System::Diagnostics::Debug::Assert(Parent->NativeID3D11DeviceContext != NULL);
    D3DUtils::CheckNull(indexBuffer, "indexBuffer");

    Parent->NativeID3D11DeviceContext->IASetIndexBuffer(indexBuffer->NativeID3D11Buffer, safe_cast<DXGI_FORMAT>(format), safe_cast<UINT>(offset));

}

void InputAssemblerPipelineStage::SetInputLayout(InputLayout^ inputLayout)
{
    System::Diagnostics::Debug::Assert(Parent->NativeID3D11DeviceContext != NULL);
    D3DUtils::CheckNull(inputLayout, "inputLayout");

    Parent->NativeID3D11DeviceContext->IASetInputLayout(inputLayout->NativeID3D11InputLayout);

}

void InputAssemblerPipelineStage::SetPrimitiveTopology(PrimitiveTopology topology)
{
    System::Diagnostics::Debug::Assert(Parent->NativeID3D11DeviceContext != NULL);

    Parent->NativeID3D11DeviceContext->IASetPrimitiveTopology(safe_cast<D3D11_PRIMITIVE_TOPOLOGY>(topology));

}

void InputAssemblerPipelineStage::SetVertexBuffers(UInt32 startSlot, IEnumerable<D3DBuffer^>^ vertexBuffers, array<UInt32>^ strides, array<UInt32>^ offsets)
{
    System::Diagnostics::Debug::Assert(Parent->NativeID3D11DeviceContext != NULL);
    D3DUtils::CheckNull(vertexBuffers, "vertexBuffers");
    D3DUtils::CheckNull(strides, "strides");
    D3DUtils::CheckNull(offsets, "offsets");

    vector<ID3D11Buffer*> itemsVector;
    UINT count = SetVectorItems<D3DBuffer, ID3D11Buffer>(vertexBuffers, itemsVector);

    if ((count != strides->Length) || (count != offsets->Length))
    {
        throw gcnew InvalidOperationException("Invalid array lengths; vertexBuffers, strides and offsets sizes must be equal.");
    }


    pin_ptr<UINT> stridesArray;
    if (count > 0) 
        stridesArray = &strides[0];

    pin_ptr<UINT> offsetsArray;
    if (count > 0) 
        offsetsArray = &offsets[0];

    Parent->NativeID3D11DeviceContext->IASetVertexBuffers(
        safe_cast<UINT>(startSlot), 
        count, 
        count == 0 ? NULL : &itemsVector[0],
        stridesArray,
        offsetsArray);
}

