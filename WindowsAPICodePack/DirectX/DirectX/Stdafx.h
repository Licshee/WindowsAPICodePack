// Copyright (c) Microsoft Corporation.  All rights reserved.

// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently,
// but are changed infrequently

#pragma once

// Exclude rarely used parts of the windows headers
#define WIN32_LEAN_AND_MEAN

//Define Unicode
#ifndef UNICODE
#define UNICODE
#endif

//Windows Headers
#include <vcclr.h>
#include <Windows.h>


//DirectX Headers
#include <D3D10_1.h>
#include <D3D10.h>
#include <D3D11.h>
#include <DXGI.h>
#include <DXGIType.h>
#include "D3DCommon.h"

// Common Includes
#include "AutoPointer.h"
#include "AutoIUnknown.h"
#include "Direct3DException.h"
#include "DXGIException.h"
#include "CommonUtils.h"

// Common Types
#include "CommonEnums.h"
#include "CommonStructs.h"
#include "DXGIEnums.h"
#include "DXGIStructs.h"
#include "D3D11Enums.h"
#include "D3D11Structs.h"


