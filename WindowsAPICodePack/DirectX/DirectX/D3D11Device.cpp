// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "D3D11Device.h"

#include "D3D11BlendState.h"
#include "D3D11Buffer.h"
#include "D3D11ClassLinkage.h"
#include "D3D11ComputeShader.h"
#include "D3D11Counter.h"
#include "D3D11DeviceContext.h"
#include "D3D11DepthStencilState.h"
#include "D3D11Resource.h"
#include "D3D11DepthStencilView.h"
#include "D3D11DomainShader.h"
#include "D3D11GeometryShader.h"
#include "D3D11HullShader.h"
#include "D3D11InputLayout.h"
#include "D3D11PixelShader.h"
#include "D3D11Predicate.h"
#include "D3D11Query.h"
#include "D3D11RasterizerState.h"
#include "D3D11RenderTargetView.h"
#include "D3D11SamplerState.h"
#include "D3D11ShaderResourceView.h"
#include "D3D11Texture1D.h"
#include "D3D11Texture2D.h"
#include "D3D11Texture3D.h"
#include "D3D11UnorderedAccessView.h"
#include "D3D11VertexShader.h"
#include "D3D11InfoQueue.h"
#include "D3D11SwitchToRef.h"
#include "DXGISwapChain.h"
#include "DXGIdevice.h"
#include "DXGIdevice1.h"
#include "IShaderBytecode.h"
#include <vector>


using namespace std;
using namespace System::Collections::Generic;

using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D11;
using namespace Microsoft::WindowsAPICodePack::DirectX::DXGI;


typedef HRESULT (*D3D11CreateDeviceAndSwapChainFuncPtr)
(
    IDXGIAdapter* pAdapter,
    D3D_DRIVER_TYPE DriverType,
    HMODULE Software,
    UINT Flags,
    CONST D3D_FEATURE_LEVEL* pFeatureLevels,
    UINT FeatureLevels,
    UINT SDKVersion,
    CONST DXGI_SWAP_CHAIN_DESC* pSwapChainDesc,
    IDXGISwapChain** ppSwapChain,
    ID3D11Device** ppDevice,
    D3D_FEATURE_LEVEL* pFeatureLevel,
    ID3D11DeviceContext** ppImmediateContext 
);

D3DDevice::D3DDevice(IntPtr windowHandle)  : d3dLibrary(0)
{
    HRESULT hr = S_OK;
#ifdef DXBETA
    wchar_t* libName = L"D3D11_BETA.dll"; // Only on beta
#else
    wchar_t* libName = L"D3D11.dll";
#endif
    d3dLibrary = D3DUtils::LoadDll(libName);

    D3D11CreateDeviceAndSwapChainFuncPtr createFuncPtr = 
        (D3D11CreateDeviceAndSwapChainFuncPtr) D3DUtils::GetFunctionfromDll(
            d3dLibrary, "D3D11CreateDeviceAndSwapChain");

    RECT rc;
    GetClientRect( (HWND)windowHandle.ToPointer(), &rc );
    UINT width = rc.right - rc.left;
    UINT height = rc.bottom - rc.top;

#ifdef _DEBUG
    UINT createDeviceFlags = D3D11_CREATE_DEVICE_DEBUG;
#else
    UINT createDeviceFlags = 0;
#endif

    DXGI_SWAP_CHAIN_DESC sd = {0};
    ZeroMemory( &sd, sizeof( sd ) );        

    sd.BufferCount = 1;
    
    sd.BufferDesc.Width = width;
    sd.BufferDesc.Height = height;
    sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    sd.BufferDesc.RefreshRate.Numerator = 60;
    sd.BufferDesc.RefreshRate.Denominator = 1;
    
    sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;        
    sd.OutputWindow = static_cast<HWND>(windowHandle.ToPointer());
    
    sd.SampleDesc.Count = 1;
    sd.SampleDesc.Quality = 0;
    sd.Windowed = TRUE;    

    sd.Flags = 0;
    sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

    ID3D11Device* tempDevice;
    ID3D11DeviceContext* tempDeviceContext;
    IDXGISwapChain* tempChain;
    D3D_FEATURE_LEVEL featureLevel;

    D3DUtils::VerifyResult((*createFuncPtr)(
        NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, createDeviceFlags, NULL, 0,
        D3D11_SDK_VERSION, &sd, &tempChain, &tempDevice, &featureLevel, &tempDeviceContext ) );

    nativeUnknown.Set(tempDevice);
    m_swapChain = gcnew SwapChain(tempChain) ;
    m_deviceContext = gcnew DeviceContext(tempDeviceContext);
}


