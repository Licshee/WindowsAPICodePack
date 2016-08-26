//Copyright (c) Microsoft Corporation.  All rights reserved.

using System;
using System.Windows.Forms;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Runtime.InteropServices;
using System.Diagnostics;
using System.Collections.Generic;

namespace Microsoft.WindowsAPICodePack.Shell
{
    /// <summary>
    /// Fires when the SelectedItems collection changes. 
    /// </summary>
    /// <param name="sender"></param>
    /// <param name="e"></param>
    public delegate void ExplorerBrowserSelectionChangedEvent( object sender, EventArgs e );
    
    /// <summary>
    /// Fires when the Items colection changes. 
    /// </summary>
    /// <param name="sender"></param>
    /// <param name="e"></param>
    public delegate void ExplorerBrowserItemsChangedEvent( object sender, EventArgs e ) ;
    
    /// <summary>
    /// Fires when a navigation has been initiated, but is not yet complete.
    /// </summary>
    /// <param name="sender"></param>
    /// <param name="args"></param>
    public delegate void ExplorerBrowserNavigationPendingEvent( object sender, NavigationPendingArgs args );
    
    /// <summary>
    /// Fires when a navigation has been 'completed': no NavigationPending listener 
    /// has cancelled, and the ExplorerBorwser has created a new view. The view 
    /// will be populated with new items asynchronously, and ItemsChanged will be 
    /// fired to reflect this some time later.
    /// </summary>
    /// <param name="sender"></param>
    /// <param name="args"></param>
    public delegate void ExplorerBrowserNavigationCompleteEvent( object sender, NavigationCompleteArgs args );
    
    /// <summary>
    /// Fires when either a NavigationPending listener cancels the navigation, or
    /// if the operating system determines that navigation is not possible.
    /// </summary>
    /// <param name="sender"></param>
    /// <param name="args"></param>
    public delegate void ExplorerBrowserNavigationFailedEvent( object sender, NavigationFailedArgs args );

    /// <summary>
    /// Event argument for The NavigationPending event
    /// </summary>
    public class NavigationPendingArgs
    {
        /// <summary>
        /// The location being navigated to
        /// </summary>
        public ShellObject PendingLocation;
        
        /// <summary>
        /// Set to 'True' to cancel the navigation.
        /// </summary>
        public bool Cancel;
    }

    /// <summary>
    /// Event argument for The NavigationComplete event
    /// </summary>
    public class NavigationCompleteArgs
    {
        /// <summary>
        /// The new location of the explorer browser
        /// </summary>
        public ShellObject NewLocation;
    }

    /// <summary>
    /// Event argument for the NavigatinoFailed event
    /// </summary>
    public class NavigationFailedArgs
    {
        /// <summary>
        /// The location the the browser would have navigated to.
        /// </summary>
        public ShellObject FailedLocation;
    }
}