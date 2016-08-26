// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "D3D11Asynchronous.h"

using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D11;

UInt32 Asynchronous::DataSize::get()
{
    System::Diagnostics::Debug::Assert(NativeID3D11Asynchronous != NULL);

    return safe_cast<UInt32>(NativeID3D11Asynchronous->GetDataSize());

}

