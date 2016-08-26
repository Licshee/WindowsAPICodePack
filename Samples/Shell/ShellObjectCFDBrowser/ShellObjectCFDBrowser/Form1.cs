//Copyright (c) Microsoft Corporation.  All rights reserved.

using System;
using System.Collections.Generic;
using System.Drawing;
using System.Windows.Forms;
using Microsoft.WindowsAPICodePack.Shell;

namespace Microsoft.WindowsAPICodePack.Samples.ShellObjectCFDBrowser
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

            LoadKnownFolders();
            LoadKnownLibraries();
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
            SortedList<string, Guid> kfList = KnownFolders.GetAllFolders();

            // Add them to our combobox.
            foreach (KeyValuePair<string, Guid> kv in kfList)
            {
                knownFoldersComboBox.Items.Add(kv.Key);
            }

            // Set our initial selection
            if (knownFoldersComboBox.Items.Count > 0)
                knownFoldersComboBox.SelectedIndex = 0;
        }

        private void cfdKFButton_Click(object sender, EventArgs e)
        {
            // Initialize
            detailsTextBox.Text = "";
            pictureBox1.Image = null;

            // Create a new CFD
            CommonOpenFileDialog cfd = new CommonOpenFileDialog();

            // Allow users to select non-filesystem objects
            cfd.AllowNonFileSystemItems = true;

            // Get the known folder selected
            string kfString = knownFoldersComboBox.SelectedItem as string;

            if (!string.IsNullOrEmpty(kfString))
            {
                try
                {
                    // Try to get a known folder using the selected item (string).
                    KnownFolder kf = KnownFolders.GetKnownFolder(kfString, false);

                    // Set the knownfolder in the CFD.
                    cfd.InitialLocation = kf;

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

                        // If we do get a valid selection, display some basic properties
                        if (selectedSO != null)
                        {
                            detailsTextBox.Text = "Name: " + selectedSO.Name;
                            detailsTextBox.Text += Environment.NewLine + "Path: " + selectedSO.Path;
                            detailsTextBox.Text += Environment.NewLine + "Type of ShellObject: " + selectedSO.GetType().Name;
                        }

                        // If this is a ShellFileSystemObject (ShellFile or ShellFolder)
                        // Display some additional properties as well
                        ShellFileSystemObject si = selectedSO as ShellFileSystemObject;

                        if (si != null)
                        {
                            // Get a thumbnail from the ShellFileSystemObject
                            si.Thumbnail.Size = new Size(128, 128);
                            pictureBox1.Image = si.Thumbnail.Bitmap;

                            detailsTextBox.Text += Environment.NewLine;
                            detailsTextBox.Text += "Properties: ";
                            detailsTextBox.Text += Environment.NewLine;

                            // Get a list of properties and display them along with their values
                            foreach (IProperty prop in si.Properties)
                            {
                                if (prop.ValueAsObject != null)
                                {
                                    try
                                    {
                                        detailsTextBox.Text += prop.CanonicalName + " = " + prop.ValueAsObject.ToString();
                                        detailsTextBox.Text += Environment.NewLine;
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
            detailsTextBox.Text = "";
            pictureBox1.Image = null;

            // If the user has selected a library,
            // try to get the known folder path (Libraries are also known folders, so this will work)
            if (librariesComboBox.SelectedIndex > -1)
            {
                string selection = librariesComboBox.SelectedItem as string;
                string path = string.Empty;

                switch (selection)
                {
                    case "Documents":
                        path = KnownFolders.Documents;
                        break;
                    case "Music":
                        path = KnownFolders.Music;
                        break;
                    case "Pictures":
                        path = KnownFolders.Pictures;
                        break;
                    case "Videos":
                        path = KnownFolders.Videos;
                        break;
                };

                // Create a CommonOpenFileDialog
                CommonOpenFileDialog cfd = new CommonOpenFileDialog();

                // Set the initial location as the path of the library
                if (!string.IsNullOrEmpty(path))
                    cfd.InitialLocation = ShellFolder.FromFolderPath(path);

                if (!cfd.ShowDialog().Canceled)
                {
                    // Get the selection from the user.
                    ShellObject so = cfd.Item;

                    // Try to get a ShellFileSystemObject
                    ShellFileSystemObject si = so as ShellFileSystemObject;

                    if (si != null)
                    {
                        // If we do get a valid ShellFileSystemObject,
                        // display some basic properties and thumbnail
                        detailsTextBox.Text += si.Path;
                        si.Thumbnail.Size = new Size(128, 128);
                        pictureBox1.Image = si.Thumbnail.Bitmap;

                        detailsTextBox.Text += Environment.NewLine;
                        detailsTextBox.Text += Environment.NewLine;

                        // Also display all the specific properties for this ShellFileSystemObject
                        foreach (IProperty prop in si.Properties)
                        {
                            if (prop.ValueAsObject != null)
                            {
                                try
                                {
                                    detailsTextBox.Text += prop.CanonicalName + " = " + prop.ValueAsObject.ToString();
                                    detailsTextBox.Text += Environment.NewLine;
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
            }
        }

        private void cfdFileButton_Click(object sender, EventArgs e)
        {
            // Initialize
            detailsTextBox.Text = "";
            pictureBox1.Image = null;

            // Create a CommonOpenFileDialog to select files
            CommonOpenFileDialog cfd = new CommonOpenFileDialog();

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

                // If we get a valid item back, display some basic properties.
                if (selectedSO != null)
                {
                    detailsTextBox.Text = "Name: " + selectedSO.Name;
                    detailsTextBox.Text += Environment.NewLine + "Path: " + selectedSO.Path;
                    detailsTextBox.Text += Environment.NewLine + "Type of ShellObject: " + selectedSO.GetType().Name;

                    // Set the path in our filename textbox
                    selectedFileTextBox.Text = selectedSO.Path;
                }

                // If this is a ShellFile, display some basic properties for this file 
                // and the thumbnail image
                ShellFile si = selectedSO as ShellFile;

                if (si != null)
                {
                    si.Thumbnail.Size = new Size(128, 128);
                    pictureBox1.Image = si.Thumbnail.Bitmap;

                    detailsTextBox.Text += Environment.NewLine;
                    detailsTextBox.Text += "Properties: ";
                    detailsTextBox.Text += Environment.NewLine;

                    foreach (IProperty prop in si.Properties)
                    {
                        if (prop.ValueAsObject != null)
                        {
                            try
                            {
                                detailsTextBox.Text += prop.CanonicalName + " = " + prop.ValueAsObject.ToString();
                                detailsTextBox.Text += Environment.NewLine;
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
        }

        private void cfdFolderButton_Click(object sender, EventArgs e)
        {
            // Initialize
            detailsTextBox.Text = "";
            pictureBox1.Image = null;
            
            // Display a CommonOpenFileDialog to select only folders 
            CommonOpenFileDialog cfd = new CommonOpenFileDialog();
            cfd.FoldersOnly = true;

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

                // Display some basic properties 
                if (selectedSO != null)
                {
                    detailsTextBox.Text = "Name: " + selectedSO.Name;
                    detailsTextBox.Text += Environment.NewLine + "Path: " + selectedSO.Path;
                    detailsTextBox.Text += Environment.NewLine + "Type of ShellObject: " + selectedSO.GetType().Name;

                    // Set the path in our filename textbox
                    selectedFolderTextBox.Text = selectedSO.Path;
                }

                ShellFolder si = selectedSO as ShellFolder;

                // If the selected item is also a ShellFolder,
                // display properties for this folder, as well as a thumbnail image.
                if (si != null)
                {
                    si.Thumbnail.Size = new Size(128, 128);
                    pictureBox1.Image = si.Thumbnail.Bitmap;

                    detailsTextBox.Text += Environment.NewLine;
                    detailsTextBox.Text += "Properties: ";
                    detailsTextBox.Text += Environment.NewLine;

                    foreach (IProperty prop in si.Properties)
                    {
                        if (prop.ValueAsObject != null)
                        {
                            try
                            {
                                detailsTextBox.Text += prop.CanonicalName + " = " + prop.ValueAsObject.ToString();
                                detailsTextBox.Text += Environment.NewLine;
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
        }
    }
}