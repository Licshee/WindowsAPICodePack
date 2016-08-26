//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once

using namespace System;
using namespace System::Windows;
using namespace System::Windows::Interop;
using namespace System::Runtime::InteropServices;

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3DControls {

public delegate void RenderHandler();

public ref class DirectHost : public HwndHost
{
private:
	HWND m_hWnd;
	HINSTANCE m_hInstance;
	LPCWSTR m_sWindowName;
	LPCWSTR m_sClassName;
    double m_width, m_height;

	bool RegisterWindowClass();

public:
    DirectHost(double width, double height) : 
				m_hWnd(NULL),
				m_hInstance(NULL),
				m_sWindowName(NULL),
				m_sClassName(NULL),
                m_width(width), m_height(height)
		{
		}


protected:
    virtual HandleRef BuildWindowCore(HandleRef hwndParent) override;
	
    virtual void OnRender(System::Windows::Media::DrawingContext^ drawingContext) override;

	virtual IntPtr WndProc(IntPtr hwnd, int msg, IntPtr wParam, IntPtr lParam, bool% handled) override;
    
    virtual void DestroyWindowCore(HandleRef hwnd) override;
    
public: 
    RenderHandler^ Render;
};
}}}}