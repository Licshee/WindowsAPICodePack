// Copyright (c) Microsoft Corporation.  All rights reserved.

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using Microsoft.WindowsAPICodePack.Shell.Taskbar;

namespace TaskbarDemo
{
    public partial class ChildDocument : Form
    {
        public ChildDocument()
        {
            InitializeComponent();

            // Progress Bar
            foreach (string state in Enum.GetNames(typeof(TaskbarButtonProgressState)))
                comboBoxProgressBarStates.Items.Add(state);

            comboBoxProgressBarStates.SelectedItem = "Normal";
        }

        private void comboBoxProgressBarStates_SelectedIndexChanged(object sender, EventArgs e)
        {
            UpdateProgressBar();
        }

        private void UpdateProgressBar()
        {
            Taskbar.MultiViewprogressBar.SetState(this, (TaskbarButtonProgressState)Enum.Parse(typeof(TaskbarButtonProgressState), (string)comboBoxProgressBarStates.SelectedItem));
            if (Taskbar.ProgressBar.State != TaskbarButtonProgressState.Indeterminate)
                Taskbar.ProgressBar.CurrentValue = progressBar1.Value;

        }

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

                // resume the taskbar progressbar
                comboBoxProgressBarStates.SelectedItem = "Normal"; // this will trigger a call to UpdateProgressBar()
            }
            else
            {
                // Stop the timer
                timerProgressBar.Enabled = false;
                buttonProgressBarToggle.Text = "Start";

                // Pause the taskbar progressbar too
                comboBoxProgressBarStates.SelectedItem = "Paused"; // this will trigger a call to UpdateProgressBar()
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
    }
}
