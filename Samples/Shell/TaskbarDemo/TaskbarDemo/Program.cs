//Copyright (c) Microsoft Corporation.  All rights reserved.

using System;
using System.Windows.Forms;
using Microsoft.WindowsAPICodePack;

namespace TaskbarDemo
{
    static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {

            if (!CoreHelpers.RunningOnWin7)
            {
                MessageBox.Show("This demo requires to be run on Windows 7", "Demo needs Windows 7", MessageBoxButtons.OK, MessageBoxIcon.Error);
                Application.Exit();
                return;
            }

            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new TaskbarDemoMainForm());
        }
    }
}
