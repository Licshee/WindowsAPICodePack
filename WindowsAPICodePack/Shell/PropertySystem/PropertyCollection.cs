//Copyright (c) Microsoft Corporation.  All rights reserved.

using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Runtime.InteropServices;
using System.Runtime.InteropServices.ComTypes;

namespace Microsoft.WindowsAPICodePack.Shell
{
    /// <summary>
    /// A readonly collection of IProperty objects
    /// </summary>
    public class PropertyCollection : ReadOnlyCollection<IProperty>
    {
        #region Private Fields

        private static PropertyDescriptionsCache Cache = PropertyDescriptionsCache.Cache;

        #endregion

        #region Internal Constructor

        /// <summary>
        /// Creates a new Property collection given an IShellItem2 native interface
        /// </summary>
        /// <param name="shellItem">Native interface</param>
        internal PropertyCollection(IShellItem2 shellItem)
            : base(new List<IProperty>())
        {
            NativeShellItem = shellItem;
            IPropertyStore nativePropertyStore = null;
            try
            {
                nativePropertyStore = CreateDefaultPropertyStore(NativeShellItem);
                AddProperties(nativePropertyStore);
            }
            finally
            {
                if (nativePropertyStore != null)
                {
                    Marshal.ReleaseComObject(nativePropertyStore);
                    nativePropertyStore = null;
                }
            }
        }

        #endregion

        #region Public Constructor

        /// <summary>
        /// Creates a new Property Collection given a file or folder path
        /// </summary>
        /// <param name="path">The path to the file or folder</param>
        public PropertyCollection(string path) : 
            this(ShellFileSystemObject.FromPath(path).NativeShellItem2)
        {
        }

        #endregion

        #region Private Methods

        private IShellItem2 NativeShellItem { get; set; }

        private void AddProperties(IPropertyStore nativePropertyStore)
        {
            uint propertyCount;
            PropertyKey propKey;

            // Populate the property collection
            nativePropertyStore.GetCount(out propertyCount);
            for (uint i = 0; i < propertyCount; i++)
            {
                nativePropertyStore.GetAt(i, out propKey);
                Items.Add(CreateTypedProperty(propKey));
            }
        }

        internal static IPropertyStore CreateDefaultPropertyStore(IShellItem2 shellItem)
        {
            IPropertyStore nativePropertyStore = null;

            Guid guid = new Guid(ShellIIDGuid.IPropertyStore);
            try
            {
                shellItem.GetPropertyStore(
                   ShellNativeMethods.GETPROPERTYSTOREFLAGS.GPS_DEFAULT,
                   ref guid,
                   out nativePropertyStore);
            }
            catch (COMException)
            {
                //We'll try one more time
            }

            // if we fail, try one more time with a more powerful flag!
            // This time, we won't catch any exceptions
            if (nativePropertyStore == null)
            {
                shellItem.GetPropertyStore(
                   ShellNativeMethods.GETPROPERTYSTOREFLAGS.GPS_BESTEFFORT,
                   ref guid,
                   out nativePropertyStore);
            }

            return nativePropertyStore;
        }

