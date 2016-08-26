//Copyright (c) Microsoft Corporation.  All rights reserved.

using System;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using Microsoft.WindowsAPICodePack;
using System.Runtime.InteropServices.ComTypes;

namespace Microsoft.WindowsAPICodePack.Shell
{
    class PropertySystemNativeMethods
    {
        #region Property Definitions

        internal enum PROPDESC_CONDITION_TYPE
        {
            PDCOT_NONE,
            PDCOT_STRING,
            PDCOT_SIZE,
            PDCOT_DATETIME,
            PDCOT_BOOLEAN,
            PDCOT_NUMBER
        }

        internal enum PROPDESC_GROUPING_RANGE
        {
            PDGR_DISCRETE,
            PDGR_ALPHANUMERIC,
            PDGR_SIZE,
            PDGR_DYNAMIC,
            PDGR_DATE,
            PDGR_PERCENT,
            PDGR_ENUMERATED
        }

        internal enum PROPDESC_RELATIVEDESCRIPTION_TYPE
        {
            PDRDT_GENERAL,
            PDRDT_DATE,
            PDRDT_SIZE,
            PDRDT_COUNT,
            PDRDT_REVISION,
            PDRDT_LENGTH,
            PDRDT_DURATION,
            PDRDT_SPEED,
            PDRDT_RATE,
            PDRDT_RATING,
            PDRDT_PRIORITY
        }

        internal enum PROPDESC_SORTDESCRIPTION
        {
            PDSD_GENERAL,
            PDSD_A_Z,
            PDSD_LOWEST_HIGHEST,
            PDSD_SMALLEST_BIGGEST,
            PDSD_OLDEST_NEWEST
        }

        [Flags]
        internal enum PROPDESC_TYPE_FLAGS
        {
            PDTF_CANBEPURGED = 0x200,
            PDTF_CANGROUPBY = 8,
            PDTF_CANSTACKBY = 0x10,
            PDTF_DEFAULT = 0,
            PDTF_INCLUDEINFULLTEXTQUERY = 0x40,
            PDTF_ISGROUP = 4,
            PDTF_ISINNATE = 2,
            PDTF_ISQUERYABLE = 0x100,
            PDTF_ISSYSTEMPROPERTY = -2147483648,
            PDTF_ISTREEPROPERTY = 0x20,
            PDTF_ISVIEWABLE = 0x80,
            PDTF_MASK_ALL = -2147481601,
            PDTF_MULTIPLEVALUES = 1,
            PDTF_SEARCHRAWVALUE = 0x400
        }

        internal enum PROPDESC_VIEW_FLAGS
        {
            PDVF_BEGINNEWGROUP = 4,
            PDVF_CANWRAP = 0x1000,
            PDVF_CENTERALIGN = 1,
            PDVF_DEFAULT = 0,
            PDVF_FILLAREA = 8,
            PDVF_HIDDEN = 0x800,
            PDVF_HIDELABEL = 0x200,
            PDVF_MASK_ALL = 0x1fff,
            PDVF_RIGHTALIGN = 2,
            PDVF_SHOWBYDEFAULT = 0x40,
            PDVF_SHOWINPRIMARYLIST = 0x80,
            PDVF_SHOWINSECONDARYLIST = 0x100,
            PDVF_SHOWONLYIFPRESENT = 0x20,
            PDVF_SORTDESCENDING = 0x10,
            PDVF_USESMARTDATETIMEFORMAT = 0x400
        }

        internal enum CONDITION_OPERATION
        {
            COP_IMPLICIT,
            COP_EQUAL,
            COP_NOTEQUAL,
            COP_LESSTHAN,
            COP_GREATERTHAN,
            COP_LESSTHANOREQUAL,
            COP_GREATERTHANOREQUAL,
            COP_VALUE_STARTSWITH,
            COP_VALUE_ENDSWITH,
            COP_VALUE_CONTAINS,
            COP_VALUE_NOTCONTAINS,
            COP_DOSWILDCARDS,
            COP_WORD_EQUAL,
            COP_WORD_STARTSWITH,
            COP_APPLICATION_SPECIFIC
        }

        #endregion

        #region Property System Helpers

        [DllImport("propsys.dll", CharSet = CharSet.Unicode, SetLastError = true)]
        internal static extern int PSGetNameFromPropertyKey(
            ref PropertyKey propkey,
            [Out, MarshalAs(UnmanagedType.LPWStr)] out string ppszCanonicalName
        );

        [DllImport("propsys.dll", CharSet = CharSet.Unicode, SetLastError = true)]
        internal static extern int PSGetPropertyDescription(
            ref PropertyKey propkey,
            ref Guid riid,
            [Out, MarshalAs(UnmanagedType.Interface)] out IPropertyDescription ppv
        );

        [DllImport("propsys.dll", CharSet = CharSet.Unicode, SetLastError = true)]
        internal static extern int PSGetPropertyKeyFromName(
            [In, MarshalAs(UnmanagedType.LPWStr)] string pszCanonicalName,
            out PropertyKey propkey
        );

        #endregion
    }
}
