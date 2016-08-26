// Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once
#include "DirectObject.h"
namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3DCommon {

/// <summary>
/// Base class for all classes supporting internal IUnknown interfaces
/// </summary>
public ref class DirectUnknown abstract
{
public protected:
    AutoIUnknown<IUnknown> nativeUnknown;

internal:
    DirectUnknown(void) {}
    DirectUnknown(void* ptr) {nativeUnknown.Set((IUnknown*)ptr);}

public:
    property IntPtr NatriveInterface
    {
        IntPtr get()
        {
            return IntPtr(nativeUnknown.Get());
        }
    }
};

}}}}
