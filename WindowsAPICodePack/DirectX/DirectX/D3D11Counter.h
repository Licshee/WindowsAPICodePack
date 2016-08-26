//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once
#include "D3D11Asynchronous.h"

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3D11 {

using namespace System;

    /// <summary>
    /// This class encapsulates methods for measuring GPU performance.
    /// <para>(Also see DirectX SDK: ID3D11Counter)</para>
    /// </summary>
    public ref class Counter :
        public Microsoft::WindowsAPICodePack::DirectX::Direct3D11::Asynchronous
    {
    public: 
        /// <summary>
        /// Get a counter description.
        /// <para>(Also see DirectX SDK: ID3D11Counter::GetDesc)</para>
        /// </summary>
        /// <param name="outDescription">A counter description (see <see cref="CounterDescription"/>)<seealso cref="CounterDescription"/>.</param>
        property CounterDescription^ Description
        {
            CounterDescription^ get();
        }


    protected:
        Counter()
        {
        }
    internal:

        Counter(ID3D11Counter* pNativeID3D11Counter)
        {
            nativeUnknown.Set(pNativeID3D11Counter);
        }

        property ID3D11Counter* NativeID3D11Counter
        {
            ID3D11Counter* get()
            {
                return reinterpret_cast<ID3D11Counter*>(nativeUnknown.Get());
            }
        }
    };
} } } }
