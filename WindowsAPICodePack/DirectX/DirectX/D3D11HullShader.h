//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once
#include "D3D11DeviceChild.h"

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3D11 {

using namespace System;

    /// <summary>
    /// A hull-shader interface manages an executable program (a hull shader) that controls the hull-shader stage.
    /// <para>(Also see DirectX SDK: ID3D11HullShader)</para>
    /// </summary>
    public ref class HullShader :
        public Microsoft::WindowsAPICodePack::DirectX::Direct3D11::DeviceChild
    {
    public: 

    protected:
        HullShader()
        {
        }
    internal:

        HullShader(ID3D11HullShader* pNativeID3D11HullShader)
        {
            nativeUnknown.Set(pNativeID3D11HullShader);
        }

        property ID3D11HullShader* NativeID3D11HullShader
        {
            ID3D11HullShader* get()
            {
                return reinterpret_cast<ID3D11HullShader*>(nativeUnknown.Get());
            }
        }
    };
} } } }
