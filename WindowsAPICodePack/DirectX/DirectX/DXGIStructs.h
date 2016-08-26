//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace DXGI { 

using namespace System;
using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3DCommon;

/// <summary>
/// A Luid is a 64-bit value guaranteed to be unique only on the system on which it was generated. The uniqueness of a locally unique identifier (LUID) is guaranteed only until the system is restarted. An LUID is not for direct manipulation. 
/// Applications are to use functions and structures to manipulate Luid values.
/// </summary>
public ref struct Luid 
{
public:
    /// <summary>
    /// Low order bits.
    /// <para>(Also see DirectX SDK: LUID.LowPart)</para>
    /// </summary>
    property Int32 LowPart
    {
        Int32 get()
        {
            return (Int32)(nativeObject->LowPart);
        }
        void set(Int32 value)
        {
            nativeObject->LowPart = (INT)value;
        }
    }
    /// <summary>
    /// High order bits.
    /// <para>(Also see DirectX SDK: LUID.HighPart)</para>
    /// </summary>
    property Int32 HighPart
    {
        Int32 get()
        {
            return (Int32)(nativeObject->HighPart);
        }
        void set(Int32 value)
        {
            nativeObject->HighPart = (INT)value;
        }
    }
public:
    Luid()
    {
        nativeObject.Set(new LUID());
        ZeroMemory(nativeObject.Get(), sizeof(LUID));
    }
internal:
    AutoPointer<LUID> nativeObject;
internal:
    Luid(LUID* pLuid)
    {
        nativeObject.Set(pLuid);
    }
    Luid(LUID* pLuid, bool isDeletable)
    {
        nativeObject.Set(pLuid, isDeletable);
    }
};


/// <summary>
/// A resource handle.
/// </summary>
public ref struct ResourceHandle
{
public:
    property IntPtr Handle;
    
    ResourceHandle()
    {
        Handle = IntPtr::Zero;
    }

    ResourceHandle(IntPtr handle)
    {
        Handle = handle;
    }
};


/// <summary>
/// Describes a monitor.
/// <para>(Also see Windows SDK: MONITORINFOEX)</para>
/// </summary>
public ref struct MonitorInfo 
{
public:
    /// <summary>
    /// Specifies the display monitor rectangle, expressed in virtual-screen coordinates. 
    /// Note that if the monitor is not the primary display monitor, some of the rectangle's coordinates may be negative values.
    /// </summary>
    property D3dRect^ MonitorCoordinates
    {
        D3dRect^ get()
        {
            if (monitorCoordinates == nullptr)
            {
                monitorCoordinates = gcnew D3dRect(&(nativeObject->rcMonitor), false);
            }
            return monitorCoordinates;
        }
    }

    /// <summary>
    /// Specifies the work area rectangle of the display monitor 
    /// that can be used by applications, expressed in virtual-screen coordinates. 
    /// Windows uses this rectangle to maximize an application on the monitor. 
    /// The rest of the area in MonitorRect contains system windows such as the task bar 
    /// and side bars. Note that if the monitor is not the primary display monitor, 
    /// some of the rectangle's coordinates may be negative values.
    /// </summary>
    property D3dRect^ WorkCoordinates
    {
        D3dRect^ get()
        {
            if (workCoordinates == nullptr)
            {
                workCoordinates = gcnew D3dRect(&(nativeObject->rcWork), false);
            }
            return workCoordinates;
        }
    }
    /// <summary>
    /// Indicates if this is the primary monitor
    /// </summary>
    property Boolean IsPrimaryMonitor
    {
        Boolean get()
        {
            return (nativeObject->dwFlags & MONITORINFOF_PRIMARY) == MONITORINFOF_PRIMARY;
        }
    }
public:
    MonitorInfo()
    {}
internal:
    AutoPointer<MONITORINFOEX> nativeObject;
internal:
    MonitorInfo(HMONITOR hMon) : monitorCoordinates(nullptr), workCoordinates(nullptr)
    {
        MONITORINFOEX* pInfo = new MONITORINFOEX();
        pInfo->cbSize = sizeof(MONITORINFOEX);

        if (!GetMonitorInfo(hMon, pInfo))
        {
            return;
        }

        nativeObject.Set(pInfo);
    }
private:
    D3dRect^ monitorCoordinates;
    D3dRect^ workCoordinates;
};

/// <summary>
/// Represents a rational number.
/// <para>(Also see DirectX SDK: DXGI_RATIONAL)</para>
/// </summary>
public ref struct Rational 
{
public:
    /// <summary>
    /// An unsigned integer value representing the top of the rational number.
    /// <para>(Also see DirectX SDK: DXGI_RATIONAL.Numerator)</para>
    /// </summary>
    property UInt32 Numerator
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->Numerator);
        }
        void set(UInt32 value)
        {
            nativeObject->Numerator = (UINT)value;
        }
    }
    /// <summary>
    /// An unsigned integer value representing the bottom of the rational number.
    /// <para>(Also see DirectX SDK: DXGI_RATIONAL.Denominator)</para>
    /// </summary>
    property UInt32 Denominator
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->Denominator);
        }
        void set(UInt32 value)
        {
            nativeObject->Denominator = (UINT)value;
        }
    }
public:
    Rational()
    {
        nativeObject.Set(new DXGI_RATIONAL());
        ZeroMemory(nativeObject.Get(), sizeof(DXGI_RATIONAL));
    }
internal:
    AutoPointer<DXGI_RATIONAL> nativeObject;
