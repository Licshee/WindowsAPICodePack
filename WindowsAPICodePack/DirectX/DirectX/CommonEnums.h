//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3DCommon {

/// <summary>
/// Driver type options.
/// <para>(Also see DirectX SDK: D3D_DRIVER_TYPE)</para>
/// </summary>
public enum class DriverType 
{
    /// <summary>
    /// The driver type is unknown.
    /// <para>(Also see DirectX SDK: D3D_DRIVER_TYPE_UNKNOWN)</para>
    /// </summary>
    Unknown = D3D_DRIVER_TYPE_UNKNOWN,
    /// <summary>
    /// A hardware driver, which implements Direct3D features in hardware. This is the primary driver that you should use in your Direct3D applications because it provides the best performance. A hardware driver uses hardware acceleration (on supported hardware) but can also use software for parts of the pipeline that are not supported in hardware. This driver type is often referred to as a hardware abstraction layer or HAL.
    /// <para>(Also see DirectX SDK: D3D_DRIVER_TYPE_HARDWARE)</para>
    /// </summary>
    Hardware = D3D_DRIVER_TYPE_HARDWARE,
    /// <summary>
    /// A reference driver, which is a software implementation that supports every Direct3D feature. A reference driver is designed for accuracy rather than speed and as a result is slow but accurate. The rasterizer portion of the driver does make use of special CPU instructions whenever it can, but it is not intended for retail applications; use it only for feature testing, demonstration of functionality, debugging, or verifying bugs in other drivers. This driver is installed by the DirectX SDK. This driver may be referred to as a REF driver, a reference driver or a reference rasterizer.
    /// <para>(Also see DirectX SDK: D3D_DRIVER_TYPE_REFERENCE)</para>
    /// </summary>
    Reference = D3D_DRIVER_TYPE_REFERENCE,
    /// <summary>
    /// A NULL driver, which is a reference driver without render capability. This driver is commonly used for debugging non-rendering API calls, it is not appropriate for retail applications. This driver is installed by the DirectX SDK.
    /// <para>(Also see DirectX SDK: D3D_DRIVER_TYPE_NULL)</para>
    /// </summary>
    Null = D3D_DRIVER_TYPE_NULL,
    /// <summary>
    /// A software driver, which is a driver implemented completely in software. The software implementation is not intended for a high-performance application due to its very slow performance.
    /// <para>(Also see DirectX SDK: D3D_DRIVER_TYPE_SOFTWARE)</para>
    /// </summary>
    Software = D3D_DRIVER_TYPE_SOFTWARE,
    /// <summary>
    /// A WARP driver, which is a high-performance software rasterizer. The rasterizer supports all current feature levels (level 9.1 through level 11.0) with a high performance software implementation when hardware is not available. For more information about using a WARP driver, see Windows Advanced Rasterization Platform (WARP) In-Depth Guide
    /// <para>(Also see DirectX SDK: D3D_DRIVER_TYPE_WARP)</para>
    /// </summary>
    Warp = D3D_DRIVER_TYPE_WARP,
};
/// <summary>
/// Describes the set of features targeted by a Direct3D device.
/// <para>(Also see DirectX SDK: D3D_FEATURE_LEVEL)</para>
/// </summary>
public enum class FeatureLevel 
{
    /// <summary>
    /// Targets features supported by Direct3D 9.1 including shader model 2.
    /// <para>(Also see DirectX SDK: D3D_FEATURE_LEVEL_9_1)</para>
    /// </summary>
    FeatureLevel_9_1 = D3D_FEATURE_LEVEL_9_1,
    /// <summary>
    /// Targets features supported by Direct3D 9.2 including shader model 2.
    /// <para>(Also see DirectX SDK: D3D_FEATURE_LEVEL_9_2)</para>
    /// </summary>
    FeatureLevel_9_2 = D3D_FEATURE_LEVEL_9_2,
    /// <summary>
    /// Targets features supported by Direct3D 9.3 including shader shader model 3.
    /// <para>(Also see DirectX SDK: D3D_FEATURE_LEVEL_9_3)</para>
    /// </summary>
    FeatureLevel_9_3 = D3D_FEATURE_LEVEL_9_3,
    /// <summary>
    /// Targets features supported by Direct3D 10.0 including shader shader model 4.
    /// <para>(Also see DirectX SDK: D3D_FEATURE_LEVEL_10_0)</para>
    /// </summary>
    FeatureLevel_10_0 = D3D_FEATURE_LEVEL_10_0,
    /// <summary>
    /// Targets features supported by Direct3D 10.1 including shader shader model 4.1.
    /// <para>(Also see DirectX SDK: D3D_FEATURE_LEVEL_10_1)</para>
    /// </summary>
    FeatureLevel_10_1 = D3D_FEATURE_LEVEL_10_1,
    /// <summary>
    /// Targets features supported by Direct3D 11.0 including shader shader model 5.
    /// <para>(Also see DirectX SDK: D3D_FEATURE_LEVEL_11_0)</para>
    /// </summary>
    FeatureLevel_11_0 = D3D_FEATURE_LEVEL_11_0,
};


