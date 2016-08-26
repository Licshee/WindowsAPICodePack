// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "D3D11Debug.h"

#include "DXGISwapChain.h"
#include "D3D11DeviceContext.h"
using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D11;
using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D11;

using namespace Microsoft::WindowsAPICodePack::DirectX::DXGI;
using namespace Microsoft::WindowsAPICodePack::DirectX::DXGI;


DebugFeature D3DDebug::FeatureMask::get()
{
    System::Diagnostics::Debug::Assert(NativeID3D11Debug != NULL);

    return safe_cast<DebugFeature>(NativeID3D11Debug->GetFeatureMask());
}

UInt32 D3DDebug::PresentPerRenderOpDelay::get()
{
    System::Diagnostics::Debug::Assert(NativeID3D11Debug != NULL);

    UINT returnValue = NativeID3D11Debug->GetPresentPerRenderOpDelay();
    return safe_cast<UInt32>(returnValue);
}

SwapChain^ D3DDebug::RuntimeSwapChain::get()
{
    System::Diagnostics::Debug::Assert(NativeID3D11Debug != NULL);

    IDXGISwapChain* tempoutSwapChain = NULL;
    D3DUtils::VerifyResult(NativeID3D11Debug->GetSwapChain(&tempoutSwapChain));
    
    return gcnew SwapChain(tempoutSwapChain);
}

void D3DDebug::ValidateContext(DeviceContext^ Context)
{
    System::Diagnostics::Debug::Assert(NativeID3D11Debug != NULL);

    D3DUtils::VerifyResult(NativeID3D11Debug->ValidateContext(Context->NativeID3D11DeviceContext));
}

void D3DDebug::FeatureMask::set(DebugFeature value)
{
    System::Diagnostics::Debug::Assert(NativeID3D11Debug != NULL);

    D3DUtils::VerifyResult(NativeID3D11Debug->SetFeatureMask(safe_cast<UINT>(value)));
}

void D3DDebug::PresentPerRenderOpDelay::set(UInt32 value)
{
    System::Diagnostics::Debug::Assert(NativeID3D11Debug != NULL);

    D3DUtils::VerifyResult(NativeID3D11Debug->SetPresentPerRenderOpDelay(safe_cast<UINT>(value)));
}

void D3DDebug::RuntimeSwapChain::set(SwapChain^ value)
{
    System::Diagnostics::Debug::Assert(NativeID3D11Debug != NULL);

    D3DUtils::VerifyResult(NativeID3D11Debug->SetSwapChain(value->NativeIDXGISwapChain));
}

