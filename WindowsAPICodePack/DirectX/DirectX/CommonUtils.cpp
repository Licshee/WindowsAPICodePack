//Copyright (c) Microsoft Corporation.  All rights reserved.

#include "StdAfx.h"
#include "CommonUtils.h"
#include "AllTypes.h"

using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3DCommon;

// TODO: Replace with type specific properties
GUID D3DUtils::GetGuid(System::Type^ type)
{
    return GUIDFromSystemGuid(GuidsDictionary[type]);
}

generic <typename T> where T : DirectUnknown
T D3DUtils::CreateInterfaceWrapper(System::IntPtr nativePtr)
{
    if (nativePtr == IntPtr::Zero)
    {
        throw gcnew ArgumentNullException("nativePtr", "The native pointer cannot be Null.");
    }

    return safe_cast<T>(D3DUtils::CreateObjectFromPointer<T>(nativePtr.ToPointer()));
}


generic <typename T> where T : DirectObject
T D3DUtils::CreateObjectWrapper(System::IntPtr nativePtr)
{
    if (nativePtr == IntPtr::Zero)
    {
        throw gcnew ArgumentNullException("nativePtr", "The native pointer cannot be Null.");
    }

    return safe_cast<T>(D3DUtils::CreateObjectFromPointer<T>(nativePtr.ToPointer()));
}