/// <summary>
/// Direct3D Devices supported by this library.
/// </summary>
public enum class DeviceType
{
    /// <summary>
    /// Direct3D Device 10.0
    /// </summary>
    Direct3D_10_0 = 0,

    /// <summary>
    /// Direct3D Device 10.1
    /// </summary>
    Direct3D_10_1 = 1,
    
    /// <summary>
    /// Direct3D Device 11.0
    /// </summary>
    Direct3D_11_0 = 2,
};

/// <summary>
/// Error codes that can be returned by D3D or DXGI methods
/// </summary>
public enum class ErrorCode
{
    /// <summary>
    /// The method succeeded without an error. 
    /// </summary>
    Success = S_OK ,

    /// <summary>
    /// Alternate success value, indicating a successful but nonstandard completion (the precise meaning depends on context).
    /// </summary>
    FalseSuccess =  S_FALSE,

    /// <summary>
    /// The application's device failed due to badly formed commands sent by the application. This is an design-time issue that should be investigated and fixed. 
    /// <para>(Also see DirectX SDK:  DXGI_ERROR_DEVICE_HUNG )</para>
    /// </summary>
    DeviceHung = DXGI_ERROR_DEVICE_HUNG,

    /// <summary>
    /// The video card has been physically removed from the system, or a driver upgrade for the video card has occurred. The application should destroy and recreate the device. For help debugging the problem, call Device.GetDeviceRemovedReason(). 
    /// <para>(Also see DirectX SDK:  DXGI_ERROR_DEVICE_REMOVED )</para>
    /// </summary>
    DeviceRemoved = DXGI_ERROR_DEVICE_REMOVED ,

    /// <summary>
    /// The device failed due to a badly formed command. This is a run-time issue; The application should destroy and recreate the device. 
    /// <para>(Also see DirectX SDK:  DXGI_ERROR_DEVICE_RESET )</para>
    /// </summary>
    DeviceReset = DXGI_ERROR_DEVICE_RESET ,
   
    /// <summary>
    /// The driver encountered a problem and was put into the device removed state. 
    /// <para>(Also see DirectX SDK:  DXGI_ERROR_DRIVER_INTERNAL_ERROR )</para>
    /// </summary>
    DriverInternalError = DXGI_ERROR_DRIVER_INTERNAL_ERROR ,
    
    /// <summary>
    /// The requested functionality is not supported by the device or the driver. 
    /// <para>(Also see DirectX SDK:  DXGI_ERROR_FRAME_STATISTICS_DISJOINT )</para>
    /// </summary>    
    FrameStatisticsDisjoint = DXGI_ERROR_FRAME_STATISTICS_DISJOINT ,

    /// <summary>
    /// The requested functionality is not supported by the device or the driver. 
    /// <para>(Also see DirectX SDK:  DXGI_ERROR_GRAPHICS_VIDPN_SOURCE_IN_USE )</para>
    /// </summary>
    GraphicsVidpnSourceInUse = DXGI_ERROR_GRAPHICS_VIDPN_SOURCE_IN_USE ,
    
    /// <summary>
    /// The application provided invalid parameter data; this must be debugged and fixed before the application is released. 
    /// <para>(Also see DirectX SDK:  DXGI_ERROR_INVALID_CALL )</para>
    /// </summary>
    InvalidCcall = DXGI_ERROR_INVALID_CALL ,
    
