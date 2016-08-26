//Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once
#include "DirectUnknown.h"


namespace  Microsoft { namespace WindowsAPICodePack { namespace DirectX { namespace Direct3D11 {

using namespace System;
using namespace Microsoft::WindowsAPICodePack::DirectX::Direct3D11;

    /// <summary>
    /// An information-queue interface stores, retrieves, and filters debug messages. The queue consists of a message queue, an optional storage filter stack, and a optional retrieval filter stack.
    /// <para>(Also see DirectX SDK: ID3D11InfoQueue)</para>
    /// </summary>
    public ref class InfoQueue :
        public Microsoft::WindowsAPICodePack::DirectX::Direct3DCommon::DirectUnknown
    {
    public: 
        /// <summary>
        /// Add a user-defined message to the message queue and send that message to debug output.
        /// <para>(Also see DirectX SDK: ID3D11InfoQueue::AddApplicationMessage)</para>
        /// </summary>
        /// <param name="Severity">Severity of a message (see <see cref="MessageSeverity"/>)<seealso cref="MessageSeverity"/>.</param>
        /// <param name="Description">Message string.</param>
        void AddApplicationMessage(MessageSeverity Severity, String^ Description);

        /// <summary>
        /// Add a debug message to the message queue and send that message to debug output.
        /// <para>(Also see DirectX SDK: ID3D11InfoQueue::AddMessage)</para>
        /// </summary>
        /// <param name="Category">Category of a message (see <see cref="MessageCategory"/>)<seealso cref="MessageCategory"/>.</param>
        /// <param name="Severity">Severity of a message (see <see cref="MessageSeverity"/>)<seealso cref="MessageSeverity"/>.</param>
        /// <param name="ID">Unique identifier of a message (see <see cref="MessageId"/>)<seealso cref="MessageId"/>.</param>
        /// <param name="Description">User-defined message.</param>
        void AddMessage(MessageCategory Category, MessageSeverity Severity, MessageId ID, String^ Description);

        /// <summary>
        /// Add storage filters to the top of the retrieval-filter stack.
        /// <para>(Also see DirectX SDK: ID3D11InfoQueue::AddRetrievalFilterEntries)</para>
        /// </summary>
        /// <param name="Filter">Array of retrieval filters (see <see cref="InfoQueueFilter"/>)<seealso cref="InfoQueueFilter"/>.</param>
        void AddRetrievalFilterEntries(InfoQueueFilter^ Filter);

        /// <summary>
        /// Add storage filters to the top of the storage-filter stack.
        /// <para>(Also see DirectX SDK: ID3D11InfoQueue::AddStorageFilterEntries)</para>
        /// </summary>
        /// <param name="Filter">Array of storage filters (see <see cref="InfoQueueFilter"/>)<seealso cref="InfoQueueFilter"/>.</param>
        void AddStorageFilterEntries(InfoQueueFilter^ Filter);

        /// <summary>
        /// Remove a retrieval filter from the top of the retrieval-filter stack.
        /// <para>(Also see DirectX SDK: ID3D11InfoQueue::ClearRetrievalFilter)</para>
        /// </summary>
        void ClearRetrievalFilter();

        /// <summary>
        /// Remove a storage filter from the top of the storage-filter stack.
        /// <para>(Also see DirectX SDK: ID3D11InfoQueue::ClearStorageFilter)</para>
        /// </summary>
        void ClearStorageFilter();

        /// <summary>
        /// Clear all messages from the message queue.
        /// <para>(Also see DirectX SDK: ID3D11InfoQueue::ClearStoredMessages)</para>
        /// </summary>
        void ClearStoredMessages();

        /// <summary>
        /// Get a message category to break on when a message with that category passes through the storage filter.
        /// <para>(Also see DirectX SDK: ID3D11InfoQueue::GetBreakOnCategory)</para>
        /// </summary>
        /// <param name="Category">Message category to break on (see <see cref="MessageCategory"/>)<seealso cref="MessageCategory"/>.</param>
        Boolean GetBreakOnCategory(MessageCategory Category);

        /// <summary>
        /// Get a message identifier to break on when a message with that identifier passes through the storage filter.
        /// <para>(Also see DirectX SDK: ID3D11InfoQueue::GetBreakOnID)</para>
        /// </summary>
        /// <param name="ID">Message identifier to break on (see <see cref="MessageId"/>)<seealso cref="MessageId"/>.</param>
        Boolean GetBreakOnID(MessageId ID);

        /// <summary>
        /// Get a message severity level to break on when a message with that severity level passes through the storage filter.
        /// <para>(Also see DirectX SDK: ID3D11InfoQueue::GetBreakOnSeverity)</para>
        /// </summary>
        /// <param name="Severity">Message severity level to break on (see <see cref="MessageSeverity"/>)<seealso cref="MessageSeverity"/>.</param>
        Boolean GetBreakOnSeverity(MessageSeverity Severity);

        /// <summary>
        /// Get a message from the message queue.
        /// <para>(Also see DirectX SDK: ID3D11InfoQueue::GetMessage)</para>
        /// </summary>
        /// <param name="messageIndex">Index into message queue after an optional retrieval filter has been applied. 
        /// This can be between 0 and the number of messages in the message queue that pass through the retrieval filter (which can be obtained with GetNumStoredMessagesAllowedByRetrievalFilter(). 
        /// 0 is the message at the front of the message queue.</param>
        /// <returns>Returned message (see <see cref="Message"/>)<seealso cref="Message"/>.</returns>
        Message^ GetMessage(UInt64 messageIndex);

        /// <summary>
        /// Try to get a message from the message queue.
        /// <para>(Also see DirectX SDK: ID3D11InfoQueue::GetMessage)</para>
        /// </summary>
        /// <param name="messageIndex">Index into message queue after an optional retrieval filter has been applied. 
        /// This can be between 0 and the number of messages in the message queue that pass through the retrieval filter 
        /// (which can be obtained with GetNumStoredMessagesAllowedByRetrievalFilter(). 
        /// Index 0 is the message at the front of the message queue. </param>        
        /// <param name="outMessage">Returned message (see <see cref="Message"/>)<seealso cref="Message"/>.</param>      
        /// <returns>True if successful; false otherwise.</returns>
        bool TryGetMessage(UInt64 messageIndex, [Runtime::InteropServices::Out]  Message^ % outMessage);

        /// <summary>
        /// Get the maximum number of messages that can be added to the message queue.
        /// <para>(Also see DirectX SDK: ID3D11InfoQueue::GetMessageCountLimit)</para>
        /// </summary>
        UInt64 GetMessageCountLimit();

        /// <summary>
        /// Get a boolean that turns the debug output on or off.
        /// <para>(Also see DirectX SDK: ID3D11InfoQueue::GetMuteDebugOutput)</para>
        /// </summary>
        Boolean GetMuteDebugOutput();

        /// <summary>
        /// Get the number of messages that were allowed to pass through a storage filter.
        /// <para>(Also see DirectX SDK: ID3D11InfoQueue::GetNumMessagesAllowedByStorageFilter)</para>
        /// </summary>
        UInt64 GetNumMessagesAllowedByStorageFilter();

        /// <summary>
        /// Get the number of messages that were denied passage through a storage filter.
        /// <para>(Also see DirectX SDK: ID3D11InfoQueue::GetNumMessagesDeniedByStorageFilter)</para>
        /// </summary>
        UInt64 GetNumMessagesDeniedByStorageFilter();

        /// <summary>
        /// Get the number of messages that were discarded due to the message count limit.
        /// <para>(Also see DirectX SDK: ID3D11InfoQueue::GetNumMessagesDiscardedByMessageCountLimit)</para>
        /// </summary>
        UInt64 GetNumMessagesDiscardedByMessageCountLimit();

        /// <summary>
        /// Get the number of messages currently stored in the message queue.
        /// <para>(Also see DirectX SDK: ID3D11InfoQueue::GetNumStoredMessages)</para>
        /// </summary>
        UInt64 GetNumStoredMessages();

        /// <summary>
        /// Get the number of messages that are able to pass through a retrieval filter.
        /// <para>(Also see DirectX SDK: ID3D11InfoQueue::GetNumStoredMessagesAllowedByRetrievalFilter)</para>
        /// </summary>
        UInt64 GetNumStoredMessagesAllowedByRetrievalFilter();

        /// <summary>
        /// Get the retrieval filter at the top of the retrieval-filter stack.
        /// <para>(Also see DirectX SDK: ID3D11InfoQueue::GetRetrievalFilter)</para>
        /// </summary>
        /// <returns>Retrieval filter at the top of the retrieval-filter stack.</returns>
        InfoQueueFilter^ GetRetrievalFilter();

        /// <summary>
        /// Get the size of the retrieval-filter stack in bytes.
        /// <para>(Also see DirectX SDK: ID3D11InfoQueue::GetRetrievalFilterStackSize)</para>
        /// </summary>
        UInt32 GetRetrievalFilterStackSize();

        /// <summary>
        /// Get the storage filter at the top of the storage-filter stack.
        /// <para>(Also see DirectX SDK: ID3D11InfoQueue::GetStorageFilter)</para>
        /// </summary>
        /// <returns>Storage filter at the top of the storage-filter stack.</returns>
        InfoQueueFilter^ GetStorageFilter();

        /// <summary>
        /// Get the size of the storage-filter stack in bytes.
        /// <para>(Also see DirectX SDK: ID3D11InfoQueue::GetStorageFilterStackSize)</para>
        /// </summary>
        UInt32 GetStorageFilterStackSize();

        /// <summary>
        /// Pop a retrieval filter from the top of the retrieval-filter stack.
        /// <para>(Also see DirectX SDK: ID3D11InfoQueue::PopRetrievalFilter)</para>
        /// </summary>
        void PopRetrievalFilter();

        /// <summary>
        /// Pop a storage filter from the top of the storage-filter stack.
        /// <para>(Also see DirectX SDK: ID3D11InfoQueue::PopStorageFilter)</para>
        /// </summary>
        void PopStorageFilter();

        /// <summary>
        /// Push a copy of retrieval filter currently on the top of the retrieval-filter stack onto the retrieval-filter stack.
        /// <para>(Also see DirectX SDK: ID3D11InfoQueue::PushCopyOfRetrievalFilter)</para>
        /// </summary>
        void PushCopyOfRetrievalFilter();

        /// <summary>
        /// Push a copy of storage filter currently on the top of the storage-filter stack onto the storage-filter stack.
        /// <para>(Also see DirectX SDK: ID3D11InfoQueue::PushCopyOfStorageFilter)</para>
        /// </summary>
        void PushCopyOfStorageFilter();

        /// <summary>
        /// Push an empty retrieval filter onto the retrieval-filter stack.
        /// <para>(Also see DirectX SDK: ID3D11InfoQueue::PushEmptyRetrievalFilter)</para>
        /// </summary>
        void PushEmptyRetrievalFilter();

        /// <summary>
        /// Push an empty storage filter onto the storage-filter stack.
        /// <para>(Also see DirectX SDK: ID3D11InfoQueue::PushEmptyStorageFilter)</para>
        /// </summary>
        void PushEmptyStorageFilter();

        /// <summary>
        /// Push a retrieval filter onto the retrieval-filter stack.
        /// <para>(Also see DirectX SDK: ID3D11InfoQueue::PushRetrievalFilter)</para>
        /// </summary>
        /// <param name="Filter">A retrieval filter (see <see cref="InfoQueueFilter"/>)<seealso cref="InfoQueueFilter"/>.</param>
        void PushRetrievalFilter(InfoQueueFilter^ Filter);

        /// <summary>
        /// Push a storage filter onto the storage-filter stack.
        /// <para>(Also see DirectX SDK: ID3D11InfoQueue::PushStorageFilter)</para>
        /// </summary>
        /// <param name="Filter">A storage filter (see <see cref="InfoQueueFilter"/>)<seealso cref="InfoQueueFilter"/>.</param>
        void PushStorageFilter(InfoQueueFilter^ Filter);

        /// <summary>
        /// Set a message category to break on when a message with that category passes through the storage filter.
        /// <para>(Also see DirectX SDK: ID3D11InfoQueue::SetBreakOnCategory)</para>
        /// </summary>
        /// <param name="Category">Message category to break on (see <see cref="MessageCategory"/>)<seealso cref="MessageCategory"/>.</param>
        /// <param name="bEnable">Turns this breaking condition on or off (true for on, false for off).</param>
        void SetBreakOnCategory(MessageCategory Category, Boolean bEnable);

        /// <summary>
        /// Set a message identifier to break on when a message with that identifier passes through the storage filter.
        /// <para>(Also see DirectX SDK: ID3D11InfoQueue::SetBreakOnID)</para>
        /// </summary>
        /// <param name="ID">Message identifier to break on (see <see cref="MessageId"/>)<seealso cref="MessageId"/>.</param>
        /// <param name="bEnable">Turns this breaking condition on or off (true for on, false for off).</param>
        void SetBreakOnID(MessageId ID, Boolean bEnable);

        /// <summary>
        /// Set a message severity level to break on when a message with that severity level passes through the storage filter.
        /// <para>(Also see DirectX SDK: ID3D11InfoQueue::SetBreakOnSeverity)</para>
        /// </summary>
        /// <param name="Severity">A MessageSeverity, which represents a message severity level to break on.</param>
        /// <param name="bEnable">Turns this breaking condition on or off (true for on, false for off).</param>
        void SetBreakOnSeverity(MessageSeverity Severity, Boolean bEnable);

        /// <summary>
        /// Set the maximum number of messages that can be added to the message queue.
        /// <para>(Also see DirectX SDK: ID3D11InfoQueue::SetMessageCountLimit)</para>
        /// </summary>
        /// <param name="MessageCountLimit">Maximum number of messages that can be added to the message queue. -1 means no limit.</param>
        void SetMessageCountLimit(UInt64 MessageCountLimit);

        /// <summary>
        /// Set a boolean that turns the debug output on or off.
        /// <para>(Also see DirectX SDK: ID3D11InfoQueue::SetMuteDebugOutput)</para>
        /// </summary>
        /// <param name="bMute">Disable/Enable the debug output (TRUE to disable or mute the output, FALSE to enable the output).</param>
        void SetMuteDebugOutput(Boolean bMute);


    protected:
        InfoQueue()
        {
        }
    internal:

        InfoQueue(ID3D11InfoQueue* pNativeID3D11InfoQueue)
        {
            nativeUnknown.Set(pNativeID3D11InfoQueue);
        }

        property ID3D11InfoQueue* NativeID3D11InfoQueue
        {
            ID3D11InfoQueue* get()
            {
                return reinterpret_cast<ID3D11InfoQueue*>(nativeUnknown.Get());
            }
        }
    };
} } } }
