//Copyright (c) Microsoft Corporation.  All rights reserved.

using System;
using System.Collections.ObjectModel;
using System.Runtime.InteropServices;
using System.Runtime.InteropServices.ComTypes;
using System.Collections.Generic;

namespace Microsoft.WindowsAPICodePack.Shell
{
    /// <summary>
    /// Provides information that describe a property.
    /// </summary>
    public class PropertyDescription : IDisposable
    {
        #region Private Fields

        private IPropertyDescription nativePropertyDescription = null;
        private string canoninicalName = null;
        private PropertyKey propertyKey;
        private string displayName = null;
        private string editInvitation = null;
        private VarEnum varEnumType = VarEnum.VT_EMPTY;
        private PropertyDisplayType? displayType;
        private PropertyAggregationType? aggregationTypes;
        private uint? defaultColumWidth;
        private PropertySystemNativeMethods.PROPDESC_TYPE_FLAGS? propertyTypeFlags;
        private Type valueType = null;
        private List<PropertyEnumType> propEnumTypeList = new List<PropertyEnumType>();
        private ReadOnlyCollection<PropertyEnumType> propertyEnumTypes = null;
        #endregion

        #region Private methods

        private void GetTypeFlags()
        {
            if (NativePropertyDescription != null && !propertyTypeFlags.HasValue)
            {
                PropertySystemNativeMethods.PROPDESC_TYPE_FLAGS tempFlags;
                NativePropertyDescription.GetTypeFlags(
                    PropertySystemNativeMethods.PROPDESC_TYPE_FLAGS.PDTF_MASK_ALL,
                    out tempFlags);
                propertyTypeFlags = tempFlags;
            }
        }
        
        #endregion

        #region Public Properties

        /// <summary>
        /// Gets the case-sensitive name by which 
        /// a property is known to the system, regardless of its localized name.
        /// </summary>
        public string CanoninicalName
        {
            get
            {
                if (canoninicalName == null)
                {
                    PropertySystemNativeMethods.PSGetNameFromPropertyKey(ref propertyKey, out canoninicalName);
                }
                return canoninicalName;
            }
        }

        /// <summary>
        /// The property key identifying the underlying property
        /// </summary>
        public PropertyKey PropertyKey
        {
            get
            {
                return propertyKey;
            }
        }

        /// <summary>
        /// Gets the display name of the property as it is shown in any user interface (UI).
        /// </summary>
        public string DisplayName
        {
            get
            {
                if (NativePropertyDescription != null && displayName == null)
                {
                    try
                    {
                        NativePropertyDescription.GetDisplayName(out displayName);
                    }
                    catch (COMException)
                    { 
                        // DisplayName can be empty
                    }
                }

                return displayName;
            }
        }

        /// <summary>
        /// Gets the text used in edit controls hosted in various dialog boxes.
        /// </summary>
        public string EditInvitation
        {
            get
            {
                if (NativePropertyDescription != null && editInvitation == null)
                {
                    try
                    {
                        NativePropertyDescription.GetEditInvitation(out editInvitation);
                    }
                    catch (COMException)
                    { 
                        // EditInvitation can be empty
                    }
                }

                return editInvitation;
            }
        }

        /// <summary>
        /// The VarEnum OLE Type for value of this property
        /// </summary>
        public VarEnum VarEnumType
        {
            get
            {
                if (NativePropertyDescription != null && varEnumType == VarEnum.VT_EMPTY)
                {
                    NativePropertyDescription.GetPropertyType(out varEnumType);
                }

                return varEnumType;
            }
        }

        /// <summary>
        /// The System (.Net) Type for a value of this property
        /// A null return means the type is empty
        /// </summary>
        public Type ValueType
        {
            get
            {
                if (valueType == null)
                {
                    //valueType = typeof(Object);

                    valueType = VarEnumToSystemType(VarEnumType);
                }
                return valueType;
            }
        }

        /// <summary>
        /// Gets the current data type used to display the property.
        /// </summary>
        public PropertyDisplayType DisplayType
        {
            get
            {
                if (NativePropertyDescription != null && !displayType.HasValue)
                {
                    PropertyDisplayType tempDisplayType;
                    NativePropertyDescription.GetDisplayType(out tempDisplayType);
                    displayType = tempDisplayType;
                }

                return displayType.HasValue ? displayType.Value : default(PropertyDisplayType);
            }
        }

        /// <summary>
        /// The default UI column width for this property
        /// </summary>
        public uint DefaultColumWidth
        {
            get
            {
                if (NativePropertyDescription != null && !defaultColumWidth.HasValue)
                {
                    uint tempDefaultColumWidth;
                    NativePropertyDescription.GetDefaultColumnWidth(out tempDefaultColumWidth);
                    defaultColumWidth = tempDefaultColumWidth;
                }

                return defaultColumWidth.HasValue ? defaultColumWidth.Value : default(uint);
            }
        }

