//Copyright (c) Microsoft Corporation.  All rights reserved.

using System;

namespace Microsoft.WindowsAPICodePack.Shell
{
    /// <summary>
    /// These options control the Explorer Browser operational mode.
    /// </summary>
    public class ExplorerBrowserControlOptions
    {
        #region construction
        ExplorerBrowser eb;
        internal ExplorerBrowserControlOptions( ExplorerBrowser eb )
        {
            this.eb = eb;
        }
        #endregion

        #region Flags property
        /// <summary>
        /// The binary flags that are passed to the explorer browser control's GetOptions/SetOptions methods
        /// </summary>
        public ExplorerBrowserControlFlags Flags
        {
            get
            {
                EXPLORER_BROWSER_OPTIONS ebo = new EXPLORER_BROWSER_OPTIONS( );
                if( eb.explorerBrowserControl != null )
                {
                    eb.explorerBrowserControl.GetOptions( out ebo );
                    return (ExplorerBrowserControlFlags)ebo;
                }
                return (ExplorerBrowserControlFlags)ebo;
            }
            set
            {
                EXPLORER_BROWSER_OPTIONS ebo = (EXPLORER_BROWSER_OPTIONS)value;
                if( eb.explorerBrowserControl != null )
                {
                    eb.explorerBrowserControl.SetOptions( ebo );
                }
            }
        }
        #endregion

        #region control flags to properties mapping
        /// <summary>
        /// Do not navigate further than the initial navigation.
        /// </summary>
        public bool NavigateOnce
        {
            get
            {
                return IsFlagSet( ExplorerBrowserControlFlags.NavigateOnce );
            }
            set
            {
                SetFlag( ExplorerBrowserControlFlags.NavigateOnce, value );
            }
        }
        /// <summary>
        /// Use the following standard panes: Commands Module pane, Navigation pane, Details pane, and Preview pane.
        /// </summary>
        public bool ShowFrames
        {
            get
            {
                return IsFlagSet( ExplorerBrowserControlFlags.ShowFrames );
            }
            set
            {
                SetFlag( ExplorerBrowserControlFlags.ShowFrames, value );
            }
        }
        /// <summary>
        /// Always navigate, even if you are attempting to navigate to the current folder.
        /// </summary>
        public bool AlwaysNavigate
        {
            get
            {
                return IsFlagSet( ExplorerBrowserControlFlags.AlwaysNavigate );
            }
            set
            {
                SetFlag( ExplorerBrowserControlFlags.AlwaysNavigate, value );
            }
        }
        /// <summary>
        /// Do not update the travel log.
        /// </summary>
        public bool NoTravelLog
        {
            get
            {
                return IsFlagSet( ExplorerBrowserControlFlags.NoTravelLog );
            }
            set
            {
                SetFlag( ExplorerBrowserControlFlags.NoTravelLog, value );
            }
        }

        private bool IsFlagSet( ExplorerBrowserControlFlags flag )
        {
            return ( Flags & flag ) != 0;
        }

        private void SetFlag( ExplorerBrowserControlFlags flag, bool value )
        {
            if( value )
                Flags |= flag;
            else
                Flags = Flags & ~flag;
        }
        #endregion
    }
}
