//Copyright (c) Microsoft Corporation.  All rights reserved.

using System;
using System.Collections.Generic;
using System.IO;
using System.Collections.ObjectModel;
using System.Runtime.InteropServices;

namespace Microsoft.WindowsAPICodePack.Shell
{
    /// <summary>
    /// A folder in the Shell Namespace
    /// </summary>
    public sealed class ShellFolder : ShellFileSystemObject, IShellContainer<ShellObject>
    {
        #region Private Fields

        private IShellFolder nativeShellFolder;
        private static IShellFolder desktopFolder;
        private static ShellFolder desktop;
        
        #endregion

        #region Internal Properties

        internal static IShellFolder DesktopFolder
        {
            get
            {
                if (desktopFolder == null)
                {
                    ShellNativeMethods.SHGetDesktopFolder(out desktopFolder);
                }
                return desktopFolder;
            }
        }

        internal IShellFolder NativeShellFolder
        {
            get
            {
                if (nativeShellFolder == null)
                {
                    IntPtr pidl = ShellHelper.PidlFromShellItem(NativeShellItem);
                    Guid guid = new Guid(ShellIIDGuid.IShellFolder);
                    DesktopFolder.BindToObject(pidl, IntPtr.Zero, ref guid, out nativeShellFolder);
                }

                return nativeShellFolder;
            }
        }
        
        #endregion

        #region Internal Constructor


        internal ShellFolder() 
        {
        }
        
        #endregion

        #region Public Methods

        /// <summary>
        /// Constructs a new ShellFolder given a folder path
        /// </summary>
        /// <param name="path">The file or folder path</param>
        static public ShellFolder FromFolderPath(string path)
        {
            if (string.IsNullOrEmpty(path))
            {
                throw new ArgumentNullException("path");
            }

            if (!Directory.Exists(path))
            {
                throw new System.IO.DirectoryNotFoundException("Could not find path.");
            }

            ShellFolder folder = new ShellFolder();
            folder.Path = new DirectoryInfo(path).FullName;            

            return folder;
        }

        #endregion

        #region Public Properties

        /// <summary>
        /// Return the Desktop folder which is the root for all folders in the Shell namespace
        /// </summary>
        public static ShellFolder Desktop
        {
            get
            {
                if (desktop == null)
                {
                    desktop = ShellFolder.FromFolderPath(KnownFolders.Desktop);
                    desktop.nativeShellFolder = DesktopFolder;
                    desktop.path = KnownFolders.Desktop;
                }
                return desktop;
            }
        }

        #endregion

        #region Disposable Pattern

        /// <summary>
        /// Release resources
        /// </summary>
        /// <param name="disposing"></param>
        protected override void Dispose(bool disposing)
        {
            if (nativeShellFolder != null)
            {
                Marshal.FinalReleaseComObject(nativeShellFolder);
                nativeShellFolder = null;
            }

            base.Dispose(disposing);
        }
        
        /// <summary>
        /// Release resources
        /// </summary>
        ~ShellFolder()
        {
            Dispose(false);
        }

        #endregion

        #region IEnumerable<ShellObject> Members

        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        public IEnumerator<ShellObject> GetEnumerator()
        {
            return new ShellFolderItems(NativeShellFolder);
        }

        #endregion

        #region IEnumerable Members

        System.Collections.IEnumerator System.Collections.IEnumerable.GetEnumerator()
        {
            return new ShellFolderItems(NativeShellFolder);
        }

        #endregion
    }
}
