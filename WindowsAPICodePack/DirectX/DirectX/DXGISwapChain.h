//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once
#include "DXGIDeviceSubObject.h"

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace DXGI {

using namespace System;
ref class Output;

    /// <summary>
    /// An SwapChain interface implements one or more surfaces for storing rendered data before presenting it to an output.
    /// <para>(Also see DirectX SDK: IDXGISwapChain)</para>
    /// </summary>
    public ref class SwapChain :
        public Microsoft::WindowsAPICodePack::DirectX::DXGI::DeviceSubObject
    {
    public: 
        /// <summary>
        /// Access one of the swap-chain back buffers.
        /// <para>(Also see DirectX SDK: IDXGISwapChain::GetBuffer)</para>
        /// </summary>
        /// <param name="bufferIndex">A zero-based buffer index. 
        /// If the swap effect is not Sequential, this method only has access to the first buffer; for this case, set the index to zero.
        /// </param>
        /// <returns>The back-buffer object.</returns>
        generic <typename T> 
        T GetBuffer(UInt32 bufferIndex);

        /// <summary>
        /// Get the output (the display monitor) that contains the majority of the client area of the target window.
        /// <para>(Also see DirectX SDK: IDXGISwapChain::GetContainingOutput)</para>
        /// </summary>
        property Output^ ClientOutput
        {
            Output^ get();
        }

        /// <summary>
        /// Get a description of the swap chain.
        /// <para>(Also see DirectX SDK: IDXGISwapChain::GetDesc)</para>
        /// </summary>
        property SwapChainDescription^ Description
        {
            SwapChainDescription^ get();
        }

        /// <summary>
        /// Get performance statistics about the last render frame.
        /// <para>(Also see DirectX SDK: IDXGISwapChain::GetFrameStatistics)</para>
        /// </summary>
        property FrameStatistics^ LastRenderFrameStatistics
        {
            FrameStatistics^ get();
        }

        /// <summary>
        /// Get the state associated with full-screen mode.
        /// <para>(Also see DirectX SDK: IDXGISwapChain::GetFullscreenState)</para>
        /// </summary>
        /// <param name="outTarget">The output target (see <see cref="Output"/>)<seealso cref="Output"/> when the mode is full screen; otherwise null.</param>
        /// <returns>A boolean whose value is either:TRUE if the swap chain is in full-screen modeFALSE if the swap chain is in windowed mode</returns>
        bool GetFullScreenState([Runtime::InteropServices::Out] Output^ %outTarget);

        /// <summary>
        /// Checks if this swap chain is in full screen.
        /// <para>(Also see DirectX SDK: IDXGISwapChain::GetFullscreenState)</para>
        /// </summary>
        property bool IsFullScreen
        {
            bool get();
        }

        /// <summary>
        /// Get the number of times SwapChain.Present has been called.
        /// <para>(Also see DirectX SDK: IDXGISwapChain::GetLastPresentCount)</para>
        /// </summary>
        property UInt32 LastPresentCount
        {
            UInt32 get();
        }

        /// <summary>
        /// Present a rendered image to the user.
        /// This method can throw exceptions if the Swap Chain is unable to present. 
        /// TryPresent() method should be used instead when exceptions can impact performance.
        /// <para>(Also see DirectX SDK: IDXGISwapChain::Present)</para>
        /// </summary>
        /// <param name="syncInterval">If the update region straddles more than one output (each represented by Output), the synchronization will be performed to the output that contains the largest subrectangle of the target window's client area.</param>
        /// <param name="flags">An integer value that contains swap-chain presentation options (see <see cref="Present"/>)<seealso cref="Present"/>.</param>
        void Present(UInt32 syncInterval, PresentFlag flags);

        /// <summary>
        /// Try to present a rendered image to the user.
        /// No exceptions will be thrown by this method.
        /// <para>(Also see DirectX SDK: IDXGISwapChain::Present)</para>
        /// </summary>
        /// <param name="SyncInterval">If the update region straddles more than one output (each represented by Output), the synchronization will be performed to the output that contains the largest subrectangle of the target window's client area.</param>
        /// <param name="Flags">An integer value that contains swap-chain presentation options (see <see cref="Present"/>)<seealso cref="Present"/>.</param>
        /// <param name="error">An error code indicating Present error if unsuccessful.</param>
        /// <returns>False if unsuccessful; True otherwise.</returns>
        bool TryPresent(UInt32 SyncInterval, PresentFlag Flags, [Runtime::InteropServices::Out] ErrorCode % error);

        /// <summary>
        /// Change the swap chain's back buffer size, format, and number of buffers. This should be called when the application window is resized.
        /// <para>(Also see DirectX SDK: IDXGISwapChain::ResizeBuffers)</para>
        /// </summary>
        /// <param name="BufferCount">The number of buffers in the swap chain (including all back and front buffers). This can be different from the number of buffers the swap chain was created with.</param>
        /// <param name="Width">New width of the back buffer. If 0 is specified the width of the client area of the target window will be used.</param>
        /// <param name="Height">New height of the back buffer. If 0 is specified the height of the client area of the target window will be used.</param>
        /// <param name="NewFormat">The new format of the back buffer.</param>
        /// <param name="SwapChainFlags">Flags that indicate how the swap chain will function.</param>
        void ResizeBuffers(UInt32 BufferCount, UInt32 Width, UInt32 Height, Format NewFormat, SwapChainFlag SwapChainFlags);

        /// <summary>
        /// Resize the output target.
        /// <para>(Also see DirectX SDK: IDXGISwapChain::ResizeTarget)</para>
        /// </summary>
        /// <param name="NewTargetParameters">The mode description (see <see cref="ModeDescription"/>)<seealso cref="ModeDescription"/>, which specifies the new width, height, format and refresh rate of the target. 
        /// If the format is UNKNOWN, the existing format will be used. Using UNKNOWN is only recommended when the swap chain is in full-screen mode as this method is not thread safe.</param>
        void ResizeTarget(ModeDescription^ NewTargetParameters);

        /// <summary>
        /// Set the display mode to windowed or full-screen.
        /// <para>(Also see DirectX SDK: IDXGISwapChain::SetFullscreenState)</para>
        /// </summary>
        /// <param name="Fullscreen">Use TRUE for full-screen, FALSE for windowed.</param>
        /// <param name="Target">If the current display mode is full-screen, this parameter must be the output target (see <see cref="Output"/>)<seealso cref="Output"/> that contains the swap chain; 
        /// otherwise, this parameter is ignored. If you set this parameter to NULL, DXGI will choose the output based on the swap-chain's device and the output window's placement.</param>
        void SetFullscreenState(Boolean Fullscreen, Output^ Target);


    protected:
        SwapChain()
        {
        }
    internal:

        SwapChain(IDXGISwapChain* pNativeIDXGISwapChain)
        {
            nativeUnknown.Set(pNativeIDXGISwapChain);
        }

        property IDXGISwapChain* NativeIDXGISwapChain
        {
            IDXGISwapChain* get()
            {
                return reinterpret_cast<IDXGISwapChain*>(nativeUnknown.Get());
            }
        }
    };
} } } }
