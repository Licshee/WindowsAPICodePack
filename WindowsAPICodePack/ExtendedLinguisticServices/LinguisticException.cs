// Copyright (c) Microsoft Corporation.  All rights reserved.

using System;
using System.ComponentModel;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading;
using System.Runtime.ConstrainedExecution;
using System.Collections.Generic;

namespace Microsoft.WindowsAPICodePack.ExtendedLinguisticServices
{

    /// <summary>
    /// This exception is thrown by the managed wrappers of ELS when the underlying
    /// unmanaged implementation returns an HResult which is not S_OK (0).
    /// This exception is also thrown when the managed wrapper detects an exceptional
    /// condition which causes it to fail. Please note that other .NET exceptions are also
    /// possible to be thrown from the ELS managed wrappers.
    /// </summary>
    public class LinguisticException : Win32Exception
    {
        internal const uint E_INVALIDARG = 0x80070057;
        internal const uint E_FAIL = 0x80004005;
        internal const uint E_INVALIDDATA = 0x8007000D;

        internal LinguisticException()
            : this(E_FAIL)
        {
        }

        internal LinguisticException(UInt32 hResult)
            : base((int)(hResult == 0 ? E_FAIL : hResult))
        {
            HResult = (int)(hResult == 0 ? E_FAIL : hResult);
        }

        /// <summary>
        /// Gets the MappingResultState describing the error condition for this exception.
        /// </summary>
        public MappingResultState ResultState
        {
            get
            {
                return new MappingResultState(HResult, Message);
            }
        }
    }

}
