//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once
#include "D3D11View.h"

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3D11 {

using namespace System;

    /// <summary>
    /// A view interface specifies the parts of a resource the pipeline can access during rendering.
    /// <para>(Also see DirectX SDK: ID3D11UnorderedAccessView)</para>
    /// </summary>
    public ref class UnorderedAccessView :
        public Microsoft::WindowsAPICodePack::DirectX::Direct3D11::View
    {
    public: 
        /// <summary>
        /// Get a description of the resource.
        /// <para>(Also see DirectX SDK: ID3D11UnorderedAccessView::GetDesc)</para>
        /// </summary>
        /// <param name="outDescription">A resource description (see <see cref="UnorderedAccessViewDescription"/>)<seealso cref="UnorderedAccessViewDescription"/>.</param>
        property UnorderedAccessViewDescription^ Description
        {
            UnorderedAccessViewDescription^ get();
        }


    protected:
        UnorderedAccessView()
        {
        }
    internal:

        UnorderedAccessView(ID3D11UnorderedAccessView* pNativeID3D11UnorderedAccessView)
        {
            nativeUnknown.Set(pNativeID3D11UnorderedAccessView);
        }

        property ID3D11UnorderedAccessView* NativeID3D11UnorderedAccessView
        {
            ID3D11UnorderedAccessView* get()
            {
                return reinterpret_cast<ID3D11UnorderedAccessView*>(nativeUnknown.Get());
            }
        }
    };
} } } }
