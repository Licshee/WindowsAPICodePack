// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "DXGIFactory1.h"
#include "DXGIAdapter1.h"

using namespace System::Collections::Generic;
using namespace System::Collections::ObjectModel;
using namespace Microsoft::WindowsAPICodePack::DirectX::DXGI;
using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3DCommon;

typedef HRESULT (*CreateDXGIFactory1FuncPtr)(REFIID riid, void **ppFactory);

DXGIFactory1::DXGIFactory1() : dxgiLibrary1 (0)
{

#ifdef DXBETA
    wchar_t* libName = L"DXGI_BETA.dll"; // Only on beta
#else
    wchar_t* libName = L"DXGI.dll";
#endif
    dxgiLibrary1 = D3DUtils::LoadDll(libName);

    CreateDXGIFactory1FuncPtr createFuncPtr = 
        (CreateDXGIFactory1FuncPtr) D3DUtils::GetFunctionfromDll(
            dxgiLibrary1, "CreateDXGIFactory1");

    IDXGIFactory1 * factory = NULL;

    D3DUtils::VerifyResult(
        (*createFuncPtr)(__uuidof(IDXGIFactory1), (void**)(&factory)));

    nativeUnknown.Set(factory);
}

CachedCollection<Adapter1^>^ DXGIFactory1::Adapters1Cache::get()
{
    if (adapters1Cache == nullptr)
    {
        adapters1Cache = gcnew CachedCollection<Adapter1^>();
    }

    if (!adapters1Cache->IsValid)
    {
        int i = 0;
        while (true)
        {
            IDXGIAdapter1* tempAdapter;

            if (DXGI_ERROR_NOT_FOUND != NativeIDXGIFactory1->EnumAdapters1(i++, &tempAdapter))
                adapters1Cache->InternalAdd(gcnew Adapter1(tempAdapter));
            else
                break;
        }
        adapters1Cache->IsValid = true;
    }

    return adapters1Cache;}

Boolean DXGIFactory1::IsCurrent::get()
{
    System::Diagnostics::Debug::Assert(NativeIDXGIFactory1 != NULL);

    BOOL returnValue = NativeIDXGIFactory1->IsCurrent();
    return returnValue != 0;
}

