//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once

using namespace System;
using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3DCommon;
using namespace Microsoft::WindowsAPICodePack::DirectX::DXGI;

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3D11 { 

/// <summary>
/// Describes the blend state for a render target.
/// <para>(Also see DirectX SDK: D3D11_RENDER_TARGET_BLEND_DESC)</para>
/// </summary>
public ref struct RenderTargetBlendDescription 
{
public:
    /// <summary>
    /// Enable (or disable) blending.
    /// <para>(Also see DirectX SDK: D3D11_RENDER_TARGET_BLEND_DESC.BlendEnable)</para>
    /// </summary>
    property Boolean BlendEnable
    {
        Boolean get()
        {
            return nativeObject->BlendEnable != 0;
        }
        void set(Boolean value)
        {
            nativeObject->BlendEnable = (BOOL)value;
        }
    }
    /// <summary>
    /// This blend option specifies the first RGB data source and includes an optional pre-blend operation.
    /// <para>(Also see DirectX SDK: D3D11_RENDER_TARGET_BLEND_DESC.SrcBlend)</para>
    /// </summary>
    property Blend SrcBlend
    {
        Blend get()
        {
            return (Blend)(nativeObject->SrcBlend);
        }
        void set(Blend value)
        {
            nativeObject->SrcBlend = (D3D11_BLEND)value;
        }
    }
    /// <summary>
    /// This blend option specifies the second RGB data source and includes an optional pre-blend operation.
    /// <para>(Also see DirectX SDK: D3D11_RENDER_TARGET_BLEND_DESC.DestBlend)</para>
    /// </summary>
    property Blend DestBlend
    {
        Blend get()
        {
            return (Blend)(nativeObject->DestBlend);
        }
        void set(Blend value)
        {
            nativeObject->DestBlend = (D3D11_BLEND)value;
        }
    }
    /// <summary>
    /// This blend operation defines how to combine the RGB data sources.
    /// <para>(Also see DirectX SDK: D3D11_RENDER_TARGET_BLEND_DESC.BlendOp)</para>
    /// </summary>
    property BlendOperation BlendOp
    {
        BlendOperation get()
        {
            return (BlendOperation)(nativeObject->BlendOp);
        }
        void set(BlendOperation value)
        {
            nativeObject->BlendOp = (D3D11_BLEND_OP)value;
        }
    }
    /// <summary>
    /// This blend option specifies the first alpha data source and includes an optional pre-blend operation. Blend options that end in _COLOR are not allowed.
    /// <para>(Also see DirectX SDK: D3D11_RENDER_TARGET_BLEND_DESC.SrcBlendAlpha)</para>
    /// </summary>
    property Blend SrcBlendAlpha
    {
        Blend get()
        {
            return (Blend)(nativeObject->SrcBlendAlpha);
        }
        void set(Blend value)
        {
            nativeObject->SrcBlendAlpha = (D3D11_BLEND)value;
        }
    }
    /// <summary>
    /// This blend option specifies the second alpha data source and includes an optional pre-blend operation. Blend options that end in _COLOR are not allowed.
    /// <para>(Also see DirectX SDK: D3D11_RENDER_TARGET_BLEND_DESC.DestBlendAlpha)</para>
    /// </summary>
    property Blend DestBlendAlpha
    {
        Blend get()
        {
            return (Blend)(nativeObject->DestBlendAlpha);
        }
        void set(Blend value)
        {
            nativeObject->DestBlendAlpha = (D3D11_BLEND)value;
        }
    }
    /// <summary>
    /// This blend operation defines how to combine the alpha data sources.
    /// <para>(Also see DirectX SDK: D3D11_RENDER_TARGET_BLEND_DESC.BlendOpAlpha)</para>
    /// </summary>
    property BlendOperation BlendOpAlpha
    {
        BlendOperation get()
        {
            return (BlendOperation)(nativeObject->BlendOpAlpha);
        }
        void set(BlendOperation value)
        {
            nativeObject->BlendOpAlpha = (D3D11_BLEND_OP)value;
        }
    }
    /// <summary>
    /// A write mask.
    /// <para>(Also see DirectX SDK: D3D11_RENDER_TARGET_BLEND_DESC.RenderTargetWriteMask)</para>
    /// </summary>
    property Byte RenderTargetWriteMask
    {
        Byte get()
        {
            return (Byte)(nativeObject->RenderTargetWriteMask);
        }
        void set(Byte value)
        {
            nativeObject->RenderTargetWriteMask = (UINT8)value;
        }
    }
public:
    RenderTargetBlendDescription()
    {
        nativeObject.Set(new D3D11_RENDER_TARGET_BLEND_DESC());
        ZeroMemory(nativeObject.Get(), sizeof(D3D11_RENDER_TARGET_BLEND_DESC));
    }
internal:
    AutoPointer<D3D11_RENDER_TARGET_BLEND_DESC> nativeObject;
internal:
    RenderTargetBlendDescription(D3D11_RENDER_TARGET_BLEND_DESC* pRenderTargetBlendDescription)
    {
        nativeObject.Set(pRenderTargetBlendDescription);
    }

    RenderTargetBlendDescription(D3D11_RENDER_TARGET_BLEND_DESC* pRenderTargetBlendDescription, bool deletable)
    {
        nativeObject.Set(pRenderTargetBlendDescription, deletable);
    }

};
/// <summary>
/// Describes the blend state.
/// <para>(Also see DirectX SDK: D3D11_BLEND_DESC)</para>
/// </summary>
public ref struct BlendDescription 
{
public:
    /// <summary>
    /// Determines whether or not to use alpha-to-coverage as a multisampling technique when setting a pixel to a rendertarget.
    /// <para>(Also see DirectX SDK: D3D11_BLEND_DESC.AlphaToCoverageEnable)</para>
    /// </summary>
    property Boolean AlphaToCoverageEnable
    {
        Boolean get()
        {
            return nativeObject->AlphaToCoverageEnable != 0;
        }
        void set(Boolean value)
        {
            nativeObject->AlphaToCoverageEnable = (BOOL)value;
        }
    }
    /// <summary>
    /// Set to TRUE to enable independent blending in simultaneous render targets.
    /// <para>(Also see DirectX SDK: D3D11_BLEND_DESC.IndependentBlendEnable)</para>
    /// </summary>
    property Boolean IndependentBlendEnable
    {
        Boolean get()
        {
            return nativeObject->IndependentBlendEnable != 0;
        }
        void set(Boolean value)
        {
            nativeObject->IndependentBlendEnable = (BOOL)value;
        }
    }
    /// <summary>
    /// A collection of render-target-blend descriptions (see <see cref="RenderTargetBlendDescription"/>)<seealso cref="RenderTargetBlendDescription"/>; these correspond to the eight rendertargets that can be set to the output-merger stage at one time.
    /// <para>(Also see DirectX SDK: D3D11_BLEND_DESC.RenderTarget)</para>
    /// </summary>
    property array<RenderTargetBlendDescription^>^ RenderTarget
    {
        array<RenderTargetBlendDescription^>^ get()
        {
            if (renderTargetArray == nullptr)
            {
                renderTargetArray = gcnew array<RenderTargetBlendDescription^>(RenderTargetArrayLength);
                for (int i=0; i < renderTargetArray->Length; i++)
                {
                    renderTargetArray[i] = gcnew RenderTargetBlendDescription(&(nativeObject->RenderTarget[i]), false);
                }
            }
            return renderTargetArray;
        }
    }
public:
    BlendDescription()
    {
        nativeObject.Set(new D3D11_BLEND_DESC());
        ZeroMemory(nativeObject.Get(), sizeof(D3D11_BLEND_DESC));
    }
internal:
    AutoPointer<D3D11_BLEND_DESC> nativeObject;
internal:
    BlendDescription(D3D11_BLEND_DESC* pBlendDescription)
    {
        nativeObject.Set(pBlendDescription);        
    }

    BlendDescription(D3D11_BLEND_DESC* pBlendDescription, bool deletable)
    {
        nativeObject.Set(pBlendDescription, deletable);        
    }
private:
        static int RenderTargetArrayLength = 8;
        array<RenderTargetBlendDescription^>^ renderTargetArray;
};
/// <summary>
/// Defines a 3D box.
/// <para>(Also see DirectX SDK: D3D11_BOX)</para>
/// </summary>
public ref struct Box 
{
public:
    /// <summary>
    /// The x position of the left hand side of the box.
    /// <para>(Also see DirectX SDK: D3D11_BOX.left)</para>
    /// </summary>
    property UInt32 left
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->left);
        }
        void set(UInt32 value)
        {
            nativeObject->left = (UINT)value;
        }
    }
    /// <summary>
    /// The y position of the top of the box.
    /// <para>(Also see DirectX SDK: D3D11_BOX.top)</para>
    /// </summary>
    property UInt32 top
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->top);
        }
        void set(UInt32 value)
        {
            nativeObject->top = (UINT)value;
        }
    }
    /// <summary>
    /// The z position of the front of the box.
    /// <para>(Also see DirectX SDK: D3D11_BOX.front)</para>
    /// </summary>
    property UInt32 front
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->front);
        }
        void set(UInt32 value)
        {
            nativeObject->front = (UINT)value;
        }
    }
    /// <summary>
    /// The x position of the right hand side of the box.
    /// <para>(Also see DirectX SDK: D3D11_BOX.right)</para>
    /// </summary>
    property UInt32 right
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->right);
        }
        void set(UInt32 value)
        {
            nativeObject->right = (UINT)value;
        }
    }
    /// <summary>
    /// The y position of the bottom of the box.
    /// <para>(Also see DirectX SDK: D3D11_BOX.bottom)</para>
    /// </summary>
    property UInt32 bottom
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->bottom);
        }
        void set(UInt32 value)
        {
            nativeObject->bottom = (UINT)value;
        }
    }
    /// <summary>
    /// The z position of the back of the box.
    /// <para>(Also see DirectX SDK: D3D11_BOX.back)</para>
    /// </summary>
    property UInt32 back
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->back);
        }
        void set(UInt32 value)
        {
            nativeObject->back = (UINT)value;
        }
    }
public:
    Box()
    {
        nativeObject.Set(new D3D11_BOX());
        ZeroMemory(nativeObject.Get(), sizeof(D3D11_BOX));
    }
internal:
    AutoPointer<D3D11_BOX> nativeObject;
internal:
    Box(D3D11_BOX* pBox)
    {
        nativeObject.Set(pBox);
    }
    Box(D3D11_BOX* pBox, bool deletable)
    {
        nativeObject.Set(pBox, deletable);
    }
};
/// <summary>
/// Describes a raw buffer resource.
/// <para>(Also see DirectX SDK: D3D11_BUFFEREX_SRV)</para>
/// </summary>
public ref struct BufferexShaderResourceView 
{
public:
    /// <summary>
    /// The index of the first element to be accessed by the view.
    /// <para>(Also see DirectX SDK: D3D11_BUFFEREX_SRV.FirstElement)</para>
    /// </summary>
    property UInt32 FirstElement
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->FirstElement);
        }
        void set(UInt32 value)
        {
            nativeObject->FirstElement = (UINT)value;
        }
    }
    /// <summary>
    /// The number of elements in the resource.
    /// <para>(Also see DirectX SDK: D3D11_BUFFEREX_SRV.NumElements)</para>
    /// </summary>
    property UInt32 NumElements
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->NumElements);
        }
        void set(UInt32 value)
        {
            nativeObject->NumElements = (UINT)value;
        }
    }
    /// <summary>
    /// Options for binding a raw buffer (see <see cref="BufferexShaderResourceViewFlag"/>)<seealso cref="BufferexShaderResourceViewFlag"/>
    /// <para>(Also see DirectX SDK: D3D11_BUFFEREX_SRV.Flags)</para>
    /// </summary>
    property BufferexShaderResourceViewFlag Flags
    {
        BufferexShaderResourceViewFlag get()
        {
            return (BufferexShaderResourceViewFlag)(nativeObject->Flags);
        }
        void set(BufferexShaderResourceViewFlag value)
        {
            nativeObject->Flags = (UINT)value;
        }
    }
public:
    BufferexShaderResourceView()
    {
        nativeObject.Set(new D3D11_BUFFEREX_SRV());
        ZeroMemory(nativeObject.Get(), sizeof(D3D11_BUFFEREX_SRV));
    }
internal:
    AutoPointer<D3D11_BUFFEREX_SRV> nativeObject;
internal:
    BufferexShaderResourceView(D3D11_BUFFEREX_SRV* pBufferexShaderResourceView)
    {
        nativeObject.Set(pBufferexShaderResourceView);
    }
    BufferexShaderResourceView(D3D11_BUFFEREX_SRV* pBufferexShaderResourceView, bool deletable)
    {
        nativeObject.Set(pBufferexShaderResourceView, deletable);
    }
};
/// <summary>
/// Describes a buffer resource.
/// <para>(Also see DirectX SDK: D3D11_BUFFER_DESC)</para>
/// </summary>
public ref struct BufferDescription 
{
public:
    /// <summary>
    /// Size of the buffer in bytes.
    /// <para>(Also see DirectX SDK: D3D11_BUFFER_DESC.ByteWidth)</para>
    /// </summary>
    property UInt32 ByteWidth
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->ByteWidth);
        }
        void set(UInt32 value)
        {
            nativeObject->ByteWidth = (UINT)value;
        }
    }
    /// <summary>
    /// Identify how the buffer is expected to be read from and written to. Frequency of update is a key factor. The most common value is typically Usage_DEFAULT; see Usage for all possible values.
    /// <para>(Also see DirectX SDK: D3D11_BUFFER_DESC.Usage)</para>
    /// </summary>
    property Usage UsageOptions
    {
        Usage get()
        {
            return (Usage)(nativeObject->Usage);
        }
        void set(Usage value)
        {
            nativeObject->Usage = (D3D11_USAGE)value;
        }
    }
    /// <summary>
    /// Identify how the buffer will be bound to the pipeline. Flags (see <see cref="BindFlag"/>)<seealso cref="BindFlag"/> can be combined with a logical OR.
    /// <para>(Also see DirectX SDK: D3D11_BUFFER_DESC.BindFlags)</para>
    /// </summary>
    property BindFlag BindFlags
    {
        BindFlag get()
        {
            return (BindFlag)(nativeObject->BindFlags);
        }
        void set(BindFlag value)
        {
            nativeObject->BindFlags = (UINT)value;
        }
    }
    /// <summary>
    /// CPU access flags (see <see cref="CpuAccessFlag"/>)<seealso cref="CpuAccessFlag"/> or 0 if no CPU access is necessary. Flags can be combined with a logical OR.
    /// <para>(Also see DirectX SDK: D3D11_BUFFER_DESC.CPUAccessFlags)</para>
    /// </summary>
    property CpuAccessFlag CPUAccessFlags
    {
        CpuAccessFlag get()
        {
            return (CpuAccessFlag)(nativeObject->CPUAccessFlags);
        }
        void set(CpuAccessFlag value)
        {
            nativeObject->CPUAccessFlags = (UINT)value;
        }
    }
    /// <summary>
    /// Miscellaneous flags (see <see cref="ResourceMiscFlag"/>)<seealso cref="ResourceMiscFlag"/> or 0 if unused. Flags can be combined with a logical OR.
    /// <para>(Also see DirectX SDK: D3D11_BUFFER_DESC.MiscFlags)</para>
    /// </summary>
    property ResourceMiscFlag MiscFlags
    {
        ResourceMiscFlag get()
        {
            return (ResourceMiscFlag)(nativeObject->MiscFlags);
        }
        void set(ResourceMiscFlag value)
        {
            nativeObject->MiscFlags = (UINT)value;
        }
    }
    /// <summary>
    /// The size of the structure (in bytes) when it represents a structured buffer.
    /// <para>(Also see DirectX SDK: D3D11_BUFFER_DESC.StructureByteStride)</para>
    /// </summary>
    property UInt32 StructureByteStride
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->StructureByteStride);
        }
        void set(UInt32 value)
        {
            nativeObject->StructureByteStride = (UINT)value;
        }
    }
public:
    BufferDescription()
    {
        nativeObject.Set(new D3D11_BUFFER_DESC());
        ZeroMemory(nativeObject.Get(), sizeof(D3D11_BUFFER_DESC));
    }
internal:
    AutoPointer<D3D11_BUFFER_DESC> nativeObject;
internal:
    BufferDescription(D3D11_BUFFER_DESC* pBufferDescription)
    {
        nativeObject.Set(pBufferDescription);
    }
    BufferDescription(D3D11_BUFFER_DESC* pBufferDescription, bool deletable)
    {
        nativeObject.Set(pBufferDescription, deletable);
    }
};
/// <summary>
/// Specifies the elements in a buffer resource to use in a render-target view.
/// <para>(Also see DirectX SDK: D3D11_BUFFER_RTV)</para>
/// </summary>
public ref struct BufferRenderTargetView 
{
public:
    /// <summary>
    /// Number of bytes between the beginning of the buffer and the first element to access.
    /// <para>(Also see DirectX SDK: D3D11_BUFFER_RTV.ElementOffset)</para>
    /// </summary>
    property UInt32 ElementOffset
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->ElementOffset);
        }
        void set(UInt32 value)
        {
            nativeObject->ElementOffset = (UINT)value;
        }
    }
    /// <summary>
    /// The width of each element (in bytes). This can be determined from the format stored in the render-target-view description.
    /// <para>(Also see DirectX SDK: D3D11_BUFFER_RTV.ElementWidth)</para>
    /// </summary>
    property UInt32 ElementWidth
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->ElementWidth);
        }
        void set(UInt32 value)
        {
            nativeObject->ElementWidth = (UINT)value;
        }
    }
public:
    BufferRenderTargetView()
    {
        nativeObject.Set(new D3D11_BUFFER_RTV());
        ZeroMemory(nativeObject.Get(), sizeof(D3D11_BUFFER_RTV));
    }
internal:
    AutoPointer<D3D11_BUFFER_RTV> nativeObject;
internal:
    BufferRenderTargetView(D3D11_BUFFER_RTV* pBufferRenderTargetView)
    {
        nativeObject.Set(pBufferRenderTargetView);
    }
    BufferRenderTargetView(D3D11_BUFFER_RTV* pBufferRenderTargetView, bool deletable)
    {
        nativeObject.Set(pBufferRenderTargetView, deletable);
    }
};
/// <summary>
/// Specifies the elements in a buffer resource to use in a shader-resource view.
/// <para>(Also see DirectX SDK: D3D11_BUFFER_SRV)</para>
/// </summary>
public ref struct BufferShaderResourceView 
{
public:
    /// <summary>
    /// The offset of the first element in the view to access, relative to element 0.
    /// <para>(Also see DirectX SDK: D3D11_BUFFER_SRV.ElementOffset)</para>
    /// </summary>
    property UInt32 ElementOffset
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->ElementOffset);
        }
        void set(UInt32 value)
        {
            nativeObject->ElementOffset = (UINT)value;
        }
    }
    /// <summary>
    /// The total number of elements in the view.
    /// <para>(Also see DirectX SDK: D3D11_BUFFER_SRV.ElementWidth)</para>
    /// </summary>
    property UInt32 ElementWidth
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->ElementWidth);
        }
        void set(UInt32 value)
        {
            nativeObject->ElementWidth = (UINT)value;
        }
    }
public:
    BufferShaderResourceView()
    {
        nativeObject.Set(new D3D11_BUFFER_SRV());
        ZeroMemory(nativeObject.Get(), sizeof(D3D11_BUFFER_SRV));
    }
internal:
    AutoPointer<D3D11_BUFFER_SRV> nativeObject;
internal:
    BufferShaderResourceView(D3D11_BUFFER_SRV* pBufferShaderResourceView)
    {
        nativeObject.Set(pBufferShaderResourceView);
    }
    BufferShaderResourceView(D3D11_BUFFER_SRV* pBufferShaderResourceView, bool deletable)
    {
        nativeObject.Set(pBufferShaderResourceView, deletable);
    }
};
/// <summary>
/// Describes a unordered-access buffer resource.
/// <para>(Also see DirectX SDK: D3D11_BUFFER_UAV)</para>
/// </summary>
public ref struct BufferUnorderedAccessView 
{
public:
    /// <summary>
    /// The zero-based index of the first element to be accessed.
    /// <para>(Also see DirectX SDK: D3D11_BUFFER_UAV.FirstElement)</para>
    /// </summary>
    property UInt32 FirstElement
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->FirstElement);
        }
        void set(UInt32 value)
        {
            nativeObject->FirstElement = (UINT)value;
        }
    }
    /// <summary>
    /// The number of elements in the resource.
    /// <para>(Also see DirectX SDK: D3D11_BUFFER_UAV.NumElements)</para>
    /// </summary>
    property UInt32 NumElements
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->NumElements);
        }
        void set(UInt32 value)
        {
            nativeObject->NumElements = (UINT)value;
        }
    }
    /// <summary>
    /// View options for the resource (see <see cref="BufferUnorderedAccessViewFlag"/>)<seealso cref="BufferUnorderedAccessViewFlag"/>.
    /// <para>(Also see DirectX SDK: D3D11_BUFFER_UAV.Flags)</para>
    /// </summary>
    property BufferUnorderedAccessViewFlag Flags
    {
        BufferUnorderedAccessViewFlag get()
        {
            return (BufferUnorderedAccessViewFlag)(nativeObject->Flags);
        }
        void set(BufferUnorderedAccessViewFlag value)
        {
            nativeObject->Flags = (UINT)value;
        }
    }
public:
    BufferUnorderedAccessView()
    {
        nativeObject.Set(new D3D11_BUFFER_UAV());
        ZeroMemory(nativeObject.Get(), sizeof(D3D11_BUFFER_UAV));
    }
internal:
    AutoPointer<D3D11_BUFFER_UAV> nativeObject;
internal:
    BufferUnorderedAccessView(D3D11_BUFFER_UAV* pBufferUnorderedAccessView)
    {
        nativeObject.Set(pBufferUnorderedAccessView);
    }
    BufferUnorderedAccessView(D3D11_BUFFER_UAV* pBufferUnorderedAccessView, bool deletable)
    {
        nativeObject.Set(pBufferUnorderedAccessView, deletable);
    }
};
/// <summary>
/// Describes an HLSL class instance.
/// <para>(Also see DirectX SDK: D3D11_CLASS_INSTANCE_DESC)</para>
/// </summary>
public ref struct ClassInstanceDescription 
{
public:
    /// <summary>
    /// The instance ID of an HLSL class; the default value is 0.
    /// <para>(Also see DirectX SDK: D3D11_CLASS_INSTANCE_DESC.InstanceId)</para>
    /// </summary>
    property UInt32 InstanceId
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->InstanceId);
        }
        void set(UInt32 value)
        {
            nativeObject->InstanceId = (UINT)value;
        }
    }
    /// <summary>
    /// The instance index of an HLSL class; the default value is 0.
    /// <para>(Also see DirectX SDK: D3D11_CLASS_INSTANCE_DESC.InstanceIndex)</para>
    /// </summary>
    property UInt32 InstanceIndex
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->InstanceIndex);
        }
        void set(UInt32 value)
        {
            nativeObject->InstanceIndex = (UINT)value;
        }
    }
    /// <summary>
    /// The type ID of an HLSL class; the default value is 0.
    /// <para>(Also see DirectX SDK: D3D11_CLASS_INSTANCE_DESC.TypeId)</para>
    /// </summary>
    property UInt32 TypeId
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->TypeId);
        }
        void set(UInt32 value)
        {
            nativeObject->TypeId = (UINT)value;
        }
    }
    /// <summary>
    /// Describes the constant buffer associated with an HLSL class; the default value is 0.
    /// <para>(Also see DirectX SDK: D3D11_CLASS_INSTANCE_DESC.ConstantBuffer)</para>
    /// </summary>
    property UInt32 ConstantBuffer
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->ConstantBuffer);
        }
        void set(UInt32 value)
        {
            nativeObject->ConstantBuffer = (UINT)value;
        }
    }
    /// <summary>
    /// The base constant buffer offset associated with an HLSL class; the default value is 0.
    /// <para>(Also see DirectX SDK: D3D11_CLASS_INSTANCE_DESC.BaseConstantBufferOffset)</para>
    /// </summary>
    property UInt32 BaseConstantBufferOffset
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->BaseConstantBufferOffset);
        }
        void set(UInt32 value)
        {
            nativeObject->BaseConstantBufferOffset = (UINT)value;
        }
    }
    /// <summary>
    /// The base texture associated with an HLSL class; the default value is 127.
    /// <para>(Also see DirectX SDK: D3D11_CLASS_INSTANCE_DESC.BaseTexture)</para>
    /// </summary>
    property UInt32 BaseTexture
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->BaseTexture);
        }
        void set(UInt32 value)
        {
            nativeObject->BaseTexture = (UINT)value;
        }
    }
    /// <summary>
    /// The base sampler associated with an HLSL class; the default value is 15.
    /// <para>(Also see DirectX SDK: D3D11_CLASS_INSTANCE_DESC.BaseSampler)</para>
    /// </summary>
    property UInt32 BaseSampler
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->BaseSampler);
        }
        void set(UInt32 value)
        {
            nativeObject->BaseSampler = (UINT)value;
        }
    }
    /// <summary>
    /// True if the class was created; the default value is false.
    /// <para>(Also see DirectX SDK: D3D11_CLASS_INSTANCE_DESC.Created)</para>
    /// </summary>
    property Boolean Created
    {
        Boolean get()
        {
            return nativeObject->Created != 0;
        }
        void set(Boolean value)
        {
            nativeObject->Created = (BOOL)value;
        }
    }
public:
    ClassInstanceDescription()
    {
        nativeObject.Set(new D3D11_CLASS_INSTANCE_DESC());
        ZeroMemory(nativeObject.Get(), sizeof(D3D11_CLASS_INSTANCE_DESC));
    }
