// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "D3D11CommandList.h"

using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D11;

UInt32 CommandList::ContextFlags::get()
{
    System::Diagnostics::Debug::Assert(NativeID3D11CommandList != NULL);

    UINT returnValue = NativeID3D11CommandList->GetContextFlags();
    
    return safe_cast<UInt32>(returnValue);

}

