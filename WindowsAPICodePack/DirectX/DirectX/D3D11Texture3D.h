//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once
#include "D3D11Resource.h"

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3D11 {

using namespace System;

    /// <summary>
    /// A 3D texture interface accesses texel data, which is structured memory.
    /// <para>(Also see DirectX SDK: ID3D11Texture3D)</para>
    /// </summary>
    public ref class Texture3D :
        public Microsoft::WindowsAPICodePack::DirectX::Direct3D11::D3DResource
    {
    public: 
        /// <summary>
        /// Get the properties of the texture resource.
        /// <para>(Also see DirectX SDK: ID3D11Texture3D::GetDesc)</para>
        /// </summary>
        property Texture3dDescription^ Description
        {
            Texture3dDescription^ get();
        }


    protected:
        Texture3D()
        {
        }
    internal:

        Texture3D(ID3D11Texture3D* pNativeID3D11Texture3D)
        {
            nativeUnknown.Set(pNativeID3D11Texture3D);
        }

        property ID3D11Texture3D* NativeID3D11Texture3D
        {
            ID3D11Texture3D* get()
            {
                return reinterpret_cast<ID3D11Texture3D*>(nativeUnknown.Get());
            }
        }
    };
} } } }