internal:
    AutoPointer<D3D11_CLASS_INSTANCE_DESC> nativeObject;
internal:
    ClassInstanceDescription(D3D11_CLASS_INSTANCE_DESC* pClassInstanceDescription)
    {
        nativeObject.Set(pClassInstanceDescription);
    }
    ClassInstanceDescription(D3D11_CLASS_INSTANCE_DESC* pClassInstanceDescription, bool deletable)
    {
        nativeObject.Set(pClassInstanceDescription, deletable);
    }
};
/// <summary>
/// Describes a counter.
/// <para>(Also see DirectX SDK: D3D11_COUNTER_DESC)</para>
/// </summary>
public ref struct CounterDescription 
{
public:
    /// <summary>
    /// Type of counter (see <see cref="CounterOption"/>)<seealso cref="CounterOption"/>.
    /// <para>(Also see DirectX SDK: D3D11_COUNTER_DESC.Counter)</para>
    /// </summary>
    property CounterOption Counter
    {
        CounterOption get()
        {
            return (CounterOption)(nativeObject->Counter);
        }
        void set(CounterOption value)
        {
            nativeObject->Counter = (D3D11_COUNTER)value;
        }
    }
    /// <summary>
    /// Reserved.
    /// <para>(Also see DirectX SDK: D3D11_COUNTER_DESC.MiscFlags)</para>
    /// </summary>
    property UInt32 MiscFlags
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->MiscFlags);
        }
        void set(UInt32 value)
        {
            nativeObject->MiscFlags = (UINT)value;
        }
    }
public:
    CounterDescription()
    {
        nativeObject.Set(new D3D11_COUNTER_DESC());
        ZeroMemory(nativeObject.Get(), sizeof(D3D11_COUNTER_DESC));
    }
internal:
    AutoPointer<D3D11_COUNTER_DESC> nativeObject;
internal:
    CounterDescription(D3D11_COUNTER_DESC* pCounterDescription)
    {
        nativeObject.Set(pCounterDescription);
    }
    CounterDescription(D3D11_COUNTER_DESC* pCounterDescription, bool deletable)
    {
        nativeObject.Set(pCounterDescription, deletable);
    }
};
/// <summary>
/// Information about the video card's performance counter capabilities.
/// <para>(Also see DirectX SDK: D3D11_COUNTER_INFO)</para>
/// </summary>
public ref struct CounterInfo 
{
public:
    /// <summary>
    /// Largest device-dependent counter ID that the device supports. If none are supported, this value will be 0. Otherwise it will be greater than or equal to DeviceDependent_0. See CounterOption.
    /// <para>(Also see DirectX SDK: D3D11_COUNTER_INFO.LastDeviceDependentCounter)</para>
    /// </summary>
    property CounterOption LastDeviceDependentCounter
    {
        CounterOption get()
        {
            return (CounterOption)(nativeObject->LastDeviceDependentCounter);
        }
        void set(CounterOption value)
        {
            nativeObject->LastDeviceDependentCounter = (D3D11_COUNTER)value;
        }
    }
    /// <summary>
    /// Number of counters that can be simultaneously supported.
    /// <para>(Also see DirectX SDK: D3D11_COUNTER_INFO.NumSimultaneousCounters)</para>
    /// </summary>
    property UInt32 NumSimultaneousCounters
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->NumSimultaneousCounters);
        }
        void set(UInt32 value)
        {
            nativeObject->NumSimultaneousCounters = (UINT)value;
        }
    }
    /// <summary>
    /// Number of detectable parallel units that the counter is able to discern. Values are 1 ~ 4. Use NumDetectableParallelUnits to interpret the values of the VERTEX_PROCESSING, GEOMETRY_PROCESSING, PIXEL_PROCESSING, and OTHER_GPU_PROCESSING counters.
    /// <para>(Also see DirectX SDK: D3D11_COUNTER_INFO.NumDetectableParallelUnits)</para>
    /// </summary>
    property Byte NumDetectableParallelUnits
    {
        Byte get()
        {
            return (Byte)(nativeObject->NumDetectableParallelUnits);
        }
        void set(Byte value)
        {
            nativeObject->NumDetectableParallelUnits = (UINT8)value;
        }
    }
public:
    CounterInfo()
    {
        nativeObject.Set(new D3D11_COUNTER_INFO());
        ZeroMemory(nativeObject.Get(), sizeof(D3D11_COUNTER_INFO));
    }
internal:
    AutoPointer<D3D11_COUNTER_INFO> nativeObject;
internal:
    CounterInfo(D3D11_COUNTER_INFO* pCounterInfo)
    {
        nativeObject.Set(pCounterInfo);
    }
    CounterInfo(D3D11_COUNTER_INFO* pCounterInfo, bool deletable)
    {
        nativeObject.Set(pCounterInfo, deletable);
    }
};
/// <summary>
/// Stencil operations that can be performed based on the results of stencil test.
/// <para>(Also see DirectX SDK: D3D11_DEPTH_STENCILOP_DESC)</para>
/// </summary>
public ref struct DepthStencilopDescription 
{
public:
    /// <summary>
    /// The stencil operation to perform when stencil testing fails.
    /// <para>(Also see DirectX SDK: D3D11_DEPTH_STENCILOP_DESC.StencilFailOp)</para>
    /// </summary>
    property StencilOperation StencilFailOp
    {
        StencilOperation get()
        {
            return (StencilOperation)(nativeObject->StencilFailOp);
        }
        void set(StencilOperation value)
        {
            nativeObject->StencilFailOp = (D3D11_STENCIL_OP)value;
        }
    }
    /// <summary>
    /// The stencil operation to perform when stencil testing passes and depth testing fails.
    /// <para>(Also see DirectX SDK: D3D11_DEPTH_STENCILOP_DESC.StencilDepthFailOp)</para>
    /// </summary>
    property StencilOperation StencilDepthFailOp
    {
        StencilOperation get()
        {
            return (StencilOperation)(nativeObject->StencilDepthFailOp);
        }
        void set(StencilOperation value)
        {
            nativeObject->StencilDepthFailOp = (D3D11_STENCIL_OP)value;
        }
    }
    /// <summary>
    /// The stencil operation to perform when stencil testing and depth testing both pass.
    /// <para>(Also see DirectX SDK: D3D11_DEPTH_STENCILOP_DESC.StencilPassOp)</para>
    /// </summary>
    property StencilOperation StencilPassOp
    {
        StencilOperation get()
        {
            return (StencilOperation)(nativeObject->StencilPassOp);
        }
        void set(StencilOperation value)
        {
            nativeObject->StencilPassOp = (D3D11_STENCIL_OP)value;
        }
    }
    /// <summary>
    /// A function that compares stencil data against existing stencil data. The function options are listed in ComparisonFunc.
    /// <para>(Also see DirectX SDK: D3D11_DEPTH_STENCILOP_DESC.StencilFunc)</para>
    /// </summary>
    property ComparisonFunc StencilFunc
    {
        ComparisonFunc get()
        {
            return (ComparisonFunc)(nativeObject->StencilFunc);
        }
        void set(ComparisonFunc value)
        {
            nativeObject->StencilFunc = (D3D11_COMPARISON_FUNC)value;
        }
    }
public:
    DepthStencilopDescription()
    {
        nativeObject.Set(new D3D11_DEPTH_STENCILOP_DESC());
        ZeroMemory(nativeObject.Get(), sizeof(D3D11_DEPTH_STENCILOP_DESC));
    }
internal:
    AutoPointer<D3D11_DEPTH_STENCILOP_DESC> nativeObject;
internal:
    DepthStencilopDescription(D3D11_DEPTH_STENCILOP_DESC* pDepthStencilopDescription)
    {
        nativeObject.Set(pDepthStencilopDescription);
    }
    DepthStencilopDescription(D3D11_DEPTH_STENCILOP_DESC* pDepthStencilopDescription, bool deletable)
    {
        nativeObject.Set(pDepthStencilopDescription, deletable);
    }};
/// <summary>
/// Specifies the subresources from an array of 1D textures to use in a depth-stencil view.
/// <para>(Also see DirectX SDK: D3D11_TEX1D_ARRAY_DSV)</para>
/// </summary>
public ref struct Tex1dArrayDepthStencilView 
{
public:
    /// <summary>
    /// The index of the first mipmap level to use.
    /// <para>(Also see DirectX SDK: D3D11_TEX1D_ARRAY_DSV.MipSlice)</para>
    /// </summary>
    property UInt32 MipSlice
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->MipSlice);
        }
        void set(UInt32 value)
        {
            nativeObject->MipSlice = (UINT)value;
        }
    }
    /// <summary>
    /// The index of the first texture to use in an array of textures.
    /// <para>(Also see DirectX SDK: D3D11_TEX1D_ARRAY_DSV.FirstArraySlice)</para>
    /// </summary>
    property UInt32 FirstArraySlice
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->FirstArraySlice);
        }
        void set(UInt32 value)
        {
            nativeObject->FirstArraySlice = (UINT)value;
        }
    }
    /// <summary>
    /// Number of textures to use.
    /// <para>(Also see DirectX SDK: D3D11_TEX1D_ARRAY_DSV.ArraySize)</para>
    /// </summary>
    property UInt32 ArraySize
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->ArraySize);
        }
        void set(UInt32 value)
        {
            nativeObject->ArraySize = (UINT)value;
        }
    }
public:
    Tex1dArrayDepthStencilView()
    {
        nativeObject.Set(new D3D11_TEX1D_ARRAY_DSV());
        ZeroMemory(nativeObject.Get(), sizeof(D3D11_TEX1D_ARRAY_DSV));
    }
internal:
    AutoPointer<D3D11_TEX1D_ARRAY_DSV> nativeObject;
internal:
    Tex1dArrayDepthStencilView(D3D11_TEX1D_ARRAY_DSV* pTex1dArrayDepthStencilView)
    {
        nativeObject.Set(pTex1dArrayDepthStencilView);
    }
    Tex1dArrayDepthStencilView(D3D11_TEX1D_ARRAY_DSV* pTex1dArrayDepthStencilView, bool deletable)
    {
        nativeObject.Set(pTex1dArrayDepthStencilView, deletable);
    }};
/// <summary>
/// Specifies the subresources from an array of 1D textures to use in a render-target view.
/// <para>(Also see DirectX SDK: D3D11_TEX1D_ARRAY_RTV)</para>
/// </summary>
public ref struct Tex1dArrayRenderTargetView 
{
public:
    /// <summary>
    /// The index of the mipmap level to use mip slice.
    /// <para>(Also see DirectX SDK: D3D11_TEX1D_ARRAY_RTV.MipSlice)</para>
    /// </summary>
    property UInt32 MipSlice
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->MipSlice);
        }
        void set(UInt32 value)
        {
            nativeObject->MipSlice = (UINT)value;
        }
    }
    /// <summary>
    /// The index of the first texture to use in an array of textures.
    /// <para>(Also see DirectX SDK: D3D11_TEX1D_ARRAY_RTV.FirstArraySlice)</para>
    /// </summary>
    property UInt32 FirstArraySlice
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->FirstArraySlice);
        }
        void set(UInt32 value)
        {
            nativeObject->FirstArraySlice = (UINT)value;
        }
    }
    /// <summary>
    /// Number of textures to use.
    /// <para>(Also see DirectX SDK: D3D11_TEX1D_ARRAY_RTV.ArraySize)</para>
    /// </summary>
    property UInt32 ArraySize
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->ArraySize);
        }
        void set(UInt32 value)
        {
            nativeObject->ArraySize = (UINT)value;
        }
    }
public:
    Tex1dArrayRenderTargetView()
    {
        nativeObject.Set(new D3D11_TEX1D_ARRAY_RTV());
        ZeroMemory(nativeObject.Get(), sizeof(D3D11_TEX1D_ARRAY_RTV));
    }
internal:
    AutoPointer<D3D11_TEX1D_ARRAY_RTV> nativeObject;
internal:
    Tex1dArrayRenderTargetView(D3D11_TEX1D_ARRAY_RTV* pTex1dArrayRenderTargetView)
    {
        nativeObject.Set(pTex1dArrayRenderTargetView);
    }
    Tex1dArrayRenderTargetView(D3D11_TEX1D_ARRAY_RTV* pTex1dArrayRenderTargetView, bool deletable)
    {
        nativeObject.Set(pTex1dArrayRenderTargetView, deletable);
    }};
/// <summary>
/// Specifies the subresources from an array of 1D textures to use in a shader-resource view.
/// <para>(Also see DirectX SDK: D3D11_TEX1D_ARRAY_SRV)</para>
/// </summary>
public ref struct Tex1dArrayShaderResourceView 
{
public:
    /// <summary>
    /// Index of the most detailed mipmap level to use; this number is between 0 and MipLevels.
    /// <para>(Also see DirectX SDK: D3D11_TEX1D_ARRAY_SRV.MostDetailedMip)</para>
    /// </summary>
    property UInt32 MostDetailedMip
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->MostDetailedMip);
        }
        void set(UInt32 value)
        {
            nativeObject->MostDetailedMip = (UINT)value;
        }
    }
    /// <summary>
    /// The maximum number of mipmap levels in the texture. See the remarks in Tex1dShaderResourceView.
    /// <para>(Also see DirectX SDK: D3D11_TEX1D_ARRAY_SRV.MipLevels)</para>
    /// </summary>
    property UInt32 MipLevels
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->MipLevels);
        }
        void set(UInt32 value)
        {
            nativeObject->MipLevels = (UINT)value;
        }
    }
    /// <summary>
    /// The index of the first texture to use in an array of textures.
    /// <para>(Also see DirectX SDK: D3D11_TEX1D_ARRAY_SRV.FirstArraySlice)</para>
    /// </summary>
    property UInt32 FirstArraySlice
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->FirstArraySlice);
        }
        void set(UInt32 value)
        {
            nativeObject->FirstArraySlice = (UINT)value;
        }
    }
    /// <summary>
    /// Number of textures in the array.
    /// <para>(Also see DirectX SDK: D3D11_TEX1D_ARRAY_SRV.ArraySize)</para>
    /// </summary>
    property UInt32 ArraySize
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->ArraySize);
        }
        void set(UInt32 value)
        {
            nativeObject->ArraySize = (UINT)value;
        }
    }
public:
    Tex1dArrayShaderResourceView()
    {
        nativeObject.Set(new D3D11_TEX1D_ARRAY_SRV());
        ZeroMemory(nativeObject.Get(), sizeof(D3D11_TEX1D_ARRAY_SRV));
    }
internal:
    AutoPointer<D3D11_TEX1D_ARRAY_SRV> nativeObject;
internal:
    Tex1dArrayShaderResourceView(D3D11_TEX1D_ARRAY_SRV* pTex1dArrayShaderResourceView)
    {
        nativeObject.Set(pTex1dArrayShaderResourceView);
    }
    Tex1dArrayShaderResourceView(D3D11_TEX1D_ARRAY_SRV* pTex1dArrayShaderResourceView, bool deletable)
    {
        nativeObject.Set(pTex1dArrayShaderResourceView, deletable);
    }};
/// <summary>
/// Describes an array of unordered-access 1D texture resources.
/// <para>(Also see DirectX SDK: D3D11_TEX1D_ARRAY_UAV)</para>
/// </summary>
public ref struct Tex1dArrayUnorderedAccessView 
{
public:
    /// <summary>
    /// The mipmap slice index.
    /// <para>(Also see DirectX SDK: D3D11_TEX1D_ARRAY_UAV.MipSlice)</para>
    /// </summary>
    property UInt32 MipSlice
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->MipSlice);
        }
        void set(UInt32 value)
        {
            nativeObject->MipSlice = (UINT)value;
        }
    }
    /// <summary>
    /// The zero-based index of the first array slice to be accessed.
    /// <para>(Also see DirectX SDK: D3D11_TEX1D_ARRAY_UAV.FirstArraySlice)</para>
    /// </summary>
    property UInt32 FirstArraySlice
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->FirstArraySlice);
        }
        void set(UInt32 value)
        {
            nativeObject->FirstArraySlice = (UINT)value;
        }
    }
    /// <summary>
    /// The number of slices in the array.
    /// <para>(Also see DirectX SDK: D3D11_TEX1D_ARRAY_UAV.ArraySize)</para>
    /// </summary>
    property UInt32 ArraySize
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->ArraySize);
        }
        void set(UInt32 value)
        {
            nativeObject->ArraySize = (UINT)value;
        }
    }
public:
    Tex1dArrayUnorderedAccessView()
    {
        nativeObject.Set(new D3D11_TEX1D_ARRAY_UAV());
        ZeroMemory(nativeObject.Get(), sizeof(D3D11_TEX1D_ARRAY_UAV));
    }
internal:
    AutoPointer<D3D11_TEX1D_ARRAY_UAV> nativeObject;
internal:
    Tex1dArrayUnorderedAccessView(D3D11_TEX1D_ARRAY_UAV* pTex1dArrayUnorderedAccessView)
    {
        nativeObject.Set(pTex1dArrayUnorderedAccessView);
    }
    Tex1dArrayUnorderedAccessView(D3D11_TEX1D_ARRAY_UAV* pTex1dArrayUnorderedAccessView, bool deletable)
    {
        nativeObject.Set(pTex1dArrayUnorderedAccessView, deletable);
    }};
/// <summary>
/// Specifies the subresource from a 1D texture that is accessable to a depth-stencil view.
/// <para>(Also see DirectX SDK: D3D11_TEX1D_DSV)</para>
/// </summary>
public ref struct Tex1dDepthStencilView 
{
public:
    /// <summary>
    /// The index of the first mipmap level to use.
    /// <para>(Also see DirectX SDK: D3D11_TEX1D_DSV.MipSlice)</para>
    /// </summary>
    property UInt32 MipSlice
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->MipSlice);
        }
        void set(UInt32 value)
        {
            nativeObject->MipSlice = (UINT)value;
        }
    }
public:
    Tex1dDepthStencilView()
    {
        nativeObject.Set(new D3D11_TEX1D_DSV());
        ZeroMemory(nativeObject.Get(), sizeof(D3D11_TEX1D_DSV));
    }
internal:
    AutoPointer<D3D11_TEX1D_DSV> nativeObject;
internal:
    Tex1dDepthStencilView(D3D11_TEX1D_DSV* pTex1dDepthStencilView)
    {
        nativeObject.Set(pTex1dDepthStencilView);
    }
    Tex1dDepthStencilView(D3D11_TEX1D_DSV* pTex1dDepthStencilView, bool deletable)
    {
        nativeObject.Set(pTex1dDepthStencilView, deletable);
    }};
/// <summary>
/// Specifies the subresource from a 1D texture to use in a render-target view.
/// <para>(Also see DirectX SDK: D3D11_TEX1D_RTV)</para>
/// </summary>
public ref struct Tex1dRenderTargetView 
{
public:
    /// <summary>
    /// The index of the mipmap level to use mip slice.
    /// <para>(Also see DirectX SDK: D3D11_TEX1D_RTV.MipSlice)</para>
    /// </summary>
    property UInt32 MipSlice
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->MipSlice);
        }
        void set(UInt32 value)
        {
            nativeObject->MipSlice = (UINT)value;
        }
    }
public:
    Tex1dRenderTargetView()
    {
        nativeObject.Set(new D3D11_TEX1D_RTV());
        ZeroMemory(nativeObject.Get(), sizeof(D3D11_TEX1D_RTV));
    }
internal:
    AutoPointer<D3D11_TEX1D_RTV> nativeObject;
internal:
    Tex1dRenderTargetView(D3D11_TEX1D_RTV* pTex1dRenderTargetView)
    {
        nativeObject.Set(pTex1dRenderTargetView);
    }
    Tex1dRenderTargetView(D3D11_TEX1D_RTV* pTex1dRenderTargetView, bool deletable)
    {
        nativeObject.Set(pTex1dRenderTargetView, deletable);
    }};
/// <summary>
/// Specifies the subresource from a 1D texture to use in a shader-resource view.
/// <para>(Also see DirectX SDK: D3D11_TEX1D_SRV)</para>
/// </summary>
public ref struct Tex1dShaderResourceView 
{
public:
    /// <summary>
    /// Index of the most detailed mipmap level to use; this number is between 0 and MipLevels.
    /// <para>(Also see DirectX SDK: D3D11_TEX1D_SRV.MostDetailedMip)</para>
    /// </summary>
    property UInt32 MostDetailedMip
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->MostDetailedMip);
        }
        void set(UInt32 value)
        {
            nativeObject->MostDetailedMip = (UINT)value;
        }
    }
    /// <summary>
    /// The maximum number of mipmap levels in the texture. See the remarks in Tex1dShaderResourceView.
    /// <para>(Also see DirectX SDK: D3D11_TEX1D_SRV.MipLevels)</para>
    /// </summary>
    property UInt32 MipLevels
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->MipLevels);
        }
        void set(UInt32 value)
        {
            nativeObject->MipLevels = (UINT)value;
        }
    }
public:
    Tex1dShaderResourceView()
    {
        nativeObject.Set(new D3D11_TEX1D_SRV());
        ZeroMemory(nativeObject.Get(), sizeof(D3D11_TEX1D_SRV));
    }
internal:
    AutoPointer<D3D11_TEX1D_SRV> nativeObject;
internal:
    Tex1dShaderResourceView(D3D11_TEX1D_SRV* pTex1dShaderResourceView)
    {
        nativeObject.Set(pTex1dShaderResourceView);
    }
    Tex1dShaderResourceView(D3D11_TEX1D_SRV* pTex1dShaderResourceView, bool deletable)
    {
        nativeObject.Set(pTex1dShaderResourceView, deletable);
    }};
/// <summary>
/// Describes a unordered-access 1D texture resource.
/// <para>(Also see DirectX SDK: D3D11_TEX1D_UAV)</para>
/// </summary>
public ref struct Tex1dUnorderedAccessView 
{
public:
    /// <summary>
    /// The mipmap slice index.
    /// <para>(Also see DirectX SDK: D3D11_TEX1D_UAV.MipSlice)</para>
    /// </summary>
    property UInt32 MipSlice
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->MipSlice);
        }
        void set(UInt32 value)
        {
            nativeObject->MipSlice = (UINT)value;
        }
    }
public:
    Tex1dUnorderedAccessView()
    {
        nativeObject.Set(new D3D11_TEX1D_UAV());
        ZeroMemory(nativeObject.Get(), sizeof(D3D11_TEX1D_UAV));
    }
internal:
    AutoPointer<D3D11_TEX1D_UAV> nativeObject;
internal:
    Tex1dUnorderedAccessView(D3D11_TEX1D_UAV* pTex1dUnorderedAccessView)
    {
        nativeObject.Set(pTex1dUnorderedAccessView);
    }
    Tex1dUnorderedAccessView(D3D11_TEX1D_UAV* pTex1dUnorderedAccessView, bool deletable)
    {
        nativeObject.Set(pTex1dUnorderedAccessView, deletable);
    }};
/// <summary>
/// Specifies the subresources from an array of multisampled 2D textures for a depth-stencil view.
/// <para>(Also see DirectX SDK: D3D11_TEX2DMS_ARRAY_DSV)</para>
/// </summary>
public ref struct Tex2dmsArrayDepthStencilView 
{
public:
    /// <summary>
    /// The index of the first texture to use in an array of textures.
    /// <para>(Also see DirectX SDK: D3D11_TEX2DMS_ARRAY_DSV.FirstArraySlice)</para>
    /// </summary>
    property UInt32 FirstArraySlice
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->FirstArraySlice);
        }
        void set(UInt32 value)
        {
            nativeObject->FirstArraySlice = (UINT)value;
        }
    }
    /// <summary>
    /// Number of textures to use.
    /// <para>(Also see DirectX SDK: D3D11_TEX2DMS_ARRAY_DSV.ArraySize)</para>
    /// </summary>
    property UInt32 ArraySize
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->ArraySize);
        }
        void set(UInt32 value)
        {
            nativeObject->ArraySize = (UINT)value;
        }
    }
public:
    Tex2dmsArrayDepthStencilView()
    {
        nativeObject.Set(new D3D11_TEX2DMS_ARRAY_DSV());
        ZeroMemory(nativeObject.Get(), sizeof(D3D11_TEX2DMS_ARRAY_DSV));
    }
internal:
    AutoPointer<D3D11_TEX2DMS_ARRAY_DSV> nativeObject;
internal:
    Tex2dmsArrayDepthStencilView(D3D11_TEX2DMS_ARRAY_DSV* pTex2dmsArrayDepthStencilView)
    {
        nativeObject.Set(pTex2dmsArrayDepthStencilView);
    }
    Tex2dmsArrayDepthStencilView(D3D11_TEX2DMS_ARRAY_DSV* pTex2dmsArrayDepthStencilView, bool deletable)
    {
        nativeObject.Set(pTex2dmsArrayDepthStencilView, deletable);
    }};
/// <summary>
/// Specifies the subresources from a an array of multisampled 2D textures to use in a render-target view.
/// <para>(Also see DirectX SDK: D3D11_TEX2DMS_ARRAY_RTV)</para>
/// </summary>
public ref struct Tex2dmsArrayRenderTargetView 
{
public:
    /// <summary>
    /// The index of the first texture to use in an array of textures.
    /// <para>(Also see DirectX SDK: D3D11_TEX2DMS_ARRAY_RTV.FirstArraySlice)</para>
    /// </summary>
    property UInt32 FirstArraySlice
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->FirstArraySlice);
        }
        void set(UInt32 value)
        {
            nativeObject->FirstArraySlice = (UINT)value;
        }
    }
    /// <summary>
    /// Number of textures to use.
    /// <para>(Also see DirectX SDK: D3D11_TEX2DMS_ARRAY_RTV.ArraySize)</para>
    /// </summary>
    property UInt32 ArraySize
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->ArraySize);
        }
        void set(UInt32 value)
        {
            nativeObject->ArraySize = (UINT)value;
        }
    }