bool D3DDevice::CheckCounter(CounterDescription^ description, [Runtime::InteropServices::Out] CounterType %outType, [Runtime::InteropServices::Out] UInt32 %outNumActiveCounters, [Runtime::InteropServices::Out] String^ %outName, [Runtime::InteropServices::Out] String^ %outUnits, [Runtime::InteropServices::Out] String^ %outDescription)
{
    System::Diagnostics::Debug::Assert(NativeID3D11Device != NULL);
    D3DUtils::CheckNull(description, "description");

    D3D11_COUNTER_TYPE tempoutType;
    
    UINT tempoutActiveCounters;
    
    UINT tempoutNameLength = D3DUtils::MaxNameSize;
    UINT tempoutUnitsLength = D3DUtils::MaxNameSize;
    UINT tempoutDescriptionLength = D3DUtils::MaxNameSize;

    LPSTR tempoutszName = new char[D3DUtils::MaxNameSize];
    LPSTR tempoutszUnits = new char[D3DUtils::MaxNameSize];
    LPSTR tempoutszDescription = new char[D3DUtils::MaxNameSize];

    bool succeeded = SUCCEEDED(NativeID3D11Device->CheckCounter(description->nativeObject.Get(), &tempoutType, &tempoutActiveCounters, tempoutszName, &tempoutNameLength, tempoutszUnits, &tempoutUnitsLength, tempoutszDescription, &tempoutDescriptionLength));
    
    if (succeeded)
    {
        outType = safe_cast<CounterType>(tempoutType);
        outNumActiveCounters = safe_cast<UInt32>(tempoutActiveCounters);
        outName = gcnew String(tempoutszName);
        outUnits = gcnew String(tempoutszUnits);
        outDescription = gcnew String(tempoutszDescription);
    }

    delete [] tempoutszName;
    delete [] tempoutszUnits;
    delete [] tempoutszDescription;

    return succeeded;
}

CounterInfo^ D3DDevice::GetCounterInformation()
{
    System::Diagnostics::Debug::Assert(NativeID3D11Device != NULL);

    D3D11_COUNTER_INFO* tempoutCounterInfo = new D3D11_COUNTER_INFO();
    NativeID3D11Device->CheckCounterInfo(tempoutCounterInfo);
    return gcnew CounterInfo(tempoutCounterInfo);
}

bool D3DDevice::CheckThreadingSupport( [Runtime::InteropServices::Out] FeatureDataThreading ^ %outFeatureData)
{
    System::Diagnostics::Debug::Assert(NativeID3D11Device != NULL);

    outFeatureData = nullptr;
    D3D11_FEATURE_DATA_THREADING* temp = new D3D11_FEATURE_DATA_THREADING();
    
    if(!SUCCEEDED(NativeID3D11Device->CheckFeatureSupport(D3D11_FEATURE_THREADING , temp, sizeof(D3D11_FEATURE_DATA_THREADING))))
    {
        delete temp;
        return false;
    }
    else
    {
        outFeatureData = gcnew FeatureDataThreading(temp);
        return true;
    }
}

bool D3DDevice::CheckFeatureDataDoubles( [Runtime::InteropServices::Out] FeatureDataDoubles ^ %outFeatureData)
{
    System::Diagnostics::Debug::Assert(NativeID3D11Device != NULL);

    outFeatureData = nullptr;
    D3D11_FEATURE_DATA_DOUBLES* temp = new D3D11_FEATURE_DATA_DOUBLES();
    
    if(!SUCCEEDED(NativeID3D11Device->CheckFeatureSupport(D3D11_FEATURE_DOUBLES , temp, sizeof(D3D11_FEATURE_DATA_DOUBLES))))
    {
        delete temp;
        return false;
    }
    else
    {    
        outFeatureData = gcnew FeatureDataDoubles(temp);
        return true;
    }
}

bool D3DDevice::CheckFeatureDataFormatSupport( [Runtime::InteropServices::In, Runtime::InteropServices::Out] FeatureDataFormatSupport^ %featureData)
{
    System::Diagnostics::Debug::Assert(NativeID3D11Device != NULL);

    D3D11_FEATURE_DATA_FORMAT_SUPPORT* temp = featureData->nativeObject.Get();
    
    return SUCCEEDED(NativeID3D11Device->CheckFeatureSupport(D3D11_FEATURE_FORMAT_SUPPORT , temp, sizeof(D3D11_FEATURE_DATA_FORMAT_SUPPORT)));
}

bool D3DDevice::CheckFeatureDataFormatSupport2([Runtime::InteropServices::In, Runtime::InteropServices::Out] FeatureDataFormatSupport2 ^ %featureData)
{
    System::Diagnostics::Debug::Assert(NativeID3D11Device != NULL);

    D3D11_FEATURE_DATA_FORMAT_SUPPORT2* temp = featureData->nativeObject.Get();
    
    return SUCCEEDED(NativeID3D11Device->CheckFeatureSupport(D3D11_FEATURE_FORMAT_SUPPORT2 , temp, sizeof(D3D11_FEATURE_DATA_FORMAT_SUPPORT2)));
}

bool D3DDevice::CheckFeatureDataD3D10XHardwareOptions( [Runtime::InteropServices::Out] FeatureDataD3D10XHardwareOptions ^ %outFeatureData)
{
    System::Diagnostics::Debug::Assert(NativeID3D11Device != NULL);

    outFeatureData = nullptr;
    D3D11_FEATURE_DATA_D3D10_X_HARDWARE_OPTIONS* temp = new D3D11_FEATURE_DATA_D3D10_X_HARDWARE_OPTIONS();
    
    if(!SUCCEEDED(NativeID3D11Device->CheckFeatureSupport(D3D11_FEATURE_D3D10_X_HARDWARE_OPTIONS , temp, sizeof(D3D11_FEATURE_DATA_D3D10_X_HARDWARE_OPTIONS))))
    {
        delete temp;
        return false;
    }
    else
    {
        outFeatureData = gcnew FeatureDataD3D10XHardwareOptions(temp);
        return true;
    }
}

