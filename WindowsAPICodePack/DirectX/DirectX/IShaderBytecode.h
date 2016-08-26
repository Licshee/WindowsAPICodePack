// Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once

using namespace System;

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3DCommon {

public interface class IShaderBytecode
{
public:
    property IntPtr ShaderBytecode
    {
        IntPtr get() = 0;
    }

    property UInt32 ShaderBytecodeLength
    {
        UInt32 get() = 0;
    }
};

} } } }
