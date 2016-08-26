//Copyright (c) Microsoft Corporation.  All rights reserved.

using System;

namespace Microsoft.WindowsAPICodePack.Shell
{
    #region Property System Enumerations

    /// <summary>
    /// Indicates the format of a preoperty string.
    /// Typically use one, or a bitwise combination of 
    /// these flags to specify format. Some flags are mutually exclusive, 
    /// for example ShortTime | LongTime | HideTime, is not allowed.
    /// </summary>
    [Flags]
    public enum PropertyDescriptionFormat
    {
        /// <summary>
        /// Use the format settings specified in the property's .propdesc file.
        /// </summary>
        Default = 0,

        /// <summary>
        /// Precede the value with the property's display name. 
        /// If the hideLabelPrefix attribute of the labelInfo element 
        /// in the property's .propinfo file is set to true, then this flag is ignored.
        /// </summary>
        PrefixName = 0x1,

        /// <summary>
        /// Treat the string as a file name.
        /// </summary>
        FileName = 0x2,

        /// <summary>
        /// Byte sizes are always displayed in kilobytes (KB), regardless of size. 
        /// This allows for the clean alignment of the values in the column. 
        /// This flag only applies to properties of Integer types.
        /// </summary>
        AlwaysKB = 0x4,

        /// <summary>
        /// Reserved.
        /// </summary>
        RightToLeft = 0x8,

        /// <summary>
        /// Display time as 'hh:mm am/pm'.
        /// </summary>
        ShortTime = 0x10,

        /// <summary>
        /// Display time as 'hh:mm:ss am/pm'.
        /// </summary>
        LongTime = 0x20,

        /// <summary>
        /// Hide the time portion of datetime.
        /// </summary>
        HideTime = 64,

        /// <summary>
        /// Display date as 'MM/DD/YY'. For example, '3/21/04'.
        /// </summary>
        ShortDate = 0x80,

        /// <summary>
        /// Display date as 'DayOfWeek Month day, year'. 
        /// For example, 'Monday, March 21, 2004'.
        /// </summary>
        LongDate = 0x100,

        /// <summary>
        /// Hide the date portion of datetime.
        /// </summary>
        HideDate = 0x200,

        /// <summary>
        /// Use friendly date descriptions. For example, "Yesterday".
        /// </summary>
        RelativeDate = 0x400,

        /// <summary>
        /// Return the invitation text if formatting failed or the value was empty. 
        /// Invitation text is text displayed in a text box as a cue for the user, 
        /// such as 'Enter your name.' Formatting can fail if the data entered 
        /// is not of an expected type, such as putting alpha characters in 
        /// a phone number field.
        /// </summary>
        UseEditInvitation = 0x800,

        /// <summary>
        /// This flag requires UseEditInvitation to also be specified. When the 
        /// formatting flags are ReadOnly | UseEditInvitation and the algorithm 
        /// would have shown invitation text, a string is returned that indicates 
        /// the value is "Unknown" instead of the invitation text.
        /// </summary>
        ReadOnly = 0x1000,

        /// <summary>
        /// Do not detect reading order automatically. Useful when converting 
        /// to ANSI to omit the Unicode reading order characters.
        /// </summary>
        NoAutoReadingOrder = 0x2000,

        /// <summary>
        /// Smart display of DateTime values
        /// </summary>
        SmartDateTime = 0x4000
    }

    /// <summary>
    /// Display Types for a Property
    /// </summary>
    public enum PropertyDisplayType
    {
        /// <summary>
        /// String Display, this is the default if the property doesn't have one
        /// </summary>
        String = 0,

        /// <summary>
        /// Number Display
        /// </summary>
        Number = 1,

        /// <summary>
        /// Boolean Display
        /// </summary>
        Boolean = 2,

        /// <summary>
        /// DateTime Display
        /// </summary>
        DateTime = 3,

        /// <summary>
        /// Enumerated Display
        /// </summary>
        Enumerated = 4
    }

    /// <summary>
    /// Property Aggregation Type
    /// </summary>
    public enum PropertyAggregationType
    {
        /// <summary>
        /// Display the string "Multiple Values".
        /// </summary>
        Default = 0,

        /// <summary>
        /// Display the first value in the selection.
        /// </summary>
        First = 1,

        /// <summary>
        /// Display the sum of the selected values. This flag is never returned 
        /// for data types VT_LPWSTR, VT_BOOL, and VT_FILETIME.
        /// </summary>
        Sum = 2,

        /// <summary>
        /// Display the numerical average of the selected values. This flag 
        /// is never returned for data types VT_LPWSTR, VT_BOOL, and VT_FILETIME.
        /// </summary>
        Average = 3,

        /// <summary>
        /// Display the date range of the selected values. This flag is only 
        /// returned for values of the VT_FILETIME data type.
        /// </summary>
        DateRange = 4,

        /// <summary>
        /// Display a concatenated string of all the values. The order of 
        /// individual values in the string is undefined. The concatenated 
        /// string omits duplicate values; if a value occurs more than once, 
        /// it only appears a single time in the concatenated string.
        /// </summary>
        Union = 5,

        /// <summary>
        /// Display the highest of the selected values.
        /// </summary>
        Max = 6,

        /// <summary>
        /// Display the lowest of the selected values.
        /// </summary>
        Min = 7
    }

    /// <summary>
    /// Property Enumeration Types
    /// </summary>
    public enum PropEnumType
    {
        /// <summary>
        /// Use DisplayText and either RangeMinValue or RangeSetValue.
        /// </summary>
        DiscreteValue = 0,

        /// <summary>
        /// Use DisplayText and either RangeMinValue or RangeSetValue
        /// </summary>
        RangedValue = 1,

        /// <summary>
        /// Use DisplayText
        /// </summary>
        DefaultValue = 2,

        /// <summary>
        /// Use Value or RangeMinValue
        /// </summary>
        EndRange = 3
    };

    #endregion
}
