// Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Collections::ObjectModel;

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3DCommon {

generic <class T>
public ref class Direct3DList :
    public ReadOnlyCollection<T>
{
internal:
    Direct3DList(void* collectionArray, bool deletable, IList<T>^ list) : ReadOnlyCollection<T>(list)
    {
        nativeArray.SetArray(collectionArray, deletable);
    };

private:
    AutoPointer<void> nativeArray;

};

}}}}
