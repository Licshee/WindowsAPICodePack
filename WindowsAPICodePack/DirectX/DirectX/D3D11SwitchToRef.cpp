// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "D3D11SwitchToRef.h"

using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D11;

Boolean SwitchToRef::GetUseRef()
{
    System::Diagnostics::Debug::Assert(NativeID3D11SwitchToRef != NULL);

    BOOL returnValue = NativeID3D11SwitchToRef->GetUseRef();
    return returnValue != 0;

}

Boolean SwitchToRef::SetUseRef(Boolean UseRef)
{
    System::Diagnostics::Debug::Assert(NativeID3D11SwitchToRef != NULL);

    BOOL returnValue = NativeID3D11SwitchToRef->SetUseRef(safe_cast<BOOL>(UseRef));
    return returnValue != 0;

}