// TODO: Replace with generic constructors
generic <typename T>
T D3DUtils::CreateObjectFromPointer(void* ptr)
{
    if (T::typeid == Microsoft::WindowsAPICodePack::DirectX::Direct3D11::Asynchronous::typeid)
        return safe_cast<T>(gcnew Microsoft::WindowsAPICodePack::DirectX::Direct3D11::Asynchronous((ID3D11Asynchronous*)ptr));
    else if (T::typeid == Microsoft::WindowsAPICodePack::DirectX::Direct3D11::Asynchronous::typeid)   
        return safe_cast<T>(gcnew Microsoft::WindowsAPICodePack::DirectX::Direct3D11::Asynchronous((ID3D11Asynchronous*)ptr));
    else if (T::typeid == Microsoft::WindowsAPICodePack::DirectX::Direct3D11::BlendState::typeid)   
        return safe_cast<T>(gcnew Microsoft::WindowsAPICodePack::DirectX::Direct3D11::BlendState((ID3D11BlendState*)ptr));
    else if (T::typeid == Microsoft::WindowsAPICodePack::DirectX::Direct3D11::D3DBuffer::typeid)   
        return safe_cast<T>(gcnew Microsoft::WindowsAPICodePack::DirectX::Direct3D11::D3DBuffer((ID3D11Buffer*)ptr));
    else if (T::typeid == Microsoft::WindowsAPICodePack::DirectX::Direct3D11::ClassInstance::typeid)   
        return safe_cast<T>(gcnew Microsoft::WindowsAPICodePack::DirectX::Direct3D11::ClassInstance((ID3D11ClassInstance*)ptr));
    else if (T::typeid == Microsoft::WindowsAPICodePack::DirectX::Direct3D11::ClassLinkage::typeid)   
        return safe_cast<T>(gcnew Microsoft::WindowsAPICodePack::DirectX::Direct3D11::ClassLinkage((ID3D11ClassLinkage*)ptr));
    else if (T::typeid == Microsoft::WindowsAPICodePack::DirectX::Direct3D11::CommandList::typeid)   
        return safe_cast<T>(gcnew Microsoft::WindowsAPICodePack::DirectX::Direct3D11::CommandList((ID3D11CommandList*)ptr));
    else if (T::typeid == Microsoft::WindowsAPICodePack::DirectX::Direct3D11::ComputeShader::typeid)   
        return safe_cast<T>(gcnew Microsoft::WindowsAPICodePack::DirectX::Direct3D11::ComputeShader((ID3D11ComputeShader*)ptr));
    else if (T::typeid == Microsoft::WindowsAPICodePack::DirectX::Direct3D11::Counter::typeid)   
        return safe_cast<T>(gcnew Microsoft::WindowsAPICodePack::DirectX::Direct3D11::Counter((ID3D11Counter*)ptr));
    else if (T::typeid == Microsoft::WindowsAPICodePack::DirectX::Direct3D11::D3DDebug::typeid)   
        return safe_cast<T>(gcnew Microsoft::WindowsAPICodePack::DirectX::Direct3D11::D3DDebug((ID3D11Debug*)ptr));
    else if (T::typeid == Microsoft::WindowsAPICodePack::DirectX::Direct3D11::DepthStencilState::typeid)   
        return safe_cast<T>(gcnew Microsoft::WindowsAPICodePack::DirectX::Direct3D11::DepthStencilState((ID3D11DepthStencilState*)ptr));
    else if (T::typeid == Microsoft::WindowsAPICodePack::DirectX::Direct3D11::DepthStencilView::typeid)   
        return safe_cast<T>(gcnew Microsoft::WindowsAPICodePack::DirectX::Direct3D11::DepthStencilView((ID3D11DepthStencilView*)ptr));
    else if (T::typeid == Microsoft::WindowsAPICodePack::DirectX::Direct3D11::D3DDevice::typeid)   
        return safe_cast<T>(gcnew Microsoft::WindowsAPICodePack::DirectX::Direct3D11::D3DDevice((ID3D11Device*)ptr));
    else if (T::typeid == Microsoft::WindowsAPICodePack::DirectX::Direct3D11::DeviceChild::typeid)   
        return safe_cast<T>(gcnew Microsoft::WindowsAPICodePack::DirectX::Direct3D11::DeviceChild((ID3D11DeviceChild*)ptr));
    else if (T::typeid == Microsoft::WindowsAPICodePack::DirectX::Direct3D11::DeviceContext::typeid)   
        return safe_cast<T>(gcnew Microsoft::WindowsAPICodePack::DirectX::Direct3D11::DeviceContext((ID3D11DeviceContext*)ptr));
    else if (T::typeid == Microsoft::WindowsAPICodePack::DirectX::Direct3D11::DomainShader::typeid)   
        return safe_cast<T>(gcnew Microsoft::WindowsAPICodePack::DirectX::Direct3D11::DomainShader((ID3D11DomainShader*)ptr));
    else if (T::typeid == Microsoft::WindowsAPICodePack::DirectX::Direct3D11::GeometryShader::typeid)   
        return safe_cast<T>(gcnew Microsoft::WindowsAPICodePack::DirectX::Direct3D11::GeometryShader((ID3D11GeometryShader*)ptr));
    else if (T::typeid == Microsoft::WindowsAPICodePack::DirectX::Direct3D11::HullShader::typeid)   
        return safe_cast<T>(gcnew Microsoft::WindowsAPICodePack::DirectX::Direct3D11::HullShader((ID3D11HullShader*)ptr));
    else if (T::typeid == Microsoft::WindowsAPICodePack::DirectX::Direct3D11::InfoQueue::typeid)   
        return safe_cast<T>(gcnew Microsoft::WindowsAPICodePack::DirectX::Direct3D11::InfoQueue((ID3D11InfoQueue*)ptr));
    else if (T::typeid == Microsoft::WindowsAPICodePack::DirectX::Direct3D11::InputLayout::typeid)   
        return safe_cast<T>(gcnew Microsoft::WindowsAPICodePack::DirectX::Direct3D11::InputLayout((ID3D11InputLayout*)ptr));
    else if (T::typeid == Microsoft::WindowsAPICodePack::DirectX::Direct3D11::PixelShader::typeid)   
        return safe_cast<T>(gcnew Microsoft::WindowsAPICodePack::DirectX::Direct3D11::PixelShader((ID3D11PixelShader*)ptr));
    else if (T::typeid == Microsoft::WindowsAPICodePack::DirectX::Direct3D11::D3DPredicate::typeid)   
        return safe_cast<T>(gcnew Microsoft::WindowsAPICodePack::DirectX::Direct3D11::D3DPredicate((ID3D11Predicate*)ptr));
    else if (T::typeid == Microsoft::WindowsAPICodePack::DirectX::Direct3D11::D3DQuery::typeid)   
        return safe_cast<T>(gcnew Microsoft::WindowsAPICodePack::DirectX::Direct3D11::D3DQuery((ID3D11Query*)ptr));
    else if (T::typeid == Microsoft::WindowsAPICodePack::DirectX::Direct3D11::RasterizerState::typeid)   
        return safe_cast<T>(gcnew Microsoft::WindowsAPICodePack::DirectX::Direct3D11::RasterizerState((ID3D11RasterizerState*)ptr));
    else if (T::typeid == Microsoft::WindowsAPICodePack::DirectX::Direct3D11::RenderTargetView::typeid)   
        return safe_cast<T>(gcnew Microsoft::WindowsAPICodePack::DirectX::Direct3D11::RenderTargetView((ID3D11RenderTargetView*)ptr));
    else if (T::typeid == Microsoft::WindowsAPICodePack::DirectX::Direct3D11::D3DResource::typeid)   
        return safe_cast<T>(gcnew Microsoft::WindowsAPICodePack::DirectX::Direct3D11::D3DResource((ID3D11Resource*)ptr));
    else if (T::typeid == Microsoft::WindowsAPICodePack::DirectX::Direct3D11::SamplerState::typeid)   
        return safe_cast<T>(gcnew Microsoft::WindowsAPICodePack::DirectX::Direct3D11::SamplerState((ID3D11SamplerState*)ptr));
    else if (T::typeid == Microsoft::WindowsAPICodePack::DirectX::Direct3D11::ShaderResourceView::typeid)   
        return safe_cast<T>(gcnew Microsoft::WindowsAPICodePack::DirectX::Direct3D11::ShaderResourceView((ID3D11ShaderResourceView*)ptr));
    else if (T::typeid == Microsoft::WindowsAPICodePack::DirectX::Direct3D11::SwitchToRef::typeid)   
        return safe_cast<T>(gcnew Microsoft::WindowsAPICodePack::DirectX::Direct3D11::SwitchToRef((ID3D11SwitchToRef*)ptr));
    else if (T::typeid == Microsoft::WindowsAPICodePack::DirectX::Direct3D11::Texture1D::typeid)   
        return safe_cast<T>(gcnew Microsoft::WindowsAPICodePack::DirectX::Direct3D11::Texture1D((ID3D11Texture1D*)ptr));
    else if (T::typeid == Microsoft::WindowsAPICodePack::DirectX::Direct3D11::Texture2D::typeid)   
        return safe_cast<T>(gcnew Microsoft::WindowsAPICodePack::DirectX::Direct3D11::Texture2D((ID3D11Texture2D*)ptr));
    else if (T::typeid == Microsoft::WindowsAPICodePack::DirectX::Direct3D11::Texture3D::typeid)   
        return safe_cast<T>(gcnew Microsoft::WindowsAPICodePack::DirectX::Direct3D11::Texture3D((ID3D11Texture3D*)ptr));
    else if (T::typeid == Microsoft::WindowsAPICodePack::DirectX::Direct3D11::UnorderedAccessView::typeid)   
        return safe_cast<T>(gcnew Microsoft::WindowsAPICodePack::DirectX::Direct3D11::UnorderedAccessView((ID3D11UnorderedAccessView*)ptr));
    else if (T::typeid == Microsoft::WindowsAPICodePack::DirectX::Direct3D11::VertexShader::typeid)   
        return safe_cast<T>(gcnew Microsoft::WindowsAPICodePack::DirectX::Direct3D11::VertexShader((ID3D11VertexShader*)ptr));
    else if (T::typeid == Microsoft::WindowsAPICodePack::DirectX::Direct3D11::View::typeid)   
        return safe_cast<T>(gcnew Microsoft::WindowsAPICodePack::DirectX::Direct3D11::View((ID3D11View*)ptr));
    else if (T::typeid == Microsoft::WindowsAPICodePack::DirectX::DXGI::Adapter::typeid)   
        return safe_cast<T>(gcnew Microsoft::WindowsAPICodePack::DirectX::DXGI::Adapter((IDXGIAdapter*)ptr));
    else if (T::typeid == Microsoft::WindowsAPICodePack::DirectX::DXGI::Adapter1::typeid)   
        return safe_cast<T>(gcnew Microsoft::WindowsAPICodePack::DirectX::DXGI::Adapter1((IDXGIAdapter1*)ptr));
    else if (T::typeid == Microsoft::WindowsAPICodePack::DirectX::DXGI::DXGIDevice::typeid)   
        return safe_cast<T>(gcnew Microsoft::WindowsAPICodePack::DirectX::DXGI::DXGIDevice((IDXGIDevice*)ptr));
    else if (T::typeid == Microsoft::WindowsAPICodePack::DirectX::DXGI::DXGIDevice1::typeid)   
        return safe_cast<T>(gcnew Microsoft::WindowsAPICodePack::DirectX::DXGI::DXGIDevice1((IDXGIDevice1*)ptr));
    else if (T::typeid == Microsoft::WindowsAPICodePack::DirectX::DXGI::DeviceSubObject::typeid)   
        return safe_cast<T>(gcnew Microsoft::WindowsAPICodePack::DirectX::DXGI::DeviceSubObject((IDXGIDeviceSubObject*)ptr));
    else if (T::typeid == Microsoft::WindowsAPICodePack::DirectX::DXGI::DXGIFactory::typeid)   
        return safe_cast<T>(gcnew Microsoft::WindowsAPICodePack::DirectX::DXGI::DXGIFactory((IDXGIFactory*)ptr));
    else if (T::typeid == Microsoft::WindowsAPICodePack::DirectX::DXGI::DXGIFactory1::typeid)   
        return safe_cast<T>(gcnew Microsoft::WindowsAPICodePack::DirectX::DXGI::DXGIFactory1((IDXGIFactory1*)ptr));
    else if (T::typeid == Microsoft::WindowsAPICodePack::DirectX::DXGI::KeyedMutex::typeid)   
        return safe_cast<T>(gcnew Microsoft::WindowsAPICodePack::DirectX::DXGI::KeyedMutex((IDXGIKeyedMutex*)ptr));
    else if (T::typeid == Microsoft::WindowsAPICodePack::DirectX::DXGI::DXGIObject::typeid)   
        return safe_cast<T>(gcnew Microsoft::WindowsAPICodePack::DirectX::DXGI::DXGIObject((IDXGIObject*)ptr));
    else if (T::typeid == Microsoft::WindowsAPICodePack::DirectX::DXGI::Output::typeid)   
        return safe_cast<T>(gcnew Microsoft::WindowsAPICodePack::DirectX::DXGI::Output((IDXGIOutput*)ptr));
    else if (T::typeid == Microsoft::WindowsAPICodePack::DirectX::DXGI::DXGIResource::typeid)   
        return safe_cast<T>(gcnew Microsoft::WindowsAPICodePack::DirectX::DXGI::DXGIResource((IDXGIResource*)ptr));
    else if (T::typeid == Microsoft::WindowsAPICodePack::DirectX::DXGI::Surface::typeid)   
        return safe_cast<T>(gcnew Microsoft::WindowsAPICodePack::DirectX::DXGI::Surface((IDXGISurface*)ptr));
    else if (T::typeid == Microsoft::WindowsAPICodePack::DirectX::DXGI::Surface1::typeid)   
        return safe_cast<T>(gcnew Microsoft::WindowsAPICodePack::DirectX::DXGI::Surface1((IDXGISurface1*)ptr));
    else if (T::typeid == Microsoft::WindowsAPICodePack::DirectX::DXGI::SwapChain::typeid)   
        return safe_cast<T>(gcnew Microsoft::WindowsAPICodePack::DirectX::DXGI::SwapChain((IDXGISwapChain*)ptr));
    else
        throw gcnew NotSupportedException();
}


