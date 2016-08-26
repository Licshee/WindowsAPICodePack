//Copyright (c) Microsoft Corporation.  All rights reserved.

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using Microsoft.WindowsAPICodePack.Shell;
using System.Windows.Forms.Integration;
using System.Reflection;

namespace Microsoft.WindowsAPICodePack.Samples
{
    public partial class ExplorerBrowserTestForm : Form
    {
        /// <summary>
        /// Initializes the state of the combo boxes
        /// </summary>
        public ExplorerBrowserTestForm()
        {
            InitializeComponent();

            viewModeCombo.Items.AddRange( 
                Enum.GetNames( typeof( ExplorerBrowserViewMode ) ) );

            contentOptionsList.Items.Clear( );
            contentOptionsList.Items.AddRange(
                Enum.GetNames( typeof( ExplorerBrowserContentFlags ) ) );

            controlOptionsList.Items.Clear( );
            controlOptionsList.Items.AddRange(
                Enum.GetNames( typeof( ExplorerBrowserControlFlags ) ) );

            IList<string> keys = KnownFolders.GetAllFolders( ).Keys;
            string[ ] folders = new string[keys.Count];
            keys.CopyTo( folders, 0 );
            knownFolderCombo.Items.AddRange( folders );
        }

        /// <summary>
        /// Updates the ViewMode of the ExplorerBrowser to match the combo box
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void viewModeCombo_SelectedIndexChanged( object sender, EventArgs e )
        {
            ExplorerBrowserViewMode viewMode =
                (ExplorerBrowserViewMode)Enum.Parse(
                    typeof( ExplorerBrowserViewMode ), 
                    viewModeCombo.Text );
            this.explorerBrowser.ContentOptions.ViewMode = viewMode;
        }

        /// <summary>
        /// Initial synchronization the combo boxes to the state of the explorer browser
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void explorerBrowser_VisibleChanged( object sender, EventArgs e )
        {
            viewModeCombo.Text = Enum.GetName(
                    typeof( ExplorerBrowserViewMode ),
                    this.explorerBrowser.ContentOptions.ViewMode );
            
            Array values = Enum.GetValues( typeof( ExplorerBrowserContentFlags ) );
            uint flags = (uint)this.explorerBrowser.ContentOptions.Flags;
            for( int index = 0; index < values.Length; index++ )
            {
                bool set = ( ( flags & (uint)values.GetValue( index ) ) != 0 );
                contentOptionsList.SetItemChecked( index, set );
            }

            flags = (uint)this.explorerBrowser.ControlOptions.Flags;
            for( int bit = 0; bit < 4; bit++ )
            {
                bool set = ( ( flags & ( 1 << bit ) ) != 0 );
                controlOptionsList.SetItemChecked( bit, set );
            }
        
        }

        /// <summary>
        /// Sets the ExplorerBrowser's ContentOptions.Flags to match the state of the list box
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void contentOptionsList_ItemCheck( object sender, ItemCheckEventArgs e )
        {
            ExplorerBrowserContentFlags flag = 
                (ExplorerBrowserContentFlags)Enum.Parse(
                    typeof( ExplorerBrowserContentFlags ),
                    contentOptionsList.Items[ e.Index ].ToString( ) );

            if( e.NewValue == CheckState.Checked )
                this.explorerBrowser.ContentOptions.Flags |= flag;
            else
                this.explorerBrowser.ContentOptions.Flags &= ~flag;
        }

        /// <summary>
        /// Sets the ExplorerBrowser's ControlOptions.Flags to match the state of the list box
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void controlOptionsList_ItemCheck( object sender, ItemCheckEventArgs e )
        {
            ExplorerBrowserControlFlags flag =
                (ExplorerBrowserControlFlags)Enum.Parse(
                    typeof( ExplorerBrowserControlFlags ),
                    controlOptionsList.Items[ e.Index ].ToString( ) );

            if( e.NewValue == CheckState.Checked )
                this.explorerBrowser.ControlOptions.Flags |= flag;
            else
                this.explorerBrowser.ControlOptions.Flags &= ~flag;
        }

        /// <summary>
        /// Navigates to a specified folder
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void navigateButton_Click( object sender, EventArgs e )
        {
            if( explorerBrowser.Navigate( ShellFolder.FromFolderPath( pathEdit.Text ) ) == false )
                MessageBox.Show( "I can't go there!" );
        }

        /// <summary>
        /// Navigates to a specified file (must be a container file to work, i.e., ZIP, CAB)
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void filePathNavigate_Click( object sender, EventArgs e )
        {
            try
            {
                this.explorerBrowser.Navigate( ShellFile.FromFilePath( this.filePathEdit.Text ) );
            }
            catch( Exception /*err*/ )
            {
                MessageBox.Show( "I can't go there!" );
            }
        }

        /// <summary>
        /// Navigates to a known folder
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void knownFolderNavigate_Click( object sender, EventArgs e )
        {
            try
            {
                KnownFolder kf = KnownFolders.GetKnownFolder( 
                        this.knownFolderCombo.Items[ knownFolderCombo.SelectedIndex ].ToString ( ),
                        false );
                
                this.explorerBrowser.Navigate( kf );
            }
            catch( Exception /*err*/ )
            {
                MessageBox.Show( "I can't go there!" );
            }
            
        }

        uint lastItemCount = 0;
        uint lastSelectedItemCount = 0;
        StringBuilder itemText = new StringBuilder( );
        StringBuilder selectionText = new StringBuilder( );
        
        
        /// <summary>
        /// Collection changed events are not implemented at this point on the 
        /// ExplorerBrowser collections. This a work around for that issue.
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void collectionChangeTimer_Tick( object sender, EventArgs e )
        {
            bool textChanged = false;
            if( lastItemCount != this.explorerBrowser.Items.Count )
            {
                itemText = new StringBuilder( );
                lastItemCount = this.explorerBrowser.Items.Count;

                itemText.AppendLine( "Items in collection = " + lastItemCount );
                foreach( ShellObject item in explorerBrowser.Items )
                {
                    if( item != null )
                        itemText.AppendLine( "\tItem = " + item.GetDisplayName( ShellItemDisplayNameType.Normal ) );
                }

                textChanged = true;
            }

            if( lastSelectedItemCount != this.explorerBrowser.SelectedItems.Count )
            {
                selectionText = new StringBuilder( );
                lastSelectedItemCount = this.explorerBrowser.SelectedItems.Count;

                selectionText.AppendLine( "Items in selection = " + lastSelectedItemCount );
                foreach( ShellObject item in explorerBrowser.SelectedItems )
                {
                    if( item != null )
                        selectionText.AppendLine( "\tItem = " + item.GetDisplayName( ShellItemDisplayNameType.Normal ) );
                }

                textChanged = true;
            }

            if( textChanged )
                richTextBox.Text = itemText.ToString( ) + selectionText.ToString();
        }
    }
}
