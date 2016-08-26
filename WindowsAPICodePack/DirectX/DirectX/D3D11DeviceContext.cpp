// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "D3D11DeviceContext.h"

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

#include "D3D11ComputeShaderPipelineStage.h"
#include "D3D11DomainShaderPipelineStage.h"
#include "D3D11GeometryShaderPipelineStage.h"
#include "D3D11HullShaderPipelineStage.h"
#include "D3D11InputAssemblerPipelineStage.h"
#include "D3D11OutputMergerPipelineStage.h"
#include "D3D11PixelShaderPipelineStage.h"
#include "D3D11RasterizerPipelineStage.h"
#include "D3D11StreamOutputPipelineStage.h"
#include "D3D11VertexShaderPipelineStage.h"

using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D11;

void DeviceContext::Begin(Asynchronous^ asyncData)
{
    System::Diagnostics::Debug::Assert(NativeID3D11DeviceContext != NULL);

    NativeID3D11DeviceContext->Begin(asyncData->NativeID3D11Asynchronous);
}

void DeviceContext::ClearDepthStencilView(DepthStencilView^ depthStencilView, ClearFlag clearFlags, Single depth, Byte stencil)
{
    System::Diagnostics::Debug::Assert(NativeID3D11DeviceContext != NULL);

    NativeID3D11DeviceContext->ClearDepthStencilView(depthStencilView->NativeID3D11DepthStencilView, safe_cast<UINT>(clearFlags), safe_cast<FLOAT>(depth), safe_cast<UINT8>(stencil));
}

void DeviceContext::ClearRenderTargetView(RenderTargetView^ renderTargetView, ColorRGBA^ colorRGBA)
{
    System::Diagnostics::Debug::Assert(NativeID3D11DeviceContext != NULL);

    NativeID3D11DeviceContext->ClearRenderTargetView(renderTargetView->NativeID3D11RenderTargetView, colorRGBA->nativeObject.Get());
}

void DeviceContext::ClearState()
{
    System::Diagnostics::Debug::Assert(NativeID3D11DeviceContext != NULL);

    NativeID3D11DeviceContext->ClearState();

}

void DeviceContext::ClearUnorderedAccessViewFloat(UnorderedAccessView^ unorderedAccessView, array<Single>^ values)
{
    System::Diagnostics::Debug::Assert(NativeID3D11DeviceContext != NULL);

    if (values == nullptr)
    {
        throw gcnew ArgumentNullException("values");
    }
    if (values->Length != 4)
    {
        throw gcnew ArgumentOutOfRangeException("values", "Array length must be 4.");
    }

    pin_ptr<FLOAT> arr = &values[0];

    NativeID3D11DeviceContext->ClearUnorderedAccessViewFloat(unorderedAccessView->NativeID3D11UnorderedAccessView, arr);

}

void DeviceContext::ClearUnorderedAccessViewUint(UnorderedAccessView^ unorderedAccessView, array<UInt32>^ values)
{
    System::Diagnostics::Debug::Assert(NativeID3D11DeviceContext != NULL);

    if (values == nullptr)
    {
        throw gcnew ArgumentNullException("values");
    }
    if (values->Length != 4)
    {
        throw gcnew ArgumentOutOfRangeException("values", "Array length must be 4.");
    }

    pin_ptr<UINT> arr = &values[0];

    NativeID3D11DeviceContext->ClearUnorderedAccessViewUint(unorderedAccessView->NativeID3D11UnorderedAccessView, arr);

}

void DeviceContext::CopyResource(D3DResource^ destinationResource, D3DResource^ sourceResource)
{
    System::Diagnostics::Debug::Assert(NativeID3D11DeviceContext != NULL);

    NativeID3D11DeviceContext->CopyResource(destinationResource->NativeID3D11Resource, sourceResource->NativeID3D11Resource);
}

void DeviceContext::CopySubresourceRegion(D3DResource^ destinationResource, UInt32 destinationSubresource, UInt32 DstX, UInt32 DstY, UInt32 DstZ, D3DResource^ sourceResource, UInt32 sourceSubresource, Box^ SrcBox)
{
    System::Diagnostics::Debug::Assert(NativeID3D11DeviceContext != NULL);

    NativeID3D11DeviceContext->CopySubresourceRegion(destinationResource->NativeID3D11Resource, safe_cast<UINT>(destinationSubresource), safe_cast<UINT>(DstX), safe_cast<UINT>(DstY), safe_cast<UINT>(DstZ), sourceResource->NativeID3D11Resource, safe_cast<UINT>(sourceSubresource), SrcBox->nativeObject.Get());
}

