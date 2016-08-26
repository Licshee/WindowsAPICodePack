//Copyright (c) Microsoft Corporation.  All rights reserved.

using System;
using System.Runtime.InteropServices;

namespace Microsoft.WindowsAPICodePack.Shell.Taskbar
{
    /// <summary>
    /// Represents a separator in the user task list. This control
    /// can only be used in a user task list.
    /// </summary>
    public class JumpListSeparator : IJumpListTask
    {
        /// <summary>
        /// Gets an IShellLinkW representation of this object
        /// </summary>
        /// <returns>An IShellLinkW object</returns>
        public object GetShellRepresentation()
        {
            IShellLinkW shellLink = (IShellLinkW)new CShellLink();

            IPropertyStore propertyStore = (IPropertyStore)shellLink;
            PropVariant propVariant = new PropVariant();

            propVariant.SetValue(true);
            propertyStore.SetValue(ref PropertyKey.PKEY_AppUserModel_IsDestListSeparator, ref propVariant);
            propVariant.Clear();

            propertyStore.Commit();

            return shellLink;
        }
    }
}
