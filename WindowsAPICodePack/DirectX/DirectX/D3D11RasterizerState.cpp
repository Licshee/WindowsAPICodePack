// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "D3D11RasterizerState.h"

using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D11;

RasterizerDescription^ RasterizerState::Description::get()
{
    System::Diagnostics::Debug::Assert(NativeID3D11RasterizerState != NULL);

    D3D11_RASTERIZER_DESC* tempoutDescription = new D3D11_RASTERIZER_DESC();
    NativeID3D11RasterizerState->GetDesc(tempoutDescription);
    
    return gcnew RasterizerDescription(tempoutDescription);
}

