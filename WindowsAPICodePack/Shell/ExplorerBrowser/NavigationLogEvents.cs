//Copyright (c) Microsoft Corporation.  All rights reserved.
using System;

namespace Microsoft.WindowsAPICodePack.Shell
{
    /// <summary>
    /// The event argument for NavigationLogChangedEvent
    /// </summary>
    public class NavigationLogEventArgs
    {
        /// <summary>
        /// Indicates CanNavigateForward has changed
        /// </summary>
        public bool CanNavigateForwardChanged;

        /// <summary>
        /// Indicates CanNavigateBackward has changed
        /// </summary>
        public bool CanNavigateBackwardChanged;

        /// <summary>
        /// Indicates the Locations collection has changed
        /// </summary>
        public bool LocationsChanged;
    }

    /// <summary>
    /// This is fired when the navigation log changes
    /// </summary>
    /// <param name="sender">The ExplorerBrowser that this navigation log is attached to.</param>
    /// <param name="args">The changes made to the navigation log</param>
    public delegate void NavigationLogChangedEvent( object sender, NavigationLogEventArgs args );
}