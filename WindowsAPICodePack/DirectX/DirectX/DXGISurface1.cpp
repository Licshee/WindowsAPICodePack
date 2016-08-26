// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "DXGISurface1.h"

using namespace Microsoft::WindowsAPICodePack::DirectX::DXGI;

IntPtr Surface1::GetDC(Boolean Discard)
{
    System::Diagnostics::Debug::Assert(NativeIDXGISurface1 != NULL);

    HDC tempouthdc;
    D3DUtils::VerifyResult(NativeIDXGISurface1->GetDC(safe_cast<BOOL>(Discard), &tempouthdc));
    
    return IntPtr(tempouthdc);
}

void Surface1::ReleaseDC(D3dRect^ DirtyRect)
{
    System::Diagnostics::Debug::Assert(NativeIDXGISurface1 != NULL);

    D3DUtils::VerifyResult(NativeIDXGISurface1->ReleaseDC(DirtyRect->nativeObject.Get()));
}