internal:
    Rational(DXGI_RATIONAL* pRational)
    {
        nativeObject.Set(pRational);
    }

    Rational(DXGI_RATIONAL* pRational, bool isDeletable)
    {
        nativeObject.Set(pRational, isDeletable);
    }
};
/// <summary>
/// Represents an RGB color.
/// <para>(Also see DirectX SDK: DXGI_RGB)</para>
/// </summary>
public ref struct ColorRGB
{
public:
    /// <summary>
    /// A value representing the color of the red component. The range of this value is between 0 and 1.
    /// <para>(Also see DirectX SDK: DXGI_RGB.Red)</para>
    /// </summary>
    property Single Red
    {
        Single get()
        {
            return (Single)(nativeObject->Red);
        }
        void set(Single value)
        {
            nativeObject->Red = (float)value;
        }
    }
    /// <summary>
    /// A value representing the color of the green component. The range of this value is between 0 and 1.
    /// <para>(Also see DirectX SDK: DXGI_RGB.Green)</para>
    /// </summary>
    property Single Green
    {
        Single get()
        {
            return (Single)(nativeObject->Green);
        }
        void set(Single value)
        {
            nativeObject->Green = (float)value;
        }
    }
    /// <summary>
    /// A value representing the color of the blue component. The range of this value is between 0 and 1.
    /// <para>(Also see DirectX SDK: DXGI_RGB.Blue)</para>
    /// </summary>
    property Single Blue
    {
        Single get()
        {
            return (Single)(nativeObject->Blue);
        }
        void set(Single value)
        {
            nativeObject->Blue = (float)value;
        }
    }
public:
    ColorRGB(array<float>^ rgbColors)
    {
        if (rgbColors->Length != 3)
        {
            throw gcnew ArgumentOutOfRangeException("rgbColors","Length of input array must be exactly \"3\".");
        }
        nativeObject.Set(new DXGI_RGB());
        pin_ptr<FLOAT> arr = &rgbColors[0];

        memcpy(nativeObject.Get(), arr, sizeof(DXGI_RGB));
    }
    ColorRGB()
    {
        nativeObject.Set(new DXGI_RGB());
        ZeroMemory(nativeObject.Get(), sizeof(DXGI_RGB));
    }
internal:
    AutoPointer<DXGI_RGB> nativeObject;
internal:
    ColorRGB(DXGI_RGB* pRgb)
    {
        nativeObject.Set(pRgb);
    }

    ColorRGB(DXGI_RGB* pRgb, bool isDeletable)
    {
        nativeObject.Set(pRgb, isDeletable);
    }
};

/// <summary>
/// Represents an RGBA color.
/// </summary>
public ref struct ColorRGBA
{
public:
    /// <summary>
    /// A value representing the color of the red component. The range of this value is between 0 and 1.
    /// </summary>
    property Single Red
    {
        Single get()
        {
            return (Single)(nativeObject.Get()[0]);
        }
        void set(Single value)
        {
            nativeObject.Get()[0] = (float)value;
        }
    }
    /// <summary>
    /// A value representing the color of the green component. The range of this value is between 0 and 1.
    /// </summary>
    property Single Green
    {
        Single get()
        {
            return (Single)(nativeObject.Get()[1]);
        }
        void set(Single value)
        {
            nativeObject.Get()[1] = (float)value;
        }
    }
    /// <summary>
    /// A value representing the color of the blue component. The range of this value is between 0 and 1.
    /// </summary>
    property Single Blue
    {
        Single get()
        {
            return (Single)(nativeObject.Get()[2]);
        }
        void set(Single value)
        {
            nativeObject.Get()[2] = (float)value;
        }
    }

    /// <summary>
    /// A value representing the alpha channel component. The range of this value is between 0 and 1.
    /// </summary>
    property Single Alpha
    {
        Single get()
        {
            return (Single)(nativeObject.Get()[3]);
        }
        void set(Single value)
        {
            nativeObject.Get()[3] = (float)value;
        }
    }

public:
    ColorRGBA(array<float>^ rgbaColors)
    {
        if (rgbaColors->Length != 4)
        {
            throw gcnew ArgumentOutOfRangeException("rgbaColors","Length of input array must be exactly \"4\".");
        }
        nativeObject.Set(new FLOAT[4]);
        pin_ptr<FLOAT> arr = &rgbaColors[0];

        memcpy(nativeObject.Get(), arr, sizeof(FLOAT) * 4);
    }

    ColorRGBA()
    {
        nativeObject.Set(new FLOAT[4]);
        ZeroMemory(nativeObject.Get(), sizeof(FLOAT) * 4);
    }
internal:
    AutoPointer<FLOAT> nativeObject;
internal:

    ColorRGBA(FLOAT pRgba[4])
    {
        nativeObject.Set(pRgba);        
    }

    ColorRGBA(FLOAT pRgba[4], bool isDeletable)
    {
        nativeObject.Set(pRgba, isDeletable);
    }
};

/// <summary>
/// Describes an adapter (or video card) by using DXGI 1.0.
/// <para>(Also see DirectX SDK: DXGI_ADAPTER_DESC)</para>
/// </summary>
public ref struct AdapterDescription 
{
public:
    /// <summary>
    /// A string that contains the adapter description.
    /// <para>(Also see DirectX SDK: DXGI_ADAPTER_DESC.Description)</para>
    /// </summary>
    property String^ Description
    {
        String^ get()
        {
            if (adapterDescription == nullptr)
            {
                adapterDescription = 
                    nativeObject->Description == NULL ? nullptr : gcnew String(nativeObject->Description);
            }
            return adapterDescription;
        }
    }
    /// <summary>
    /// The PCI ID of the hardware vendor.
    /// <para>(Also see DirectX SDK: DXGI_ADAPTER_DESC.VendorId)</para>
    /// </summary>
    property UInt32 VendorId
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->VendorId);
        }
        void set(UInt32 value)
        {
            nativeObject->VendorId = (UINT)value;
        }
    }
    /// <summary>
    /// The PCI ID of the hardware device.
    /// <para>(Also see DirectX SDK: DXGI_ADAPTER_DESC.DeviceId)</para>
    /// </summary>
    property UInt32 DeviceId
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->DeviceId);
        }
        void set(UInt32 value)
        {
            nativeObject->DeviceId = (UINT)value;
        }
    }
    /// <summary>
    /// The PCI ID of the sub system.
    /// <para>(Also see DirectX SDK: DXGI_ADAPTER_DESC.SubSysId)</para>
    /// </summary>
    property UInt32 SubSysId
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->SubSysId);
        }
        void set(UInt32 value)
        {
            nativeObject->SubSysId = (UINT)value;
        }
    }
    /// <summary>
    /// The PCI ID of the revision number of the adapter.
    /// <para>(Also see DirectX SDK: DXGI_ADAPTER_DESC.Revision)</para>
    /// </summary>
    property UInt32 Revision
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->Revision);
        }
        void set(UInt32 value)
        {
            nativeObject->Revision = (UINT)value;
        }
    }
    /// <summary>
    /// The number of bytes of dedicated video memory that are not shared with the CPU.
    /// <para>(Also see DirectX SDK: DXGI_ADAPTER_DESC.DedicatedVideoMemory)</para>
    /// </summary>
    property UInt32 DedicatedVideoMemory
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->DedicatedVideoMemory);
        }
        void set(UInt32 value)
        {
            nativeObject->DedicatedVideoMemory = (SIZE_T)value;
        }
    }
    /// <summary>
    /// The number of bytes of dedicated system memory that are not shared with the GPU. This memory is allocated from available system memory at boot time.
    /// <para>(Also see DirectX SDK: DXGI_ADAPTER_DESC.DedicatedSystemMemory)</para>
    /// </summary>
    property UInt32 DedicatedSystemMemory
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->DedicatedSystemMemory);
        }
        void set(UInt32 value)
        {
            nativeObject->DedicatedSystemMemory = (SIZE_T)value;
        }
    }
    /// <summary>
    /// The number of bytes of shared system memory. This is the maximum value of system memory that may be consumed by the adapter during operation. Any incidental memory consumed by the driver as it manages and uses video memory is additional.
    /// <para>(Also see DirectX SDK: DXGI_ADAPTER_DESC.SharedSystemMemory)</para>
    /// </summary>
    property UInt32 SharedSystemMemory
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->SharedSystemMemory);
        }
        void set(UInt32 value)
        {
            nativeObject->SharedSystemMemory = (SIZE_T)value;
        }
    }
    /// <summary>
    /// A unique value that identifies the adapter. See LUID for a definition of the structure. LUID is defined in dxgi.h.
    /// <para>(Also see DirectX SDK: DXGI_ADAPTER_DESC.AdapterLuid)</para>
    /// </summary>
    property Luid^ AdapterLuid
    {
        Luid^ get()
        {
            if (adapterLuid == nullptr)
                adapterLuid = gcnew Luid(&(nativeObject->AdapterLuid), false);
            return adapterLuid;
        }
        void set(Luid^ value)
        {
            memcpy(&(nativeObject->AdapterLuid), (void*)(value->nativeObject.Get()), sizeof(LUID));
        }
    }
