//Copyright (c) Microsoft Corporation.  All rights reserved.

using System;
using System.IO;
using System.Reflection;
using System.Windows.Forms;
using Microsoft.WindowsAPICodePack.Shell;
using Microsoft.WindowsAPICodePack.Shell.Taskbar;

namespace TaskbarDemo
{
    /// <summary>
    /// A word about known/custom categories.  In order for an application
    /// to have known/custom categories, a file type must be registered with
    /// that application.  This demo provides two menu items that allows you
    /// to register and unregister .txt files with this demo. By default
    /// shell displays the 'Recent' category for an application with a
    /// registered file type.
    /// 
    /// An exception will be thrown if you try to add a shell item to
    /// 'Custom Category 1' before registering a file type with this demo
    /// application.
    /// 
    /// Also, once a file type has been registered with this demo, setting
    /// jumpList.KnownCategoryToDisplay = KnownCategoryType.Neither will have
    /// no effect until at least one custom category or user task has been
    /// added to the taskbar jump list.
    /// </summary>    
    public partial class TaskbarDemoMainForm : Form
    {
        const string appId = "TaskbarDemo";
        const string progId = "TaskbarDemo";

        CustomCategory category1 = new CustomCategory("Custom Category 1");
        CustomCategory category2 = new CustomCategory("Custom Category 2");

        JumpList jumpList;

        string executableFolder;
        readonly string executablePath;

        #region Form Initialize

        public TaskbarDemoMainForm()
        {
            InitializeComponent();

            // Set the application specific id
            Taskbar.AppID = appId;

            // Retrieve the taskbar jump list
            jumpList = Taskbar.JumpList;

            // Add custom categories
            jumpList.CustomCategories.Add(category1);
            jumpList.CustomCategories.Add(category2);

            // Default values for jump lists
            comboBoxKnownCategoryType.SelectedItem = "Recent";
            comboBoxKnownCategoryLocation.SelectedItem = "Top";

            // Progress Bar
            foreach (string state in Enum.GetNames(typeof(TaskbarButtonProgressState)))
                comboBoxProgressBarStates.Items.Add(state);

            comboBoxProgressBarStates.SelectedItem = "Normal";

            // Update UI
            UpdateStatusBar("Application ready...");

            // Save current folder and path of running executable
            executablePath = Assembly.GetEntryAssembly().Location;
            executableFolder = Path.GetDirectoryName(executablePath);
        }

        #endregion

        #region File Registration Helpers

        private void registerFileTypeToolStripMenuItem_Click(object sender, EventArgs e)
        {
            RegistrationHelper.RegisterFileAssociations(
                progId,
                false,
                appId,
                executablePath + " /doc:%1",
                ".txt");
        }

        private void unregisterFileTypeToolStripMenuItem_Click(object sender, EventArgs e)
        {
            RegistrationHelper.UnregisterFileAssociations(
                progId,
                false,
                appId,
                executablePath + " /doc:%1",
                ".txt");
        }

        #endregion

        #region Menu Open/Close

        private void openToolStripMenuItem_Click(object sender, EventArgs e)
        {
            CommonOpenFileDialog dialog = new CommonOpenFileDialog();
            dialog.Title = "Select a text document to load";
            dialog.Filters.Add(new CommonFileDialogFilter("Text files (*.txt)", "*.txt"));

            CommonFileDialogResult result = dialog.ShowDialog();

            if (result.Canceled == false)
                ReportUsage(dialog.FileName);
        }

        private void saveToolStripMenuItem_Click(object sender, EventArgs e)
        {
            CommonSaveFileDialog dialog = new CommonSaveFileDialog();
            dialog.Title = "Select where to save your file";
            dialog.Filters.Add(new CommonFileDialogFilter("Text files (*.txt)", "*.txt"));

            CommonFileDialogResult result = dialog.ShowDialog();

            if (result.Canceled == false)
                ReportUsage(dialog.FileName);
        }

        private void ReportUsage(string fileName)
        {
            // Report file usage to shell.  Note: The dialog box automatically
            // reports usage to shell, but it's still recommeneded that the user
            // explicitly calls AddToRecent. Shell will automatically handle
            // duplicate additions.
            Taskbar.JumpList.AddToRecent(fileName);

            UpdateStatusBar("File added to recent documents");
        }

        #endregion;

        #region Known Categories

        private void comboBoxKnownCategoryLocation_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (comboBoxKnownCategoryLocation.SelectedIndex == 0)
                jumpList.KnownCategoryLocation = KnownCategoryLocationType.Top;
            else
                jumpList.KnownCategoryLocation = KnownCategoryLocationType.Bottom;
        }

        private void comboBoxKnownCategoryType_SelectedIndexChanged(object sender, EventArgs e)
        {
            switch (comboBoxKnownCategoryType.SelectedItem as string)
            {
                case "None":
                    jumpList.KnownCategoryToDisplay = KnownCategoryType.Neither;
                    break;
                case "Recent":
                    jumpList.KnownCategoryToDisplay = KnownCategoryType.Recent;
                    break;
                case "Frequent":
                    jumpList.KnownCategoryToDisplay = KnownCategoryType.Frequent;
                    break;
            }
        }

        #endregion

