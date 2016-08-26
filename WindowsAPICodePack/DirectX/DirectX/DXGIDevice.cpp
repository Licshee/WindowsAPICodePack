// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "DXGIDevice.h"

#include "DXGISurface.h"
#include "DXGIAdapter.h"
using namespace Microsoft::WindowsAPICodePack::DirectX::DXGI;

Adapter^ DXGIDevice::DeviceAdapter::get()
{
    System::Diagnostics::Debug::Assert(NativeIDXGIDevice != NULL);

    IDXGIAdapter* tempoutAdapter;
    D3DUtils::VerifyResult(NativeIDXGIDevice->GetAdapter(&tempoutAdapter));
    return (tempoutAdapter == NULL ? nullptr : gcnew Adapter(tempoutAdapter));
}

Int32 DXGIDevice::GPUThreadPriority::get()
{
    System::Diagnostics::Debug::Assert(NativeIDXGIDevice != NULL);

    INT tempoutPriority;
    D3DUtils::VerifyResult(NativeIDXGIDevice->GetGPUThreadPriority(&tempoutPriority));
    return safe_cast<Int32>(tempoutPriority);
}

void DXGIDevice::GPUThreadPriority::set(Int32 value)
{
    System::Diagnostics::Debug::Assert(NativeIDXGIDevice != NULL);

    if (value < -7 || value > 7)
    {
        throw gcnew ArgumentOutOfRangeException("value", "GPUThreadPriority valid range is -7 to +7, inclusive.");
    }

    D3DUtils::VerifyResult(NativeIDXGIDevice->SetGPUThreadPriority(safe_cast<INT>(value)));

}
//Residency DXGIDevice::QueryResourceResidency(IntPtr Resources, UInt32 NumResources)
//{
//    System::Diagnostics::Debug::Assert(NativeIDXGIDevice != NULL);
//
//    DXGI_RESIDENCY tempoutResidencyStatus;
//    D3DUtils::VerifyResult(NativeIDXGIDevice->QueryResourceResidency(reinterpret_cast<IUnknown**>(Resources.ToPointer()), &tempoutResidencyStatus, safe_cast<UINT>(NumResources)));
//    return safe_cast<Residency>(tempoutResidencyStatus);
//}



