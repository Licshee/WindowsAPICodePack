// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "DXGIResource.h"

using namespace Microsoft::WindowsAPICodePack::DirectX::DXGI;

ResourcePriority DXGIResource::EvictionPriority::get()
{
    System::Diagnostics::Debug::Assert(NativeIDXGIResource != NULL);

    UINT tempoutEvictionPriority;
    D3DUtils::VerifyResult(NativeIDXGIResource->GetEvictionPriority(&tempoutEvictionPriority));
    return safe_cast<ResourcePriority>(tempoutEvictionPriority);

}

void DXGIResource::EvictionPriority::set(ResourcePriority value)
{
    System::Diagnostics::Debug::Assert(NativeIDXGIResource != NULL);

    D3DUtils::VerifyResult(NativeIDXGIResource->SetEvictionPriority(safe_cast<UINT>(value)));
}

ResourceHandle^ DXGIResource::SharedHandle::get()
{
    System::Diagnostics::Debug::Assert(NativeIDXGIResource != NULL);

    HANDLE tempoutSharedHandle;
    D3DUtils::VerifyResult(NativeIDXGIResource->GetSharedHandle(&tempoutSharedHandle));
    return gcnew ResourceHandle(IntPtr(tempoutSharedHandle));

}

UsageOption DXGIResource::UsageFlags::get()
{
    System::Diagnostics::Debug::Assert(NativeIDXGIResource != NULL);

    DXGI_USAGE tempoutUsage;
    D3DUtils::VerifyResult(NativeIDXGIResource->GetUsage(&tempoutUsage));
    return safe_cast<UsageOption>(tempoutUsage);
}