public:
    AdapterDescription() : adapterDescription(nullptr), adapterLuid(nullptr)
    {
        nativeObject.Set(new DXGI_ADAPTER_DESC());
        ZeroMemory(nativeObject.Get(), sizeof(DXGI_ADAPTER_DESC));
    }
internal:
    AutoPointer<DXGI_ADAPTER_DESC> nativeObject;
internal:
    AdapterDescription(DXGI_ADAPTER_DESC* pAdapterDescription) : adapterDescription(nullptr), adapterLuid(nullptr)
    {
        nativeObject.Set(pAdapterDescription);
    }
    AdapterDescription(DXGI_ADAPTER_DESC* pAdapterDescription, bool isDeletable) : adapterDescription(nullptr), adapterLuid(nullptr)
    {
        nativeObject.Set(pAdapterDescription, isDeletable);
    }
private: 
        String^ adapterDescription;
        Luid^ adapterLuid;
};
/// <summary>
/// Describes an adapter (or video card) using DXGI 1.1.
/// <para>(Also see DirectX SDK: DXGI_ADAPTER_DESC1)</para>
/// </summary>
public ref struct AdapterDescription1 
{
public:
    /// <summary>
    /// A string that contains the adapter description.
    /// <para>(Also see DirectX SDK: DXGI_ADAPTER_DESC1.Description)</para>
    /// </summary>
    property String^ Description
    {
        String^ get()
        {
            if (adapterDescription == nullptr)
            {
                adapterDescription = 
                    nativeObject->Description == NULL ? nullptr : gcnew String(nativeObject->Description);
            }
            return adapterDescription;
        }
    }
    /// <summary>
    /// The PCI ID of the hardware vendor.
    /// <para>(Also see DirectX SDK: DXGI_ADAPTER_DESC1.VendorId)</para>
    /// </summary>
    property UInt32 VendorId
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->VendorId);
        }
        void set(UInt32 value)
        {
            nativeObject->VendorId = (UINT)value;
        }
    }
    /// <summary>
    /// The PCI ID of the hardware device.
    /// <para>(Also see DirectX SDK: DXGI_ADAPTER_DESC1.DeviceId)</para>
    /// </summary>
    property UInt32 DeviceId
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->DeviceId);
        }
        void set(UInt32 value)
        {
            nativeObject->DeviceId = (UINT)value;
        }
    }
    /// <summary>
    /// The PCI ID of the sub system.
    /// <para>(Also see DirectX SDK: DXGI_ADAPTER_DESC1.SubSysId)</para>
    /// </summary>
    property UInt32 SubSysId
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->SubSysId);
        }
        void set(UInt32 value)
        {
            nativeObject->SubSysId = (UINT)value;
        }
    }
    /// <summary>
    /// The PCI ID of the revision number of the adapter.
    /// <para>(Also see DirectX SDK: DXGI_ADAPTER_DESC1.Revision)</para>
    /// </summary>
    property UInt32 Revision
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->Revision);
        }
        void set(UInt32 value)
        {
            nativeObject->Revision = (UINT)value;
        }
    }
    /// <summary>
    /// The number of bytes of dedicated video memory that are not shared with the CPU.
    /// <para>(Also see DirectX SDK: DXGI_ADAPTER_DESC1.DedicatedVideoMemory)</para>
    /// </summary>
    property UInt32 DedicatedVideoMemory
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->DedicatedVideoMemory);
        }
        void set(UInt32 value)
        {
            nativeObject->DedicatedVideoMemory = (SIZE_T)value;
        }
    }
    /// <summary>
    /// The number of bytes of dedicated system memory that are not shared with the GPU. This memory is allocated from available system memory at boot time.
    /// <para>(Also see DirectX SDK: DXGI_ADAPTER_DESC1.DedicatedSystemMemory)</para>
    /// </summary>
    property UInt32 DedicatedSystemMemory
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->DedicatedSystemMemory);
        }
        void set(UInt32 value)
        {
            nativeObject->DedicatedSystemMemory = (SIZE_T)value;
        }
    }
    /// <summary>
    /// The number of bytes of shared system memory. This is the maximum value of system memory that may be consumed by the adapter during operation. Any incidental memory consumed by the driver as it manages and uses video memory is additional.
    /// <para>(Also see DirectX SDK: DXGI_ADAPTER_DESC1.SharedSystemMemory)</para>
    /// </summary>
    property UInt32 SharedSystemMemory
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->SharedSystemMemory);
        }
        void set(UInt32 value)
        {
            nativeObject->SharedSystemMemory = (SIZE_T)value;
        }
    }
    /// <summary>
    /// A unique value that identifies the adapter. See LUID for a definition of the structure. LUID is defined in dxgi.h.
    /// <para>(Also see DirectX SDK: DXGI_ADAPTER_DESC1.AdapterLuid)</para>
    /// </summary>
    property Luid^ AdapterLuid
    {
        Luid^ get()
        {
            if (adapterLuid == nullptr)
                adapterLuid = gcnew Luid(&(nativeObject->AdapterLuid), false);
            return adapterLuid;
        }
        void set(Luid^ value)
        {
            memcpy(&(nativeObject->AdapterLuid), (void*)(value->nativeObject.Get()), sizeof(LUID));
        }
    }
    /// <summary>
    /// A member of the AdapterFlag enumerated type that describes the adapter type.  The AdapterFlag_REMOTE flag specifies that the adapter is a remote adapter.
    /// <para>(Also see DirectX SDK: DXGI_ADAPTER_DESC1.Flags)</para>
    /// </summary>
    property AdapterFlag Flags
    {
        AdapterFlag get()
        {
            return (AdapterFlag)(nativeObject->Flags);
        }
        void set(AdapterFlag value)
        {
            nativeObject->Flags = (UINT)value;
        }
    }
