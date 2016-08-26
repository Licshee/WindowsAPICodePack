// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "D3D11Counter.h"

using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D11;
using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D11;


CounterDescription^ Counter::Description::get()
{
    System::Diagnostics::Debug::Assert(NativeID3D11Counter != NULL);

    D3D11_COUNTER_DESC* tempoutDescription = new D3D11_COUNTER_DESC();
    NativeID3D11Counter->GetDesc(tempoutDescription);

    return gcnew CounterDescription(tempoutDescription);
}

