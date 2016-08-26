// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "D3D11DepthStencilState.h"

using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D11;
using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D11;

DepthStencilDescription^ DepthStencilState::Description::get()
{
    System::Diagnostics::Debug::Assert(NativeID3D11DepthStencilState != NULL);

    D3D11_DEPTH_STENCIL_DESC* tempoutDescription = new D3D11_DEPTH_STENCIL_DESC();
    NativeID3D11DepthStencilState->GetDesc(tempoutDescription);


    return gcnew DepthStencilDescription(tempoutDescription);
}

