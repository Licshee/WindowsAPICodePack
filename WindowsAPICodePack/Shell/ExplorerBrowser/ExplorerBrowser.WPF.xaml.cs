//Copyright (c) Microsoft Corporation.  All rights reserved.
using System;
using System.Collections.Generic;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Windows.Forms.Integration;
using Microsoft.WindowsAPICodePack.Shell;

namespace Microsoft.WindowsAPICodePack.Shell.Presentation
{
    /// <summary>
    /// Interaction logic for ExplorerBrowser.xaml
    /// </summary>
    public partial class ExplorerBrowser : UserControl
    {
        internal static Microsoft.WindowsAPICodePack.Shell.ExplorerBrowser eb = null;

        /// <summary>
        /// Hosts the ExplorerBrowser WinForms wrapper in this control
        /// </summary>
        public ExplorerBrowser( )
        {
            InitializeComponent( );

            Loaded += new RoutedEventHandler( ExplorerBrowser_Loaded );
        }

        /// <summary>
        /// Navigates to the specified shell object (a container or a file container, i.e. ZIP or CAB file )
        /// </summary>
        /// <param name="shellObject"></param>
        /// <returns></returns>
        public bool Navigate( ShellObject shellObject )
        {
            return eb.Navigate( shellObject );
        }

        /// <summary>
        /// The items in the ExplorerBrowser window
        /// </summary>
        public ShellObjectCollection Items
        {
            get
            {
                return eb.Items;
            }
        }

        /// <summary>
        /// The selected items int the ExplorerBrowser window
        /// </summary>
        public ShellObjectCollection SelectedItems
        {
            get
            {
                return eb.SelectedItems;
            }
        }

        /// <summary>
        /// To avoid the 'Dispatcher processing has been suspended' InvalidOperationException on Win7,
        /// the ExplorerBorwser native control is initialized after this control is fully loaded.
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        void ExplorerBrowser_Loaded( object sender, RoutedEventArgs e )
        {
            if( System.ComponentModel.DesignerProperties.GetIsInDesignMode( this ) == false )
            {
                ExplorerBrowser.eb = new Microsoft.WindowsAPICodePack.Shell.ExplorerBrowser( );

                WindowsFormsHost host = new WindowsFormsHost( );
                host.Child = ExplorerBrowser.eb;
                this.root.Children.Clear( );
                this.root.Children.Add( host );
            }
        }

        /// <summary>
        /// The viewing mode of the Explorer Browser
        /// </summary>
        public ExplorerBrowserViewMode ViewMode
        {
            get
            {
                if( ExplorerBrowser.eb == null )
                    return ExplorerBrowserViewMode.Auto;
                else
                    return ExplorerBrowser.eb.ContentOptions.ViewMode;
            }

            set
            {
                if( ExplorerBrowser.eb != null )
                    ExplorerBrowser.eb.ContentOptions.ViewMode = value;
            }
        }

        internal static DependencyProperty ViewModeProperty =
                    DependencyProperty.Register(
                        "ViewMode", typeof( ExplorerBrowserViewMode ),
                        typeof( ExplorerBrowser ),
                        new PropertyMetadata( ExplorerBrowserViewMode.Auto, OnViewModeChanged ) );

        private static void OnViewModeChanged( DependencyObject d, DependencyPropertyChangedEventArgs e )
        {
            if( ExplorerBrowser.eb != null )
                ExplorerBrowser.eb.ContentOptions.ViewMode = (ExplorerBrowserViewMode)e.NewValue;
        }


        /// <summary>
        /// The view should be left-aligned. 
        /// </summary>
        public bool AlignLeft
        {
            get
            {
                if( ExplorerBrowser.eb == null )
                    return false;
                else
                    return ExplorerBrowser.eb.ContentOptions.AlignLeft;
            }

            set
            {
                if( ExplorerBrowser.eb != null )
                    ExplorerBrowser.eb.ContentOptions.AlignLeft = value;
            }
        }

        internal static DependencyProperty AlignLeftProperty =
                    DependencyProperty.Register(
                        "AlignLeft", typeof( bool ),
                        typeof( ExplorerBrowser ),
                        new PropertyMetadata( false, OnAlignLeftChanged ) );

