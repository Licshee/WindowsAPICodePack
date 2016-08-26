//Copyright (c) Microsoft Corporation.  All rights reserved.

namespace Microsoft.WindowsAPICodePack.Shell
{
    /// <summary>
    /// Represents a saved search
    /// </summary>
    public class SavedSearch : SearchContainer
    {
        internal SavedSearch(IShellItem2 shellItem)
            :base(shellItem)
        {
        }
    }
}
