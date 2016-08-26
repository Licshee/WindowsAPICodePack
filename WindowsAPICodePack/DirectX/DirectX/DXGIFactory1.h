//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once

#include "DXGIFactory.h"
#include "CachedCollection.h"

using namespace System;

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace DXGI {

ref class Adapter1;

    /// <summary>
    /// The DXGIFactory1 interface implements methods for generating DXGI objects.
    /// <para>(Also see DirectX SDK: IDXGIFactory1)</para>
    /// </summary>
    public ref class DXGIFactory1 :
        public Microsoft::WindowsAPICodePack::DirectX::DXGI::DXGIFactory
    {
    public: 
        /// <summary>
        /// Enumerates both local and remote adapters (video cards).
        /// <para>(Also see DirectX SDK: IDXGIFactory1::EnumAdapters1)</para>
        /// </summary>
        property CachedCollection<Adapter1^>^ Adapters1Cache
        {
            CachedCollection<Adapter1^>^ get();
        }        

        /// <summary>
        /// Informs application the possible need to re-enumerate adapters -- new adapter(s) have become available, current adapter(s) become unavailable.
        /// Called by Direct3D 10.1 Command Remoting applications to handle Remote Desktop Services session transitions.
        /// <para>(Also see DirectX SDK: IDXGIFactory1::IsCurrent)</para>
        /// </summary>
        property Boolean IsCurrent
        {
            Boolean get();
        }


    public:
        DXGIFactory1();

    internal:
        DXGIFactory1(IDXGIFactory1* pNativeIDXGIFactory1)
        {
            nativeUnknown.Set(pNativeIDXGIFactory1);
        }

        property IDXGIFactory1* NativeIDXGIFactory1
        {
            IDXGIFactory1* get()
            {
                return reinterpret_cast<IDXGIFactory1*>(nativeUnknown.Get());
            }
        }

    protected:
        virtual ~DXGIFactory1()
        {
            if (adapters1Cache != nullptr)
            {
                adapters1Cache = nullptr;
            }
            this->!DXGIFactory1();
        }
            
        !DXGIFactory1()
        {
            if (dxgiLibrary1 != 0)
                FreeLibrary(dxgiLibrary1);
        }

    private:
        HINSTANCE dxgiLibrary1;
        CachedCollection<Adapter1^>^ adapters1Cache;
    };
} } } }
