// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "DXGIDevice1.h"

using namespace Microsoft::WindowsAPICodePack::DirectX::DXGI;

UInt32 DXGIDevice1::MaximumFrameLatency::get()
{
    System::Diagnostics::Debug::Assert(NativeIDXGIDevice1 != NULL);

    UINT tempoutMaxLatency;
    D3DUtils::VerifyResult(NativeIDXGIDevice1->GetMaximumFrameLatency(&tempoutMaxLatency));
    return safe_cast<UInt32>(tempoutMaxLatency);

}

void DXGIDevice1::MaximumFrameLatency::set(UInt32 value)
{
    System::Diagnostics::Debug::Assert(NativeIDXGIDevice1 != NULL);

    D3DUtils::VerifyResult(NativeIDXGIDevice1->SetMaximumFrameLatency(safe_cast<UINT>(value)));

}

