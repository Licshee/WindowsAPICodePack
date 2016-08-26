//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once
#include "D3D11PipelineStage.h"

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3D11 {

/// <summary>
/// OutputMerger pipeline stage. 
/// </summary>
public ref class OutputMergerPipelineStage : PipelineStage
{
public:

    /// <summary>
    /// Get the blend state of the output-merger stage.
    /// <para>(Also see DirectX SDK: ID3D11DeviceContext::OMGetBlendState)</para>
    /// </summary>
    /// <param name="outBlendFactor">Array of blend factors containing four entries; one for each RGBA component.</param>
    /// <param name="outSampleMask">A sample mask.</param>
    /// <returns>A blend-state object (see <see cref="BlendState"/>)<seealso cref="BlendState"/>.</returns>
    BlendState^ GetBlendState([Runtime::InteropServices::Out] array<Single>^ %outBlendFactor, [Runtime::InteropServices::Out] UInt32 %outSampleMask);

    /// <summary>
    /// Gets the depth-stencil state of the output-merger stage.
    /// <para>(Also see DirectX SDK: ID3D11DeviceContext::OMGetDepthStencilState)</para>
    /// </summary>
    /// <param name="outStencilRef">The stencil reference value used in the depth-stencil test.</param>
    /// <returns>A depth-stencil state object (see <see cref="DepthStencilState"/>)<seealso cref="DepthStencilState"/> to be filled with information from the device.</returns>
    DepthStencilState^ GetDepthStencilState([Runtime::InteropServices::Out] UInt32 %outStencilRef);

    /// <summary>
    /// Get pointers to the resources bound to the output-merger stage.
    /// <para>(Also see DirectX SDK: ID3D11DeviceContext::OMGetRenderTargets)</para>
    /// </summary>
    /// <param name="numViews">Number of render targets to retrieve.</param>
    /// <returns>A collection of ID3D11RenderTargetViews which represent render target views.</returns>
    Collection<RenderTargetView^>^ GetRenderTargets(UInt32 numViews);

    /// <summary>
    /// Get the resources bound to the output-merger stage.
    /// <para>(Also see DirectX SDK: ID3D11DeviceContext::OMGetRenderTargets)</para>
    /// </summary>
    /// <param name="numViews">Number of render targets to retrieve.</param>
    /// <param name="outDepthStencilView">Retrieves a depth-stencil view.</param>
    /// <returns>A collection of ID3D11RenderTargetViews which represent render target views.</returns>
    Collection<RenderTargetView^>^ GetRenderTargets(UInt32 numViews, [Runtime::InteropServices::Out] DepthStencilView^ %outDepthStencilView);

    /// <summary>
    /// Get the depth stencil view bound to the output-merger stage.
    /// <para>(Also see DirectX SDK: ID3D11DeviceContext::OMGetRenderTargets)</para>
    /// </summary>
    /// <returns>The depth-stencil view bound to the output-merger stage.</returns>
    DepthStencilView^ GetDepthStencilView();

    /// <summary>
    /// Get the resources bound to the output-merger stage.
    /// <para>(Also see DirectX SDK: ID3D11DeviceContext::OMGetRenderTargetsAndUnorderedAccessViews)</para>
    /// </summary>
    /// <param name="numViews">The number of render-target views to retrieve.</param>
    /// <param name="outDepthStencilView">Retrieves the depth-stencil view. </param>
    /// <param name="UAVstartSlot">Start Unordered Access View Slot.</param>
    /// <param name="numUAVs">Number of Unordered Access Views</param>
    /// <param name="outUnorderedAccessViews">A collection of Unordered Access Views.</param>
    /// <returns>A collection of render-target views. </returns>
    Collection<RenderTargetView^>^ GetRenderTargetsAndUnorderedAccessViews(UInt32 numViews, [Runtime::InteropServices::Out] DepthStencilView^ %outDepthStencilView, UInt32 UAVstartSlot, UInt32 numUAVs, [Runtime::InteropServices::Out] Collection<UnorderedAccessView^>^ %outUnorderedAccessViews);

    /// <summary>
    /// Get the resources bound to the output-merger stage.
    /// <para>(Also see DirectX SDK: ID3D11DeviceContext::OMGetRenderTargetsAndUnorderedAccessViews)</para>
    /// </summary>
    /// <param name="UAVstartSlot">Start Unordered Access View Slot.</param>
    /// <param name="numUAVs">Number of Unordered Access Views</param>
    /// <returns>A collection of Unordered Access Views.</returns>
    Collection<UnorderedAccessView^>^ GetUnorderedAccessViews(UInt32 UAVstartSlot, UInt32 numUAVs);

    /// <summary>
    /// Set the blend state of the output-merger stage.
    /// <para>(Also see DirectX SDK: ID3D11DeviceContext::OMSetBlendState)</para>
    /// </summary>
    /// <param name="blendState">A blend-state interface (see <see cref="BlendState"/>)<seealso cref="BlendState"/>. Passing in NULL implies a default blend state. See remarks for further details.</param>
    /// <param name="blendFactor">Four components array of blend factors, one for each RGBA component. This requires a blend state object that specifies the BlendFactor option.</param>
    /// <param name="sampleMask">32-bit sample coverage. The default value is 0xffffffff.</param>
    void SetBlendState(BlendState^ blendState, array<Single>^ blendFactor, UInt32 sampleMask);

    /// <summary>
    /// Sets the depth-stencil state of the output-merger stage.
    /// <para>(Also see DirectX SDK: ID3D11DeviceContext::OMSetDepthStencilState)</para>
    /// </summary>
    /// <param name="depthStencilState">A depth-stencil state interface (see <see cref="DepthStencilState"/>)<seealso cref="DepthStencilState"/> to bind to the device. Set this to NULL to use the default state listed in DepthStencilDescription.</param>
    /// <param name="stencilRef">Reference value to perform against when doing a depth-stencil test.</param>
    void SetDepthStencilState(DepthStencilState^ depthStencilState, UInt32 stencilRef);

    /// <summary>
    /// Bind one or more render targets atomically and the depth-stencil buffer to the output-merger stage.
    /// <para>(Also see DirectX SDK: ID3D11DeviceContext::OMSetRenderTargets)</para>
    /// </summary>
    /// <param name="renderTargetViews">A collection of render targets (see <see cref="RenderTargetView"/>)<seealso cref="RenderTargetView"/> to bind to the device (ranges between 0 and D3D11_SIMULTANEOUS_RENDER_TARGET_COUNT). 
    /// If this parameter is null, no render targets are bound.</param>
    /// <param name="depthStencilView">A depth-stencil view (see <see cref="DepthStencilView"/>)<seealso cref="DepthStencilView"/> to bind to the device. 
    /// If this parameter is null, the depth-stencil state is not bound.</param>
    void SetRenderTargets(IEnumerable<RenderTargetView^>^ renderTargetViews, DepthStencilView^ depthStencilView);

    /// <summary>
    /// Bind resources to the output-merger stage.
    /// <para>(Also see DirectX SDK: ID3D11DeviceContext::OMSetRenderTargetsAndUnorderedAccessViews)</para>
    /// </summary>
    /// <param name="renderTargetViews">A collection of ID3D11RenderTargetViews, which represent render-target views. Specify NULL to set none.</param>
    /// <param name="depthStencilView">A DepthStencilView, which represents a depth-stencil view. Specify NULL to set none.</param>
    /// <param name="UAVstartSlot">Index into a zero-based array to begin setting unordered access views (ranges from 0 to D3D11_PS_CS_UAV_REGISTER_COUNT - 1).</param>
    /// <param name="unorderedAccessViews">A collection of ID3D11UnorderedAccessViews, which represent unordered access views.</param>
    /// <param name="UAVInitialCounts">An array The number of unordered access views to set.</param>
    void SetRenderTargetsAndUnorderedAccessViews(IEnumerable<RenderTargetView^>^ renderTargetViews, DepthStencilView^ depthStencilView, UInt32 UAVstartSlot, IEnumerable<UnorderedAccessView^>^ unorderedAccessViews, array<UInt32>^ UAVInitialCounts);


protected:
    OutputMergerPipelineStage() {}
internal:
    OutputMergerPipelineStage(DeviceContext^ parent) : PipelineStage(parent)
    {
    }
};
} } } }
