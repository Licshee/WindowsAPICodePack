// Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once

#include "AutoPointer.h"

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3DCommon {

/// <summary>
/// An Auto pointer styled class supporting an IUnknown interface
/// Reserved for internal use only.
/// </summary>
template <typename T>
public ref struct AutoIUnknown : AutoPointer<T>
{
public protected:
    AutoIUnknown() : AutoPointer<T>::AutoPointer()  {}
    AutoIUnknown(T* target) : AutoPointer<T>::AutoPointer(target){}

    virtual void DisposeTarget() override
    {
        if (isDeletable && targetPointer != 0)
        {
            targetPointer->Release();
            targetPointer = 0; // Make sure it's not accessed again
        }
    }
    
};
}}}}
