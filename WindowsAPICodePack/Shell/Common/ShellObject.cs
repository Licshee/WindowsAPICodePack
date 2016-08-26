//Copyright (c) Microsoft Corporation.  All rights reserved.

using System;
using System.IO;
using System.Runtime.InteropServices;
using System.Diagnostics;
using System.Collections.Generic;
namespace Microsoft.WindowsAPICodePack.Shell
{
    /// <summary>
    /// The base class for all Shell objects in Shell Namespace
    /// </summary>
    abstract public class ShellObject : IDisposable
    {
        #region Internal Methods

        /// <summary>
        /// Creates a ShellObject given a native IShellItem interface
        /// </summary>
        /// <param name="nativeShellItem"></param>
        /// <returns>A newly constructed ShellObject object</returns>
        internal static ShellObject FromShellItem(IShellItem nativeShellItem)
        {
            if (nativeShellItem == null)
                throw new ArgumentNullException("nativeShellItem");
            
            bool isLibrary = ShellHelper.IsLibrary(nativeShellItem);
            bool isFolder = ShellHelper.IsFolder(nativeShellItem);
            string parsingName = ShellHelper.GetParsingName(nativeShellItem);

            // Need to check if this file/path is a library, search connector, knownfolder, directory or a file.
            if (ShellHelper.IsLibrary(nativeShellItem))
            {
                if (parsingName.StartsWith("::"))
                {
                    KnownFolder kf = KnownFolder.FromShellItem(nativeShellItem);
                    if (kf != null)
                        return ShellLibrary.Load(kf, true);
                }
                else
                {
                    try
                    {
                        return ShellLibrary.FromShellItem(nativeShellItem, true);
                    }
                    catch (COMException)
                    {} // Might be thrown if this is a known folder
                    catch (IOException)
                    { } // Might be thrown if this is a known folder

                    // Try one more time from a known folder
                    KnownFolder kf = KnownFolder.FromShellItem(nativeShellItem);
                    if (kf != null)
                        return ShellLibrary.Load(kf, true);

                }
            }

            if (ShellHelper.IsSearchConnector(nativeShellItem))
            {
                return SearchConnector.FromShellItem(nativeShellItem);
            }

            // Try to see if it's a known folder
            if (isFolder)
            {
                try
                {
                    KnownFolder folder;

                    if ((folder = KnownFolder.FromShellItem(nativeShellItem)) != null)
                        return folder;
                }
                catch (COMException)
                {} // Will be thrown if this is NOT a Known folder
                catch (IOException)
                {}
                catch (KeyNotFoundException)
                {}
            }

            // If all else fails, return a ShellFolder or ShellFile
            return ShellFileSystemObject.FromShellItem(nativeShellItem);
        }

        /// <summary>
        /// Creates a ShellObject subclass given a path. Not all ShellObjects will have a valid path,
        /// so for some the return value might be null.
        /// </summary>
        /// <param name="path"></param>
        /// <returns>A newly constructed ShellObject object</returns>
        public static ShellObject FromPath(string path)
        {
            if (string.IsNullOrEmpty(path))
                throw new ArgumentNullException("path");

            // First try to see if it's a special folder
            if (path.StartsWith("::"))
            {
                return KnownFolderManager.GetKnownFolderFromParsingName(path);
            }

            // Create a native shellitem from our path
            IShellItem2 nativeShellItem;
            Guid guid = new Guid(ShellIIDGuid.IShellItem2);
            int retCode = ShellNativeMethods.SHCreateItemFromParsingName(path, IntPtr.Zero, ref guid, out nativeShellItem);

            if (CoreErrorHelper.Succeeded(retCode))
            {
                return ShellObject.FromShellItem(nativeShellItem);
            }
            else
            {
                throw new ExternalException("Unable to Create Shell Item from IDList", Marshal.GetExceptionForHR(retCode));
            }
        }

        /// <summary>
        /// Constructs a new Shell object from IDList pointer
        /// </summary>
        /// <param name="idPistPtr"></param>
        /// <returns></returns>
        internal static ShellObject FromIDList(IntPtr idPistPtr)
        {
            Guid guid = new Guid(ShellIIDGuid.IShellItem2);
            IShellItem2 nativeShellItem;
            int retCode = ShellNativeMethods.SHCreateItemFromIDList(idPistPtr, ref guid, out nativeShellItem);
            if (CoreErrorHelper.Succeeded(retCode))
            {
                return ShellObject.FromShellItem(nativeShellItem);
            }
            else
            {
                throw new ExternalException("Unable to Create Shell Item from IDList", Marshal.GetExceptionForHR(retCode));
            }
        }