public:
    Tex2dmsArrayRenderTargetView()
    {
        nativeObject.Set(new D3D11_TEX2DMS_ARRAY_RTV());
        ZeroMemory(nativeObject.Get(), sizeof(D3D11_TEX2DMS_ARRAY_RTV));
    }
internal:
    AutoPointer<D3D11_TEX2DMS_ARRAY_RTV> nativeObject;
internal:
    Tex2dmsArrayRenderTargetView(D3D11_TEX2DMS_ARRAY_RTV* pTex2dmsArrayRenderTargetView)
    {
        nativeObject.Set(pTex2dmsArrayRenderTargetView);
    }
    Tex2dmsArrayRenderTargetView(D3D11_TEX2DMS_ARRAY_RTV* pTex2dmsArrayRenderTargetView, bool deletable)
    {
        nativeObject.Set(pTex2dmsArrayRenderTargetView, deletable);
    }};
/// <summary>
/// Specifies the subresources from an array of multisampled 2D textures to use in a shader-resource view.
/// <para>(Also see DirectX SDK: D3D11_TEX2DMS_ARRAY_SRV)</para>
/// </summary>
public ref struct Tex2dmsArrayShaderResourceView 
{
public:
    /// <summary>
    /// The index of the first texture to use in an array of textures.
    /// <para>(Also see DirectX SDK: D3D11_TEX2DMS_ARRAY_SRV.FirstArraySlice)</para>
    /// </summary>
    property UInt32 FirstArraySlice
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->FirstArraySlice);
        }
        void set(UInt32 value)
        {
            nativeObject->FirstArraySlice = (UINT)value;
        }
    }
    /// <summary>
    /// Number of textures to use.
    /// <para>(Also see DirectX SDK: D3D11_TEX2DMS_ARRAY_SRV.ArraySize)</para>
    /// </summary>
    property UInt32 ArraySize
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->ArraySize);
        }
        void set(UInt32 value)
        {
            nativeObject->ArraySize = (UINT)value;
        }
    }
public:
    Tex2dmsArrayShaderResourceView()
    {
        nativeObject.Set(new D3D11_TEX2DMS_ARRAY_SRV());
        ZeroMemory(nativeObject.Get(), sizeof(D3D11_TEX2DMS_ARRAY_SRV));
    }
internal:
    AutoPointer<D3D11_TEX2DMS_ARRAY_SRV> nativeObject;
internal:
    Tex2dmsArrayShaderResourceView(D3D11_TEX2DMS_ARRAY_SRV* pTex2dmsArrayShaderResourceView)
    {
        nativeObject.Set(pTex2dmsArrayShaderResourceView);
    }
    Tex2dmsArrayShaderResourceView(D3D11_TEX2DMS_ARRAY_SRV* pTex2dmsArrayShaderResourceView, bool deletable)
    {
        nativeObject.Set(pTex2dmsArrayShaderResourceView, deletable);
    }};
/// <summary>
/// Specifies the subresource from a multisampled 2D texture that is accessable to a depth-stencil view.
/// <para>(Also see DirectX SDK: D3D11_TEX2DMS_DSV)</para>
/// </summary>
public ref struct Tex2dmsDepthStencilView 
{
public:
    /// <summary>
    /// Unused.
    /// <para>(Also see DirectX SDK: D3D11_TEX2DMS_DSV.UnusedField_NothingToDefine)</para>
    /// </summary>
    property UInt32 UnusedField_NothingToDefine
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->UnusedField_NothingToDefine);
        }
        void set(UInt32 value)
        {
            nativeObject->UnusedField_NothingToDefine = (UINT)value;
        }
    }
public:
    Tex2dmsDepthStencilView()
    {
        nativeObject.Set(new D3D11_TEX2DMS_DSV());
        ZeroMemory(nativeObject.Get(), sizeof(D3D11_TEX2DMS_DSV));
    }
internal:
    AutoPointer<D3D11_TEX2DMS_DSV> nativeObject;
internal:
    Tex2dmsDepthStencilView(D3D11_TEX2DMS_DSV* pTex2dmsDepthStencilView)
    {
        nativeObject.Set(pTex2dmsDepthStencilView);
    }
    Tex2dmsDepthStencilView(D3D11_TEX2DMS_DSV* pTex2dmsDepthStencilView, bool deletable)
    {
        nativeObject.Set(pTex2dmsDepthStencilView, deletable);
    }};
/// <summary>
/// Specifies the subresource from a multisampled 2D texture to use in a render-target view.
/// <para>(Also see DirectX SDK: D3D11_TEX2DMS_RTV)</para>
/// </summary>
public ref struct Tex2dmsRenderTargetView 
{
public:
    /// <summary>
    /// Integer of any value.
    /// <para>(Also see DirectX SDK: D3D11_TEX2DMS_RTV.UnusedField_NothingToDefine)</para>
    /// </summary>
    property UInt32 UnusedField_NothingToDefine
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->UnusedField_NothingToDefine);
        }
        void set(UInt32 value)
        {
            nativeObject->UnusedField_NothingToDefine = (UINT)value;
        }
    }
public:
    Tex2dmsRenderTargetView()
    {
        nativeObject.Set(new D3D11_TEX2DMS_RTV());
        ZeroMemory(nativeObject.Get(), sizeof(D3D11_TEX2DMS_RTV));
    }
internal:
    AutoPointer<D3D11_TEX2DMS_RTV> nativeObject;
internal:
    Tex2dmsRenderTargetView(D3D11_TEX2DMS_RTV* pTex2dmsRenderTargetView)
    {
        nativeObject.Set(pTex2dmsRenderTargetView);
    }
    Tex2dmsRenderTargetView(D3D11_TEX2DMS_RTV* pTex2dmsRenderTargetView, bool deletable)
    {
        nativeObject.Set(pTex2dmsRenderTargetView, deletable);
    }};
/// <summary>
/// Specifies the subresources from a multisampled 2D texture to use in a shader-resource view.
/// <para>(Also see DirectX SDK: D3D11_TEX2DMS_SRV)</para>
/// </summary>
public ref struct Tex2dmsShaderResourceView 
{
public:
    /// <summary>
    /// Integer of any value.
    /// <para>(Also see DirectX SDK: D3D11_TEX2DMS_SRV.UnusedField_NothingToDefine)</para>
    /// </summary>
    property UInt32 UnusedField_NothingToDefine
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->UnusedField_NothingToDefine);
        }
        void set(UInt32 value)
        {
            nativeObject->UnusedField_NothingToDefine = (UINT)value;
        }
    }
public:
    Tex2dmsShaderResourceView()
    {
        nativeObject.Set(new D3D11_TEX2DMS_SRV());
        ZeroMemory(nativeObject.Get(), sizeof(D3D11_TEX2DMS_SRV));
    }
internal:
    AutoPointer<D3D11_TEX2DMS_SRV> nativeObject;
internal:
    Tex2dmsShaderResourceView(D3D11_TEX2DMS_SRV* pTex2dmsShaderResourceView)
    {
        nativeObject.Set(pTex2dmsShaderResourceView);
    }
    Tex2dmsShaderResourceView(D3D11_TEX2DMS_SRV* pTex2dmsShaderResourceView, bool deletable)
    {
        nativeObject.Set(pTex2dmsShaderResourceView, deletable);
    }
};
/// <summary>
/// Specifies the subresources from an array 2D textures that are accessable to a depth-stencil view.
/// <para>(Also see DirectX SDK: D3D11_TEX2D_ARRAY_DSV)</para>
/// </summary>
public ref struct Tex2dArrayDepthStencilView 
{
public:
    /// <summary>
    /// The index of the first mipmap level to use.
    /// <para>(Also see DirectX SDK: D3D11_TEX2D_ARRAY_DSV.MipSlice)</para>
    /// </summary>
    property UInt32 MipSlice
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->MipSlice);
        }
        void set(UInt32 value)
        {
            nativeObject->MipSlice = (UINT)value;
        }
    }
    /// <summary>
    /// The index of the first texture to use in an array of textures.
    /// <para>(Also see DirectX SDK: D3D11_TEX2D_ARRAY_DSV.FirstArraySlice)</para>
    /// </summary>
    property UInt32 FirstArraySlice
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->FirstArraySlice);
        }
        void set(UInt32 value)
        {
            nativeObject->FirstArraySlice = (UINT)value;
        }
    }
    /// <summary>
    /// Number of textures to use.
    /// <para>(Also see DirectX SDK: D3D11_TEX2D_ARRAY_DSV.ArraySize)</para>
    /// </summary>
    property UInt32 ArraySize
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->ArraySize);
        }
        void set(UInt32 value)
        {
            nativeObject->ArraySize = (UINT)value;
        }
    }
public:
    Tex2dArrayDepthStencilView()
    {
        nativeObject.Set(new D3D11_TEX2D_ARRAY_DSV());
        ZeroMemory(nativeObject.Get(), sizeof(D3D11_TEX2D_ARRAY_DSV));
    }
internal:
    AutoPointer<D3D11_TEX2D_ARRAY_DSV> nativeObject;
internal:
    Tex2dArrayDepthStencilView(D3D11_TEX2D_ARRAY_DSV* pTex2dArrayDepthStencilView)
    {
        nativeObject.Set(pTex2dArrayDepthStencilView);
    }

    Tex2dArrayDepthStencilView(D3D11_TEX2D_ARRAY_DSV* pTex2dArrayDepthStencilView, bool deletable)
    {
        nativeObject.Set(pTex2dArrayDepthStencilView, deletable);
    }
};
/// <summary>
/// Specifies the subresources from an array of 2D textures to use in a render-target view.
/// <para>(Also see DirectX SDK: D3D11_TEX2D_ARRAY_RTV)</para>
/// </summary>
public ref struct Tex2dArrayRenderTargetView 
{
public:
    /// <summary>
    /// The index of the mipmap level to use mip slice.
    /// <para>(Also see DirectX SDK: D3D11_TEX2D_ARRAY_RTV.MipSlice)</para>
    /// </summary>
    property UInt32 MipSlice
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->MipSlice);
        }
        void set(UInt32 value)
        {
            nativeObject->MipSlice = (UINT)value;
        }
    }
    /// <summary>
    /// The index of the first texture to use in an array of textures.
    /// <para>(Also see DirectX SDK: D3D11_TEX2D_ARRAY_RTV.FirstArraySlice)</para>
    /// </summary>
    property UInt32 FirstArraySlice
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->FirstArraySlice);
        }
        void set(UInt32 value)
        {
            nativeObject->FirstArraySlice = (UINT)value;
        }
    }
    /// <summary>
    /// Number of textures in the array to use in the render target view, starting from FirstArraySlice.
    /// <para>(Also see DirectX SDK: D3D11_TEX2D_ARRAY_RTV.ArraySize)</para>
    /// </summary>
    property UInt32 ArraySize
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->ArraySize);
        }
        void set(UInt32 value)
        {
            nativeObject->ArraySize = (UINT)value;
        }
    }
public:
    Tex2dArrayRenderTargetView()
    {
        nativeObject.Set(new D3D11_TEX2D_ARRAY_RTV());
        ZeroMemory(nativeObject.Get(), sizeof(D3D11_TEX2D_ARRAY_RTV));
    }
internal:
    AutoPointer<D3D11_TEX2D_ARRAY_RTV> nativeObject;
internal:
    Tex2dArrayRenderTargetView(D3D11_TEX2D_ARRAY_RTV* pTex2dArrayRenderTargetView)
    {
        nativeObject.Set(pTex2dArrayRenderTargetView);
    }
    Tex2dArrayRenderTargetView(D3D11_TEX2D_ARRAY_RTV* pTex2dArrayRenderTargetView, bool deletable)
    {
        nativeObject.Set(pTex2dArrayRenderTargetView, deletable);
    }
};
/// <summary>
/// Specifies the subresources from an array of 2D textures to use in a shader-resource view.
/// <para>(Also see DirectX SDK: D3D11_TEX2D_ARRAY_SRV)</para>
/// </summary>
public ref struct Tex2dArrayShaderResourceView 
{
public:
    /// <summary>
    /// Index of the most detailed mipmap level to use; this number is between 0 and MipLevels.
    /// <para>(Also see DirectX SDK: D3D11_TEX2D_ARRAY_SRV.MostDetailedMip)</para>
    /// </summary>
    property UInt32 MostDetailedMip
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->MostDetailedMip);
        }
        void set(UInt32 value)
        {
            nativeObject->MostDetailedMip = (UINT)value;
        }
    }
    /// <summary>
    /// The maximum number of mipmap levels in the texture. See the remarks in Tex1dShaderResourceView.
    /// <para>(Also see DirectX SDK: D3D11_TEX2D_ARRAY_SRV.MipLevels)</para>
    /// </summary>
    property UInt32 MipLevels
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->MipLevels);
        }
        void set(UInt32 value)
        {
            nativeObject->MipLevels = (UINT)value;
        }
    }
    /// <summary>
    /// The index of the first texture to use in an array of textures.
    /// <para>(Also see DirectX SDK: D3D11_TEX2D_ARRAY_SRV.FirstArraySlice)</para>
    /// </summary>
    property UInt32 FirstArraySlice
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->FirstArraySlice);
        }
        void set(UInt32 value)
        {
            nativeObject->FirstArraySlice = (UINT)value;
        }
    }
    /// <summary>
    /// Number of textures in the array.
    /// <para>(Also see DirectX SDK: D3D11_TEX2D_ARRAY_SRV.ArraySize)</para>
    /// </summary>
    property UInt32 ArraySize
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->ArraySize);
        }
        void set(UInt32 value)
        {
            nativeObject->ArraySize = (UINT)value;
        }
    }
public:
    Tex2dArrayShaderResourceView()
    {
        nativeObject.Set(new D3D11_TEX2D_ARRAY_SRV());
        ZeroMemory(nativeObject.Get(), sizeof(D3D11_TEX2D_ARRAY_SRV));
    }
internal:
    AutoPointer<D3D11_TEX2D_ARRAY_SRV> nativeObject;
internal:
    Tex2dArrayShaderResourceView(D3D11_TEX2D_ARRAY_SRV* pTex2dArrayShaderResourceView)
    {
        nativeObject.Set(pTex2dArrayShaderResourceView);
    }
    Tex2dArrayShaderResourceView(D3D11_TEX2D_ARRAY_SRV* pTex2dArrayShaderResourceView, bool deletable)
    {
        nativeObject.Set(pTex2dArrayShaderResourceView, deletable);
    }
};
/// <summary>
/// Describes an array of unordered-access 2D texture resources.
/// <para>(Also see DirectX SDK: D3D11_TEX2D_ARRAY_UAV)</para>
/// </summary>
public ref struct Tex2dArrayUnorderedAccessView 
{
public:
    /// <summary>
    /// The mipmap slice index.
    /// <para>(Also see DirectX SDK: D3D11_TEX2D_ARRAY_UAV.MipSlice)</para>
    /// </summary>
    property UInt32 MipSlice
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->MipSlice);
        }
        void set(UInt32 value)
        {
            nativeObject->MipSlice = (UINT)value;
        }
    }
    /// <summary>
    /// The zero-based index of the first array slice to be accessed.
    /// <para>(Also see DirectX SDK: D3D11_TEX2D_ARRAY_UAV.FirstArraySlice)</para>
    /// </summary>
    property UInt32 FirstArraySlice
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->FirstArraySlice);
        }
        void set(UInt32 value)
        {
            nativeObject->FirstArraySlice = (UINT)value;
        }
    }
    /// <summary>
    /// The number of slices in the array.
    /// <para>(Also see DirectX SDK: D3D11_TEX2D_ARRAY_UAV.ArraySize)</para>
    /// </summary>
    property UInt32 ArraySize
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->ArraySize);
        }
        void set(UInt32 value)
        {
            nativeObject->ArraySize = (UINT)value;
        }
    }
public:
    Tex2dArrayUnorderedAccessView()
    {
        nativeObject.Set(new D3D11_TEX2D_ARRAY_UAV());
        ZeroMemory(nativeObject.Get(), sizeof(D3D11_TEX2D_ARRAY_UAV));
    }
internal:
    AutoPointer<D3D11_TEX2D_ARRAY_UAV> nativeObject;
internal:
    Tex2dArrayUnorderedAccessView(D3D11_TEX2D_ARRAY_UAV* pTex2dArrayUnorderedAccessView)
    {
        nativeObject.Set(pTex2dArrayUnorderedAccessView);
    }
    Tex2dArrayUnorderedAccessView(D3D11_TEX2D_ARRAY_UAV* pTex2dArrayUnorderedAccessView, bool deletable)
    {
        nativeObject.Set(pTex2dArrayUnorderedAccessView, deletable);
    }
};
/// <summary>
/// Specifies the subresource from a 2D texture that is accessable to a depth-stencil view.
/// <para>(Also see DirectX SDK: D3D11_TEX2D_DSV)</para>
/// </summary>
public ref struct Tex2dDepthStencilView 
{
public:
    /// <summary>
    /// The index of the first mipmap level to use.
    /// <para>(Also see DirectX SDK: D3D11_TEX2D_DSV.MipSlice)</para>
    /// </summary>
    property UInt32 MipSlice
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->MipSlice);
        }
        void set(UInt32 value)
        {
            nativeObject->MipSlice = (UINT)value;
        }
    }
public:
    Tex2dDepthStencilView()
    {
        nativeObject.Set(new D3D11_TEX2D_DSV());
        ZeroMemory(nativeObject.Get(), sizeof(D3D11_TEX2D_DSV));
    }
internal:
    AutoPointer<D3D11_TEX2D_DSV> nativeObject;
internal:
    Tex2dDepthStencilView(D3D11_TEX2D_DSV* pTex2dDepthStencilView)
    {
        nativeObject.Set(pTex2dDepthStencilView);
    }
    Tex2dDepthStencilView(D3D11_TEX2D_DSV* pTex2dDepthStencilView, bool deletable)
    {
        nativeObject.Set(pTex2dDepthStencilView, deletable);
    }};
/// <summary>
/// Specifies the subresource from a 2D texture to use in a render-target view.
/// <para>(Also see DirectX SDK: D3D11_TEX2D_RTV)</para>
/// </summary>
public ref struct Tex2dRenderTargetView 
{
public:
    /// <summary>
    /// The index of the mipmap level to use mip slice.
    /// <para>(Also see DirectX SDK: D3D11_TEX2D_RTV.MipSlice)</para>
    /// </summary>
    property UInt32 MipSlice
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->MipSlice);
        }
        void set(UInt32 value)
        {
            nativeObject->MipSlice = (UINT)value;
        }
    }
public:
    Tex2dRenderTargetView()
    {
        nativeObject.Set(new D3D11_TEX2D_RTV());
        ZeroMemory(nativeObject.Get(), sizeof(D3D11_TEX2D_RTV));
    }
internal:
    AutoPointer<D3D11_TEX2D_RTV> nativeObject;
internal:
    Tex2dRenderTargetView(D3D11_TEX2D_RTV* pTex2dRenderTargetView)
    {
        nativeObject.Set(pTex2dRenderTargetView);
    }
    Tex2dRenderTargetView(D3D11_TEX2D_RTV* pTex2dRenderTargetView, bool deletable)
    {
        nativeObject.Set(pTex2dRenderTargetView, deletable);
    }
};
/// <summary>
/// Specifies the subresource from a 2D texture to use in a shader-resource view.
/// <para>(Also see DirectX SDK: D3D11_TEX2D_SRV)</para>
/// </summary>
public ref struct Tex2dShaderResourceView 
{
public:
    /// <summary>
    /// Index of the most detailed mipmap level to use; this number is between 0 and MipLevels.
    /// <para>(Also see DirectX SDK: D3D11_TEX2D_SRV.MostDetailedMip)</para>
    /// </summary>
    property UInt32 MostDetailedMip
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->MostDetailedMip);
        }
        void set(UInt32 value)
        {
            nativeObject->MostDetailedMip = (UINT)value;
        }
    }
    /// <summary>
    /// The maximum number of mipmap levels in the texture. See the remarks in Tex1dShaderResourceView.
    /// <para>(Also see DirectX SDK: D3D11_TEX2D_SRV.MipLevels)</para>
    /// </summary>
    property UInt32 MipLevels
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->MipLevels);
        }
        void set(UInt32 value)
        {
            nativeObject->MipLevels = (UINT)value;
        }
    }
public:
    Tex2dShaderResourceView()
    {
        nativeObject.Set(new D3D11_TEX2D_SRV());
        ZeroMemory(nativeObject.Get(), sizeof(D3D11_TEX2D_SRV));
    }
internal:
    AutoPointer<D3D11_TEX2D_SRV> nativeObject;
internal:
    Tex2dShaderResourceView(D3D11_TEX2D_SRV* pTex2dShaderResourceView)
    {
        nativeObject.Set(pTex2dShaderResourceView);
    }
    Tex2dShaderResourceView(D3D11_TEX2D_SRV* pTex2dShaderResourceView, bool deletable)
    {
        nativeObject.Set(pTex2dShaderResourceView, deletable);
    }
};
/// <summary>
/// Describes a unordered-access 2D texture resource.
/// <para>(Also see DirectX SDK: D3D11_TEX2D_UAV)</para>
/// </summary>
public ref struct Tex2dUnorderedAccessView 
{
public:
    /// <summary>
    /// The mipmap slice index.
    /// <para>(Also see DirectX SDK: D3D11_TEX2D_UAV.MipSlice)</para>
    /// </summary>
    property UInt32 MipSlice
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->MipSlice);
        }
        void set(UInt32 value)
        {
            nativeObject->MipSlice = (UINT)value;
        }
    }
public:
    Tex2dUnorderedAccessView()
    {
        nativeObject.Set(new D3D11_TEX2D_UAV());
        ZeroMemory(nativeObject.Get(), sizeof(D3D11_TEX2D_UAV));
    }
internal:
    AutoPointer<D3D11_TEX2D_UAV> nativeObject;
internal:
    Tex2dUnorderedAccessView(D3D11_TEX2D_UAV* pTex2dUnorderedAccessView)
    {
        nativeObject.Set(pTex2dUnorderedAccessView);
    }
    Tex2dUnorderedAccessView(D3D11_TEX2D_UAV* pTex2dUnorderedAccessView, bool deletable)
    {
        nativeObject.Set(pTex2dUnorderedAccessView, deletable);
    }
};
/// <summary>
/// Specifies the subresources from a 3D texture to use in a render-target view.
/// <para>(Also see DirectX SDK: D3D11_TEX3D_RTV)</para>
/// </summary>
public ref struct Tex3dRenderTargetView 
{
public:
    /// <summary>
    /// The index of the mipmap level to use mip slice.
    /// <para>(Also see DirectX SDK: D3D11_TEX3D_RTV.MipSlice)</para>
    /// </summary>
    property UInt32 MipSlice
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->MipSlice);
        }
        void set(UInt32 value)
        {
            nativeObject->MipSlice = (UINT)value;
        }
    }
    /// <summary>
    /// First depth level to use.
    /// <para>(Also see DirectX SDK: D3D11_TEX3D_RTV.FirstWSlice)</para>
    /// </summary>
    property UInt32 FirstWSlice
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->FirstWSlice);
        }
        void set(UInt32 value)
        {
            nativeObject->FirstWSlice = (UINT)value;
        }
    }
    /// <summary>
    /// Number of depth levels to use in the render-target view, starting from FirstWSlice. A value of -1 indicates all of the slices along the w axis, starting from FirstWSlice.
    /// <para>(Also see DirectX SDK: D3D11_TEX3D_RTV.WSize)</para>
    /// </summary>
    property UInt32 WSize
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->WSize);
        }
        void set(UInt32 value)
        {
            nativeObject->WSize = (UINT)value;
        }
    }
public:
    Tex3dRenderTargetView()
    {
        nativeObject.Set(new D3D11_TEX3D_RTV());
        ZeroMemory(nativeObject.Get(), sizeof(D3D11_TEX3D_RTV));
    }
internal:
    AutoPointer<D3D11_TEX3D_RTV> nativeObject;
internal:
    Tex3dRenderTargetView(D3D11_TEX3D_RTV* pTex3dRenderTargetView)
    {
        nativeObject.Set(pTex3dRenderTargetView);
    }
    Tex3dRenderTargetView(D3D11_TEX3D_RTV* pTex3dRenderTargetView, bool deletable)
    {
        nativeObject.Set(pTex3dRenderTargetView, deletable);
    }
};
/// <summary>
/// Specifies the subresources from a 3D texture to use in a shader-resource view.
/// <para>(Also see DirectX SDK: D3D11_TEX3D_SRV)</para>
/// </summary>
public ref struct Tex3dShaderResourceView 
{
public:
    /// <summary>
    /// Index of the most detailed mipmap level to use; this number is between 0 and MipLevels.
    /// <para>(Also see DirectX SDK: D3D11_TEX3D_SRV.MostDetailedMip)</para>
    /// </summary>
    property UInt32 MostDetailedMip
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->MostDetailedMip);
        }
        void set(UInt32 value)
        {
            nativeObject->MostDetailedMip = (UINT)value;
        }
    }
    /// <summary>
    /// The maximum number of mipmap levels in the texture. See the remarks in Tex1dShaderResourceView.
    /// <para>(Also see DirectX SDK: D3D11_TEX3D_SRV.MipLevels)</para>
    /// </summary>
    property UInt32 MipLevels
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->MipLevels);
        }
        void set(UInt32 value)
        {
            nativeObject->MipLevels = (UINT)value;
        }
    }
public:
    Tex3dShaderResourceView()
    {
        nativeObject.Set(new D3D11_TEX3D_SRV());
        ZeroMemory(nativeObject.Get(), sizeof(D3D11_TEX3D_SRV));
    }