void DeviceContext::Dispatch(UInt32 threadGroupCountX, UInt32 threadGroupCountY, UInt32 threadGroupCountZ)
{
    System::Diagnostics::Debug::Assert(NativeID3D11DeviceContext != NULL);

    NativeID3D11DeviceContext->Dispatch(safe_cast<UINT>(threadGroupCountX), safe_cast<UINT>(threadGroupCountY), safe_cast<UINT>(threadGroupCountZ));
}

void DeviceContext::DispatchIndirect(D3DBuffer^ bufferForArgs, UInt32 alignedOffsetForArgs)
{
    System::Diagnostics::Debug::Assert(NativeID3D11DeviceContext != NULL);

    NativeID3D11DeviceContext->DispatchIndirect(bufferForArgs->NativeID3D11Buffer, safe_cast<UINT>(alignedOffsetForArgs));
}

void DeviceContext::Draw(UInt32 vertexCount, UInt32 startVertexLocation)
{
    System::Diagnostics::Debug::Assert(NativeID3D11DeviceContext != NULL);

    NativeID3D11DeviceContext->Draw(safe_cast<UINT>(vertexCount), safe_cast<UINT>(startVertexLocation));
}

void DeviceContext::DrawAuto()
{
    System::Diagnostics::Debug::Assert(NativeID3D11DeviceContext != NULL);

    NativeID3D11DeviceContext->DrawAuto();
}

void DeviceContext::DrawIndexed(UInt32 indexCount, UInt32 startIndexLocation, Int32 baseVertexLocation)
{
    System::Diagnostics::Debug::Assert(NativeID3D11DeviceContext != NULL);

    NativeID3D11DeviceContext->DrawIndexed(safe_cast<UINT>(indexCount), safe_cast<UINT>(startIndexLocation), safe_cast<INT>(baseVertexLocation));
}

void DeviceContext::DrawIndexedInstanced(UInt32 IndexCountPerInstance, UInt32 InstanceCount, UInt32 StartIndexLocation, Int32 BaseVertexLocation, UInt32 StartInstanceLocation)
{
    System::Diagnostics::Debug::Assert(NativeID3D11DeviceContext != NULL);

    NativeID3D11DeviceContext->DrawIndexedInstanced(safe_cast<UINT>(IndexCountPerInstance), safe_cast<UINT>(InstanceCount), safe_cast<UINT>(StartIndexLocation), safe_cast<INT>(BaseVertexLocation), safe_cast<UINT>(StartInstanceLocation));

}

void DeviceContext::DrawIndexedInstancedIndirect(D3DBuffer^ BufferForArgs, UInt32 AlignedByteOffsetForArgs)
{
    System::Diagnostics::Debug::Assert(NativeID3D11DeviceContext != NULL);

    NativeID3D11DeviceContext->DrawIndexedInstancedIndirect(BufferForArgs->NativeID3D11Buffer, safe_cast<UINT>(AlignedByteOffsetForArgs));

}

void DeviceContext::DrawInstanced(UInt32 VertexCountPerInstance, UInt32 InstanceCount, UInt32 StartVertexLocation, UInt32 StartInstanceLocation)
{
    System::Diagnostics::Debug::Assert(NativeID3D11DeviceContext != NULL);

    NativeID3D11DeviceContext->DrawInstanced(safe_cast<UINT>(VertexCountPerInstance), safe_cast<UINT>(InstanceCount), safe_cast<UINT>(StartVertexLocation), safe_cast<UINT>(StartInstanceLocation));

}

void DeviceContext::DrawInstancedIndirect(D3DBuffer^ BufferForArgs, UInt32 AlignedByteOffsetForArgs)
{
    System::Diagnostics::Debug::Assert(NativeID3D11DeviceContext != NULL);

    NativeID3D11DeviceContext->DrawInstancedIndirect(BufferForArgs->NativeID3D11Buffer, safe_cast<UINT>(AlignedByteOffsetForArgs));

}

void DeviceContext::End(Asynchronous^ Async)
{
    System::Diagnostics::Debug::Assert(NativeID3D11DeviceContext != NULL);

    NativeID3D11DeviceContext->End(Async->NativeID3D11Asynchronous);

}

