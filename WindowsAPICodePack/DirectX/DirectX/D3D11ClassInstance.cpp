// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "D3D11ClassInstance.h"

#include "D3D11ClassLinkage.h"
using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D11;

ClassLinkage^ ClassInstance::CurrentClassLinkage::get()
{
    System::Diagnostics::Debug::Assert(NativeID3D11ClassInstance != NULL);

    ID3D11ClassLinkage* tempoutLinkage = NULL;
    NativeID3D11ClassInstance->GetClassLinkage(&tempoutLinkage);

    return tempoutLinkage == NULL ? nullptr : gcnew ClassLinkage(tempoutLinkage);
}

ClassInstanceDescription^ ClassInstance::Description::get()
{
    System::Diagnostics::Debug::Assert(NativeID3D11ClassInstance != NULL);

    D3D11_CLASS_INSTANCE_DESC* tempoutDescription = new D3D11_CLASS_INSTANCE_DESC();
    NativeID3D11ClassInstance->GetDesc(tempoutDescription);

    return gcnew ClassInstanceDescription(tempoutDescription);
}

String^ ClassInstance::InstanceName::get()
{
    System::Diagnostics::Debug::Assert(NativeID3D11ClassInstance != NULL);

    SIZE_T len = D3DUtils::MaxNameSize;
    LPSTR tempInstanceName = new char[D3DUtils::MaxNameSize];

    NativeID3D11ClassInstance->GetInstanceName(tempInstanceName, &len);

    String^ name = gcnew String(tempInstanceName);
    delete [] tempInstanceName;

    return name;
}

String^ ClassInstance::TypeName::get()
{
    System::Diagnostics::Debug::Assert(NativeID3D11ClassInstance != NULL);

    SIZE_T len = D3DUtils::MaxNameSize;
    LPSTR tempTypeName = new char[D3DUtils::MaxNameSize];

    NativeID3D11ClassInstance->GetInstanceName(tempTypeName, &len);

    String^ name = gcnew String(tempTypeName);
    delete [] tempTypeName;

    return name;
}

