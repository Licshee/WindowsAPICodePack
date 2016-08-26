// Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3DCommon {

/// <summary>
/// Base class for all classes supporting internal Direct3D objects
/// </summary>
public ref class DirectObject abstract
{
public protected:
    AutoPointer<void> nativeObject;

internal:
    DirectObject(void) {}
    virtual ~DirectObject(void) {}

};

}}}}