internal:
    AutoPointer<D3D11_TEX3D_SRV> nativeObject;
internal:
    Tex3dShaderResourceView(D3D11_TEX3D_SRV* pTex3dShaderResourceView)
    {
        nativeObject.Set(pTex3dShaderResourceView);
    }
    Tex3dShaderResourceView(D3D11_TEX3D_SRV* pTex3dShaderResourceView, bool deletable)
    {
        nativeObject.Set(pTex3dShaderResourceView, deletable);
    }
};
/// <summary>
/// Describes a unordered-access 3D texture resource.
/// <para>(Also see DirectX SDK: D3D11_TEX3D_UAV)</para>
/// </summary>
public ref struct Tex3dUnorderedAccessView 
{
public:
    /// <summary>
    /// The mipmap slice index.
    /// <para>(Also see DirectX SDK: D3D11_TEX3D_UAV.MipSlice)</para>
    /// </summary>
    property UInt32 MipSlice
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->MipSlice);
        }
        void set(UInt32 value)
        {
            nativeObject->MipSlice = (UINT)value;
        }
    }
    /// <summary>
    /// The zero-based index of the first depth slice to be accessed.
    /// <para>(Also see DirectX SDK: D3D11_TEX3D_UAV.FirstWSlice)</para>
    /// </summary>
    property UInt32 FirstWSlice
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->FirstWSlice);
        }
        void set(UInt32 value)
        {
            nativeObject->FirstWSlice = (UINT)value;
        }
    }
    /// <summary>
    /// The number of depth slices.
    /// <para>(Also see DirectX SDK: D3D11_TEX3D_UAV.WSize)</para>
    /// </summary>
    property UInt32 WSize
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->WSize);
        }
        void set(UInt32 value)
        {
            nativeObject->WSize = (UINT)value;
        }
    }
public:
    Tex3dUnorderedAccessView()
    {
        nativeObject.Set(new D3D11_TEX3D_UAV());
        ZeroMemory(nativeObject.Get(), sizeof(D3D11_TEX3D_UAV));
    }
internal:
    AutoPointer<D3D11_TEX3D_UAV> nativeObject;
internal:
    Tex3dUnorderedAccessView(D3D11_TEX3D_UAV* pTex3dUnorderedAccessView)
    {
        nativeObject.Set(pTex3dUnorderedAccessView);
    }
    Tex3dUnorderedAccessView(D3D11_TEX3D_UAV* pTex3dUnorderedAccessView, bool deletable)
    {
        nativeObject.Set(pTex3dUnorderedAccessView, deletable);
    }
};
/// <summary>
/// Specifies the subresources from an array of cube textures to use in a shader-resource view.
/// <para>(Also see DirectX SDK: D3D11_TEXCUBE_ARRAY_SRV)</para>
/// </summary>
public ref struct TexcubeArrayShaderResourceView 
{
public:
    /// <summary>
    /// Index of the most detailed mipmap level to use; this number is between 0 and MipLevels.
    /// <para>(Also see DirectX SDK: D3D11_TEXCUBE_ARRAY_SRV.MostDetailedMip)</para>
    /// </summary>
    property UInt32 MostDetailedMip
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->MostDetailedMip);
        }
        void set(UInt32 value)
        {
            nativeObject->MostDetailedMip = (UINT)value;
        }
    }
    /// <summary>
    /// The maximum number of mipmap levels in the texture. See the remarks in Tex1dShaderResourceView.
    /// <para>(Also see DirectX SDK: D3D11_TEXCUBE_ARRAY_SRV.MipLevels)</para>
    /// </summary>
    property UInt32 MipLevels
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->MipLevels);
        }
        void set(UInt32 value)
        {
            nativeObject->MipLevels = (UINT)value;
        }
    }
    /// <summary>
    /// Index of the first 2D texture to use.
    /// <para>(Also see DirectX SDK: D3D11_TEXCUBE_ARRAY_SRV.First2DArrayFace)</para>
    /// </summary>
    property UInt32 First2DArrayFace
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->First2DArrayFace);
        }
        void set(UInt32 value)
        {
            nativeObject->First2DArrayFace = (UINT)value;
        }
    }
    /// <summary>
    /// Number of cube textures in the array.
    /// <para>(Also see DirectX SDK: D3D11_TEXCUBE_ARRAY_SRV.NumCubes)</para>
    /// </summary>
    property UInt32 NumCubes
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->NumCubes);
        }
        void set(UInt32 value)
        {
            nativeObject->NumCubes = (UINT)value;
        }
    }
public:
    TexcubeArrayShaderResourceView()
    {
        nativeObject.Set(new D3D11_TEXCUBE_ARRAY_SRV());
        ZeroMemory(nativeObject.Get(), sizeof(D3D11_TEXCUBE_ARRAY_SRV));
    }
internal:
    AutoPointer<D3D11_TEXCUBE_ARRAY_SRV> nativeObject;
internal:
    TexcubeArrayShaderResourceView(D3D11_TEXCUBE_ARRAY_SRV* pTexcubeArrayShaderResourceView)
    {
        nativeObject.Set(pTexcubeArrayShaderResourceView);
    }
    TexcubeArrayShaderResourceView(D3D11_TEXCUBE_ARRAY_SRV* pTexcubeArrayShaderResourceView, bool deletable)
    {
        nativeObject.Set(pTexcubeArrayShaderResourceView, deletable);
    }
};
/// <summary>
/// Specifies the subresource from a cube texture to use in a shader-resource view.
/// <para>(Also see DirectX SDK: D3D11_TEXCUBE_SRV)</para>
/// </summary>
public ref struct TexcubeShaderResourceView 
{
public:
    /// <summary>
    /// Index of the most detailed mipmap level to use; this number is between 0 and MipLevels.
    /// <para>(Also see DirectX SDK: D3D11_TEXCUBE_SRV.MostDetailedMip)</para>
    /// </summary>
    property UInt32 MostDetailedMip
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->MostDetailedMip);
        }
        void set(UInt32 value)
        {
            nativeObject->MostDetailedMip = (UINT)value;
        }
    }
    /// <summary>
    /// The maximum number of mipmap levels in the texture. See the remarks in Tex1dShaderResourceView.
    /// <para>(Also see DirectX SDK: D3D11_TEXCUBE_SRV.MipLevels)</para>
    /// </summary>
    property UInt32 MipLevels
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->MipLevels);
        }
        void set(UInt32 value)
        {
            nativeObject->MipLevels = (UINT)value;
        }
    }
public:
    TexcubeShaderResourceView()
    {
        nativeObject.Set(new D3D11_TEXCUBE_SRV());
        ZeroMemory(nativeObject.Get(), sizeof(D3D11_TEXCUBE_SRV));
    }
internal:
    AutoPointer<D3D11_TEXCUBE_SRV> nativeObject;
internal:
    TexcubeShaderResourceView(D3D11_TEXCUBE_SRV* pTexcubeShaderResourceView)
    {
        nativeObject.Set(pTexcubeShaderResourceView);
    }
    TexcubeShaderResourceView(D3D11_TEXCUBE_SRV* pTexcubeShaderResourceView, bool deletable)
    {
        nativeObject.Set(pTexcubeShaderResourceView, deletable);
    }
};
/// <summary>
/// Describes a 1D texture.
/// <para>(Also see DirectX SDK: D3D11_TEXTURE1D_DESC)</para>
/// </summary>
public ref struct Texture1dDescription 
{
public:
    /// <summary>
    /// Texture width (in texels).
    /// <para>(Also see DirectX SDK: D3D11_TEXTURE1D_DESC.Width)</para>
    /// </summary>
    property UInt32 Width
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->Width);
        }
        void set(UInt32 value)
        {
            nativeObject->Width = (UINT)value;
        }
    }
    /// <summary>
    /// The maximum number of mipmap levels in the texture. See the remarks in Tex1dShaderResourceView. Use 1 for a multisampled texture; or 0 to generate a full set of subtextures.
    /// <para>(Also see DirectX SDK: D3D11_TEXTURE1D_DESC.MipLevels)</para>
    /// </summary>
    property UInt32 MipLevels
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->MipLevels);
        }
        void set(UInt32 value)
        {
            nativeObject->MipLevels = (UINT)value;
        }
    }
    /// <summary>
    /// Number of textures in the array.
    /// <para>(Also see DirectX SDK: D3D11_TEXTURE1D_DESC.ArraySize)</para>
    /// </summary>
    property UInt32 ArraySize
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->ArraySize);
        }
        void set(UInt32 value)
        {
            nativeObject->ArraySize = (UINT)value;
        }
    }
    /// <summary>
    /// Texture format (see <see cref="Format"/>)<seealso cref="Format"/>.
    /// <para>(Also see DirectX SDK: D3D11_TEXTURE1D_DESC.Format)</para>
    /// </summary>
    property Format Texture1dFormat
    {
        Format get()
        {
            return (Format)(nativeObject->Format);
        }
        void set(Format value)
        {
            nativeObject->Format = (DXGI_FORMAT)value;
        }
    }
    /// <summary>
    /// Value that identifies how the texture is to be read from and written to. The most common value is Usage-DEFAULT; see Usage for all possible values.
    /// <para>(Also see DirectX SDK: D3D11_TEXTURE1D_DESC.Usage)</para>
    /// </summary>
    property Usage Texture1dUsage
    {
        Usage get()
        {
            return (Usage)(nativeObject->Usage);
        }
        void set(Usage value)
        {
            nativeObject->Usage = (D3D11_USAGE)value;
        }
    }
    /// <summary>
    /// Flags (see <see cref="BindFlag"/>)<seealso cref="BindFlag"/> for binding to pipeline stages. The flags can be combined by a logical OR. For a 1D texture, the allowable values are: ShaderResource, RenderTarget and DepthStencil.
    /// <para>(Also see DirectX SDK: D3D11_TEXTURE1D_DESC.BindFlags)</para>
    /// </summary>
    property BindFlag BindFlags
    {
        BindFlag get()
        {
            return (BindFlag)(nativeObject->BindFlags);
        }
        void set(BindFlag value)
        {
            nativeObject->BindFlags = (UINT)value;
        }
    }
    /// <summary>
    /// Flags (see <see cref="CpuAccessFlag"/>)<seealso cref="CpuAccessFlag"/> to specify the types of CPU access allowed. Use 0 if CPU access is not required. These flags can be combined with a logical OR.
    /// <para>(Also see DirectX SDK: D3D11_TEXTURE1D_DESC.CPUAccessFlags)</para>
    /// </summary>
    property CpuAccessFlag CPUAccessFlags
    {
        CpuAccessFlag get()
        {
            return (CpuAccessFlag)(nativeObject->CPUAccessFlags);
        }
        void set(CpuAccessFlag value)
        {
            nativeObject->CPUAccessFlags = (UINT)value;
        }
    }
    /// <summary>
    /// Flags (see <see cref="ResourceMiscFlag"/>)<seealso cref="ResourceMiscFlag"/> that identifies other, less common resource options. Use 0 if none of these flags apply. These flags can be combined with a logical OR.
    /// <para>(Also see DirectX SDK: D3D11_TEXTURE1D_DESC.MiscFlags)</para>
    /// </summary>
    property ResourceMiscFlag MiscFlags
    {
        ResourceMiscFlag get()
        {
            return (ResourceMiscFlag)(nativeObject->MiscFlags);
        }
        void set(ResourceMiscFlag value)
        {
            nativeObject->MiscFlags = (UINT)value;
        }
    }
public:
    Texture1dDescription()
    {
        nativeObject.Set(new D3D11_TEXTURE1D_DESC());
        ZeroMemory(nativeObject.Get(), sizeof(D3D11_TEXTURE1D_DESC));
    }
internal:
    AutoPointer<D3D11_TEXTURE1D_DESC> nativeObject;
internal:
    Texture1dDescription(D3D11_TEXTURE1D_DESC* pTexture1dDescription)
    {
        nativeObject.Set(pTexture1dDescription);
    }
    Texture1dDescription(D3D11_TEXTURE1D_DESC* pTexture1dDescription, bool deletable)
    {
        nativeObject.Set(pTexture1dDescription, deletable);
    }
};
/// <summary>
/// Describes a 2D texture.
/// <para>(Also see DirectX SDK: D3D11_TEXTURE2D_DESC)</para>
/// </summary>
public ref struct Texture2dDescription 
{
public:
    /// <summary>
    /// Texture width (in texels). See Remarks.
    /// <para>(Also see DirectX SDK: D3D11_TEXTURE2D_DESC.Width)</para>
    /// </summary>
    property UInt32 Width
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->Width);
        }
        void set(UInt32 value)
        {
            nativeObject->Width = (UINT)value;
        }
    }
    /// <summary>
    /// Texture height (in texels). See Remarks.
    /// <para>(Also see DirectX SDK: D3D11_TEXTURE2D_DESC.Height)</para>
    /// </summary>
    property UInt32 Height
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->Height);
        }
        void set(UInt32 value)
        {
            nativeObject->Height = (UINT)value;
        }
    }
    /// <summary>
    /// The maximum number of mipmap levels in the texture. See the remarks in Tex1dShaderResourceView. Use 1 for a multisampled texture; or 0 to generate a full set of subtextures.
    /// <para>(Also see DirectX SDK: D3D11_TEXTURE2D_DESC.MipLevels)</para>
    /// </summary>
    property UInt32 MipLevels
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->MipLevels);
        }
        void set(UInt32 value)
        {
            nativeObject->MipLevels = (UINT)value;
        }
    }
    /// <summary>
    /// Number of textures in the texture array.
    /// <para>(Also see DirectX SDK: D3D11_TEXTURE2D_DESC.ArraySize)</para>
    /// </summary>
    property UInt32 ArraySize
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->ArraySize);
        }
        void set(UInt32 value)
        {
            nativeObject->ArraySize = (UINT)value;
        }
    }
    /// <summary>
    /// Texture format (see <see cref="Format"/>)<seealso cref="Format"/>.
    /// <para>(Also see DirectX SDK: D3D11_TEXTURE2D_DESC.Format)</para>
    /// </summary>
    property Format Texture2DFormat
    {
        Format get()
        {
            return (Format)(nativeObject->Format);
        }
        void set(Format value)
        {
            nativeObject->Format = (DXGI_FORMAT)value;
        }
    }
    /// <summary>
    /// Structure that specifies multisampling parameters for the texture. See SampleDescription.
    /// <para>(Also see DirectX SDK: D3D11_TEXTURE2D_DESC.SampleDesc)</para>
    /// </summary>
    property SampleDescription^ SampleDesc
    {
        SampleDescription^ get()
        {
            if (sampleDescription == nullptr)
                sampleDescription  = gcnew SampleDescription(&(nativeObject->SampleDesc), false);

            return sampleDescription;
        }
        void set(SampleDescription^ value)
        {
            memcpy(&(nativeObject->SampleDesc), (void*)(value->nativeObject.Get()), sizeof(DXGI_SAMPLE_DESC));
        }
    }
    /// <summary>
    /// Value that identifies how the texture is to be read from and written to. The most common value is Usage-DEFAULT; see Usage for all possible values.
    /// <para>(Also see DirectX SDK: D3D11_TEXTURE2D_DESC.Usage)</para>
    /// </summary>
    property Usage Texture2DUsage
    {
        Usage get()
        {
            return (Usage)(nativeObject->Usage);
        }
        void set(Usage value)
        {
            nativeObject->Usage = (D3D11_USAGE)value;
        }
    }
    /// <summary>
    /// Flags (see <see cref="BindFlag"/>)<seealso cref="BindFlag"/> for binding to pipeline stages. The flags can be combined by a logical OR.
    /// <para>(Also see DirectX SDK: D3D11_TEXTURE2D_DESC.BindFlags)</para>
    /// </summary>
    property BindFlag BindFlags
    {
        BindFlag get()
        {
            return (BindFlag)(nativeObject->BindFlags);
        }
        void set(BindFlag value)
        {
            nativeObject->BindFlags = (UINT)value;
        }
    }
    /// <summary>
    /// Flags (see <see cref="CpuAccessFlag"/>)<seealso cref="CpuAccessFlag"/> to specify the types of CPU access allowed. Use 0 if CPU access is not required. These flags can be combined with a logical OR.
    /// <para>(Also see DirectX SDK: D3D11_TEXTURE2D_DESC.CPUAccessFlags)</para>
    /// </summary>
    property CpuAccessFlag CPUAccessFlags
    {
        CpuAccessFlag get()
        {
            return (CpuAccessFlag)(nativeObject->CPUAccessFlags);
        }
        void set(CpuAccessFlag value)
        {
            nativeObject->CPUAccessFlags = (UINT)value;
        }
    }
    /// <summary>
    /// Flags (see <see cref="ResourceMiscFlag"/>)<seealso cref="ResourceMiscFlag"/> that identifies other, less common resource options. Use 0 if none of these flags apply. These flags can be combined with a logical OR.
    /// <para>(Also see DirectX SDK: D3D11_TEXTURE2D_DESC.MiscFlags)</para>
    /// </summary>
    property ResourceMiscFlag MiscFlags
    {
        ResourceMiscFlag get()
        {
            return (ResourceMiscFlag)(nativeObject->MiscFlags);
        }
        void set(ResourceMiscFlag value)
        {
            nativeObject->MiscFlags = (UINT)value;
        }
    }
public:
    Texture2dDescription()
    {
        nativeObject.Set(new D3D11_TEXTURE2D_DESC());
        ZeroMemory(nativeObject.Get(), sizeof(D3D11_TEXTURE2D_DESC));
    }
internal:
    AutoPointer<D3D11_TEXTURE2D_DESC> nativeObject;
internal:
    Texture2dDescription(D3D11_TEXTURE2D_DESC* pTexture2dDescription)
    {
        nativeObject.Set(pTexture2dDescription);
    }

    Texture2dDescription(D3D11_TEXTURE2D_DESC* pTexture2dDescription, bool deletable)
    {
        nativeObject.Set(pTexture2dDescription, deletable);
    }
private:
    SampleDescription^ sampleDescription;
};
/// <summary>
/// Describes a 3D texture.
/// <para>(Also see DirectX SDK: D3D11_TEXTURE3D_DESC)</para>
/// </summary>
public ref struct Texture3dDescription 
{
public:
    /// <summary>
    /// Texture width (in texels). See Remarks.
    /// <para>(Also see DirectX SDK: D3D11_TEXTURE3D_DESC.Width)</para>
    /// </summary>
    property UInt32 Width
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->Width);
        }
        void set(UInt32 value)
        {
            nativeObject->Width = (UINT)value;
        }
    }
    /// <summary>
    /// Texture height (in texels). See Remarks.
    /// <para>(Also see DirectX SDK: D3D11_TEXTURE3D_DESC.Height)</para>
    /// </summary>
    property UInt32 Height
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->Height);
        }
        void set(UInt32 value)
        {
            nativeObject->Height = (UINT)value;
        }
    }
    /// <summary>
    /// Texture depth (in texels)
    /// <para>(Also see DirectX SDK: D3D11_TEXTURE3D_DESC.Depth)</para>
    /// </summary>
    property UInt32 Depth
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->Depth);
        }
        void set(UInt32 value)
        {
            nativeObject->Depth = (UINT)value;
        }
    }
    /// <summary>
    /// The maximum number of mipmap levels in the texture. See the remarks in Tex1dShaderResourceView. Use 1 for a multisampled texture; or 0 to generate a full set of subtextures.
    /// <para>(Also see DirectX SDK: D3D11_TEXTURE3D_DESC.MipLevels)</para>
    /// </summary>
    property UInt32 MipLevels
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->MipLevels);
        }
        void set(UInt32 value)
        {
            nativeObject->MipLevels = (UINT)value;
        }
    }
    /// <summary>
    /// Texture format (see <see cref="Format"/>)<seealso cref="Format"/>.
    /// <para>(Also see DirectX SDK: D3D11_TEXTURE3D_DESC.Format)</para>
    /// </summary>
    property Format Texture3dFormat
    {
        Format get()
        {
            return (Format)(nativeObject->Format);
        }
        void set(Format value)
        {
            nativeObject->Format = (DXGI_FORMAT)value;
        }
    }
    /// <summary>
    /// Value that identifies how the texture is to be read from and written to. The most common value is Usage-DEFAULT; see Usage for all possible values.
    /// <para>(Also see DirectX SDK: D3D11_TEXTURE3D_DESC.Usage)</para>
    /// </summary>
    property Usage Texture3dUsage
    {
        Usage get()
        {
            return (Usage)(nativeObject->Usage);
        }
        void set(Usage value)
        {
            nativeObject->Usage = (D3D11_USAGE)value;
        }
    }
    /// <summary>
    /// Flags (see <see cref="BindFlag"/>)<seealso cref="BindFlag"/> for binding to pipeline stages. The flags can be combined by a logical OR.
    /// <para>(Also see DirectX SDK: D3D11_TEXTURE3D_DESC.BindFlags)</para>
    /// </summary>
    property BindFlag BindFlags
    {
        BindFlag get()
        {
            return (BindFlag)(nativeObject->BindFlags);
        }
        void set(BindFlag value)
        {
            nativeObject->BindFlags = (UINT)value;
        }
    }
    /// <summary>
    /// Flags (see <see cref="CpuAccessFlag"/>)<seealso cref="CpuAccessFlag"/> to specify the types of CPU access allowed. Use 0 if CPU access is not required. These flags can be combined with a logical OR.
    /// <para>(Also see DirectX SDK: D3D11_TEXTURE3D_DESC.CPUAccessFlags)</para>
    /// </summary>
    property CpuAccessFlag CPUAccessFlags
    {
        CpuAccessFlag get()
        {
            return (CpuAccessFlag)(nativeObject->CPUAccessFlags);
        }
        void set(CpuAccessFlag value)
        {
            nativeObject->CPUAccessFlags = (UINT)value;
        }
    }
    /// <summary>
    /// Flags (see <see cref="ResourceMiscFlag"/>)<seealso cref="ResourceMiscFlag"/> that identifies other, less common resource options. Use 0 if none of these flags apply. These flags can be combined with a logical OR.
    /// <para>(Also see DirectX SDK: D3D11_TEXTURE3D_DESC.MiscFlags)</para>
    /// </summary>
    property ResourceMiscFlag MiscFlags
    {
        ResourceMiscFlag get()
        {
            return (ResourceMiscFlag)(nativeObject->MiscFlags);
        }
        void set(ResourceMiscFlag value)
        {
            nativeObject->MiscFlags = (UINT)value;
        }
    }
public:
    Texture3dDescription()
    {
        nativeObject.Set(new D3D11_TEXTURE3D_DESC());
        ZeroMemory(nativeObject.Get(), sizeof(D3D11_TEXTURE3D_DESC));
    }
internal:
    AutoPointer<D3D11_TEXTURE3D_DESC> nativeObject;
