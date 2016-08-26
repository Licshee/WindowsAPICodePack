// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "DXGIDeviceSubObject.h"

#include "DXGIDevice.h"
#include "D3D11Device.h"

using namespace Microsoft::WindowsAPICodePack::DirectX::DXGI;


Microsoft::WindowsAPICodePack::DirectX::Direct3D11::D3DDevice^ DeviceSubObject::GetDirect3D11Device()
{
    System::Diagnostics::Debug::Assert(NativeIDXGIDeviceSubObject != NULL);

    ID3D11Device* tempoutDevice = NULL;

    D3DUtils::VerifyResult(NativeIDXGIDeviceSubObject->GetDevice(__uuidof(tempoutDevice), (void**)&tempoutDevice));

    return tempoutDevice == NULL ? nullptr : gcnew Microsoft::WindowsAPICodePack::DirectX::Direct3D11::D3DDevice(tempoutDevice);
}

Microsoft::WindowsAPICodePack::DirectX::DXGI::DXGIDevice^ DeviceSubObject::GetDXGIDevice()
{
    System::Diagnostics::Debug::Assert(NativeIDXGIDeviceSubObject != NULL);

    IDXGIDevice* tempoutDevice;

    D3DUtils::VerifyResult(NativeIDXGIDeviceSubObject->GetDevice(__uuidof(tempoutDevice), (void**)&tempoutDevice));

    return tempoutDevice == NULL ? nullptr : gcnew Microsoft::WindowsAPICodePack::DirectX::DXGI::DXGIDevice(tempoutDevice);
}

