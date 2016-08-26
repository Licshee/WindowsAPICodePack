//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once
#include "D3D11DeviceChild.h"

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3D11 {

using namespace System;

    /// <summary>
    /// A pixel-shader interface manages an executable program (a pixel shader) that controls the pixel-shader stage.
    /// <para>(Also see DirectX SDK: ID3D11PixelShader)</para>
    /// </summary>
    public ref class PixelShader :
        public Microsoft::WindowsAPICodePack::DirectX::Direct3D11::DeviceChild
    {
    public: 

    protected:
        PixelShader()
        {
        }
    internal:

        PixelShader(ID3D11PixelShader* pNativeID3D11PixelShader)
        {
            nativeUnknown.Set(pNativeID3D11PixelShader);
        }

        property ID3D11PixelShader* NativeID3D11PixelShader
        {
            ID3D11PixelShader* get()
            {
                return reinterpret_cast<ID3D11PixelShader*>(nativeUnknown.Get());
            }
        }
    };
} } } }
