//Copyright (c) Microsoft Corporation.  All rights reserved.

using System;
using System.Collections.Generic;
using System.Drawing;
using System.Windows.Forms;
using Microsoft.WindowsAPICodePack.Shell;
using System.IO;
using System.Diagnostics;

namespace Microsoft.WindowsAPICodePack.Samples.ShellObjectCFDBrowser
{
    public partial class Form1 : Form
    {
        private ShellObject currentlySelected = null;

        public Form1()
        {
            InitializeComponent();

            LoadKnownFolders();
            LoadSavedSearches();

            if (CoreHelpers.RunningOnWin7)
                LoadKnownLibraries();
            else
                label2.Enabled = cfdLibraryButton.Enabled = librariesComboBox.Enabled = false;

            if (CoreHelpers.RunningOnWin7)
                LoadSearchConnectors();
            else
                label7.Enabled = searchConnectorButton.Enabled = searchConnectorComboBox.Enabled = false;
        }

        /// <summary>
        /// Load all the Saved Searches on the current system
        /// </summary>
        private void LoadSavedSearches()
        {
            foreach (ShellObject so in KnownFolders.SavedSearches)
            {
                if (so is SavedSearch)
                    savedSearchComboBox.Items.Add(Path.GetFileName(so.ParsingName));
            }

            if (savedSearchComboBox.Items.Count > 0)
                savedSearchComboBox.SelectedIndex = 0;
            else
                savedSearchButton.Enabled = false;
        }

        /// <summary>
        /// Load all the Search Connectors on the current system
        /// </summary>
        private void LoadSearchConnectors()
        {
            foreach (ShellObject so in KnownFolders.SavedSearches)
            {
                if (so is SearchConnector)
                    searchConnectorComboBox.Items.Add(Path.GetFileName(so.ParsingName));
            }

            if (searchConnectorComboBox.Items.Count > 0)
                searchConnectorComboBox.SelectedIndex = 0;
            else
                searchConnectorButton.Enabled = false;
        }

        /// <summary>
        /// Load the known Shell Libraries
        /// </summary>
        private void LoadKnownLibraries()
        {
            // Load all the known libraries.
            // (There's currently no easy way to get all the known libraries in the system, 
            // so hard-code them here.)

            // Make sure we are clear
            librariesComboBox.Items.Clear();

            // 
            librariesComboBox.Items.Add("Documents");
            librariesComboBox.Items.Add("Music");
            librariesComboBox.Items.Add("Pictures");
            librariesComboBox.Items.Add("Videos");

            // Set initial selection
            librariesComboBox.SelectedIndex = 0;
        }

        /// <summary>
        /// Load all the knownfolders into the combobox
        /// </summary>
        private void LoadKnownFolders()
        {
            // Make sure we are clear
            knownFoldersComboBox.Items.Clear();

            // Get a list of all the known folders
            foreach (IKnownFolder kf in KnownFolders.All)
                if (kf != null && kf.CanonicalName != null)
                    knownFoldersComboBox.Items.Add(kf.CanonicalName);

            // Set our initial selection
            if (knownFoldersComboBox.Items.Count > 0)
                knownFoldersComboBox.SelectedIndex = 0;
        }

