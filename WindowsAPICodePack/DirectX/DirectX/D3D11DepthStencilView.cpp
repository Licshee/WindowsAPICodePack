// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "D3D11DepthStencilView.h"

using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D11;
using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D11;


DepthStencilViewDescription^ DepthStencilView::Description::get()
{
    System::Diagnostics::Debug::Assert(NativeID3D11DepthStencilView != NULL);

    D3D11_DEPTH_STENCIL_VIEW_DESC* tempoutDescription = new D3D11_DEPTH_STENCIL_VIEW_DESC();
    NativeID3D11DepthStencilView->GetDesc(tempoutDescription);

    return gcnew DepthStencilViewDescription(tempoutDescription);
}