        /// <summary>
        /// Gets a value that describes how the property values are displayed when 
        /// multiple items are selected in the user interface (UI).
        /// </summary>
        public PropertyAggregationType AggregationTypes
        {
            get
            {
                if (NativePropertyDescription != null && !aggregationTypes.HasValue)
                {
                    PropertyAggregationType tempAggregationTypes;
                    NativePropertyDescription.GetAggregationType(out tempAggregationTypes);
                    aggregationTypes = tempAggregationTypes;
                }

                return aggregationTypes.HasValue ? aggregationTypes.Value : default(PropertyAggregationType);
            }
        }

        /// <summary>
        /// Enumerate the possible values for this property
        /// </summary>
        public ReadOnlyCollection<PropertyEnumType> PropertyEnumTypes
        {
            get
            {
                if (propertyEnumTypes == null)
                {
                    Guid guid = new Guid(ShellIIDGuid.IPropertyEnumTypeList);
                    IPropertyEnumTypeList nativeList;
                    NativePropertyDescription.GetEnumTypeList(ref guid, out nativeList);

                    if (nativeList == null)
                        return null;

                    uint count;
                    nativeList.GetCount(out count);
                    guid = new Guid(ShellIIDGuid.IPropertyEnumType);

                    for (uint i = 0; i < count; i++)
                    {
                        IPropertyEnumType nativeEnumType;
                        nativeList.GetAt(i, ref guid, out nativeEnumType);
                        propEnumTypeList.Add(new PropertyEnumType(nativeEnumType));
                    }

                    propertyEnumTypes = new ReadOnlyCollection<PropertyEnumType>(propEnumTypeList);
                }

                return propertyEnumTypes;

            }
        }

        /// <summary>
        /// This property cannot be written to.
        /// </summary>
        public bool IsInnate
        {
            get
            {
                GetTypeFlags();
                return propertyTypeFlags.HasValue ? 
                    ((propertyTypeFlags.Value & 
                        PropertySystemNativeMethods.PROPDESC_TYPE_FLAGS.PDTF_ISINNATE) == 
                        PropertySystemNativeMethods.PROPDESC_TYPE_FLAGS.PDTF_ISINNATE)
                    : default(bool);
            }
        }

        /// <summary>
        /// The property can have multiple values.
        /// </summary>
        public bool HasMultipleValues
        {
            get
            {
                GetTypeFlags();
                return propertyTypeFlags.HasValue ?
                    ((propertyTypeFlags.Value & 
                        PropertySystemNativeMethods.PROPDESC_TYPE_FLAGS.PDTF_MULTIPLEVALUES) == 
                        PropertySystemNativeMethods.PROPDESC_TYPE_FLAGS.PDTF_MULTIPLEVALUES)
                    : default(bool);
            }
        }

        /// <summary>
        /// The property is a group heading.
        /// </summary>
        public bool IsGroup
        {
            get
            {
                GetTypeFlags();
                return propertyTypeFlags.HasValue ?
                    ((propertyTypeFlags.Value &
                        PropertySystemNativeMethods.PROPDESC_TYPE_FLAGS.PDTF_ISGROUP) ==
                        PropertySystemNativeMethods.PROPDESC_TYPE_FLAGS.PDTF_ISGROUP)
                    : default(bool);
            }
        }

        /// <summary>
        /// This property is meant to be viewed by the user.
        /// </summary>
        public bool IsViewable
        {
            get
            {
                GetTypeFlags();
                return propertyTypeFlags.HasValue ?
                    ((propertyTypeFlags.Value &
                        PropertySystemNativeMethods.PROPDESC_TYPE_FLAGS.PDTF_ISVIEWABLE) ==
                        PropertySystemNativeMethods.PROPDESC_TYPE_FLAGS.PDTF_ISVIEWABLE)
                    : default(bool);
            }
        }

        /// <summary>
        /// This property is included in the list of properties that can be queried. 
        /// A queryable property is also viewable. This influences whether the 
        /// property shows up in the query builder UI. 
        /// </summary>
        public bool IsQueryable
        {
            get
            {
                GetTypeFlags();
                return propertyTypeFlags.HasValue ?
                    ((propertyTypeFlags.Value &
                        PropertySystemNativeMethods.PROPDESC_TYPE_FLAGS.PDTF_ISQUERYABLE) ==
                        PropertySystemNativeMethods.PROPDESC_TYPE_FLAGS.PDTF_ISQUERYABLE)
                    : default(bool);
            }
        }

        /// <summary>
        /// This property is owned by the system. 
        /// </summary>
        public bool IsSystemProperty
        {
            get
            {
                GetTypeFlags();
                return propertyTypeFlags.HasValue ?
                    ((propertyTypeFlags.Value &
                        PropertySystemNativeMethods.PROPDESC_TYPE_FLAGS.PDTF_ISSYSTEMPROPERTY) ==
                        PropertySystemNativeMethods.PROPDESC_TYPE_FLAGS.PDTF_ISSYSTEMPROPERTY)
                    : default(bool);
            }
        }

        #endregion

        #region Internal Constructor

