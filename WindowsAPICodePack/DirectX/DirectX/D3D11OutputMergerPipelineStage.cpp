// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "D3D11OutputMergerPipelineStage.h"

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

BlendState^ OutputMergerPipelineStage::GetBlendState([Runtime::InteropServices::Out] array<Single>^  %outBlendFactor, [Runtime::InteropServices::Out] UInt32 %outSampleMask)
{
    System::Diagnostics::Debug::Assert(Parent->NativeID3D11DeviceContext != NULL);

    ID3D11BlendState* tempoutBlendState;
    UINT tempoutSampleMask;

    vector<FLOAT> tempoutBlendFactor(4);

    Parent->NativeID3D11DeviceContext->OMGetBlendState(&tempoutBlendState, &tempoutBlendFactor[0], &tempoutSampleMask);
    
    outSampleMask = safe_cast<UInt32>(tempoutSampleMask);

    outBlendFactor = gcnew array<Single>(4);
    pin_ptr<FLOAT> blends = &outBlendFactor[0];
    memcpy(blends, &tempoutBlendFactor[0], sizeof(FLOAT) * 4);

    return tempoutBlendState == NULL ? nullptr : gcnew BlendState(tempoutBlendState);

}

DepthStencilState^ OutputMergerPipelineStage::GetDepthStencilState([Runtime::InteropServices::Out] UInt32 %outStencilRef)
{
    System::Diagnostics::Debug::Assert(Parent->NativeID3D11DeviceContext != NULL);

    ID3D11DepthStencilState* tempoutDepthStencilState;
    UINT tempoutStencilRef;

    Parent->NativeID3D11DeviceContext->OMGetDepthStencilState(&tempoutDepthStencilState, &tempoutStencilRef);

    outStencilRef = safe_cast<UInt32>(tempoutStencilRef);

    return tempoutDepthStencilState == NULL ? nullptr : gcnew DepthStencilState(tempoutDepthStencilState);

}

Collection<RenderTargetView^>^ OutputMergerPipelineStage::GetRenderTargets(UInt32 numViews, [Runtime::InteropServices::Out] DepthStencilView^ %outDepthStencilView)
{
    System::Diagnostics::Debug::Assert(Parent->NativeID3D11DeviceContext != NULL);

    vector<ID3D11RenderTargetView*> tempoutRenderTargetViews(numViews);
    ID3D11DepthStencilView* tempoutDepthStencilView;
    
    Parent->NativeID3D11DeviceContext->OMGetRenderTargets(safe_cast<UINT>(numViews), &tempoutRenderTargetViews[0], &tempoutDepthStencilView);
    
    outDepthStencilView = tempoutDepthStencilView == NULL ? nullptr : gcnew DepthStencilView(tempoutDepthStencilView);

    return GetList<RenderTargetView, ID3D11RenderTargetView>(numViews, tempoutRenderTargetViews);
}

Collection<RenderTargetView^>^ OutputMergerPipelineStage::GetRenderTargets(UInt32 numViews)
{
    System::Diagnostics::Debug::Assert(Parent->NativeID3D11DeviceContext != NULL);

    vector<ID3D11RenderTargetView*> tempoutRenderTargetViews(numViews);
    
    Parent->NativeID3D11DeviceContext->OMGetRenderTargets(safe_cast<UINT>(numViews), &tempoutRenderTargetViews[0], NULL);
    
    return GetList<RenderTargetView, ID3D11RenderTargetView>(numViews, tempoutRenderTargetViews);
}

 DepthStencilView^ OutputMergerPipelineStage::GetDepthStencilView()
{
    System::Diagnostics::Debug::Assert(Parent->NativeID3D11DeviceContext != NULL);

    ID3D11DepthStencilView* tempoutDepthStencilView;
    
    Parent->NativeID3D11DeviceContext->OMGetRenderTargets(0, NULL, &tempoutDepthStencilView);
    
    return tempoutDepthStencilView == NULL ? nullptr : gcnew DepthStencilView(tempoutDepthStencilView);
}

Collection<RenderTargetView^>^ OutputMergerPipelineStage::GetRenderTargetsAndUnorderedAccessViews(
    UInt32 numViews, [Runtime::InteropServices::Out] DepthStencilView^ %outDepthStencilView, UInt32 UAVstartSlot, UInt32 numUAVs, [Runtime::InteropServices::Out] Collection<UnorderedAccessView^>^ %outUnorderedAccessViews)
{
    System::Diagnostics::Debug::Assert(Parent->NativeID3D11DeviceContext != NULL);

    vector<ID3D11RenderTargetView*> tempoutRenderTargetViews(numViews);
    ID3D11DepthStencilView* tempoutDepthStencilView;
    vector<ID3D11UnorderedAccessView*> tempoutUnorderedAccessView(numUAVs);
    
    Parent->NativeID3D11DeviceContext->OMGetRenderTargetsAndUnorderedAccessViews(
        safe_cast<UINT>(numViews), &tempoutRenderTargetViews[0], &tempoutDepthStencilView,
        safe_cast<UINT>(UAVstartSlot), safe_cast<UINT>(numUAVs), &tempoutUnorderedAccessView[0]);
    
    outDepthStencilView = tempoutDepthStencilView == NULL ? nullptr : gcnew DepthStencilView(tempoutDepthStencilView);
    
    outUnorderedAccessViews = GetList<UnorderedAccessView, ID3D11UnorderedAccessView>(numUAVs, tempoutUnorderedAccessView);

    return GetList<RenderTargetView, ID3D11RenderTargetView>(numViews, tempoutRenderTargetViews);
}

