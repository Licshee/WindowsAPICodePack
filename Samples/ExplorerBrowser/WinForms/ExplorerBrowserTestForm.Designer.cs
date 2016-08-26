//Copyright (c) Microsoft Corporation.  All rights reserved.


namespace Microsoft.WindowsAPICodePack.Samples
{
    partial class ExplorerBrowserTestForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container( );
            this.viewModeCombo = new System.Windows.Forms.ComboBox( );
            this.label1 = new System.Windows.Forms.Label( );
            this.contentOptionsList = new System.Windows.Forms.CheckedListBox( );
            this.label2 = new System.Windows.Forms.Label( );
            this.label3 = new System.Windows.Forms.Label( );
            this.controlOptionsList = new System.Windows.Forms.CheckedListBox( );
            this.richTextBox = new System.Windows.Forms.RichTextBox( );
            this.label7 = new System.Windows.Forms.Label( );
            this.filePathNavigate = new System.Windows.Forms.Button( );
            this.filePathEdit = new System.Windows.Forms.TextBox( );
            this.knownFolderNavigate = new System.Windows.Forms.Button( );
            this.label6 = new System.Windows.Forms.Label( );
            this.knownFolderCombo = new System.Windows.Forms.ComboBox( );
            this.navigateButton = new System.Windows.Forms.Button( );
            this.label5 = new System.Windows.Forms.Label( );
            this.pathEdit = new System.Windows.Forms.TextBox( );
            this.collectionChangeTimer = new System.Windows.Forms.Timer( this.components );
            this.splitContainer1 = new System.Windows.Forms.SplitContainer( );
            this.splitContainer2 = new System.Windows.Forms.SplitContainer( );
            this.splitContainer3 = new System.Windows.Forms.SplitContainer( );
            this.explorerBrowser = new Microsoft.WindowsAPICodePack.Shell.ExplorerBrowser( );
            this.splitContainer1.Panel1.SuspendLayout( );
            this.splitContainer1.Panel2.SuspendLayout( );
            this.splitContainer1.SuspendLayout( );
            this.splitContainer2.Panel1.SuspendLayout( );
            this.splitContainer2.Panel2.SuspendLayout( );
            this.splitContainer2.SuspendLayout( );
            this.splitContainer3.Panel1.SuspendLayout( );
            this.splitContainer3.Panel2.SuspendLayout( );
            this.splitContainer3.SuspendLayout( );
            this.SuspendLayout( );
            // 
            // viewModeCombo
            // 
            this.viewModeCombo.FormattingEnabled = true;
            this.viewModeCombo.Location = new System.Drawing.Point( 5, 25 );
            this.viewModeCombo.Name = "viewModeCombo";
            this.viewModeCombo.Size = new System.Drawing.Size( 150, 21 );
            this.viewModeCombo.TabIndex = 5;
            this.viewModeCombo.SelectedIndexChanged += new System.EventHandler( this.viewModeCombo_SelectedIndexChanged );
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point( 3, 9 );
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size( 60, 13 );
            this.label1.TabIndex = 6;
            this.label1.Text = "View Mode";
            // 
            // contentOptionsList
            // 
            this.contentOptionsList.CheckOnClick = true;
            this.contentOptionsList.FormattingEnabled = true;
            this.contentOptionsList.Items.AddRange( new object[ ] {
            "1",
            "2",
            "3",
            "4",
            "5",
            "6",
            "7",
            "8",
            "9",
            "10",
            "11",
            "12",
            "13",
            "14",
            "15",
            "16",
            "17",
            "18",
            "19",
            "20",
            "21",
            "22",
            "23",
            "24",
            "25",
            "26",
            "27",
            "28",
            "29",
            "30",
            "31",
            "32"} );
            this.contentOptionsList.Location = new System.Drawing.Point( 6, 162 );
            this.contentOptionsList.Name = "contentOptionsList";
            this.contentOptionsList.Size = new System.Drawing.Size( 147, 364 );
            this.contentOptionsList.TabIndex = 7;
            this.contentOptionsList.ItemCheck += new System.Windows.Forms.ItemCheckEventHandler( this.contentOptionsList_ItemCheck );
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point( 6, 144 );
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size( 83, 13 );
            this.label2.TabIndex = 8;
            this.label2.Text = "Content Options";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point( 3, 55 );
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size( 79, 13 );
            this.label3.TabIndex = 9;
            this.label3.Text = "Control Options";
            // 
            // controlOptionsList
            // 
            this.controlOptionsList.CheckOnClick = true;
            this.controlOptionsList.FormattingEnabled = true;
            this.controlOptionsList.Items.AddRange( new object[ ] {
            "1",
            "2",
            "3",
            "4"} );
            this.controlOptionsList.Location = new System.Drawing.Point( 6, 71 );
            this.controlOptionsList.Name = "controlOptionsList";
            this.controlOptionsList.Size = new System.Drawing.Size( 147, 64 );
            this.controlOptionsList.TabIndex = 10;
            this.controlOptionsList.ItemCheck += new System.Windows.Forms.ItemCheckEventHandler( this.controlOptionsList_ItemCheck );
            // 
            // richTextBox
            // 
            this.richTextBox.Dock = System.Windows.Forms.DockStyle.Fill;
            this.richTextBox.Location = new System.Drawing.Point( 0, 0 );
            this.richTextBox.Name = "richTextBox";
            this.richTextBox.Size = new System.Drawing.Size( 669, 190 );
            this.richTextBox.TabIndex = 0;
            this.richTextBox.Text = "";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point( 30, 37 );
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size( 51, 13 );
            this.label7.TabIndex = 8;
            this.label7.Text = "File Path:";
            // 
            // filePathNavigate
            // 
            this.filePathNavigate.Location = new System.Drawing.Point( 492, 32 );
            this.filePathNavigate.Name = "filePathNavigate";
            this.filePathNavigate.Size = new System.Drawing.Size( 126, 23 );
            this.filePathNavigate.TabIndex = 7;
            this.filePathNavigate.Text = "Navigate File";
            this.filePathNavigate.UseVisualStyleBackColor = true;
            this.filePathNavigate.Click += new System.EventHandler( this.filePathNavigate_Click );
            // 
            // filePathEdit
            // 
            this.filePathEdit.Location = new System.Drawing.Point( 87, 33 );
            this.filePathEdit.Name = "filePathEdit";
            this.filePathEdit.Size = new System.Drawing.Size( 399, 20 );
            this.filePathEdit.TabIndex = 6;
            // 
            // knownFolderNavigate
            // 
            this.knownFolderNavigate.Location = new System.Drawing.Point( 492, 61 );
            this.knownFolderNavigate.Name = "knownFolderNavigate";
            this.knownFolderNavigate.Size = new System.Drawing.Size( 126, 23 );
            this.knownFolderNavigate.TabIndex = 5;
            this.knownFolderNavigate.Text = "Navigate Known Folder";
            this.knownFolderNavigate.UseVisualStyleBackColor = true;
            this.knownFolderNavigate.Click += new System.EventHandler( this.knownFolderNavigate_Click );
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point( 6, 66 );
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size( 75, 13 );
            this.label6.TabIndex = 4;
            this.label6.Text = "Known Folder:";
            // 
            // knownFolderCombo
            // 
            this.knownFolderCombo.FormattingEnabled = true;
            this.knownFolderCombo.Location = new System.Drawing.Point( 87, 63 );
            this.knownFolderCombo.Name = "knownFolderCombo";
            this.knownFolderCombo.Size = new System.Drawing.Size( 399, 21 );
            this.knownFolderCombo.TabIndex = 3;
            // 
            // navigateButton
            // 
            this.navigateButton.Location = new System.Drawing.Point( 492, 4 );
            this.navigateButton.Name = "navigateButton";
            this.navigateButton.Size = new System.Drawing.Size( 127, 23 );
            this.navigateButton.TabIndex = 2;
            this.navigateButton.Text = "Navigate Path";
            this.navigateButton.UseVisualStyleBackColor = true;
            this.navigateButton.Click += new System.EventHandler( this.navigateButton_Click );
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point( 17, 9 );
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size( 64, 13 );
            this.label5.TabIndex = 1;
            this.label5.Text = "Folder Path:";
            // 
            // pathEdit
            // 
            this.pathEdit.Location = new System.Drawing.Point( 87, 5 );
            this.pathEdit.Name = "pathEdit";
            this.pathEdit.Size = new System.Drawing.Size( 399, 20 );
            this.pathEdit.TabIndex = 0;
            // 
            // collectionChangeTimer
            // 
            this.collectionChangeTimer.Enabled = true;
            this.collectionChangeTimer.Tick += new System.EventHandler( this.collectionChangeTimer_Tick );
            // 
            // splitContainer1
            // 
            this.splitContainer1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.splitContainer1.FixedPanel = System.Windows.Forms.FixedPanel.Panel1;
            this.splitContainer1.IsSplitterFixed = true;
            this.splitContainer1.Location = new System.Drawing.Point( 0, 0 );
            this.splitContainer1.Name = "splitContainer1";
            // 
            // splitContainer1.Panel1
            // 
            this.splitContainer1.Panel1.Controls.Add( this.label1 );
            this.splitContainer1.Panel1.Controls.Add( this.label2 );
            this.splitContainer1.Panel1.Controls.Add( this.controlOptionsList );
            this.splitContainer1.Panel1.Controls.Add( this.contentOptionsList );
            this.splitContainer1.Panel1.Controls.Add( this.label3 );
            this.splitContainer1.Panel1.Controls.Add( this.viewModeCombo );
            // 
            // splitContainer1.Panel2
            // 
            this.splitContainer1.Panel2.Controls.Add( this.splitContainer2 );
            this.splitContainer1.Size = new System.Drawing.Size( 841, 904 );
            this.splitContainer1.SplitterDistance = 168;
            this.splitContainer1.TabIndex = 11;
            // 
            // splitContainer2
            // 
            this.splitContainer2.Dock = System.Windows.Forms.DockStyle.Fill;
            this.splitContainer2.FixedPanel = System.Windows.Forms.FixedPanel.Panel1;
            this.splitContainer2.IsSplitterFixed = true;
            this.splitContainer2.Location = new System.Drawing.Point( 0, 0 );
            this.splitContainer2.Name = "splitContainer2";
            this.splitContainer2.Orientation = System.Windows.Forms.Orientation.Horizontal;
            // 
            // splitContainer2.Panel1
            // 
            this.splitContainer2.Panel1.Controls.Add( this.label5 );
            this.splitContainer2.Panel1.Controls.Add( this.pathEdit );
            this.splitContainer2.Panel1.Controls.Add( this.label7 );
            this.splitContainer2.Panel1.Controls.Add( this.navigateButton );
            this.splitContainer2.Panel1.Controls.Add( this.filePathNavigate );
            this.splitContainer2.Panel1.Controls.Add( this.knownFolderCombo );
            this.splitContainer2.Panel1.Controls.Add( this.filePathEdit );
            this.splitContainer2.Panel1.Controls.Add( this.label6 );
            this.splitContainer2.Panel1.Controls.Add( this.knownFolderNavigate );
            // 
            // splitContainer2.Panel2
            // 
            this.splitContainer2.Panel2.Controls.Add( this.splitContainer3 );
            this.splitContainer2.Size = new System.Drawing.Size( 669, 904 );
            this.splitContainer2.SplitterDistance = 93;
            this.splitContainer2.TabIndex = 0;
            // 
            // splitContainer3
            // 
            this.splitContainer3.Dock = System.Windows.Forms.DockStyle.Fill;
            this.splitContainer3.FixedPanel = System.Windows.Forms.FixedPanel.Panel2;
            this.splitContainer3.IsSplitterFixed = true;
            this.splitContainer3.Location = new System.Drawing.Point( 0, 0 );
            this.splitContainer3.Name = "splitContainer3";
            this.splitContainer3.Orientation = System.Windows.Forms.Orientation.Horizontal;
            // 
            // splitContainer3.Panel1
            // 
            this.splitContainer3.Panel1.Controls.Add( this.explorerBrowser );
            // 
            // splitContainer3.Panel2
            // 
            this.splitContainer3.Panel2.Controls.Add( this.richTextBox );
            this.splitContainer3.Size = new System.Drawing.Size( 669, 807 );
            this.splitContainer3.SplitterDistance = 613;
            this.splitContainer3.TabIndex = 0;
            // 
            // explorerBrowser1
            // 
            this.explorerBrowser.Dock = System.Windows.Forms.DockStyle.Fill;
            this.explorerBrowser.Location = new System.Drawing.Point( 0, 0 );
            this.explorerBrowser.Name = "explorerBrowser1";
            this.explorerBrowser.Size = new System.Drawing.Size( 669, 613 );
            this.explorerBrowser.TabIndex = 0;
            this.explorerBrowser.Text = "explorerBrowser1";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF( 6F, 13F );
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size( 841, 904 );
            this.Controls.Add( this.splitContainer1 );
            this.Name = "Form1";
            this.Text = "Explorer Browser Demo";
            this.splitContainer1.Panel1.ResumeLayout( false );
            this.splitContainer1.Panel1.PerformLayout( );
            this.splitContainer1.Panel2.ResumeLayout( false );
            this.splitContainer1.ResumeLayout( false );
            this.splitContainer2.Panel1.ResumeLayout( false );
            this.splitContainer2.Panel1.PerformLayout( );
            this.splitContainer2.Panel2.ResumeLayout( false );
            this.splitContainer2.ResumeLayout( false );
            this.splitContainer3.Panel1.ResumeLayout( false );
            this.splitContainer3.Panel2.ResumeLayout( false );
            this.splitContainer3.ResumeLayout( false );
            this.ResumeLayout( false );

        }

        #endregion

        private System.Windows.Forms.ComboBox viewModeCombo;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.CheckedListBox contentOptionsList;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.CheckedListBox controlOptionsList;
        private System.Windows.Forms.Button navigateButton;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox pathEdit;
        private System.Windows.Forms.Button knownFolderNavigate;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.ComboBox knownFolderCombo;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Button filePathNavigate;
        private System.Windows.Forms.TextBox filePathEdit;
        private System.Windows.Forms.RichTextBox richTextBox;
        private System.Windows.Forms.Timer collectionChangeTimer;
        private System.Windows.Forms.SplitContainer splitContainer1;
        private System.Windows.Forms.SplitContainer splitContainer2;
        private System.Windows.Forms.SplitContainer splitContainer3;
        private Microsoft.WindowsAPICodePack.Shell.ExplorerBrowser explorerBrowser;

    }
}

