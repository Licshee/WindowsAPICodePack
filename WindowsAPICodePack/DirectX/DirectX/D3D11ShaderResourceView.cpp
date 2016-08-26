// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "D3D11ShaderResourceView.h"

using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D11;

ShaderResourceViewDescription^ ShaderResourceView::Description::get()
{
    System::Diagnostics::Debug::Assert(NativeID3D11ShaderResourceView != NULL);

    D3D11_SHADER_RESOURCE_VIEW_DESC* tempoutDescription = new D3D11_SHADER_RESOURCE_VIEW_DESC();
    NativeID3D11ShaderResourceView->GetDesc(tempoutDescription);

    return gcnew ShaderResourceViewDescription(tempoutDescription);

}

