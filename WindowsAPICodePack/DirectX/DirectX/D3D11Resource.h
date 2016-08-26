//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once
#include "D3D11DeviceChild.h"

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3D11 {

using namespace System;

    /// <summary>
    /// A resource interface provides common actions on all resources.
    /// <para>(Also see DirectX SDK: ID3D11Resource)</para>
    /// </summary>
    public ref class D3DResource :
        public Microsoft::WindowsAPICodePack::DirectX::Direct3D11::DeviceChild
    {
    public: 
        /// <summary>
        /// Gets or sets the eviction priority of a resource.
        /// <para>(Also see DirectX SDK: ID3D11Resource::GetEvictionPriority, ID3D11Resource::SetEvictionPriority)</para>
        /// </summary>
        property UInt32 EvictionPriority
        {
            UInt32 get();
            void set(UInt32 value);
        }

        /// <summary>
        /// Get the type of the resource.
        /// <para>(Also see DirectX SDK: ID3D11Resource::GetType)</para>
        /// </summary>
        property ResourceDimension ResourceType
        {
            ResourceDimension get();
        }

    protected:
        D3DResource()
        {
        }
    internal:

        D3DResource(ID3D11Resource* pNativeID3D11Resource)
        {
            nativeUnknown.Set(pNativeID3D11Resource);
        }

        property ID3D11Resource* NativeID3D11Resource
        {
            ID3D11Resource* get()
            {
                return reinterpret_cast<ID3D11Resource*>(nativeUnknown.Get());
            }
        }
    };
} } } }
