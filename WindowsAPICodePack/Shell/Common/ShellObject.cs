//Copyright (c) Microsoft Corporation.  All rights reserved.

using System;
using System.IO;
using System.Runtime.InteropServices;

namespace Microsoft.WindowsAPICodePack.Shell
{
    /// <summary>
    /// The base class for all Shell objects in Shell Namespace
    /// </summary>
    abstract public class ShellObject : IDisposable
    {

        #region Public Static Methods

        /// <summary>
        /// Creates a ShellObject subclass given a parsing name.
        /// For file system items, this method will only accept absolute paths.
        /// </summary>
        /// <param name="parsingName"></param>
        /// <returns>A newly constructed ShellObject object</returns>
        public static ShellObject FromParsingName(string parsingName)
        {
            return ShellObjectFactory.Create(parsingName);
        }

        #endregion

        #region Internal Fields

        /// <summary>
        /// Internal member to keep track of the native IShellItem2
        /// </summary>
        internal IShellItem2 nativeShellItem;

        #endregion

        internal ShellObject()
        {

        }

        internal ShellObject(IShellItem2 shellItem)
        {
            nativeShellItem = shellItem;
        }



        #region Protected Fields

        /// <summary>
        /// Parsing name for this Object e.g. c:\Windows\file.txt,
        /// or ::{Some Guid} 
        /// </summary>
        protected string parsingName = null;

        /// <summary>
        /// A friendly name for this object that' suitable for display
        /// </summary>
        protected string name = null;

        /// <summary>
        /// PID List (PIDL) for this object
        /// </summary>
        protected IntPtr pidl = IntPtr.Zero;

        #endregion

        #region Internal Properties

        /// <summary>
        /// Return the native ShellFolder object as newer IShellItem2
        /// </summary>
        /// <exception cref="System.Runtime.InteropServices.ExternalException">If the native object cannot be created.
        /// The ErrorCode member will contain the external error code.</exception>
        virtual internal IShellItem2 NativeShellItem2
        {
            get
            {
                if (nativeShellItem == null && ParsingName != null)
                {
                    Guid guid = new Guid(ShellIIDGuid.IShellItem2);
                    int retCode = ShellNativeMethods.SHCreateItemFromParsingName(ParsingName, IntPtr.Zero, ref guid, out nativeShellItem);

                    if (nativeShellItem == null || !CoreErrorHelper.Succeeded(retCode))
                    {
                        throw new ExternalException("Shell item could not be created.", Marshal.GetExceptionForHR(retCode));
                    }
                }
                return nativeShellItem;
            }
        }

        /// <summary>
        /// Return the native ShellFolder object
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

        private PropertyCollection properties = null;
        /// <summary>
        /// Retrieve the Readonly Properties of this Shell Item
        /// Non-file shell items can only have read only properties
        /// </summary>
        public PropertyCollection Properties
        {
            get
            {
                if (properties == null && NativeShellItem2 != null)
                {
                    properties = new PropertyCollection(this);
                }
                return properties;
            }
        }

        /// <summary>
        /// The parsing name for this Shell Item
        /// </summary>
        virtual public string ParsingName
        {
            get
            {
                if (parsingName == null && nativeShellItem != null)
                {
                    parsingName = ShellHelper.GetParsingName(nativeShellItem);
                }
                return parsingName;
            }
            protected set
            {
                this.parsingName = value;
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
                    IntPtr pszString = IntPtr.Zero;
                    HRESULT hr = NativeShellItem.GetDisplayName(ShellNativeMethods.SIGDN.SIGDN_NORMALDISPLAY, out pszString);
                    if (hr == HRESULT.S_OK && pszString != IntPtr.Zero)
                    {
                        name = Marshal.PtrToStringAuto(pszString);
                    }
                }
                return name;
            }

            protected set
            {
                this.name = value;
            }
        }

        /// <summary>
        /// The PID List (PIDL) for this ShellItem
        /// </summary>
        virtual internal IntPtr PIDL
        {
            get
            {
                // Get teh PIDL for the ShellItem
                if (pidl == IntPtr.Zero && NativeShellItem != null)
                    pidl = ShellHelper.PidlFromShellItem(nativeShellItem);

                return pidl;
            }
            set
            {
                this.pidl = value;
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
        /// Gets the display name of the ShellFolder object. DisplayNameType represents one of the 
        /// values that indicates how the name should look. 
        /// See <see cref="Microsoft.WindowsAPICodePack.Shell.DisplayNameType"/>for a list of possible values.
        /// </summary>
        /// <param name="displayNameType"></param>
        /// <returns></returns>
        virtual public string GetDisplayName(DisplayNameType displayNameType)
        {
            string returnValue = null;

            HRESULT hr = HRESULT.S_OK;

            if (NativeShellItem2 != null)
                hr = NativeShellItem2.GetDisplayName((ShellNativeMethods.SIGDN)displayNameType, out returnValue);

            if (hr != HRESULT.S_OK)
                throw new COMException("Can't get the display name", (int)hr);

            return returnValue;
        }

        /// <summary>
        /// Checks if this Shell Object is a link or shortcut
        /// </summary>
        public bool IsLink
        {
            get
            {
                try
                {
                    ShellNativeMethods.SFGAO sfgao;
                    NativeShellItem.GetAttributes(ShellNativeMethods.SFGAO.SFGAO_LINK, out sfgao);
                    return (sfgao & ShellNativeMethods.SFGAO.SFGAO_LINK) != 0;
                }
                catch (FileNotFoundException)
                {
                    return false;
                }
                catch (NullReferenceException)
                {
                    // TODO
                    // NativeShellItem is null ... do we throw an exception or ignore it?
                    return false;
                }
            }
        }

        /// <summary>
        /// Checks if this Shell Object is a link or shortcut
        /// </summary>
        public bool IsFileSystemObject
        {
            get
            {
                try
                {
                    ShellNativeMethods.SFGAO sfgao;
                    NativeShellItem.GetAttributes(ShellNativeMethods.SFGAO.SFGAO_FILESYSTEM, out sfgao);
                    return (sfgao & ShellNativeMethods.SFGAO.SFGAO_FILESYSTEM) != 0;
                }
                catch (FileNotFoundException)
                {
                    return false;
                }
                catch (NullReferenceException)
                {
                    // TODO
                    // NativeShellItem is null ... do we throw an exception or ignore it?
                    return false;
                }
            }
        }

        private ShellThumbnail thumbnail;
        /// <summary>
        /// Gets the thumbnail of the ShellObject.
        /// </summary>
        public ShellThumbnail Thumbnail
        {
            get
            {
                if (thumbnail == null)
                    thumbnail = new ShellThumbnail(this);

                return thumbnail;
            }
        }

        private ShellObject parentShellObject = null;
        /// <summary>
        /// Gets the parent ShellObject
        /// </summary>
        public ShellObject Parent
        {
            get
            {
                if (parentShellObject == null && nativeShellItem != null)
                {
                    IShellItem parentShellItem = null;

                    HRESULT hr = nativeShellItem.GetParent(out parentShellItem);

                    if (hr == HRESULT.S_OK && parentShellItem != null)
                        parentShellObject = ShellObjectFactory.Create(parentShellItem);
                    else
                        throw Marshal.GetExceptionForHR((int)hr);
                }

                return parentShellObject;
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
                parsingName = null;
            }

            if (nativeShellItem != null)
            {
                Marshal.ReleaseComObject(nativeShellItem);
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