public:
    AdapterDescription1() : adapterDescription(nullptr), adapterLuid(nullptr)
    {
        nativeObject.Set(new DXGI_ADAPTER_DESC1());
        ZeroMemory(nativeObject.Get(), sizeof(DXGI_ADAPTER_DESC1));
    }
internal:
    AutoPointer<DXGI_ADAPTER_DESC1> nativeObject;
internal:
    AdapterDescription1(DXGI_ADAPTER_DESC1* pAdapterDescription1) : adapterDescription(nullptr), adapterLuid(nullptr)
    {
        nativeObject.Set(pAdapterDescription1);
    }
    AdapterDescription1(DXGI_ADAPTER_DESC1* pAdapterDescription1, bool isDeletable) : adapterDescription(nullptr), adapterLuid(nullptr)
    {
        nativeObject.Set(pAdapterDescription1, isDeletable);
    }
private: 
        String^ adapterDescription;
        Luid^ adapterLuid;
};
/// <summary>
/// Describes timing and presentation statistics for a frame.
/// <para>(Also see DirectX SDK: DXGI_FRAME_STATISTICS)</para>
/// </summary>
public ref struct FrameStatistics 
{
public:
    /// <summary>
    /// A value representing the running total count of times that an image has been presented to the monitor since the computer booted. Note that the number of times that an image has been presented to the monitor is not necessarily the same as the number of times that SwapChain.Present has been called.
    /// <para>(Also see DirectX SDK: DXGI_FRAME_STATISTICS.PresentCount)</para>
    /// </summary>
    property UInt32 PresentCount
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->PresentCount);
        }
        void set(UInt32 value)
        {
            nativeObject->PresentCount = (UINT)value;
        }
    }
    /// <summary>
    /// A value representing  the running total count of v-blanks that have happened since the computer booted.
    /// <para>(Also see DirectX SDK: DXGI_FRAME_STATISTICS.PresentRefreshCount)</para>
    /// </summary>
    property UInt32 PresentRefreshCount
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->PresentRefreshCount);
        }
        void set(UInt32 value)
        {
            nativeObject->PresentRefreshCount = (UINT)value;
        }
    }
    /// <summary>
    /// A value representing  the running total count of v-blanks that have happened since the computer booted.
    /// <para>(Also see DirectX SDK: DXGI_FRAME_STATISTICS.SyncRefreshCount)</para>
    /// </summary>
    property UInt32 SyncRefreshCount
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->SyncRefreshCount);
        }
        void set(UInt32 value)
        {
            nativeObject->SyncRefreshCount = (UINT)value;
        }
    }
    /// <summary>
    /// A value representing the high-resolution performance counter timer. 
    /// This value is that same as the value returned by the QueryPerformanceCounter function.
    /// <para>(Also see DirectX SDK: DXGI_FRAME_STATISTICS.SyncQPCTime)</para>
    /// </summary>
    property Int64 SyncQPCTime
    {
        Int64 get()
        {
            return (Int64)(nativeObject->SyncQPCTime.QuadPart);
        }
        void set(Int64 value)
        {
            nativeObject->SyncQPCTime.QuadPart = (INT64)value;
        }
    }
    /// <summary>
    /// Reserved. Always returns 0.
    /// <para>(Also see DirectX SDK: DXGI_FRAME_STATISTICS.SyncGPUTime)</para>
    /// </summary>
    property Int64 SyncGPUTime
    {
        Int64 get()
        {
            return (Int64)(nativeObject->SyncGPUTime.QuadPart);
        }
        void set(Int64 value)
        {
            nativeObject->SyncGPUTime.QuadPart = (INT64)value;
        }
    }
public:
    FrameStatistics()
    {
        nativeObject.Set(new DXGI_FRAME_STATISTICS());
        ZeroMemory(nativeObject.Get(), sizeof(DXGI_FRAME_STATISTICS));
    }
internal:
    AutoPointer<DXGI_FRAME_STATISTICS> nativeObject;
