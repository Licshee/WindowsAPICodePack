//Copyright (c) Microsoft Corporation.  All rights reserved.

namespace Microsoft.WindowsAPICodePack.Shell
{
    /// <summary>
    /// Represents the base class for all search-related classes.
    /// </summary>
    public abstract class SearchContainer : ShellContainer
    {
        internal SearchContainer()
        {

        }

        internal SearchContainer(IShellItem2 shellItem):base(shellItem)
        {
        }
    }
}