FormatSupport D3DDevice::GetFormatSupport(Format format)
{
    System::Diagnostics::Debug::Assert(NativeID3D11Device != NULL);

    UINT tempoutFormatSupport = 0;
    
    D3DUtils::VerifyResult(NativeID3D11Device->CheckFormatSupport(safe_cast<DXGI_FORMAT>(format), &tempoutFormatSupport));
    
    return safe_cast<FormatSupport>(tempoutFormatSupport);
}

bool D3DDevice::TryGetFormatSupport(Format format, [Runtime::InteropServices::Out] FormatSupport % formatSupport )
{
    System::Diagnostics::Debug::Assert(NativeID3D11Device != NULL);

    UINT tempoutFormatSupport = 0;
    
    bool succeeded = SUCCEEDED(NativeID3D11Device->CheckFormatSupport(safe_cast<DXGI_FORMAT>(format), &tempoutFormatSupport));
    
    formatSupport =  safe_cast<FormatSupport>(tempoutFormatSupport);

    return succeeded;
}

UInt32 D3DDevice::GetMultisampleQualityLevels(Format format, UInt32 sampleCount)
{
    System::Diagnostics::Debug::Assert(NativeID3D11Device != NULL);

    UINT tempoutNumQualityLevels;
    D3DUtils::VerifyResult(NativeID3D11Device->CheckMultisampleQualityLevels(safe_cast<DXGI_FORMAT>(format), safe_cast<UINT>(sampleCount), &tempoutNumQualityLevels));
    return safe_cast<UInt32>(tempoutNumQualityLevels);
}

bool D3DDevice::TryGetMultisampleQualityLevels(Format format, UInt32 sampleCount, [Runtime::InteropServices::Out] UInt32 % multisampleQualityLevels)
{
    System::Diagnostics::Debug::Assert(NativeID3D11Device != NULL);

    UINT tempoutNumQualityLevels;
    bool succeeded = SUCCEEDED(NativeID3D11Device->CheckMultisampleQualityLevels(safe_cast<DXGI_FORMAT>(format), safe_cast<UINT>(sampleCount), &tempoutNumQualityLevels));

    if (succeeded) 
        multisampleQualityLevels = safe_cast<UInt32>(tempoutNumQualityLevels);

    return succeeded;
}

BlendState^ D3DDevice::CreateBlendState(BlendDescription^ description)
{
    System::Diagnostics::Debug::Assert(NativeID3D11Device != NULL);
    D3DUtils::CheckNull(description, "description");

    ID3D11BlendState* tempoutBlendState = NULL;
    D3DUtils::VerifyResult(NativeID3D11Device->CreateBlendState(description->nativeObject.Get(), &tempoutBlendState));
    
    return tempoutBlendState == NULL ? nullptr : gcnew BlendState(tempoutBlendState);

}
D3DBuffer^ D3DDevice::CreateBuffer(BufferDescription^ description, SubresourceData^ initialData)
{
    System::Diagnostics::Debug::Assert(NativeID3D11Device != NULL);
    D3DUtils::CheckNull(description, "description");

    ID3D11Buffer* tempoutBuffer = NULL;

    D3DUtils::VerifyResult(NativeID3D11Device->CreateBuffer(
        description->nativeObject.Get(), 
        initialData == nullptr ? NULL : initialData->nativeObject.Get(), 
        &tempoutBuffer));

    return tempoutBuffer == NULL ? nullptr : gcnew D3DBuffer(tempoutBuffer);
}

D3DBuffer^ D3DDevice::CreateBuffer(BufferDescription^ description)
{
    System::Diagnostics::Debug::Assert(NativeID3D11Device != NULL);
    D3DUtils::CheckNull(description, "description");

    ID3D11Buffer* tempoutBuffer = NULL;

    D3DUtils::VerifyResult(NativeID3D11Device->CreateBuffer(
        description->nativeObject.Get(), 
        NULL, 
        &tempoutBuffer));

    return tempoutBuffer == NULL ? nullptr : gcnew D3DBuffer(tempoutBuffer);
}
ClassLinkage^ D3DDevice::CreateClassLinkage()
{
    System::Diagnostics::Debug::Assert(NativeID3D11Device != NULL);

    ID3D11ClassLinkage* tempoutLinkage = NULL;
    D3DUtils::VerifyResult(NativeID3D11Device->CreateClassLinkage(&tempoutLinkage));
    return tempoutLinkage == NULL ? nullptr : gcnew ClassLinkage(tempoutLinkage);
}


Counter^ D3DDevice::CreateCounter(CounterDescription^ description)
{
    System::Diagnostics::Debug::Assert(NativeID3D11Device != NULL);
    D3DUtils::CheckNull(description, "description");

    ID3D11Counter* tempoutCounter = NULL;
    D3DUtils::VerifyResult(NativeID3D11Device->CreateCounter(description->nativeObject.Get(), &tempoutCounter));
    
    return tempoutCounter == NULL ? nullptr : gcnew Counter(tempoutCounter);
}

