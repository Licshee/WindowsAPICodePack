//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once
#include "D3D11DeviceContext.h"
#include <vector>

using namespace std;

namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3D11 {

/// <summary>
/// A pipeline stage. base class for all pipline stage related classes.
/// </summary>
public ref class PipelineStage abstract
{
private: 
    DeviceContext^ m_parent;

protected:
    property DeviceContext^ Parent
    {
        DeviceContext^ get()
        {
            return m_parent;
        }
    }

    template <class T, class S>
    Collection<T^>^ GetList(UINT numElements, vector<S*> & buffer)
    {

        Collection<T^>^ items = gcnew Collection<T^>();
        for (UINT i = 0; i < numElements; i++)
        {
            items->Add(buffer[i] == NULL ? nullptr : gcnew T(buffer[i]));
        }

        return items;
    }


    template <class T, class S>
    UINT SetVectorItems(IEnumerable<T^>^ items, vector<S*> & buffer)
    {
        if (items != nullptr)
        {
            for each (T^ item in items)
            {
                buffer.push_back(item == nullptr ? NULL : (S*)item->nativeUnknown.Get());
            }
        }

        return static_cast<UINT>(buffer.size());
    }

protected:
    PipelineStage() {}
internal:
    PipelineStage(DeviceContext^ parent) : m_parent(parent) {}
};
} } } }