        private IProperty CreateTypedProperty(PropertyKey propKey)
        {
            PropertyDescription desc = Cache.GetPropertyDescription(propKey);

            switch (desc.VarEnumType)
            {
                case (VarEnum.VT_EMPTY):
                case (VarEnum.VT_NULL):
                    {
                        return (new Property<Object>(propKey, desc, NativeShellItem));
                    }
                case (VarEnum.VT_UI1):
                    {
                        return (new Property<Byte?>(propKey, desc, NativeShellItem));
                    }
                case (VarEnum.VT_I2):
                    {
                        return (new Property<Int16?>(propKey, desc, NativeShellItem));
                    }
                case (VarEnum.VT_UI2):
                    {
                        return (new Property<UInt16?>(propKey, desc, NativeShellItem));
                    }
                case (VarEnum.VT_I4):
                    {
                        return (new Property<Int32?>(propKey, desc, NativeShellItem));
                    }
                case (VarEnum.VT_UI4):
                    {
                        return (new Property<UInt32?>(propKey, desc, NativeShellItem));
                    }
                case (VarEnum.VT_I8):
                    {
                        return (new Property<Int64?>(propKey, desc, NativeShellItem));
                    }
                case (VarEnum.VT_UI8):
                    {
                        return (new Property<UInt64?>(propKey, desc, NativeShellItem));
                    }
                case (VarEnum.VT_R8):
                    {
                        return (new Property<Double?>(propKey, desc, NativeShellItem));
                    }
                case (VarEnum.VT_BOOL):
                    {
                        return (new Property<Boolean?>(propKey, desc, NativeShellItem));
                    }
                case (VarEnum.VT_FILETIME):
                    {
                        return (new Property<DateTime?>(propKey, desc, NativeShellItem));
                    }
                case (VarEnum.VT_CLSID):
                    {
                        return (new Property<IntPtr?>(propKey, desc, NativeShellItem));
                    }
                case (VarEnum.VT_CF):
                    {
                        return (new Property<IntPtr?>(propKey, desc, NativeShellItem));
                    }
                case (VarEnum.VT_BLOB):
                    {
                        return (new Property<Byte[]>(propKey, desc, NativeShellItem));
                    }
                case (VarEnum.VT_LPWSTR):
                    {
                        return (new Property<String>(propKey, desc, NativeShellItem));
                    }
                case (VarEnum.VT_UNKNOWN):
                    {
                        return (new Property<IntPtr?>(propKey, desc, NativeShellItem));
                    }
                case (VarEnum.VT_STREAM):
                    {
                        return (new Property<IStream>(propKey, desc, NativeShellItem));
                    }
                case (VarEnum.VT_VECTOR | VarEnum.VT_UI1):
                    {
                        return (new Property<Byte[]>(propKey, desc, NativeShellItem));
                    }
                case (VarEnum.VT_VECTOR | VarEnum.VT_I2):
                    {
                        return (new Property<Int16[]>(propKey, desc, NativeShellItem));
                    }
                case (VarEnum.VT_VECTOR | VarEnum.VT_UI2):
                    {
                        return (new Property<UInt16[]>(propKey, desc, NativeShellItem));
                    }
                case (VarEnum.VT_VECTOR | VarEnum.VT_I4):
                    {
                        return (new Property<Int32[]>(propKey, desc, NativeShellItem));
                    }
                case (VarEnum.VT_VECTOR | VarEnum.VT_UI4):
                    {
                        return (new Property<UInt32[]>(propKey, desc, NativeShellItem));
                    }
                case (VarEnum.VT_VECTOR | VarEnum.VT_I8):
                    {
                        return (new Property<Int64[]>(propKey, desc, NativeShellItem));
                    }
                case (VarEnum.VT_VECTOR | VarEnum.VT_UI8):
                    {
                        return (new Property<UInt64[]>(propKey, desc, NativeShellItem));
                    }
                case (VarEnum.VT_VECTOR | VarEnum.VT_R8):
                    {
                        return (new Property<Double[]>(propKey, desc, NativeShellItem));
                    }
                case (VarEnum.VT_VECTOR | VarEnum.VT_BOOL):
                    {
                        return (new Property<Boolean[]>(propKey, desc, NativeShellItem));
                    }
                case (VarEnum.VT_VECTOR | VarEnum.VT_FILETIME):
                    {
                        return (new Property<DateTime[]>(propKey, desc, NativeShellItem));
                    }
                case (VarEnum.VT_VECTOR | VarEnum.VT_CLSID):
                    {
                        return (new Property<IntPtr[]>(propKey, desc, NativeShellItem));
                    }
                case (VarEnum.VT_VECTOR | VarEnum.VT_CF):
                    {
                        return (new Property<IntPtr[]>(propKey, desc, NativeShellItem));
                    }
                case (VarEnum.VT_VECTOR | VarEnum.VT_LPWSTR):
                    {
                        return (new Property<String[]>(propKey, desc, NativeShellItem));
                    }
                default:
                    {
                        return (new Property<Object>(propKey, desc, NativeShellItem));
                    }
            }
        }



