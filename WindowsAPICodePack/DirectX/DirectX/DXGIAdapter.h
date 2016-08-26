//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once
#include "DXGIObject.h"
#include "CachedCollection.h"

using namespace System;
using namespace System::Collections::ObjectModel;


namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace DXGI {
ref class Output;

    /// <summary>
    /// The  Adapter interface represents a display sub-system (including one or more GPU's, DACs and video memory).
    /// <para>(Also see DirectX SDK: IDXGIAdapter)</para>
    /// </summary>
    public ref class Adapter :
        public DXGIObject
    {
    public: 
        /// <summary>
        /// Checks to see if a device interface for a graphics component is supported by the system.
        /// <para>(Also see DirectX SDK: IDXGIAdapter::CheckInterfaceSupport)</para>
        /// </summary>
        /// <param name="deviceType"> The device support checked.</param>
        /// <param name="UMDVersionMajor">An out parameter containing the user mode driver version of InterfaceName high 32 bit value. Returns 0 if interface is not supported.</param>
        /// <param name="UMDVersionMinor">An out parameter containing the user mode driver version of InterfaceName low 32 bit value. Returns 0 if interface is not supported.</param>
        /// <returns>True if the device is supported by the system; false otherwise</returns>
        bool CheckDeviceSupport(DeviceType deviceType, [Runtime::InteropServices::Out] Int32 %UMDVersionMajor, [Runtime::InteropServices::Out] Int32 %UMDVersionMinor );

        /// <summary>
        /// Checks to see if a device interface for a graphics component is supported by the system.
        /// <para>(Also see DirectX SDK: IDXGIAdapter::CheckInterfaceSupport)</para>
        /// </summary>
        /// <param name="deviceType"> The device support checked.</param>
        /// <returns>True if the device is supported by the system; false otherwise</returns>
        bool CheckDeviceSupport(DeviceType deviceType);


        /// <summary>
        /// Enumerate adapter (video card) outputs.
        /// <para>(Also see DirectX SDK: IDXGIAdapter::EnumOutputs)</para>
        /// </summary>
        property CachedCollection<Output^>^ OutputsCache
        {
            CachedCollection<Output^>^ get();              
        }


        /// <summary>
        /// Gets a DXGI 1.0 description of an adapter (or video card).
        /// <para>(Also see DirectX SDK: IDXGIAdapter::GetDesc)</para>
        /// </summary>
        property AdapterDescription^ Description
        {
            AdapterDescription^ get();
        }

    protected:

        Adapter()
        { 
        }
    internal:

        Adapter(IDXGIAdapter* pNativeIDXGIAdapter)
        {
            nativeUnknown.Set(pNativeIDXGIAdapter);
        }

        property IDXGIAdapter* NativeIDXGIAdapter
        {
            IDXGIAdapter* get()
            {
                return reinterpret_cast<IDXGIAdapter*>(nativeUnknown.Get());
            }
        }

    private:
        AdapterDescription^ m_description;
        CachedCollection<Output^>^ outputsCache;
    };
} } } }
