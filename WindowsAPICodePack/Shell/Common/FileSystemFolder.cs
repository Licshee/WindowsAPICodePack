//Copyright (c) Microsoft Corporation.  All rights reserved.

using System;
using System.IO;

namespace Microsoft.WindowsAPICodePack.Shell
{
    /// <summary>
    /// A folder in the Shell Namespace
    /// </summary>
    public class FileSystemFolder : ShellFolder
    {
        #region Internal Constructor

        internal FileSystemFolder()
        {

        }

        internal FileSystemFolder(IShellItem2 shellItem)
        {
            nativeShellItem = shellItem;
        }

        #endregion

        #region Public Methods
        /// <summary>
        /// Constructs a new ShellFolder object given a folder path
        /// </summary>
        /// <param name="path">The folder path</param>
        static public FileSystemFolder FromFolderPath(string path)
        {
            // Get the absolute path
            string absPath = ShellHelper.GetAbsolutePath(path);
            
            // Make sure this is valid
            if(!Directory.Exists(absPath))
                throw new DirectoryNotFoundException(string.Format("The given path does not exist ({0})", path));

            FileSystemFolder folder = new FileSystemFolder();
            folder.ParsingName = absPath;
            folder.Path = absPath;
            return folder;
        }

        #endregion

        #region Protected Properties

        /// <summary>
        /// Path for this Folder e.g. c:\Windows
        /// </summary>
        protected string path = null;

        #endregion

        #region Public Properties

        /// <summary>
        /// The path for this Folder
        /// </summary>
        virtual public string Path
        {
            get
            {
                if (path == null && NativeShellItem != null)
                {
                    path = ShellHelper.GetParsingName(NativeShellItem);
                }
                return path;
            }
            protected set
            {
                this.path = value;
            }
        }

        #endregion

    }
}