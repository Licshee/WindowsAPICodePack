// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "D3D11SamplerState.h"

using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D11;

SamplerDescription^ SamplerState::Description::get()
{
    System::Diagnostics::Debug::Assert(NativeID3D11SamplerState != NULL);

    D3D11_SAMPLER_DESC* tempoutDescription = new D3D11_SAMPLER_DESC();
    NativeID3D11SamplerState->GetDesc(tempoutDescription);

    return gcnew SamplerDescription(tempoutDescription);

}

