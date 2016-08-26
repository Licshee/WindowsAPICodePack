//Copyright (c) Microsoft Corporation.  All rights reserved.

using System;
using System.Windows.Forms;
using Microsoft.WindowsAPICodePack.Shell;

namespace Microsoft.WindowsAPICodePack.Samples.ThumbnailBrowserDemo
{
    public partial class ThumbnailBrowser : Form
    {
        /// <summary>
        /// Different views the picture browser supports
        /// </summary>
        private enum Views
        {
            Small,
            Medium,
            Large,
            ExtraLarge,
        }

        /// <summary>
        /// Our current view (defaults to Views.Large)
        /// </summary>
        private Views currentView = Views.Large;

        /// <summary>
        /// Our current ShellFileSystemObject.
        /// </summary>
        private ShellFileSystemObject currentItem = null;

        public ThumbnailBrowser()
        {
            InitializeComponent();

            // Set some ExplorerBrowser properties
            explorerBrowser1.ContentOptions.SingleSelection = true;

            // set our initial state CurrentView == large
            toolStripSplitButton1.Image = Microsoft.WindowsAPICodePack.Samples.ThumbnailBrowserDemo.Properties.Resources.large;
            smallToolStripMenuItem.Checked = false;
            mediumToolStripMenuItem.Checked = false;
            largeToolStripMenuItem.Checked = true;
            extraLargeToolStripMenuItem.Checked = false;
        }

        /// <summary>
        /// When the timer ticks, get the updated selected items from Explorer Browser
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void timer1_Tick(object sender, EventArgs e)
        {
            if (this.explorerBrowser1.SelectedItems != null &&
                this.explorerBrowser1.SelectedItems.Count == 1)
            {
                // Set our new current item
                currentItem = explorerBrowser1.SelectedItems[0] as ShellFileSystemObject;

                // Update preview
                UpdatePreivew();
            }
        }

        /// <summary>
        /// Updates the thumbnail preview for currently selected item and current view
        /// </summary>
        private void UpdatePreivew()
        {
            if (currentItem != null)
            {
                ShellObjectThumbnail thumb = currentItem.Thumbnail;

                if (currentView == Views.Small)
                    thumb = currentItem.Thumbnail.Small;
                else if (currentView == Views.Medium)
                    thumb = currentItem.Thumbnail.Medium;
                else if (currentView == Views.Large)
                    thumb = currentItem.Thumbnail.Large;
                else if (currentView == Views.ExtraLarge)
                    thumb = currentItem.Thumbnail.ExtraLarge;

                pictureBox1.Image = thumb.Bitmap;
            }
            else
            {
                pictureBox1.Image = null;
            }
        }

        private void browseLocationButton_Click(object sender, EventArgs e)
        {
            // Create a new CommonOpenFileDialog to allow users to select a folder/library
            CommonOpenFileDialog cfd = new CommonOpenFileDialog();

            // Set options to allow libraries and non filesystem items to be selected
            cfd.FoldersOnly = true;
            cfd.AllowNonFileSystemItems = true;

            // Show the dialog
            CommonFileDialogResult result = cfd.ShowDialog();

            // if the user didn't cancel
            if (!result.Canceled)
            {
                // Update the location on the ExplorerBrowser
                ShellObject resultItem = cfd.Item;
                explorerBrowser1.Navigate(resultItem);

                // Also update our textbox to display the full path
                locationTextBox.Text = resultItem.Path;
            }
        }

        private void toolStripSplitButton1_ButtonClick(object sender, EventArgs e)
        {
            ToggleViews();
        }

