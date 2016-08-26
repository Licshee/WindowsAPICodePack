namespace Microsoft.WindowsAPICodePack.Samples.ShellObjectCFDBrowser
{
    partial class Form1
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
            this.knownFoldersComboBox = new System.Windows.Forms.ComboBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.librariesComboBox = new System.Windows.Forms.ComboBox();
            this.cfdKFButton = new System.Windows.Forms.Button();
            this.cfdLibraryButton = new System.Windows.Forms.Button();
            this.cfdFileButton = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.selectedFileTextBox = new System.Windows.Forms.TextBox();
            this.selectedFolderTextBox = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.cfdFolderButton = new System.Windows.Forms.Button();
            this.detailsTextBox = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.SuspendLayout();
            // 
            // knownFoldersComboBox
            // 
            this.knownFoldersComboBox.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.knownFoldersComboBox.FormattingEnabled = true;
            this.knownFoldersComboBox.Location = new System.Drawing.Point(98, 37);
            this.knownFoldersComboBox.Name = "knownFoldersComboBox";
            this.knownFoldersComboBox.Size = new System.Drawing.Size(198, 21);
            this.knownFoldersComboBox.TabIndex = 0;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 40);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(80, 13);
            this.label1.TabIndex = 1;
            this.label1.Text = "Known Folders:";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(12, 80);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(49, 13);
            this.label2.TabIndex = 2;
            this.label2.Text = "Libraries:";
            // 
            // librariesComboBox
            // 
            this.librariesComboBox.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.librariesComboBox.FormattingEnabled = true;
            this.librariesComboBox.Location = new System.Drawing.Point(98, 77);
            this.librariesComboBox.Name = "librariesComboBox";
            this.librariesComboBox.Size = new System.Drawing.Size(198, 21);
            this.librariesComboBox.TabIndex = 3;
            // 
            // cfdKFButton
            // 
            this.cfdKFButton.Location = new System.Drawing.Point(334, 35);
            this.cfdKFButton.Name = "cfdKFButton";
            this.cfdKFButton.Size = new System.Drawing.Size(160, 23);
            this.cfdKFButton.TabIndex = 4;
            this.cfdKFButton.Text = "Open Dialog (selected KF)";
            this.cfdKFButton.UseVisualStyleBackColor = true;
            this.cfdKFButton.Click += new System.EventHandler(this.cfdKFButton_Click);
            // 
            // cfdLibraryButton
            // 
            this.cfdLibraryButton.Location = new System.Drawing.Point(334, 75);
            this.cfdLibraryButton.Name = "cfdLibraryButton";
            this.cfdLibraryButton.Size = new System.Drawing.Size(160, 23);
            this.cfdLibraryButton.TabIndex = 5;
            this.cfdLibraryButton.Text = "Open Dialog (selected library)";
            this.cfdLibraryButton.UseVisualStyleBackColor = true;
            this.cfdLibraryButton.Click += new System.EventHandler(this.cfdLibraryButton_Click);
            // 
            // cfdFileButton
            // 
            this.cfdFileButton.Location = new System.Drawing.Point(334, 116);
            this.cfdFileButton.Name = "cfdFileButton";
            this.cfdFileButton.Size = new System.Drawing.Size(160, 23);
            this.cfdFileButton.TabIndex = 6;
            this.cfdFileButton.Text = "Open Dialog (select a file)";
            this.cfdFileButton.UseVisualStyleBackColor = true;
            this.cfdFileButton.Click += new System.EventHandler(this.cfdFileButton_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(12, 121);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(68, 13);
            this.label3.TabIndex = 7;
            this.label3.Text = "Selected file:";
            // 
            // selectedFileTextBox
            // 
            this.selectedFileTextBox.Location = new System.Drawing.Point(98, 118);
            this.selectedFileTextBox.Name = "selectedFileTextBox";
            this.selectedFileTextBox.ReadOnly = true;
            this.selectedFileTextBox.Size = new System.Drawing.Size(198, 20);
            this.selectedFileTextBox.TabIndex = 8;
            this.selectedFileTextBox.Text = "(none)";
            // 
            // selectedFolderTextBox
            // 
            this.selectedFolderTextBox.Location = new System.Drawing.Point(98, 159);
            this.selectedFolderTextBox.Name = "selectedFolderTextBox";
            this.selectedFolderTextBox.ReadOnly = true;
            this.selectedFolderTextBox.Size = new System.Drawing.Size(198, 20);
            this.selectedFolderTextBox.TabIndex = 11;
            this.selectedFolderTextBox.Text = "(none)";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(12, 162);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(81, 13);
            this.label4.TabIndex = 10;
            this.label4.Text = "Selected folder:";
            // 
            // cfdFolderButton
            // 
            this.cfdFolderButton.Location = new System.Drawing.Point(334, 157);
            this.cfdFolderButton.Name = "cfdFolderButton";
            this.cfdFolderButton.Size = new System.Drawing.Size(160, 23);
            this.cfdFolderButton.TabIndex = 9;
            this.cfdFolderButton.Text = "Open Dialog (select a folder)";
            this.cfdFolderButton.UseVisualStyleBackColor = true;
            this.cfdFolderButton.Click += new System.EventHandler(this.cfdFolderButton_Click);
            // 
            // detailsTextBox
            // 
            this.detailsTextBox.Location = new System.Drawing.Point(153, 214);
            this.detailsTextBox.Multiline = true;
            this.detailsTextBox.Name = "detailsTextBox";
            this.detailsTextBox.ReadOnly = true;
            this.detailsTextBox.ScrollBars = System.Windows.Forms.ScrollBars.Both;
            this.detailsTextBox.Size = new System.Drawing.Size(364, 128);
            this.detailsTextBox.TabIndex = 12;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(12, 196);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(117, 13);
            this.label5.TabIndex = 13;
            this.label5.Text = "Details about selection:";
            // 
            // pictureBox1
            // 
            this.pictureBox1.Location = new System.Drawing.Point(12, 212);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(128, 128);
            this.pictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.CenterImage;
            this.pictureBox1.TabIndex = 14;
            this.pictureBox1.TabStop = false;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(535, 361);
            this.Controls.Add(this.pictureBox1);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.detailsTextBox);
            this.Controls.Add(this.selectedFolderTextBox);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.cfdFolderButton);
            this.Controls.Add(this.selectedFileTextBox);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.cfdFileButton);
            this.Controls.Add(this.cfdLibraryButton);
            this.Controls.Add(this.cfdKFButton);
            this.Controls.Add(this.librariesComboBox);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.knownFoldersComboBox);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.MaximizeBox = false;
            this.Name = "Form1";
            this.SizeGripStyle = System.Windows.Forms.SizeGripStyle.Hide;
            this.Text = "ShellObject browser for CommonFileDialog";
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ComboBox knownFoldersComboBox;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.ComboBox librariesComboBox;
        private System.Windows.Forms.Button cfdKFButton;
        private System.Windows.Forms.Button cfdLibraryButton;
        private System.Windows.Forms.Button cfdFileButton;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox selectedFileTextBox;
        private System.Windows.Forms.TextBox selectedFolderTextBox;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Button cfdFolderButton;
        private System.Windows.Forms.TextBox detailsTextBox;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.PictureBox pictureBox1;
    }
}

