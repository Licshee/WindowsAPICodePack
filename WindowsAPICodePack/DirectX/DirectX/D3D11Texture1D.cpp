// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "D3D11Texture1D.h"

using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D11;

Texture1dDescription^ Texture1D::Description::get()
{
    System::Diagnostics::Debug::Assert(NativeID3D11Texture1D != NULL);

    D3D11_TEXTURE1D_DESC* tempoutDescription = new D3D11_TEXTURE1D_DESC();
    NativeID3D11Texture1D->GetDesc(tempoutDescription);

    return gcnew Texture1dDescription(tempoutDescription);
}

