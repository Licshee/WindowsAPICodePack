// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "DXGISwapChain.h"
#include "DXGIOutput.h"

using namespace Microsoft::WindowsAPICodePack::DirectX::DXGI;

generic <typename T> 
T SwapChain::GetBuffer(UInt32 BufferIndex)
{
    GUID guid = D3DUtils::GetGuid(T::typeid);
    void* tempoutSurface = NULL;

    D3DUtils::VerifyResult(NativeIDXGISwapChain->GetBuffer(safe_cast<UINT>(BufferIndex), guid, &tempoutSurface));

    return safe_cast<T>(D3DUtils::CreateObjectFromPointer<T>(tempoutSurface));
}

Output^ SwapChain::ClientOutput::get()
{
    System::Diagnostics::Debug::Assert(NativeIDXGISwapChain != NULL);

    IDXGIOutput* tempoutOutput;
    D3DUtils::VerifyResult(NativeIDXGISwapChain->GetContainingOutput(&tempoutOutput));

    return (tempoutOutput == NULL ? nullptr : gcnew Output(tempoutOutput));

}

SwapChainDescription^ SwapChain::Description::get()
{
    System::Diagnostics::Debug::Assert(NativeIDXGISwapChain != NULL);

    DXGI_SWAP_CHAIN_DESC* tempoutDescription = new DXGI_SWAP_CHAIN_DESC();
    D3DUtils::VerifyResult(NativeIDXGISwapChain->GetDesc(tempoutDescription));
    return (tempoutDescription == NULL ? nullptr : gcnew SwapChainDescription(tempoutDescription));

}

FrameStatistics^ SwapChain::LastRenderFrameStatistics::get()
{
    System::Diagnostics::Debug::Assert(NativeIDXGISwapChain != NULL);

    DXGI_FRAME_STATISTICS* tempoutStats = new DXGI_FRAME_STATISTICS();
    D3DUtils::VerifyResult(NativeIDXGISwapChain->GetFrameStatistics(tempoutStats));
    
    return  (tempoutStats == NULL ? nullptr : gcnew FrameStatistics(tempoutStats));

}

bool SwapChain::GetFullScreenState([Runtime::InteropServices::Out] Output^ %outTarget)
{
    System::Diagnostics::Debug::Assert(NativeIDXGISwapChain != NULL);

    BOOL tempoutFullscreen;
    IDXGIOutput* tempoutTarget = NULL;
    
    D3DUtils::VerifyResult(NativeIDXGISwapChain->GetFullscreenState(&tempoutFullscreen, &tempoutTarget));
    
    outTarget = (tempoutTarget == NULL ? nullptr : gcnew Output(tempoutTarget));

    return tempoutFullscreen != 0;
}

bool SwapChain::IsFullScreen::get()
{
    System::Diagnostics::Debug::Assert(NativeIDXGISwapChain != NULL);

    BOOL tempoutFullscreen;
    IDXGIOutput* tempoutTarget;
    
    D3DUtils::VerifyResult(NativeIDXGISwapChain->GetFullscreenState(&tempoutFullscreen, &tempoutTarget));
    
    return tempoutFullscreen != 0;
}

UInt32 SwapChain::LastPresentCount::get()
{
    System::Diagnostics::Debug::Assert(NativeIDXGISwapChain != NULL);

    UINT tempoutLastPresentCount;
    D3DUtils::VerifyResult(NativeIDXGISwapChain->GetLastPresentCount(&tempoutLastPresentCount));
    return safe_cast<UInt32>(tempoutLastPresentCount);

}

void SwapChain::Present(UInt32 SyncInterval, PresentFlag Flags)
{
    System::Diagnostics::Debug::Assert(NativeIDXGISwapChain != NULL);

    D3DUtils::VerifyResult(NativeIDXGISwapChain->Present(safe_cast<UINT>(SyncInterval), safe_cast<UINT>(Flags)));
}

bool SwapChain::TryPresent(UInt32 SyncInterval, PresentFlag Flags, [Runtime::InteropServices::Out] ErrorCode % error)
{
    System::Diagnostics::Debug::Assert(NativeIDXGISwapChain != NULL);

    HRESULT hr = NativeIDXGISwapChain->Present(safe_cast<UINT>(SyncInterval), safe_cast<UINT>(Flags));

    error = safe_cast<ErrorCode>(hr);

    return SUCCEEDED(hr);
}

void SwapChain::ResizeBuffers(UInt32 BufferCount, UInt32 Width, UInt32 Height, Format NewFormat, SwapChainFlag SwapChainFlags)
{
    System::Diagnostics::Debug::Assert(NativeIDXGISwapChain != NULL);

    D3DUtils::VerifyResult(NativeIDXGISwapChain->ResizeBuffers(safe_cast<UINT>(BufferCount), safe_cast<UINT>(Width), safe_cast<UINT>(Height), safe_cast<DXGI_FORMAT>(NewFormat), safe_cast<UINT>(SwapChainFlags)));
}

void SwapChain::ResizeTarget(ModeDescription^ NewTargetParameters)
{
    System::Diagnostics::Debug::Assert(NativeIDXGISwapChain != NULL);

    D3DUtils::VerifyResult(NativeIDXGISwapChain->ResizeTarget(NewTargetParameters->nativeObject.Get()));
}

void SwapChain::SetFullscreenState(Boolean Fullscreen, Output^ Target)
{
    System::Diagnostics::Debug::Assert(NativeIDXGISwapChain != NULL);

    D3DUtils::VerifyResult(NativeIDXGISwapChain->SetFullscreenState(safe_cast<BOOL>(Fullscreen), Target == nullptr ? NULL : Target->NativeIDXGIOutput));
}

