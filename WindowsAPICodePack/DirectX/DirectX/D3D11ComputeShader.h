//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once
#include "D3D11DeviceChild.h"

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3D11 {

using namespace System;

    /// <summary>
    /// A compute-shader interface manages an executable program (a compute shader) that controls the compute-shader stage.
    /// <para>(Also see DirectX SDK: ID3D11ComputeShader)</para>
    /// </summary>
    public ref class ComputeShader :
        public Microsoft::WindowsAPICodePack::DirectX::Direct3D11::DeviceChild
    {
    public: 

    protected:
        ComputeShader()
        {
        }
    internal:

        ComputeShader(ID3D11ComputeShader* pNativeID3D11ComputeShader)
        {
            nativeUnknown.Set(pNativeID3D11ComputeShader);
        }

        property ID3D11ComputeShader* NativeID3D11ComputeShader
        {
            ID3D11ComputeShader* get()
            {
                return reinterpret_cast<ID3D11ComputeShader*>(nativeUnknown.Get());
            }
        }
    };
} } } }
