// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "D3D11Resource.h"

using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D11;

UInt32 D3DResource::EvictionPriority::get()
{
    System::Diagnostics::Debug::Assert(NativeID3D11Resource != NULL);

    return safe_cast<UInt32>(NativeID3D11Resource->GetEvictionPriority());
}

void D3DResource::EvictionPriority::set(UInt32 value)
{
    System::Diagnostics::Debug::Assert(NativeID3D11Resource != NULL);

    NativeID3D11Resource->SetEvictionPriority(safe_cast<UINT>(value));
}

ResourceDimension D3DResource::ResourceType::get()
{
    System::Diagnostics::Debug::Assert(NativeID3D11Resource != NULL);

    D3D11_RESOURCE_DIMENSION tempoutrType = D3D11_RESOURCE_DIMENSION_UNKNOWN;

    NativeID3D11Resource->GetType(&tempoutrType);

    return safe_cast<ResourceDimension>(tempoutrType);
}



