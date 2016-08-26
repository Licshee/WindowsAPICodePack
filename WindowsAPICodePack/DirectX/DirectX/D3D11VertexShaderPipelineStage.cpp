// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "D3D11VertexShaderPipelineStage.h"

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

#include <vector>
using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D11;

Collection<D3DBuffer^>^ VertexShaderPipelineStage::GetConstantBuffers(UInt32 startSlot, UInt32 numBuffers)
{
    System::Diagnostics::Debug::Assert( Parent->NativeID3D11DeviceContext != NULL);

    vector<ID3D11Buffer*> items(numBuffers);

    Parent->NativeID3D11DeviceContext->VSGetConstantBuffers(safe_cast<UINT>(startSlot), safe_cast<UINT>(numBuffers), &(items[0]));

    return GetList<D3DBuffer, ID3D11Buffer>(numBuffers, items);
}

Collection<SamplerState^>^ VertexShaderPipelineStage::GetSamplers(UInt32 startSlot, UInt32 numSamplers)
{
    System::Diagnostics::Debug::Assert( Parent->NativeID3D11DeviceContext != NULL);

    vector<ID3D11SamplerState*> samplersVector(numSamplers);
    Parent->NativeID3D11DeviceContext->VSGetSamplers(safe_cast<UINT>(startSlot), safe_cast<UINT>(numSamplers), &samplersVector[0]);

    return GetList<SamplerState, ID3D11SamplerState>(numSamplers, samplersVector);
}

VertexShader^ VertexShaderPipelineStage::GetShader(UInt32 numClassInstances, [Runtime::InteropServices::Out] Collection<ClassInstance^>^ %outClassInstances)
{
    System::Diagnostics::Debug::Assert(Parent->NativeID3D11DeviceContext != NULL);

    ID3D11VertexShader* tempShader = NULL;

    UINT tempoutNumClassInstances = safe_cast<UINT>(numClassInstances);
    vector<ID3D11ClassInstance*> tempoutClassInstances(numClassInstances); 

    Parent->NativeID3D11DeviceContext->VSGetShader(
        &tempShader, 
        numClassInstances == 0 ? NULL : &(tempoutClassInstances[0]), 
        &tempoutNumClassInstances);

    outClassInstances = GetList<ClassInstance, ID3D11ClassInstance>(
        tempoutNumClassInstances, tempoutClassInstances);

    return tempShader == NULL ? nullptr : gcnew VertexShader(tempShader);
}

Collection<ShaderResourceView^>^ VertexShaderPipelineStage::GetShaderResources(UInt32 startSlot, UInt32 numViews)
{
    System::Diagnostics::Debug::Assert( Parent->NativeID3D11DeviceContext != NULL);

    vector<ID3D11ShaderResourceView*> tempoutShaderResourceViews(numViews);
    Parent->NativeID3D11DeviceContext->VSGetShaderResources(safe_cast<UINT>(startSlot), safe_cast<UINT>(numViews), &tempoutShaderResourceViews[0]);
    
    return GetList<ShaderResourceView, ID3D11ShaderResourceView>(numViews, tempoutShaderResourceViews);
}

void VertexShaderPipelineStage::SetConstantBuffers(UInt32 startSlot, IEnumerable<D3DBuffer^>^ constantBuffers)
{
    System::Diagnostics::Debug::Assert(Parent->NativeID3D11DeviceContext != NULL);
    D3DUtils::CheckNull(constantBuffers, "constantBuffers");

    vector<ID3D11Buffer*> itemsVector;

    UINT count = SetVectorItems<D3DBuffer, ID3D11Buffer>(constantBuffers, itemsVector);

    Parent->NativeID3D11DeviceContext->VSSetConstantBuffers(
        safe_cast<UINT>(startSlot), 
        count, 
        count == 0 ? NULL : &(itemsVector[0]));
}

void VertexShaderPipelineStage::SetSamplers(UInt32 startSlot, IEnumerable<SamplerState^>^ samplers)
{
    System::Diagnostics::Debug::Assert(Parent->NativeID3D11DeviceContext != NULL);
    D3DUtils::CheckNull(samplers, "samplers");

    vector<ID3D11SamplerState*> itemsVector;

    UINT count = SetVectorItems<SamplerState, ID3D11SamplerState>(samplers, itemsVector);

    Parent->NativeID3D11DeviceContext->VSSetSamplers(
        safe_cast<UINT>(startSlot), 
        count, 
        count == 0 ? NULL : &(itemsVector[0]));
}


void VertexShaderPipelineStage::SetShader(VertexShader^ shader, IEnumerable<ClassInstance^>^ classInstances)
{
    System::Diagnostics::Debug::Assert(Parent->NativeID3D11DeviceContext != NULL);

    vector<ID3D11ClassInstance*> classInstancesVector;

    UINT count = SetVectorItems<ClassInstance,ID3D11ClassInstance>(classInstances, classInstancesVector);

    Parent->NativeID3D11DeviceContext->VSSetShader(
        shader == nullptr ? NULL : shader->NativeID3D11VertexShader, 
        count == 0 ? NULL : &(classInstancesVector[0]), 
        count);
}

void VertexShaderPipelineStage::SetShaderResources(UInt32 startSlot, IEnumerable<ShaderResourceView^>^ shaderResourceViews)
{
    System::Diagnostics::Debug::Assert(Parent->NativeID3D11DeviceContext != NULL);
    D3DUtils::CheckNull(shaderResourceViews, "shaderResourceViews");

    vector<ID3D11ShaderResourceView*> itemsVector;

    UINT count = SetVectorItems<ShaderResourceView, ID3D11ShaderResourceView>(shaderResourceViews, itemsVector);

    Parent->NativeID3D11DeviceContext->VSSetShaderResources(
        safe_cast<UINT>(startSlot), 
        count, 
        count == 0 ? NULL : &(itemsVector[0]));
}
