//Copyright (c) Microsoft Corporation.  All rights reserved.

namespace Microsoft.WindowsAPICodePack.Shell
{
    /// <summary>
    /// Used to store the result of displaying a dialog.
    /// </summary>
    public class CommonFileDialogResult
    {
        /// <summary>
        /// Creates a new instance of this class.
        /// </summary>
        /// <param name="canceled">Specifies the starting value for the <see cref="Microsoft.WindowsAPICodePack.Shell.CommonFileDialogResult.Canceled"/> property.</param>
        public CommonFileDialogResult(bool canceled) 
        {
            this.canceled = canceled;
        }

        private bool canceled;
        /// <summary>
        /// Gets a value that indicates whether the end user canceled the dialog.
        /// </summary>
        public bool Canceled
        {
            get { return canceled; }
        }

    }
}
