//Copyright (c) Microsoft Corporation.  All rights reserved.

using System;
using System.Runtime.InteropServices;
using System.IO;

namespace Microsoft.WindowsAPICodePack.Shell.Taskbar
{
    /// <summary>
    /// Represents a jump list item
    /// </summary>
    public class JumpListItem : IJumpListItem
    {
        /// <summary>
        /// Path to jump list item
        /// </summary>
        public string Path { get; set; }

        /// <summary>
        /// Creates a jump list item with the specified path
        /// </summary>
        /// <param name="Path">Path to jump list item</param>
        public JumpListItem(string Path)
        {
            this.Path = Path;
        }

        /// <summary>
        /// Gets an IShellItem representation of this object
        /// </summary>
        /// <returns>An IShellItem object</returns>
        public object GetShellRepresentation()
        {
            return ShellFileSystemObject.FromPath(Path).NativeShellItem;
        }
    }
}
