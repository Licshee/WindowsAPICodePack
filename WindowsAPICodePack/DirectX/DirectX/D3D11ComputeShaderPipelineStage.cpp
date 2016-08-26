// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "D3D11ComputeShaderPipelineStage.h"

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

Collection<SamplerState^>^ ComputeShaderPipelineStage::GetSamplers(UInt32 startSlot, UInt32 numSamplers)
{
    System::Diagnostics::Debug::Assert( Parent->NativeID3D11DeviceContext != NULL);

    vector<ID3D11SamplerState*> tempoutSamplers(numSamplers);
    Parent->NativeID3D11DeviceContext->CSGetSamplers(safe_cast<UINT>(startSlot), safe_cast<UINT>(numSamplers), &tempoutSamplers[0]);

    return GetList<SamplerState, ID3D11SamplerState>(numSamplers, tempoutSamplers);
}

void ComputeShaderPipelineStage::SetSamplers(UInt32 startSlot, IEnumerable<SamplerState^>^ samplers)
{
    System::Diagnostics::Debug::Assert(Parent->NativeID3D11DeviceContext != NULL);
    D3DUtils::CheckNull(samplers, "samplers");

    vector<ID3D11SamplerState*> itemsVector;

    UINT count = SetVectorItems<SamplerState, ID3D11SamplerState>(samplers, itemsVector);

    Parent->NativeID3D11DeviceContext->CSSetSamplers(
        safe_cast<UINT>(startSlot), 
        count, 
        count == 0 ? NULL : &(itemsVector[0]));
}

Collection<D3DBuffer^>^ ComputeShaderPipelineStage::GetConstantBuffers(UInt32 startSlot, UInt32 numBuffers)
{
    System::Diagnostics::Debug::Assert( Parent->NativeID3D11DeviceContext != NULL);

    vector<ID3D11Buffer*> tempoutConstantBuffers(numBuffers);
    Parent->NativeID3D11DeviceContext->CSGetConstantBuffers(safe_cast<UINT>(startSlot), safe_cast<UINT>(numBuffers), &tempoutConstantBuffers[0]);
        
    return GetList<D3DBuffer, ID3D11Buffer>(numBuffers, tempoutConstantBuffers);
}

void ComputeShaderPipelineStage::SetConstantBuffers(UInt32 startSlot, IEnumerable<D3DBuffer^>^ constantBuffers)
{
    System::Diagnostics::Debug::Assert(Parent->NativeID3D11DeviceContext != NULL);
    D3DUtils::CheckNull(constantBuffers, "constantBuffers");

    vector<ID3D11Buffer*> itemsVector;

    UINT count = SetVectorItems<D3DBuffer, ID3D11Buffer>(constantBuffers, itemsVector);

    Parent->NativeID3D11DeviceContext->CSSetConstantBuffers(
        safe_cast<UINT>(startSlot), 
        count, 
        count == 0 ? NULL : &(itemsVector[0]));
}

ComputeShader^ ComputeShaderPipelineStage::GetShader(UInt32 numClassInstances, [Runtime::InteropServices::Out] Collection<ClassInstance^>^ %outClassInstances)
{
    System::Diagnostics::Debug::Assert(Parent->NativeID3D11DeviceContext != NULL);

    ID3D11ComputeShader* tempoutComputeShader = NULL;

    UINT tempoutNumClassInstances = safe_cast<UINT>(numClassInstances);
    vector<ID3D11ClassInstance*> tempoutClassInstances(numClassInstances); 

    Parent->NativeID3D11DeviceContext->CSGetShader(&tempoutComputeShader, &(tempoutClassInstances[0]), &tempoutNumClassInstances);

    outClassInstances = GetList<ClassInstance, ID3D11ClassInstance>(tempoutNumClassInstances, tempoutClassInstances);

    return tempoutComputeShader == NULL ? nullptr : gcnew ComputeShader(tempoutComputeShader);
}

