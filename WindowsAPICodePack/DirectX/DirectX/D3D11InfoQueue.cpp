// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "D3D11InfoQueue.h"

using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D11;

void InfoQueue::AddApplicationMessage(MessageSeverity Severity, String^ Description)
{
    System::Diagnostics::Debug::Assert(NativeID3D11InfoQueue != NULL);

    char* tempDescription = D3DUtils::CharArrayfromSystemString(Description);
    try
    {
        D3DUtils::VerifyResult(NativeID3D11InfoQueue->AddApplicationMessage(safe_cast<D3D11_MESSAGE_SEVERITY>(Severity), tempDescription));
    }
    finally
    {
        Marshal::FreeHGlobal(IntPtr(tempDescription));
    }

}

void InfoQueue::AddMessage(MessageCategory Category, MessageSeverity Severity, MessageId ID, String^ Description)
{
    System::Diagnostics::Debug::Assert(NativeID3D11InfoQueue != NULL);

    char* tempDescription = D3DUtils::CharArrayfromSystemString(Description);

    try
    {
        D3DUtils::VerifyResult(NativeID3D11InfoQueue->AddMessage(safe_cast<D3D11_MESSAGE_CATEGORY>(Category), safe_cast<D3D11_MESSAGE_SEVERITY>(Severity), safe_cast<D3D11_MESSAGE_ID>(ID), tempDescription));
    }
    finally
    {
        Marshal::FreeHGlobal(IntPtr(tempDescription));
    }

}

void InfoQueue::AddRetrievalFilterEntries(InfoQueueFilter^ Filter)
{
    System::Diagnostics::Debug::Assert(NativeID3D11InfoQueue != NULL);

    D3DUtils::VerifyResult(NativeID3D11InfoQueue->AddRetrievalFilterEntries(Filter->nativeObject.Get()));

}

void InfoQueue::AddStorageFilterEntries(InfoQueueFilter^ Filter)
{
    System::Diagnostics::Debug::Assert(NativeID3D11InfoQueue != NULL);

    D3DUtils::VerifyResult(NativeID3D11InfoQueue->AddStorageFilterEntries(Filter->nativeObject.Get()));

}

void InfoQueue::ClearRetrievalFilter()
{
    System::Diagnostics::Debug::Assert(NativeID3D11InfoQueue != NULL);

    NativeID3D11InfoQueue->ClearRetrievalFilter();

}

void InfoQueue::ClearStorageFilter()
{
    System::Diagnostics::Debug::Assert(NativeID3D11InfoQueue != NULL);

    NativeID3D11InfoQueue->ClearStorageFilter();

}

void InfoQueue::ClearStoredMessages()
{
    System::Diagnostics::Debug::Assert(NativeID3D11InfoQueue != NULL);

    NativeID3D11InfoQueue->ClearStoredMessages();

}

Boolean InfoQueue::GetBreakOnCategory(MessageCategory Category)
{
    System::Diagnostics::Debug::Assert(NativeID3D11InfoQueue != NULL);

    BOOL returnValue = NativeID3D11InfoQueue->GetBreakOnCategory(safe_cast<D3D11_MESSAGE_CATEGORY>(Category));
    return returnValue != 0;

}

Boolean InfoQueue::GetBreakOnID(MessageId ID)
{
    System::Diagnostics::Debug::Assert(NativeID3D11InfoQueue != NULL);

    BOOL returnValue = NativeID3D11InfoQueue->GetBreakOnID(safe_cast<D3D11_MESSAGE_ID>(ID));
    return returnValue != 0;

}

Boolean InfoQueue::GetBreakOnSeverity(MessageSeverity Severity)
{
    System::Diagnostics::Debug::Assert(NativeID3D11InfoQueue != NULL);

    BOOL returnValue = NativeID3D11InfoQueue->GetBreakOnSeverity(safe_cast<D3D11_MESSAGE_SEVERITY>(Severity));
    return returnValue != 0;

}

