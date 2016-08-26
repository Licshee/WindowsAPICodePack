//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once
#include "D3D11DeviceChild.h"

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3D11 {

using namespace System;

    /// <summary>
    /// A domain-shader interface manages an executable program (a domain shader) that controls the domain-shader stage.
    /// <para>(Also see DirectX SDK: ID3D11DomainShader)</para>
    /// </summary>
    public ref class DomainShader :
        public Microsoft::WindowsAPICodePack::DirectX::Direct3D11::DeviceChild
    {
    public: 

    protected:
        DomainShader()
        {
        }
    internal:

        DomainShader(ID3D11DomainShader* pNativeID3D11DomainShader)
        {
            nativeUnknown.Set(pNativeID3D11DomainShader);
        }

        property ID3D11DomainShader* NativeID3D11DomainShader
        {
            ID3D11DomainShader* get()
            {
                return reinterpret_cast<ID3D11DomainShader*>(nativeUnknown.Get());
            }
        }
    };
} } } }