        internal PropertyDescription(PropertyKey key)
        {
            this.propertyKey = key;
        }

        #endregion

        #region Internal Methods

        static internal Type VarEnumToSystemType(VarEnum VarEnumType)
        {
            switch (VarEnumType)
            {
                case (VarEnum.VT_EMPTY):
                case (VarEnum.VT_NULL) :
                    
                        return typeof(Object);
                    
                case (VarEnum.VT_UI1) :
                    
                        return typeof(Byte?);
                    
                case (VarEnum.VT_I2):
                    
                        return typeof(Int16?);
                    
                case (VarEnum.VT_UI2):
                    
                        return typeof(UInt16?);
                    
                case (VarEnum.VT_I4):
                    
                        return typeof(Int32?);
                    
                case (VarEnum.VT_UI4):
                    
                        return typeof(UInt32?);
                    
                case (VarEnum.VT_I8):
                    
                        return typeof(Int64?);
                    
                case (VarEnum.VT_UI8):
                    
                        return typeof(UInt64?);
                    
                case (VarEnum.VT_R8):
                    
                        return typeof(Double?);
                    
                case (VarEnum.VT_BOOL):
                    
                        return typeof(Boolean?);
                    
                case (VarEnum.VT_FILETIME):
                    
                        return typeof(DateTime?);
                    
                case (VarEnum.VT_CLSID):
                    
                        return typeof(IntPtr?);
                    
                case (VarEnum.VT_CF):
                    
                        return typeof(IntPtr?);
                    
                case (VarEnum.VT_BLOB):
                    
                        return typeof(Byte[]);
                    
                case (VarEnum.VT_LPWSTR):
                    
                        return typeof(String);
                    
                case (VarEnum.VT_UNKNOWN):
                    
                        return typeof(IntPtr?);
                    
                case (VarEnum.VT_STREAM):
                    
                        return typeof(IStream);
                    
                case (VarEnum.VT_VECTOR|VarEnum.VT_UI1):
                    
                        return typeof(Byte[]);
                    
                case (VarEnum.VT_VECTOR|VarEnum.VT_I2):
                    
                        return typeof(Int16[]);
                    
                case (VarEnum.VT_VECTOR|VarEnum.VT_UI2):
                    
                        return typeof(UInt16[]);
                    
                case (VarEnum.VT_VECTOR|VarEnum.VT_I4):
                    
                        return typeof(Int32[]);
                    
                case (VarEnum.VT_VECTOR|VarEnum.VT_UI4):
                    
                        return typeof(UInt32[]);
                    
                case (VarEnum.VT_VECTOR|VarEnum.VT_I8):
                    
                        return typeof(Int64[]);
                    
                case (VarEnum.VT_VECTOR|VarEnum.VT_UI8):
                    
                        return typeof(UInt64[]);
                    
                case (VarEnum.VT_VECTOR|VarEnum.VT_R8):
                    
                        return typeof(Double[]);
                    
                case (VarEnum.VT_VECTOR|VarEnum.VT_BOOL):
                    
                        return typeof(Boolean[]);
                    
                case (VarEnum.VT_VECTOR|VarEnum.VT_FILETIME):
                    
                        return typeof(DateTime[]);
                    
                case (VarEnum.VT_VECTOR|VarEnum.VT_CLSID):
                    
                        return typeof(IntPtr[]);
                    
                case (VarEnum.VT_VECTOR|VarEnum.VT_CF):
                    
                        return typeof(IntPtr[]);
                    
                case (VarEnum.VT_VECTOR | VarEnum.VT_LPWSTR):
                    
                        return typeof(String[]);
                    
                default:
                    
                        return typeof(Object);
            }
        }

        /// <summary>
        /// Get the native property description COM interface
        /// </summary>
        internal IPropertyDescription NativePropertyDescription
        {
            get
            {
                if (nativePropertyDescription == null)
                {
                    Guid guid = new Guid(ShellIIDGuid.IPropertyDescription);
                    PropertySystemNativeMethods.PSGetPropertyDescription(ref propertyKey, ref guid, out nativePropertyDescription);
                }
                return nativePropertyDescription;
            }
        }

        #endregion

        #region IDisposable Members

        /// <summary>
        /// Release the native objects
        /// </summary>
        public void Dispose(bool disposing)
        {
            if (nativePropertyDescription != null)
            {
                try
                {
                    Marshal.FinalReleaseComObject(nativePropertyDescription);
                }
                finally
                {
                    // The native object
                    nativePropertyDescription = null;

                    // and the managed ones
                    canoninicalName = null;
                    displayName = null;
                    editInvitation = null;
                    displayType = null;
                    aggregationTypes = null;
                    defaultColumWidth = null;
                    propertyTypeFlags = null;
                    valueType = null;
                    propEnumTypeList = null;
                    propertyEnumTypes = null;
                }
                
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
        /// Release the native objects
        /// </summary>
        ~PropertyDescription()
        {
            Dispose(false);
        }

        #endregion
    }
}