internal:
    Texture3dDescription(D3D11_TEXTURE3D_DESC* pTexture3dDescription)
    {
        nativeObject.Set(pTexture3dDescription);
    }
    Texture3dDescription(D3D11_TEXTURE3D_DESC* pTexture3dDescription, bool deletable)
    {
        nativeObject.Set(pTexture3dDescription, deletable);
    }
};
/// <summary>
/// Specifies the subresources of a texture that are accessible from a depth-stencil view.
/// <para>(Also see DirectX SDK: D3D11_DEPTH_STENCIL_VIEW_DESC)</para>
/// </summary>
public ref struct DepthStencilViewDescription 
{
public:
    /// <summary>
    /// Resource data  format (see <see cref="Format"/>)<seealso cref="Format"/>. See remarks for allowable formats.
    /// <para>(Also see DirectX SDK: D3D11_DEPTH_STENCIL_VIEW_DESC.Format)</para>
    /// </summary>
    property Format ResourceDataFormat
    {
        Format get()
        {
            return (Format)(nativeObject->Format);
        }
        void set(Format value)
        {
            nativeObject->Format = (DXGI_FORMAT)value;
        }
    }
    /// <summary>
    /// Type of resource (see <see cref="DepthStencilViewDimension"/>)<seealso cref="DepthStencilViewDimension"/>. Specifies how a depth-stencil resource will be accessed; the value is stored in the union in this structure.
    /// <para>(Also see DirectX SDK: D3D11_DEPTH_STENCIL_VIEW_DESC.ViewDimension)</para>
    /// </summary>
    property DepthStencilViewDimension ViewDimension
    {
        DepthStencilViewDimension get()
        {
            return (DepthStencilViewDimension)(nativeObject->ViewDimension);
        }
        void set(DepthStencilViewDimension value)
        {
            nativeObject->ViewDimension = (D3D11_DSV_DIMENSION)value;
        }
    }
    /// <summary>
    /// A value that describes whether the texture is read only.  Pass 0 to specify that it is not read only; otherwise, pass one of the members of the DepthStencilViewFlag enumerated type.
    /// <para>(Also see DirectX SDK: D3D11_DEPTH_STENCIL_VIEW_DESC.Flags)</para>
    /// </summary>
    property DepthStencilViewFlag Flags
    {
        DepthStencilViewFlag get()
        {
            return (DepthStencilViewFlag)(nativeObject->Flags);
        }
        void set(DepthStencilViewFlag value)
        {
            nativeObject->Flags = (UINT)value;
        }
    }
    /// <summary>
    /// Specifies a 1D texture subresource (see <see cref="Tex1dDepthStencilView"/>)<seealso cref="Tex1dDepthStencilView"/>.
    /// <para>(Also see DirectX SDK: D3D11_DEPTH_STENCIL_VIEW_DESC.Texture1D)</para>
    /// </summary>
    property Tex1dDepthStencilView^ Texture1D
    {
        Tex1dDepthStencilView^ get()
        {
            if (texture1D == nullptr)
                texture1D =  gcnew Tex1dDepthStencilView(&(nativeObject->Texture1D), false);
            return texture1D;
        }
        void set(Tex1dDepthStencilView^ value)
        {
            memcpy(&(nativeObject->Texture1D), (void*)(value->nativeObject.Get()), sizeof(D3D11_TEX1D_DSV));
        }
    }
    /// <summary>
    /// Specifies an array of 1D texture subresources (see <see cref="Tex1dArrayDepthStencilView"/>)<seealso cref="Tex1dArrayDepthStencilView"/>.
    /// <para>(Also see DirectX SDK: D3D11_DEPTH_STENCIL_VIEW_DESC.Texture1DArray)</para>
    /// </summary>
    property Tex1dArrayDepthStencilView^ Texture1DArray
    {
        Tex1dArrayDepthStencilView^ get()
        {
            if (texture1DArray == nullptr)
                texture1DArray = gcnew Tex1dArrayDepthStencilView(&(nativeObject->Texture1DArray), false);
            return texture1DArray;
        }
        void set(Tex1dArrayDepthStencilView^ value)
        {
            memcpy(&(nativeObject->Texture1DArray), (void*)(value->nativeObject.Get()), sizeof(D3D11_TEX1D_ARRAY_DSV));
        }
    }
    /// <summary>
    /// Specifies a 2D texture subresource (see <see cref="Tex2dDepthStencilView"/>)<seealso cref="Tex2dDepthStencilView"/>.
    /// <para>(Also see DirectX SDK: D3D11_DEPTH_STENCIL_VIEW_DESC.Texture2D)</para>
    /// </summary>
    property Tex2dDepthStencilView^ Texture2D
    {
        Tex2dDepthStencilView^ get()
        {
            if (texture2D == nullptr)
                texture2D =  gcnew Tex2dDepthStencilView(&(nativeObject->Texture2D), false);
            return texture2D ;
        }
        void set(Tex2dDepthStencilView^ value)
        {
            memcpy(&(nativeObject->Texture2D), (void*)(value->nativeObject.Get()), sizeof(D3D11_TEX2D_DSV));
        }
    }
    /// <summary>
    /// Specifies an array of 2D texture subresources (see <see cref="Tex2dArrayDepthStencilView"/>)<seealso cref="Tex2dArrayDepthStencilView"/>.
    /// <para>(Also see DirectX SDK: D3D11_DEPTH_STENCIL_VIEW_DESC.Texture2DArray)</para>
    /// </summary>
    property Tex2dArrayDepthStencilView^ Texture2DArray
    {
        Tex2dArrayDepthStencilView^ get()
        {
            if (texture2DArray == nullptr)
                texture2DArray =  gcnew Tex2dArrayDepthStencilView(&(nativeObject->Texture2DArray), false);
            return texture2DArray;
        }
        void set(Tex2dArrayDepthStencilView^ value)
        {
            memcpy(&(nativeObject->Texture2DArray), (void*)(value->nativeObject.Get()), sizeof(D3D11_TEX2D_ARRAY_DSV));
        }
    }
    /// <summary>
    /// Specifies a multisampled 2D texture (see <see cref="Tex2dmsDepthStencilView"/>)<seealso cref="Tex2dmsDepthStencilView"/>.
    /// <para>(Also see DirectX SDK: D3D11_DEPTH_STENCIL_VIEW_DESC.Texture2DMS)</para>
    /// </summary>
    property Tex2dmsDepthStencilView^ Texture2DMS
    {
        Tex2dmsDepthStencilView^ get()
        {
            if ( texture2DMS == nullptr)
                 texture2DMS = gcnew Tex2dmsDepthStencilView(&(nativeObject->Texture2DMS), false);
            return texture2DMS;
        }
        void set(Tex2dmsDepthStencilView^ value)
        {
            memcpy(&(nativeObject->Texture2DMS), (void*)(value->nativeObject.Get()), sizeof(D3D11_TEX2DMS_DSV));
        }
    }
    /// <summary>
    /// Specifies an array of multisampled 2D textures (see <see cref="Tex2dmsArrayDepthStencilView"/>)<seealso cref="Tex2dmsArrayDepthStencilView"/>.
    /// <para>(Also see DirectX SDK: D3D11_DEPTH_STENCIL_VIEW_DESC.Texture2DMSArray)</para>
    /// </summary>
    property Tex2dmsArrayDepthStencilView^ Texture2DMSArray
    {
        Tex2dmsArrayDepthStencilView^ get()
        {
            if (texture2DMSArray == nullptr)
                texture2DMSArray = gcnew Tex2dmsArrayDepthStencilView(&(nativeObject->Texture2DMSArray), false);
            return texture2DMSArray;
        }
        void set(Tex2dmsArrayDepthStencilView^ value)
        {
            memcpy(&(nativeObject->Texture2DMSArray), (void*)(value->nativeObject.Get()), sizeof(D3D11_TEX2DMS_ARRAY_DSV));
        }
    }
public:
    DepthStencilViewDescription()
    {
        nativeObject.Set(new D3D11_DEPTH_STENCIL_VIEW_DESC());
        ZeroMemory(nativeObject.Get(), sizeof(D3D11_DEPTH_STENCIL_VIEW_DESC));
    }
internal:
    AutoPointer<D3D11_DEPTH_STENCIL_VIEW_DESC> nativeObject;
internal:
    DepthStencilViewDescription(D3D11_DEPTH_STENCIL_VIEW_DESC* pDepthStencilViewDescription)
    {
        nativeObject.Set(pDepthStencilViewDescription);
    }
    
    DepthStencilViewDescription(D3D11_DEPTH_STENCIL_VIEW_DESC* pDepthStencilViewDescription, bool deletable)
    {
        nativeObject.Set(pDepthStencilViewDescription, deletable);
    }
private:
    Tex1dDepthStencilView^ texture1D;
    Tex1dArrayDepthStencilView^ texture1DArray;
    Tex2dDepthStencilView^ texture2D;
    Tex2dArrayDepthStencilView^ texture2DArray;
    Tex2dmsDepthStencilView^ texture2DMS;
    Tex2dmsArrayDepthStencilView^ texture2DMSArray;
};
/// <summary>
/// Describes depth-stencil state.
/// <para>(Also see DirectX SDK: D3D11_DEPTH_STENCIL_DESC)</para>
/// </summary>
public ref struct DepthStencilDescription 
{
public:
    /// <summary>
    /// Enable depth testing.
    /// <para>(Also see DirectX SDK: D3D11_DEPTH_STENCIL_DESC.DepthEnable)</para>
    /// </summary>
    property Boolean DepthEnable
    {
        Boolean get()
        {
            return nativeObject->DepthEnable != 0;
        }
        void set(Boolean value)
        {
            nativeObject->DepthEnable = (BOOL)value;
        }
    }
    /// <summary>
    /// Identify a portion of the depth-stencil buffer that can be modified by depth data (see <see cref="DepthWriteMask"/>)<seealso cref="DepthWriteMask"/>.
    /// <para>(Also see DirectX SDK: D3D11_DEPTH_STENCIL_DESC.DepthWriteMask)</para>
    /// </summary>
    property DepthWriteMask Mask
    {
        DepthWriteMask get()
        {
            return (DepthWriteMask)(nativeObject->DepthWriteMask);
        }
        void set(DepthWriteMask value)
        {
            nativeObject->DepthWriteMask = (D3D11_DEPTH_WRITE_MASK)value;
        }
    }
    /// <summary>
    /// A function that compares depth data against existing depth data. The function options are listed in ComparisonFunc.
    /// <para>(Also see DirectX SDK: D3D11_DEPTH_STENCIL_DESC.DepthFunc)</para>
    /// </summary>
    property ComparisonFunc DepthFunc
    {
        ComparisonFunc get()
        {
            return (ComparisonFunc)(nativeObject->DepthFunc);
        }
        void set(ComparisonFunc value)
        {
            nativeObject->DepthFunc = (D3D11_COMPARISON_FUNC)value;
        }
    }
    /// <summary>
    /// Enable stencil testing.
    /// <para>(Also see DirectX SDK: D3D11_DEPTH_STENCIL_DESC.StencilEnable)</para>
    /// </summary>
    property Boolean StencilEnable
    {
        Boolean get()
        {
            return nativeObject->StencilEnable != 0;
        }
        void set(Boolean value)
        {
            nativeObject->StencilEnable = (BOOL)value;
        }
    }
    /// <summary>
    /// Identify a portion of the depth-stencil buffer for reading stencil data.
    /// <para>(Also see DirectX SDK: D3D11_DEPTH_STENCIL_DESC.StencilReadMask)</para>
    /// </summary>
    property Byte StencilReadMask
    {
        Byte get()
        {
            return (Byte)(nativeObject->StencilReadMask);
        }
        void set(Byte value)
        {
            nativeObject->StencilReadMask = (UINT8)value;
        }
    }
    /// <summary>
    /// Identify a portion of the depth-stencil buffer for writing stencil data.
    /// <para>(Also see DirectX SDK: D3D11_DEPTH_STENCIL_DESC.StencilWriteMask)</para>
    /// </summary>
    property Byte StencilWriteMask
    {
        Byte get()
        {
            return (Byte)(nativeObject->StencilWriteMask);
        }
        void set(Byte value)
        {
            nativeObject->StencilWriteMask = (UINT8)value;
        }
    }
    /// <summary>
    /// Identify how to use the results of the depth test and the stencil test for pixels whose surface normal is facing towards the camera (see <see cref="DepthStencilopDescription"/>)<seealso cref="DepthStencilopDescription"/>.
    /// <para>(Also see DirectX SDK: D3D11_DEPTH_STENCIL_DESC.FrontFace)</para>
    /// </summary>
    property DepthStencilopDescription^ FrontFace
    {
        DepthStencilopDescription^ get()
        {
            if (frontFace == nullptr)
                frontFace = gcnew DepthStencilopDescription(&(nativeObject->FrontFace), false);
            return frontFace;
        }
        void set(DepthStencilopDescription^ value)
        {
            memcpy(&(nativeObject->FrontFace), (void*)(value->nativeObject.Get()), sizeof(D3D11_DEPTH_STENCILOP_DESC));
        }
    }
    /// <summary>
    /// Identify how to use the results of the depth test and the stencil test for pixels whose surface normal is facing away from the camera (see <see cref="DepthStencilopDescription"/>)<seealso cref="DepthStencilopDescription"/>.
    /// <para>(Also see DirectX SDK: D3D11_DEPTH_STENCIL_DESC.BackFace)</para>
    /// </summary>
    property DepthStencilopDescription^ BackFace
    {
        DepthStencilopDescription^ get()
        {
            if (backFace == nullptr)
                backFace = gcnew DepthStencilopDescription(&(nativeObject->BackFace), false);
            return backFace;
        }
        void set(DepthStencilopDescription^ value)
        {
            memcpy(&(nativeObject->BackFace), (void*)(value->nativeObject.Get()), sizeof(D3D11_DEPTH_STENCILOP_DESC));
        }
    }
public:
    DepthStencilDescription()
    {
        nativeObject.Set(new D3D11_DEPTH_STENCIL_DESC());
        ZeroMemory(nativeObject.Get(), sizeof(D3D11_DEPTH_STENCIL_DESC));
    }
internal:
    AutoPointer<D3D11_DEPTH_STENCIL_DESC> nativeObject;
internal:
    DepthStencilDescription(D3D11_DEPTH_STENCIL_DESC* pDepthStencilDescription)
    {
        nativeObject.Set(pDepthStencilDescription);
    }
    DepthStencilDescription(D3D11_DEPTH_STENCIL_DESC* pDepthStencilDescription, bool deletable)
    {
        nativeObject.Set(pDepthStencilDescription, deletable);
    }
private:
    DepthStencilopDescription^ frontFace;
    DepthStencilopDescription^ backFace;
};
/// <summary>
/// Describes the multi-threading features that are supported by the current graphics driver.
/// <para>(Also see DirectX SDK: D3D11_FEATURE_DATA_THREADING)</para>
/// </summary>
public ref struct FeatureDataThreading 
{
public:
    /// <summary>
    /// TRUE means resources can be created concurrently on multiple threads while drawing; FALSE means that the presence of coarse synchronization will prevent concurrency.
    /// <para>(Also see DirectX SDK: D3D11_FEATURE_DATA_THREADING.DriverConcurrentCreates)</para>
    /// </summary>
    property Boolean DriverConcurrentCreates
    {
        Boolean get()
        {
            return nativeObject->DriverConcurrentCreates != 0;
        }
        void set(Boolean value)
        {
            nativeObject->DriverConcurrentCreates = (BOOL)value;
        }
    }
    /// <summary>
    /// TRUE means command lists are supported by the current driver; FALSE means that the API will emulate deferred contexts and command lists with software.
    /// <para>(Also see DirectX SDK: D3D11_FEATURE_DATA_THREADING.DriverCommandLists)</para>
    /// </summary>
    property Boolean DriverCommandLists
    {
        Boolean get()
        {
            return nativeObject->DriverCommandLists != 0;
        }
        void set(Boolean value)
        {
            nativeObject->DriverCommandLists = (BOOL)value;
        }
    }
public:
    FeatureDataThreading()
    {
        nativeObject.Set(new D3D11_FEATURE_DATA_THREADING());
        ZeroMemory(nativeObject.Get(), sizeof(D3D11_FEATURE_DATA_THREADING));
    }
internal:
    AutoPointer<D3D11_FEATURE_DATA_THREADING> nativeObject;
internal:
    FeatureDataThreading(D3D11_FEATURE_DATA_THREADING* pFeatureDataThreading)
    {
        nativeObject.Set(pFeatureDataThreading);
    }
    FeatureDataThreading(D3D11_FEATURE_DATA_THREADING* pFeatureDataThreading, bool deletable)
    {
        nativeObject.Set(pFeatureDataThreading, deletable);
    }
};
/// <summary>
/// <para>(Also see DirectX SDK: D3D11_FEATURE_DATA_DOUBLES)</para>
/// </summary>
public ref struct FeatureDataDoubles 
{
public:
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D11_FEATURE_DATA_DOUBLES.DoublePrecisionFloatShaderOps)</para>
    /// </summary>
    property Boolean DoublePrecisionFloatShaderOps
    {
        Boolean get()
        {
            return nativeObject->DoublePrecisionFloatShaderOps != 0;
        }
        void set(Boolean value)
        {
            nativeObject->DoublePrecisionFloatShaderOps = (BOOL)value;
        }
    }
public:
    FeatureDataDoubles()
    {
        nativeObject.Set(new D3D11_FEATURE_DATA_DOUBLES());
        ZeroMemory(nativeObject.Get(), sizeof(D3D11_FEATURE_DATA_DOUBLES));
    }
internal:
    AutoPointer<D3D11_FEATURE_DATA_DOUBLES> nativeObject;
internal:
    FeatureDataDoubles(D3D11_FEATURE_DATA_DOUBLES* pFeatureData)
    {
        nativeObject.Set(pFeatureData);
    }
    FeatureDataDoubles(D3D11_FEATURE_DATA_DOUBLES* pFeatureData, bool deletable)
    {
        nativeObject.Set(pFeatureData, deletable);
    }};

/// <summary>
/// <para>(Also see DirectX SDK: D3D11_FEATURE_DATA_FORMAT_SUPPORT)</para>
/// </summary>
public ref struct FeatureDataFormatSupport 
{
public:
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D11_FEATURE_DATA_FORMAT_SUPPORT.InFormat)</para>
    /// </summary>
    property Format InFormat
    {
        Format get()
        {
            return safe_cast<Format>(nativeObject->InFormat);
        }
        void set(Format value)
        {
            nativeObject->InFormat = safe_cast<DXGI_FORMAT>(value);
        }
    }

    /// <summary>
    /// <para>(Also see DirectX SDK: D3D11_FEATURE_DATA_FORMAT_SUPPORT.OutFormatSupport)</para>
    /// </summary>
    property FormatSupport OutFormatSupport
    {
        FormatSupport get()
        {
            return safe_cast<FormatSupport>(nativeObject->OutFormatSupport);
        }
        void set(FormatSupport value)
        {
            nativeObject->OutFormatSupport = safe_cast<UINT>(value);
        }
    }

public:
    FeatureDataFormatSupport()
    {
        nativeObject.Set(new D3D11_FEATURE_DATA_FORMAT_SUPPORT());
        ZeroMemory(nativeObject.Get(), sizeof(D3D11_FEATURE_DATA_FORMAT_SUPPORT));
    }
internal:
    AutoPointer<D3D11_FEATURE_DATA_FORMAT_SUPPORT> nativeObject;
internal:
    FeatureDataFormatSupport(D3D11_FEATURE_DATA_FORMAT_SUPPORT* pFeatureData)
    {
        nativeObject.Set(pFeatureData);
    }
    FeatureDataFormatSupport(D3D11_FEATURE_DATA_FORMAT_SUPPORT* pFeatureData, bool deletable)
    {
        nativeObject.Set(pFeatureData, deletable);
    }};

/// <summary>
/// <para>(Also see DirectX SDK: D3D11_FEATURE_DATA_FORMAT_SUPPORT)</para>
/// </summary>
public ref struct FeatureDataFormatSupport2 
{
public:
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D11_FEATURE_DATA_FORMAT_SUPPORT2.InFormat)</para>
    /// </summary>
    property Format InFormat
    {
        Format get()
        {
            return safe_cast<Format>(nativeObject->InFormat);
        }
        void set(Format value)
        {
            nativeObject->InFormat = safe_cast<DXGI_FORMAT>(value);
        }
    }

    /// <summary>
    /// <para>(Also see DirectX SDK: D3D11_FEATURE_DATA_FORMAT_SUPPORT2.OutFormatSupport2)</para>
    /// </summary>
    property FormatSupport2 OutFormatSupport2
    {
        FormatSupport2 get()
        {
            return safe_cast<FormatSupport2>(nativeObject->OutFormatSupport2);
        }
        void set(FormatSupport2 value)
        {
            nativeObject->OutFormatSupport2 = safe_cast<UINT>(value);
        }
    }

public:
    FeatureDataFormatSupport2()
    {
        nativeObject.Set(new D3D11_FEATURE_DATA_FORMAT_SUPPORT2());
        ZeroMemory(nativeObject.Get(), sizeof(D3D11_FEATURE_DATA_FORMAT_SUPPORT2));
    }
internal:
    AutoPointer<D3D11_FEATURE_DATA_FORMAT_SUPPORT2> nativeObject;
internal:
    FeatureDataFormatSupport2(D3D11_FEATURE_DATA_FORMAT_SUPPORT2* pFeatureData)
    {
        nativeObject.Set(pFeatureData);
    }
    FeatureDataFormatSupport2(D3D11_FEATURE_DATA_FORMAT_SUPPORT2* pFeatureData, bool deletable)
    {
        nativeObject.Set(pFeatureData, deletable);
    }};



/// <summary>
/// <para>(Also see DirectX SDK: D3D11_FEATURE_DATA_D3D10_X_HARDWARE_OPTIONS)</para>
/// </summary>
public ref struct FeatureDataD3D10XHardwareOptions 
{
public:
    /// <summary>
    /// <para>(Also see DirectX SDK: D3D11_FEATURE_DATA_D3D10_X_HARDWARE_OPTIONS.ComputeShaders_Plus_RawAndStructuredBuffers_Via_Shader_4_x)</para>
    /// </summary>
    property Boolean ComputeShaders_Plus_RawAndStructuredBuffers_Via_Shader_4_x
    {
        Boolean get()
        {
            return nativeObject->ComputeShaders_Plus_RawAndStructuredBuffers_Via_Shader_4_x != 0;
        }
        void set(Boolean value)
        {
            nativeObject->ComputeShaders_Plus_RawAndStructuredBuffers_Via_Shader_4_x = (BOOL)value;
        }
    }
public:
    FeatureDataD3D10XHardwareOptions()
    {
        nativeObject.Set(new D3D11_FEATURE_DATA_D3D10_X_HARDWARE_OPTIONS());
        ZeroMemory(nativeObject.Get(), sizeof(D3D11_FEATURE_DATA_D3D10_X_HARDWARE_OPTIONS));
    }
internal:
    AutoPointer<D3D11_FEATURE_DATA_D3D10_X_HARDWARE_OPTIONS> nativeObject;
internal:
    FeatureDataD3D10XHardwareOptions(D3D11_FEATURE_DATA_D3D10_X_HARDWARE_OPTIONS* pFeatureData)
    {
        nativeObject.Set(pFeatureData);
    }
    FeatureDataD3D10XHardwareOptions(D3D11_FEATURE_DATA_D3D10_X_HARDWARE_OPTIONS* pFeatureData, bool deletable)
    {
        nativeObject.Set(pFeatureData, deletable);
    }};


/// <summary>
/// Allow or deny certain types of messages to pass through a filter.
/// <para>(Also see DirectX SDK: D3D11_INFO_QUEUE_FILTER_DESC)</para>
/// </summary>
public ref struct InfoQueueFilterDescription 
{
public:
    /// <summary>
    /// Number of message categories to allow or deny.
    /// <para>(Also see DirectX SDK: D3D11_INFO_QUEUE_FILTER_DESC.NumCategories)</para>
    /// </summary>
    property UInt32 NumCategories
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->NumCategories);
        }
        void set(UInt32 value)
        {
            nativeObject->NumCategories = (UINT)value;
        }
    }
    /// <summary>
    /// Collection of message categories to allow or deny. Array must have at least NumCategories members (see <see cref="MessageCategory"/>)<seealso cref="MessageCategory"/>.
    /// <para>(Also see DirectX SDK: D3D11_INFO_QUEUE_FILTER_DESC.pCategoryList)</para>
    /// </summary>
    property Object^ pCategoryList
    {
        Object^ get()
        {
    //        return (Object^)(nativeObject->pCategoryList);
            return nullptr;
        }
        void set(Object^ value)
        {
    //        nativeObject->pCategoryList = (D3D11_MESSAGE_CATEGORY)value;
        }
    }
    /// <summary>
    /// Number of message severity levels to allow or deny.
    /// <para>(Also see DirectX SDK: D3D11_INFO_QUEUE_FILTER_DESC.NumSeverities)</para>
    /// </summary>
    property UInt32 NumSeverities
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->NumSeverities);
        }
        void set(UInt32 value)
        {
            nativeObject->NumSeverities = (UINT)value;
        }
    }
    /// <summary>
    /// Collection of message severity levels to allow or deny. Array must have at least NumSeverities members (see <see cref="MessageSeverity"/>)<seealso cref="MessageSeverity"/>.
    /// <para>(Also see DirectX SDK: D3D11_INFO_QUEUE_FILTER_DESC.pSeverityList)</para>
    /// </summary>
    property Object^ pSeverityList
    {
        Object^ get()
        {
    //        return (Object^)(nativeObject->pSeverityList);
            return nullptr;
        }
        void set(Object^ value)
        {
    //        nativeObject->pSeverityList = (D3D11_MESSAGE_SEVERITY)value;
        }
    }
    /// <summary>
    /// Number of message IDs to allow or deny.
    /// <para>(Also see DirectX SDK: D3D11_INFO_QUEUE_FILTER_DESC.NumIDs)</para>
    /// </summary>
    property UInt32 NumIDs
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->NumIDs);
        }
        void set(UInt32 value)
        {
            nativeObject->NumIDs = (UINT)value;
        }
    }
    /// <summary>
    /// Collection of message IDs to allow or deny. Array must have at least NumIDs members (see <see cref="MessageId"/>)<seealso cref="MessageId"/>.
    /// <para>(Also see DirectX SDK: D3D11_INFO_QUEUE_FILTER_DESC.pIDList)</para>
    /// </summary>
    property Object^ pIDList
    {
        Object^ get()
        {
    //        return (Object^)(nativeObject->pIDList);
            return nullptr;
        }
        void set(Object^ value)
        {
    //        nativeObject->pIDList = (D3D11_MESSAGE_ID)value;
        }
    }
public:
    InfoQueueFilterDescription()
    {
        nativeObject.Set(new D3D11_INFO_QUEUE_FILTER_DESC());
        ZeroMemory(nativeObject.Get(), sizeof(D3D11_INFO_QUEUE_FILTER_DESC));
    }
internal:
    AutoPointer<D3D11_INFO_QUEUE_FILTER_DESC> nativeObject;
internal:
    InfoQueueFilterDescription(D3D11_INFO_QUEUE_FILTER_DESC* pInfoQueueFilterDescription)
    {
        nativeObject.Set(pInfoQueueFilterDescription);
    }
    InfoQueueFilterDescription(D3D11_INFO_QUEUE_FILTER_DESC* pInfoQueueFilterDescription, bool deletable)
    {
        nativeObject.Set(pInfoQueueFilterDescription, deletable);
    }};
