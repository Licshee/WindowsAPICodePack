// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "DXGIAdapter1.h"

using namespace Microsoft::WindowsAPICodePack::DirectX::DXGI;


AdapterDescription1^ Adapter1::Description1::get()
{
    if (m_description1 == nullptr)
    {
        System::Diagnostics::Debug::Assert(NativeIDXGIAdapter1 != NULL);

        DXGI_ADAPTER_DESC1* tempoutDescription = new DXGI_ADAPTER_DESC1();
        D3DUtils::VerifyResult(NativeIDXGIAdapter1->GetDesc1(tempoutDescription));
        m_description1 =  gcnew AdapterDescription1(tempoutDescription);
    }
    return m_description1;
}