DeviceContext^ D3DDevice::CreateDeferredContext(UInt32 contextFlags)
{
    System::Diagnostics::Debug::Assert(NativeID3D11Device != NULL);

    ID3D11DeviceContext* tempoutDeferredContext = NULL;
    D3DUtils::VerifyResult(NativeID3D11Device->CreateDeferredContext(safe_cast<UINT>(contextFlags), &tempoutDeferredContext));
    return tempoutDeferredContext == NULL ? nullptr : gcnew DeviceContext(tempoutDeferredContext);

}

DepthStencilState^ D3DDevice::CreateDepthStencilState(DepthStencilDescription^ description)
{
    System::Diagnostics::Debug::Assert(NativeID3D11Device != NULL);
    D3DUtils::CheckNull(description, "description");

    ID3D11DepthStencilState* tempoutDepthStencilState = NULL;
    D3DUtils::VerifyResult(NativeID3D11Device->CreateDepthStencilState(description->nativeObject.Get(), &tempoutDepthStencilState));
    return tempoutDepthStencilState == NULL ? nullptr : gcnew DepthStencilState(tempoutDepthStencilState);
}

DepthStencilView^  D3DDevice::CreateDepthStencilView(D3DResource^ resource, DepthStencilViewDescription^ description)
{
    System::Diagnostics::Debug::Assert(NativeID3D11Device != NULL);
    D3DUtils::CheckNull(resource, "resource");

    ID3D11DepthStencilView* tempoutDepthStencilView = NULL;
    D3DUtils::VerifyResult(NativeID3D11Device->CreateDepthStencilView(
        resource->NativeID3D11Resource, 
        description == nullptr ? NULL : description->nativeObject.Get(), 
        &tempoutDepthStencilView));

    return tempoutDepthStencilView == NULL ? nullptr : gcnew DepthStencilView(tempoutDepthStencilView);
}

ComputeShader^ D3DDevice::CreateComputeShader(IShaderBytecode^ shaderBytecode, ClassLinkage^ classLinkage)
{
    System::Diagnostics::Debug::Assert(NativeID3D11Device != NULL);
    D3DUtils::CheckNull(shaderBytecode, "shaderBytecode");

    ID3D11ComputeShader* tempShader = NULL;
    D3DUtils::VerifyResult(NativeID3D11Device->CreateComputeShader(
        shaderBytecode->ShaderBytecode.ToPointer(), 
        shaderBytecode->ShaderBytecodeLength, 
        classLinkage == nullptr ? NULL : classLinkage->NativeID3D11ClassLinkage, 
        &tempShader));

    return tempShader == NULL ? nullptr : gcnew ComputeShader(tempShader);

}

ComputeShader^ D3DDevice::CreateComputeShader(IShaderBytecode^ shaderBytecode)
{
    System::Diagnostics::Debug::Assert(NativeID3D11Device != NULL);
    D3DUtils::CheckNull(shaderBytecode, "shaderBytecode");

    ID3D11ComputeShader* tempShader = NULL;
    D3DUtils::VerifyResult(NativeID3D11Device->CreateComputeShader(
        shaderBytecode->ShaderBytecode.ToPointer(), 
        shaderBytecode->ShaderBytecodeLength, 
        NULL, 
        &tempShader));

    return tempShader == NULL ? nullptr : gcnew ComputeShader(tempShader);

}

DomainShader^ D3DDevice::CreateDomainShader(IShaderBytecode^ shaderBytecode, ClassLinkage^ classLinkage)
{
    System::Diagnostics::Debug::Assert(NativeID3D11Device != NULL);
    D3DUtils::CheckNull(shaderBytecode, "shaderBytecode");

    ID3D11DomainShader* tempShader = NULL;
    D3DUtils::VerifyResult(NativeID3D11Device->CreateDomainShader(
        shaderBytecode->ShaderBytecode.ToPointer(), 
        shaderBytecode->ShaderBytecodeLength, 
        classLinkage == nullptr ? NULL : classLinkage->NativeID3D11ClassLinkage, 
        &tempShader));

    return tempShader == NULL ? nullptr : gcnew DomainShader(tempShader);

}

DomainShader^ D3DDevice::CreateDomainShader(IShaderBytecode^ shaderBytecode)
{
    System::Diagnostics::Debug::Assert(NativeID3D11Device != NULL);
    D3DUtils::CheckNull(shaderBytecode, "shaderBytecode");

    ID3D11DomainShader* tempShader = NULL;
    D3DUtils::VerifyResult(NativeID3D11Device->CreateDomainShader(
        shaderBytecode->ShaderBytecode.ToPointer(), 
        shaderBytecode->ShaderBytecodeLength, 
        NULL, 
        &tempShader));

    return tempShader == NULL ? nullptr : gcnew DomainShader(tempShader);

}


GeometryShader^ D3DDevice::CreateGeometryShader(IShaderBytecode^ shaderBytecode, ClassLinkage^ classLinkage)
{
    System::Diagnostics::Debug::Assert(NativeID3D11Device != NULL);
    D3DUtils::CheckNull(shaderBytecode, "shaderBytecode");

    ID3D11GeometryShader* tempShader = NULL;
    D3DUtils::VerifyResult(NativeID3D11Device->CreateGeometryShader(
        shaderBytecode->ShaderBytecode.ToPointer(), 
        shaderBytecode->ShaderBytecodeLength, 
        classLinkage == nullptr ? NULL : classLinkage->NativeID3D11ClassLinkage, 
        &tempShader));

    return tempShader == NULL ? nullptr : gcnew GeometryShader(tempShader);
}

