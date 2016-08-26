// Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3DCommon {

using namespace System;
using namespace System::Runtime::InteropServices;

public ref class Direct3DException :
public System::Exception
{
private:
    int hResult;
public:
    Direct3DException(void) : System::Exception() {}
    
    Direct3DException(String^ message, int hr) : System::Exception(message) 
    {
        HResult = hr;
    }
    
    Direct3DException(int hr) : System::Exception("Direct3D Error was returned.") 
    {
        HResult = hr;
        
    }
    
    Direct3DException(String^ message, Exception^ innerException, int hr) : 
        System::Exception(message, innerException) 
    {
        HResult = hr;
    }
};

} } } }