        private static void OnAlignLeftChanged( DependencyObject d, DependencyPropertyChangedEventArgs e )
        {
            if( ExplorerBrowser.eb != null )
                ExplorerBrowser.eb.ContentOptions.AlignLeft = (bool)e.NewValue;
        }


        /// <summary>
        /// Automatically arrange the elements in the view. 
        /// </summary>
        public bool AutoArrange
        {
            get
            {
                if( ExplorerBrowser.eb == null )
                    return false;
                else
                    return ExplorerBrowser.eb.ContentOptions.AutoArrange;
            }

            set
            {
                if( ExplorerBrowser.eb != null )
                    ExplorerBrowser.eb.ContentOptions.AutoArrange = value;
            }
        }

        internal static DependencyProperty AutoArrangeProperty =
                    DependencyProperty.Register(
                        "AutoArrange", typeof( bool ),
                        typeof( ExplorerBrowser ),
                        new PropertyMetadata( false, OnAutoArrangeChanged ) );

        private static void OnAutoArrangeChanged( DependencyObject d, DependencyPropertyChangedEventArgs e )
        {
            if( ExplorerBrowser.eb != null )
                ExplorerBrowser.eb.ContentOptions.AutoArrange = (bool)e.NewValue;
        }

        /// <summary>
        /// Turns on check mode for the view
        /// </summary>
        public bool CheckSelect
        {
            get
            {
                if( ExplorerBrowser.eb == null )
                    return false;
                else
                    return ExplorerBrowser.eb.ContentOptions.CheckSelect;
            }

            set
            {
                if( ExplorerBrowser.eb != null )
                    ExplorerBrowser.eb.ContentOptions.CheckSelect = value;
            }
        }

        internal static DependencyProperty CheckSelectProperty =
                    DependencyProperty.Register(
                        "CheckSelect", typeof( bool ),
                        typeof( ExplorerBrowser ),
                        new PropertyMetadata( false, OnCheckSelectChanged ) );

        private static void OnCheckSelectChanged( DependencyObject d, DependencyPropertyChangedEventArgs e )
        {
            if( ExplorerBrowser.eb != null )
                ExplorerBrowser.eb.ContentOptions.CheckSelect = (bool)e.NewValue;
        }

        /// <summary>
        /// When the view is in "tile view mode" the layout of a single item should be extended to the width of the view.
        /// </summary>
        public bool ExtendedTiles
        {
            get
            {
                if( ExplorerBrowser.eb == null )
                    return false;
                else
                    return ExplorerBrowser.eb.ContentOptions.ExtendedTiles;
            }

            set
            {
                if( ExplorerBrowser.eb != null )
                    ExplorerBrowser.eb.ContentOptions.ExtendedTiles = value;
            }
        }

        internal static DependencyProperty ExtendedTilesProperty =
                    DependencyProperty.Register(
                        "ExtendedTiles", typeof( bool ),
                        typeof( ExplorerBrowser ),
                        new PropertyMetadata( false, OnExtendedTilesChanged ) );

        private static void OnExtendedTilesChanged( DependencyObject d, DependencyPropertyChangedEventArgs e )
        {
            if( ExplorerBrowser.eb != null )
                ExplorerBrowser.eb.ContentOptions.ExtendedTiles = (bool)e.NewValue;
        }

        /// <summary>
        /// When an item is selected, the item and all its sub-items are highlighted.
        /// </summary>
        public bool FullRowSelect
        {
            get
            {
                if( ExplorerBrowser.eb == null )
                    return false;
                else
                    return ExplorerBrowser.eb.ContentOptions.FullRowSelect;
            }

            set
            {
                if( ExplorerBrowser.eb != null )
                    ExplorerBrowser.eb.ContentOptions.FullRowSelect = value;
            }
        }

        internal static DependencyProperty FullRowSelectProperty =
                    DependencyProperty.Register(
                        "FullRowSelect", typeof( bool ),
                        typeof( ExplorerBrowser ),
                        new PropertyMetadata( false, OnFullRowSelectChanged ) );