GeometryShader^ D3DDevice::CreateGeometryShader(IShaderBytecode^ shaderBytecode)
{
    System::Diagnostics::Debug::Assert(NativeID3D11Device != NULL);
    D3DUtils::CheckNull(shaderBytecode, "shaderBytecode");

    ID3D11GeometryShader* tempShader = NULL;
    D3DUtils::VerifyResult(NativeID3D11Device->CreateGeometryShader(
        shaderBytecode->ShaderBytecode.ToPointer(), 
        shaderBytecode->ShaderBytecodeLength, 
        NULL, 
        &tempShader));

    return tempShader == NULL ? nullptr : gcnew GeometryShader(tempShader);
}

GeometryShader^ D3DDevice::CreateGeometryShaderWithStreamOutput(IShaderBytecode^ shaderBytecode, ICollection<SoDeclarationEntry^>^ SODeclarations, 
    ICollection<UInt32>^ bufferStrides, UInt32 rasterizedStream, ClassLinkage^ classLinkage)
{
    System::Diagnostics::Debug::Assert(NativeID3D11Device != NULL);
    D3DUtils::CheckNull(shaderBytecode, "shaderBytecode");

    ID3D11GeometryShader* tempoutGeometryShader = NULL;

    UINT declEntriesLen = SODeclarations == nullptr ? 0 : SODeclarations->Count;

    vector<D3D11_SO_DECLARATION_ENTRY> declEntries(declEntriesLen);

    if (declEntriesLen > 0)
    {
        int i = 0;
        for each(SoDeclarationEntry^ entry in SODeclarations)
        {
            declEntries[i++] =  *(entry->nativeObject.Get());
        }
    }

    pin_ptr<UInt32> strides;
    
    if (bufferStrides->Count > 0)
    {
        array<UInt32>^ arr = gcnew array<UInt32>(bufferStrides->Count);
        strides = &(arr[ 0 ]);
    }

    D3DUtils::VerifyResult(
        NativeID3D11Device->CreateGeometryShaderWithStreamOutput(
        shaderBytecode->ShaderBytecode.ToPointer(), 
        shaderBytecode->ShaderBytecodeLength, 
        declEntriesLen == 0 ? NULL : &declEntries[0], 
        declEntriesLen, 
        strides, 
        safe_cast<UINT>(bufferStrides->Count), 
        safe_cast<UINT>(rasterizedStream), 
        classLinkage == nullptr ? NULL : classLinkage->NativeID3D11ClassLinkage, 
        &tempoutGeometryShader));

        return tempoutGeometryShader == NULL ? nullptr : gcnew GeometryShader(tempoutGeometryShader);
}

HullShader^ D3DDevice::CreateHullShader(IShaderBytecode^ shaderBytecode, ClassLinkage^ classLinkage)
{
    System::Diagnostics::Debug::Assert(NativeID3D11Device != NULL);
    D3DUtils::CheckNull(shaderBytecode, "shaderBytecode");

    ID3D11HullShader* tempShader = NULL;
    D3DUtils::VerifyResult(NativeID3D11Device->CreateHullShader(
        shaderBytecode->ShaderBytecode.ToPointer(), 
        shaderBytecode->ShaderBytecodeLength, 
        classLinkage == nullptr ? NULL : classLinkage->NativeID3D11ClassLinkage, 
        &tempShader));

    return tempShader == NULL ? nullptr : gcnew HullShader(tempShader);
}

HullShader^ D3DDevice::CreateHullShader(IShaderBytecode^ shaderBytecode)
{
    System::Diagnostics::Debug::Assert(NativeID3D11Device != NULL);
    D3DUtils::CheckNull(shaderBytecode, "shaderBytecode");

    ID3D11HullShader* tempShader = NULL;
    D3DUtils::VerifyResult(NativeID3D11Device->CreateHullShader(
        shaderBytecode->ShaderBytecode.ToPointer(), 
        shaderBytecode->ShaderBytecodeLength, 
        NULL, 
        &tempShader));

    return tempShader == NULL ? nullptr : gcnew HullShader(tempShader);
}

InputLayout^ D3DDevice::CreateInputLayout(
    IEnumerable<InputElementDescription^>^ inputElementDescriptions, 
    IntPtr shaderBytecodeWithInputSignature, 
    UInt32 shaderBytecodeWithInputSignatureSize)
{
    System::Diagnostics::Debug::Assert(NativeID3D11Device != NULL);
    D3DUtils::CheckNull(inputElementDescriptions, "inputElementDescriptions");


    vector<D3D11_INPUT_ELEMENT_DESC> inputElements;
    
    UINT i = 0;
    for each(InputElementDescription^ desc in inputElementDescriptions)
    {
        inputElements.push_back( *(desc->nativeObject.Get()));
    }
    UINT len = (UINT)inputElements.size();

    ID3D11InputLayout* tempoutInputLayout = NULL;

    D3DUtils::VerifyResult(
        NativeID3D11Device->CreateInputLayout(
        len == 0 ? NULL : &inputElements[0],
        len,
        shaderBytecodeWithInputSignature.ToPointer(), 
        shaderBytecodeWithInputSignatureSize, 
        &tempoutInputLayout));

    return tempoutInputLayout == NULL ? nullptr : gcnew InputLayout(tempoutInputLayout);
}

