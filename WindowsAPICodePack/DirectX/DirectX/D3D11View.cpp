// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "D3D11View.h"

#include "D3D11Resource.h"
using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D11;

D3DResource^ View::Resource::get()
{
    System::Diagnostics::Debug::Assert(NativeID3D11View != NULL);

    ID3D11Resource* tempoutResource = NULL;
    NativeID3D11View->GetResource(&tempoutResource);

    return tempoutResource == NULL ? nullptr  : gcnew D3DResource(tempoutResource);

}

