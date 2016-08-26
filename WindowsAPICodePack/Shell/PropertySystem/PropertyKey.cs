//Copyright (c) Microsoft Corporation.  All rights reserved.

using System;
using System.Runtime.InteropServices;

namespace Microsoft.WindowsAPICodePack.Shell
{
    /// <summary>
    /// Defines a unique key for a Shell Property
    /// </summary>
    [StructLayout(LayoutKind.Sequential, Pack = 4)]
    public struct PropertyKey
    {
        #region Private Fields

        private Guid formatId;
        private uint propertyId;

        #endregion

        #region Public Properties
        /// <summary>
        /// A unique GUID for the property
        /// </summary>
        public Guid FormatId
        {
            get
            {
                return formatId;
            }
        }

        /// <summary>
        ///  Property identifier (PID)
        /// </summary>
        public uint PropertyId
        {
            get
            {
                return propertyId;
            }
        }

        #endregion

        #region Public Constructor

        /// <summary>
        /// PropertyKey Constructor
        /// </summary>
        /// <param name="formatId">A unique GUID for the property</param>
        /// <param name="propertyId">Property identifier (PID)</param>
        public PropertyKey(Guid formatId, uint propertyId)
        {
            this.formatId = formatId;
            this.propertyId = propertyId;
        }

        #endregion
    }
}
