// Copyright (c) Microsoft Corporation.  All rights reserved.

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3DCommon {
#pragma once

/// <summary>
/// An auto pointer style class supporting a simple void pointer
/// Reserved for internal use only.
/// </summary>
template <typename T>
public ref struct AutoPointer
{
public protected:
    AutoPointer() : targetPointer(0), isDeletable(true), isArray(false)  { }
    AutoPointer(T* target) : targetPointer(target), isDeletable(true), isArray(false) {}

    void Set(T* target)
    {
        targetPointer = target;
    }

    void Set(T* target, bool deletable)
    {
        targetPointer = target;
        isDeletable = deletable;
    }

    void SetArray(T* target, bool deletable)
    {
        targetPointer = target;
        isDeletable = deletable;
        isArray = true;
    }

    T* operator->()
    {
        System::Diagnostics::Debug::Assert(0 != targetPointer);
        return targetPointer;
    }

    T* Get()
    {
        return targetPointer;
    }

    virtual void DisposeTarget()
    {
        if (isDeletable && targetPointer != 0)
        {
            if (isArray)
                delete [] targetPointer;
            else
                delete targetPointer;

            targetPointer = 0;
        }
    }

    virtual ~AutoPointer()
    {
        AutoPointer::!AutoPointer();
    }
    
    !AutoPointer()
    {
        DisposeTarget();
    }

protected:
    T* targetPointer;
    bool isDeletable;
    bool isArray;
};
}}}}