internal:
    FrameStatistics(DXGI_FRAME_STATISTICS* pFrameStatistics)
    {
        nativeObject.Set(pFrameStatistics);
    }
    FrameStatistics(DXGI_FRAME_STATISTICS* pFrameStatistics, bool isDeletable)
    {
        nativeObject.Set(pFrameStatistics, isDeletable);
    }
};
/// <summary>
/// Controls the settings of a gamma curve.
/// <para>(Also see DirectX SDK: DXGI_GAMMA_CONTROL)</para>
/// </summary>
public ref struct GammaControl 
{
public:
    /// <summary>
    /// A ColorRGB structure with scalar values that are applied to rgb values before being sent to the gamma look up table.
    /// <para>(Also see DirectX SDK: DXGI_GAMMA_CONTROL.Scale)</para>
    /// </summary>
    property ColorRGB^ Scale
    {
        ColorRGB^ get()
        {
            if (scale == nullptr)
                scale =  gcnew ColorRGB(&(nativeObject->Scale), false);
            return scale;
        }
        void set(ColorRGB^ value)
        {
            memcpy(&(nativeObject->Scale), (void*)(value->nativeObject.Get()), sizeof(DXGI_RGB));
        }
    }
    /// <summary>
    /// A ColorRGB structure with offset values that are applied to the rgb values before being sent to the gamma look up table.
    /// <para>(Also see DirectX SDK: DXGI_GAMMA_CONTROL.offset)</para>
    /// </summary>
    property ColorRGB^ Offset
    {
        ColorRGB^ get()
        {
            if (offset == nullptr)
                offset = gcnew ColorRGB(&(nativeObject->Offset), false);
            return offset;
        }
        void set(ColorRGB^ value)
        {
            memcpy(&(nativeObject->Offset), (void*)(value->nativeObject.Get()), sizeof(DXGI_RGB));
        }
    }
    /// <summary>
    /// A collection of ColorRGB structures that control the points of a gamma curve.
    /// <para>(Also see DirectX SDK: DXGI_GAMMA_CONTROL.GammaCurve)</para>
    /// </summary>
    property array<ColorRGB^>^ GammaCurve
    {
        array<ColorRGB^>^ get()
        {
            if (gammaCurveArray == nullptr)
            {
                gammaCurveArray = gcnew array<ColorRGB^>(GammaCurveArrayLength);
                for (int i=0; i < gammaCurveArray->Length; i++)
                {
                    gammaCurveArray[i] = gcnew ColorRGB(&(nativeObject->GammaCurve[i]), false);
                }
            }
            return gammaCurveArray;
        }
    }
public:
    GammaControl()
    {
        nativeObject.Set(new DXGI_GAMMA_CONTROL());
        ZeroMemory(nativeObject.Get(), sizeof(DXGI_GAMMA_CONTROL));
    }
internal:
    AutoPointer<DXGI_GAMMA_CONTROL> nativeObject;
internal:
    GammaControl(DXGI_GAMMA_CONTROL* pGammaControl)
    {
        nativeObject.Set(pGammaControl);
    }
    GammaControl(DXGI_GAMMA_CONTROL* pGammaControl, bool isDeletable)
    {
        nativeObject.Set(pGammaControl, isDeletable);
    }
private:
    static int GammaCurveArrayLength = 1025;
    array<ColorRGB^>^ gammaCurveArray;
    ColorRGB^ scale;
    ColorRGB^ offset;

};
/// <summary>
/// Controls the gamma capabilities of an adapter.
/// <para>(Also see DirectX SDK: DXGI_GAMMA_CONTROL_CAPABILITIES)</para>
/// </summary>
public ref struct GammaControlCapabilities 
{
public:
    /// <summary>
    /// True if scaling and offset operations are supported during gamma correction; otherwise, false.
    /// <para>(Also see DirectX SDK: DXGI_GAMMA_CONTROL_CAPABILITIES.ScaleAndOffsetSupported)</para>
    /// </summary>
    property Boolean ScaleAndOffsetSupported
    {
        Boolean get()
        {
            return nativeObject->ScaleAndOffsetSupported != 0;
        }
        void set(Boolean value)
        {
            nativeObject->ScaleAndOffsetSupported = (BOOL)value;
        }
    }
    /// <summary>
    /// A value describing the maximum range of the control-point positions.
    /// <para>(Also see DirectX SDK: DXGI_GAMMA_CONTROL_CAPABILITIES.MaxConvertedValue)</para>
    /// </summary>
    property Single MaxConvertedValue
    {
        Single get()
        {
            return (Single)(nativeObject->MaxConvertedValue);
        }
        void set(Single value)
        {
            nativeObject->MaxConvertedValue = (float)value;
        }
    }
    /// <summary>
    /// A value describing the minimum range of the control-point positions.
    /// <para>(Also see DirectX SDK: DXGI_GAMMA_CONTROL_CAPABILITIES.MinConvertedValue)</para>
    /// </summary>
    property Single MinConvertedValue
    {
        Single get()
        {
            return (Single)(nativeObject->MinConvertedValue);
        }
        void set(Single value)
        {
            nativeObject->MinConvertedValue = (float)value;
        }
    }
    /// <summary>
    /// A value describing the number of control points in the array.
    /// <para>(Also see DirectX SDK: DXGI_GAMMA_CONTROL_CAPABILITIES.NumGammaControlPoints)</para>
    /// </summary>
    property UInt32 NumGammaControlPoints
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->NumGammaControlPoints);
        }
        void set(UInt32 value)
        {
            nativeObject->NumGammaControlPoints = (UINT)value;
        }
    }
    /// <summary>
    /// A collection of values describing control points; the maximum length of control points is 1025.
    /// <para>(Also see DirectX SDK: DXGI_GAMMA_CONTROL_CAPABILITIES.ControlPointPositions)</para>
    /// </summary>
    property array<Single>^ ControlPointPositions
    {
        array<Single>^ get()
        {
            if (controlPointPositionsArray == nullptr)
            {
                controlPointPositionsArray = gcnew array<Single>(ControlPointPositionsArrayLength);
                for (int i=0; i < controlPointPositionsArray->Length; i++)
                {
                    controlPointPositionsArray[i] = nativeObject->ControlPointPositions[i];
                }
            }
            return controlPointPositionsArray;
        }
    }
public:
    GammaControlCapabilities() : controlPointPositionsArray(nullptr)
    {
        nativeObject.Set(new DXGI_GAMMA_CONTROL_CAPABILITIES());
        ZeroMemory(nativeObject.Get(), sizeof(DXGI_GAMMA_CONTROL_CAPABILITIES));
    }
internal:
    AutoPointer<DXGI_GAMMA_CONTROL_CAPABILITIES> nativeObject;
internal:
    GammaControlCapabilities(DXGI_GAMMA_CONTROL_CAPABILITIES* pGammaControlCapabilities) :
      controlPointPositionsArray(nullptr)
    {
        nativeObject.Set(pGammaControlCapabilities);
    }
    GammaControlCapabilities(DXGI_GAMMA_CONTROL_CAPABILITIES* pGammaControlCapabilities, bool isDeletable) :
      controlPointPositionsArray(nullptr)
    {
        nativeObject.Set(pGammaControlCapabilities, isDeletable);
    }
