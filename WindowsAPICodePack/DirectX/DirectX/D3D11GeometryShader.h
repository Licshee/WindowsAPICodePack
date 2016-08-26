//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once
#include "D3D11DeviceChild.h"

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3D11 {

using namespace System;

    /// <summary>
    /// A geometry-shader interface manages an executable program (a geometry shader) that controls the geometry-shader stage.
    /// <para>(Also see DirectX SDK: ID3D11GeometryShader)</para>
    /// </summary>
    public ref class GeometryShader :
        public Microsoft::WindowsAPICodePack::DirectX::Direct3D11::DeviceChild
    {
    public: 

    protected:
        GeometryShader()
        {
        }
    internal:

        GeometryShader(ID3D11GeometryShader* pNativeID3D11GeometryShader)
        {
            nativeUnknown.Set(pNativeID3D11GeometryShader);
        }

        property ID3D11GeometryShader* NativeID3D11GeometryShader
        {
            ID3D11GeometryShader* get()
            {
                return reinterpret_cast<ID3D11GeometryShader*>(nativeUnknown.Get());
            }
        }
    };
} } } }
