//Copyright (c) Microsoft Corporation.  All rights reserved.

using System;
using System.Diagnostics;
using System.Reflection;
using System.Runtime.InteropServices;

namespace Microsoft.WindowsAPICodePack.Shell
{
    /// <summary>
    /// A strongly typed Property object. 
    /// Writable Property objects must be of this type 
    /// to be able to call the Value Setter
    /// </summary>
    /// <typeparam name="T">The type for this property's value. 
    /// Because a property value can be empty, only Nullable types 
    /// are allowed; e.g uint? or string for its value</typeparam>
    public class Property<T> : IProperty
    {
        #region Private Fields

        private PropertyKey propertyKey;
        string imageReferencePath = null;
        int? imageReferenceIconIndex;
        private PropertyDescription description = null;

        #endregion

        #region Private Methods

        private IShellItem2 NativeShellItem { get; set; }

        private void GetImageRefernece()
        {
            PropVariant propVar;
            
            IPropertyStore store = PropertyCollection.CreateDefaultPropertyStore(NativeShellItem);

            store.GetValue(ref propertyKey, out propVar);

            Marshal.ReleaseComObject(store);
            store = null;

            string refPath;
            ((IPropertyDescription2)Description.NativePropertyDescription).GetImageReferenceForValue(
                ref propVar, out refPath);

            if (refPath == null)
            {
                return;
            }

            int index = ShellNativeMethods.PathParseIconLocation(ref refPath);
            if (refPath != null)
            {
                imageReferencePath = refPath;
                imageReferenceIconIndex = index;
            }
        }

        private void StorePropVariantValue(PropVariant propVar)
        {
            Guid guid = new Guid(ShellIIDGuid.IPropertyStore);
            IPropertyStore writablePropStore = null;
            try
            {
                NativeShellItem.GetPropertyStore(
                    ShellNativeMethods.GETPROPERTYSTOREFLAGS.GPS_READWRITE,
                    ref guid,
                    out writablePropStore);

                writablePropStore.SetValue(ref propertyKey, ref propVar);
                writablePropStore.Commit();
            }
            catch (InvalidCastException)
            {
                throw new ExternalException("Unable to get writable property store for this property.");
            }
            catch (COMException e)
            {
                throw new ExternalException("Unable to set the value of this property.", e);
            }
            finally
            {
                if (writablePropStore != null)
                {
                    Marshal.FinalReleaseComObject(writablePropStore);
                    writablePropStore = null;
                }
            }
        }

        #endregion

        #region Internal Constructor

        /// <summary>
        /// Constructs a new Property object
        /// </summary>
        /// <param name="propertyKey"></param>
        /// <param name="description"></param>
        /// <param name="shellItem"></param>
        internal Property(
            PropertyKey propertyKey,
            PropertyDescription description,
            IShellItem2 shellItem
            )
        {
            this.propertyKey = propertyKey;
            this.description = description;
            NativeShellItem = shellItem;
        }

        #endregion

        #region Public Properties

        /// <summary>
        /// The value of this property, using a strong type.
        /// If the Value is set to null, it will be cleared.
        /// </summary>
        /// <exception cref="System.Runtime.InteropServices.COMException">
        /// If the property value cannot be retrieved or updated in the Property System</exception>
        public T Value
        {
            get
            {
                // Make sure we load the correct type
                Debug.Assert(ValueType == PropertyDescription.VarEnumToSystemType(Description.VarEnumType));

                PropVariant propVar;
                IPropertyStore store = PropertyCollection.CreateDefaultPropertyStore(NativeShellItem);
                store.GetValue(ref propertyKey, out propVar);

                //Release the store as soon as we can
                Marshal.ReleaseComObject(store);
                store = null;

                //Get the value
                T value;
                try
                {
                    value = (T) propVar.Value;
                }
                finally
                {
                    propVar.Clear();
                }

                return value;
            }

            
            set
            {
                // Make sure we use the correct type
                Debug.Assert(ValueType == PropertyDescription.VarEnumToSystemType(Description.VarEnumType));

                PropVariant propVar = new PropVariant();

                if (typeof(T) != ValueType)
                {
                    throw new NotSupportedException(
                        String.Format("This property only accepts a value of type \"{0}\".", ValueType.Name));
                }

                if (value is Nullable)
                {
                    Type t = typeof(T);
                    PropertyInfo pi = t.GetProperty("HasValue");
                    if (pi != null)
                    {
                        bool hasValue = (bool)pi.GetValue(value, null);
                        if (!hasValue)
                        {
                            ClearValue();
                            return;
                        }
                    }
                }
                else if (value == null)
                {
                    ClearValue();
                    return;
                }

                try
                {
                    propVar = SetValue(value);
                    StorePropVariantValue(propVar);
                }
                finally
                {
                    // Release objects
                    propVar.Clear();
                }
            }
        }

