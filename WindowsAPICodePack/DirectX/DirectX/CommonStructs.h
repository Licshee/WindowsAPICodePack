//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once

using namespace System;

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3DCommon {

/// <summary>
/// This structure defines the coordinates of the upper-left and lower-right corners of a rectangle.
/// </summary>
public ref struct D3dRect 
{
public:
    /// <summary>
    /// Specifies the x-coordinate of the upper-left corner of the rectangle.
    /// </summary>
    property Int32 left
    {
        Int32 get()
        {
            return (Int32)(nativeObject->left);
        }
        void set(Int32 value)
        {
            nativeObject->left = (INT)value;
        }
    }
    /// <summary>
    /// Specifies the y-coordinate of the upper-left corner of the rectangle.
    /// </summary>
    property Int32 top
    {
        Int32 get()
        {
            return (Int32)(nativeObject->top);
        }
        void set(Int32 value)
        {
            nativeObject->top = (INT)value;
        }
    }
    /// <summary>
    /// Specifies the x-coordinate of the lower-right corner of the rectangle.
    /// </summary>
    property Int32 right
    {
        Int32 get()
        {
            return (Int32)(nativeObject->right);
        }
        void set(Int32 value)
        {
            nativeObject->right = (INT)value;
        }
    }
    /// <summary>
    /// Specifies the y-coordinate of the lower-right corner of the rectangle.
    /// </summary>
    property Int32 bottom
    {
        Int32 get()
        {
            return (Int32)(nativeObject->bottom);
        }
        void set(Int32 value)
        {
            nativeObject->bottom = (INT)value;
        }
    }
public:
    D3dRect()
    {
        nativeObject.Set(new RECT());
        ZeroMemory(nativeObject.Get(), sizeof(RECT));
    }
internal:
    AutoPointer<RECT> nativeObject;
internal:
    D3dRect(RECT* pD3dRect)
    {
        nativeObject.Set(pD3dRect);
    }
    D3dRect(RECT* pD3dRect, bool deletable)
    {
        nativeObject.Set(pD3dRect, deletable);
    }
    D3dRect(const RECT &rect)
    {
        nativeObject.Set(new RECT());
        memcpy(nativeObject.Get(), &rect, sizeof(RECT));
    }
};
} } } }
