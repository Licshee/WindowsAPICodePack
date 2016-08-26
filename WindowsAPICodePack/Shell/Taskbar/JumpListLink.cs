//Copyright (c) Microsoft Corporation.  All rights reserved.

using System;
using System.Runtime.InteropServices;

namespace Microsoft.WindowsAPICodePack.Shell.Taskbar
{
    /// <summary>
    /// Represents a jump list link object.
    /// </summary>
    public class JumpListLink : IJumpListTask, IJumpListItem
    {
        /// <summary>
        /// Gets or sets the link's title
        /// </summary>
        public string Title { get; set; }

        /// <summary>
        /// Gets or sets the link's path
        /// </summary>
        public string Path { get; set; }

        /// <summary>
        /// Gets or sets the location of the link's icon.
        /// </summary>
        public string IconLocation { get; set; }

        /// <summary>
        /// Gets or sets the index of the link's icon in the
        /// specified icon't location.
        /// </summary>
        public int IconIndex { get; set; }

        /// <summary>
        /// Gets or sets the object's arguments (passed to the command line).
        /// </summary>
        public string Arguments { get; set; }

        /// <summary>
        /// Gets or sets the object's working directory.
        /// </summary>
        public string WorkingDirectory { get; set; }

        /// <summary>
        /// Gets or sets the show command of the lauched application.
        /// </summary>
        public WindowShowCommand ShowCommand { get; set; }

        /// <summary>
        /// Gets an IShellLinkW representation of this object
        /// </summary>
        /// <returns>An IShellLinkW object</returns>
        public object GetShellRepresentation()
        {
            IShellLinkW shellLink = (IShellLinkW)new CShellLink();

            IPropertyStore propertyStore = (IPropertyStore)shellLink;
            PropVariant propVariant = new PropVariant();

            shellLink.SetPath(Path);

            if (!String.IsNullOrEmpty(IconLocation))
                shellLink.SetIconLocation(IconLocation, IconIndex);

            if (!String.IsNullOrEmpty(Arguments))
                shellLink.SetArguments(Arguments);

            if (!String.IsNullOrEmpty(WorkingDirectory))
                shellLink.SetWorkingDirectory(WorkingDirectory);

            shellLink.SetShowCmd((uint)ShowCommand);

            propVariant.SetValue(Title);
            propertyStore.SetValue(ref PropertyKey.PKEY_Title, ref propVariant);
            propVariant.Clear();

            propertyStore.Commit();

            return shellLink;
        }
    }
}