        /// <summary>
        /// Set the property value. 
        /// At this point we're sure every 
        /// property has a value, or for non Nullable types, it's not null
        /// </summary>
        /// <param name="value"></param>
        /// <returns></returns>
        private PropVariant SetValue(T value)
        {
            PropVariant propVar = new PropVariant();

            if (typeof(T) == typeof(string))
            {
                //Strings require special consideration, because they cannot be empty as well
                if (String.IsNullOrEmpty(value as string) || String.IsNullOrEmpty((value as string).Trim()))
                    throw new ArgumentException("String argument cannot be null or empty.");
                propVar.SetString(value as string);
            }
            else if (typeof(T) == typeof(bool?))
            {
                propVar.SetBool((value as bool?).Value);
            }
            else if (typeof(T) == typeof(byte?))
            {
                propVar.SetByte((value as byte?).Value);
            }
            else if (typeof(T) == typeof(sbyte?))
            {
                propVar.SetSByte((value as sbyte?).Value);
            }
            else if (typeof(T) == typeof(short?))
            {
                propVar.SetShort((value as short?).Value);
            }
            else if (typeof(T) == typeof(ushort?))
            {
                propVar.SetUShort((value as ushort?).Value);
            }
            else if (typeof(T) == typeof(int?))
            {
                propVar.SetInt((value as int?).Value);
            }
            else if (typeof(T) == typeof(uint?))
            {
                propVar.SetUInt((value as uint?).Value);
            }
            else if (typeof(T) == typeof(long?))
            {
                propVar.SetLong((value as long?).Value);
            }
            else if (typeof(T) == typeof(ulong?))
            {
                propVar.SetULong((value as ulong?).Value);
            }
            else if (typeof(T) == typeof(double?))
            {
                propVar.SetDouble((value as double?).Value);
            }
            else if (typeof(T) == typeof(DateTime?))
            {
                propVar.SetDateTime((value as DateTime?).Value);
            }
            else if (typeof(T) == typeof(string[]))
            {
                propVar.SetStringVector((value as string[]));
            }
            else if (typeof(T) == typeof(short[]))
            {
                propVar.SetShortVector((value as short[]));
            }
            else if (typeof(T) == typeof(ushort[]))
            {
                propVar.SetUShortVector((value as ushort[]));
            }
            else if (typeof(T) == typeof(int[]))
            {
                propVar.SetIntVector((value as int[]));
            }
            else if (typeof(T) == typeof(uint[]))
            {
                propVar.SetUIntVector((value as uint[]));
            }
            else if (typeof(T) == typeof(long[]))
            {
                propVar.SetLongVector((value as long[]));
            }
            else if (typeof(T) == typeof(ulong[]))
            {
                propVar.SetULongVector((value as ulong[]));
            }
            else if (typeof(T) == typeof(DateTime[]))
            {
                propVar.SetDateTimeVector((value as DateTime[]));
            }
            else if (typeof(T) == typeof(bool[]))
            {
                propVar.SetBoolVector((value as bool[]));
            }
            else
            {
                //Should not happen!
                throw new NotSupportedException("This Value type is not supported");
            }

            return propVar;
        }