/// <summary>
/// Debug message filter; contains a lists of message types to allow or deny.
/// <para>(Also see DirectX SDK: D3D11_INFO_QUEUE_FILTER)</para>
/// </summary>
public ref struct InfoQueueFilter 
{
public:
    /// <summary>
    /// Types of messages that you want to allow. See InfoQueueFilterDescription.
    /// <para>(Also see DirectX SDK: D3D11_INFO_QUEUE_FILTER.AllowList)</para>
    /// </summary>
    property InfoQueueFilterDescription^ AllowList
    {
        InfoQueueFilterDescription^ get()
        {
            if (allowList == nullptr)
                allowList = gcnew InfoQueueFilterDescription(&(nativeObject->AllowList), false);
            return allowList;
        }
        void set(InfoQueueFilterDescription^ value)
        {
            memcpy(&(nativeObject->AllowList), (void*)(value->nativeObject.Get()), sizeof(D3D11_INFO_QUEUE_FILTER_DESC));
        }
    }
    /// <summary>
    /// Types of messages that you want to deny.
    /// <para>(Also see DirectX SDK: D3D11_INFO_QUEUE_FILTER.DenyList)</para>
    /// </summary>
    property InfoQueueFilterDescription^ DenyList
    {
        InfoQueueFilterDescription^ get()
        {
            if (denyList == nullptr)
                denyList = gcnew InfoQueueFilterDescription(&(nativeObject->DenyList),false);
            return denyList;
        }
        void set(InfoQueueFilterDescription^ value)
        {
            memcpy(&(nativeObject->DenyList), (void*)(value->nativeObject.Get()), sizeof(D3D11_INFO_QUEUE_FILTER_DESC));
        }
    }
public:
    InfoQueueFilter()
    {
        nativeObject.Set(new D3D11_INFO_QUEUE_FILTER());
        ZeroMemory(nativeObject.Get(), sizeof(D3D11_INFO_QUEUE_FILTER));
    }
internal:
    AutoPointer<D3D11_INFO_QUEUE_FILTER> nativeObject;
internal:
    InfoQueueFilter(D3D11_INFO_QUEUE_FILTER* pInfoQueueFilter)
    {
        nativeObject.Set(pInfoQueueFilter);
    }
    InfoQueueFilter(D3D11_INFO_QUEUE_FILTER* pInfoQueueFilter, bool deletable)
    {
        nativeObject.Set(pInfoQueueFilter, deletable);
    }
private:
    InfoQueueFilterDescription^ denyList;
    InfoQueueFilterDescription^ allowList;
protected:
    ~InfoQueueFilter()
    {
        if (denyList != nullptr)
        {
            delete denyList;
            denyList = nullptr;
        }
        if (allowList != nullptr)
        {
            delete allowList;
            allowList = nullptr;
        }
        this->!InfoQueueFilter();
    }

    !InfoQueueFilter()
    {
        if (nativeObject.Get() != 0)
        {
            free (nativeObject.Get());
            nativeObject.Set(NULL);
        }
    }
};
/// <summary>
/// A description of a single element for the input-assembler stage.
/// <para>(Also see DirectX SDK: D3D11_INPUT_ELEMENT_DESC)</para>
/// </summary>
public ref struct InputElementDescription 
{
public:
    /// <summary>
    /// The HLSL semantic associated with this element in a shader input-signature.
    /// <para>(Also see DirectX SDK: D3D11_INPUT_ELEMENT_DESC.SemanticName)</para>
    /// </summary>
    property String^ SemanticName
    {
        String^ get()
        {
            if (nativeObject->SemanticName == NULL)
            {
                return nullptr;
            }
            return gcnew String(nativeObject->SemanticName);
        }

        void set(String^ value)
        {
            if (nativeObject->SemanticName != NULL)
            {
                delete [] nativeObject->SemanticName;
            }

            nativeObject->SemanticName = D3DUtils::CharArrayfromSystemString(value);
        }
    }
    /// <summary>
    /// The semantic index for the element. A semantic index modifies a semantic, with an integer index number. A semantic index is only needed in a case where there is more than one element with the same semantic. For example, a 4x4 matrix would have four components each with the semantic name matrix, however each of the four component would have different semantic indices (0, 1, 2, and 3).
    /// <para>(Also see DirectX SDK: D3D11_INPUT_ELEMENT_DESC.SemanticIndex)</para>
    /// </summary>
    property UInt32 SemanticIndex
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->SemanticIndex);
        }
        void set(UInt32 value)
        {
            nativeObject->SemanticIndex = (UINT)value;
        }
    }
    /// <summary>
    /// The data type of the element data. See Format.
    /// <para>(Also see DirectX SDK: D3D11_INPUT_ELEMENT_DESC.Format)</para>
    /// </summary>
    property Format ElementDataFormat
    {
        Format get()
        {
            return (Format)(nativeObject->Format);
        }
        void set(Format value)
        {
            nativeObject->Format = (DXGI_FORMAT)value;
        }
    }
    /// <summary>
    /// An integer value that identifies the input-assembler (see input slot). Valid values are between 0 and 15, defined in D3D11.h.
    /// <para>(Also see DirectX SDK: D3D11_INPUT_ELEMENT_DESC.InputSlot)</para>
    /// </summary>
    property UInt32 InputSlot
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->InputSlot);
        }
        void set(UInt32 value)
        {
            nativeObject->InputSlot = (UINT)value;
        }
    }
    /// <summary>
    /// Optional. Offset (in bytes) between each element. Use D3D11_APPEND_ALIGNED_ELEMENT for convenience to define the current element directly after the previous one, including any packing if necessary.
    /// <para>(Also see DirectX SDK: D3D11_INPUT_ELEMENT_DESC.AlignedByteOffset)</para>
    /// </summary>
    property UInt32 AlignedByteOffset
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->AlignedByteOffset);
        }
        void set(UInt32 value)
        {
            nativeObject->AlignedByteOffset = (UINT)value;
        }
    }
    /// <summary>
    /// Identifies the input data class for a single input slot (see <see cref="InputClassification"/>)<seealso cref="InputClassification"/>.
    /// <para>(Also see DirectX SDK: D3D11_INPUT_ELEMENT_DESC.InputSlotClass)</para>
    /// </summary>
    property InputClassification InputSlotClass
    {
        InputClassification get()
        {
            return (InputClassification)(nativeObject->InputSlotClass);
        }
        void set(InputClassification value)
        {
            nativeObject->InputSlotClass = (D3D11_INPUT_CLASSIFICATION)value;
        }
    }
    /// <summary>
    /// The number of instances to draw using the same per-instance data before advancing in the buffer by one element. This value must be 0 for an element that contains per-vertex data (the slot class is set to PerVertexData).
    /// <para>(Also see DirectX SDK: D3D11_INPUT_ELEMENT_DESC.InstanceDataStepRate)</para>
    /// </summary>
    property UInt32 InstanceDataStepRate
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->InstanceDataStepRate);
        }
        void set(UInt32 value)
        {
            nativeObject->InstanceDataStepRate = (UINT)value;
        }
    }
public:
    InputElementDescription()
    {
        nativeObject.Set(new D3D11_INPUT_ELEMENT_DESC());
        ZeroMemory(nativeObject.Get(), sizeof(D3D11_INPUT_ELEMENT_DESC));
    }
internal:
    AutoPointer<D3D11_INPUT_ELEMENT_DESC> nativeObject;
internal:
    InputElementDescription(D3D11_INPUT_ELEMENT_DESC* pInputElementDescription)
    {
        nativeObject.Set(pInputElementDescription);
    }
    InputElementDescription(D3D11_INPUT_ELEMENT_DESC* pInputElementDescription, bool deletable)
    {
        nativeObject.Set(pInputElementDescription, deletable);
    }
protected:
    !InputElementDescription()
    {
        if (nativeObject.Get() != NULL && nativeObject->SemanticName != NULL)
        {
            Marshal::FreeHGlobal(IntPtr((void*)nativeObject->SemanticName));
            nativeObject->SemanticName = NULL;
        }
    }

    ~InputElementDescription()
    {
        InputElementDescription::!InputElementDescription();
    }
};
/// <summary>
/// Provides access to subresource data.
/// <para>(Also see DirectX SDK: D3D11_MAPPED_SUBRESOURCE)</para>
/// </summary>
public ref struct MappedSubresource 
{
public:
    /// <summary>
    /// Pointer to the data.
    /// <para>(Also see DirectX SDK: D3D11_MAPPED_SUBRESOURCE.pData)</para>
    /// </summary>
    property IntPtr Data
    {
        IntPtr get()
        {
            return IntPtr((void*) nativeObject->pData);
        }
        void set(IntPtr value)
        {
            nativeObject->pData = value.ToPointer();
        }
    }
    /// <summary>
    /// The row pitch, or width, or physical size (in bytes) of the data.
    /// <para>(Also see DirectX SDK: D3D11_MAPPED_SUBRESOURCE.RowPitch)</para>
    /// </summary>
    property UInt32 RowPitch
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->RowPitch);
        }
        void set(UInt32 value)
        {
            nativeObject->RowPitch = (UINT)value;
        }
    }
    /// <summary>
    /// The depth pitch, or width, or physical size (in bytes)of the data.
    /// <para>(Also see DirectX SDK: D3D11_MAPPED_SUBRESOURCE.DepthPitch)</para>
    /// </summary>
    property UInt32 DepthPitch
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->DepthPitch);
        }
        void set(UInt32 value)
        {
            nativeObject->DepthPitch = (UINT)value;
        }
    }
public:
    MappedSubresource()
    {
        nativeObject.Set(new D3D11_MAPPED_SUBRESOURCE());
        ZeroMemory(nativeObject.Get(), sizeof(D3D11_MAPPED_SUBRESOURCE));
    }
internal:
    AutoPointer<D3D11_MAPPED_SUBRESOURCE> nativeObject;
internal:
    MappedSubresource(D3D11_MAPPED_SUBRESOURCE* pMappedSubresource)
    {
        nativeObject.Set(pMappedSubresource);
    }
    MappedSubresource(D3D11_MAPPED_SUBRESOURCE* pMappedSubresource, bool deletable)
    {
        nativeObject.Set(pMappedSubresource, deletable);
    }};
/// <summary>
/// A debug message in the Information Queue.
/// <para>(Also see DirectX SDK: D3D11_MESSAGE)</para>
/// </summary>
public ref struct Message 
{
public:
    /// <summary>
    /// The category of the message. See MessageCategory.
    /// <para>(Also see DirectX SDK: D3D11_MESSAGE.Category)</para>
    /// </summary>
    property MessageCategory Category
    {
        MessageCategory get()
        {
            return (MessageCategory)(nativeObject->Category);
        }
        void set(MessageCategory value)
        {
            nativeObject->Category = (D3D11_MESSAGE_CATEGORY)value;
        }
    }
    /// <summary>
    /// The severity of the message. See MessageSeverity.
    /// <para>(Also see DirectX SDK: D3D11_MESSAGE.Severity)</para>
    /// </summary>
    property MessageSeverity Severity
    {
        MessageSeverity get()
        {
            return (MessageSeverity)(nativeObject->Severity);
        }
        void set(MessageSeverity value)
        {
            nativeObject->Severity = (D3D11_MESSAGE_SEVERITY)value;
        }
    }
    /// <summary>
    /// The ID of the message. See MessageId.
    /// <para>(Also see DirectX SDK: D3D11_MESSAGE.ID)</para>
    /// </summary>
    property MessageId ID
    {
        MessageId get()
        {
            return (MessageId)(nativeObject->ID);
        }
        void set(MessageId value)
        {
            nativeObject->ID = (D3D11_MESSAGE_ID)value;
        }
    }
    /// <summary>
    /// The message string.
    /// <para>(Also see DirectX SDK: D3D11_MESSAGE.pDescription)</para>
    /// </summary>
    property String^ Description
    {
        String^ get()
        {
            if (description == nullptr)
                description = nativeObject->pDescription == NULL ? 
                    nullptr :
                    gcnew String(nativeObject->pDescription);

            return description;
        }
    }
    /// <summary>
    /// The length of the original Description in bytes.
    /// <para>(Also see DirectX SDK: D3D11_MESSAGE.DescriptionByteLength)</para>
    /// </summary>
    property UInt32 DescriptionByteLength
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->DescriptionByteLength);
        }
        void set(UInt32 value)
        {
            nativeObject->DescriptionByteLength = (SIZE_T)value;
        }
    }
public:
    Message()
    {
        nativeObject.Set(new D3D11_MESSAGE());
        ZeroMemory(nativeObject.Get(), sizeof(D3D11_MESSAGE));
    }
internal:
    AutoPointer<D3D11_MESSAGE> nativeObject;
internal:
    Message(D3D11_MESSAGE* pMessage)
    {
        nativeObject.Set(pMessage);
    }
    Message(D3D11_MESSAGE* pMessage, bool deletable)
    {
        nativeObject.Set(pMessage, deletable);
    }
private:
    String^ description;
protected:
    ~Message()
    {
        if (description != nullptr)
        {
            delete description;
            description = nullptr;
        }
        this->!Message();
    }
    !Message()
    {
        if (nativeObject.Get() != 0)
        {
            free (nativeObject.Get());
            nativeObject.Set(NULL);
        }
    }
};
/// <summary>
/// Query information about graphics-pipeline activity in between calls to DeviceContext.Begin and DeviceContext.End.
/// <para>(Also see DirectX SDK: D3D11_QUERY_DATA_PIPELINE_STATISTICS)</para>
/// </summary>
public ref struct QueryDataPipelineStatistics 
{
public:
    /// <summary>
    /// Number of vertices read by input assembler.
    /// <para>(Also see DirectX SDK: D3D11_QUERY_DATA_PIPELINE_STATISTICS.IAVertices)</para>
    /// </summary>
    property UInt64 IAVertices
    {
        UInt64 get()
        {
            return (UInt64)(nativeObject->IAVertices);
        }
        void set(UInt64 value)
        {
            nativeObject->IAVertices = (UINT64)value;
        }
    }
    /// <summary>
    /// Number of primitives read by the input assembler. This number can be different depending on the primitive topology used. For example, a triangle strip with 6 vertices will produce 4 triangles, however a triangle list with 6 vertices will produce 2 triangles.
    /// <para>(Also see DirectX SDK: D3D11_QUERY_DATA_PIPELINE_STATISTICS.IAPrimitives)</para>
    /// </summary>
    property UInt64 IAPrimitives
    {
        UInt64 get()
        {
            return (UInt64)(nativeObject->IAPrimitives);
        }
        void set(UInt64 value)
        {
            nativeObject->IAPrimitives = (UINT64)value;
        }
    }
    /// <summary>
    /// Number of times a vertex shader was invoked. Direct3D invokes the vertex shader once per vertex.
    /// <para>(Also see DirectX SDK: D3D11_QUERY_DATA_PIPELINE_STATISTICS.VSInvocations)</para>
    /// </summary>
    property UInt64 VSInvocations
    {
        UInt64 get()
        {
            return (UInt64)(nativeObject->VSInvocations);
        }
        void set(UInt64 value)
        {
            nativeObject->VSInvocations = (UINT64)value;
        }
    }
    /// <summary>
    /// Number of times a geometry shader was invoked. When the geometry shader is set to NULL, this statistic may or may not increment depending on the hardware manufacturer.
    /// <para>(Also see DirectX SDK: D3D11_QUERY_DATA_PIPELINE_STATISTICS.GSInvocations)</para>
    /// </summary>
    property UInt64 GSInvocations
    {
        UInt64 get()
        {
            return (UInt64)(nativeObject->GSInvocations);
        }
        void set(UInt64 value)
        {
            nativeObject->GSInvocations = (UINT64)value;
        }
    }
    /// <summary>
    /// Number of primitives output by a geometry shader.
    /// <para>(Also see DirectX SDK: D3D11_QUERY_DATA_PIPELINE_STATISTICS.GSPrimitives)</para>
    /// </summary>
    property UInt64 GSPrimitives
    {
        UInt64 get()
        {
            return (UInt64)(nativeObject->GSPrimitives);
        }
        void set(UInt64 value)
        {
            nativeObject->GSPrimitives = (UINT64)value;
        }
    }
    /// <summary>
    /// Number of primitives that were sent to the rasterizer. When the rasterizer is disabled, this will not increment.
    /// <para>(Also see DirectX SDK: D3D11_QUERY_DATA_PIPELINE_STATISTICS.CInvocations)</para>
    /// </summary>
    property UInt64 CInvocations
    {
        UInt64 get()
        {
            return (UInt64)(nativeObject->CInvocations);
        }
        void set(UInt64 value)
        {
            nativeObject->CInvocations = (UINT64)value;
        }
    }
    /// <summary>
    /// Number of primitives that were rendered. This may be larger or smaller than CInvocations because after a primitive is clipped sometimes it is either broken up into more than one primitive or completely culled.
    /// <para>(Also see DirectX SDK: D3D11_QUERY_DATA_PIPELINE_STATISTICS.CPrimitives)</para>
    /// </summary>
    property UInt64 CPrimitives
    {
        UInt64 get()
        {
            return (UInt64)(nativeObject->CPrimitives);
        }
        void set(UInt64 value)
        {
            nativeObject->CPrimitives = (UINT64)value;
        }
    }
    /// <summary>
    /// Number of times a pixel shader was invoked.
    /// <para>(Also see DirectX SDK: D3D11_QUERY_DATA_PIPELINE_STATISTICS.PSInvocations)</para>
    /// </summary>
    property UInt64 PSInvocations
    {
        UInt64 get()
        {
            return (UInt64)(nativeObject->PSInvocations);
        }
        void set(UInt64 value)
        {
            nativeObject->PSInvocations = (UINT64)value;
        }
    }
    /// <summary>
    /// Number of times a hull shader was invoked.
    /// <para>(Also see DirectX SDK: D3D11_QUERY_DATA_PIPELINE_STATISTICS.HSInvocations)</para>
    /// </summary>
    property UInt64 HSInvocations
    {
        UInt64 get()
        {
            return (UInt64)(nativeObject->HSInvocations);
        }
        void set(UInt64 value)
        {
            nativeObject->HSInvocations = (UINT64)value;
        }
    }
    /// <summary>
    /// Number of times a domain shader was invoked.
    /// <para>(Also see DirectX SDK: D3D11_QUERY_DATA_PIPELINE_STATISTICS.DSInvocations)</para>
    /// </summary>
    property UInt64 DSInvocations
    {
        UInt64 get()
        {
            return (UInt64)(nativeObject->DSInvocations);
        }
        void set(UInt64 value)
        {
            nativeObject->DSInvocations = (UINT64)value;
        }
    }
public:
    QueryDataPipelineStatistics()
    {
        nativeObject.Set(new D3D11_QUERY_DATA_PIPELINE_STATISTICS());
        ZeroMemory(nativeObject.Get(), sizeof(D3D11_QUERY_DATA_PIPELINE_STATISTICS));
    }
internal:
    AutoPointer<D3D11_QUERY_DATA_PIPELINE_STATISTICS> nativeObject;
internal:
    QueryDataPipelineStatistics(D3D11_QUERY_DATA_PIPELINE_STATISTICS* pQueryDataPipelineStatistics)
    {
        nativeObject.Set(pQueryDataPipelineStatistics);
    }
    QueryDataPipelineStatistics(D3D11_QUERY_DATA_PIPELINE_STATISTICS* pQueryDataPipelineStatistics, bool deletable)
    {
        nativeObject.Set(pQueryDataPipelineStatistics, deletable);
    }
};
/// <summary>
/// Query information about the amount of data streamed out to the stream-output buffers in between DeviceContext.Begin and DeviceContext.End.
/// <para>(Also see DirectX SDK: D3D11_QUERY_DATA_SO_STATISTICS)</para>
/// </summary>
public ref struct QueryDataSoStatistics 
{
public:
    /// <summary>
    /// Number of primitives (that is, points, lines, and triangles) written to the stream-output buffers.
    /// <para>(Also see DirectX SDK: D3D11_QUERY_DATA_SO_STATISTICS.NumPrimitivesWritten)</para>
    /// </summary>
    property UInt64 NumPrimitivesWritten
    {
        UInt64 get()
        {
            return (UInt64)(nativeObject->NumPrimitivesWritten);
        }
        void set(UInt64 value)
        {
            nativeObject->NumPrimitivesWritten = (UINT64)value;
        }
    }
    /// <summary>
    /// Number of primitives that would have been written to the stream-output buffers if there had been enough space for them all.
    /// <para>(Also see DirectX SDK: D3D11_QUERY_DATA_SO_STATISTICS.PrimitivesStorageNeeded)</para>
    /// </summary>
    property UInt64 PrimitivesStorageNeeded
    {
        UInt64 get()
        {
            return (UInt64)(nativeObject->PrimitivesStorageNeeded);
        }
        void set(UInt64 value)
        {
            nativeObject->PrimitivesStorageNeeded = (UINT64)value;
        }
    }
public:
    QueryDataSoStatistics()
    {
        nativeObject.Set(new D3D11_QUERY_DATA_SO_STATISTICS());
        ZeroMemory(nativeObject.Get(), sizeof(D3D11_QUERY_DATA_SO_STATISTICS));
    }
internal:
    AutoPointer<D3D11_QUERY_DATA_SO_STATISTICS> nativeObject;
internal:
    QueryDataSoStatistics(D3D11_QUERY_DATA_SO_STATISTICS* pQueryDataSoStatistics)
    {
        nativeObject.Set(pQueryDataSoStatistics);
    }
    QueryDataSoStatistics(D3D11_QUERY_DATA_SO_STATISTICS* pQueryDataSoStatistics, bool deletable)
    {
        nativeObject.Set(pQueryDataSoStatistics, deletable);
    }
};
/// <summary>
/// Query information about the reliability of a timestamp query.
/// <para>(Also see DirectX SDK: D3D11_QUERY_DATA_TIMESTAMP_DISJOINT)</para>
/// </summary>
public ref struct QueryDataTimestampDisjoint 
{
public:
    /// <summary>
    /// How frequently the GPU counter increments in Hz.
    /// <para>(Also see DirectX SDK: D3D11_QUERY_DATA_TIMESTAMP_DISJOINT.Frequency)</para>
    /// </summary>
    property UInt64 Frequency
    {
        UInt64 get()
        {
            return (UInt64)(nativeObject->Frequency);
        }
        void set(UInt64 value)
        {
            nativeObject->Frequency = (UINT64)value;
        }
    }
    /// <summary>
    /// If this is TRUE, something occurred in between the query's DeviceContext.Begin and DeviceContext.End calls that caused the timestamp counter to become discontinuous or disjoint, such as unplugging the AC chord on a laptop, overheating, or throttling up/down due to laptop savings events. The timestamp returned by DeviceContext.GetData for a timestamp query is only reliable if Disjoint is FALSE.
    /// <para>(Also see DirectX SDK: D3D11_QUERY_DATA_TIMESTAMP_DISJOINT.Disjoint)</para>
    /// </summary>
    property Boolean Disjoint
    {
        Boolean get()
        {
            return nativeObject->Disjoint != 0;
        }
        void set(Boolean value)
        {
            nativeObject->Disjoint = (BOOL)value;
        }
    }
public:
    QueryDataTimestampDisjoint()
    {
        nativeObject.Set(new D3D11_QUERY_DATA_TIMESTAMP_DISJOINT());
        ZeroMemory(nativeObject.Get(), sizeof(D3D11_QUERY_DATA_TIMESTAMP_DISJOINT));
    }
internal:
    AutoPointer<D3D11_QUERY_DATA_TIMESTAMP_DISJOINT> nativeObject;
internal:
    QueryDataTimestampDisjoint(D3D11_QUERY_DATA_TIMESTAMP_DISJOINT* pQueryDataTimestampDisjoint)
    {
        nativeObject.Set(pQueryDataTimestampDisjoint);
    }
    QueryDataTimestampDisjoint(D3D11_QUERY_DATA_TIMESTAMP_DISJOINT* pQueryDataTimestampDisjoint, bool deletable)
    {
        nativeObject.Set(pQueryDataTimestampDisjoint, deletable);
    }};
/// <summary>
/// Describes a query.
/// <para>(Also see DirectX SDK: D3D11_QUERY_DESC)</para>
/// </summary>
public ref struct QueryDescription 
{
public:
    /// <summary>
    /// Type of query.
    /// <para>(Also see DirectX SDK: D3D11_QUERY_DESC.D3DQuery)</para>
    /// </summary>
    property QueryType Query
    {
        QueryType get()
        {
            return safe_cast<QueryType>(nativeObject->Query);
        }
        void set(QueryType value)
        {
            nativeObject->Query = safe_cast<D3D11_QUERY>(value);
        }
    }
    /// <summary>
    /// Miscellaneous flags (see <see cref="QueryMiscFlag"/>)<seealso cref="QueryMiscFlag"/>.
    /// <para>(Also see DirectX SDK: D3D11_QUERY_DESC.MiscFlags)</para>
    /// </summary>
    property QueryMiscFlag MiscFlags
    {
        QueryMiscFlag get()
        {
            return (QueryMiscFlag)(nativeObject->MiscFlags);
        }
        void set(QueryMiscFlag value)
        {
            nativeObject->MiscFlags = (UINT)value;
        }
    }
public:
    QueryDescription()
    {
        nativeObject.Set(new D3D11_QUERY_DESC());
        ZeroMemory(nativeObject.Get(), sizeof(D3D11_QUERY_DESC));
    }
internal:
    AutoPointer<D3D11_QUERY_DESC> nativeObject;
internal:
    QueryDescription(D3D11_QUERY_DESC* pQueryDescription)
    {
        nativeObject.Set(pQueryDescription);
    }
    QueryDescription(D3D11_QUERY_DESC* pQueryDescription, bool deletable)
    {
        nativeObject.Set(pQueryDescription, deletable);
    }};
