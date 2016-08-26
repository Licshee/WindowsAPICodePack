//Copyright (c) Microsoft Corporation.  All rights reserved.

using System;
using System.Collections.Generic;
using System.Windows;
using System.Windows.Controls;

using Microsoft.WindowsAPICodePack.Shell;

namespace Microsoft.WindowsAPICodePack.Samples
{
    /// <summary>
    /// Interaction logic for Window1.xaml
    /// </summary>
    public partial class ExplorerBrowserTestWindow : Window
    {
        System.Windows.Threading.DispatcherTimer timer;

        public ExplorerBrowserTestWindow( )
        {
            InitializeComponent( );

            // use timer as workaround for Items and SelectedItems not being observable
            timer = new System.Windows.Threading.DispatcherTimer( );
            timer.Interval = new TimeSpan( 100 * 10000 );   // 100 milli seconds
            timer.IsEnabled = true;
            timer.Tick += new EventHandler( timer_Tick );

            // fill combo box with known folders
            IList<string> keys = KnownFolders.GetAllFolders( ).Keys;
            string[ ] folders = new string[keys.Count];
            keys.CopyTo( folders, 0 );
            foreach( string folder in folders )
            {
                ComboBoxItem cbi = new ComboBoxItem( );
                TextBlock tb = new TextBlock();
                tb.Text = folder;
                cbi.Content = tb;
                knownFoldersCombo.Items.Add( cbi );
            }
        }


        uint lastItemCount = 0;
        uint lastSelectedItemCount = 0;
        List<string> items = new List<string>();
        List<string> selectedItems = new List<string>( );

        void timer_Tick( object sender, EventArgs e )
        {
            // collection changed events are not implemented at this point on the 
            // ExplorerBrowser collections. In a future release these will be 
            // observable collections.

            bool textChanged = false;
            if( lastItemCount != eb.Items.Count )
            {
                lastItemCount = eb.Items.Count;
                textChanged = true;

                items.Clear( );
                items.Add( "Items in collection = " + lastItemCount );
                foreach( ShellObject item in eb.Items )
                {
                    if( item != null )
                        items.Add( "\tItem = " + item.GetDisplayName( ShellItemDisplayNameType.Normal ) );
                }
            }


            if( lastSelectedItemCount != eb.SelectedItems.Count )
            {
                lastSelectedItemCount = eb.SelectedItems.Count;

                textChanged = true;

                selectedItems.Clear( );
                selectedItems.Add( "Items in selection = " + lastSelectedItemCount );
                foreach( ShellObject item in eb.SelectedItems )
                {
                    if( item != null )
                        selectedItems.Add( "\tItem = " + item.GetDisplayName( ShellItemDisplayNameType.Normal ) );
                }

            }

            if( textChanged )
            {
                ItemsList.Children.Clear( );

                foreach( string item in items )
                {
                    TextBlock tb = new TextBlock( );
                    tb.Text = item;
                    ItemsList.Children.Add( tb );
                }

                foreach( string item in selectedItems )
                {
                    TextBlock tb = new TextBlock( );
                    tb.Text = item;
                    ItemsList.Children.Add( tb );
                }
            } 
        
        }

        private void ViewMode_SelectionChanged( object sender, SelectionChangedEventArgs e )
        {
            ListBox lb = e.Source as ListBox;
            if( lb.SelectedIndex != -1 )
            {
                ListBoxItem item = lb.SelectedItems[ 0 ] as ListBoxItem;

                if( eb != null )
                    eb.ViewMode = (ExplorerBrowserViewMode)Enum.Parse( typeof( ExplorerBrowserViewMode ), (string)item.Content );
            }
        }

        private void navigateFileButton_Click( object sender, RoutedEventArgs e )
        {
            try
            {
                ShellFile sf = ShellFile.FromFilePath( navigateFileTextBox.Text );
                eb.Navigate( sf );
            }
            catch
            {
                MessageBox.Show( "Navigation not possible!" );
            }
        }

        private void navigateFolderButton_Click( object sender, RoutedEventArgs e )
        {
            try
            {
                ShellFolder sf = ShellFolder.FromFolderPath( navigateFolderTextBox.Text );
                eb.Navigate( sf );
            }
            catch
            {
                MessageBox.Show( "Navigation not possible!" );
            }
        }

        private void navigateKnownFolderButton_Click( object sender, RoutedEventArgs e )
        {
            try
            {
                ComboBoxItem item = knownFoldersCombo.Items[ knownFoldersCombo.SelectedIndex ] as ComboBoxItem;
                TextBlock tb = item.Content as TextBlock;
                KnownFolder kf = KnownFolders.GetKnownFolder( tb.Text, false );
                eb.Navigate( kf );
            }
            catch
            {
                MessageBox.Show( "Navigation not possible!" );
            }
        }
    }
}
