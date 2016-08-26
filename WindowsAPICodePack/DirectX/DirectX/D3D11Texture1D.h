//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once
#include "D3D11Resource.h"

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3D11 {

using namespace System;

    /// <summary>
    /// A 1D texture interface accesses texel data, which is structured memory.
    /// <para>(Also see DirectX SDK: ID3D11Texture1D)</para>
    /// </summary>
    public ref class Texture1D :
        public Microsoft::WindowsAPICodePack::DirectX::Direct3D11::D3DResource
    {
    public: 
        /// <summary>
        /// Get the properties of the texture resource.
        /// <para>(Also see DirectX SDK: ID3D11Texture1D::GetDesc)</para>
        /// </summary>
        /// <param name="outDescription">A resource description (see <see cref="Texture1dDescription"/>)<seealso cref="Texture1dDescription"/>.</param>
        property Texture1dDescription^ Description
        {
            Texture1dDescription^ get();
        }


    protected:
        Texture1D()
        {
        }
    internal:

        Texture1D(ID3D11Texture1D* pNativeID3D11Texture1D)
        {
            nativeUnknown.Set(pNativeID3D11Texture1D);
        }

        property ID3D11Texture1D* NativeID3D11Texture1D
        {
            ID3D11Texture1D* get()
            {
                return reinterpret_cast<ID3D11Texture1D*>(nativeUnknown.Get());
            }
        }
    };
} } } }
