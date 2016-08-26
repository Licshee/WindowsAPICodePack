// Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Collections::ObjectModel;

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3DCommon {

generic <class T>
public ref class CachedCollection:
    public ReadOnlyCollection<T>
{
internal:
    CachedCollection() : ReadOnlyCollection<T>(gcnew List<T>()) { }
internal:
    property bool IsValid;

public:
    void Invalidate()
    {
        IsValid = false;
        Items->Clear();
    }

    internal: 
        void InternalAdd(T item)
        {
            Items->Add(item);
        }
};

}}}}
