//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once
#include "DXGIObject.h"

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace DXGI {

using namespace System;
ref class Surface;
ref class Adapter;

    /// <summary>
    /// An Device interface implements a derived class for DXGI objects that produce image data.
    /// <para>(Also see DirectX SDK: IDXGIDevice)</para>
    /// </summary>
    public ref class DXGIDevice :
        public DXGIObject
    {
    public: 

        /// <summary>
        /// Returns the adapter for the specified device.
        /// <para>(Also see DirectX SDK: IDXGIDevice::GetAdapter)</para>
        /// </summary>
        property Adapter^ DeviceAdapter
        {
            Adapter^ get();
        }

        /// <summary>
        /// Sets or Gets the GPU thread priority.
        /// <para>(Also see DirectX SDK: IDXGIDevice::GetGPUThreadPriority and IDXGIDevice::SetGPUThreadPriority)</para>
        /// </summary>
        property Int32 GPUThreadPriority
        {
            Int32 get();
            void set(Int32 value);
        }

        ///// <summary>
        ///// Gets the residency status of an array of resources.
        ///// <para>(Also see DirectX SDK: IDXGIDevice::QueryResourceResidency)</para>
        ///// </summary>
        ///// <param name="Resources">An array of Resource interfaces.</param>
        ///// <param name="NumResources">The number of resources in the ppResources argument array and pResidencyStatus argument array.</param>
        ///// <returns>An array of Residency flags. Each element describes the residency status for corresponding element in
        ///// the ppResources argument array.</returns>
        //Residency QueryResourceResidency(IntPtr Resources, UInt32 NumResources);

    protected:
        DXGIDevice()
        {
        }
    internal:

        DXGIDevice(IDXGIDevice* pNativeIDXGIDevice)
        {
            nativeUnknown.Set(pNativeIDXGIDevice);
        }

        property IDXGIDevice* NativeIDXGIDevice
        {
            IDXGIDevice* get()
            {
                return reinterpret_cast<IDXGIDevice*>(nativeUnknown.Get());
            }
        }
        
    };
} } } }
