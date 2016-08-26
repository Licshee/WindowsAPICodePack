//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once
#include "DirectUnknown.h"
using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D11;

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3D11 {

using namespace System;
ref class D3DDevice;

    /// <summary>
    /// A device-child interface accesses data used by a device.
    /// <para>(Also see DirectX SDK: ID3D11DeviceChild)</para>
    /// </summary>
    public ref class DeviceChild :
        public Microsoft::WindowsAPICodePack::DirectX::Direct3DCommon::DirectUnknown
    {
    public: 
        /// <summary>
        /// Get the device that created this object.
        /// <para>(Also see DirectX SDK: ID3D11DeviceChild::GetDevice)</para>
        /// </summary>
        property D3DDevice^ ParentDevice
        {
            D3DDevice^ get();
        }

        ///// <summary>
        ///// Get application-defined data from a device child.
        ///// <para>(Also see DirectX SDK: ID3D11DeviceChild::GetPrivateData)</para>
        ///// </summary>
        ///// <param name="guid">Guid associated with the data.</param>
        ///// <param name="outDataSize">Size of the data.</param>
        ///// <param name="outData">Pointer to the data stored with the device child. If pData is NULL, DataSize must also be 0, and any data previously associated with the guid will be destroyed.</param>
        //void GetPrivateData(Guid guid, [Runtime::InteropServices::Out, Runtime::InteropServices::In] UInt32 %outDataSize, [Runtime::InteropServices::Out] IntPtr %outData);

        ///// <summary>
        ///// Set application-defined data to a device child and associate that data with an application-defined guid.
        ///// <para>(Also see DirectX SDK: ID3D11DeviceChild::SetPrivateData)</para>
        ///// </summary>
        ///// <param name="guid">Guid associated with the data.</param>
        ///// <param name="DataSize">Size of the data.</param>
        ///// <param name="Data">Pointer to the data to be stored with this device child. If pData is NULL, DataSize must also be 0, and any data previously associated with the specified guid will be destroyed.</param>
        //void SetPrivateData(Guid guid, UInt32 DataSize, IntPtr Data);

        ///// <summary>
        ///// Associate an IUnknown-derived interface with this device child and associate that interface with an application-defined guid.
        ///// <para>(Also see DirectX SDK: ID3D11DeviceChild::SetPrivateDataInterface)</para>
        ///// </summary>
        ///// <param name="guid">Guid associated with the object.</param>
        ///// <param name="Data">An IUnknown-derived interface to be associated with the device child.</param>
        //void SetPrivateDataInterface(Guid guid, IntPtr Data);


    protected:
        DeviceChild()
        {
        }
    internal:

        DeviceChild(ID3D11DeviceChild* pNativeID3D11DeviceChild)
        {
            nativeUnknown.Set(pNativeID3D11DeviceChild);
        }

        property ID3D11DeviceChild* NativeID3D11DeviceChild
        {
            ID3D11DeviceChild* get()
            {
                return reinterpret_cast<ID3D11DeviceChild*>(nativeUnknown.Get());
            }
        }
    };
} } } }