/// <summary>
/// Describes rasterizer state.
/// <para>(Also see DirectX SDK: D3D11_RASTERIZER_DESC)</para>
/// </summary>
public ref struct RasterizerDescription 
{
public:
    /// <summary>
    /// Determines the fill mode to use when rendering (see <see cref="FillMode"/>)<seealso cref="FillMode"/>.
    /// <para>(Also see DirectX SDK: D3D11_RASTERIZER_DESC.FillMode)</para>
    /// </summary>
    property FillMode RasterizerFillMode
    {
        FillMode get()
        {
            return (FillMode)(nativeObject->FillMode);
        }
        void set(FillMode value)
        {
            nativeObject->FillMode = (D3D11_FILL_MODE)value;
        }
    }
    /// <summary>
    /// Indicates triangles facing the specified direction are not drawn (see <see cref="CullMode"/>)<seealso cref="CullMode"/>.
    /// <para>(Also see DirectX SDK: D3D11_RASTERIZER_DESC.CullMode)</para>
    /// </summary>
    property CullMode RasterizerCullMode
    {
        CullMode get()
        {
            return (CullMode)(nativeObject->CullMode);
        }
        void set(CullMode value)
        {
            nativeObject->CullMode = (D3D11_CULL_MODE)value;
        }
    }
    /// <summary>
    /// Determines if a triangle is front- or back-facing. If this parameter is true, then a triangle will be considered front-facing if its vertices are counter-clockwise on the render target and considered back-facing if they are clockwise. If this parameter is false then the opposite is true.
    /// <para>(Also see DirectX SDK: D3D11_RASTERIZER_DESC.FrontCounterClockwise)</para>
    /// </summary>
    property Boolean FrontCounterClockwise
    {
        Boolean get()
        {
            return nativeObject->FrontCounterClockwise != 0;
        }
        void set(Boolean value)
        {
            nativeObject->FrontCounterClockwise = (BOOL)value;
        }
    }
    /// <summary>
    /// Depth value added to a given pixel.
    /// <para>(Also see DirectX SDK: D3D11_RASTERIZER_DESC.DepthBias)</para>
    /// </summary>
    property Int32 DepthBias
    {
        Int32 get()
        {
            return (Int32)(nativeObject->DepthBias);
        }
        void set(Int32 value)
        {
            nativeObject->DepthBias = (INT)value;
        }
    }
    /// <summary>
    /// Maximum depth bias of a pixel.
    /// <para>(Also see DirectX SDK: D3D11_RASTERIZER_DESC.DepthBiasClamp)</para>
    /// </summary>
    property Single DepthBiasClamp
    {
        Single get()
        {
            return (Single)(nativeObject->DepthBiasClamp);
        }
        void set(Single value)
        {
            nativeObject->DepthBiasClamp = (FLOAT)value;
        }
    }
    /// <summary>
    /// Scalar on a given pixel's slope.
    /// <para>(Also see DirectX SDK: D3D11_RASTERIZER_DESC.SlopeScaledDepthBias)</para>
    /// </summary>
    property Single SlopeScaledDepthBias
    {
        Single get()
        {
            return (Single)(nativeObject->SlopeScaledDepthBias);
        }
        void set(Single value)
        {
            nativeObject->SlopeScaledDepthBias = (FLOAT)value;
        }
    }
    /// <summary>
    /// Enable clipping based on distance.
    /// <para>(Also see DirectX SDK: D3D11_RASTERIZER_DESC.DepthClipEnable)</para>
    /// </summary>
    property Boolean DepthClipEnable
    {
        Boolean get()
        {
            return nativeObject->DepthClipEnable != 0;
        }
        void set(Boolean value)
        {
            nativeObject->DepthClipEnable = (BOOL)value;
        }
    }
    /// <summary>
    /// Enable scissor-rectangle culling. All pixels ouside an active scissor rectangle are culled.
    /// <para>(Also see DirectX SDK: D3D11_RASTERIZER_DESC.ScissorEnable)</para>
    /// </summary>
    property Boolean ScissorEnable
    {
        Boolean get()
        {
            return nativeObject->ScissorEnable != 0;
        }
        void set(Boolean value)
        {
            nativeObject->ScissorEnable = (BOOL)value;
        }
    }
    /// <summary>
    /// Enable multisample antialiasing.
    /// <para>(Also see DirectX SDK: D3D11_RASTERIZER_DESC.MultisampleEnable)</para>
    /// </summary>
    property Boolean MultisampleEnable
    {
        Boolean get()
        {
            return nativeObject->MultisampleEnable != 0;
        }
        void set(Boolean value)
        {
            nativeObject->MultisampleEnable = (BOOL)value;
        }
    }
    /// <summary>
    /// Enable line antialiasing; only applies if doing line drawing and MultisampleEnable is false.
    /// <para>(Also see DirectX SDK: D3D11_RASTERIZER_DESC.AntialiasedLineEnable)</para>
    /// </summary>
    property Boolean AntialiasedLineEnable
    {
        Boolean get()
        {
            return nativeObject->AntialiasedLineEnable != 0;
        }
        void set(Boolean value)
        {
            nativeObject->AntialiasedLineEnable = (BOOL)value;
        }
    }
public:
    RasterizerDescription()
    {
        nativeObject.Set(new D3D11_RASTERIZER_DESC());
        ZeroMemory(nativeObject.Get(), sizeof(D3D11_RASTERIZER_DESC));
    }
internal:
    AutoPointer<D3D11_RASTERIZER_DESC> nativeObject;
internal:
    RasterizerDescription(D3D11_RASTERIZER_DESC* pRasterizerDescription)
    {
        nativeObject.Set(pRasterizerDescription);
    }
    RasterizerDescription(D3D11_RASTERIZER_DESC* pRasterizerDescription, bool deletable)
    {
        nativeObject.Set(pRasterizerDescription, deletable);
    }
};

/// <summary>
/// Specifies the subresources from a resource that are accessible using a render-target view.
/// <para>(Also see DirectX SDK: D3D11_RENDER_TARGET_VIEW_DESC)</para>
/// </summary>
public ref struct RenderTargetViewDescription 
{
public:
    /// <summary>
    /// The data format (see <see cref="Format"/>)<seealso cref="Format"/>.
    /// <para>(Also see DirectX SDK: D3D11_RENDER_TARGET_VIEW_DESC.Format)</para>
    /// </summary>
    property Format DataFormat
    {
        Format get()
        {
            return (Format)(nativeObject->Format);
        }
        void set(Format value)
        {
            nativeObject->Format = (DXGI_FORMAT)value;
        }
    }
    /// <summary>
    /// The resource type (see <see cref="RenderTargetViewDimension"/>)<seealso cref="RenderTargetViewDimension"/>, which specifies how the render-target resource will be accessed.
    /// <para>(Also see DirectX SDK: D3D11_RENDER_TARGET_VIEW_DESC.ViewDimension)</para>
    /// </summary>
    property RenderTargetViewDimension ViewDimension
    {
        RenderTargetViewDimension get()
        {
            return (RenderTargetViewDimension)(nativeObject->ViewDimension);
        }
        void set(RenderTargetViewDimension value)
        {
            nativeObject->ViewDimension = (D3D11_RTV_DIMENSION)value;
        }
    }
    /// <summary>
    /// Specifies which buffer elements can be accessed (see <see cref="BufferRenderTargetView"/>)<seealso cref="BufferRenderTargetView"/>.
    /// <para>(Also see DirectX SDK: D3D11_RENDER_TARGET_VIEW_DESC.Buffer)</para>
    /// </summary>
    property BufferRenderTargetView^ Buffer
    {
        BufferRenderTargetView^ get()
        {
            if (buffer == nullptr)
                buffer = gcnew BufferRenderTargetView(&(nativeObject->Buffer), false);
            return buffer;
        }
        void set(BufferRenderTargetView^ value)
        {
            memcpy(&(nativeObject->Buffer), (void*)(value->nativeObject.Get()), sizeof(D3D11_BUFFER_RTV));
        }
    }
    /// <summary>
    /// Specifies the subresources in a 1D texture that can be accessed (see <see cref="Tex1dRenderTargetView"/>)<seealso cref="Tex1dRenderTargetView"/>.
    /// <para>(Also see DirectX SDK: D3D11_RENDER_TARGET_VIEW_DESC.Texture1D)</para>
    /// </summary>
    property Tex1dRenderTargetView^ Texture1D
    {
        Tex1dRenderTargetView^ get()
        {
            if (texture1D == nullptr)
               texture1D = gcnew Tex1dRenderTargetView(&(nativeObject->Texture1D), false);
            return texture1D;

        }
        void set(Tex1dRenderTargetView^ value)
        {
            memcpy(&(nativeObject->Texture1D), (void*)(value->nativeObject.Get()), sizeof(D3D11_TEX1D_RTV));
        }
    }
    /// <summary>
    /// Specifies the subresources in a 1D texture array that can be accessed (see <see cref="Tex1dArrayRenderTargetView"/>)<seealso cref="Tex1dArrayRenderTargetView"/>.
    /// <para>(Also see DirectX SDK: D3D11_RENDER_TARGET_VIEW_DESC.Texture1DArray)</para>
    /// </summary>
    property Tex1dArrayRenderTargetView^ Texture1DArray
    {
        Tex1dArrayRenderTargetView^ get()
        {
            if (texture1DArray == nullptr)
                texture1DArray = gcnew Tex1dArrayRenderTargetView(&(nativeObject->Texture1DArray), false);
            return texture1DArray;
        }
        void set(Tex1dArrayRenderTargetView^ value)
        {
            memcpy(&(nativeObject->Texture1DArray), (void*)(value->nativeObject.Get()), sizeof(D3D11_TEX1D_ARRAY_RTV));
        }
    }
    /// <summary>
    /// Specifies the subresources in a 2D texture that can be accessed (see <see cref="Tex2dRenderTargetView"/>)<seealso cref="Tex2dRenderTargetView"/>.
    /// <para>(Also see DirectX SDK: D3D11_RENDER_TARGET_VIEW_DESC.Texture2D)</para>
    /// </summary>
    property Tex2dRenderTargetView^ Texture2D
    {
        Tex2dRenderTargetView^ get()
        {
            if (texture2D == nullptr)
               texture2D = gcnew Tex2dRenderTargetView(&(nativeObject->Texture2D), false);
            return texture2D;
        }
        void set(Tex2dRenderTargetView^ value)
        {
            memcpy(&(nativeObject->Texture2D), (void*)(value->nativeObject.Get()), sizeof(D3D11_TEX2D_RTV));
        }
    }
    /// <summary>
    /// Specifies the subresources in a 2D texture array that can be accessed (see <see cref="Tex2dArrayRenderTargetView"/>)<seealso cref="Tex2dArrayRenderTargetView"/>.
    /// <para>(Also see DirectX SDK: D3D11_RENDER_TARGET_VIEW_DESC.Texture2DArray)</para>
    /// </summary>
    property Tex2dArrayRenderTargetView^ Texture2DArray
    {
        Tex2dArrayRenderTargetView^ get()
        {
            if (texture2DArray == nullptr)
                texture2DArray = gcnew Tex2dArrayRenderTargetView(&(nativeObject->Texture2DArray), false);
            return texture2DArray;
        }
        void set(Tex2dArrayRenderTargetView^ value)
        {
            memcpy(&(nativeObject->Texture2DArray), (void*)(value->nativeObject.Get()), sizeof(D3D11_TEX2D_ARRAY_RTV));
        }
    }
    /// <summary>
    /// Specifies a single subresource because a multisampled 2D texture only contains one subresource (see <see cref="Tex2dmsRenderTargetView"/>)<seealso cref="Tex2dmsRenderTargetView"/>.
    /// <para>(Also see DirectX SDK: D3D11_RENDER_TARGET_VIEW_DESC.Texture2DMS)</para>
    /// </summary>
    property Tex2dmsRenderTargetView^ Texture2DMS
    {
        Tex2dmsRenderTargetView^ get()
        {
            if (texture2DMS == nullptr)
                texture2DMS = gcnew Tex2dmsRenderTargetView(&(nativeObject->Texture2DMS), false);
            return texture2DMS ;
        }
        void set(Tex2dmsRenderTargetView^ value)
        {
            memcpy(&(nativeObject->Texture2DMS), (void*)(value->nativeObject.Get()), sizeof(D3D11_TEX2DMS_RTV));
        }
    }
    /// <summary>
    /// Specifies the subresources in a multisampled 2D texture array that can be accessed (see <see cref="Tex2dmsArrayRenderTargetView"/>)<seealso cref="Tex2dmsArrayRenderTargetView"/>.
    /// <para>(Also see DirectX SDK: D3D11_RENDER_TARGET_VIEW_DESC.Texture2DMSArray)</para>
    /// </summary>
    property Tex2dmsArrayRenderTargetView^ Texture2DMSArray
    {
        Tex2dmsArrayRenderTargetView^ get()
        {
            if (texture2DMSArray == nullptr)
                texture2DMSArray = gcnew Tex2dmsArrayRenderTargetView(&(nativeObject->Texture2DMSArray), false);
            return texture2DMSArray;
        }
        void set(Tex2dmsArrayRenderTargetView^ value)
        {
            memcpy(&(nativeObject->Texture2DMSArray), (void*)(value->nativeObject.Get()), sizeof(D3D11_TEX2DMS_ARRAY_RTV));
        }
    }
    /// <summary>
    /// Specifies subresources in a 3D texture that can be accessed (see <see cref="Tex3dRenderTargetView"/>)<seealso cref="Tex3dRenderTargetView"/>.
    /// <para>(Also see DirectX SDK: D3D11_RENDER_TARGET_VIEW_DESC.Texture3D)</para>
    /// </summary>
    property Tex3dRenderTargetView^ Texture3D
    {
        Tex3dRenderTargetView^ get()
        {
            if (texture3D == nullptr)
                texture3D = gcnew Tex3dRenderTargetView(&(nativeObject->Texture3D), false);
            return texture3D;
        }
        void set(Tex3dRenderTargetView^ value)
        {
            memcpy(&(nativeObject->Texture3D), (void*)(value->nativeObject.Get()), sizeof(D3D11_TEX3D_RTV));
        }
    }
public:
    RenderTargetViewDescription()
    {
        nativeObject.Set(new D3D11_RENDER_TARGET_VIEW_DESC());
        ZeroMemory(nativeObject.Get(), sizeof(D3D11_RENDER_TARGET_VIEW_DESC));
    }
internal:
    AutoPointer<D3D11_RENDER_TARGET_VIEW_DESC> nativeObject;
internal:
    RenderTargetViewDescription(D3D11_RENDER_TARGET_VIEW_DESC* pRenderTargetViewDescription)
    {
        nativeObject.Set(pRenderTargetViewDescription);
    }
    RenderTargetViewDescription(D3D11_RENDER_TARGET_VIEW_DESC* pRenderTargetViewDescription, bool deletable)
    {
        nativeObject.Set(pRenderTargetViewDescription, deletable);
    }
private:
    BufferRenderTargetView^ buffer;
    Tex1dRenderTargetView^ texture1D;
    Tex1dArrayRenderTargetView^ texture1DArray;
    Tex2dRenderTargetView^ texture2D;
    Tex2dArrayRenderTargetView^ texture2DArray;
    Tex2dmsRenderTargetView^ texture2DMS;
    Tex2dmsArrayRenderTargetView^ texture2DMSArray;
    Tex3dRenderTargetView^ texture3D;
};
/// <summary>
/// Describes a sampler state.
/// <para>(Also see DirectX SDK: D3D11_SAMPLER_DESC)</para>
/// </summary>
public ref struct SamplerDescription 
{
public:
    /// <summary>
    /// Filtering method to use when sampling a texture (see <see cref="Filter"/>)<seealso cref="Filter"/>.
    /// <para>(Also see DirectX SDK: D3D11_SAMPLER_DESC.Filter)</para>
    /// </summary>
    property Filter FilterMethod
    {
        Filter get()
        {
            return (Filter)(nativeObject->Filter);
        }
        void set(Filter value)
        {
            nativeObject->Filter = (D3D11_FILTER)value;
        }
    }
    /// <summary>
    /// Method to use for resolving a u texture coordinate that is outside the 0 to 1 range (see <see cref="TextureAddressMode"/>)<seealso cref="TextureAddressMode"/>.
    /// <para>(Also see DirectX SDK: D3D11_SAMPLER_DESC.AddressU)</para>
    /// </summary>
    property TextureAddressMode AddressU
    {
        TextureAddressMode get()
        {
            return (TextureAddressMode)(nativeObject->AddressU);
        }
        void set(TextureAddressMode value)
        {
            nativeObject->AddressU = (D3D11_TEXTURE_ADDRESS_MODE)value;
        }
    }
    /// <summary>
    /// Method to use for resolving a v texture coordinate that is outside the 0 to 1 range.
    /// <para>(Also see DirectX SDK: D3D11_SAMPLER_DESC.AddressV)</para>
    /// </summary>
    property TextureAddressMode AddressV
    {
        TextureAddressMode get()
        {
            return (TextureAddressMode)(nativeObject->AddressV);
        }
        void set(TextureAddressMode value)
        {
            nativeObject->AddressV = (D3D11_TEXTURE_ADDRESS_MODE)value;
        }
    }
    /// <summary>
    /// Method to use for resolving a w texture coordinate that is outside the 0 to 1 range.
    /// <para>(Also see DirectX SDK: D3D11_SAMPLER_DESC.AddressW)</para>
    /// </summary>
    property TextureAddressMode AddressW
    {
        TextureAddressMode get()
        {
            return (TextureAddressMode)(nativeObject->AddressW);
        }
        void set(TextureAddressMode value)
        {
            nativeObject->AddressW = (D3D11_TEXTURE_ADDRESS_MODE)value;
        }
    }
    /// <summary>
    /// offset from the calculated mipmap level. For example, if Direct3D calculates that a texture should be sampled at mipmap level 3 and MipLODBias is 2, then the texture will be sampled at mipmap level 5.
    /// <para>(Also see DirectX SDK: D3D11_SAMPLER_DESC.MipLODBias)</para>
    /// </summary>
    property Single MipLODBias
    {
        Single get()
        {
            return (Single)(nativeObject->MipLODBias);
        }
        void set(Single value)
        {
            nativeObject->MipLODBias = (FLOAT)value;
        }
    }
    /// <summary>
    /// Clamping value used if Anisotropic or ComparisonAnisotropic is specified in Filter. Valid values are between 1 and 16.
    /// <para>(Also see DirectX SDK: D3D11_SAMPLER_DESC.MaxAnisotropy)</para>
    /// </summary>
    property UInt32 MaxAnisotropy
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->MaxAnisotropy);
        }
        void set(UInt32 value)
        {
            nativeObject->MaxAnisotropy = (UINT)value;
        }
    }
    /// <summary>
    /// A function that compares sampled data against existing sampled data. The function options are listed in ComparisonFunc.
    /// <para>(Also see DirectX SDK: D3D11_SAMPLER_DESC.ComparisonFunc)</para>
    /// </summary>
    property ComparisonFunc ComparisonFunction
    {
        ComparisonFunc get()
        {
            return (ComparisonFunc)(nativeObject->ComparisonFunc);
        }
        void set(ComparisonFunc value)
        {
            nativeObject->ComparisonFunc = (D3D11_COMPARISON_FUNC)value;
        }
    }
    /// <summary>
    /// Border color to use if Border is specified for AddressU, AddressV, or AddressW. Range must be between 0.0 and 1.0 inclusive.
    /// <para>(Also see DirectX SDK: D3D11_SAMPLER_DESC.BorderColor)</para>
    /// </summary>
    property ColorRGBA^ BorderColor
    {
        ColorRGBA^ get()
        {
            if (borderColor == nullptr)
                borderColor = gcnew ColorRGBA(nativeObject->BorderColor, false);
            return borderColor;
        }

        void set(ColorRGBA^ value)
        {
            memcpy(nativeObject->BorderColor, value->nativeObject.Get(), sizeof(FLOAT) * 4);
        }

    }
    /// <summary>
    /// Lower end of the mipmap range to clamp access to, where 0 is the largest and most detailed mipmap level and any level higher than that is less detailed.
    /// <para>(Also see DirectX SDK: D3D11_SAMPLER_DESC.MinLOD)</para>
    /// </summary>
    property Single MinLOD
    {
        Single get()
        {
            return (Single)(nativeObject->MinLOD);
        }
        void set(Single value)
        {
            nativeObject->MinLOD = (FLOAT)value;
        }
    }
    /// <summary>
    /// Upper end of the mipmap range to clamp access to, where 0 is the largest and most detailed mipmap level and any level higher than that is less detailed. This value must be greater than or equal to MinLOD. To have no upper limit on LOD set this to a large value such as D3D11_FLOAT32_MAX.
    /// <para>(Also see DirectX SDK: D3D11_SAMPLER_DESC.MaxLOD)</para>
    /// </summary>
    property Single MaxLOD
    {
        Single get()
        {
            return (Single)(nativeObject->MaxLOD);
        }
        void set(Single value)
        {
            nativeObject->MaxLOD = (FLOAT)value;
        }
    }
public:
    SamplerDescription()
    {
        nativeObject.Set(new D3D11_SAMPLER_DESC());
        ZeroMemory(nativeObject.Get(), sizeof(D3D11_SAMPLER_DESC));
    }
internal:
    AutoPointer<D3D11_SAMPLER_DESC> nativeObject;
internal:
    SamplerDescription(D3D11_SAMPLER_DESC* pSamplerDescription)
    {
        nativeObject.Set(pSamplerDescription);
    }
    SamplerDescription(D3D11_SAMPLER_DESC* pSamplerDescription, bool deletable)
    {
        nativeObject.Set(pSamplerDescription, deletable);
    }