        #endregion

        #region Collection Public Methods

        /// <summary>
        /// Checks if a property with the given Canaonical Name is available
        /// </summary>
        public bool Contains(string canonicalName)
        {
            if (String.IsNullOrEmpty(canonicalName))
            {
                throw new NullReferenceException("Argument CanonicalName cannot be null or empty.");
            }

            return Items.
                Where(p => p.CanonicalName == canonicalName).
                Count() > 0;

        }

        /// <summary>
        /// Checks if a property with the given Property Key is available
        /// </summary>
        public bool Contains(PropertyKey key)
        {
            return Items.
                Where(p => p.PropertyKey.FormatId == key.FormatId && p.PropertyKey.PropertyId == key.PropertyId).
                Count() > 0;
        }

        /// <summary>
        /// Returns the Property with the supplied canonicalName string
        /// Property Canonical name is Case Sensitive.
        /// Also gets a property that might not be in the current collection
        /// </summary>
        /// <param name="canonicalName">The canonical name</param>
        /// <returns>The Property having the canonical name, if found</returns>
        /// <exception cref="IndexOutOfRangeException">Throws IndexOutOfRangeException 
        /// if no matching Property is found</exception>
        public IProperty this[string canonicalName]
        {
            get
            {
                if (String.IsNullOrEmpty(canonicalName))
                {
                    throw new NullReferenceException("Argument CanonicalName cannot be null or empty.");
                }

                IProperty[] props = Items
                    .Where(p => p.CanonicalName == canonicalName).ToArray();

                if (props != null && props.Length > 0 )
                    return props[0];

                throw new IndexOutOfRangeException("This CanonicalName is not a valid index.");
            }           
        }

        /// <summary>
        /// Returns a Property that have the supplied PropertyKey
        /// Also gets a property that might not be in the current collection
        /// </summary>
        /// <param name="key">The property key</param>
        /// <returns>The Property having the PropertyKey, if found</returns>
        /// <exception cref="IndexOutOfRangeException">Throws IndexOutOfRangeException 
        /// if no matching Property is found</exception>
        public IProperty this[PropertyKey key]
        {
            get
            {
                IProperty[] props = 
                    Items
                    .Where(p => p.PropertyKey.PropertyId == key.PropertyId && p.PropertyKey.FormatId == key.FormatId)
                    .ToArray();

                if (props != null && props.Length > 0)
                    return props[0];

                throw new IndexOutOfRangeException("This PropertyKey is not a valid index.");
            }
        }

        /// <summary>
        /// Get a property that's available in the Property System, 
        /// but not a part of this collection
        /// </summary>
        /// <param name="key"></param>
        /// <returns></returns>
        public IProperty GetAnyProperty(PropertyKey key)
        {
            try
            {
                return this[key];
            }
            catch (IndexOutOfRangeException) { }

            try
            {
                return CreateTypedProperty(key);
            }
            catch (COMException e)
            {
                throw new ArgumentOutOfRangeException("This PropertyKey is not valid.", e);
            }

        }

        /// <summary>
        /// Get a property that's available in the Property System, 
        /// but not a part of this collection
        /// </summary>
        /// <param name="canonicalName"></param>
        /// <returns></returns>
        public IProperty GetAnyProperty(string canonicalName)
        {
            try
            {
                return this[canonicalName];
            }
            catch (IndexOutOfRangeException) { }


            // Otherwise, call the native PropertyStore method
            PropertyKey propKey;

            int result = PropertySystemNativeMethods.PSGetPropertyKeyFromName(canonicalName, out propKey);

            if (!CoreErrorHelper.Succeeded(result))
            {
                throw new ArgumentOutOfRangeException(
                    "This CanonicalName is not a valid index.",
                    Marshal.GetExceptionForHR(result));
            }

            try
            {
                return CreateTypedProperty(propKey);
            }
            catch (COMException e)
            {
                throw new ArgumentOutOfRangeException("This CanonicalName is not valid.", e);
            }

        }
        #endregion

    }
}
