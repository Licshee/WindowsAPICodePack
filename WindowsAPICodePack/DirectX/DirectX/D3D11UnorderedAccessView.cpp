// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "D3D11UnorderedAccessView.h"

using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D11;

UnorderedAccessViewDescription^ UnorderedAccessView::Description::get()
{
    System::Diagnostics::Debug::Assert(NativeID3D11UnorderedAccessView != NULL);

    D3D11_UNORDERED_ACCESS_VIEW_DESC* tempoutDescription = new D3D11_UNORDERED_ACCESS_VIEW_DESC();
    NativeID3D11UnorderedAccessView->GetDesc(tempoutDescription);

    return gcnew UnorderedAccessViewDescription(tempoutDescription);

}

