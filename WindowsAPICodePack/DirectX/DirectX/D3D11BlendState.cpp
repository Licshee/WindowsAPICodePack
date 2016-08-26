// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "D3D11BlendState.h"

using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D11;

BlendDescription^ BlendState::Description::get()
{
    System::Diagnostics::Debug::Assert(NativeID3D11BlendState != NULL);

    D3D11_BLEND_DESC* tempoutDescription = new D3D11_BLEND_DESC();
    NativeID3D11BlendState->GetDesc(tempoutDescription);

    return gcnew BlendDescription(tempoutDescription);

}