        private static void OnFullRowSelectChanged( DependencyObject d, DependencyPropertyChangedEventArgs e )
        {
            if( ExplorerBrowser.eb != null )
                ExplorerBrowser.eb.ContentOptions.FullRowSelect = (bool)e.NewValue;
        }

        /// <summary>
        /// The view should not display file names
        /// </summary>
        public bool HideFileNames
        {
            get
            {
                if( ExplorerBrowser.eb == null )
                    return false;
                else
                    return ExplorerBrowser.eb.ContentOptions.HideFileNames;
            }

            set
            {
                if( ExplorerBrowser.eb != null )
                    ExplorerBrowser.eb.ContentOptions.HideFileNames = value;
            }
        }

        internal static DependencyProperty HideFileNamesProperty =
                    DependencyProperty.Register(
                        "HideFileNames", typeof( bool ),
                        typeof( ExplorerBrowser ),
                        new PropertyMetadata( false, OnHideFileNamesChanged ) );

        private static void OnHideFileNamesChanged( DependencyObject d, DependencyPropertyChangedEventArgs e )
        {
            if( ExplorerBrowser.eb != null )
                ExplorerBrowser.eb.ContentOptions.HideFileNames = (bool)e.NewValue;
        }

        /// <summary>
        /// The view should not save view state in the browser.
        /// </summary>
        public bool NoBrowserViewState
        {
            get
            {
                if( ExplorerBrowser.eb == null )
                    return false;
                else
                    return ExplorerBrowser.eb.ContentOptions.NoBrowserViewState;
            }

            set
            {
                if( ExplorerBrowser.eb != null )
                    ExplorerBrowser.eb.ContentOptions.NoBrowserViewState = value;
            }
        }

        internal static DependencyProperty NoBrowserViewStateProperty =
                    DependencyProperty.Register(
                        "NoBrowserViewState", typeof( bool ),
                        typeof( ExplorerBrowser ),
                        new PropertyMetadata( false, OnNoBrowserViewStateChanged ) );

        private static void OnNoBrowserViewStateChanged( DependencyObject d, DependencyPropertyChangedEventArgs e )
        {
            if( ExplorerBrowser.eb != null )
                ExplorerBrowser.eb.ContentOptions.NoBrowserViewState = (bool)e.NewValue;
        }

        /// <summary>
        /// Do not display a column header in the view in any view mode.
        /// </summary>
        public bool NoColumnHeader
        {
            get
            {
                if( ExplorerBrowser.eb == null )
                    return false;
                else
                    return ExplorerBrowser.eb.ContentOptions.NoColumnHeader;
            }

            set
            {
                if( ExplorerBrowser.eb != null )
                    ExplorerBrowser.eb.ContentOptions.NoColumnHeader = value;
            }
        }

        internal static DependencyProperty NoColumnHeaderProperty =
                    DependencyProperty.Register(
                        "NoColumnHeader", typeof( bool ),
                        typeof( ExplorerBrowser ),
                        new PropertyMetadata( false, OnNoColumnHeaderChanged ) );

        private static void OnNoColumnHeaderChanged( DependencyObject d, DependencyPropertyChangedEventArgs e )
        {
            if( ExplorerBrowser.eb != null )
                ExplorerBrowser.eb.ContentOptions.NoColumnHeader = (bool)e.NewValue;
        }

        /// <summary>
        /// Only show the column header in details view mode.
        /// </summary>
        public bool NoHeaderInAllViews
        {
            get
            {
                if( ExplorerBrowser.eb == null )
                    return false;
                else
                    return ExplorerBrowser.eb.ContentOptions.NoHeaderInAllViews;
            }

            set
            {
                if( ExplorerBrowser.eb != null )
                    ExplorerBrowser.eb.ContentOptions.NoHeaderInAllViews = value;
            }
        }

        internal static DependencyProperty NoHeaderInAllViewsProperty =
                    DependencyProperty.Register(
                        "NoHeaderInAllViews", typeof( bool ),
                        typeof( ExplorerBrowser ),
                        new PropertyMetadata( false, OnNoHeaderInAllViewsChanged ) );