void ComputeShaderPipelineStage::SetShader(ComputeShader^ shader, IEnumerable<ClassInstance^>^ classInstances)
{
    System::Diagnostics::Debug::Assert(Parent->NativeID3D11DeviceContext != NULL);

    vector<ID3D11ClassInstance*> classInstancesVector;

    UINT count = SetVectorItems<ClassInstance,ID3D11ClassInstance>(classInstances, classInstancesVector);

    Parent->NativeID3D11DeviceContext->CSSetShader(
        shader == nullptr ? NULL : shader->NativeID3D11ComputeShader, 
        count == 0 ? NULL : &(classInstancesVector[0]), 
        count);
}

Collection<ShaderResourceView^>^ ComputeShaderPipelineStage::GetShaderResources(UInt32 startSlot, UInt32 numViews)
{
    System::Diagnostics::Debug::Assert( Parent->NativeID3D11DeviceContext != NULL);

    vector<ID3D11ShaderResourceView*> tempoutShaderResourceViews(numViews);
    Parent->NativeID3D11DeviceContext->CSGetShaderResources(safe_cast<UINT>(startSlot), safe_cast<UINT>(numViews), &tempoutShaderResourceViews[0]);
    
    return GetList<ShaderResourceView, ID3D11ShaderResourceView>(numViews, tempoutShaderResourceViews);
}

void ComputeShaderPipelineStage::SetShaderResources(UInt32 startSlot, IEnumerable<ShaderResourceView^>^ shaderResourceViews)
{
    System::Diagnostics::Debug::Assert(Parent->NativeID3D11DeviceContext != NULL);
    D3DUtils::CheckNull(shaderResourceViews, "shaderResourceViews");

    vector<ID3D11ShaderResourceView*> itemsVector;

    UINT count = SetVectorItems<ShaderResourceView, ID3D11ShaderResourceView>(shaderResourceViews, itemsVector);

    Parent->NativeID3D11DeviceContext->CSSetShaderResources(
        safe_cast<UINT>(startSlot), 
        count, 
        count == 0 ? NULL : &(itemsVector[0]));
}

Collection<UnorderedAccessView^>^ ComputeShaderPipelineStage::GetUnorderedAccessViews(UInt32 startSlot, UInt32 numUAVs)
{
    System::Diagnostics::Debug::Assert( Parent->NativeID3D11DeviceContext != NULL);

    vector<ID3D11UnorderedAccessView*> views(numUAVs);

    Parent->NativeID3D11DeviceContext->CSGetUnorderedAccessViews(
        safe_cast<UINT>(startSlot), safe_cast<UINT>(numUAVs), &views[0]);
    
    return GetList<UnorderedAccessView, ID3D11UnorderedAccessView>(numUAVs, views);
}

void ComputeShaderPipelineStage::SetUnorderedAccessViews(UInt32 startSlot, IEnumerable<UnorderedAccessView^>^ unorderedAccessViews, array<UInt32>^ initialCounts)
{
    System::Diagnostics::Debug::Assert(Parent->NativeID3D11DeviceContext != NULL);

    D3DUtils::CheckNull(unorderedAccessViews, "unorderedAccessViews");
    D3DUtils::CheckNull(initialCounts, "initialCounts");

    vector<ID3D11UnorderedAccessView*> itemsVector;
    UINT count = SetVectorItems<UnorderedAccessView, ID3D11UnorderedAccessView>(unorderedAccessViews, itemsVector);

    if (count != initialCounts->Length)
    {
        throw gcnew InvalidOperationException("Both unorderedAccessViews and initialCounts sizes must be equal.");
    }

    pin_ptr<UINT> countArray;
    if (count > 0) 
        countArray = &initialCounts[0];

    Parent->NativeID3D11DeviceContext->CSSetUnorderedAccessViews(
        safe_cast<UINT>(startSlot), 
        count, 
        count == 0 ? NULL : &itemsVector[0],
        countArray);

}
