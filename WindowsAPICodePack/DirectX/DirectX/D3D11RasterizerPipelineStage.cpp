// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "D3D11RasterizerPipelineStage.h"

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

Collection<D3dRect^>^ RasterizerPipelineStage::GetScissorRects(UInt32 maxNumberOfRects)
{
    System::Diagnostics::Debug::Assert(Parent->NativeID3D11DeviceContext != NULL);

    UINT tempoutNumRects = safe_cast<UINT>(maxNumberOfRects);
    vector<D3D11_RECT> rects(maxNumberOfRects);

    Parent->NativeID3D11DeviceContext->RSGetScissorRects(&tempoutNumRects, &rects[0]);

    Collection<D3dRect^>^ collection = gcnew Collection<D3dRect^>();
    for (UINT i = 0; i < tempoutNumRects; i++)
    {
        collection->Add(gcnew D3dRect(rects[i]));
    }

    return collection;
}

RasterizerState^ RasterizerPipelineStage::GetState()
{
    System::Diagnostics::Debug::Assert(Parent->NativeID3D11DeviceContext != NULL);

    ID3D11RasterizerState* tempoutRasterizerState;
    Parent->NativeID3D11DeviceContext->RSGetState(&tempoutRasterizerState);
    
    return tempoutRasterizerState == NULL ? nullptr : gcnew RasterizerState(tempoutRasterizerState);
}

Collection<Viewport^>^ RasterizerPipelineStage::GetViewports(UInt32 maxNumberOfViewports)
{
    System::Diagnostics::Debug::Assert(Parent->NativeID3D11DeviceContext != NULL);

    UINT numViewports = safe_cast<UINT>(maxNumberOfViewports);
    vector<D3D11_VIEWPORT> viewports(numViewports);

    Parent->NativeID3D11DeviceContext->RSGetViewports(&numViewports, &viewports[0]);

    Collection<Viewport^>^ collection = gcnew Collection<Viewport^>();
    for (UINT i = 0; i < numViewports; i++)
    {
        collection->Add(gcnew Viewport(viewports[i]));
    }

    return collection;
}

void RasterizerPipelineStage::SetScissorRects(IEnumerable<D3dRect^>^ rects)
{
    System::Diagnostics::Debug::Assert(Parent->NativeID3D11DeviceContext != NULL);

    UINT numRects = 0;

    vector<D3D11_RECT> rectsVector(numRects);

    if (rects != nullptr)
    {
        for each (D3dRect^ rect in rects)
        {
            rectsVector.push_back(*(rect->nativeObject.Get()));
        }
    }

    Parent->NativeID3D11DeviceContext->RSSetScissorRects(
        numRects, 
        numRects == 0 ? NULL : &rectsVector[0]);
}

void RasterizerPipelineStage::SetState(RasterizerState^ rasterizerState)
{
    System::Diagnostics::Debug::Assert(Parent->NativeID3D11DeviceContext != NULL);

    Parent->NativeID3D11DeviceContext->RSSetState(
        rasterizerState == nullptr ? NULL : rasterizerState->NativeID3D11RasterizerState);

}

void RasterizerPipelineStage::SetViewports(IEnumerable<Viewport^>^ viewports)
{
    UINT numPorts = 0;

    vector<D3D11_VIEWPORT> portsVector;

    if (viewports != nullptr)
    {
        for each (Viewport^ port in viewports)
        {
            portsVector.push_back(*(port->nativeObject.Get()));
        }
    }

    Parent->NativeID3D11DeviceContext->RSSetViewports(
        numPorts, 
        numPorts == 0 ? NULL : &portsVector[0]);
}

