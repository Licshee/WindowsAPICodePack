// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "DXGIAdapter.h"
#include "DXGIOutput.h"

using namespace Microsoft::WindowsAPICodePack::DirectX::DXGI;
using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3DCommon;
using namespace System::Collections::Generic;

bool Adapter::CheckDeviceSupport(DeviceType deviceType)
{
    Int32 high, low;
    return CheckDeviceSupport(deviceType, high, low);
}

bool Adapter::CheckDeviceSupport(
            DeviceType deviceType, 
            [Runtime::InteropServices::Out] Int32 %UMDVersionMajor, 
            [Runtime::InteropServices::Out] Int32 %UMDVersionMinor )
{
    System::Diagnostics::Debug::Assert(NativeIDXGIAdapter != NULL);

    LARGE_INTEGER tempoutUMDVersion;
    GUID interfaceGuid;

    switch (deviceType)
    {
        case DeviceType::Direct3D_10_0:
            interfaceGuid = __uuidof(ID3D10Device);
            break;
        case DeviceType::Direct3D_10_1:
            interfaceGuid = __uuidof(ID3D10Device1);
            break;
        case DeviceType::Direct3D_11_0:
            interfaceGuid = __uuidof(ID3D11Device);
            break;
        default:
            throw gcnew ArgumentOutOfRangeException("Device type not supported.", "deviceType");
    }


    if (!SUCCEEDED(NativeIDXGIAdapter->CheckInterfaceSupport(interfaceGuid, &tempoutUMDVersion)))
    {
        UMDVersionMajor = UMDVersionMinor = 0;
        return false;
    }
    else
    {
        UMDVersionMajor = tempoutUMDVersion.HighPart;
        UMDVersionMinor = tempoutUMDVersion.LowPart;
        return true;
    }
}

CachedCollection<Output^>^ Adapter::OutputsCache::get()
{
    System::Diagnostics::Debug::Assert(NativeIDXGIAdapter != NULL);

    if (outputsCache == nullptr)
    {
        outputsCache = gcnew CachedCollection<Output^>();
    }

    if (!outputsCache->IsValid)
    {
        int i = 0;
        while (true)
        {
            IDXGIOutput* tempoutOutput;

            if (DXGI_ERROR_NOT_FOUND != NativeIDXGIAdapter->EnumOutputs(i++, &tempoutOutput))
                outputsCache->InternalAdd(gcnew Output(tempoutOutput));
            else
                break;
        }
        outputsCache->IsValid = true;
    }

    return outputsCache;
}

AdapterDescription^ Adapter::Description::get()
{
    if (m_description == nullptr)
    {
        System::Diagnostics::Debug::Assert(NativeIDXGIAdapter != NULL);

        DXGI_ADAPTER_DESC* tempoutDescription = new DXGI_ADAPTER_DESC();
        D3DUtils::VerifyResult(NativeIDXGIAdapter->GetDesc(tempoutDescription));
        m_description  = gcnew AdapterDescription(tempoutDescription);
    }
    return m_description;
}

