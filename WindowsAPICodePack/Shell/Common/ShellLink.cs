//Copyright (c) Microsoft Corporation.  All rights reserved.

using System;
using System.Runtime.InteropServices;

namespace Microsoft.WindowsAPICodePack.Shell
{
    /// <summary>
    /// Represents a link to existing FileSystem or Virtual item.
    /// </summary>
    public class ShellLink : ShellObject
    {
        #region Protected Properties
        
        /// <summary>
        /// Path for this file e.g. c:\Windows\file.txt,
        /// </summary>
        protected string path = null;

        #endregion

        #region Internal Constructors

        internal ShellLink(IShellItem2 shellItem)
        {
            nativeShellItem = shellItem;
        }

        #endregion

        #region Public Properties
        
        /// <summary>
        /// The path for this link
        /// </summary>
        virtual public string Path
        {
            get
            {
                if (path == null && NativeShellItem != null)
                {
                    path = ShellHelper.GetParsingName(NativeShellItem);
                }
                return path;
            }
            protected set
            {
                this.path = value;
            }
        }

        /// <summary>
        /// Gets the location to which this link points to.
        /// </summary>
        public string TargetLocation
        {
            get
            {
                Property<string> prop = this.Properties.GetAnyProperty("System.Link.TargetParsingPath") as Property<string>;
                return (prop != null) ? prop.Value : string.Empty;
            }
        }

        /// <summary>
        /// Gets the ShellObject to which this link points to.
        /// </summary>
        public ShellObject TargetObject
        {
            get
            {
                return ShellObjectFactory.Create(TargetLocation);
            }
        }

        #endregion

    }
}