Collection<UnorderedAccessView^>^ OutputMergerPipelineStage::GetUnorderedAccessViews(UInt32 UAVstartSlot, UInt32 numUAVs)
{
    System::Diagnostics::Debug::Assert(Parent->NativeID3D11DeviceContext != NULL);

    vector<ID3D11UnorderedAccessView*> tempoutUnorderedAccessView(numUAVs);
    
    Parent->NativeID3D11DeviceContext->OMGetRenderTargetsAndUnorderedAccessViews(
        0, NULL, NULL,
        safe_cast<UINT>(UAVstartSlot), safe_cast<UINT>(numUAVs), &tempoutUnorderedAccessView[0]);
    
    return GetList<UnorderedAccessView, ID3D11UnorderedAccessView>(numUAVs, tempoutUnorderedAccessView);
}

void OutputMergerPipelineStage::SetBlendState(BlendState^ blendState, array<Single>^ blendFactor, UInt32 SampleMask)
{
    System::Diagnostics::Debug::Assert(Parent->NativeID3D11DeviceContext != NULL);
    D3DUtils::CheckNull(blendState, "blendState");
    D3DUtils::CheckNull(blendFactor, "blendFactor");
    if (blendFactor->Length != 4)
    {
        throw gcnew ArgumentException("Length of blendFactor must be 4 (for each RGBA component).", "blendFactor");
    }

    pin_ptr<FLOAT> belndAarray = &blendFactor[0];

    Parent->NativeID3D11DeviceContext->OMSetBlendState(
        blendState->NativeID3D11BlendState, 
        belndAarray, 
        safe_cast<UINT>(SampleMask));
}

void OutputMergerPipelineStage::SetDepthStencilState(DepthStencilState^ depthStencilState, UInt32 stencilRef)
{
    System::Diagnostics::Debug::Assert(Parent->NativeID3D11DeviceContext != NULL);
    D3DUtils::CheckNull(depthStencilState, "depthStencilState");

    Parent->NativeID3D11DeviceContext->OMSetDepthStencilState(depthStencilState->NativeID3D11DepthStencilState, safe_cast<UINT>(stencilRef));
}

void OutputMergerPipelineStage::SetRenderTargets(IEnumerable<RenderTargetView^>^ renderTargetViews, DepthStencilView^ depthStencilView)
{
    System::Diagnostics::Debug::Assert(Parent->NativeID3D11DeviceContext != NULL);

    vector<ID3D11RenderTargetView*> itemsVector;

    UINT count = SetVectorItems<RenderTargetView, ID3D11RenderTargetView>(renderTargetViews, itemsVector);

    Parent->NativeID3D11DeviceContext->OMSetRenderTargets(
        count, 
        count == 0 ? NULL : &itemsVector[0], 
        depthStencilView == nullptr ? NULL : depthStencilView->NativeID3D11DepthStencilView);

}

void OutputMergerPipelineStage::SetRenderTargetsAndUnorderedAccessViews(
    IEnumerable<RenderTargetView^>^ renderTargetViews, DepthStencilView^ depthStencilView, UInt32 UAVstartSlot, 
    IEnumerable<UnorderedAccessView^>^ unorderedAccessViews, array<UInt32>^ UAVInitialCounts)
{
    System::Diagnostics::Debug::Assert(Parent->NativeID3D11DeviceContext != NULL);

    if ((unorderedAccessViews != nullptr && UAVInitialCounts == nullptr) || 
        (unorderedAccessViews == nullptr && UAVInitialCounts != nullptr))
    {
        throw gcnew InvalidOperationException("Both unorderedAccessViews and UAVInitialCounts must be set together. Neither one can be null if the other is not null.");        
    }
    

    vector<ID3D11RenderTargetView*> itemsVector;
    UINT count = SetVectorItems<RenderTargetView, ID3D11RenderTargetView>(renderTargetViews, itemsVector);

    if (unorderedAccessViews != nullptr && (count != UAVInitialCounts->Length))
    {
        throw gcnew InvalidOperationException("Both unorderedAccessViews and UAVInitialCounts sizes must be equal.");
    }
    vector<ID3D11UnorderedAccessView*> UAVVector;
    UINT UAVcount = SetVectorItems<UnorderedAccessView, ID3D11UnorderedAccessView>(unorderedAccessViews, UAVVector);

    pin_ptr<UINT> countArray;
    if (UAVcount > 0) 
        countArray = &UAVInitialCounts[0];

    Parent->NativeID3D11DeviceContext->OMSetRenderTargetsAndUnorderedAccessViews(
        count, 
        count == 0 ? NULL : &itemsVector[0], 
        depthStencilView == nullptr ? NULL : depthStencilView->NativeID3D11DepthStencilView,
        safe_cast<UINT>(UAVstartSlot), 
        UAVcount,
        UAVcount == 0 ? NULL : &UAVVector[0],
        countArray);
}

