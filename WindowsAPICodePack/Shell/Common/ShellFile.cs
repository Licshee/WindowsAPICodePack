//Copyright (c) Microsoft Corporation.  All rights reserved.

using System;
using System.IO;

namespace Microsoft.WindowsAPICodePack.Shell
{
    /// <summary>
    /// A file in the Shell Namespace
    /// </summary>
    public class ShellFile : ShellEntity
    {
        #region Internal Constructor

        internal ShellFile()
        {

        }

        internal ShellFile(IShellItem2 shellItem)
        {
            nativeShellItem = shellItem;
        }

        #endregion

        #region Public Methods
        /// <summary>
        /// Constructs a new ShellFile object given a file path
        /// </summary>
        /// <param name="path">The file or folder path</param>
        static public ShellFile FromFilePath(string path)
        {
            // Get the absolute path
            string absPath = ShellHelper.GetAbsolutePath(path);

            // Make sure this is valid
            if (!File.Exists(absPath))
                throw new FileNotFoundException(string.Format("The given path does not exist ({0})", path));

            ShellFile file = new ShellFile();
            file.ParsingName = absPath;
            file.Path = absPath;
            return file;

        }

        #endregion

        #region Protected Properties

        /// <summary>
        /// Path for this file e.g. c:\Windows\file.txt,
        /// </summary>
        protected string path = null;

        #endregion

        #region Public Properties

        /// <summary>
        /// The path for this file
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