void DeviceContext::ExecuteCommandList(CommandList^ _CommandList, Boolean RestoreContextState)
{
    System::Diagnostics::Debug::Assert(NativeID3D11DeviceContext != NULL);

    NativeID3D11DeviceContext->ExecuteCommandList(_CommandList->NativeID3D11CommandList, safe_cast<BOOL>(RestoreContextState));

}

void DeviceContext::FinishCommandList(Boolean RestoreDeferredContextState, [Runtime::InteropServices::Out] CommandList^ %outCommandList)
{
    System::Diagnostics::Debug::Assert(NativeID3D11DeviceContext != NULL);

    ID3D11CommandList* tempoutCommandList;
    D3DUtils::VerifyResult(NativeID3D11DeviceContext->FinishCommandList(safe_cast<BOOL>(RestoreDeferredContextState), &tempoutCommandList));
    outCommandList = gcnew CommandList(tempoutCommandList);

}

void DeviceContext::Flush()
{
    System::Diagnostics::Debug::Assert(NativeID3D11DeviceContext != NULL);

    NativeID3D11DeviceContext->Flush();

}

void DeviceContext::GenerateMips(ShaderResourceView^ shaderResourceView)
{
    System::Diagnostics::Debug::Assert(NativeID3D11DeviceContext != NULL);

    NativeID3D11DeviceContext->GenerateMips(shaderResourceView->NativeID3D11ShaderResourceView);

}

UInt32 DeviceContext::ContextFlags::get()
{
    System::Diagnostics::Debug::Assert(NativeID3D11DeviceContext != NULL);

    UINT returnValue = NativeID3D11DeviceContext->GetContextFlags();
    return safe_cast<UInt32>(returnValue);

}

void DeviceContext::GetData(Asynchronous^ asyncData, IntPtr data, UInt32 dataSize, AsyncGetdataFlag flags)
{
    System::Diagnostics::Debug::Assert(NativeID3D11DeviceContext != NULL);

    D3DUtils::VerifyResult(NativeID3D11DeviceContext->GetData(asyncData->NativeID3D11Asynchronous, data.ToPointer(), safe_cast<UINT>(dataSize), safe_cast<UINT>(flags)));
}

void DeviceContext::GetPredication([Runtime::InteropServices::Out] D3DPredicate^ %outPredicate, [Runtime::InteropServices::Out] Boolean %outPredicateValue)
{
    System::Diagnostics::Debug::Assert(NativeID3D11DeviceContext != NULL);

    ID3D11Predicate* tempoutPredicate;
    BOOL tempoutPredicateValue;
    NativeID3D11DeviceContext->GetPredication(&tempoutPredicate, &tempoutPredicateValue);
    outPredicate = gcnew D3DPredicate(tempoutPredicate);
    outPredicateValue = tempoutPredicateValue != 0;
}

Single DeviceContext::GetResourceMinLOD(D3DResource^ Resource)
{
    System::Diagnostics::Debug::Assert(NativeID3D11DeviceContext != NULL);

    float returnValue = NativeID3D11DeviceContext->GetResourceMinLOD(Resource->NativeID3D11Resource);
    return safe_cast<Single>(returnValue);
}

DeviceContextType DeviceContext::GetType()
{
    System::Diagnostics::Debug::Assert(NativeID3D11DeviceContext != NULL);

    D3D11_DEVICE_CONTEXT_TYPE returnValue = NativeID3D11DeviceContext->GetType();
    return safe_cast<DeviceContextType>(returnValue);
}

void DeviceContext::Map(D3DResource^ resource, UInt32 subresource, MapOption mapType, MapFlag mapFlags, MappedSubresource^ mappedResource)
{
    System::Diagnostics::Debug::Assert(NativeID3D11DeviceContext != NULL);

    D3DUtils::VerifyResult(NativeID3D11DeviceContext->Map(resource->NativeID3D11Resource, safe_cast<UINT>(subresource), safe_cast<D3D11_MAP>(mapType), safe_cast<UINT>(mapFlags), mappedResource->nativeObject.Get()));
}

