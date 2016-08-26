// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "D3D11ClassLinkage.h"

#include "D3D11ClassInstance.h"
using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D11;

ClassInstance^ ClassLinkage::CreateClassInstance(String^ szClassTypeName, UInt32 ConstantBufferOffset, UInt32 ConstantVectorOffset, UInt32 TextureOffset, UInt32 SamplerOffset)
{
    System::Diagnostics::Debug::Assert(NativeID3D11ClassLinkage != NULL);
    D3DUtils::CheckNull(szClassTypeName,"szClassTypeName");

    ID3D11ClassInstance* tempoutInstance = NULL;
    char* tempszClassTypeName = D3DUtils::CharArrayfromSystemString(szClassTypeName);
    try
    {
        D3DUtils::VerifyResult(NativeID3D11ClassLinkage->CreateClassInstance(tempszClassTypeName, safe_cast<UINT>(ConstantBufferOffset), safe_cast<UINT>(ConstantVectorOffset), safe_cast<UINT>(TextureOffset), safe_cast<UINT>(SamplerOffset), &tempoutInstance));
        return gcnew ClassInstance(tempoutInstance);
    }
    finally
    {
        Marshal::FreeHGlobal(IntPtr(tempszClassTypeName));
    }

}

ClassInstance^ ClassLinkage::GetClassInstance(String^ ClassInstanceName, UInt32 InstanceIndex)
{
    System::Diagnostics::Debug::Assert(NativeID3D11ClassLinkage != NULL);
    D3DUtils::CheckNull(ClassInstanceName,"ClassInstanceName");

    ID3D11ClassInstance* tempoutInstance = NULL;
    char* tempClassInstanceName = D3DUtils::CharArrayfromSystemString(ClassInstanceName);
    
    try
    {
        D3DUtils::VerifyResult(NativeID3D11ClassLinkage->GetClassInstance(tempClassInstanceName, safe_cast<UINT>(InstanceIndex), &tempoutInstance));
        return gcnew ClassInstance(tempoutInstance);
    }
    finally
    {
        Marshal::FreeHGlobal(IntPtr(tempClassInstanceName));
    }

}

