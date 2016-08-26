// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "D3D11Texture3D.h"

using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D11;

Texture3dDescription^ Texture3D::Description::get()
{
    System::Diagnostics::Debug::Assert(NativeID3D11Texture3D != NULL);

    D3D11_TEXTURE3D_DESC* tempoutDescription = new D3D11_TEXTURE3D_DESC();
    NativeID3D11Texture3D->GetDesc(tempoutDescription);

    return gcnew Texture3dDescription(tempoutDescription);
}