private:
        static int ControlPointPositionsArrayLength = 1025;
        array<Single>^ controlPointPositionsArray;
};
/// <summary>
/// A mapped rectangle used for accessing a surface.
/// <para>(Also see DirectX SDK: DXGI_MAPPED_RECT)</para>
/// </summary>
public ref struct MappedRect 
{
public:
    /// <summary>
    /// A value describing the width of the surface.
    /// <para>(Also see DirectX SDK: DXGI_MAPPED_RECT.Pitch)</para>
    /// </summary>
    property Int32 Pitch
    {
        Int32 get()
        {
            return (Int32)(nativeObject->Pitch);
        }
        void set(Int32 value)
        {
            nativeObject->Pitch = (INT)value;
        }
    }
    /// <summary>
    /// The image buffer of the surface.
    /// <para>(Also see DirectX SDK: DXGI_MAPPED_RECT.pBits)</para>
    /// </summary>
    property IntPtr pBits
    {        
        IntPtr get()
        {
            return IntPtr(nativeObject->pBits);
        }
        void set(IntPtr value)
        {
            nativeObject->pBits = (BYTE*)value.ToPointer();
        }
    }
public:
    MappedRect()
    {
        nativeObject.Set(new DXGI_MAPPED_RECT());
        ZeroMemory(nativeObject.Get(), sizeof(DXGI_MAPPED_RECT));
    }
internal:
    AutoPointer<DXGI_MAPPED_RECT> nativeObject;
internal:
    MappedRect(DXGI_MAPPED_RECT* pMappedRect)
    {
        nativeObject.Set(pMappedRect);
    }
};
/// <summary>
/// Describes a display mode.
/// <para>(Also see DirectX SDK: DXGI_MODE_DESC)</para>
/// </summary>
public ref struct ModeDescription 
{
public:
    /// <summary>
    /// A value describing the resolution width.
    /// <para>(Also see DirectX SDK: DXGI_MODE_DESC.Width)</para>
    /// </summary>
    property UInt32 Width
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->Width);
        }
        void set(UInt32 value)
        {
            nativeObject->Width = (UINT)value;
        }
    }
    /// <summary>
    /// A value describing the resolution height.
    /// <para>(Also see DirectX SDK: DXGI_MODE_DESC.Height)</para>
    /// </summary>
    property UInt32 Height
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->Height);
        }
        void set(UInt32 value)
        {
            nativeObject->Height = (UINT)value;
        }
    }
    /// <summary>
    /// A Rational structure describing the refresh rate in hertz
    /// <para>(Also see DirectX SDK: DXGI_MODE_DESC.RefreshRate)</para>
    /// </summary>
    property Rational^ RefreshRate
    {
        Rational^ get()
        {
             if (refreshRate == nullptr)
                 refreshRate  = gcnew Rational(&(nativeObject->RefreshRate), false);
             return refreshRate;
        }
        void set(Rational^ value)
        {
            memcpy(&(nativeObject->RefreshRate), (void*)(value->nativeObject.Get()), sizeof(DXGI_RATIONAL));
        }
    }
    /// <summary>
    /// A Format structure describing the display format.
    /// <para>(Also see DirectX SDK: DXGI_MODE_DESC.Format)</para>
    /// </summary>
    property Format DisplayFormat
    {
        Format get()
        {
            return (Format)(nativeObject->Format);
        }
        void set(Format value)
        {
            nativeObject->Format = (DXGI_FORMAT)value;
        }
    }
    /// <summary>
    /// A member of the ModeScanlineOrder enumerated type describing the scanline drawing mode.
    /// <para>(Also see DirectX SDK: DXGI_MODE_DESC.ScanlineOrdering)</para>
    /// </summary>
    property ModeScanlineOrder ScanlineOrdering
    {
        ModeScanlineOrder get()
        {
            return (ModeScanlineOrder)(nativeObject->ScanlineOrdering);
        }
        void set(ModeScanlineOrder value)
        {
            nativeObject->ScanlineOrdering = (DXGI_MODE_SCANLINE_ORDER)value;
        }
    }
    /// <summary>
    /// A member of the ModeScaling enumerated type describing the scaling mode.
    /// <para>(Also see DirectX SDK: DXGI_MODE_DESC.Scaling)</para>
    /// </summary>
    property ModeScaling Scaling
    {
        ModeScaling get()
        {
            return (ModeScaling)(nativeObject->Scaling);
        }
        void set(ModeScaling value)
        {
            nativeObject->Scaling = (DXGI_MODE_SCALING)value;
        }
    }
public:
    ModeDescription()
    {
        nativeObject.Set(new DXGI_MODE_DESC());
        ZeroMemory(nativeObject.Get(), sizeof(DXGI_MODE_DESC));
    }
internal:
    AutoPointer<DXGI_MODE_DESC> nativeObject;
internal:
    ModeDescription(DXGI_MODE_DESC* pModeDescription)
    {
        nativeObject.Set(pModeDescription);
    }
    ModeDescription(DXGI_MODE_DESC* pModeDescription, bool isDeletable)
    {
        nativeObject.Set(pModeDescription, isDeletable);
    }
