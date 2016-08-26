// Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace DXGI { 

using namespace System;
ref class DXGIException :
public System::Exception
{
private:
    int hResult;

public:
    DXGIException(void) : System::Exception() {}
    
    DXGIException(int hr) : System::Exception("DXGI Error was returned. Check HResult.")
    {
        HResult = hr;
    }

    DXGIException(String^ message, int hr) : System::Exception(message)
    {
        HResult = hr;
    }

    DXGIException(String^ message, Exception^ innerException, int hr) : 
        System::Exception(message, innerException) 
        {
            HResult = hr;
        }
};

} } } }
