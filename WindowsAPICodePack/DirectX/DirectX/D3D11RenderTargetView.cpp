// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "D3D11RenderTargetView.h"

using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D11;

RenderTargetViewDescription^ RenderTargetView::Description::get()
{
    System::Diagnostics::Debug::Assert(NativeID3D11RenderTargetView != NULL);

    D3D11_RENDER_TARGET_VIEW_DESC* tempoutDescription = new D3D11_RENDER_TARGET_VIEW_DESC();
    NativeID3D11RenderTargetView->GetDesc(tempoutDescription);


    return gcnew RenderTargetViewDescription(tempoutDescription);
}