        /// <summary>
        /// Toggle the different views for the thumbnail image.
        /// Includes: Small, Medium, Large (default), and Extra Large.
        /// </summary>
        private void ToggleViews()
        {
            // Toggle the views
            // Update our current view, as well as the image shown
            // on the "Views" menu.

            if (currentView == Views.Small)
            {
                currentView = Views.Medium;
                toolStripSplitButton1.Image = Microsoft.WindowsAPICodePack.Samples.ThumbnailBrowserDemo.Properties.Resources.medium;
                smallToolStripMenuItem.Checked = false;
                mediumToolStripMenuItem.Checked = true;
                largeToolStripMenuItem.Checked = false;
                extraLargeToolStripMenuItem.Checked = false;
            }
            else if (currentView == Views.Medium)
            {
                currentView = Views.Large;
                toolStripSplitButton1.Image = Microsoft.WindowsAPICodePack.Samples.ThumbnailBrowserDemo.Properties.Resources.large;
                smallToolStripMenuItem.Checked = false;
                mediumToolStripMenuItem.Checked = false;
                largeToolStripMenuItem.Checked = true;
                extraLargeToolStripMenuItem.Checked = false;
            }
            else if (currentView == Views.Large)
            {
                currentView = Views.ExtraLarge;
                toolStripSplitButton1.Image = Microsoft.WindowsAPICodePack.Samples.ThumbnailBrowserDemo.Properties.Resources.extralarge;
                smallToolStripMenuItem.Checked = false;
                mediumToolStripMenuItem.Checked = false;
                largeToolStripMenuItem.Checked = false;
                extraLargeToolStripMenuItem.Checked = true;
            }
            else if (currentView == Views.ExtraLarge)
            {
                currentView = Views.Small;
                toolStripSplitButton1.Image = Microsoft.WindowsAPICodePack.Samples.ThumbnailBrowserDemo.Properties.Resources.small;
                smallToolStripMenuItem.Checked = true;
                mediumToolStripMenuItem.Checked = false;
                largeToolStripMenuItem.Checked = false;
                extraLargeToolStripMenuItem.Checked = false;
            }

            // Update the image
            UpdatePreivew();
        }

        private void smallToolStripMenuItem_Click(object sender, EventArgs e)
        {
            // Update current view
            currentView = Views.Small;

            // Update the menu item states
            smallToolStripMenuItem.Checked = true;
            mediumToolStripMenuItem.Checked = false;
            largeToolStripMenuItem.Checked = false;
            extraLargeToolStripMenuItem.Checked = false;

            // Update the main splitbutton image
            toolStripSplitButton1.Image = Microsoft.WindowsAPICodePack.Samples.ThumbnailBrowserDemo.Properties.Resources.small;

            // Update the image
            UpdatePreivew();
        }

        private void mediumToolStripMenuItem_Click(object sender, EventArgs e)
        {
            // Update current view
            currentView = Views.Medium;

            // Update the menu item states
            smallToolStripMenuItem.Checked = false;
            mediumToolStripMenuItem.Checked = true;
            largeToolStripMenuItem.Checked = false;
            extraLargeToolStripMenuItem.Checked = false;

            // Update the main splitbutton image
            toolStripSplitButton1.Image = Microsoft.WindowsAPICodePack.Samples.ThumbnailBrowserDemo.Properties.Resources.medium;

            // Update the image
            UpdatePreivew();
        }

        private void largeToolStripMenuItem_Click(object sender, EventArgs e)
        {
            // Update current view
            currentView = Views.Large;

            // Update the menu item states
            smallToolStripMenuItem.Checked = false;
            mediumToolStripMenuItem.Checked = false;
            largeToolStripMenuItem.Checked = true;
            extraLargeToolStripMenuItem.Checked = false;

            // Update the main splitbutton image
            toolStripSplitButton1.Image = Microsoft.WindowsAPICodePack.Samples.ThumbnailBrowserDemo.Properties.Resources.large;

            // Update the image
            UpdatePreivew();
        }

        private void extraLargeToolStripMenuItem_Click(object sender, EventArgs e)
        {
            // Update current view
            currentView = Views.ExtraLarge;

            // Update the menu item states
            smallToolStripMenuItem.Checked = false;
            mediumToolStripMenuItem.Checked = false;
            largeToolStripMenuItem.Checked = false;
            extraLargeToolStripMenuItem.Checked = true;

            // Update the main splitbutton image
            toolStripSplitButton1.Image = Microsoft.WindowsAPICodePack.Samples.ThumbnailBrowserDemo.Properties.Resources.extralarge;

            // Update the image
            UpdatePreivew();

        }
    }
}
