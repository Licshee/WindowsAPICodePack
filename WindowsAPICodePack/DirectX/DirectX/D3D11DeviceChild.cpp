// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "D3D11DeviceChild.h"

#include "D3D11Device.h"
using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D11;

D3DDevice^ DeviceChild::ParentDevice::get()
{
    System::Diagnostics::Debug::Assert(NativeID3D11DeviceChild != NULL);

    ID3D11Device* tempoutDevice = NULL;
    NativeID3D11DeviceChild->GetDevice(&tempoutDevice);
    return tempoutDevice == NULL ? nullptr : gcnew D3DDevice(tempoutDevice);

}

//
//void DeviceChild::GetPrivateData(Guid guid, [Runtime::InteropServices::Out, Runtime::InteropServices::In] UInt32 %outDataSize, [Runtime::InteropServices::Out] IntPtr %outData)
//{
//    System::Diagnostics::Debug::Assert(NativeID3D11DeviceChild != NULL);
//
//    UINT tempoutDataSize = safe_cast<UINT>(outDataSize);
//    LPVOID tempoutData;
//    GUID tempguid = D3DUtils::GUIDFromSystemGuid(guid);
//    D3DUtils::VerifyResult(NativeID3D11DeviceChild->GetPrivateData(tempguid, &tempoutDataSize, &tempoutData));
//    outDataSize = safe_cast<UInt32>(tempoutDataSize);
//    outData = safe_cast<IntPtr>(tempoutData);
//
//}
//
//void DeviceChild::SetPrivateData(Guid guid, UInt32 DataSize, IntPtr Data)
//{
//    System::Diagnostics::Debug::Assert(NativeID3D11DeviceChild != NULL);
//
//    GUID tempguid = D3DUtils::GUIDFromSystemGuid(guid);
//    D3DUtils::VerifyResult(NativeID3D11DeviceChild->SetPrivateData(tempguid, safe_cast<UINT>(DataSize), reinterpret_cast<LPVOID>(Data.ToPointer())));
//
//}
//
//void DeviceChild::SetPrivateDataInterface(Guid guid, IntPtr Data)
//{
//    System::Diagnostics::Debug::Assert(NativeID3D11DeviceChild != NULL);
//
//    GUID tempguid = D3DUtils::GUIDFromSystemGuid(guid);
//    D3DUtils::VerifyResult(NativeID3D11DeviceChild->SetPrivateDataInterface(tempguid, reinterpret_cast<IUnknown*>(Data.ToPointer())));
//
//}
//
