// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"

#include "DXGIFactory.h"
#include "D3DDeviceBase.h"
#include "DXGIAdapter.h"
#include "DXGISwapChain.h"


using namespace System::Collections::Generic;
using namespace Microsoft::WindowsAPICodePack::DirectX::DXGI;
using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3DCommon;

typedef HRESULT (*CreateDXGIFactoryFuncPtr)(REFIID riid, void **ppFactory);

DXGIFactory::DXGIFactory() : dxgiLibrary (0)
{

#ifdef DXBETA
    wchar_t* libName = L"DXGI_BETA.dll"; // Only on beta
#else
    wchar_t* libName = L"DXGI.dll";
#endif
    dxgiLibrary = D3DUtils::LoadDll(libName);

    CreateDXGIFactoryFuncPtr createFuncPtr = 
        (CreateDXGIFactoryFuncPtr) D3DUtils::GetFunctionfromDll(
            dxgiLibrary, "CreateDXGIFactory");

    IDXGIFactory * pNativeIDXGIFactory = NULL;

    D3DUtils::VerifyResult(
        (*createFuncPtr)(__uuidof(IDXGIFactory), (void**)(&pNativeIDXGIFactory)));

    nativeUnknown.Set(pNativeIDXGIFactory);
}

SwapChain^ DXGIFactory::CreateSwapChain(D3DDeviceBase^ Device, SwapChainDescription^ Description)
{
    System::Diagnostics::Debug::Assert(NativeIDXGIFactory != NULL);

    IDXGISwapChain* tempoutSwapChain;
    D3DUtils::VerifyResult(NativeIDXGIFactory->CreateSwapChain(Device->NativeDevice, Description->nativeObject.Get(), &tempoutSwapChain));
    return gcnew SwapChain(tempoutSwapChain);

}

CachedCollection<Adapter^>^ DXGIFactory::AdaptersCache::get()
{
    if (adaptersCache == nullptr)
    {
        adaptersCache = gcnew CachedCollection<Adapter^>();
    }

    if (!adaptersCache->IsValid)
    {
        int i = 0;
        while (true)
        {
            IDXGIAdapter* tempAdapter;

            if (DXGI_ERROR_NOT_FOUND != NativeIDXGIFactory->EnumAdapters(i++, &tempAdapter))
                adaptersCache->InternalAdd(gcnew Adapter(tempAdapter));
            else
                break;
        }
        adaptersCache->IsValid = true;
    }

    return adaptersCache;
}            

IntPtr DXGIFactory::GetWindowAssociation()
{
    System::Diagnostics::Debug::Assert(NativeIDXGIFactory != NULL);

    HWND hWnd = 0;
    D3DUtils::VerifyResult(NativeIDXGIFactory->GetWindowAssociation(&hWnd));
    
    return IntPtr(hWnd);
}

void DXGIFactory::MakeWindowAssociation(IntPtr WindowHandle, MakeWindowAssociationFlags Flags)
{
    System::Diagnostics::Debug::Assert(NativeIDXGIFactory != NULL);

    D3DUtils::VerifyResult(NativeIDXGIFactory->MakeWindowAssociation(static_cast<HWND>(WindowHandle.ToPointer()), safe_cast<UINT>(Flags)));
}

