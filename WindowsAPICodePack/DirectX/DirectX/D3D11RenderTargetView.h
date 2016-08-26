//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once
#include "D3D11View.h"

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3D11 {

using namespace System;

    /// <summary>
    /// A render-target-view interface identifies the render-target subresources that can be accessed during rendering.
    /// <para>(Also see DirectX SDK: ID3D11RenderTargetView)</para>
    /// </summary>
    public ref class RenderTargetView :
        public Microsoft::WindowsAPICodePack::DirectX::Direct3D11::View
    {
    public: 
        /// <summary>
        /// Get the properties of a render target view.
        /// <para>(Also see DirectX SDK: ID3D11RenderTargetView::GetDesc)</para>
        /// </summary>
        property RenderTargetViewDescription^ Description
        {
            RenderTargetViewDescription^ get();
        }


    protected:
        RenderTargetView()
        {
        }
    internal:

        RenderTargetView(ID3D11RenderTargetView* pNativeID3D11RenderTargetView)
        {
            nativeUnknown.Set(pNativeID3D11RenderTargetView);
        }

        property ID3D11RenderTargetView* NativeID3D11RenderTargetView
        {
            ID3D11RenderTargetView* get()
            {
                return reinterpret_cast<ID3D11RenderTargetView*>(nativeUnknown.Get());
            }
        }
    };
} } } }
