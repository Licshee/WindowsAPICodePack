//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once
#include "D3D11Asynchronous.h"

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3D11 {

using namespace System;

    /// <summary>
    /// A query interface queries information from the GPU.
    /// <para>(Also see DirectX SDK: ID3D11Query)</para>
    /// </summary>
    public ref class D3DQuery :
        public Microsoft::WindowsAPICodePack::DirectX::Direct3D11::Asynchronous
    {
    public: 
        /// <summary>
        /// Get a query description.
        /// <para>(Also see DirectX SDK: ID3D11Query::GetDesc)</para>
        /// </summary>
        /// <param name="outDescription">A query description (see <see cref="QueryDescription"/>)<seealso cref="QueryDescription"/>.</param>
        property QueryDescription^ Description
        {
            QueryDescription^ get();
        }


    protected:
        D3DQuery()
        {
        }
    internal:

        D3DQuery(ID3D11Query* pNativeID3D11Query)
        {
            nativeUnknown.Set(pNativeID3D11Query);
        }

        property ID3D11Query* NativeID3D11Query
        {
            ID3D11Query* get()
            {
                return reinterpret_cast<ID3D11Query*>(nativeUnknown.Get());
            }
        }
    };
} } } }
