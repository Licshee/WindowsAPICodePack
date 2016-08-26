// Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3DCommon {

using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;
using namespace System::Runtime::InteropServices;
using namespace Microsoft::WindowsAPICodePack::DirectX::DXGI;

ref class DirectUnknown;
ref class DirectObject;

public ref class D3DUtils
{
private:
    static Dictionary<System::Type^, System::Guid>^ GuidsDictionary = nullptr;
    static void FillGuidsDictionary();
    static D3DUtils()
    {
        FillGuidsDictionary();
    }
internal:
    static int MaxNameSize = 1024;

    
    static System::Guid SystemGuidFromGUID(REFGUID guid );
    
    static GUID GUIDFromSystemGuid( System::Guid guid );

    static GUID GetGuid(System::Type^ type);

    generic <typename T>
    static T CreateObjectFromPointer(void* ptr);

    //template <class T>
    static FARPROC GetFunctionfromDll(HINSTANCE library, LPCSTR functionName);

    static HINSTANCE LoadDll(LPCWSTR libraryName);

public:
    static void CheckNull(Object^ o, String^ argName);

    static char* CharArrayfromSystemString(String^ str);

    static Exception^ GetExceptionForHR(HRESULT hr);
    
    static void VerifyResult(HRESULT hr);

    generic <typename T> where T : DirectUnknown
    static T CreateInterfaceWrapper(System::IntPtr nativePtr);

    generic <typename T> where T : DirectObject
    static T CreateObjectWrapper(System::IntPtr nativePtr);

};
}}}}