        private static void OnNoHeaderInAllViewsChanged( DependencyObject d, DependencyPropertyChangedEventArgs e )
        {
            if( ExplorerBrowser.eb != null )
                ExplorerBrowser.eb.ContentOptions.NoHeaderInAllViews = (bool)e.NewValue;
        }

        /// <summary>
        /// The view should not display icons. 
        /// </summary>
        public bool NoIcons
        {
            get
            {
                if( ExplorerBrowser.eb == null )
                    return false;
                else
                    return ExplorerBrowser.eb.ContentOptions.NoIcons;
            }

            set
            {
                if( ExplorerBrowser.eb != null )
                    ExplorerBrowser.eb.ContentOptions.NoIcons = value;
            }
        }

        internal static DependencyProperty NoIconsProperty =
                    DependencyProperty.Register(
                        "NoIcons", typeof( bool ),
                        typeof( ExplorerBrowser ),
                        new PropertyMetadata( false, OnNoIconsChanged ) );

        private static void OnNoIconsChanged( DependencyObject d, DependencyPropertyChangedEventArgs e )
        {
            if( ExplorerBrowser.eb != null )
                ExplorerBrowser.eb.ContentOptions.NoIcons = (bool)e.NewValue;
        }

        /// <summary>
        /// Do not show subfolders. 
        /// </summary>
        public bool NoSubFolders
        {
            get
            {
                if( ExplorerBrowser.eb == null )
                    return false;
                else
                    return ExplorerBrowser.eb.ContentOptions.NoSubFolders;
            }

            set
            {
                if( ExplorerBrowser.eb != null )
                    ExplorerBrowser.eb.ContentOptions.NoSubFolders = value;
            }
        }

        internal static DependencyProperty NoSubFoldersProperty =
                    DependencyProperty.Register(
                        "NoSubFolders", typeof( bool ),
                        typeof( ExplorerBrowser ),
                        new PropertyMetadata( false, OnNoSubFoldersChanged ) );

        private static void OnNoSubFoldersChanged( DependencyObject d, DependencyPropertyChangedEventArgs e )
        {
            if( ExplorerBrowser.eb != null )
                ExplorerBrowser.eb.ContentOptions.NoSubFolders = (bool)e.NewValue;
        }

        /// <summary>
        /// Navigate with a single click
        /// </summary>
        public bool SingleClickActivate
        {
            get
            {
                if( ExplorerBrowser.eb == null )
                    return false;
                else
                    return ExplorerBrowser.eb.ContentOptions.SingleClickActivate;
            }

            set
            {
                if( ExplorerBrowser.eb != null )
                    ExplorerBrowser.eb.ContentOptions.SingleClickActivate = value;
            }
        }

        internal static DependencyProperty SingleClickActivateProperty =
                    DependencyProperty.Register(
                        "SingleClickActivate", typeof( bool ),
                        typeof( ExplorerBrowser ),
                        new PropertyMetadata( false, OnSingleClickActivateChanged ) );

        private static void OnSingleClickActivateChanged( DependencyObject d, DependencyPropertyChangedEventArgs e )
        {
            if( ExplorerBrowser.eb != null )
                ExplorerBrowser.eb.ContentOptions.SingleClickActivate = (bool)e.NewValue;
        }

        /// <summary>
        /// Do not allow more than a single item to be selected.
        /// </summary>
        public bool SingleSelection
        {
            get
            {
                if( ExplorerBrowser.eb == null )
                    return false;
                else
                    return ExplorerBrowser.eb.ContentOptions.SingleSelection;
            }

            set
            {
                if( ExplorerBrowser.eb != null )
                    ExplorerBrowser.eb.ContentOptions.SingleSelection = value;
            }
        }

        internal static DependencyProperty SingleSelectionProperty =
                    DependencyProperty.Register(
                        "SingleSelection", typeof( bool ),
                        typeof( ExplorerBrowser ),
                        new PropertyMetadata( false, OnSingleSelectionChanged ) );

        private static void OnSingleSelectionChanged( DependencyObject d, DependencyPropertyChangedEventArgs e )
        {
            if( ExplorerBrowser.eb != null )
                ExplorerBrowser.eb.ContentOptions.SingleSelection = (bool)e.NewValue;
        }