private:
     Rational^ refreshRate;
};
/// <summary>
/// Describes an output or physical connection between the adapter (video card) and a device.
/// <para>(Also see DirectX SDK: DXGI_OUTPUT_DESC)</para>
/// </summary>
public ref struct OutputDescription 
{
public:
    /// <summary>
    /// A string that contains the name of the output device.
    /// <para>(Also see DirectX SDK: DXGI_OUTPUT_DESC.DeviceName)</para>
    /// </summary>
    property String^ DeviceName
    {
        String^ get()
        {
            if (deviceName == nullptr)
            {
                 deviceName = nativeObject->DeviceName == NULL ?
                     nullptr : gcnew String(nativeObject->DeviceName);
            }

            return deviceName;
        }
    }
    /// <summary>
    /// A RECT structure containing the bounds of the output in desktop coordinates.
    /// <para>(Also see DirectX SDK: DXGI_OUTPUT_DESC.DesktopCoordinates)</para>
    /// </summary>
    property D3dRect^ DesktopCoordinates
    {
        D3dRect^ get()
        {
            if (desktopCoordinates == nullptr)
                desktopCoordinates  =  gcnew D3dRect(nativeObject->DesktopCoordinates);

            return desktopCoordinates ;
        }
    }
    /// <summary>
    /// True if the output is attached to the desktop; otherwise, false.
    /// <para>(Also see DirectX SDK: DXGI_OUTPUT_DESC.AttachedToDesktop)</para>
    /// </summary>
    property Boolean AttachedToDesktop
    {
        Boolean get()
        {
            return nativeObject->AttachedToDesktop != 0;
        }
        void set(Boolean value)
        {
            nativeObject->AttachedToDesktop = (BOOL)value;
        }
    }
    /// <summary>
    /// A member of the ModeRotation enumerated type describing on how an image is rotated by the output.
    /// <para>(Also see DirectX SDK: DXGI_OUTPUT_DESC.Rotation)</para>
    /// </summary>
    property ModeRotation Rotation
    {
        ModeRotation get()
        {
            return (ModeRotation)(nativeObject->Rotation);
        }
        void set(ModeRotation value)
        {
            nativeObject->Rotation = (DXGI_MODE_ROTATION)value;
        }
    }
    /// <summary>
    /// An HMONITOR handle that represents the display monitor. For more information, see HMONITOR and the Device Context.
    /// <para>(Also see DirectX SDK: DXGI_OUTPUT_DESC.Monitor)</para>
    /// </summary>
    property MonitorInfo^ Monitor
    {
        MonitorInfo^ get()
        {
            if (monitorInfo == nullptr)
                monitorInfo = gcnew MonitorInfo(nativeObject->Monitor);
            return monitorInfo;
        }
    }
public:
    OutputDescription()
    {
        nativeObject.Set(new DXGI_OUTPUT_DESC());
        ZeroMemory(nativeObject.Get(), sizeof(DXGI_OUTPUT_DESC));
    }
internal:
    AutoPointer<DXGI_OUTPUT_DESC> nativeObject;
internal:

    OutputDescription(DXGI_OUTPUT_DESC* pOutputDescription)
    {
        nativeObject.Set(pOutputDescription);
    }

    OutputDescription(DXGI_OUTPUT_DESC* pOutputDescription, bool isDeletable)
    {
        nativeObject.Set(pOutputDescription, isDeletable);
    }
private:
    String^ deviceName;
    MonitorInfo^ monitorInfo;
    D3dRect^ desktopCoordinates;
};
/// <summary>
/// Describes multi-sampling parameters for a resource.
/// <para>(Also see DirectX SDK: DXGI_SAMPLE_DESC)</para>
/// </summary>
public ref struct SampleDescription 
{
public:
    /// <summary>
    /// The number of multisamples per pixel.
    /// <para>(Also see DirectX SDK: DXGI_SAMPLE_DESC.Count)</para>
    /// </summary>
    property UInt32 Count
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->Count);
        }
        void set(UInt32 value)
        {
            nativeObject->Count = (UINT)value;
        }
    }
    /// <summary>
    /// The image quality level. The higher the quality, the lower the performance. The valid range is between zero and one less than the level returned         by Device.CheckMultiSampleQualityLevels.
    /// <para>(Also see DirectX SDK: DXGI_SAMPLE_DESC.Quality)</para>
    /// </summary>
    property UInt32 Quality
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->Quality);
        }
        void set(UInt32 value)
        {
            nativeObject->Quality = (UINT)value;
        }
    }
public:
    SampleDescription()
    {
        nativeObject.Set(new DXGI_SAMPLE_DESC());
        ZeroMemory(nativeObject.Get(), sizeof(DXGI_SAMPLE_DESC));
    }
internal:
    AutoPointer<DXGI_SAMPLE_DESC> nativeObject;
internal:
    SampleDescription(DXGI_SAMPLE_DESC* pSampleDescription)
    {
        nativeObject.Set(pSampleDescription);
    }
    SampleDescription(DXGI_SAMPLE_DESC* pSampleDescription, bool isDeletable)
    {
        nativeObject.Set(pSampleDescription, isDeletable);
    }
};
/// <summary>
/// Represents a handle to a shared resource.
/// <para>(Also see DirectX SDK: DXGI_SHARED_RESOURCE)</para>
/// </summary>
public ref struct SharedResource 
{
public:
    /// <summary>
    /// A handle to a shared resource.
    /// <para>(Also see DirectX SDK: DXGI_SHARED_RESOURCE.Handle)</para>
    /// </summary>
    HANDLE Handle;
public:
    SharedResource()
    {
        nativeObject.Set(new DXGI_SHARED_RESOURCE());
        ZeroMemory(nativeObject.Get(), sizeof(DXGI_SHARED_RESOURCE));
    }
internal:
    AutoPointer<DXGI_SHARED_RESOURCE> nativeObject;
internal:
    SharedResource(DXGI_SHARED_RESOURCE* pSharedResource)
    {
        nativeObject.Set(pSharedResource);
    }
    SharedResource(DXGI_SHARED_RESOURCE* pSharedResource, bool isDeletable)
    {
        nativeObject.Set(pSharedResource, isDeletable);
    }
};
/// <summary>
/// Describes a surface.
/// <para>(Also see DirectX SDK: DXGI_SURFACE_DESC)</para>
/// </summary>
public ref struct SurfaceDescription 
{
public:
    /// <summary>
    /// A value describing the surface width.
    /// <para>(Also see DirectX SDK: DXGI_SURFACE_DESC.Width)</para>
    /// </summary>
    property UInt32 Width
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->Width);
        }
        void set(UInt32 value)
        {
            nativeObject->Width = (UINT)value;
        }
    }
    /// <summary>
    /// A value describing the surface height.
    /// <para>(Also see DirectX SDK: DXGI_SURFACE_DESC.Height)</para>
    /// </summary>
    property UInt32 Height
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->Height);
        }
        void set(UInt32 value)
        {
            nativeObject->Height = (UINT)value;
        }
    }
    /// <summary>
    /// A member of the Format enumerated type that describes the surface format.
    /// <para>(Also see DirectX SDK: DXGI_SURFACE_DESC.Format)</para>
    /// </summary>
    property Format SurfaceFormat
    {
        Format get()
        {
            return (Format)(nativeObject->Format);
        }
        void set(Format value)
        {
            nativeObject->Format = (DXGI_FORMAT)value;
        }
    }
    /// <summary>
    /// A member of the SampleDescription structure that describes multi-sampling parameters for the surface.
    /// <para>(Also see DirectX SDK: DXGI_SURFACE_DESC.SampleDesc)</para>
    /// </summary>
    property SampleDescription^ SampleDesc
    {
        SampleDescription^ get()
        {
            if (sampleDescription == nullptr)
                sampleDescription  = gcnew SampleDescription(&(nativeObject->SampleDesc), false);

            return sampleDescription;
        }

        void set(SampleDescription^ value)
        {
            memcpy(&(nativeObject->SampleDesc), (void*)(value->nativeObject.Get()), sizeof(DXGI_SAMPLE_DESC));
        }
    }