        #endregion

        #region IProperty Members

        /// <summary>
        /// The Property Key identifying this Property
        /// </summary>
        public PropertyKey PropertyKey
        {
            get
            {
                return propertyKey;
            }
        }

        /// <summary>
        /// Gets a formatted, Unicode string representation of a property value
        /// </summary>
        /// <param name="format">One or more of the PropertyDescriptionFormat flags 
        /// that indicate the desired format</param>
        /// <returns>The formatted value as a string, or null if this property 
        /// cannot be formatted for display</returns>
        public string FormatForDisplay(PropertyDescriptionFormat format)
        {
            string formattedString;
            PropVariant propVar;

            if (Description == null || Description.NativePropertyDescription == null)
            {
                // We cannot do anything without a property description
                return null;
            }

            IPropertyStore store = PropertyCollection.CreateDefaultPropertyStore(NativeShellItem);

            store.GetValue(ref propertyKey, out propVar);

            // Release the Propertystore
            Marshal.ReleaseComObject(store);
            store = null;

            try
            {
                Description.NativePropertyDescription.FormatForDisplay(ref propVar, ref format, out formattedString);
            }
            catch (COMException)
            {
                // Sometimes, the value cannot be displayed properly, such as for blobs
                return null;
            }
            catch (System.ArgumentException)
            {
                return null;
            }

            return formattedString;
        }

        /// <summary>
        /// Get the property description object
        /// </summary>
        public PropertyDescription Description
        {
            get
            {
                return description;
            }
        }

        /// <summary>
        /// Gets the case-sensitive name by which 
        /// a property is known to the system, regardless of its localized name.
        /// </summary>
        public string CanonicalName
        {
            get
            {
                return Description.CanoninicalName;
            }
        }

        /// <summary>
        /// Clear the value for the property
        /// </summary>
        public void ClearValue()
        {
            PropVariant propVar = new PropVariant();
            propVar.SetEmptyValue();

            StorePropVariantValue(propVar);
        }

        /// <summary>
        /// Return the value for this property using generic "Object" type.
        /// To obtain a specific type for this value, use the more type strong
        /// Property&lt;T&gt; class.
        /// Also, you can only set a value for this type using Property&lt;T&gt;
        /// </summary>
        public object ValueAsObject
        {
            get
            {
                PropVariant propVar;

                IPropertyStore store = PropertyCollection.CreateDefaultPropertyStore(NativeShellItem);

                store.GetValue(ref propertyKey, out propVar);

                Marshal.ReleaseComObject(store);
                store = null;

                object value = null;

                try
                {
                    value = propVar.Value;
                }
                finally
                {
                    propVar.Clear();
                }

                return value;
            }
        }

        /// <summary>
        /// Get the associated Runtime Type
        /// </summary>
        public Type ValueType
        {
            get
            {
                // The type for this object need to match that of the description
                Debug.Assert(Description.ValueType == typeof(T));

                return Description.ValueType;
            }
        }

        /// <summary>
        /// Gets the image reference path associated with a property value 
        /// This is a Windows 7 only API
        /// </summary>
        public string ImageReferencePath
        {
            get
            {
                if (!CoreHelpers.RunningOnWin7)
                {
                    throw new PlatformNotSupportedException("This Property is available on Windows 7 only.");
                }

                if (imageReferencePath == null)
                {
                    GetImageRefernece();
                }

                return imageReferencePath;
            }
        }

        /// <summary>
        /// Gets the image reference icon index associated with a property value 
        /// This is a Windows 7 only API
        /// </summary>
        public int ImageReferenceIconIndex
        {
            get
            {
                if (!CoreHelpers.RunningOnWin7)
                {
                    throw new PlatformNotSupportedException("This Property is available on Windows 7 only.");
                }

                if (!imageReferenceIconIndex.HasValue)
                {
                    GetImageRefernece();
                }

                return (imageReferenceIconIndex.HasValue ? imageReferenceIconIndex.Value : -1);
            }
        }

        #endregion

    }
}
