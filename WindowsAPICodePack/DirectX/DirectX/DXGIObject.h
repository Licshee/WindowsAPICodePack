//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once
#include "DirectUnknown.h"

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace DXGI {

using namespace System;
using namespace Microsoft::WindowsAPICodePack::DirectX::DXGI;

    /// <summary>
    /// An DXGIObject interface is a base interface for all DXGI objects; 
    /// <para>(Also see DirectX SDK: IDXGIObject)</para>
    /// </summary>
    public ref class DXGIObject :
        public Microsoft::WindowsAPICodePack::DirectX::Direct3DCommon::DirectUnknown
    {
    public: 

        /// <summary>
        /// Gets the parent of the object.
        /// <para>(Also see DirectX SDK: IDXGIObject::GetParent)</para>
        /// </summary>
        /// <returns>The parent object.</returns>
        generic <typename T>
            where T : DXGIObject
        T GetParent();
/*
        /// <summary>
        /// Get the object's data.
        /// <para>(Also see DirectX SDK: IDXGIObject::GetPrivateData)</para>
        /// </summary>
        /// <param name="Name">A GUID identifying the data.</param>
        /// <param name="outDataSize">The size of the data.</param>
        /// <param name="outData">Pointer to the data.</param>
        void GetPrivateData(Guid Name, [Runtime::InteropServices::Out, Runtime::InteropServices::In] UInt32 %outDataSize, [Runtime::InteropServices::Out] IntPtr %outData);

        /// <summary>
        /// Sets an IUnknown interface as private data; this associates application-defined data with the object.
        /// <para>(Also see DirectX SDK: IDXGIObject::SetPrivateData)</para>
        /// </summary>
        /// <param name="Name">A GUID identifying the data. This GUID will also be used when getting the data.</param>
        /// <param name="DataSize">The size of the object's data.</param>
        /// <param name="Data">Pointer to the object's data.</param>
        void SetPrivateData(Guid Name, UInt32 DataSize, IntPtr Data);

        /// <summary>
        /// Set an interface in the object's private data.
        /// <para>(Also see DirectX SDK: IDXGIObject::SetPrivateDataInterface)</para>
        /// </summary>
        /// <param name="Name">A GUID identifying the object.</param>
        /// <param name="Unknown">The interface to set.</param>
        void SetPrivateDataInterface(Guid Name, IntPtr Unknown);
*/

    protected:
        DXGIObject()
        {
        }
    internal:

        DXGIObject(IDXGIObject* pNativeIDXGIObject)
        {
            nativeUnknown.Set(pNativeIDXGIObject);
        }

        property IDXGIObject* NativeIDXGIObject
        {
            IDXGIObject* get()
            {
                return reinterpret_cast<IDXGIObject*>(nativeUnknown.Get());
            }
        }
    };
} } } }
