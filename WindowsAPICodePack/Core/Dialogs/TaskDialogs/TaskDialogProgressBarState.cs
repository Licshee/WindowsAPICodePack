//Copyright (c) Microsoft Corporation.  All rights reserved.

using System;
using System.Collections.Generic;
using System.Text;
using Microsoft.WindowsAPICodePack;

namespace Microsoft.WindowsAPICodePack
{
    /// <summary>
    /// Sets the state of a task dialog progress bar.
    /// </summary>
    public enum TaskDialogProgressBarState
    {
        /// <summary>
        /// Normal state.
        /// </summary>
        Normal      = TaskDialogNativeMethods.PBST.PBST_NORMAL,
        /// <summary>
        /// An error occurred.
        /// </summary>
        Error = TaskDialogNativeMethods.PBST.PBST_ERROR,
        /// <summary>
        /// The progress is paused.
        /// </summary>
        Paused = TaskDialogNativeMethods.PBST.PBST_PAUSED
    }
}
