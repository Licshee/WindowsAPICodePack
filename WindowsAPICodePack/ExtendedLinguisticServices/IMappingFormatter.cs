// Copyright (c) Microsoft Corporation.  All rights reserved.

using System;
using System.ComponentModel;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading;
using System.Runtime.ConstrainedExecution;
using System.Collections.Generic;

namespace Microsoft.WindowsAPICodePack.ExtendedLinguisticServices
{

    /// <summary>
    /// Defines an interface with which the low-level data contained inside MappingPropertyBag and MappingDataRange
    /// objects can be formatted into .NET objects.
    /// </summary>
    /// <typeparam name="T">The type of the objects into which the low-level data should be converted.</typeparam>
    public interface IMappingFormatter<T>
    {
        /// <summary>
        /// Formats a single MappingDataRange into the type specified by T.
        /// </summary>
        /// <param name="dataRange">The MappingDataRange object to format.</param>
        /// <returns>The formatted object constructed with the data contained inside the MappingDataRange.</returns>
        T Format(MappingDataRange dataRange);
        /// <summary>
        /// Formats all MappingDataRanges contained inside the MappingPropertyBag.
        /// </summary>
        /// <param name="bag">The MappingPropertyBag to format.</param>
        /// <returns>An array of T objects which represent the data contained inside each MappingDataRange of the
        /// provided MappingPropertyBag object.</returns>
        T[] FormatAll(MappingPropertyBag bag);
    }

}
