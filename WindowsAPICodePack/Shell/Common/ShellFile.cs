//Copyright (c) Microsoft Corporation.  All rights reserved.

using System;
using System.IO;

namespace Microsoft.WindowsAPICodePack.Shell
{
    /// <summary>
    /// A file in the Shell Namespace
    /// </summary>
    public sealed class ShellFile : ShellFileSystemObject
    {
        #region Internal Constructor

        internal ShellFile() { }

        #endregion

        #region Public Methods
        /// <summary>
        /// Constructs a new ShellFile object given a file path
        /// </summary>
        /// <param name="path">The file or folder path</param>
        static public ShellFile FromFilePath(string path)
        {
            if (string.IsNullOrEmpty(path))
            {
                throw new ArgumentNullException("path");
            }

            if (!File.Exists(path))
            {
                throw new FileNotFoundException("Could not find path.", path);
            }

            ShellFile shellFile = new ShellFile();
            shellFile.Path = new FileInfo(path).FullName;

            return shellFile;
        }

        #endregion

    }
}