Message^ InfoQueue::GetMessage(UInt64 messageIndex)
{
    System::Diagnostics::Debug::Assert(NativeID3D11InfoQueue != NULL);

    // Get the size of the message
    SIZE_T messageLength = 0;
    D3DUtils::VerifyResult(NativeID3D11InfoQueue->GetMessage(static_cast<UINT64>(messageIndex), NULL, &messageLength));

    // Allocate space and get the message
    D3D11_MESSAGE * pMessage = (D3D11_MESSAGE*)malloc(messageLength);
    D3DUtils::VerifyResult(NativeID3D11InfoQueue->GetMessage(static_cast<UINT64>(messageIndex), pMessage, &messageLength));

    return pMessage == NULL ? nullptr : gcnew Message(pMessage, false); // poinhter will be disposed in the Message's finalizer
}

 bool InfoQueue::TryGetMessage(UInt64 messageIndex, [Runtime::InteropServices::Out]  Message^ % outMessage)
{
    System::Diagnostics::Debug::Assert(NativeID3D11InfoQueue != NULL);

    outMessage = nullptr;

    // Get the size of the message
    SIZE_T messageLength = 0;
    if (FAILED(NativeID3D11InfoQueue->GetMessage(static_cast<UINT64>(messageIndex), NULL, &messageLength)))
    {
        return false;
    }

    // Allocate space and get the message
    D3D11_MESSAGE * pMessage = (D3D11_MESSAGE*)malloc(messageLength);
    if (SUCCEEDED(NativeID3D11InfoQueue->GetMessage(static_cast<UINT64>(messageIndex), pMessage, &messageLength)))
    {
        outMessage = pMessage == NULL ? nullptr : gcnew Message(pMessage, false); // poinhter will be disposed in the Message's finalizer
        return true;
    }
    else
    {
        return false;
    }
}


UInt64 InfoQueue::GetMessageCountLimit()
{
    System::Diagnostics::Debug::Assert(NativeID3D11InfoQueue != NULL);

    UINT64 returnValue = NativeID3D11InfoQueue->GetMessageCountLimit();
    return safe_cast<UInt64>(returnValue);

}

Boolean InfoQueue::GetMuteDebugOutput()
{
    System::Diagnostics::Debug::Assert(NativeID3D11InfoQueue != NULL);

    BOOL returnValue = NativeID3D11InfoQueue->GetMuteDebugOutput();
    return returnValue != 0;

}

UInt64 InfoQueue::GetNumMessagesAllowedByStorageFilter()
{
    System::Diagnostics::Debug::Assert(NativeID3D11InfoQueue != NULL);

    UINT64 returnValue = NativeID3D11InfoQueue->GetNumMessagesAllowedByStorageFilter();
    return safe_cast<UInt64>(returnValue);

}

UInt64 InfoQueue::GetNumMessagesDeniedByStorageFilter()
{
    System::Diagnostics::Debug::Assert(NativeID3D11InfoQueue != NULL);

    UINT64 returnValue = NativeID3D11InfoQueue->GetNumMessagesDeniedByStorageFilter();
    return safe_cast<UInt64>(returnValue);

}

UInt64 InfoQueue::GetNumMessagesDiscardedByMessageCountLimit()
{
    System::Diagnostics::Debug::Assert(NativeID3D11InfoQueue != NULL);

    UINT64 returnValue = NativeID3D11InfoQueue->GetNumMessagesDiscardedByMessageCountLimit();
    return safe_cast<UInt64>(returnValue);

}

UInt64 InfoQueue::GetNumStoredMessages()
{
    System::Diagnostics::Debug::Assert(NativeID3D11InfoQueue != NULL);

    UINT64 returnValue = NativeID3D11InfoQueue->GetNumStoredMessages();
    return safe_cast<UInt64>(returnValue);

}

UInt64 InfoQueue::GetNumStoredMessagesAllowedByRetrievalFilter()
{
    System::Diagnostics::Debug::Assert(NativeID3D11InfoQueue != NULL);

    UINT64 returnValue = NativeID3D11InfoQueue->GetNumStoredMessagesAllowedByRetrievalFilter();
    return safe_cast<UInt64>(returnValue);

}

InfoQueueFilter^ InfoQueue::GetRetrievalFilter()
{
    System::Diagnostics::Debug::Assert(NativeID3D11InfoQueue != NULL);

    SIZE_T size = 0;
    D3DUtils::VerifyResult(NativeID3D11InfoQueue->GetRetrievalFilter(NULL, &size));

    D3D11_INFO_QUEUE_FILTER * filter = (D3D11_INFO_QUEUE_FILTER*)malloc(size);
    D3DUtils::VerifyResult(NativeID3D11InfoQueue->GetRetrievalFilter(filter, &size));

    return filter == NULL ? nullptr : gcnew InfoQueueFilter(filter, false); // poinhter will be disposed in the Message's finalizer
}

UInt32 InfoQueue::GetRetrievalFilterStackSize()
{
    System::Diagnostics::Debug::Assert(NativeID3D11InfoQueue != NULL);

    UINT returnValue = NativeID3D11InfoQueue->GetRetrievalFilterStackSize();
    return safe_cast<UInt32>(returnValue);

}

