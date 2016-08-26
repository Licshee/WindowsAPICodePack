//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once
#include "D3D11DeviceChild.h"

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3D11 {

using namespace System;

    /// <summary>
    /// The CommandList interface encapsulates a collection of graphics commands for play back.
    /// <para>(Also see DirectX SDK: ID3D11CommandList)</para>
    /// </summary>
    public ref class CommandList :
        public Microsoft::WindowsAPICodePack::DirectX::Direct3D11::DeviceChild
    {
    public: 
        /// <summary>
        /// Gets the initialization flags associated with the deferred context that created the command list.
        /// The context flag is reserved for future use and is always 0.
        /// <para>(Also see DirectX SDK: ID3D11CommandList::GetContextFlags)</para>
        /// </summary>
        property UInt32 ContextFlags
        {
            UInt32 get();
        }


    protected:
        CommandList()
        {
        }
    internal:

        CommandList(ID3D11CommandList* pNativeID3D11CommandList)
        {
            nativeUnknown.Set(pNativeID3D11CommandList);
        }

        property ID3D11CommandList* NativeID3D11CommandList
        {
            ID3D11CommandList* get()
            {
                return reinterpret_cast<ID3D11CommandList*>(nativeUnknown.Get());
            }
        }
    };
} } } }
