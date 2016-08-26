//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once
#include "DXGIDevice.h"

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace DXGI {

using namespace System;

    /// <summary>
    /// A D3DDevice1 class implements a derived class for DXGI objects that produce image data.
    /// <para>(Also see DirectX SDK: IDXGIDevice1)</para>
    /// </summary>
    public ref class DXGIDevice1 :
        public Microsoft::WindowsAPICodePack::DirectX::DXGI::DXGIDevice
    {
    public: 
        /// <summary>
        /// Gets or sets the number of frames that the system is allowed to queue for rendering.
        /// <para>(Also see DirectX SDK: IDXGIDevice1::GetMaximumFrameLatency, IDXGIDevice1::SetMaximumFrameLatency)</para>
        /// </summary>
        property UInt32 MaximumFrameLatency
        {
            UInt32 get();
            void set (UInt32 value);
        }

    protected:
        DXGIDevice1()
        {
        }
    internal:

        DXGIDevice1(IDXGIDevice1* pNativeIDXGIDevice1)
        {
            nativeUnknown.Set(pNativeIDXGIDevice1);
        }

        property IDXGIDevice1* NativeIDXGIDevice1
        {
            IDXGIDevice1* get()
            {
                return reinterpret_cast<IDXGIDevice1*>(nativeUnknown.Get());
            }
        }
    };
} } } }
