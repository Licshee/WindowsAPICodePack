//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once
#include "D3D11DeviceChild.h"

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3D11 {

using namespace System;
ref class ClassInstance;

    /// <summary>
    /// This class encapsulates an HLSL dynamic linkage.
    /// <para>(Also see DirectX SDK: ID3D11ClassLinkage)</para>
    /// </summary>
    public ref class ClassLinkage :
        public Microsoft::WindowsAPICodePack::DirectX::Direct3D11::DeviceChild
    {
    public: 
        /// <summary>
        /// Initializes a class-instance object that represents an HLSL class instance.
        /// <para>(Also see DirectX SDK: ID3D11ClassLinkage::CreateClassInstance)</para>
        /// </summary>
        /// <param name="szClassTypeName">The type name of a class to initialize.</param>
        /// <param name="ConstantBufferOffset">Identifies the constant buffer that contains the class data.</param>
        /// <param name="ConstantVectorOffset">The four-component vector offset from the start of the constant buffer where the class data will begin. Consequently, this is not a byte offset.</param>
        /// <param name="TextureOffset">The texture slot for the first texture; there may be multiple textures following the offset.</param>
        /// <param name="SamplerOffset">The sampler slot for the first sampler; there may be multiple samplers following the offset.</param>
        /// <returns>A ClassInstance interface to initialize.</returns>
        ClassInstance^ CreateClassInstance(String^ szClassTypeName, UInt32 ConstantBufferOffset, UInt32 ConstantVectorOffset, UInt32 TextureOffset, UInt32 SamplerOffset);

        /// <summary>
        /// Gets the class-instance object that represents the specified HLSL class.
        /// <para>(Also see DirectX SDK: ID3D11ClassLinkage::GetClassInstance)</para>
        /// </summary>
        /// <param name="ClassInstanceName">The name of a class for which to get the class instance.</param>
        /// <param name="InstanceIndex">The index of the class instance.</param>
        /// <returns>A ClassInstance to initialize.</returns>
        ClassInstance^ GetClassInstance(String^ ClassInstanceName, UInt32 InstanceIndex);


    protected:
        ClassLinkage()
        {
        }
    internal:

        ClassLinkage(ID3D11ClassLinkage* pNativeID3D11ClassLinkage)
        {
            nativeUnknown.Set(pNativeID3D11ClassLinkage);
        }

        property ID3D11ClassLinkage* NativeID3D11ClassLinkage
        {
            ID3D11ClassLinkage* get()
            {
                return reinterpret_cast<ID3D11ClassLinkage*>(nativeUnknown.Get());
            }
        }

    };
} } } }
