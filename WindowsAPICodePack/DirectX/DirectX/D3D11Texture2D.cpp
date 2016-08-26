// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "D3D11Texture2D.h"

using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D11;

Texture2dDescription^ Texture2D::Description::get()
{
    System::Diagnostics::Debug::Assert(NativeID3D11Texture2D != NULL);

    D3D11_TEXTURE2D_DESC* tempoutDescription = new D3D11_TEXTURE2D_DESC();
    NativeID3D11Texture2D->GetDesc(tempoutDescription);

    return gcnew Texture2dDescription(tempoutDescription);
}