public:
    SurfaceDescription() : sampleDescription(nullptr)
    {
        nativeObject.Set(new DXGI_SURFACE_DESC());
        ZeroMemory(nativeObject.Get(), sizeof(DXGI_SURFACE_DESC));
    }
internal:
    AutoPointer<DXGI_SURFACE_DESC> nativeObject;
internal:
    SurfaceDescription(DXGI_SURFACE_DESC* pSurfaceDescription) : sampleDescription(nullptr)
    {
        nativeObject.Set(pSurfaceDescription);
    }
    SurfaceDescription(DXGI_SURFACE_DESC* pSurfaceDescription, bool isDeletable) : sampleDescription(nullptr)
    {
        nativeObject.Set(pSurfaceDescription, isDeletable);
    }
private:
    SampleDescription^ sampleDescription;
};
/// <summary>
/// Describes a swap chain.
/// <para>(Also see DirectX SDK: DXGI_SWAP_CHAIN_DESC)</para>
/// </summary>
public ref struct SwapChainDescription 
{
public:
    /// <summary>
    /// A ModeDescription structure describing the backbuffer display mode.
    /// <para>(Also see DirectX SDK: DXGI_SWAP_CHAIN_DESC.BufferDesc)</para>
    /// </summary>
    property ModeDescription^ BufferDesc
    {
        ModeDescription^ get()
        {
            if (bufferDescription == nullptr)
                bufferDescription  = gcnew ModeDescription(&(nativeObject->BufferDesc), false);

            return bufferDescription;
        }
        void set(ModeDescription^ value)
        {
            memcpy(&(nativeObject->BufferDesc), (void*)(value->nativeObject.Get()), sizeof(DXGI_MODE_DESC));
        }
    }
    /// <summary>
    /// A SampleDescription structure describing multi-sampling parameters.
    /// <para>(Also see DirectX SDK: DXGI_SWAP_CHAIN_DESC.SampleDesc)</para>
    /// </summary>
    property SampleDescription^ SampleDesc
    {
        SampleDescription^ get()
        {
            if (sampleDescription == nullptr)
                sampleDescription  = gcnew SampleDescription(&(nativeObject->SampleDesc), false);

            return sampleDescription;
        }
        void set(SampleDescription^ value)
        {
            memcpy(&(nativeObject->SampleDesc), (void*)(value->nativeObject.Get()), sizeof(DXGI_SAMPLE_DESC));
        }
    }
    /// <summary>
    /// A member of the UsageOption enumerated type describing the surface usage and CPU access options for the back buffer. The back buffer can be used for shader input or render-target output.
    /// <para>(Also see DirectX SDK: DXGI_SWAP_CHAIN_DESC.BufferUsage)</para>
    /// </summary>
    property UsageOption BufferUsage
    {
        UsageOption get()
        {
            return (UsageOption)(nativeObject->BufferUsage);
        }
        void set(UsageOption value)
        {
            nativeObject->BufferUsage = (DXGI_USAGE)value;
        }
    }
    /// <summary>
    /// A value that describes the number of buffers in the swap chain, including the front buffer.
    /// <para>(Also see DirectX SDK: DXGI_SWAP_CHAIN_DESC.BufferCount)</para>
    /// </summary>
    property UInt32 BufferCount
    {
        UInt32 get()
        {
            return (UInt32)(nativeObject->BufferCount);
        }
        void set(UInt32 value)
        {
            nativeObject->BufferCount = (UINT)value;
        }
    }
    /// <summary>
    /// An HWND handle to the output window. This member must not be IntPtr.Zero.
    /// <para>(Also see DirectX SDK: DXGI_SWAP_CHAIN_DESC.OutputWindow)</para>
    /// </summary>
    property IntPtr OutputWindow
    {
        IntPtr get()
        {
            return IntPtr(nativeObject->OutputWindow);
        }
        
        void set(IntPtr value)
        {
            nativeObject->OutputWindow = (HWND) value.ToPointer();

        }
    }

    /// <summary>
    /// True if the output is in windowed mode; otherwise, false. For more information, see Factory.CreateSwapChain.
    /// <para>(Also see DirectX SDK: DXGI_SWAP_CHAIN_DESC.Windowed)</para>
    /// </summary>
    property Boolean Windowed
    {
        Boolean get()
        {
            return nativeObject->Windowed != 0;
        }
        void set(Boolean value)
        {
            nativeObject->Windowed = (BOOL)value;
        }
    }
    /// <summary>
    /// A member of the SwapEffect enumerated type that describes options for handling the contents of the presentation buffer after         presenting a surface.
    /// <para>(Also see DirectX SDK: DXGI_SWAP_CHAIN_DESC.SwapEffect)</para>
    /// </summary>
    property SwapEffect SwapEffectType
    {
        SwapEffect get()
        {
            return (SwapEffect)(nativeObject->SwapEffect);
        }
        void set(SwapEffect value)
        {
            nativeObject->SwapEffect = (DXGI_SWAP_EFFECT)value;
        }
    }
    /// <summary>
    /// A member of the SwapChainFlag enumerated type that describes options for swap-chain behavior.
    /// <para>(Also see DirectX SDK: DXGI_SWAP_CHAIN_DESC.Flags)</para>
    /// </summary>
    property SwapChainFlag Flags
    {
        SwapChainFlag get()
        {
            return (SwapChainFlag)(nativeObject->Flags);
        }
        void set(SwapChainFlag value)
        {
            nativeObject->Flags = (UINT)value;
        }
    }
public:
    SwapChainDescription() : sampleDescription(nullptr), bufferDescription(nullptr)
    {
        nativeObject.Set(new DXGI_SWAP_CHAIN_DESC());
        ZeroMemory(nativeObject.Get(), sizeof(DXGI_SWAP_CHAIN_DESC));
    }
internal:
    AutoPointer<DXGI_SWAP_CHAIN_DESC> nativeObject;
internal:
    SwapChainDescription(DXGI_SWAP_CHAIN_DESC* pSwapChainDescription)  : sampleDescription(nullptr), bufferDescription(nullptr)
    {
        nativeObject.Set(pSwapChainDescription);
    }
    SwapChainDescription(DXGI_SWAP_CHAIN_DESC* pSwapChainDescription, bool isDeletable): sampleDescription(nullptr), bufferDescription(nullptr) 
    {
        nativeObject.Set(pSwapChainDescription, isDeletable);
    }
private:
    SampleDescription^ sampleDescription;
    ModeDescription^ bufferDescription;
};

} } } }
