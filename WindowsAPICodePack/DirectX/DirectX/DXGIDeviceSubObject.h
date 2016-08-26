//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once
#include "DXGIObject.h"

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3D11 {
ref class D3DDevice;
}}}}

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3D10 {
ref class D3DDevice;
ref class D3DDevice1;
}}}}


namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace DXGI {

ref class DXGIDevice;
using namespace System;

    /// <summary>
    /// Inherited from objects that are tied to the device so that they can retrieve it.
    /// <para>(Also see DirectX SDK: IDXGIDeviceSubObject)</para>
    /// </summary>
    public ref class DeviceSubObject :
        public DXGIObject
    {
    public: 

        /// <summary>
        /// Retrieves the device as Direct3D 11 device.
        /// <para>(Also see DirectX SDK: IDXGIDeviceSubObject::GetDevice)</para>
        /// </summary>
        /// <returns>A Direct3D 11 Device.</returns>
        Microsoft::WindowsAPICodePack::DirectX::Direct3D11::D3DDevice^ GetDirect3D11Device();

        /// <summary>
        /// Retrieves the device as DXGI device.
        /// <para>(Also see DirectX SDK: IDXGIDeviceSubObject::GetDevice)</para>
        /// </summary>
        /// <returns>A DXGI Device.</returns>
        Microsoft::WindowsAPICodePack::DirectX::DXGI::DXGIDevice^ GetDXGIDevice();

    protected:
        DeviceSubObject()
        {
        }
    internal:

        DeviceSubObject(IDXGIDeviceSubObject* pNativeIDXGIDeviceSubObject)
        {
            nativeUnknown.Set(pNativeIDXGIDeviceSubObject);
        }

        property IDXGIDeviceSubObject* NativeIDXGIDeviceSubObject
        {
            IDXGIDeviceSubObject* get()
            {
                return reinterpret_cast<IDXGIDeviceSubObject*>(nativeUnknown.Get());
            }
        }
    };
} } } }
