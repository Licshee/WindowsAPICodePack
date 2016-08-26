//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once
#include "D3D11DeviceChild.h"

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3D11 {

using namespace System;

    /// <summary>
    /// This class encapsulates methods for retrieving data from the GPU asynchronously.
    /// <para>(Also see DirectX SDK: ID3D11Asynchronous)</para>
    /// </summary>
    public ref class Asynchronous :
        public Microsoft::WindowsAPICodePack::DirectX::Direct3D11::DeviceChild
    {
    public: 
        /// <summary>
        /// Get the size of the data (in bytes) that is output when calling DeviceContext.GetData.
        /// <para>(Also see DirectX SDK: ID3D11Asynchronous::GetDataSize)</para>
        /// </summary>
        property UInt32 DataSize
        {
            UInt32 get();
        }


    protected:
        Asynchronous()
        {
        }
    internal:

        Asynchronous(ID3D11Asynchronous* pNativeID3D11Asynchronous)
        {
            nativeUnknown.Set(pNativeID3D11Asynchronous);
        }

        Asynchronous(ID3D11Asynchronous* pNativeID3D11Asynchronous, bool deletable)
        {
            nativeUnknown.Set(pNativeID3D11Asynchronous, deletable);
        }

        property ID3D11Asynchronous* NativeID3D11Asynchronous
        {
            ID3D11Asynchronous* get()
            {
                return reinterpret_cast<ID3D11Asynchronous*>(nativeUnknown.Get());
            }
        }
    };
} } } }
