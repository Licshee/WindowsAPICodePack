//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once
#include "D3D11DeviceChild.h"

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3D11 {

using namespace System;

    /// <summary>
    /// This blend-state interface accesses blending state for the output-merger stage.
    /// <para>(Also see DirectX SDK: ID3D11BlendState)</para>
    /// </summary>
    public ref class BlendState :
        public Microsoft::WindowsAPICodePack::DirectX::Direct3D11::DeviceChild
    {
    public: 
        /// <summary>
        /// Get the blend state description.
        /// <para>(Also see DirectX SDK: ID3D11BlendState::GetDesc)</para>
        /// </summary>
        property BlendDescription^ Description
        {
            BlendDescription^ get();
        }


    protected:
        BlendState()
        {
        }
    internal:

        BlendState(ID3D11BlendState* pNativeID3D11BlendState)
        {
            nativeUnknown.Set(pNativeID3D11BlendState);
        }

        property ID3D11BlendState* NativeID3D11BlendState
        {
            ID3D11BlendState* get()
            {
                return reinterpret_cast<ID3D11BlendState*>(nativeUnknown.Get());
            }
        }
    };
} } } }
