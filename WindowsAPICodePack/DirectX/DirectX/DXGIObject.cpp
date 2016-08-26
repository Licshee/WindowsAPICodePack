// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "DXGIObject.h"

using namespace Microsoft::WindowsAPICodePack::DirectX::DXGI;

generic <typename T>
    where T : DXGIObject
T DXGIObject::GetParent() 
{
    System::Diagnostics::Debug::Assert(NativeIDXGIObject != NULL);

    void* tempUnknown = NULL;
    GUID guid = D3DUtils::GetGuid(T::typeid);
    
    D3DUtils::VerifyResult(NativeIDXGIObject->GetParent(guid, &tempUnknown));

    return safe_cast<T>(D3DUtils::CreateObjectFromPointer<T>(tempUnknown));
}

//void DXGIObject::GetPrivateData(Guid Name, [Runtime::InteropServices::Out, Runtime::InteropServices::In] UInt32 %outDataSize, [Runtime::InteropServices::Out] IntPtr %outData)
//{
//    System::Diagnostics::Debug::Assert(NativeIDXGIObject != NULL);
//
//    UINT tempoutDataSize = safe_cast<UINT>(outDataSize);
//    LPVOID tempoutData;
//    GUID tempName = D3DUtils::GUIDFromSystemGuid(Name);
//    D3DUtils::VerifyResult(NativeIDXGIObject->GetPrivateData(tempName, &tempoutDataSize, &tempoutData));
//    outDataSize = safe_cast<UInt32>(tempoutDataSize);
//    outData = safe_cast<IntPtr>(tempoutData);
//
//}
//
//void DXGIObject::SetPrivateData(Guid Name, UInt32 DataSize, IntPtr Data)
//{
//    System::Diagnostics::Debug::Assert(NativeIDXGIObject != NULL);
//
//    GUID tempName = D3DUtils::GUIDFromSystemGuid(Name);
//    D3DUtils::VerifyResult(NativeIDXGIObject->SetPrivateData(tempName, safe_cast<UINT>(DataSize), reinterpret_cast<LPVOID>(Data.ToPointer())));
//
//}
//
//void DXGIObject::SetPrivateDataInterface(Guid Name, IntPtr Unknown)
//{
//    System::Diagnostics::Debug::Assert(NativeIDXGIObject != NULL);
//
//    GUID tempName = D3DUtils::GUIDFromSystemGuid(Name);
//    D3DUtils::VerifyResult(NativeIDXGIObject->SetPrivateDataInterface(tempName, reinterpret_cast<IUnknown*>(Unknown.ToPointer())));
//
//}