        /// <summary>
        /// Always navigate, even if you are attempting to navigate to the current folder.
        /// </summary>
        public bool AlwaysNavigate
        {
            get
            {
                if( ExplorerBrowser.eb == null )
                    return false;
                else
                    return ExplorerBrowser.eb.ControlOptions.AlwaysNavigate;
            }

            set
            {
                if( ExplorerBrowser.eb != null )
                    ExplorerBrowser.eb.ControlOptions.AlwaysNavigate = value;
            }
        }

        internal static DependencyProperty AlwaysNavigateProperty =
                    DependencyProperty.Register(
                        "AlwaysNavigate", typeof( bool ),
                        typeof( ExplorerBrowser ),
                        new PropertyMetadata( false, OnAlwaysNavigateChanged ) );

        private static void OnAlwaysNavigateChanged( DependencyObject d, DependencyPropertyChangedEventArgs e )
        {
            if( ExplorerBrowser.eb != null )
                ExplorerBrowser.eb.ControlOptions.AlwaysNavigate = (bool)e.NewValue;
        }

        /// <summary>
        /// Do not navigate further than the initial navigation.
        /// </summary>
        public bool NavigateOnce
        {
            get
            {
                if( ExplorerBrowser.eb == null )
                    return false;
                else
                    return ExplorerBrowser.eb.ControlOptions.NavigateOnce;
            }

            set
            {
                if( ExplorerBrowser.eb != null )
                    ExplorerBrowser.eb.ControlOptions.NavigateOnce = value;
            }
        }

        internal static DependencyProperty NavigateOnceProperty =
                    DependencyProperty.Register(
                        "NavigateOnce", typeof( bool ),
                        typeof( ExplorerBrowser ),
                        new PropertyMetadata( false, OnNavigateOnceChanged ) );

        private static void OnNavigateOnceChanged( DependencyObject d, DependencyPropertyChangedEventArgs e )
        {
            if( ExplorerBrowser.eb != null )
                ExplorerBrowser.eb.ControlOptions.NavigateOnce = (bool)e.NewValue;
        }

        /// <summary>
        /// Do not update the travel log.
        /// </summary>
        public bool NoTravelLog
        {
            get
            {
                if( ExplorerBrowser.eb == null )
                    return false;
                else
                    return ExplorerBrowser.eb.ControlOptions.NoTravelLog;
            }

            set
            {
                if( ExplorerBrowser.eb != null )
                    ExplorerBrowser.eb.ControlOptions.NoTravelLog = value;
            }
        }

        internal static DependencyProperty NoTravelLogProperty =
                    DependencyProperty.Register(
                        "NoTravelLog", typeof( bool ),
                        typeof( ExplorerBrowser ),
                        new PropertyMetadata( false, OnNoTravelLogChanged ) );

        private static void OnNoTravelLogChanged( DependencyObject d, DependencyPropertyChangedEventArgs e )
        {
            if( ExplorerBrowser.eb != null )
                ExplorerBrowser.eb.ControlOptions.NoTravelLog = (bool)e.NewValue;
        }

        /// <summary>
        /// Use the following standard panes: Commands Module pane, Navigation pane, Details pane, and Preview pane.
        /// </summary>
        public bool ShowFrames
        {
            get
            {
                if( ExplorerBrowser.eb == null )
                    return false;
                else
                    return ExplorerBrowser.eb.ControlOptions.ShowFrames;
            }

            set
            {
                if( ExplorerBrowser.eb != null )
                    ExplorerBrowser.eb.ControlOptions.ShowFrames = value;
            }
        }

        internal static DependencyProperty ShowFramesProperty =
                    DependencyProperty.Register(
                        "ShowFrames", typeof( bool ),
                        typeof( ExplorerBrowser ),
                        new PropertyMetadata( false, OnShowFramesChanged ) );

        private static void OnShowFramesChanged( DependencyObject d, DependencyPropertyChangedEventArgs e )
        {
            if( ExplorerBrowser.eb != null )
                ExplorerBrowser.eb.ControlOptions.ShowFrames = (bool)e.NewValue;
        }
    }
}
