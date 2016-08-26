//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once
#include "D3D11View.h"

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3D11 {

using namespace System;

    /// <summary>
    /// A depth-stencil-view interface accesses a texture resource during depth-stencil testing.
    /// <para>(Also see DirectX SDK: ID3D11DepthStencilView)</para>
    /// </summary>
    public ref class DepthStencilView :
        public Microsoft::WindowsAPICodePack::DirectX::Direct3D11::View
    {
    public: 
        /// <summary>
        /// Get the depth-stencil view.
        /// <para>(Also see DirectX SDK: ID3D11DepthStencilView::GetDesc)</para>
        /// </summary>
        /// <param name="outDescription">A depth-stencil-view description (see <see cref="DepthStencilViewDescription"/>)<seealso cref="DepthStencilViewDescription"/>.</param>
        property DepthStencilViewDescription^ Description
        {
            DepthStencilViewDescription^ get(); 
        }


    protected:
        DepthStencilView()
        {
        }
    internal:

        DepthStencilView(ID3D11DepthStencilView* pNativeID3D11DepthStencilView)
        {
            nativeUnknown.Set(pNativeID3D11DepthStencilView);
        }

        property ID3D11DepthStencilView* NativeID3D11DepthStencilView
        {
            ID3D11DepthStencilView* get()
            {
                return reinterpret_cast<ID3D11DepthStencilView*>(nativeUnknown.Get());
            }
        }
    };
} } } }