        /// <summary>
        /// Constructs a new Shell object from IDList pointer
        /// </summary>
        /// <param name="idPistPtr"></param>
        /// <param name="parent"></param>
        /// <returns></returns>
        internal static ShellObject FromIDList(IntPtr idPistPtr, IShellFolder parent)
        {
            IShellItem nativeShellItem;

            int retCode = ShellNativeMethods.SHCreateShellItem(
                IntPtr.Zero,
                parent,
                idPistPtr, out nativeShellItem);
            
            if (CoreErrorHelper.Succeeded(retCode))
            {
                return ShellObject.FromShellItem(nativeShellItem);
            }
            else
            {
                throw new ExternalException("Unable to Create Shell Item from IDList", Marshal.GetExceptionForHR(retCode));
            }
        }

        #endregion

        #region Internal Fields

        /// <summary>
        /// Internal member to keep track of the native IShellItem2
        /// </summary>
        internal IShellItem2 nativeShellItem;

        #endregion

        #region Protected Fields

        /// <summary>
        /// path for this Object e.g. c:\Windows\file.txt,
        /// or ::{Some Guid} 
        /// </summary>
        protected string path = null;

        /// <summary>
        /// A friendly name for this object that' suitable for display
        /// </summary>
        protected string name = null;

        #endregion

        #region Internal Properties

        /// <summary>
        /// Return the native ShellFileSystemObject object as newer IShellItem2
        /// </summary>
        /// <exception cref="System.Runtime.InteropServices.ExternalException">If the native object cannot be created.
        /// The ErrorCode member will contain the external error code.</exception>
        virtual internal IShellItem2 NativeShellItem2
        {
            get
            {
                if (nativeShellItem == null && path != null)
                {
                    Guid guid = new Guid(ShellIIDGuid.IShellItem2);
                    int retCode = ShellNativeMethods.SHCreateItemFromParsingName(Path, IntPtr.Zero, ref guid, out nativeShellItem);

                    if (nativeShellItem == null || !CoreErrorHelper.Succeeded(retCode))
                    {
                        throw new ExternalException("Shell item could not be created.", Marshal.GetExceptionForHR(retCode));

                    }
                }
                return nativeShellItem;
            }
        }

        /// <summary>
        /// Return the native ShellFileSystemObject object
        /// </summary>
        virtual internal IShellItem NativeShellItem
        {
            get
            {
                return NativeShellItem2;
            }
        }

        #endregion

        #region Public Properties


        /// <summary>
        /// The path for this Shell Item
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

        /// <summary>
        /// The Normal Display for this Shell Item
        /// </summary>
        virtual public string Name
        {
            get
            {
                if (name == null && NativeShellItem != null)
                {
                    NativeShellItem.GetDisplayName(ShellNativeMethods.SIGDN.SIGDN_NORMALDISPLAY, out name);
                }
                return name;
            }

            protected set
            {
                this.name = value;
            }
        }

        /// <summary>
        /// Override object.ToString()
        /// </summary>
        /// <returns></returns>
        public override string ToString()
        {
            return this.Name;
        }

        /// <summary>
        /// Gets the display name of the ShellFileSystemObject object. ShellItemDisplayNameType represents one of the 
        /// values that indicates how the name should look. 
        /// See <see cref="Microsoft.WindowsAPICodePack.Shell.ShellItemDisplayNameType"/>for a list of possible values.
        /// </summary>
        /// <param name="displayNameType"></param>
        /// <returns></returns>
        virtual public string GetDisplayName(ShellItemDisplayNameType displayNameType)
        {
            string returnValue = null;

            if (NativeShellItem2 != null)
                NativeShellItem2.GetDisplayName((ShellNativeMethods.SIGDN)displayNameType, out returnValue);

            return returnValue;
        }

        /// <summary>
        /// Checks if this Shell Object is a link or shortcut
        /// </summary>
        public bool IsLink
        {
            get
            {
                ShellNativeMethods.SFGAO sfgao;
                NativeShellItem.GetAttributes(ShellNativeMethods.SFGAO.SFGAO_LINK, out sfgao);
                return (sfgao & ShellNativeMethods.SFGAO.SFGAO_LINK) != 0;
            }
        }

        /// <summary>
        /// Checks if this Shell Object is a link or shortcut
        /// </summary>
        public bool IsFileSystemObject
        {
            get
            {
                ShellNativeMethods.SFGAO sfgao;
                NativeShellItem.GetAttributes(ShellNativeMethods.SFGAO.SFGAO_FILESYSTEM, out sfgao);
                return (sfgao & ShellNativeMethods.SFGAO.SFGAO_FILESYSTEM) != 0;
            }
        }

        #endregion

        #region IDisposable Members

        /// <summary>
        /// Release the native and managed objects
        /// </summary>
        protected virtual void Dispose(bool disposing)
        {
            if (disposing)
            {
                name = null;
                path = null;
            }

            if (nativeShellItem != null)
            {
                Marshal.FinalReleaseComObject(nativeShellItem);
                nativeShellItem = null;
            }

        }

        /// <summary>
        /// Release the native objects
        /// </summary>
        public void Dispose()
        {
            Dispose(true);
            GC.SuppressFinalize(this);
        }

        /// <summary>
        /// 
        /// </summary>
        ~ShellObject()
        {
            Dispose(false);
        }

        #endregion
    }
}