private:
    ColorRGBA^ borderColor;
};
/// <summary>
/// Describes a shader-resource view.
/// <para>(Also see DirectX SDK: D3D11_SHADER_RESOURCE_VIEW_DESC)</para>
/// </summary>
public ref struct ShaderResourceViewDescription 
{
public:
    /// <summary>
    /// A Format specifying the viewing format.
    /// <para>(Also see DirectX SDK: D3D11_SHADER_RESOURCE_VIEW_DESC.Format)</para>
    /// </summary>
    property Format ViewingFormat
    {
        Format get()
        {
            return (Format)(nativeObject->Format);
        }
        void set(Format value)
        {
            nativeObject->Format = (DXGI_FORMAT)value;
        }
    }
    /// <summary>
    /// The resource type of the view. See ShaderResourceViewDimension. This should be the same as the resource type of the underlying resource. This parameter also determines which _SRV to use in the union below.
    /// <para>(Also see DirectX SDK: D3D11_SHADER_RESOURCE_VIEW_DESC.ViewDimension)</para>
    /// </summary>
    property ShaderResourceViewDimension ViewDimension
    {
        ShaderResourceViewDimension get()
        {
            return (ShaderResourceViewDimension)(nativeObject->ViewDimension);
        }
        void set(ShaderResourceViewDimension value)
        {
            nativeObject->ViewDimension = (D3D11_SRV_DIMENSION)value;
        }
    }
    /// <summary>
    /// View the resource as a buffer using information from a shader-resource view (see <see cref="BufferShaderResourceView"/>)<seealso cref="BufferShaderResourceView"/>.
    /// <para>(Also see DirectX SDK: D3D11_SHADER_RESOURCE_VIEW_DESC.Buffer)</para>
    /// </summary>
    property BufferShaderResourceView^ Buffer
    {
        BufferShaderResourceView^ get()
        {
            if (buffer == nullptr)
                buffer =  gcnew BufferShaderResourceView(&(nativeObject->Buffer), false);
            return buffer;
        }
        void set(BufferShaderResourceView^ value)
        {
            memcpy(&(nativeObject->Buffer), (void*)(value->nativeObject.Get()), sizeof(D3D11_BUFFER_SRV));
        }
    }
    /// <summary>
    /// View the resource as a 1D texture using information from a shader-resource view (see <see cref="Tex1dShaderResourceView"/>)<seealso cref="Tex1dShaderResourceView"/>.
    /// <para>(Also see DirectX SDK: D3D11_SHADER_RESOURCE_VIEW_DESC.Texture1D)</para>
    /// </summary>
    property Tex1dShaderResourceView^ Texture1D
    {
        Tex1dShaderResourceView^ get()
        {
            if (texture1D == nullptr)
                texture1D = gcnew Tex1dShaderResourceView(&(nativeObject->Texture1D), false);
            return texture1D;
        }
        void set(Tex1dShaderResourceView^ value)
        {
            memcpy(&(nativeObject->Texture1D), (void*)(value->nativeObject.Get()), sizeof(D3D11_TEX1D_SRV));
        }
    }
    /// <summary>
    /// View the resource as a 1D-texture array using information from a shader-resource view (see <see cref="Tex1dArrayShaderResourceView"/>)<seealso cref="Tex1dArrayShaderResourceView"/>.
    /// <para>(Also see DirectX SDK: D3D11_SHADER_RESOURCE_VIEW_DESC.Texture1DArray)</para>
    /// </summary>
    property Tex1dArrayShaderResourceView^ Texture1DArray
    {
        Tex1dArrayShaderResourceView^ get()
        {
            if (texture1DArray == nullptr)
                texture1DArray = gcnew Tex1dArrayShaderResourceView(&(nativeObject->Texture1DArray), false);
            return texture1DArray;
        }
        void set(Tex1dArrayShaderResourceView^ value)
        {
            memcpy(&(nativeObject->Texture1DArray), (void*)(value->nativeObject.Get()), sizeof(D3D11_TEX1D_ARRAY_SRV));
        }
    }
    /// <summary>
    /// View the resource as a 2D-texture using information from a shader-resource view (see <see cref="Tex2dShaderResourceView"/>)<seealso cref="Tex2dShaderResourceView"/>.
    /// <para>(Also see DirectX SDK: D3D11_SHADER_RESOURCE_VIEW_DESC.Texture2D)</para>
    /// </summary>
    property Tex2dShaderResourceView^ Texture2D
    {
        Tex2dShaderResourceView^ get()
        {
            if (texture2D == nullptr)
                texture2D = gcnew Tex2dShaderResourceView(&(nativeObject->Texture2D), false);
            return texture2D;
        }
        void set(Tex2dShaderResourceView^ value)
        {
            memcpy(&(nativeObject->Texture2D), (void*)(value->nativeObject.Get()), sizeof(D3D11_TEX2D_SRV));
        }
    }
    /// <summary>
    /// View the resource as a 2D-texture array using information from a shader-resource view (see <see cref="Tex2dArrayShaderResourceView"/>)<seealso cref="Tex2dArrayShaderResourceView"/>.
    /// <para>(Also see DirectX SDK: D3D11_SHADER_RESOURCE_VIEW_DESC.Texture2DArray)</para>
    /// </summary>
    property Tex2dArrayShaderResourceView^ Texture2DArray
    {
        Tex2dArrayShaderResourceView^ get()
        {
            if (texture2DArray == nullptr)
                texture2DArray  = gcnew Tex2dArrayShaderResourceView(&(nativeObject->Texture2DArray), false);
            return texture2DArray ;
        }
        void set(Tex2dArrayShaderResourceView^ value)
        {
            memcpy(&(nativeObject->Texture2DArray), (void*)(value->nativeObject.Get()), sizeof(D3D11_TEX2D_ARRAY_SRV));
        }
    }
    /// <summary>
    /// View the resource as a 2D-multisampled texture using information from a shader-resource view (see <see cref="Tex2dmsShaderResourceView"/>)<seealso cref="Tex2dmsShaderResourceView"/>.
    /// <para>(Also see DirectX SDK: D3D11_SHADER_RESOURCE_VIEW_DESC.Texture2DMS)</para>
    /// </summary>
    property Tex2dmsShaderResourceView^ Texture2DMS
    {
        Tex2dmsShaderResourceView^ get()
        {
            if (texture2DMS == nullptr)
                texture2DMS = gcnew Tex2dmsShaderResourceView(&(nativeObject->Texture2DMS), false);
            return texture2DMS;
        }
        void set(Tex2dmsShaderResourceView^ value)
        {
            memcpy(&(nativeObject->Texture2DMS), (void*)(value->nativeObject.Get()), sizeof(D3D11_TEX2DMS_SRV));
        }
    }
    /// <summary>
    /// View the resource as a 2D-multisampled-texture array using information from a shader-resource view (see <see cref="Tex2dmsArrayShaderResourceView"/>)<seealso cref="Tex2dmsArrayShaderResourceView"/>.
    /// <para>(Also see DirectX SDK: D3D11_SHADER_RESOURCE_VIEW_DESC.Texture2DMSArray)</para>
    /// </summary>
    property Tex2dmsArrayShaderResourceView^ Texture2DMSArray
    {
        Tex2dmsArrayShaderResourceView^ get()
        {
            if (texture2DMSArray == nullptr)
                texture2DMSArray = gcnew Tex2dmsArrayShaderResourceView(&(nativeObject->Texture2DMSArray), false);
            return texture2DMSArray;
        }
        void set(Tex2dmsArrayShaderResourceView^ value)
        {
            memcpy(&(nativeObject->Texture2DMSArray), (void*)(value->nativeObject.Get()), sizeof(D3D11_TEX2DMS_ARRAY_SRV));
        }
    }
    /// <summary>
    /// View the resource as a 3D texture using information from a shader-resource view (see <see cref="Tex3dShaderResourceView"/>)<seealso cref="Tex3dShaderResourceView"/>.
    /// <para>(Also see DirectX SDK: D3D11_SHADER_RESOURCE_VIEW_DESC.Texture3D)</para>
    /// </summary>
    property Tex3dShaderResourceView^ Texture3D
    {
        Tex3dShaderResourceView^ get()
        {
            if (texture3D == nullptr)
                texture3D = gcnew Tex3dShaderResourceView(&(nativeObject->Texture3D), false);
            return texture3D;
        }
        void set(Tex3dShaderResourceView^ value)
        {
            memcpy(&(nativeObject->Texture3D), (void*)(value->nativeObject.Get()), sizeof(D3D11_TEX3D_SRV));
        }
    }
    /// <summary>
    /// View the resource as a 3D-cube texture using information from a shader-resource view (see <see cref="TexcubeShaderResourceView"/>)<seealso cref="TexcubeShaderResourceView"/>.
    /// <para>(Also see DirectX SDK: D3D11_SHADER_RESOURCE_VIEW_DESC.TextureCube)</para>
    /// </summary>
    property TexcubeShaderResourceView^ TextureCube
    {
        TexcubeShaderResourceView^ get()
        {
            if (textureCube == nullptr)
                textureCube = gcnew TexcubeShaderResourceView(&(nativeObject->TextureCube), false);
            return textureCube;
        }
        void set(TexcubeShaderResourceView^ value)
        {
            memcpy(&(nativeObject->TextureCube), (void*)(value->nativeObject.Get()), sizeof(D3D11_TEXCUBE_SRV));
        }
    }
    /// <summary>
    /// View the resource as a 3D-cube-texture array using information from a shader-resource view (see <see cref="TexcubeArrayShaderResourceView"/>)<seealso cref="TexcubeArrayShaderResourceView"/>.
    /// <para>(Also see DirectX SDK: D3D11_SHADER_RESOURCE_VIEW_DESC.TextureCubeArray)</para>
    /// </summary>
    property TexcubeArrayShaderResourceView^ TextureCubeArray
    {
        TexcubeArrayShaderResourceView^ get()
        {
            if (textureCubeArray == nullptr)
                textureCubeArray = gcnew TexcubeArrayShaderResourceView(&(nativeObject->TextureCubeArray), false);
            return textureCubeArray;
        }
        void set(TexcubeArrayShaderResourceView^ value)
        {
            memcpy(&(nativeObject->TextureCubeArray), (void*)(value->nativeObject.Get()), sizeof(D3D11_TEXCUBE_ARRAY_SRV));
        }
    }
    /// <summary>
    /// View the resource as an extended buffer using information from a shader-resource view (see <see cref="BufferexShaderResourceView"/>)<seealso cref="BufferexShaderResourceView"/>.
    /// <para>(Also see DirectX SDK: D3D11_SHADER_RESOURCE_VIEW_DESC.BufferEx)</para>
    /// </summary>
    property BufferexShaderResourceView^ BufferEx
    {
        BufferexShaderResourceView^ get()
        {
            if (bufferEx == nullptr)
                bufferEx = gcnew BufferexShaderResourceView(&(nativeObject->BufferEx), false);
            return bufferEx;
        }
        void set(BufferexShaderResourceView^ value)
        {
            memcpy(&(nativeObject->BufferEx), (void*)(value->nativeObject.Get()), sizeof(D3D11_BUFFEREX_SRV));
        }
    }
public:
    ShaderResourceViewDescription()
    {
        nativeObject.Set(new D3D11_SHADER_RESOURCE_VIEW_DESC());
        ZeroMemory(nativeObject.Get(), sizeof(D3D11_SHADER_RESOURCE_VIEW_DESC));
    }
internal:
    AutoPointer<D3D11_SHADER_RESOURCE_VIEW_DESC> nativeObject;
internal:
    ShaderResourceViewDescription(D3D11_SHADER_RESOURCE_VIEW_DESC* pShaderResourceViewDescription)
    {
        nativeObject.Set(pShaderResourceViewDescription);
    }
    ShaderResourceViewDescription(D3D11_SHADER_RESOURCE_VIEW_DESC* pShaderResourceViewDescription, bool deletable)
    {
        nativeObject.Set(pShaderResourceViewDescription, deletable);
    }
private:
    BufferShaderResourceView^ buffer;
    Tex1dShaderResourceView^ texture1D;
    Tex1dArrayShaderResourceView^ texture1DArray;
    Tex2dShaderResourceView^ texture2D;
    Tex2dArrayShaderResourceView^ texture2DArray;
    Tex2dmsShaderResourceView^ texture2DMS;
    Tex2dmsArrayShaderResourceView^ texture2DMSArray;
    Tex3dShaderResourceView^ texture3D;
    TexcubeShaderResourceView^ textureCube;
    TexcubeArrayShaderResourceView^ textureCubeArray;
    BufferexShaderResourceView^ bufferEx;
};
/// <summary>
/// Description of a vertex element in a vertex buffer in an output slot.
/// <para>(Also see DirectX SDK: D3D11_SO_DECLARATION_ENTRY)</para>
/// </summary>
public ref struct SoDeclarationEntry 
{
public:
    /// <summary>
    /// Zero-based, stream number.
    /// <para>(Also see DirectX SDK: D3D11_SO_DECLARATION_ENTRY.Stream)</para>
    /// </summary>
    property UInt32 Stream
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->Stream);
        }
        void set(UInt32 value)
        {
            nativeObject->Stream = (UINT)value;
        }
    }
    /// <summary>
    /// Type of output element; possible values include: "POSITION", "NORMAL", or "TEXCOORD0".
    /// <para>(Also see DirectX SDK: D3D11_SO_DECLARATION_ENTRY.SemanticName)</para>
    /// </summary>
    property String^ SemanticName
    {
        String^ get()
        {
            if (nativeObject->SemanticName == NULL)
            {
                return nullptr;
            }
            return gcnew String(nativeObject->SemanticName);
        }

        void set(String^ value)
        {
            if (nativeObject->SemanticName != NULL)
            {
                delete [] nativeObject->SemanticName;
            }

            nativeObject->SemanticName = D3DUtils::CharArrayfromSystemString(value);
        }
    }
    /// <summary>
    /// Output element's zero-based index. Should be used if, for example, you have more than one texture coordinate stored in each vertex.
    /// <para>(Also see DirectX SDK: D3D11_SO_DECLARATION_ENTRY.SemanticIndex)</para>
    /// </summary>
    property UInt32 SemanticIndex
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->SemanticIndex);
        }
        void set(UInt32 value)
        {
            nativeObject->SemanticIndex = (UINT)value;
        }
    }
    /// <summary>
    /// Which component of the entry to begin writing out to. Valid values are 0 ~ 3. For example, if you only wish to output to the y and z components of a position, then StartComponent should be 1 and ComponentCount should be 2.
    /// <para>(Also see DirectX SDK: D3D11_SO_DECLARATION_ENTRY.StartComponent)</para>
    /// </summary>
    property SByte StartComponent
    {
        SByte get()
        {
            return (SByte)(nativeObject->StartComponent);
        }
        void set(SByte value)
        {
            nativeObject->StartComponent = (BYTE)value;
        }
    }
    /// <summary>
    /// The number of components of the entry to write out to. Valid values are 1 ~ 4. For example, if you only wish to output to the y and z components of a position, then StartComponent should be 1 and ComponentCount should be 2.
    /// <para>(Also see DirectX SDK: D3D11_SO_DECLARATION_ENTRY.ComponentCount)</para>
    /// </summary>
    property SByte ComponentCount
    {
        SByte get()
        {
            return (SByte)(nativeObject->ComponentCount);
        }
        void set(SByte value)
        {
            nativeObject->ComponentCount = (BYTE)value;
        }
    }
    /// <summary>
    /// The output slot that contains the vertex buffer that contains this output entry.
    /// <para>(Also see DirectX SDK: D3D11_SO_DECLARATION_ENTRY.OutputSlot)</para>
    /// </summary>
    property SByte OutputSlot
    {
        SByte get()
        {
            return (SByte)(nativeObject->OutputSlot);
        }
        void set(SByte value)
        {
            nativeObject->OutputSlot = (BYTE)value;
        }
    }
public:
    SoDeclarationEntry()
    {
        nativeObject.Set(new D3D11_SO_DECLARATION_ENTRY());
        ZeroMemory(nativeObject.Get(), sizeof(D3D11_SO_DECLARATION_ENTRY));
    }
internal:
    AutoPointer<D3D11_SO_DECLARATION_ENTRY> nativeObject;
internal:
    SoDeclarationEntry(D3D11_SO_DECLARATION_ENTRY* pSoDeclarationEntry)
    {
        nativeObject.Set(pSoDeclarationEntry);
    }
    SoDeclarationEntry(D3D11_SO_DECLARATION_ENTRY* pSoDeclarationEntry, bool deletable)
    {
        nativeObject.Set(pSoDeclarationEntry, deletable);
    }
protected:
    !SoDeclarationEntry()
    {
        if (nativeObject.Get() != NULL && nativeObject->SemanticName != NULL)
        {
            Marshal::FreeHGlobal(IntPtr((void*)nativeObject->SemanticName));
            nativeObject->SemanticName = NULL;
        }
    }

    ~SoDeclarationEntry()
    {
        SoDeclarationEntry::!SoDeclarationEntry();
    }
};
/// <summary>
/// Specifies data for initializing a subresource.
/// <para>(Also see DirectX SDK: D3D11_SUBRESOURCE_DATA)</para>
/// </summary>
public ref struct SubresourceData 
{
public:
    /// <summary>
    /// Pointer to the initialization data.
    /// <para>(Also see DirectX SDK: D3D11_SUBRESOURCE_DATA.pSysMem)</para>
    /// </summary>
    property IntPtr SysMem
    {
        void set(IntPtr value)
        {
            nativeObject->pSysMem = value.ToPointer();;
        }

        IntPtr get()
        {
            return IntPtr((void*)nativeObject->pSysMem);
        }
    }

    /// <summary>
    /// Pitch of the memory (in bytes). System-memory pitch is used only for 2D and 3D texture data as it is has no meaning for the other resource types.
    /// <para>(Also see DirectX SDK: D3D11_SUBRESOURCE_DATA.SysMemPitch)</para>
    /// </summary>
    property UInt32 SysMemPitch
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->SysMemPitch);
        }
        void set(UInt32 value)
        {
            nativeObject->SysMemPitch = (UINT)value;
        }
    }
    /// <summary>
    /// Size of one depth level (in bytes). System-memory-slice pitch is only used for 3D texture data as it has no meaning for the other resource types.
    /// <para>(Also see DirectX SDK: D3D11_SUBRESOURCE_DATA.SysMemSlicePitch)</para>
    /// </summary>
    property UInt32 SysMemSlicePitch
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->SysMemSlicePitch);
        }
        void set(UInt32 value)
        {
            nativeObject->SysMemSlicePitch = (UINT)value;
        }
    }
public:
    SubresourceData()
    {
        nativeObject.Set(new D3D11_SUBRESOURCE_DATA());
        ZeroMemory(nativeObject.Get(), sizeof(D3D11_SUBRESOURCE_DATA));
    }
internal:
    AutoPointer<D3D11_SUBRESOURCE_DATA> nativeObject;
internal:
    SubresourceData(D3D11_SUBRESOURCE_DATA* pSubresourceData)
    {
        nativeObject.Set(pSubresourceData);
    }
    SubresourceData(D3D11_SUBRESOURCE_DATA* pSubresourceData, bool deletable)
    {
        nativeObject.Set(pSubresourceData, deletable);
    }
};
/// <summary>
/// Specifies the subresources from a resource that are accessible using an unordered-access view.
/// <para>(Also see DirectX SDK: D3D11_UNORDERED_ACCESS_VIEW_DESC)</para>
/// </summary>
public ref struct UnorderedAccessViewDescription 
{
public:
    /// <summary>
    /// The data format (see <see cref="Format"/>)<seealso cref="Format"/>.
    /// <para>(Also see DirectX SDK: D3D11_UNORDERED_ACCESS_VIEW_DESC.Format)</para>
    /// </summary>
    property Format DataFormat
    {
        Format get()
        {
            return (Format)(nativeObject->Format);
        }
        void set(Format value)
        {
            nativeObject->Format = (DXGI_FORMAT)value;
        }
    }
    /// <summary>
    /// The resource type (see <see cref="UnorderedAccessViewDimension"/>)<seealso cref="UnorderedAccessViewDimension"/>, which specifies how the resource will be accessed.
    /// <para>(Also see DirectX SDK: D3D11_UNORDERED_ACCESS_VIEW_DESC.ViewDimension)</para>
    /// </summary>
    property UnorderedAccessViewDimension ViewDimension
    {
        UnorderedAccessViewDimension get()
        {
            return (UnorderedAccessViewDimension)(nativeObject->ViewDimension);
        }
        void set(UnorderedAccessViewDimension value)
        {
            nativeObject->ViewDimension = (D3D11_UAV_DIMENSION)value;
        }
    }
    /// <summary>
    /// Specifies which buffer elements can be accessed (see <see cref="BufferUnorderedAccessView"/>)<seealso cref="BufferUnorderedAccessView"/>.
    /// <para>(Also see DirectX SDK: D3D11_UNORDERED_ACCESS_VIEW_DESC.Buffer)</para>
    /// </summary>
    property BufferUnorderedAccessView^ Buffer
    {
        BufferUnorderedAccessView^ get()
        {
            if (buffer == nullptr)
                buffer = gcnew BufferUnorderedAccessView(&(nativeObject->Buffer), false);
            return buffer;
        }
        void set(BufferUnorderedAccessView^ value)
        {
            memcpy(&(nativeObject->Buffer), (void*)(value->nativeObject.Get()), sizeof(D3D11_BUFFER_UAV));
        }
    }
    /// <summary>
    /// Specifies the subresources in a 1D texture that can be accessed (see <see cref="Tex1dUnorderedAccessView"/>)<seealso cref="Tex1dUnorderedAccessView"/>.
    /// <para>(Also see DirectX SDK: D3D11_UNORDERED_ACCESS_VIEW_DESC.Texture1D)</para>
    /// </summary>
    property Tex1dUnorderedAccessView^ Texture1D
    {
        Tex1dUnorderedAccessView^ get()
        {
            if (texture1D == nullptr)
                texture1D = gcnew Tex1dUnorderedAccessView(&(nativeObject->Texture1D), false);
            return texture1D;
        }
        void set(Tex1dUnorderedAccessView^ value)
        {
            memcpy(&(nativeObject->Texture1D), (void*)(value->nativeObject.Get()), sizeof(D3D11_TEX1D_UAV));
        }
    }
    /// <summary>
    /// Specifies the subresources in a 1D texture array that can be accessed (see <see cref="Tex1dArrayUnorderedAccessView"/>)<seealso cref="Tex1dArrayUnorderedAccessView"/>.
    /// <para>(Also see DirectX SDK: D3D11_UNORDERED_ACCESS_VIEW_DESC.Texture1DArray)</para>
    /// </summary>
    property Tex1dArrayUnorderedAccessView^ Texture1DArray
    {
        Tex1dArrayUnorderedAccessView^ get()
        {
            if (texture1DArray == nullptr)
                texture1DArray = gcnew Tex1dArrayUnorderedAccessView(&(nativeObject->Texture1DArray), false);
            return texture1DArray;
        }
        void set(Tex1dArrayUnorderedAccessView^ value)
        {
            memcpy(&(nativeObject->Texture1DArray), (void*)(value->nativeObject.Get()), sizeof(D3D11_TEX1D_ARRAY_UAV));
        }
    }
    /// <summary>
    /// Specifies the subresources in a 2D texture that can be accessed (see <see cref="Tex2dUnorderedAccessView"/>)<seealso cref="Tex2dUnorderedAccessView"/>.
    /// <para>(Also see DirectX SDK: D3D11_UNORDERED_ACCESS_VIEW_DESC.Texture2D)</para>
    /// </summary>
    property Tex2dUnorderedAccessView^ Texture2D
    {
        Tex2dUnorderedAccessView^ get()
        {
            if (texture2D == nullptr)
                texture2D = gcnew Tex2dUnorderedAccessView(&(nativeObject->Texture2D), false);
            return texture2D;
        }
        void set(Tex2dUnorderedAccessView^ value)
        {
            memcpy(&(nativeObject->Texture2D), (void*)(value->nativeObject.Get()), sizeof(D3D11_TEX2D_UAV));
        }
    }
    /// <summary>
    /// Specifies the subresources in a 2D texture array that can be accessed (see <see cref="Tex2dArrayUnorderedAccessView"/>)<seealso cref="Tex2dArrayUnorderedAccessView"/>.
    /// <para>(Also see DirectX SDK: D3D11_UNORDERED_ACCESS_VIEW_DESC.Texture2DArray)</para>
    /// </summary>
    property Tex2dArrayUnorderedAccessView^ Texture2DArray
    {
        Tex2dArrayUnorderedAccessView^ get()
        {
            if (texture2DArray == nullptr)
                texture2DArray = gcnew Tex2dArrayUnorderedAccessView(&(nativeObject->Texture2DArray), false);
            return texture2DArray;
        }
        void set(Tex2dArrayUnorderedAccessView^ value)
        {
            memcpy(&(nativeObject->Texture2DArray), (void*)(value->nativeObject.Get()), sizeof(D3D11_TEX2D_ARRAY_UAV));
        }
    }
    /// <summary>
    /// Specifies subresources in a 3D texture that can be accessed (see <see cref="Tex3dUnorderedAccessView"/>)<seealso cref="Tex3dUnorderedAccessView"/>.
    /// <para>(Also see DirectX SDK: D3D11_UNORDERED_ACCESS_VIEW_DESC.Texture3D)</para>
    /// </summary>
    property Tex3dUnorderedAccessView^ Texture3D
    {
        Tex3dUnorderedAccessView^ get()
        {
            if (texture3D == nullptr)
                texture3D = gcnew Tex3dUnorderedAccessView(&(nativeObject->Texture3D), false);
            return texture3D;
        }
        void set(Tex3dUnorderedAccessView^ value)
        {
            memcpy(&(nativeObject->Texture3D), (void*)(value->nativeObject.Get()), sizeof(D3D11_TEX3D_UAV));
        }
    }
public:
    UnorderedAccessViewDescription()
    {
        nativeObject.Set(new D3D11_UNORDERED_ACCESS_VIEW_DESC());
        ZeroMemory(nativeObject.Get(), sizeof(D3D11_UNORDERED_ACCESS_VIEW_DESC));
    }
internal:
    AutoPointer<D3D11_UNORDERED_ACCESS_VIEW_DESC> nativeObject;
internal:
    UnorderedAccessViewDescription(D3D11_UNORDERED_ACCESS_VIEW_DESC* pUnorderedAccessViewDescription)
    {
        nativeObject.Set(pUnorderedAccessViewDescription);
    }
    UnorderedAccessViewDescription(D3D11_UNORDERED_ACCESS_VIEW_DESC* pUnorderedAccessViewDescription, bool deletable)
    {
        nativeObject.Set(pUnorderedAccessViewDescription, deletable);
    }
private:
    BufferUnorderedAccessView^ buffer;
    Tex1dUnorderedAccessView^ texture1D;
    Tex1dArrayUnorderedAccessView^ texture1DArray;
    Tex2dUnorderedAccessView^ texture2D;
    Tex2dArrayUnorderedAccessView^ texture2DArray;
    Tex3dUnorderedAccessView^ texture3D;
};
/// <summary>
/// Defines the dimensions of a viewport.
/// <para>(Also see DirectX SDK: D3D11_VIEWPORT)</para>
/// </summary>
public ref struct Viewport 
{
public:
    /// <summary>
    /// X position of the left hand side of the viewport. Ranges between D3D11_VIEWPORT_BOUNDS_MIN and D3D11_VIEWPORT_BOUNDS_MAX.
    /// <para>(Also see DirectX SDK: D3D11_VIEWPORT.TopLeftX)</para>
    /// </summary>
    property Single TopLeftX
    {
        Single get()
        {
            return (Single)(nativeObject->TopLeftX);
        }
        void set(Single value)
        {
            nativeObject->TopLeftX = (FLOAT)value;
        }
    }
    /// <summary>
    /// Y position of the top of the viewport. Ranges between D3D11_VIEWPORT_BOUNDS_MIN and D3D11_VIEWPORT_BOUNDS_MAX.
    /// <para>(Also see DirectX SDK: D3D11_VIEWPORT.TopLeftY)</para>
    /// </summary>
    property Single TopLeftY
    {
        Single get()
        {
            return (Single)(nativeObject->TopLeftY);
        }
        void set(Single value)
        {
            nativeObject->TopLeftY = (FLOAT)value;
        }
    }
    /// <summary>
    /// Width of the viewport.
    /// <para>(Also see DirectX SDK: D3D11_VIEWPORT.Width)</para>
    /// </summary>
    property Single Width
    {
        Single get()
        {
            return (Single)(nativeObject->Width);
        }
        void set(Single value)
        {
            nativeObject->Width = (FLOAT)value;
        }
    }
    /// <summary>
    /// Height of the viewport.
    /// <para>(Also see DirectX SDK: D3D11_VIEWPORT.Height)</para>
    /// </summary>
    property Single Height
    {
        Single get()
        {
            return (Single)(nativeObject->Height);
        }
        void set(Single value)
        {
            nativeObject->Height = (FLOAT)value;
        }
    }
    /// <summary>
    /// Minimum depth of the viewport. Ranges between 0 and 1.
    /// <para>(Also see DirectX SDK: D3D11_VIEWPORT.MinDepth)</para>
    /// </summary>
    property Single MinDepth
    {
        Single get()
        {
            return (Single)(nativeObject->MinDepth);
        }
        void set(Single value)
        {
            nativeObject->MinDepth = (FLOAT)value;
        }
    }
    /// <summary>
    /// Maximum depth of the viewport. Ranges between 0 and 1.
    /// <para>(Also see DirectX SDK: D3D11_VIEWPORT.MaxDepth)</para>
    /// </summary>
    property Single MaxDepth
    {
        Single get()
        {
            return (Single)(nativeObject->MaxDepth);
        }
        void set(Single value)
        {
            nativeObject->MaxDepth = (FLOAT)value;
        }
    }
public:
    Viewport()
    {
        nativeObject.Set(new D3D11_VIEWPORT());
        ZeroMemory(nativeObject.Get(), sizeof(D3D11_VIEWPORT));
    }
internal:
    AutoPointer<D3D11_VIEWPORT> nativeObject;
internal:
    Viewport(D3D11_VIEWPORT* pViewport)
    {
        nativeObject.Set(pViewport);
    }

    Viewport(D3D11_VIEWPORT* pViewport, bool deletable)
    {
        nativeObject.Set(pViewport, deletable);
    }

    Viewport(const D3D11_VIEWPORT& viewport)
    {
        nativeObject.Set(new D3D11_VIEWPORT());
        ZeroMemory(nativeObject.Get(), sizeof(D3D11_VIEWPORT));

        memcpy(nativeObject.Get(), &viewport, sizeof(D3D11_VIEWPORT));
    }
};
} } } }
