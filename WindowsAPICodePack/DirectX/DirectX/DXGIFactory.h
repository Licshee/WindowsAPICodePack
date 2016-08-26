//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once
#include "DXGIObject.h"
#include "CachedCollection.h"

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3DCommon {
ref class D3DDeviceBase;
}}}}

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace DXGI {

using namespace System;
using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3DCommon;

ref class Adapter;
ref class SwapChain;

    /// <summary>
    /// An Factory interface implements methods for generating DXGI objects (which handle fullscreen transitions).
    /// <para>(Also see DirectX SDK: IDXGIFactory)</para>
    /// </summary>
    public ref class DXGIFactory :
        public DXGIObject
    {
    public: 

        /// <summary>
        /// Creates a swap chain.
        /// <para>(Also see DirectX SDK: IDXGIFactory::CreateSwapChain)</para>
        /// </summary>
        /// <param name="Device">The device that will write 2D images to the swap chain.</param>
        /// <param name="Description">The swap-chain description (see <see cref="SwapChainDescription"/>)<seealso cref="SwapChainDescription"/>. This parameter cannot be NULL.</param>
        /// <return>The swap chain created (see <see cref="SwapChain"/>)<seealso cref="SwapChain"/>.</return>
        SwapChain^ CreateSwapChain(D3DDeviceBase^ Device, SwapChainDescription^ Description);

        /// <summary>
        /// Enumerates the adapters (video cards).
        /// <para>(Also see DirectX SDK: IDXGIFactory::EnumAdapters)</para>
        /// </summary>
        property CachedCollection<Adapter^>^ AdaptersCache
        {
            CachedCollection<Adapter^>^ get();    
        }

        /// <summary>
        /// Get the window through which the user controls the transition to and from fullscreen.
        /// <para>(Also see DirectX SDK: IDXGIFactory::GetWindowAssociation)</para>
        /// </summary>
        /// <return>A window handle.</return>
        IntPtr GetWindowAssociation();

        /// <summary>
        /// Allows DXGI to monitor an application's message queue for the alt-enter key sequence (which causes the application to switch from windowed to fullscreen or vice versa).
        /// <para>(Also see DirectX SDK: IDXGIFactory::MakeWindowAssociation)</para>
        /// </summary>
        /// <param name="WindowHandle">The handle of the window that is to be monitored. This parameter can be NULL; but only if the flags are also 0.</param>
        /// <param name="Flags">One or more of the MakeWindowAssociation flags.</param>
        void MakeWindowAssociation(IntPtr WindowHandle, MakeWindowAssociationFlags Flags);


    public:
        DXGIFactory();

    internal:
        DXGIFactory(IDXGIFactory* pNativeIDXGIFactory)
        {
            nativeUnknown.Set(pNativeIDXGIFactory);
        }

        property IDXGIFactory* NativeIDXGIFactory
        {
            IDXGIFactory* get()
            {
                return reinterpret_cast<IDXGIFactory*>(nativeUnknown.Get());
            }
        }
    protected:
        virtual ~DXGIFactory()
        {
            if (adaptersCache != nullptr)
            {
                adaptersCache = nullptr;
            }
            this->!DXGIFactory();
        }
            
        !DXGIFactory()
        {
            if (dxgiLibrary != 0)
                FreeLibrary(dxgiLibrary);
        }

    private:
        HINSTANCE dxgiLibrary;
        CachedCollection<Adapter^>^ adaptersCache;
    };
} } } }
