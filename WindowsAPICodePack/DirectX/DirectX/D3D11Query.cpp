// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "D3D11Query.h"

using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D11;

QueryDescription^ D3DQuery::Description::get()
{
    System::Diagnostics::Debug::Assert(NativeID3D11Query != NULL);

    D3D11_QUERY_DESC* tempoutDescription = new D3D11_QUERY_DESC();
    NativeID3D11Query->GetDesc(tempoutDescription);

    return gcnew QueryDescription(tempoutDescription);
}

