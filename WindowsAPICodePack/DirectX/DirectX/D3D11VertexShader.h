//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once
#include "D3D11DeviceChild.h"

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3D11 {

using namespace System;

    /// <summary>
    /// A vertex-shader interface manages an executable program (a vertex shader) that controls the vertex-shader stage.
    /// <para>(Also see DirectX SDK: ID3D11VertexShader)</para>
    /// </summary>
    public ref class VertexShader :
        public Microsoft::WindowsAPICodePack::DirectX::Direct3D11::DeviceChild
    {
    public: 

    protected:
        VertexShader()
        {
        }
    internal:

        VertexShader(ID3D11VertexShader* pNativeID3D11VertexShader)
        {
            nativeUnknown.Set(pNativeID3D11VertexShader);
        }

        property ID3D11VertexShader* NativeID3D11VertexShader
        {
            ID3D11VertexShader* get()
            {
                return reinterpret_cast<ID3D11VertexShader*>(nativeUnknown.Get());
            }
        }
    };
} } } }