InputLayout^ D3DDevice::CreateInputLayout(
       IEnumerable<InputElementDescription^>^ inputElementDescriptions, 
       IShaderBytecode^ shaderBytecodeWithInputSignature)
{
    D3DUtils::CheckNull(shaderBytecodeWithInputSignature, "shaderBytecodeWithInputSignature");

    return CreateInputLayout(inputElementDescriptions, shaderBytecodeWithInputSignature->ShaderBytecode, shaderBytecodeWithInputSignature->ShaderBytecodeLength);
}


PixelShader^ D3DDevice::CreatePixelShader(IShaderBytecode^ shaderBytecode, ClassLinkage^ classLinkage)
{
    System::Diagnostics::Debug::Assert(NativeID3D11Device != NULL);
    D3DUtils::CheckNull(shaderBytecode, "shaderBytecode");

    ID3D11PixelShader* tempoutPixelShader = NULL;
    D3DUtils::VerifyResult(
        NativeID3D11Device->CreatePixelShader(
            shaderBytecode->ShaderBytecode.ToPointer(), 
            shaderBytecode->ShaderBytecodeLength, 
            classLinkage == nullptr ? NULL : classLinkage->NativeID3D11ClassLinkage, 
            &tempoutPixelShader));
    
    return tempoutPixelShader == NULL ? nullptr : gcnew PixelShader(tempoutPixelShader);
}

PixelShader^ D3DDevice::CreatePixelShader(IShaderBytecode^ shaderBytecode)
{
    System::Diagnostics::Debug::Assert(NativeID3D11Device != NULL);
    D3DUtils::CheckNull(shaderBytecode, "shaderBytecode");

    ID3D11PixelShader* tempoutPixelShader = NULL;
    D3DUtils::VerifyResult(
        NativeID3D11Device->CreatePixelShader(
            shaderBytecode->ShaderBytecode.ToPointer(), 
            shaderBytecode->ShaderBytecodeLength, 
            NULL, 
            &tempoutPixelShader));
    
    return tempoutPixelShader == NULL ? nullptr : gcnew PixelShader(tempoutPixelShader);
}

D3DPredicate^ D3DDevice::CreatePredicate(QueryDescription^ description)
{
    System::Diagnostics::Debug::Assert(NativeID3D11Device != NULL);
    D3DUtils::CheckNull(description, "description");

    ID3D11Predicate* tempoutPredicate = NULL;
    D3DUtils::VerifyResult(NativeID3D11Device->CreatePredicate(description->nativeObject.Get(), &tempoutPredicate));
    return tempoutPredicate == NULL ? nullptr : gcnew D3DPredicate(tempoutPredicate);

}

D3DQuery^ D3DDevice::CreateQuery(QueryDescription^ description)
{
    System::Diagnostics::Debug::Assert(NativeID3D11Device != NULL);
    D3DUtils::CheckNull(description, "description");

    ID3D11Query* tempoutQuery = NULL;
    D3DUtils::VerifyResult(NativeID3D11Device->CreateQuery(description->nativeObject.Get(), &tempoutQuery));
    return tempoutQuery == NULL ? nullptr : gcnew D3DQuery(tempoutQuery);

}

RasterizerState^ D3DDevice::CreateRasterizerState(RasterizerDescription^ description)
{
    System::Diagnostics::Debug::Assert(NativeID3D11Device != NULL);
    D3DUtils::CheckNull(description, "description");

    ID3D11RasterizerState* tempoutRasterizerState = NULL;
    D3DUtils::VerifyResult(NativeID3D11Device->CreateRasterizerState(description->nativeObject.Get(), &tempoutRasterizerState));
    return tempoutRasterizerState == NULL ? nullptr : gcnew RasterizerState(tempoutRasterizerState);

}


RenderTargetView^ D3DDevice::CreateRenderTargetView(D3DResource^ resource, RenderTargetViewDescription^ description)
{
    System::Diagnostics::Debug::Assert(NativeID3D11Device != NULL);
    D3DUtils::CheckNull(resource, "resource");

    ID3D11RenderTargetView* tempoutRTView = NULL;
    D3DUtils::VerifyResult(
        NativeID3D11Device->CreateRenderTargetView(
        resource->NativeID3D11Resource, 
        description == nullptr ? NULL : description->nativeObject.Get(), 
        &tempoutRTView));
    return  tempoutRTView == NULL ? nullptr : gcnew RenderTargetView(tempoutRTView);

}

SamplerState^ D3DDevice::CreateSamplerState(SamplerDescription^ description)
{
    System::Diagnostics::Debug::Assert(NativeID3D11Device != NULL);
    D3DUtils::CheckNull(description, "description");

    ID3D11SamplerState* tempoutSamplerState = NULL;
    D3DUtils::VerifyResult(NativeID3D11Device->CreateSamplerState(description->nativeObject.Get(), &tempoutSamplerState));
    return tempoutSamplerState == NULL ? nullptr : gcnew SamplerState(tempoutSamplerState);
}

