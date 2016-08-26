// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "DXGIOutput.h"
#include "DXGISurface.h"
#include "D3DDeviceBase.h"
#include "Direct3DList.h"

using namespace System::Collections::Generic;
using namespace System::Collections::ObjectModel;
using namespace Microsoft::WindowsAPICodePack::DirectX::DXGI;

using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3DCommon;

ModeDescription^ Output::FindClosestMatchingMode(ModeDescription^ ModeToMatch, D3DDeviceBase^ ConcernedDevice)
{
    System::Diagnostics::Debug::Assert(NativeIDXGIOutput != NULL);

    DXGI_MODE_DESC* tempoutClosestMatch = new DXGI_MODE_DESC();
    D3DUtils::VerifyResult(NativeIDXGIOutput->FindClosestMatchingMode(
        ModeToMatch->nativeObject.Get(), tempoutClosestMatch, (ConcernedDevice == nullptr ? NULL : ConcernedDevice->NativeDevice)));
    return gcnew ModeDescription(tempoutClosestMatch);
}

ModeDescription^ Output::FindClosestMatchingMode(ModeDescription^ ModeToMatch)
{
    System::Diagnostics::Debug::Assert(NativeIDXGIOutput != NULL);

    DXGI_MODE_DESC* tempoutClosestMatch = new DXGI_MODE_DESC();
    D3DUtils::VerifyResult(NativeIDXGIOutput->FindClosestMatchingMode(ModeToMatch->nativeObject.Get(), tempoutClosestMatch, NULL));
    
    return gcnew ModeDescription(tempoutClosestMatch);
}

UInt32 Output::GetNumberOfDisplayModes(Format EnumFormat, EnumModes Flags)
{
    System::Diagnostics::Debug::Assert(NativeIDXGIOutput != NULL);

    UINT outNumModes = 0;

    D3DUtils::VerifyResult(
        NativeIDXGIOutput->GetDisplayModeList(
        safe_cast<DXGI_FORMAT>(EnumFormat), safe_cast<UINT>(Flags), &outNumModes, NULL));

    return outNumModes;
}

ReadOnlyCollection<ModeDescription^>^ Output::GetDisplayModeList(Format EnumFormat, EnumModes Flags)
{
    System::Diagnostics::Debug::Assert(NativeIDXGIOutput != NULL);

    UINT outNumModes = GetNumberOfDisplayModes(EnumFormat, Flags);

    DXGI_MODE_DESC* pDesc = new DXGI_MODE_DESC[outNumModes];

    D3DUtils::VerifyResult(
        NativeIDXGIOutput->GetDisplayModeList(
        safe_cast<DXGI_FORMAT>(EnumFormat), safe_cast<UINT>(Flags), &outNumModes, pDesc));
    
    IList<ModeDescription^>^ list = gcnew List<ModeDescription^>();
        
    for (UINT i = 0; i < outNumModes; i++)
    {
        list->Add(gcnew ModeDescription(&(pDesc[i]), false));
    }
    
    return gcnew Direct3DList<ModeDescription^>(pDesc, true, list);
}


OutputDescription^ Output::Description::get()
{
    if (m_description == nullptr)
    {
        System::Diagnostics::Debug::Assert(NativeIDXGIOutput != NULL);

        DXGI_OUTPUT_DESC* tempoutDescription = new DXGI_OUTPUT_DESC();
        ZeroMemory(tempoutDescription, sizeof(DXGI_OUTPUT_DESC));
        D3DUtils::VerifyResult(NativeIDXGIOutput->GetDesc(tempoutDescription));
        m_description =  gcnew OutputDescription(tempoutDescription);
    }
    return m_description;
}



void Output::GetDisplaySurfaceData(Surface^ Destination)
{
    System::Diagnostics::Debug::Assert(NativeIDXGIOutput != NULL);

    D3DUtils::VerifyResult(NativeIDXGIOutput->GetDisplaySurfaceData(Destination->NativeIDXGISurface));
}

FrameStatistics^ Output::RenderedFrameStatistics::get()
{
    System::Diagnostics::Debug::Assert(NativeIDXGIOutput != NULL);

    DXGI_FRAME_STATISTICS* tempoutStats = new DXGI_FRAME_STATISTICS();
    ZeroMemory(tempoutStats, sizeof(DXGI_FRAME_STATISTICS));
    D3DUtils::VerifyResult(NativeIDXGIOutput->GetFrameStatistics(tempoutStats));
    
    return gcnew FrameStatistics(tempoutStats);

}

GammaControl^ Output::GammaControlSettings::get()
{
    System::Diagnostics::Debug::Assert(NativeIDXGIOutput != NULL);

    DXGI_GAMMA_CONTROL* tempGamaControl = new DXGI_GAMMA_CONTROL();
    ZeroMemory(tempGamaControl, sizeof(DXGI_GAMMA_CONTROL));
    D3DUtils::VerifyResult(NativeIDXGIOutput->GetGammaControl(tempGamaControl));

    return gcnew GammaControl(tempGamaControl);
}

void Output::GammaControlSettings::set(GammaControl^ value)
{
    System::Diagnostics::Debug::Assert(NativeIDXGIOutput != NULL);

    if (value == nullptr)
        throw gcnew ArgumentNullException("value");

    D3DUtils::VerifyResult(NativeIDXGIOutput->SetGammaControl(value->nativeObject.Get()));
}

GammaControlCapabilities^ Output::GammaControlCaps::get()
{
    System::Diagnostics::Debug::Assert(NativeIDXGIOutput != NULL);

    DXGI_GAMMA_CONTROL_CAPABILITIES* tempoutGammaCaps = new DXGI_GAMMA_CONTROL_CAPABILITIES();
    ZeroMemory(tempoutGammaCaps, sizeof(DXGI_GAMMA_CONTROL_CAPABILITIES));
    D3DUtils::VerifyResult(NativeIDXGIOutput->GetGammaControlCapabilities(tempoutGammaCaps));

    return tempoutGammaCaps == NULL ? nullptr : gcnew GammaControlCapabilities(tempoutGammaCaps);
}

void Output::SetDisplaySurface(Surface^ ScanoutSurface)
{
    System::Diagnostics::Debug::Assert(NativeIDXGIOutput != NULL);

    D3DUtils::VerifyResult(NativeIDXGIOutput->SetDisplaySurface(ScanoutSurface->NativeIDXGISurface));

}

void Output::ReleaseOwnership()
{
    System::Diagnostics::Debug::Assert(NativeIDXGIOutput != NULL);

    NativeIDXGIOutput->ReleaseOwnership();

}


void Output::TakeOwnership(D3DDeviceBase^ device, Boolean exclusive)
{
    System::Diagnostics::Debug::Assert(NativeIDXGIOutput != NULL);

    D3DUtils::VerifyResult(NativeIDXGIOutput->TakeOwnership(device->NativeDevice, safe_cast<BOOL>(exclusive)));
}

void Output::WaitForVBlank()
{
    System::Diagnostics::Debug::Assert(NativeIDXGIOutput != NULL);

    D3DUtils::VerifyResult(NativeIDXGIOutput->WaitForVBlank());
}

