// Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once
#include "DirectUnknown.h"

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace DXGI {
ref class SwapChain;
ref class DXGIDevice;
}}}}

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3DCommon {

/// <summary>
/// Base class for all Direct3D and DXGI classes supporting an IUnknown 
/// </summary>
public ref class D3DDeviceBase abstract: public DirectUnknown
{
public:
    /// <summary>
    /// Gets the current feature level of the device.
    /// </summary>
    property FeatureLevel DeviceFeatureLevel
    {
        virtual FeatureLevel get() = 0;
    };

    /// <Summary>
    /// The SwapChain for this Device
    /// </Summary>
    property SwapChain^ DeviceSwapChain
    {
    public:
        SwapChain^ get()
        {
            return m_swapChain;
        }
    }

public:
    virtual DXGIDevice^ GetDXGIDevice();

internal:
    D3DDeviceBase(void) {}
    property IUnknown* NativeDevice
    {
        virtual IUnknown* get()
        {
            return nativeUnknown.Get();
        }
    };

protected:
    SwapChain^ m_swapChain;
};

}}}}
