// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "DXGISurface.h"

using namespace Microsoft::WindowsAPICodePack::DirectX::DXGI;

SurfaceDescription^ Surface::Description::get()
{
    System::Diagnostics::Debug::Assert(NativeIDXGISurface != NULL);

    DXGI_SURFACE_DESC* tempoutDescription = new DXGI_SURFACE_DESC();
    D3DUtils::VerifyResult(NativeIDXGISurface->GetDesc(tempoutDescription));
    
    return gcnew SurfaceDescription(tempoutDescription);
}

MappedRect^ Surface::MapResource(MapFlags Flags)
{
    System::Diagnostics::Debug::Assert(NativeIDXGISurface != NULL);

    DXGI_MAPPED_RECT* tempoutLockedRect = new DXGI_MAPPED_RECT();
    D3DUtils::VerifyResult(NativeIDXGISurface->Map(tempoutLockedRect, safe_cast<UINT>(Flags)));
    
    return  tempoutLockedRect == NULL ? nullptr : gcnew MappedRect(tempoutLockedRect);
}

void Surface::Unmap()
{
    System::Diagnostics::Debug::Assert(NativeIDXGISurface != NULL);

    D3DUtils::VerifyResult(NativeIDXGISurface->Unmap());
}