        #region Custom Categories

        private void buttonCategoryOneAddLink_Click(object sender, EventArgs e)
        {
            // Specify path for shell item
            string path = String.Format("{0}\\test{1}.txt",
                executableFolder,
                category1.JumpListItems.Count);

            // Make sure this file exists
            EnsureFile(path);

            // Add shell item to custom category
            category1.JumpListItems.Add(new JumpListItem(path));

            // Update status
            UpdateStatusBar(Path.GetFileName(path) + " added to 'Custom Category 1'");
        }

        private void buttonCategoryTwoAddLink_Click(object sender, EventArgs e)
        {
            // Specify path for shell link
            string path = String.Format("{0}\\test{1}.txt",
                executableFolder,
                category2.JumpListItems.Count);

            // Add jump list link to custom category
            category2.JumpListItems.Add(new JumpListLink
            {
                Title = String.Format("Custom Item - {0}", category2.JumpListItems.Count),
                Path = path,
                IconLocation = Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.System), "notepad.exe"),
                IconIndex = 0
            });

            // Update status
            UpdateStatusBar(Path.GetFileName(path) + " added to 'Custom Category 2'");
        }

        private void EnsureFile(string path)
        {
            if (File.Exists(path))
                return;

            // Simply create an empty file with the specified path
            FileStream fileStream = File.Create(path);
            fileStream.Close();
        }

        private void buttonUserTasksAddTasks_Click(object sender, EventArgs e)
        {
            // Don't add additional tasks after tasks have already been added
            if (jumpList.UserTasks.Count > 0)
                return;

            // Path to Windows system folder
            string systemFolder = Environment.GetFolderPath(Environment.SpecialFolder.System);

            // Add our user tasks
            jumpList.UserTasks.Add(new JumpListLink
            {
                Title = "Open Notepad",
                Path = Path.Combine(systemFolder, "notepad.exe"),
                IconLocation = Path.Combine(systemFolder, "notepad.exe"),
                IconIndex = 0
            });

            jumpList.UserTasks.Add(new JumpListLink
            {
                Title = "Open Paint",
                Path = Path.Combine(systemFolder, "mspaint.exe"),
                IconLocation = Path.Combine(systemFolder, "mspaint.exe"),
                IconIndex = 0
            });

            jumpList.UserTasks.Add(new JumpListSeparator());

            jumpList.UserTasks.Add(new JumpListLink
            {
                Title = "Open Calculator",
                Path = Path.Combine(systemFolder, "calc.exe"),
                IconLocation = Path.Combine(systemFolder, "calc.exe"),
                IconIndex = 0
            });

            // Update status
            UpdateStatusBar("Three user tasks added to jump list");
        }

        private void buttonCategoryOneRename_Click(object sender, EventArgs e)
        {
            category1.Name = "Updated Category Name";
        }

        #endregion

        #region Progress Bar

        private void buttonProgressBarToggle_Click(object sender, EventArgs e)
        {
            if (buttonProgressBarToggle.Text == "Start")
            {
                // Start the progress bar timer
                timerProgressBar.Enabled = true;
                buttonProgressBarToggle.Text = "Pause";

                // Reset the progress bar if necessary
                if (progressBar1.Value >= progressBar1.Maximum)
                    progressBar1.Value = 0;
            }
            else
            {
                // Stop the timer
                timerProgressBar.Enabled = false;
                buttonProgressBarToggle.Text = "Start";
            }

            UpdateProgressBar();
        }

        private void timerProgressBar_Tick(object sender, EventArgs e)
        {
            progressBar1.PerformStep();

            // Turn off the progress bar timer if it's done
            if (progressBar1.Value >= progressBar1.Maximum)
            {
                timerProgressBar.Enabled = false;
                buttonProgressBarToggle.Text = "Start";
            }

            UpdateProgressBar();
        }

        private void comboBoxProgressStates_SelectedIndexChanged(object sender, EventArgs e)
        {
            UpdateProgressBar();
        }

        private void UpdateProgressBar()
        {
            Taskbar.ProgressBar.State = (TaskbarButtonProgressState)Enum.Parse(typeof(TaskbarButtonProgressState), (string)comboBoxProgressBarStates.SelectedItem);
            Taskbar.ProgressBar.CurrentValue = progressBar1.Value;
        }

        #endregion;

        #region Icon Overlay

        private void labelNoIconOverlay_Click(object sender, EventArgs e)
        {
            Taskbar.OverlayImage = null;
        }

        private void pictureIconOverlay1_Click(object sender, EventArgs e)
        {
            Taskbar.OverlayImage =
                new OverlayImage(TaskbarDemo.Properties.Resources.Green, "Green");
        }

        private void pictureIconOverlay2_Click(object sender, EventArgs e)
        {
            Taskbar.OverlayImage =
                new OverlayImage(TaskbarDemo.Properties.Resources.Yellow, "Yellow");
        }

        private void pictureIconOverlay3_Click(object sender, EventArgs e)
        {
            Taskbar.OverlayImage =
                new OverlayImage(TaskbarDemo.Properties.Resources.Red, "Red");
        }
        #endregion

        private void UpdateStatusBar(string status)
        {
            toolStripStatusLabel1.Text = status;
        }
    }
}