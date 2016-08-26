// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "D3D11GeometryShaderPipelineStage.h"

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

Collection<D3DBuffer^>^ GeometryShaderPipelineStage::GetConstantBuffers(UInt32 startSlot, UInt32 numBuffers)
{
    System::Diagnostics::Debug::Assert( Parent->NativeID3D11DeviceContext != NULL);

    vector<ID3D11Buffer*> tempoutConstantBuffers(numBuffers);
    Parent->NativeID3D11DeviceContext->GSGetConstantBuffers(safe_cast<UINT>(startSlot), safe_cast<UINT>(numBuffers), &tempoutConstantBuffers[0]);
        
    return GetList<D3DBuffer, ID3D11Buffer>(numBuffers, tempoutConstantBuffers);
}

Collection<SamplerState^>^ GeometryShaderPipelineStage::GetSamplers(UInt32 startSlot, UInt32 numSamplers)
{
    System::Diagnostics::Debug::Assert( Parent->NativeID3D11DeviceContext != NULL);

    vector<ID3D11SamplerState*> tempoutSamplers(numSamplers);
    Parent->NativeID3D11DeviceContext->GSGetSamplers(safe_cast<UINT>(startSlot), safe_cast<UINT>(numSamplers), &tempoutSamplers[0]);

    return GetList<SamplerState, ID3D11SamplerState>(numSamplers, tempoutSamplers);
}

GeometryShader^ GeometryShaderPipelineStage::GetShader(UInt32 numClassInstances, [Runtime::InteropServices::Out] Collection<ClassInstance^>^ %outClassInstances)
{
    System::Diagnostics::Debug::Assert(Parent->NativeID3D11DeviceContext != NULL);

    ID3D11GeometryShader* tempShader = NULL;

    UINT tempoutNumClassInstances = safe_cast<UINT>(numClassInstances);
    vector<ID3D11ClassInstance*> tempoutClassInstances(numClassInstances); 

    Parent->NativeID3D11DeviceContext->GSGetShader(
        &tempShader, 
        numClassInstances == 0 ? NULL : &(tempoutClassInstances[0]), 
        &tempoutNumClassInstances);

    outClassInstances = GetList<ClassInstance, ID3D11ClassInstance>(
        tempoutNumClassInstances, tempoutClassInstances);

    return tempShader == NULL ? nullptr : gcnew GeometryShader(tempShader);
}

Collection<ShaderResourceView^>^ GeometryShaderPipelineStage::GetShaderResources(UInt32 startSlot, UInt32 numViews)
{
    System::Diagnostics::Debug::Assert( Parent->NativeID3D11DeviceContext != NULL);

    vector <ID3D11ShaderResourceView*> tempoutShaderResourceViews(numViews);
    Parent->NativeID3D11DeviceContext->GSGetShaderResources(safe_cast<UINT>(startSlot), safe_cast<UINT>(numViews), &tempoutShaderResourceViews[0]);
    
    return GetList<ShaderResourceView, ID3D11ShaderResourceView>(numViews, tempoutShaderResourceViews);
}

void GeometryShaderPipelineStage::SetConstantBuffers(UInt32 startSlot, IEnumerable<D3DBuffer^>^ constantBuffers)
{
    System::Diagnostics::Debug::Assert(Parent->NativeID3D11DeviceContext != NULL);
    D3DUtils::CheckNull(constantBuffers, "constantBuffers");

    vector<ID3D11Buffer*> itemsVector;

    UINT count = SetVectorItems<D3DBuffer, ID3D11Buffer>(constantBuffers, itemsVector);

    Parent->NativeID3D11DeviceContext->GSSetConstantBuffers(
        safe_cast<UINT>(startSlot), 
        count, 
        count == 0 ? NULL : &(itemsVector[0]));
}

void GeometryShaderPipelineStage::SetSamplers(UInt32 startSlot, IEnumerable<SamplerState^>^ samplers)
{
    System::Diagnostics::Debug::Assert(Parent->NativeID3D11DeviceContext != NULL);
    D3DUtils::CheckNull(samplers, "samplers");

    vector<ID3D11SamplerState*> itemsVector;

    UINT count = SetVectorItems<SamplerState, ID3D11SamplerState>(samplers, itemsVector);

    Parent->NativeID3D11DeviceContext->GSSetSamplers(
        safe_cast<UINT>(startSlot), 
        count, 
        count == 0 ? NULL : &(itemsVector[0]));
}

void GeometryShaderPipelineStage::SetShader(GeometryShader^ shader, IEnumerable<ClassInstance^>^ classInstances)
{
    System::Diagnostics::Debug::Assert(Parent->NativeID3D11DeviceContext != NULL);

    vector<ID3D11ClassInstance*> classInstancesVector;

    UINT count = SetVectorItems<ClassInstance,ID3D11ClassInstance>(classInstances, classInstancesVector);

    Parent->NativeID3D11DeviceContext->GSSetShader(
        shader == nullptr ? NULL : shader->NativeID3D11GeometryShader, 
        count == 0 ? NULL : &(classInstancesVector[0]), 
        count);
}

void GeometryShaderPipelineStage::SetShaderResources(UInt32 startSlot, IEnumerable<ShaderResourceView^>^ shaderResourceViews)
{
    System::Diagnostics::Debug::Assert(Parent->NativeID3D11DeviceContext != NULL);
    D3DUtils::CheckNull(shaderResourceViews, "shaderResourceViews");

    vector<ID3D11ShaderResourceView*> itemsVector;

    UINT count = SetVectorItems<ShaderResourceView, ID3D11ShaderResourceView>(shaderResourceViews, itemsVector);

    Parent->NativeID3D11DeviceContext->GSSetShaderResources(
        safe_cast<UINT>(startSlot), 
        count, 
        count == 0 ? NULL : &(itemsVector[0]));
}