ShaderResourceView^ D3DDevice::CreateShaderResourceView(D3DResource^ resource, ShaderResourceViewDescription^ description)
{
    System::Diagnostics::Debug::Assert(NativeID3D11Device != NULL);
    D3DUtils::CheckNull(resource, "resource");

    ID3D11ShaderResourceView* tempoutSRView = NULL;
    D3DUtils::VerifyResult(NativeID3D11Device->CreateShaderResourceView(
        resource->NativeID3D11Resource, 
        description == nullptr ? NULL : description->nativeObject.Get(), 
        &tempoutSRView));

    return tempoutSRView == NULL ? nullptr : gcnew ShaderResourceView(tempoutSRView);
}

Texture1D^ D3DDevice::CreateTexture1D(Texture1dDescription^ description, SubresourceData^ initialData)
{
    System::Diagnostics::Debug::Assert(NativeID3D11Device != NULL);
    D3DUtils::CheckNull(description, "description");

    ID3D11Texture1D* tempoutTexture1D = NULL;
    D3DUtils::VerifyResult(NativeID3D11Device->CreateTexture1D(
        description->nativeObject.Get(), 
        initialData == nullptr ? NULL : initialData->nativeObject.Get(), 
        &tempoutTexture1D));
    
    return tempoutTexture1D == NULL ? nullptr : gcnew Texture1D(tempoutTexture1D);
}

Texture2D^ D3DDevice::CreateTexture2D(Texture2dDescription^ description, SubresourceData^ initialData)
{
    System::Diagnostics::Debug::Assert(NativeID3D11Device != NULL);
    D3DUtils::CheckNull(description, "description");

    ID3D11Texture2D* tempoutTexture2D = NULL;
    D3DUtils::VerifyResult(NativeID3D11Device->CreateTexture2D(
        description->nativeObject.Get(), 
        initialData == nullptr ? NULL : initialData->nativeObject.Get(), 
        &tempoutTexture2D));

    return tempoutTexture2D == NULL ? nullptr : gcnew Texture2D(tempoutTexture2D);
}

Texture3D^ D3DDevice::CreateTexture3D(Texture3dDescription^ description, SubresourceData^ initialData)
{
    System::Diagnostics::Debug::Assert(NativeID3D11Device != NULL);
    D3DUtils::CheckNull(description, "description");

    ID3D11Texture3D* tempoutTexture3D = NULL;
    D3DUtils::VerifyResult(
        NativeID3D11Device->CreateTexture3D(
            description->nativeObject.Get(), 
            initialData == nullptr ? NULL : initialData->nativeObject.Get(), 
            &tempoutTexture3D));
    return tempoutTexture3D == NULL ? nullptr : gcnew Texture3D(tempoutTexture3D);
}

Texture1D^ D3DDevice::CreateTexture1D(Texture1dDescription^ description)
{
    System::Diagnostics::Debug::Assert(NativeID3D11Device != NULL);
    D3DUtils::CheckNull(description, "description");

    ID3D11Texture1D* tempoutTexture1D = NULL;
    D3DUtils::VerifyResult(NativeID3D11Device->CreateTexture1D(
        description->nativeObject.Get(), 
        NULL, 
        &tempoutTexture1D));
    
    return tempoutTexture1D == NULL ? nullptr : gcnew Texture1D(tempoutTexture1D);
}

Texture2D^ D3DDevice::CreateTexture2D(Texture2dDescription^ description)
{
    System::Diagnostics::Debug::Assert(NativeID3D11Device != NULL);
    D3DUtils::CheckNull(description, "description");

    ID3D11Texture2D* tempoutTexture2D = NULL;
    D3DUtils::VerifyResult(NativeID3D11Device->CreateTexture2D(
        description->nativeObject.Get(), 
        NULL, 
        &tempoutTexture2D));

    return tempoutTexture2D == NULL ? nullptr : gcnew Texture2D(tempoutTexture2D);
}

Texture3D^ D3DDevice::CreateTexture3D(Texture3dDescription^ description)
{
    System::Diagnostics::Debug::Assert(NativeID3D11Device != NULL);
    D3DUtils::CheckNull(description, "description");

    ID3D11Texture3D* tempoutTexture3D = NULL;
    D3DUtils::VerifyResult(
        NativeID3D11Device->CreateTexture3D(
            description->nativeObject.Get(), 
            NULL, 
            &tempoutTexture3D));
    return tempoutTexture3D == NULL ? nullptr : gcnew Texture3D(tempoutTexture3D);
}

UnorderedAccessView^ D3DDevice::CreateUnorderedAccessView(D3DResource^ resource, UnorderedAccessViewDescription^ description)
{
    System::Diagnostics::Debug::Assert(NativeID3D11Device != NULL);
    D3DUtils::CheckNull(resource, "resource");

    ID3D11UnorderedAccessView* tempoutUAView = NULL;
    D3DUtils::VerifyResult(
        NativeID3D11Device->CreateUnorderedAccessView(
            resource->NativeID3D11Resource, 
            description == nullptr ? NULL : description->nativeObject.Get(), 
            &tempoutUAView));
    
    return tempoutUAView == NULL ? nullptr : gcnew UnorderedAccessView(tempoutUAView);
}

