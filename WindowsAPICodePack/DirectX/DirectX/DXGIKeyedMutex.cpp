// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "DXGIKeyedMutex.h"

using namespace Microsoft::WindowsAPICodePack::DirectX::DXGI;

void KeyedMutex::AcquireSync(UInt64 Key, DWORD dwMilliseconds)
{
    System::Diagnostics::Debug::Assert(NativeIDXGIKeyedMutex != NULL);

    D3DUtils::VerifyResult(NativeIDXGIKeyedMutex->AcquireSync(safe_cast<UINT64>(Key), safe_cast<DWORD>(dwMilliseconds)));

}

void KeyedMutex::ReleaseSync(UInt64 Key)
{
    System::Diagnostics::Debug::Assert(NativeIDXGIKeyedMutex != NULL);

    D3DUtils::VerifyResult(NativeIDXGIKeyedMutex->ReleaseSync(safe_cast<UINT64>(Key)));

}