void DeviceContext::ResolveSubresource(D3DResource^ destinationResource, UInt32 destinationSubresource, D3DResource^ sourceResource, UInt32 sourceSubresource, Format format)
{
    System::Diagnostics::Debug::Assert(NativeID3D11DeviceContext != NULL);

    NativeID3D11DeviceContext->ResolveSubresource(destinationResource->NativeID3D11Resource, safe_cast<UINT>(destinationSubresource), sourceResource->NativeID3D11Resource, safe_cast<UINT>(sourceSubresource), safe_cast<DXGI_FORMAT>(format));
}

void DeviceContext::SetPredication(D3DPredicate^ D3DPredicate, Boolean PredicateValue)
{
    System::Diagnostics::Debug::Assert(NativeID3D11DeviceContext != NULL);

    NativeID3D11DeviceContext->SetPredication(D3DPredicate->NativeID3D11Predicate, safe_cast<BOOL>(PredicateValue));
}

void DeviceContext::SetResourceMinLOD(D3DResource^ Resource, Single MinLOD)
{
    System::Diagnostics::Debug::Assert(NativeID3D11DeviceContext != NULL);

    NativeID3D11DeviceContext->SetResourceMinLOD(Resource->NativeID3D11Resource, safe_cast<float>(MinLOD));
}

void DeviceContext::Unmap(D3DResource^ resource, UInt32 subresource)
{
    System::Diagnostics::Debug::Assert(NativeID3D11DeviceContext != NULL);

    NativeID3D11DeviceContext->Unmap(resource->NativeID3D11Resource, safe_cast<UINT>(subresource));
}

void DeviceContext::UpdateSubresource(D3DResource^ destinationResource, UInt32 destinationSubresource, Box^ DstBox, IntPtr SrcData, UInt32 SrcRowPitch, UInt32 SrcDepthPitch)
{
    System::Diagnostics::Debug::Assert(NativeID3D11DeviceContext != NULL);

    NativeID3D11DeviceContext->UpdateSubresource(destinationResource->NativeID3D11Resource, safe_cast<UINT>(destinationSubresource), DstBox->nativeObject.Get(), reinterpret_cast<LPVOID>(SrcData.ToPointer()), safe_cast<UINT>(SrcRowPitch), safe_cast<UINT>(SrcDepthPitch));
}

// The pipeline stage accessors

ComputeShaderPipelineStage^ DeviceContext::CS::get() 
{ 
    if (m_CS == nullptr) 
        m_CS = gcnew ComputeShaderPipelineStage(this); 
    
    return m_CS; 
}

DomainShaderPipelineStage^ DeviceContext::DS::get() 
{ 
    if (m_DS == nullptr) 
        m_DS = gcnew DomainShaderPipelineStage(this); 
    
    return m_DS; 
}

GeometryShaderPipelineStage^ DeviceContext::GS::get() 
{ 
    if (m_GS == nullptr) 
        m_GS = gcnew GeometryShaderPipelineStage(this); 
    
    return m_GS; 
}

HullShaderPipelineStage^ DeviceContext::HS::get() 
{ 
    if (m_HS == nullptr) 
        m_HS = gcnew HullShaderPipelineStage(this); 
    
    return m_HS; 
}

InputAssemblerPipelineStage^ DeviceContext::IA::get() 
{ 
    if (m_IA == nullptr) 
        m_IA = gcnew InputAssemblerPipelineStage(this); 
    
    return m_IA; 
}

OutputMergerPipelineStage^ DeviceContext::OM::get() 
{ 
    if (m_OM == nullptr) 
        m_OM = gcnew OutputMergerPipelineStage(this); 
    
    return m_OM; 
}

PixelShaderPipelineStage^ DeviceContext::PS::get() 
{ 
    if (m_PS == nullptr) 
        m_PS = gcnew PixelShaderPipelineStage(this); 
    
    return m_PS; 
}

RasterizerPipelineStage^ DeviceContext::RS::get() 
{ 
    if (m_RS == nullptr) 
        m_RS = gcnew RasterizerPipelineStage(this); 
    
    return m_RS; 
}

StreamOutputPipelineStage^ DeviceContext::SO::get() 
{ 
    if (m_SO == nullptr) 
        m_SO = gcnew StreamOutputPipelineStage(this); 
    
    return m_SO; 
}

VertexShaderPipelineStage^ DeviceContext::VS::get() 
{ 
    if (m_VS == nullptr) 
        m_VS = gcnew VertexShaderPipelineStage(this); 
    
    return m_VS; 
}