VertexShader^ D3DDevice::CreateVertexShader(IShaderBytecode^ shaderBytecode, ClassLinkage^ classLinkage)
{
    System::Diagnostics::Debug::Assert(NativeID3D11Device != NULL);
    D3DUtils::CheckNull(shaderBytecode, "shaderBytecode");

    ID3D11VertexShader* tempoutVertexShader = NULL;
    D3DUtils::VerifyResult(
        NativeID3D11Device->CreateVertexShader(
            shaderBytecode->ShaderBytecode.ToPointer(), 
            shaderBytecode->ShaderBytecodeLength, 
            classLinkage == nullptr ? NULL : classLinkage->NativeID3D11ClassLinkage, 
            &tempoutVertexShader));
    
    return tempoutVertexShader == NULL ? nullptr : gcnew VertexShader(tempoutVertexShader);

}

VertexShader^ D3DDevice::CreateVertexShader(IShaderBytecode^ shaderBytecode)
{
    System::Diagnostics::Debug::Assert(NativeID3D11Device != NULL);
    D3DUtils::CheckNull(shaderBytecode, "shaderBytecode");

    ID3D11VertexShader* tempoutVertexShader = NULL;
    D3DUtils::VerifyResult(
        NativeID3D11Device->CreateVertexShader(
            shaderBytecode->ShaderBytecode.ToPointer(), 
            shaderBytecode->ShaderBytecodeLength, 
            NULL, 
            &tempoutVertexShader));
    
    return tempoutVertexShader == NULL ? nullptr : gcnew VertexShader(tempoutVertexShader);

}

CreateDeviceFlag D3DDevice::CreationFlags::get()
{
    System::Diagnostics::Debug::Assert(NativeID3D11Device != NULL);

    UINT returnValue = NativeID3D11Device->GetCreationFlags();
    return safe_cast<CreateDeviceFlag>(returnValue);

}

ErrorCode D3DDevice::DeviceRemovedReason::get()
{
    System::Diagnostics::Debug::Assert(NativeID3D11Device != NULL);

    return safe_cast<ErrorCode>(NativeID3D11Device->GetDeviceRemovedReason());

}

RaiseFlag D3DDevice::ExceptionMode::get()
{
    System::Diagnostics::Debug::Assert(NativeID3D11Device != NULL);

    UINT returnValue = NativeID3D11Device->GetExceptionMode();
    return safe_cast<RaiseFlag>(returnValue);

}

void D3DDevice::ExceptionMode::set(RaiseFlag value)
{
    System::Diagnostics::Debug::Assert(NativeID3D11Device != NULL);

    D3DUtils::VerifyResult(NativeID3D11Device->SetExceptionMode(safe_cast<UINT>(value)));

}


DeviceContext^ D3DDevice::GetImmediateContext()
{
    System::Diagnostics::Debug::Assert(NativeID3D11Device != NULL);

    ID3D11DeviceContext* tempoutImmediateContext = NULL;
    NativeID3D11Device->GetImmediateContext(&tempoutImmediateContext);
    return tempoutImmediateContext == NULL ? nullptr : gcnew DeviceContext(tempoutImmediateContext);

}

InfoQueue ^ D3DDevice::GetInfoQueue()
{
    System::Diagnostics::Debug::Assert(NativeID3D11Device != NULL);
    ID3D11InfoQueue * infoQueue = NULL;

    D3DUtils::VerifyResult(NativeID3D11Device->QueryInterface(__uuidof(ID3D11InfoQueue), (void**) &infoQueue));

    return infoQueue == NULL ? nullptr : gcnew InfoQueue(infoQueue);
}

SwitchToRef ^ D3DDevice::GetSwitchToRef()
{
    System::Diagnostics::Debug::Assert(NativeID3D11Device != NULL);
    ID3D11SwitchToRef * switchToRef = NULL;

    D3DUtils::VerifyResult(NativeID3D11Device->QueryInterface(__uuidof(ID3D11SwitchToRef), (void**) &switchToRef));

    return switchToRef == NULL ? nullptr : gcnew SwitchToRef(switchToRef);
}

generic <typename T>
T D3DDevice::OpenSharedResource(ResourceHandle^ resource)
{
    System::Diagnostics::Debug::Assert(NativeID3D11Device != NULL);

    void* tempoutResource = NULL;

    GUID guid = D3DUtils::GetGuid(T::typeid);
    
    D3DUtils::VerifyResult(NativeID3D11Device->OpenSharedResource(safe_cast<HANDLE>(resource->Handle), guid, &tempoutResource));
    
    return safe_cast<T>(D3DUtils::CreateObjectFromPointer<T>(tempoutResource));
}

FeatureLevel D3DDevice::DeviceFeatureLevel::get()
{
    System::Diagnostics::Debug::Assert(NativeID3D11Device != NULL);

    D3D_FEATURE_LEVEL returnValue = NativeID3D11Device->GetFeatureLevel();
    return safe_cast<FeatureLevel>(returnValue);
}

DeviceContext^ D3DDevice::Context::get()
{
    return m_deviceContext;
}

