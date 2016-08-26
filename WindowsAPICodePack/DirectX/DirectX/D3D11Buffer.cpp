// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "D3D11Buffer.h"

using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D11;

BufferDescription^ D3DBuffer::Description::get()
{
    System::Diagnostics::Debug::Assert(NativeID3D11Buffer != NULL);

    D3D11_BUFFER_DESC* tempoutDescription = new D3D11_BUFFER_DESC();
    NativeID3D11Buffer->GetDesc(tempoutDescription);

    return gcnew BufferDescription(tempoutDescription);

}