    /// <summary>
    /// The buffer supplied by the application is not big enough to hold the requested data. 
    /// <para>(Also see DirectX SDK:  DXGI_ERROR_MORE_DATA )</para>
    /// </summary>
    MoreData = DXGI_ERROR_MORE_DATA ,
   
    /// <summary>
    /// The application attempted to acquire exclusive ownership of an output, but failed because some other application (or device within the application) has already acquired ownership. 
    /// <para>(Also see DirectX SDK:  DXGI_ERROR_NONEXCLUSIVE )</para>
    /// </summary>
    NonExclusive = DXGI_ERROR_NONEXCLUSIVE ,
    
    /// <summary>
    /// The requested functionality is not supported by the device or the driver. 
    /// <para>(Also see DirectX SDK:  DXGI_ERROR_NOT_CURRENTLY_AVAILABLE )</para>
    /// </summary>
    NotCurrentlyAvailable = DXGI_ERROR_NOT_CURRENTLY_AVAILABLE ,

    /// <summary>
    /// When calling DXGIObject.GetPrivateData, the GUID passed in is not recognized as one previously passed to DXGIObject::SetPrivateData or DXGIObject::SetPrivateDataInterface. 
    /// When calling DXGIFactory::EnumAdapters or Adapter::EnumOutputs, the enumerated ordinal is out of range. 
    /// <para>(Also see DirectX SDK:  DXGI_ERROR_NOT_FOUND )</para>
    /// </summary>
    NotFound = DXGI_ERROR_NOT_FOUND ,
   
    /// <summary>
    /// The application's remote device has been removed due to session disconnect or network disconnect. The application should call IDXGIFactory1::IsCurrent to find out when the remote device becomes available again. 
    /// <para>(Also see DirectX SDK:  DXGI_ERROR_REMOTE_CLIENT_DISCONNECTED )</para>
    /// </summary>
    RemoteClientDisconnected = DXGI_ERROR_REMOTE_CLIENT_DISCONNECTED ,

    /// <summary>
    /// The application's remote device has failed due to lack of memory or machine error. The application should destroy and recreate resources using less memory. 
    /// <para>(Also see DirectX SDK:  DXGI_ERROR_REMOTE_OUTOFMEMORY )</para>
    /// </summary>
    RemoteOutOfMemory = DXGI_ERROR_REMOTE_OUTOFMEMORY ,
    
    /// <summary>
    /// The device was busy, and did not schedule the requested task. This error only applies to asynchronous queries in Direct3D 10 (see ID3D10Asynchronous Object). 
    /// <para>(Also see DirectX SDK:  DXGI_ERROR_WAS_STILL_DRAWING )</para>
    /// </summary>
    WasStillDrawing = DXGI_ERROR_WAS_STILL_DRAWING ,
   
    /// <summary>
    /// The requested functionality is not supported by the device or the driver. 
    /// <para>(Also see DirectX SDK:  DXGI_ERROR_UNSUPPORTED )</para>
    /// </summary>
    Unsupported = DXGI_ERROR_UNSUPPORTED ,   

    /// <summary>
    /// The file was not found. 
    /// <para>(Also see DirectX SDK:  D3D11_ERROR_FILE_NOT_FOUND )</para>
    /// </summary>
    FileNotFound =  D3D11_ERROR_FILE_NOT_FOUND,

    /// <summary>
    /// There are too many unique instances of a particular type of state object.
    /// <para>(Also see DirectX SDK:  D3D11_ERROR_TOO_MANY_UNIQUE_STATE_OBJECTS )</para>
    /// </summary>
    TooManyUniqueInstances =  D3D11_ERROR_TOO_MANY_UNIQUE_STATE_OBJECTS,

    /// <summary>
    /// An invalid parameter was passed to the returning function.
    /// </summary>
    InvalidArg =  E_INVALIDARG,

    /// <summary>
    /// Direct3D could not allocate sufficient memory to complete the call.
    /// </summary>
    OutOfMemory =  E_OUTOFMEMORY,

};
} } }  }