        private void cfdKFButton_Click(object sender, EventArgs e)
        {
            // Initialize
            detailsListView.Items.Clear();
            pictureBox1.Image = null;

            // Create a new CFD
            CommonOpenFileDialog cfd = new CommonOpenFileDialog();

            // Allow users to select non-filesystem objects
            cfd.AllowNonFileSystemItems = true;
            cfd.CheckReadOnly = true;

            // Get the known folder selected
            string kfString = knownFoldersComboBox.SelectedItem as string;

            if (!string.IsNullOrEmpty(kfString))
            {
                try
                {
                    // Try to get a known folder using the selected item (string).
                    IKnownFolder kf = KnownFolderHelper.FromCanonicalName(kfString);

                    // Set the knownfolder in the CFD.
                    cfd.InitialLocation = kf as ShellContainer;

                    if (!cfd.ShowDialog().Canceled)
                    {
                        ShellObject selectedSO = null;

                        try
                        {
                            // Get the selection from the user.
                            selectedSO = cfd.Item;
                        }
                        catch
                        {
                            // In some cases the user might select an object that cannot be wrapped
                            // by ShellObject.
                            MessageBox.Show("Could not create a ShellObject from the selected item.");
                        }


                        currentlySelected = selectedSO;

                        DisplayProperties(selectedSO);

                        showChildItemsButton.Enabled = selectedSO is ShellContainer ? true : false;
                    }
                }
                catch
                {
                    MessageBox.Show("Could not create a KnownFolder object for the selected item");
                }
            }
            else
            {
                MessageBox.Show("Invalid KnownFolder set.");
            }

            // Dispose our dialog in the end
            cfd.Dispose();
        }

        private void cfdLibraryButton_Click(object sender, EventArgs e)
        {
            // Initialize
            detailsListView.Items.Clear();
            pictureBox1.Image = null;

            // If the user has selected a library,
            // try to get the known folder path (Libraries are also known folders, so this will work)
            if (librariesComboBox.SelectedIndex > -1)
            {
                string selection = librariesComboBox.SelectedItem as string;
                ShellContainer selectedFolder = null;

                switch (selection)
                {
                    case "Documents":
                        selectedFolder = KnownFolders.DocumentsLibrary as ShellContainer;
                        break;
                    case "Music":
                        selectedFolder = KnownFolders.MusicLibrary as ShellContainer;
                        break;
                    case "Pictures":
                        selectedFolder = KnownFolders.PicturesLibrary as ShellContainer;
                        break;
                    case "Videos":
                        selectedFolder = KnownFolders.VideosLibrary as ShellContainer;
                        break;
                };

                // Create a CommonOpenFileDialog
                CommonOpenFileDialog cfd = new CommonOpenFileDialog();
                cfd.CheckReadOnly = true;

                // Set the initial location as the path of the library
                cfd.InitialLocation = selectedFolder;

                if (!cfd.ShowDialog().Canceled)
                {
                    // Get the selection from the user.
                    ShellObject so = cfd.Item;

                    currentlySelected = so;

                    showChildItemsButton.Enabled = so is ShellContainer ? true : false;

                    DisplayProperties(so);
                }
            }
        }

        private void cfdFileButton_Click(object sender, EventArgs e)
        {
            // Initialize
            detailsListView.Items.Clear();
            pictureBox1.Image = null;

            // Create a CommonOpenFileDialog to select files
            CommonOpenFileDialog cfd = new CommonOpenFileDialog();
            cfd.AllowNonFileSystemItems = true;
            cfd.CheckReadOnly = true;

            if (!cfd.ShowDialog().Canceled)
            {
                ShellObject selectedSO = null;

                try
                {
                    // Try to get the selected item
                    selectedSO = cfd.Item;
                }
                catch
                {
                    MessageBox.Show("Could not create a ShellObject from the selected item");
                }

                currentlySelected = selectedSO;

                DisplayProperties(selectedSO);

                showChildItemsButton.Enabled = selectedSO is ShellContainer ? true : false;

            }
        }

        private void cfdFolderButton_Click(object sender, EventArgs e)
        {
            // Initialize
            detailsListView.Items.Clear();
            pictureBox1.Image = null;

            // Display a CommonOpenFileDialog to select only folders 
            CommonOpenFileDialog cfd = new CommonOpenFileDialog();
            cfd.CheckReadOnly = true;
            cfd.FoldersOnly = true;
            cfd.AllowNonFileSystemItems = true;

            if (!cfd.ShowDialog().Canceled)
            {
                ShellContainer selectedSO = null;

                try
                {
                    // Try to get a valid selected item
                    selectedSO = cfd.Item as ShellContainer;
                }
                catch
                {
                    MessageBox.Show("Could not create a ShellObject from the selected item");
                }

                currentlySelected = selectedSO;

                DisplayProperties(selectedSO);

                showChildItemsButton.Enabled = selectedSO is ShellContainer ? true : false;
            }
        }

