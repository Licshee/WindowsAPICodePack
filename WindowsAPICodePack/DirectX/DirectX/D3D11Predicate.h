//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once
#include "D3D11Query.h"

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3D11 {

using namespace System;

    /// <summary>
    /// A predicate interface determines whether geometry should be processed depending on the results of a previous draw call.
    /// <para>(Also see DirectX SDK: ID3D11Predicate)</para>
    /// </summary>
    public ref class D3DPredicate :
        public Microsoft::WindowsAPICodePack::DirectX::Direct3D11::D3DQuery
    {
    public: 

    protected:
        D3DPredicate()
        {
        }
    internal:

        D3DPredicate(ID3D11Predicate* pNativeID3D11Predicate)
        {
            nativeUnknown.Set(pNativeID3D11Predicate);
        }

        property ID3D11Predicate* NativeID3D11Predicate
        {
            ID3D11Predicate* get()
            {
                return reinterpret_cast<ID3D11Predicate*>(nativeUnknown.Get());
            }
        }
    };
} } } }
