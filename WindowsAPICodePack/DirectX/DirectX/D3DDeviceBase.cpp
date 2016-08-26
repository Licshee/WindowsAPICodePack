//Copyright (c) Microsoft Corporation.  All rights reserved.

#include "StdAfx.h"
#include "D3DDeviceBase.h"
#include "DXGIDevice.h"

DXGIDevice^ D3DDeviceBase::GetDXGIDevice() 
{
    IDXGIDevice * pDXGIDevice = NULL;
    D3DUtils::VerifyResult(NativeDevice->QueryInterface(__uuidof(IDXGIDevice), (void **)&pDXGIDevice));

    return pDXGIDevice == NULL ? nullptr : gcnew DXGIDevice(pDXGIDevice);
}
