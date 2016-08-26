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
    /// This class serves as the result status of asynchronous calls to ELS and
    /// as the result status of linguistic exceptions.
    /// </summary>
    public struct MappingResultState
    {
        private int _hResult;
        private string _errorMessage;

        internal MappingResultState(int hResult, string errorMessage)
        {
            _hResult = hResult;
            _errorMessage = errorMessage;
        }

        /// <summary>
        /// Gets a human-readable description of the HResult error code,
        /// as constructed by System.ComponentModel.Win32Exception.
        /// </summary>
        public string ErrorMessage
        {
            get
            {
                return _errorMessage;
            }
        }

        /// <summary>
        /// Gets the HResult error code associated with this structure.
        /// </summary>
        public int HResult
        {
            get
            {
                return _hResult;
            }
        }

    }

}