// TODO: Replace with type specific properties
void D3DUtils::FillGuidsDictionary()
{
    GuidsDictionary = gcnew Dictionary<System::Type^, System::Guid>();

    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::DXGI::Adapter::typeid, SystemGuidFromGUID(__uuidof(IDXGIAdapter)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::DXGI::Adapter1::typeid, SystemGuidFromGUID(__uuidof(IDXGIAdapter1)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::DXGI::DXGIDevice::typeid, SystemGuidFromGUID(__uuidof(IDXGIDevice)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::DXGI::DXGIDevice1::typeid, SystemGuidFromGUID(__uuidof(IDXGIDevice1)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::DXGI::DeviceSubObject::typeid, SystemGuidFromGUID(__uuidof(IDXGIDeviceSubObject)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::DXGI::DXGIFactory::typeid, SystemGuidFromGUID(__uuidof(IDXGIFactory)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::DXGI::DXGIFactory1::typeid, SystemGuidFromGUID(__uuidof(IDXGIFactory1)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::DXGI::KeyedMutex::typeid, SystemGuidFromGUID(__uuidof(IDXGIKeyedMutex)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::DXGI::DXGIObject::typeid, SystemGuidFromGUID(__uuidof(IDXGIObject)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::DXGI::Output::typeid, SystemGuidFromGUID(__uuidof(IDXGIOutput)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::DXGI::DXGIResource::typeid, SystemGuidFromGUID(__uuidof(IDXGIResource)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::DXGI::Surface::typeid, SystemGuidFromGUID(__uuidof(IDXGISurface)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::DXGI::Surface1::typeid, SystemGuidFromGUID(__uuidof(IDXGISurface1)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::DXGI::SwapChain::typeid, SystemGuidFromGUID(__uuidof(IDXGISwapChain)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D11::Asynchronous::typeid, SystemGuidFromGUID(__uuidof(ID3D11Asynchronous)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D11::BlendState::typeid, SystemGuidFromGUID(__uuidof(ID3D11BlendState)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D11::D3DBuffer::typeid, SystemGuidFromGUID(__uuidof(ID3D11Buffer)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D11::ClassInstance::typeid, SystemGuidFromGUID(__uuidof(ID3D11ClassInstance)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D11::ClassLinkage::typeid, SystemGuidFromGUID(__uuidof(ID3D11ClassLinkage)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D11::CommandList::typeid, SystemGuidFromGUID(__uuidof(ID3D11CommandList)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D11::ComputeShader::typeid, SystemGuidFromGUID(__uuidof(ID3D11ComputeShader)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D11::Counter::typeid, SystemGuidFromGUID(__uuidof(ID3D11Counter)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D11::D3DDebug::typeid, SystemGuidFromGUID(__uuidof(ID3D11Debug)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D11::DepthStencilState::typeid, SystemGuidFromGUID(__uuidof(ID3D11DepthStencilState)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D11::DepthStencilView::typeid, SystemGuidFromGUID(__uuidof(ID3D11DepthStencilView)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D11::D3DDevice::typeid, SystemGuidFromGUID(__uuidof(ID3D11Device)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D11::DeviceChild::typeid, SystemGuidFromGUID(__uuidof(ID3D11DeviceChild)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D11::DeviceContext::typeid, SystemGuidFromGUID(__uuidof(ID3D11DeviceContext)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D11::DomainShader::typeid, SystemGuidFromGUID(__uuidof(ID3D11DomainShader)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D11::GeometryShader::typeid, SystemGuidFromGUID(__uuidof(ID3D11GeometryShader)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D11::HullShader::typeid, SystemGuidFromGUID(__uuidof(ID3D11HullShader)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D11::InfoQueue::typeid, SystemGuidFromGUID(__uuidof(ID3D11InfoQueue)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D11::InputLayout::typeid, SystemGuidFromGUID(__uuidof(ID3D11InputLayout)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D11::PixelShader::typeid, SystemGuidFromGUID(__uuidof(ID3D11PixelShader)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D11::D3DPredicate::typeid, SystemGuidFromGUID(__uuidof(ID3D11Predicate)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D11::D3DQuery::typeid, SystemGuidFromGUID(__uuidof(ID3D11Query)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D11::RasterizerState::typeid, SystemGuidFromGUID(__uuidof(ID3D11RasterizerState)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D11::RenderTargetView::typeid, SystemGuidFromGUID(__uuidof(ID3D11RenderTargetView)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D11::D3DResource::typeid, SystemGuidFromGUID(__uuidof(ID3D11Resource)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D11::SamplerState::typeid, SystemGuidFromGUID(__uuidof(ID3D11SamplerState)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D11::ShaderResourceView::typeid, SystemGuidFromGUID(__uuidof(ID3D11ShaderResourceView)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D11::SwitchToRef::typeid, SystemGuidFromGUID(__uuidof(ID3D11SwitchToRef)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D11::Texture1D::typeid, SystemGuidFromGUID(__uuidof(ID3D11Texture1D)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D11::Texture2D::typeid, SystemGuidFromGUID(__uuidof(ID3D11Texture2D)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D11::Texture3D::typeid, SystemGuidFromGUID(__uuidof(ID3D11Texture3D)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D11::UnorderedAccessView::typeid, SystemGuidFromGUID(__uuidof(ID3D11UnorderedAccessView)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D11::VertexShader::typeid, SystemGuidFromGUID(__uuidof(ID3D11VertexShader)));
    GuidsDictionary->Add(Microsoft::WindowsAPICodePack::DirectX::Direct3D11::View::typeid, SystemGuidFromGUID(__uuidof(ID3D11View)));
}


char* D3DUtils::CharArrayfromSystemString(String^ str)
{
    return (char*) Marshal::StringToHGlobalAnsi(str).ToPointer();
}

System::Guid D3DUtils::SystemGuidFromGUID(REFGUID guid ) 
{
   return Guid( 
       guid.Data1, guid.Data2, guid.Data3, 
       guid.Data4[ 0 ], guid.Data4[ 1 ], 
       guid.Data4[ 2 ], guid.Data4[ 3 ], 
       guid.Data4[ 4 ], guid.Data4[ 5 ], 
       guid.Data4[ 6 ], guid.Data4[ 7 ] );
}

GUID D3DUtils::GUIDFromSystemGuid( System::Guid guid ) 
{
   pin_ptr<Byte> data = &(guid.ToByteArray()[ 0 ]);
   return *(GUID *)data;
}


void D3DUtils::VerifyResult(HRESULT hr)
{
    if (SUCCEEDED(hr))
        return;
    else
        throw GetExceptionForHR(hr);
}

Exception^ D3DUtils::GetExceptionForHR(HRESULT hr)
{
    switch (hr)
    {
    case D3D10_ERROR_FILE_NOT_FOUND: 
        return gcnew FileNotFoundException();

    case D3D11_ERROR_FILE_NOT_FOUND:
        return gcnew FileNotFoundException();

    case D3D10_ERROR_TOO_MANY_UNIQUE_STATE_OBJECTS: 
        return gcnew Direct3DException("Too many unique instances", hr);

    case D3D11_ERROR_TOO_MANY_UNIQUE_STATE_OBJECTS:
        return gcnew Direct3DException("Too many unique instances", hr);

    //case D3DERR_INVALIDCALL: 
    //    return gcnew ArgumentException("The method call is invalid.");

    //case D3DERR_WASSTILLDRAWING: 
    //    return gcnew Direct3DException("The previous blit operation that is transferring information to or from this surface is incomplete.", hr);

    case E_INVALIDARG: 
        return gcnew ArgumentException ("An invalid parameter was passed to the returning function. ");

    case E_OUTOFMEMORY: 
        return gcnew OutOfMemoryException("Direct3D could not allocate sufficient memory to complete the call. ");

    case DXGI_ERROR_DEVICE_HUNG: 
        return gcnew DXGIException("The application's device failed due to badly formed commands sent by the application. This is an design-time issue that should be investigated and fixed.", hr);

    case DXGI_ERROR_DEVICE_REMOVED: 
        return gcnew DXGIException("The video card has been physically removed from the system, or a driver upgrade for the video card has occurred. The application should destroy and recreate the device. For help debugging the problem, call Device.GetDeviceRemovedReason().", hr);

    case DXGI_ERROR_DEVICE_RESET: 
        return gcnew DXGIException("The device failed due to a badly formed command. This is a run-time issue; The application should destroy and recreate the device. ", hr);

    case DXGI_ERROR_DRIVER_INTERNAL_ERROR: 
        return gcnew DXGIException("The driver encountered a problem and was put into the device removed state. ", hr);

    case DXGI_ERROR_FRAME_STATISTICS_DISJOINT: 
        return gcnew NotSupportedException("The requested functionality is not supported by the device or the driver. ", gcnew DXGIException(hr));

    case DXGI_ERROR_GRAPHICS_VIDPN_SOURCE_IN_USE: 
        return gcnew DXGIException("The requested functionality is not supported by the device or the driver. ", hr);

    case DXGI_ERROR_INVALID_CALL: 
        return gcnew ArgumentOutOfRangeException("The application provided invalid parameter data; this must be debugged and fixed before the application is released. ", gcnew DXGIException(hr));

    case DXGI_ERROR_MORE_DATA: 
        return gcnew DXGIException("The buffer supplied by the application is not big enough to hold the requested data. ", hr);

    case DXGI_ERROR_NONEXCLUSIVE: 
        return gcnew DXGIException("The application attempted to acquire exclusive ownership of an output, but failed because some other application (or device within the application) has already acquired ownership. ", hr);

    case DXGI_ERROR_NOT_CURRENTLY_AVAILABLE: 
        return gcnew DXGIException("The requested functionality is not supported by the device or the driver. ", hr);

    case DXGI_ERROR_NOT_FOUND: 
        return gcnew DXGIException("When calling DXGIObject.GetPrivateData(), the GUID passed in is not recognized as one previously passed to DXGIObject.SetPrivateData() or DXGIObject.SetPrivateDataInterface(). ", hr);

    case DXGI_ERROR_REMOTE_CLIENT_DISCONNECTED: 
        return gcnew DXGIException("The application's remote device has been removed due to session disconnect or network disconnect. The application should call DXGI.DXGIFactory1.IsCurrent() to find out when the remote device becomes available again. ", hr);
    
    case DXGI_ERROR_REMOTE_OUTOFMEMORY: 
        return gcnew OutOfMemoryException("The application's remote device has failed due to lack of memory or machine error. The application should destroy and recreate resources using less memory. ", gcnew DXGIException(hr));
    
    case DXGI_ERROR_WAS_STILL_DRAWING: 
        return gcnew DXGIException("The device was busy, and did not schedule the requested task. This error only applies to Asynchronous queries in Direct3D 10.", hr); 
    
    case DXGI_ERROR_UNSUPPORTED: 
        return gcnew NotSupportedException("The requested functionality is not supported by the device or the driver. ", gcnew DXGIException(hr));

    case E_FAIL: 
        return gcnew Direct3DException("Attempted to create a device with the debug layer enabled and the layer is not installed.", hr);

    default:
        return Marshal::GetExceptionForHR(hr);
    }    
}


void D3DUtils::CheckNull(Object^ o, String^ argName)
{
    if (o == nullptr)
    {
        throw gcnew ArgumentNullException(argName);
    }
}

HINSTANCE D3DUtils::LoadDll(LPCWSTR libraryName)
{

    HINSTANCE library = LoadLibrary(libraryName);
     
    // Check to see if the library was loaded successfully 
    if (library == 0)
    {
        throw gcnew PlatformNotSupportedException(
            String::Format("Unable to load dynamic link library: \"{0}\".", gcnew String(libraryName)));
    }

    return library;
}

FARPROC D3DUtils::GetFunctionfromDll(HINSTANCE library, LPCSTR functionName)
{
    System::Diagnostics::Debug::Assert(library != 0);

    FARPROC funcPtr = GetProcAddress(library, functionName);

    if (funcPtr == 0)
    {
        throw gcnew NotSupportedException(
            String::Format("Unable to find entry point for {0}().", gcnew String(functionName)));
    }

    return funcPtr;
}