        private void savedSearchButton_Click(object sender, EventArgs e)
        {
            // Initialize
            detailsListView.Items.Clear();
            pictureBox1.Image = null;

            // Display a CommonOpenFileDialog to select only folders 
            CommonOpenFileDialog cfd = new CommonOpenFileDialog();
            cfd.InitialDirectory = Path.Combine(KnownFolders.SavedSearches.Path, savedSearchComboBox.SelectedItem.ToString());
            cfd.CheckReadOnly = true;

            if (!cfd.ShowDialog().Canceled)
            {
                ShellObject selectedSO = null;

                try
                {
                    // Try to get a valid selected item
                    selectedSO = cfd.Item;
                }
                catch
                {
                    MessageBox.Show("Could not create a ShellObject from the selected item");
                }

                currentlySelected = selectedSO;

                DisplayProperties(selectedSO);

                showChildItemsButton.Enabled = selectedSO is ShellContainer ? true : false;

            }
        }

        private void DisplayProperties(ShellObject selectedSO)
        {
            // Display some basic properties 
            if (selectedSO != null)
            {
                // Set the path in our filename textbox
                selectedFolderTextBox.Text = selectedSO.ParsingName;

                // display properties for this folder, as well as a thumbnail image.
                selectedSO.Thumbnail.CurrentSize = new System.Windows.Size(128, 128);
                pictureBox1.Image = selectedSO.Thumbnail.Bitmap;

                // show the properties
                AddProperty("Name", selectedSO.Name);
                AddProperty("Path", selectedSO.ParsingName);
                AddProperty("Type of ShellObject", selectedSO.GetType().Name);

                foreach (IProperty prop in selectedSO.Properties)
                {
                    if (prop.ValueAsObject != null)
                    {
                        try
                        {
                            AddProperty(prop.CanonicalName, prop.ValueAsObject.ToString());
                        }
                        catch
                        {
                            // Ignore
                            // Accessing some properties might throw exception.
                        }
                    }
                }
            }

        }

        private void AddProperty(string property, string value)
        {
            if (!string.IsNullOrEmpty(property))
            {
                // Create the property ListViewItem
                ListViewItem lvi = new ListViewItem(property);

                // Add a subitem for the value
                ListViewItem.ListViewSubItem subItemValue = new ListViewItem.ListViewSubItem(lvi, value);
                lvi.SubItems.Add(subItemValue);

                // Add the ListViewItem to our list
                detailsListView.Items.Add(lvi);
            }
        }

        private void searchConnectorButton_Click(object sender, EventArgs e)
        {
            // Initialize
            detailsListView.Items.Clear();
            pictureBox1.Image = null;

            // Display a CommonOpenFileDialog to select only folders 
            CommonOpenFileDialog cfd = new CommonOpenFileDialog();
            cfd.InitialDirectory = Path.Combine(KnownFolders.SavedSearches.Path, searchConnectorComboBox.SelectedItem.ToString());
            cfd.CheckReadOnly = true;

            if (!cfd.ShowDialog().Canceled)
            {
                ShellObject selectedSO = null;

                try
                {
                    // Try to get a valid selected item
                    selectedSO = cfd.Item;
                }
                catch
                {
                    MessageBox.Show("Could not create a ShellObject from the selected item");
                }

                currentlySelected = selectedSO;

                DisplayProperties(selectedSO);

                showChildItemsButton.Enabled = selectedSO is ShellContainer ? true : false;

            }
        }

        private void showChildItemsButton_Click(object sender, EventArgs e)
        {
            ShellContainer container = currentlySelected as ShellContainer;

            if (container == null)
                return;

            SubItemsForm subItems = new SubItemsForm();

            // Populate
            foreach (ShellObject so in container)
                subItems.AddItem(so.Name, so.Thumbnail.SmallBitmap);

            subItems.ShowDialog();
        }
    }
}