InfoQueueFilter^ InfoQueue::GetStorageFilter()
{
    System::Diagnostics::Debug::Assert(NativeID3D11InfoQueue != NULL);
    System::Diagnostics::Debug::Assert(NativeID3D11InfoQueue != NULL);

    SIZE_T size = 0;
    D3DUtils::VerifyResult(NativeID3D11InfoQueue->GetStorageFilter(NULL, &size));

    D3D11_INFO_QUEUE_FILTER * filter = (D3D11_INFO_QUEUE_FILTER*)malloc(size);
    D3DUtils::VerifyResult(NativeID3D11InfoQueue->GetStorageFilter(filter, &size));

    return filter == NULL ? nullptr : gcnew InfoQueueFilter(filter, false); // poinhter will be disposed in the Message's finalizer
}

UInt32 InfoQueue::GetStorageFilterStackSize()
{
    System::Diagnostics::Debug::Assert(NativeID3D11InfoQueue != NULL);

    UINT returnValue = NativeID3D11InfoQueue->GetStorageFilterStackSize();
    return safe_cast<UInt32>(returnValue);

}

void InfoQueue::PopRetrievalFilter()
{
    System::Diagnostics::Debug::Assert(NativeID3D11InfoQueue != NULL);

    NativeID3D11InfoQueue->PopRetrievalFilter();

}

void InfoQueue::PopStorageFilter()
{
    System::Diagnostics::Debug::Assert(NativeID3D11InfoQueue != NULL);

    NativeID3D11InfoQueue->PopStorageFilter();

}

void InfoQueue::PushCopyOfRetrievalFilter()
{
    System::Diagnostics::Debug::Assert(NativeID3D11InfoQueue != NULL);

    D3DUtils::VerifyResult(NativeID3D11InfoQueue->PushCopyOfRetrievalFilter());

}

void InfoQueue::PushCopyOfStorageFilter()
{
    System::Diagnostics::Debug::Assert(NativeID3D11InfoQueue != NULL);

    D3DUtils::VerifyResult(NativeID3D11InfoQueue->PushCopyOfStorageFilter());

}

void InfoQueue::PushEmptyRetrievalFilter()
{
    System::Diagnostics::Debug::Assert(NativeID3D11InfoQueue != NULL);

    D3DUtils::VerifyResult(NativeID3D11InfoQueue->PushEmptyRetrievalFilter());

}

void InfoQueue::PushEmptyStorageFilter()
{
    System::Diagnostics::Debug::Assert(NativeID3D11InfoQueue != NULL);

    D3DUtils::VerifyResult(NativeID3D11InfoQueue->PushEmptyStorageFilter());

}

void InfoQueue::PushRetrievalFilter(InfoQueueFilter^ Filter)
{
    System::Diagnostics::Debug::Assert(NativeID3D11InfoQueue != NULL);

    D3DUtils::VerifyResult(NativeID3D11InfoQueue->PushRetrievalFilter(Filter->nativeObject.Get()));

}

void InfoQueue::PushStorageFilter(InfoQueueFilter^ Filter)
{
    System::Diagnostics::Debug::Assert(NativeID3D11InfoQueue != NULL);

    D3DUtils::VerifyResult(NativeID3D11InfoQueue->PushStorageFilter(Filter->nativeObject.Get()));

}

void InfoQueue::SetBreakOnCategory(MessageCategory Category, Boolean bEnable)
{
    System::Diagnostics::Debug::Assert(NativeID3D11InfoQueue != NULL);

    D3DUtils::VerifyResult(NativeID3D11InfoQueue->SetBreakOnCategory(safe_cast<D3D11_MESSAGE_CATEGORY>(Category), safe_cast<BOOL>(bEnable)));

}

void InfoQueue::SetBreakOnID(MessageId ID, Boolean bEnable)
{
    System::Diagnostics::Debug::Assert(NativeID3D11InfoQueue != NULL);

    D3DUtils::VerifyResult(NativeID3D11InfoQueue->SetBreakOnID(safe_cast<D3D11_MESSAGE_ID>(ID), safe_cast<BOOL>(bEnable)));

}

void InfoQueue::SetBreakOnSeverity(MessageSeverity Severity, Boolean bEnable)
{
    System::Diagnostics::Debug::Assert(NativeID3D11InfoQueue != NULL);

    D3DUtils::VerifyResult(NativeID3D11InfoQueue->SetBreakOnSeverity(safe_cast<D3D11_MESSAGE_SEVERITY>(Severity), safe_cast<BOOL>(bEnable)));

}

void InfoQueue::SetMessageCountLimit(UInt64 MessageCountLimit)
{
    System::Diagnostics::Debug::Assert(NativeID3D11InfoQueue != NULL);

    D3DUtils::VerifyResult(NativeID3D11InfoQueue->SetMessageCountLimit(safe_cast<UINT64>(MessageCountLimit)));

}

void InfoQueue::SetMuteDebugOutput(Boolean bMute)
{
    System::Diagnostics::Debug::Assert(NativeID3D11InfoQueue != NULL);

    NativeID3D11InfoQueue->SetMuteDebugOutput(safe_cast<BOOL>(bMute));

}

