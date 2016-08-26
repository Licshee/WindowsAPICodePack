//Copyright (c) Microsoft Corporation.  All rights reserved.

using System;
using System.Collections.Generic;
using System.Text;

namespace Microsoft.WindowsAPICodePack
{
    /// <summary>
    /// Identifies one of the standard buttons that 
    /// can be displayed via TaskDialog.
    /// </summary>
    [Flags]
    public enum TaskDialogStandardButton
    {
        /// <summary>
        /// No buttons on the dialog
        /// </summary>
        None    = 0x0000,   

        /// <summary>
        /// OK button
        /// </summary>
        Ok      = 0x0001,

        /// <summary>
        /// "Yes" button
        /// </summary>
        Yes     = 0x0002,

        /// <summary>
        /// "No" button
        /// </summary>
        No      = 0x0004,

        /// <summary>
        /// "Cancel" button
        /// </summary>
        Cancel  = 0x0008,

        /// <summary>
        /// "Retry" button
        /// </summary>
        Retry   = 0x0010,

        /// <summary>
        /// "Close" button
        /// </summary>
        Close   = 0x0020
    }
}
