//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once
#include "D3D11DeviceChild.h"

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3D11 {

using namespace System;

    /// <summary>
    /// A sampler-state interface accesses sampler state for a texture.
    /// <para>(Also see DirectX SDK: ID3D11SamplerState)</para>
    /// </summary>
    public ref class SamplerState :
        public Microsoft::WindowsAPICodePack::DirectX::Direct3D11::DeviceChild
    {
    public: 
        /// <summary>
        /// Get the sampler state.
        /// <para>(Also see DirectX SDK: ID3D11SamplerState::GetDesc)</para>
        /// </summary>
        property SamplerDescription^ Description
        {
            SamplerDescription^ get();
        }        

    protected:
        SamplerState()
        {
        }
    internal:

        SamplerState(ID3D11SamplerState* pNativeID3D11SamplerState)
        {
            nativeUnknown.Set(pNativeID3D11SamplerState);
        }

        SamplerState(ID3D11SamplerState* pNativeID3D11SamplerState, bool deletable)
        {
            nativeUnknown.Set(pNativeID3D11SamplerState, deletable);
        }

        property ID3D11SamplerState* NativeID3D11SamplerState
        {
            ID3D11SamplerState* get()
            {
                return reinterpret_cast<ID3D11SamplerState*>(nativeUnknown.Get());
            }
        }
    };
} } } }
