//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once
#include "D3DDeviceBase.h"
#include "IShaderBytecode.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Runtime::InteropServices;
using namespace Microsoft::WindowsAPICodePack::DirectX::DXGI;
using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D11;


namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3D11 {

    ref class BlendState;
    ref class D3DBuffer;
    ref class ClassLinkage;
    ref class ComputeShader;
    ref class Counter;
    ref class DeviceContext;
    ref class DepthStencilState;
    ref class D3DResource;
    ref class DepthStencilView;
    ref class DomainShader;
    ref class GeometryShader;
    ref class HullShader;
    ref class InputLayout;
    ref class PixelShader;
    ref class D3DPredicate;
    ref class D3DQuery;
    ref class RasterizerState;
    ref class RenderTargetView;
    ref class SamplerState;
    ref class ShaderResourceView;
    ref class Texture1D;
    ref class Texture2D;
    ref class Texture3D;
    ref class UnorderedAccessView;
    ref class VertexShader;
    ref class InfoQueue;
    ref class SwitchToRef;

    /// <summary>
    /// The device interface represents a virtual adapter; it is used to perform rendering and create resources.
    /// <para>(Also see DirectX SDK: ID3D11Device)</para>
    /// </summary>
    public ref class D3DDevice :
        public Microsoft::WindowsAPICodePack::DirectX::Direct3DCommon::D3DDeviceBase
    {
    public: 

        /// <summary>
        /// Get the type, name, units of measure, and a description of an existing counter.
        /// <para>(Also see DirectX SDK: ID3D11Device::CheckCounter)</para>
        /// </summary>
        /// <param name="description">A counter description (see <see cref="CounterDescription"/>)<seealso cref="CounterDescription"/>. Specifies which counter information is to be retrieved about.</param>
        /// <param name="outType">The data type of a counter (see <see cref="CounterType"/>)<seealso cref="CounterType"/>. Specifies the data type of the counter being retrieved.</param>
        /// <param name="outNumActiveCounters">The number of hardware counters that are needed for this counter type to be created. All instances of the same counter type use the same hardware counters.</param>
        /// <param name="outName">String to be filled with a brief name for the counter. May be NULL if the application is not interested in the name of the counter.</param>
        /// <param name="outUnits">Name of the units a counter measures, provided the memory the pointer points to has enough room to hold the string. Can be NULL. The returned string will always be in English.</param>
        /// <param name="outDescription">A description of the counter, provided the memory the pointer points to has enough room to hold the string. Can be NULL. The returned string will always be in English.</param>
        /// <returns>True if successful; false otherwise.</returns>
        bool CheckCounter(CounterDescription^ description, [Runtime::InteropServices::Out] CounterType %outType, [Runtime::InteropServices::Out] UInt32 %outNumActiveCounters, [Runtime::InteropServices::Out] String^ %outName, [Runtime::InteropServices::Out] String^ %outUnits, [Runtime::InteropServices::Out] String^ %outDescription);

        /// <summary>
        /// Get a counter's information.
        /// <para>(Also see DirectX SDK: ID3D11Device::CheckCounterInfo)</para>
        /// </summary>
        /// <returns>The counter information.</returns>
        CounterInfo^  GetCounterInformation();

        /// <summary>
        /// Gets information about the features that are supported by the current graphics driver.
        /// <para>(Also see DirectX SDK: ID3D11Device::CheckFeatureSupport)</para>
        /// </summary>
        /// <param name="outFeatureData">Data object describing the feature if supported. 
        /// If feature is not supported this parameter will be null.</param>
        /// <returns>True if feature is supported. Otherwise, returns false.</returns>
        bool CheckThreadingSupport([Runtime::InteropServices::Out] FeatureDataThreading ^ %outFeatureData);

        /// <summary>
        /// Gets information about the features that are supported by the current graphics driver.
        /// <para>(Also see DirectX SDK: ID3D11Device::CheckFeatureSupport)</para>
        /// </summary>
        /// <param name="outFeatureData">Data object describing the feature if supported. 
        /// If feature is not supported this parameter will be null.</param>
        /// <returns>True if feature is supported. Otherwise, returns false.</returns>
        bool CheckFeatureDataDoubles([Runtime::InteropServices::Out] FeatureDataDoubles ^ %outFeatureData);

        /// <summary>
        /// Gets information about the features that are supported by the current graphics driver.
        /// <para>(Also see DirectX SDK: ID3D11Device::CheckFeatureSupport)</para>
        /// </summary>
        /// <param name="featureData">Data object describing the feature if supported.</param>
        /// <returns>True if feature is supported. Otherwise, returns false.</returns>
        bool CheckFeatureDataFormatSupport([Runtime::InteropServices::In, Runtime::InteropServices::Out] FeatureDataFormatSupport ^ %featureData);

        /// <summary>
        /// Gets information about the features that are supported by the current graphics driver.
        /// <para>(Also see DirectX SDK: ID3D11Device::CheckFeatureSupport)</para>
        /// </summary>
        /// <param name="featureData">Data object describing the feature if supported.</param>
        /// <returns>True if feature is supported. Otherwise, returns false.</returns>
        bool CheckFeatureDataFormatSupport2([Runtime::InteropServices::In, Runtime::InteropServices::Out] FeatureDataFormatSupport2 ^ %featureData);

        /// <summary>
        /// Gets information about the features that are supported by the current graphics driver.
        /// <para>(Also see DirectX SDK: ID3D11Device::CheckFeatureSupport)</para>
        /// </summary>
        /// <param name="outFeatureData">Data object describing the feature if supported. 
        /// If feature is not supported this parameter will be null.</param>
        /// <returns>True if feature is supported. Otherwise, returns false.</returns>
        bool CheckFeatureDataD3D10XHardwareOptions([Runtime::InteropServices::Out] FeatureDataD3D10XHardwareOptions ^ %outFeatureData);

        /// <summary>
        /// Get the support of a given format on the installed video device.
        /// <para>(Also see DirectX SDK: ID3D11Device::CheckFormatSupport)</para>
        /// </summary>
        /// <param name="format">A Format enumeration that describes a format for which to check for support.</param>
        /// <returns>A FormatSupport enumeration values describing how the specified format is supported on the installed device. The values are ORed together.</returns>
        FormatSupport GetFormatSupport(Format format);

        /// <summary>
        /// Get the support of a given format on the installed video device.
        /// <para>(Also see DirectX SDK: ID3D11Device::CheckFormatSupport)</para>
        /// </summary>
        /// <param name="format">A Format enumeration that describes a format for which to check for support.</param>
        /// <param name="formatSupport">The type of support for the given format. 
        /// This value is undefined if the retun value is false.</param>
        /// <returns>True if successful; false otherwise.</returns>
        bool TryGetFormatSupport(Format format, [Runtime::InteropServices::Out] FormatSupport % formatSupport);

        /// <summary>
        /// Get the number of quality levels available during multisampling.
        /// <para>(Also see DirectX SDK: ID3D11Device::CheckMultisampleQualityLevels)</para>
        /// </summary>
        /// <param name="format">The texture format. See Format.</param>
        /// <param name="sampleCount">The number of samples during multisampling.</param>
        /// <returns>Number of quality levels supported by the adapter.</returns>
        UInt32 GetMultisampleQualityLevels(Format format, UInt32 sampleCount);

        /// <summary>
        /// Get the number of quality levels available during multisampling.
        /// <para>(Also see DirectX SDK: ID3D11Device::CheckMultisampleQualityLevels)</para>
        /// </summary>
        /// <param name="format">The texture format. See Format.</param>
        /// <param name="sampleCount">The number of samples during multisampling.</param>
        /// <param name="multisampleQualityLevels">An our parameter containing the number of quality levels supported by the adapter.
        /// This value is undefined if the retun value is false.</param>
        /// <returns>True if successful; false otherwise.</returns>
        bool TryGetMultisampleQualityLevels(Format format, UInt32 sampleCount, [Runtime::InteropServices::Out] UInt32 %multisampleQualityLevels);

        /// <summary>
        /// Create a blend-state object that encapsules blend state for the output-merger stage.
        /// <para>(Also see DirectX SDK: ID3D11Device::CreateBlendState)</para>
        /// </summary>
        /// <param name="description">A blend-state description (see <see cref="BlendDescription"/>)<seealso cref="BlendDescription"/>.</param>
        /// <returns>The blend-state object created (see <see cref="BlendState"/>)<seealso cref="BlendState"/>.</returns>
        BlendState^ CreateBlendState(BlendDescription^ description);

        /// <summary>
        /// Create a buffer (vertex buffer, index buffer, or shader-constant buffer).
        /// <para>(Also see DirectX SDK: ID3D11Device::CreateBuffer)</para>
        /// </summary>
        /// <param name="description">A buffer description (see <see cref="BufferDescription"/>)<seealso cref="BufferDescription"/>.</param>
        /// <param name="InitialData">Initialization data (see <see cref="SubresourceData"/>)<seealso cref="SubresourceData"/>; Cannot be emmpty or null if the usage flag is Immutable).</param>
        /// <returns>The buffer created (see <see cref="D3DBuffer"/>)<seealso cref="D3DBuffer"/>.</returns>
        D3DBuffer^ CreateBuffer(BufferDescription^ description, SubresourceData^ InitialData);

        /// <summary>
        /// Create a buffer (vertex buffer, index buffer, or shader-constant buffer).
        /// This method does not include initialization data. 
        /// Use CreateBuffer(BufferDescription, SubresourceData) if you need to include initialization data.
        /// <para>(Also see DirectX SDK: ID3D11Device::CreateBuffer)</para>
        /// </summary>
        /// <param name="description">A buffer description (see <see cref="BufferDescription"/>)<seealso cref="BufferDescription"/>.</param>
        /// <returns>The buffer created (see <see cref="D3DBuffer"/>)<seealso cref="D3DBuffer"/>.</returns>
        D3DBuffer^ CreateBuffer(BufferDescription^ description);

        /// <summary>
        /// TBD
        /// <para>(Also see DirectX SDK: ID3D11Device::CreateClassLinkage)</para>
        /// </summary>
        /// <returns>A class-linkage object (see <see cref="ClassLinkage"/>)<seealso cref="ClassLinkage"/>.</returns>
        ClassLinkage^ CreateClassLinkage();

        /// <summary>
        /// Create a compute shader.
        /// <para>(Also see DirectX SDK: ID3D11Device::CreateComputeShader)</para>
        /// </summary>
        /// <param name="shaderBytecode">A compiled shader.</param>
        /// <param name="classLinkage">A ClassLinkage, which represents  class linkage interface; the value can be NULL.</param>
        /// <returns>A ComputeShader object</returns>
        ComputeShader^ CreateComputeShader(IShaderBytecode^ shaderBytecode, ClassLinkage^ classLinkage);

        /// <summary>
        /// Create a compute shader.
        /// <para>(Also see DirectX SDK: ID3D11Device::CreateComputeShader)</para>
        /// </summary>
        /// <param name="shaderBytecode">A compiled shader.</param>
        /// <returns>A ComputeShader object</returns>
        ComputeShader^ CreateComputeShader(IShaderBytecode^ shaderBytecode);

        /// <summary>
        /// Create a counter object for measuring GPU performance.
        /// <para>(Also see DirectX SDK: ID3D11Device::CreateCounter)</para>
        /// </summary>
        /// <param name="description">A counter description (see <see cref="CounterDescription"/>)<seealso cref="CounterDescription"/>.</param>
        /// <returns>A counter (see <see cref="Counter"/>)<seealso cref="Counter"/>.</returns>
        Counter^ CreateCounter(CounterDescription^ description);

        /// <summary>
        /// Creates a deferred context for play back of command lists.
        /// <para>(Also see DirectX SDK: ID3D11Device::CreateDeferredContext)</para>
        /// </summary>
        /// <param name="contextFlags">Reserved for future use. Pass 0.</param>
        /// <returns>A DeviceContext object.</returns>
        DeviceContext^ CreateDeferredContext(UInt32 contextFlags);

        /// <summary>
        /// Create a depth-stencil state object that encapsulates depth-stencil test information for the output-merger stage.
        /// <para>(Also see DirectX SDK: ID3D11Device::CreateDepthStencilState)</para>
        /// </summary>
        /// <param name="description">A depth-stencil state description (see <see cref="DepthStencilDescription"/>)<seealso cref="DepthStencilDescription"/>.</param>
        /// <returns>A depth-stencil state object created (see <see cref="DepthStencilState"/>)<seealso cref="DepthStencilState"/>.</returns>
        DepthStencilState^ CreateDepthStencilState(DepthStencilDescription^ description);

        /// <summary>
        /// Create a depth-stencil view for accessing resource data.
        /// <para>(Also see DirectX SDK: ID3D11Device::CreateDepthStencilView)</para>
        /// </summary>
        /// <param name="resource">The resource that will serve as the depth-stencil surface. This resource must have been created with the DepthStencil flag.</param>
        /// <param name="description">A depth-stencil-view description (see <see cref="DepthStencilViewDescription"/>)<seealso cref="DepthStencilViewDescription"/>. Set this parameter to null to create a view that accesses mipmap level 0 of the entire resource (using the format the resource was created with).</param>
        /// <returns>A DepthStencilView object.</returns>
        DepthStencilView^ CreateDepthStencilView(D3DResource^ resource, DepthStencilViewDescription^ description);


        /// <summary>
        /// Create a domain shader.
        /// <para>(Also see DirectX SDK: ID3D11Device::CreateDomainShader)</para>
        /// </summary>
        /// <param name="shaderBytecode">A compiled shader.</param>        
        /// <param name="classLinkage">[optional]  A class linkage object (see <see cref="ClassLinkage"/>)<seealso cref="ClassLinkage"/>; the value can be null.</param>
        /// <returns>A DomainShader object.</returns>
        DomainShader^ CreateDomainShader(IShaderBytecode^ shaderBytecode, ClassLinkage^ classLinkage);

        /// <summary>
        /// Create a domain shader.
        /// <para>(Also see DirectX SDK: ID3D11Device::CreateDomainShader)</para>
        /// </summary>
        /// <param name="shaderBytecode">A compiled shader.</param>        
        /// <returns>A DomainShader object.</returns>
        DomainShader^ CreateDomainShader(IShaderBytecode^ shaderBytecode);

        /// <summary>
        /// Create a geometry shader.
        /// <para>(Also see DirectX SDK: ID3D11Device::CreateGeometryShader)</para>
        /// </summary>
        /// <param name="shaderBytecode">The compiled shader.</param>
        /// <param name="classLinkage">[optional]  A class linkage object (see <see cref="ClassLinkage"/>)<seealso cref="ClassLinkage"/>; the value can be NULL.</param>
        /// <returns>A GeometryShader object. </returns>
        GeometryShader^ CreateGeometryShader(IShaderBytecode^ shaderBytecode, ClassLinkage^ classLinkage);

        /// <summary>
        /// Create a geometry shader.
        /// <para>(Also see DirectX SDK: ID3D11Device::CreateGeometryShader)</para>
        /// </summary>
        /// <param name="shaderBytecode">The compiled shader.</param>
        /// <returns>A GeometryShader object. </returns>
        GeometryShader^ CreateGeometryShader(IShaderBytecode^ shaderBytecode);

        /// <summary>
        /// Create a geometry shader that can write to streaming output buffers.
        /// <para>(Also see DirectX SDK: ID3D11Device::CreateGeometryShaderWithStreamOutput)</para>
        /// </summary>
        /// <param name="shaderBytecode">The compiled shader.</param>
        /// <param name="streamOutputDeclarations">A SoDeclarationEntry collection. ( ranges from 0 to D3D11_SO_STREAM_COUNT * D3D11_SO_OUTPUT_COMPONENT_COUNT ).</param>
        /// <param name="bufferStrides">A collection of buffer strides; each stride is the size of an element for that buffer (ranges from 0 to D3D11_SO_BUFFER_SLOT_COUNT).</param>
        /// <param name="rasterizedStream">The index number of the stream to be sent to the rasterizer stage (ranges from 0 to D3D11_SO_STREAM_COUNT). Set to D3D11_SO_NO_RASTERIZED_STREAM if no stream is to be rasterized.</param>
        /// <param name="classLinkage">[optional]  A class linkage object (see <see cref="ClassLinkage"/>)<seealso cref="ClassLinkage"/>; the value can be NULL.</param>
        /// <returns>A GeometryShader interface, representing the geometry shader that was created. </returns>
        GeometryShader^ CreateGeometryShaderWithStreamOutput(IShaderBytecode^ shaderBytecode, ICollection<SoDeclarationEntry^>^ streamOutputDeclarations, ICollection<UInt32>^ bufferStrides, UInt32 rasterizedStream, ClassLinkage^ classLinkage);

        /// <summary>
        /// Create a hull shader.
        /// <para>(Also see DirectX SDK: ID3D11Device::CreateHullShader)</para>
        /// </summary>
        /// <param name="shaderBytecode">A compiled shader.</param>        
        /// <param name="classLinkage">[optional]  A class linkage object (see <see cref="ClassLinkage"/>)<seealso cref="ClassLinkage"/>; the value can be NULL.</param>
        /// <returns>A hull-shader object (see <see cref="HullShader"/>)<seealso cref="HullShader"/>.</returns>
        HullShader^ CreateHullShader(IShaderBytecode^ shaderBytecode, ClassLinkage^ classLinkage);

        /// <summary>
        /// Create a hull shader.
        /// <para>(Also see DirectX SDK: ID3D11Device::CreateHullShader)</para>
        /// </summary>
        /// <param name="shaderBytecode">A compiled shader.</param>        
        /// <returns>A hull-shader object (see <see cref="HullShader"/>)<seealso cref="HullShader"/>.</returns>
        HullShader^ CreateHullShader(IShaderBytecode^ shaderBytecode);

        /// <summary>
        /// Create an input-layout object to describe the input-buffer data for the input-assembler stage.
        /// <para>(Also see DirectX SDK: ID3D11Device::CreateInputLayout)</para>
        /// </summary>
        /// <param name="inputElementDescriptions">A collection of the input-assembler stage input data types; each type is described by an element description (see <see cref="InputElementDescription"/>)<seealso cref="InputElementDescription"/>.</param>
        /// <param name="shaderBytecodeWithInputSignature">The compiled shader.  The compiled shader code contains a input signature which is validated against the array of elements.</param>        
        /// <returns>The input-layout object created (see <see cref="InputLayout"/>)<seealso cref="InputLayout"/>.</returns>
        InputLayout^ CreateInputLayout(IEnumerable<InputElementDescription^>^ inputElementDescriptions, IntPtr shaderBytecodeWithInputSignature, UInt32 shaderBytecodeWithInputSignatureSize);

        /// <summary>
        /// Create an input-layout object to describe the input-buffer data for the input-assembler stage.
        /// <para>(Also see DirectX SDK: ID3D11Device::CreateInputLayout)</para>
        /// </summary>
        /// <param name="inputElementDescriptions">A collection of the input-assembler stage input data types; each type is described by an element description (see <see cref="InputElementDescription"/>)<seealso cref="InputElementDescription"/>.</param>
        /// <param name="shaderBytecodeWithInputSignature">The compiled shader.  The compiled shader code contains a input signature which is validated against the array of elements.</param>        
        /// <returns>The input-layout object created (see <see cref="InputLayout"/>)<seealso cref="InputLayout"/>.</returns>
        InputLayout^ CreateInputLayout(IEnumerable<InputElementDescription^>^ inputElementDescriptions, IShaderBytecode^ shaderBytecodeWithInputSignature);

        /// <summary>
        /// Create a pixel shader.
        /// <para>(Also see DirectX SDK: ID3D11Device::CreatePixelShader)</para>
        /// </summary>
        /// <param name="shaderBytecode">The compiled shader.</param>
        /// <param name="classLinkage">(optional) A class linkage interface (see <see cref="ClassLinkage"/>)<seealso cref="ClassLinkage"/>; the value can be NULL.</param>
        /// <returns>A PixelShader object.</returns>
        PixelShader^ CreatePixelShader(IShaderBytecode^ shaderBytecode, ClassLinkage^ classLinkage);

        /// <summary>
        /// Create a pixel shader.
        /// <para>(Also see DirectX SDK: ID3D11Device::CreatePixelShader)</para>
        /// </summary>
        /// <param name="shaderBytecode">The compiled shader.</param>
        /// <returns>A PixelShader object.</returns>
        PixelShader^ CreatePixelShader(IShaderBytecode^ shaderBytecode);

        /// <summary>
        /// Creates a predicate.
        /// <para>(Also see DirectX SDK: ID3D11Device::CreatePredicate)</para>
        /// </summary>
        /// <param name="predicateDescription">A query description where the type of query must be a SoOverflowPredicate or OcclusionPredicate (see <see cref="QueryDescription"/>)<seealso cref="QueryDescription"/>.</param>
        /// <returns>A predicate object (see <see cref="D3DPredicate"/>)<seealso cref="D3DPredicate"/>.</returns>
        D3DPredicate^ CreatePredicate(QueryDescription^ predicateDescription);

        /// <summary>
        /// This class encapsulates methods for querying information from the GPU.
        /// <para>(Also see DirectX SDK: ID3D11Device::CreateQuery)</para>
        /// </summary>
        /// <param name="description">A query description (see <see cref="QueryDescription"/>)<seealso cref="QueryDescription"/>.</param>
        /// <returns>Address of the query object created (see <see cref="D3DQuery"/>)<seealso cref="D3DQuery"/>.</returns>
        D3DQuery^ CreateQuery(QueryDescription^ description);

        /// <summary>
        /// Create a rasterizer state object that tells the rasterizer stage how to behave.
        /// <para>(Also see DirectX SDK: ID3D11Device::CreateRasterizerState)</para>
        /// </summary>
        /// <param name="description">A rasterizer state description (see <see cref="RasterizerDescription"/>)<seealso cref="RasterizerDescription"/>.</param>
        /// <returns>A rasterizer state object (see <see cref="RasterizerState"/>)<seealso cref="RasterizerState"/>.</returns>
        RasterizerState^ CreateRasterizerState(RasterizerDescription^ description);

        /// <summary>
        /// Create a render-target view for accessing resource data.
        /// <para>(Also see DirectX SDK: ID3D11Device::CreateRenderTargetView)</para>
        /// </summary>
        /// <param name="resource">A D3DResource which represents a render target. This resource must have been created with the RenderTarget flag.</param>
        /// <param name="description">A RenderTargetViewDescription which represents a render-target-view description. Set this parameter to NULL to create a view that accesses all of the subresources in mipmap level 0.</param>
        /// <returns>A RenderTargetView. </returns>
        RenderTargetView^ CreateRenderTargetView(D3DResource^ resource, RenderTargetViewDescription^ description);

        /// <summary>
        /// Create a sampler-state object that encapsulates sampling information for a texture.
        /// <para>(Also see DirectX SDK: ID3D11Device::CreateSamplerState)</para>
        /// </summary>
        /// <param name="description">A sampler state description (see <see cref="SamplerDescription"/>)<seealso cref="SamplerDescription"/>.</param>
        /// <returns>The sampler state object created (see <see cref="SamplerState"/>)<seealso cref="SamplerState"/>.</returns>
        SamplerState^ CreateSamplerState(SamplerDescription^ description);

        /// <summary>
        /// Create a shader-resource view for accessing data in a resource.
        /// <para>(Also see DirectX SDK: ID3D11Device::CreateShaderResourceView)</para>
        /// </summary>
        /// <param name="resource">The resource that will serve as input to a shader. This resource must have been created with the ShaderResource flag.</param>
        /// <param name="description">A shader-resource-view description (see <see cref="ShaderResourceViewDescription"/>)<seealso cref="ShaderResourceViewDescription"/>. Set this parameter to NULL to create a view that accesses the entire resource (using the format the resource was created with).</param>
        /// <returns>A ShaderResourceView. </returns>
        ShaderResourceView^ CreateShaderResourceView(D3DResource^ resource, ShaderResourceViewDescription^ description);

        /// <summary>
        /// Create an array of 1D textures.
        /// <para>(Also see DirectX SDK: ID3D11Device::CreateTexture1D)</para>
        /// </summary>
        /// <param name="description">A 1D texture description (see <see cref="Texture1dDescription"/>)<seealso cref="Texture1dDescription"/>. To create a typeless resource that can be interpreted at runtime into different, compatible formats, specify a typeless format in the texture description. To generate mipmap levels automatically, set the number of mipmap levels to 0.</param>
        /// <param name="initialData">Subresource descriptions (see <see cref="SubresourceData"/>)<seealso cref="SubresourceData"/>; one for each subresource. Applications may not specify NULL for initialData when creating IMMUTABLE resources (see Usage). If the resource is multisampled, pInitialData must be NULL because multisampled resources cannot be initialized with data when they are created.</param>
        /// <returns>The created texture (see <see cref="Texture1D"/>)<seealso cref="Texture1D"/>. </returns>
        Texture1D^ CreateTexture1D(Texture1dDescription^ description, SubresourceData^ initialData);

        /// <summary>
        /// Create an array of 2D textures.
        /// <para>(Also see DirectX SDK: ID3D11Device::CreateTexture2D)</para>
        /// </summary>
        /// <param name="description">A 2D texture description (see <see cref="Texture2dDescription"/>)<seealso cref="Texture2dDescription"/>. To create a typeless resource that can be interpreted at runtime into different, compatible formats, specify a typeless format in the texture description. To generate mipmap levels automatically, set the number of mipmap levels to 0.</param>
        /// <param name="initialData">Subresource descriptions (see <see cref="SubresourceData"/>)<seealso cref="SubresourceData"/>; one for each subresource. Applications may not specify NULL for pInitialData when creating IMMUTABLE resources (see Usage). If the resource is multisampled, pInitialData must be NULL because multisampled resources cannot be initialized with data when they are created.</param>
        /// <returns>The created texture (see <see cref="Texture2D"/>)<seealso cref="Texture2D"/>. </returns>
        Texture2D^ CreateTexture2D(Texture2dDescription^ description, SubresourceData^ initialData);

        /// <summary>
        /// Create a single 3D texture.
        /// <para>(Also see DirectX SDK: ID3D11Device::CreateTexture3D)</para>
        /// </summary>
        /// <param name="description">A 3D texture description (see <see cref="Texture3dDescription"/>)<seealso cref="Texture3dDescription"/>. To create a typeless resource that can be interpreted at runtime into different, compatible formats, specify a typeless format in the texture description. To generate mipmap levels automatically, set the number of mipmap levels to 0.</param>
        /// <param name="initialData">Subresource descriptions (see <see cref="SubresourceData"/>)<seealso cref="SubresourceData"/>; one for each subresource. Applications may not specify NULL for pInitialData when creating IMMUTABLE resources (see Usage). If the resource is multisampled, pInitialData must be NULL because multisampled resources cannot be initialized with data when they are created.</param>
        /// <returns>Address of the created texture (see <see cref="Texture3D"/>)<seealso cref="Texture3D"/>. </returns>
        Texture3D^ CreateTexture3D(Texture3dDescription^ description, SubresourceData^ initialData);

        /// <summary>
        /// Create an array of 1D textures.
        /// <para>(Also see DirectX SDK: ID3D11Device::CreateTexture1D)</para>
        /// </summary>
        /// <param name="description">A 1D texture description (see <see cref="Texture1dDescription"/>)<seealso cref="Texture1dDescription"/>. To create a typeless resource that can be interpreted at runtime into different, compatible formats, specify a typeless format in the texture description. To generate mipmap levels automatically, set the number of mipmap levels to 0.</param>
        /// <returns>Address of the created texture (see <see cref="Texture1D"/>)<seealso cref="Texture1D"/>. </returns>
        Texture1D^ CreateTexture1D(Texture1dDescription^ description);

        /// <summary>
        /// Create an array of 2D textures.
        /// <para>(Also see DirectX SDK: ID3D11Device::CreateTexture2D)</para>
        /// </summary>
        /// <param name="description">A 2D texture description (see <see cref="Texture2dDescription"/>)<seealso cref="Texture2dDescription"/>. To create a typeless resource that can be interpreted at runtime into different, compatible formats, specify a typeless format in the texture description. To generate mipmap levels automatically, set the number of mipmap levels to 0.</param>
        /// <returns>The created texture (see <see cref="Texture2D"/>)<seealso cref="Texture2D"/>. </returns>
        Texture2D^ CreateTexture2D(Texture2dDescription^ description);

        /// <summary>
        /// Create a single 3D texture.
        /// <para>(Also see DirectX SDK: ID3D11Device::CreateTexture3D)</para>
        /// </summary>
        /// <param name="description">A 3D texture description (see <see cref="Texture3dDescription"/>)<seealso cref="Texture3dDescription"/>. To create a typeless resource that can be interpreted at runtime into different, compatible formats, specify a typeless format in the texture description. To generate mipmap levels automatically, set the number of mipmap levels to 0.</param>
        /// <returns>Address of the created texture (see <see cref="Texture3D"/>)<seealso cref="Texture3D"/>. </returns>
        Texture3D^ CreateTexture3D(Texture3dDescription^ description);


        /// <summary>
        /// Create a view for accessing an unordered access resource.
        /// <para>(Also see DirectX SDK: ID3D11Device::CreateUnorderedAccessView)</para>
        /// </summary>
        /// <param name="resource">An D3DResource that represents a resources that will be serve as an input to a shader.</param>
        /// <param name="description">An UnorderedAccessViewDescription that represents a shader-resource-view description. Set this parameter to NULL to create a view that accesses the entire resource (using the format the resource was created with).</param>
        /// <returns>An UnorderedAccessView object that represents an unordered access view. </returns>
        UnorderedAccessView^ CreateUnorderedAccessView(D3DResource^ resource, UnorderedAccessViewDescription^ description);

        /// <summary>
        /// Create a vertex-shader object from a compiled shader.
        /// <para>(Also see DirectX SDK: ID3D11Device::CreateVertexShader)</para>
        /// </summary>
        /// <param name="shaderBytecode">The compiled shader.</param>
        /// <param name="classLinkage">[in, optional]  A class linkage interface (see <see cref="ClassLinkage"/>)<seealso cref="ClassLinkage"/>; the value can be NULL.</param>
        /// <returns>A VertexShader object. </returns>
        VertexShader^ CreateVertexShader(IShaderBytecode^ shaderBytecode, ClassLinkage^ classLinkage);

        /// <summary>
        /// Create a vertex-shader object from a compiled shader.
        /// <para>(Also see DirectX SDK: ID3D11Device::CreateVertexShader)</para>
        /// </summary>
        /// <param name="shaderBytecode">The compiled shader.</param>
        /// <returns>A VertexShader object. </returns>
        VertexShader^ CreateVertexShader(IShaderBytecode^ shaderBytecode);


        /// <summary>
        /// Get the flags used during the call to create the device.
        /// <para>(Also see DirectX SDK: ID3D11Device::GetCreationFlags)</para>
        /// </summary>
        property CreateDeviceFlag CreationFlags
        {
            CreateDeviceFlag get();
        };

        /// <summary>
        /// Get the reason why the device was removed.
        /// <para>(Also see DirectX SDK: ID3D11Device::GetDeviceRemovedReason)</para>
        /// </summary>
        property ErrorCode DeviceRemovedReason
        {
            ErrorCode get();
        }

        /// <summary>
        /// Gets or Sets the exception-mode flags.
        /// <para>(Also see DirectX SDK: ID3D11Device::GetExceptionMode, ID3D11Device::SetExceptionMode)</para>
        /// </summary>
        property RaiseFlag ExceptionMode
        {
            RaiseFlag get();
            void set(RaiseFlag value);
        }

        /// <summary>
        /// Gets an immediate context which can record command lists.
        /// <para>(Also see DirectX SDK: ID3D11Device::GetImmediateContext)</para>
        /// </summary>
        /// <returns>Upon completion of the method, the passed DeviceContext is initialized.</returns>
        DeviceContext^ GetImmediateContext();

        /// <summary>
        /// Gets an information queue object that can retrieve, store and filter debug messages.
        /// Can only be obtained if the device was created using CreateDeviceFlag.Debug flag
        /// </summary>
        /// <returns>An information queue object.</returns>
        InfoQueue ^ GetInfoQueue();

        /// <summary>
        /// Gets a switch-to-reference object that enables an application to switch between a hardware and software device.
        /// Can only be obtained if the device was created using CreateDeviceFlag.SwitchToRef flag
        /// </summary>
        SwitchToRef ^ GetSwitchToRef();

        /// <summary>
        /// Give a device access to a shared resource created on a different device..
        /// <para>(Also see DirectX SDK: ID3D11Device::OpenSharedResource)</para>
        /// </summary>
        /// <param name="resource">The resource handle.</param>
        /// <returns>The requested resource using the given type.</returns>
        generic <typename T>
        T OpenSharedResource(ResourceHandle^ resource);

        /// <summary>
        /// Gets the feature level of the hardware device.
        /// </summary>
        property FeatureLevel DeviceFeatureLevel
        {
            virtual FeatureLevel get() override;
        };

        /// <Summary>
        /// Gets the DeviceContext object which was created when this device
        /// was constructed
        /// </Summary>
        property DeviceContext^ Context
        {
            DeviceContext^ get();
        }

    public:
        /// <Summary>
        /// Create a new Direct3D 11 device given a window handle
        /// </Summary>
        D3DDevice(IntPtr windowHandle);

    internal:
        D3DDevice(ID3D11Device* pNativeID3D11Device) : d3dLibrary(0)
        {
            nativeUnknown.Set(pNativeID3D11Device);
        }

        property ID3D11Device* NativeID3D11Device
        {
            ID3D11Device* get()
            {
                return reinterpret_cast<ID3D11Device*>(nativeUnknown.Get());
            }
        }

    protected:
        virtual ~D3DDevice()
        {

            if (m_deviceContext != nullptr)
            {
                m_deviceContext = nullptr;
            }

            this->!D3DDevice();
        }
            
        !D3DDevice()
        {
            if (d3dLibrary != 0)
            {
                FreeLibrary(d3dLibrary);
                d3dLibrary = 0;
            }
        }
    private:
        HINSTANCE d3dLibrary;
        DeviceContext^ m_deviceContext;
    };
} } } }
