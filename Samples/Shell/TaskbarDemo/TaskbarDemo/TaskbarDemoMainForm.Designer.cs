namespace TaskbarDemo
{
    partial class TaskbarDemoMainForm
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
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(TaskbarDemoMainForm));
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.fileToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.openToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.saveToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.administrationToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.registerFileTypeToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.unregisterFileTypeToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.fileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.openToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.saveToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.administrativeToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.registerFileTypeToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.unregisterFileTypeToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.statusStrip1 = new System.Windows.Forms.StatusStrip();
            this.toolStripStatusLabel1 = new System.Windows.Forms.ToolStripStatusLabel();
            this.timerProgressBar = new System.Windows.Forms.Timer(this.components);
            this.groupBoxKnownCategories = new System.Windows.Forms.GroupBox();
            this.comboBoxKnownCategoryType = new System.Windows.Forms.ComboBox();
            this.comboBoxKnownCategoryLocation = new System.Windows.Forms.ComboBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.groupBoxIconOverlay = new System.Windows.Forms.GroupBox();
            this.labelNoIconOverlay = new System.Windows.Forms.Label();
            this.pictureIconOverlay3 = new System.Windows.Forms.PictureBox();
            this.pictureIconOverlay2 = new System.Windows.Forms.PictureBox();
            this.label7 = new System.Windows.Forms.Label();
            this.pictureIconOverlay1 = new System.Windows.Forms.PictureBox();
            this.groupBoxCustomCategories = new System.Windows.Forms.GroupBox();
            this.buttonCategoryOneRename = new System.Windows.Forms.Button();
            this.label5 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.buttonCategoryTwoAddLink = new System.Windows.Forms.Button();
            this.buttonCategoryOneAddLink = new System.Windows.Forms.Button();
            this.buttonUserTasksAddTasks = new System.Windows.Forms.Button();
            this.groupBoxProgressBar = new System.Windows.Forms.GroupBox();
            this.label6 = new System.Windows.Forms.Label();
            this.comboBoxProgressBarStates = new System.Windows.Forms.ComboBox();
            this.buttonProgressBarToggle = new System.Windows.Forms.Button();
            this.progressBar1 = new System.Windows.Forms.ProgressBar();
            this.menuStrip1.SuspendLayout();
            this.groupBoxKnownCategories.SuspendLayout();
            this.groupBoxIconOverlay.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureIconOverlay3)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureIconOverlay2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureIconOverlay1)).BeginInit();
            this.groupBoxCustomCategories.SuspendLayout();
            this.groupBoxProgressBar.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fileToolStripMenuItem1,
            this.administrationToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(327, 24);
            this.menuStrip1.TabIndex = 0;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // fileToolStripMenuItem1
            // 
            this.fileToolStripMenuItem1.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.openToolStripMenuItem1,
            this.saveToolStripMenuItem1});
            this.fileToolStripMenuItem1.Name = "fileToolStripMenuItem1";
            this.fileToolStripMenuItem1.Size = new System.Drawing.Size(37, 20);
            this.fileToolStripMenuItem1.Text = "&File";
            // 
            // openToolStripMenuItem1
            // 
            this.openToolStripMenuItem1.Name = "openToolStripMenuItem1";
            this.openToolStripMenuItem1.Size = new System.Drawing.Size(152, 22);
            this.openToolStripMenuItem1.Text = "&Open";
            this.openToolStripMenuItem1.Click += new System.EventHandler(this.openToolStripMenuItem_Click);
            // 
            // saveToolStripMenuItem1
            // 
            this.saveToolStripMenuItem1.Name = "saveToolStripMenuItem1";
            this.saveToolStripMenuItem1.Size = new System.Drawing.Size(152, 22);
            this.saveToolStripMenuItem1.Text = "&Save";
            this.saveToolStripMenuItem1.Click += new System.EventHandler(this.saveToolStripMenuItem_Click);
            // 
            // administrationToolStripMenuItem
            // 
            this.administrationToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.registerFileTypeToolStripMenuItem1,
            this.unregisterFileTypeToolStripMenuItem1});
            this.administrationToolStripMenuItem.Name = "administrationToolStripMenuItem";
            this.administrationToolStripMenuItem.Size = new System.Drawing.Size(98, 20);
            this.administrationToolStripMenuItem.Text = "&Administration";
            // 
            // registerFileTypeToolStripMenuItem1
            // 
            this.registerFileTypeToolStripMenuItem1.Name = "registerFileTypeToolStripMenuItem1";
            this.registerFileTypeToolStripMenuItem1.Size = new System.Drawing.Size(178, 22);
            this.registerFileTypeToolStripMenuItem1.Text = "Register File Type";
            this.registerFileTypeToolStripMenuItem1.Click += new System.EventHandler(this.registerFileTypeToolStripMenuItem_Click);
            // 
            // unregisterFileTypeToolStripMenuItem1
            // 
            this.unregisterFileTypeToolStripMenuItem1.Name = "unregisterFileTypeToolStripMenuItem1";
            this.unregisterFileTypeToolStripMenuItem1.Size = new System.Drawing.Size(178, 22);
            this.unregisterFileTypeToolStripMenuItem1.Text = "Unregister File Type";
            this.unregisterFileTypeToolStripMenuItem1.Click += new System.EventHandler(this.unregisterFileTypeToolStripMenuItem_Click);
            // 
            // fileToolStripMenuItem
            // 
            this.fileToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.openToolStripMenuItem,
            this.saveToolStripMenuItem});
            this.fileToolStripMenuItem.Name = "fileToolStripMenuItem";
            this.fileToolStripMenuItem.Size = new System.Drawing.Size(37, 20);
            this.fileToolStripMenuItem.Text = "&File";
            // 
            // openToolStripMenuItem
            // 
            this.openToolStripMenuItem.Name = "openToolStripMenuItem";
            this.openToolStripMenuItem.Size = new System.Drawing.Size(103, 22);
            this.openToolStripMenuItem.Text = "&Open";
            this.openToolStripMenuItem.Click += new System.EventHandler(this.openToolStripMenuItem_Click);
            // 
            // saveToolStripMenuItem
            // 
            this.saveToolStripMenuItem.Name = "saveToolStripMenuItem";
            this.saveToolStripMenuItem.Size = new System.Drawing.Size(103, 22);
            this.saveToolStripMenuItem.Text = "&Save";
            this.saveToolStripMenuItem.Click += new System.EventHandler(this.saveToolStripMenuItem_Click);
            // 
            // administrativeToolStripMenuItem
            // 
            this.administrativeToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.registerFileTypeToolStripMenuItem,
            this.unregisterFileTypeToolStripMenuItem});
            this.administrativeToolStripMenuItem.Name = "administrativeToolStripMenuItem";
            this.administrativeToolStripMenuItem.Size = new System.Drawing.Size(96, 20);
            this.administrativeToolStripMenuItem.Text = "&Administrative";
            // 
            // registerFileTypeToolStripMenuItem
            // 
            this.registerFileTypeToolStripMenuItem.Name = "registerFileTypeToolStripMenuItem";
            this.registerFileTypeToolStripMenuItem.Size = new System.Drawing.Size(178, 22);
            this.registerFileTypeToolStripMenuItem.Text = "&Register File Type";
            this.registerFileTypeToolStripMenuItem.Click += new System.EventHandler(this.registerFileTypeToolStripMenuItem_Click);
            // 
            // unregisterFileTypeToolStripMenuItem
            // 
            this.unregisterFileTypeToolStripMenuItem.Name = "unregisterFileTypeToolStripMenuItem";
            this.unregisterFileTypeToolStripMenuItem.Size = new System.Drawing.Size(178, 22);
            this.unregisterFileTypeToolStripMenuItem.Text = "&Unregister File Type";
            this.unregisterFileTypeToolStripMenuItem.Click += new System.EventHandler(this.unregisterFileTypeToolStripMenuItem_Click);
            // 
            // statusStrip1
            // 
            this.statusStrip1.Location = new System.Drawing.Point(0, 428);
            this.statusStrip1.Name = "statusStrip1";
            this.statusStrip1.Size = new System.Drawing.Size(327, 22);
            this.statusStrip1.TabIndex = 9;
            this.statusStrip1.Text = "statusStrip1";
            // 
            // toolStripStatusLabel1
            // 
            this.toolStripStatusLabel1.Name = "toolStripStatusLabel1";
            this.toolStripStatusLabel1.Size = new System.Drawing.Size(118, 17);
            this.toolStripStatusLabel1.Text = "toolStripStatusLabel1";
            // 
            // timerProgressBar
            // 
            this.timerProgressBar.Interval = 500;
            this.timerProgressBar.Tick += new System.EventHandler(this.timerProgressBar_Tick);
            // 
            // groupBoxKnownCategories
            // 
            this.groupBoxKnownCategories.Controls.Add(this.comboBoxKnownCategoryType);
            this.groupBoxKnownCategories.Controls.Add(this.comboBoxKnownCategoryLocation);
            this.groupBoxKnownCategories.Controls.Add(this.label2);
            this.groupBoxKnownCategories.Controls.Add(this.label1);
            this.groupBoxKnownCategories.Location = new System.Drawing.Point(12, 27);
            this.groupBoxKnownCategories.Name = "groupBoxKnownCategories";
            this.groupBoxKnownCategories.Size = new System.Drawing.Size(305, 81);
            this.groupBoxKnownCategories.TabIndex = 7;
            this.groupBoxKnownCategories.TabStop = false;
            this.groupBoxKnownCategories.Text = "Known Categories";
            // 
            // comboBoxKnownCategoryType
            // 
            this.comboBoxKnownCategoryType.FormattingEnabled = true;
            this.comboBoxKnownCategoryType.Items.AddRange(new object[] {
            "None",
            "Recent",
            "Frequent"});
            this.comboBoxKnownCategoryType.Location = new System.Drawing.Point(5, 37);
            this.comboBoxKnownCategoryType.Name = "comboBoxKnownCategoryType";
            this.comboBoxKnownCategoryType.Size = new System.Drawing.Size(121, 21);
            this.comboBoxKnownCategoryType.TabIndex = 11;
            this.comboBoxKnownCategoryType.SelectedIndexChanged += new System.EventHandler(this.comboBoxKnownCategoryType_SelectedIndexChanged);
            // 
            // comboBoxKnownCategoryLocation
            // 
            this.comboBoxKnownCategoryLocation.FormattingEnabled = true;
            this.comboBoxKnownCategoryLocation.Items.AddRange(new object[] {
            "Top",
            "Bottom"});
            this.comboBoxKnownCategoryLocation.Location = new System.Drawing.Point(156, 37);
            this.comboBoxKnownCategoryLocation.Name = "comboBoxKnownCategoryLocation";
            this.comboBoxKnownCategoryLocation.Size = new System.Drawing.Size(121, 21);
            this.comboBoxKnownCategoryLocation.TabIndex = 10;
            this.comboBoxKnownCategoryLocation.SelectedIndexChanged += new System.EventHandler(this.comboBoxKnownCategoryLocation_SelectedIndexChanged);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(5, 21);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(37, 13);
            this.label2.TabIndex = 9;
            this.label2.Text = "Show:";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(153, 20);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(51, 13);
            this.label1.TabIndex = 7;
            this.label1.Text = "Location:";
            // 
            // groupBoxIconOverlay
            // 
            this.groupBoxIconOverlay.Controls.Add(this.labelNoIconOverlay);
            this.groupBoxIconOverlay.Controls.Add(this.pictureIconOverlay3);
            this.groupBoxIconOverlay.Controls.Add(this.pictureIconOverlay2);
            this.groupBoxIconOverlay.Controls.Add(this.label7);
            this.groupBoxIconOverlay.Controls.Add(this.pictureIconOverlay1);
            this.groupBoxIconOverlay.Location = new System.Drawing.Point(13, 317);
            this.groupBoxIconOverlay.Name = "groupBoxIconOverlay";
            this.groupBoxIconOverlay.Size = new System.Drawing.Size(305, 100);
            this.groupBoxIconOverlay.TabIndex = 11;
            this.groupBoxIconOverlay.TabStop = false;
            this.groupBoxIconOverlay.Text = "Icon Overlay";
            // 
            // labelNoIconOverlay
            // 
            this.labelNoIconOverlay.Location = new System.Drawing.Point(9, 50);
            this.labelNoIconOverlay.Name = "labelNoIconOverlay";
            this.labelNoIconOverlay.Size = new System.Drawing.Size(35, 13);
            this.labelNoIconOverlay.TabIndex = 0;
            this.labelNoIconOverlay.Text = "None";
            this.labelNoIconOverlay.Click += new System.EventHandler(this.labelNoIconOverlay_Click);
            // 
            // pictureIconOverlay3
            // 
            this.pictureIconOverlay3.Image = ((System.Drawing.Image)(resources.GetObject("pictureIconOverlay3.Image")));
            this.pictureIconOverlay3.Location = new System.Drawing.Point(126, 41);
            this.pictureIconOverlay3.Name = "pictureIconOverlay3";
            this.pictureIconOverlay3.Size = new System.Drawing.Size(32, 32);
            this.pictureIconOverlay3.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureIconOverlay3.TabIndex = 3;
            this.pictureIconOverlay3.TabStop = false;
            this.pictureIconOverlay3.Click += new System.EventHandler(this.pictureIconOverlay3_Click);
            // 
            // pictureIconOverlay2
            // 
            this.pictureIconOverlay2.Image = ((System.Drawing.Image)(resources.GetObject("pictureIconOverlay2.Image")));
            this.pictureIconOverlay2.Location = new System.Drawing.Point(88, 41);
            this.pictureIconOverlay2.Name = "pictureIconOverlay2";
            this.pictureIconOverlay2.Size = new System.Drawing.Size(32, 32);
            this.pictureIconOverlay2.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureIconOverlay2.TabIndex = 2;
            this.pictureIconOverlay2.TabStop = false;
            this.pictureIconOverlay2.Click += new System.EventHandler(this.pictureIconOverlay2_Click);
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(9, 20);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(209, 13);
            this.label7.TabIndex = 1;
            this.label7.Text = "Select an image to overlay on the task bar:";
            // 
            // pictureIconOverlay1
            // 
            this.pictureIconOverlay1.Image = ((System.Drawing.Image)(resources.GetObject("pictureIconOverlay1.Image")));
            this.pictureIconOverlay1.Location = new System.Drawing.Point(50, 41);
            this.pictureIconOverlay1.Name = "pictureIconOverlay1";
            this.pictureIconOverlay1.Size = new System.Drawing.Size(32, 32);
            this.pictureIconOverlay1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureIconOverlay1.TabIndex = 0;
            this.pictureIconOverlay1.TabStop = false;
            this.pictureIconOverlay1.Click += new System.EventHandler(this.pictureIconOverlay1_Click);
            // 
            // groupBoxCustomCategories
            // 
            this.groupBoxCustomCategories.Controls.Add(this.buttonCategoryOneRename);
            this.groupBoxCustomCategories.Controls.Add(this.label5);
            this.groupBoxCustomCategories.Controls.Add(this.label4);
            this.groupBoxCustomCategories.Controls.Add(this.label3);
            this.groupBoxCustomCategories.Controls.Add(this.buttonCategoryTwoAddLink);
            this.groupBoxCustomCategories.Controls.Add(this.buttonCategoryOneAddLink);
            this.groupBoxCustomCategories.Controls.Add(this.buttonUserTasksAddTasks);
            this.groupBoxCustomCategories.Location = new System.Drawing.Point(13, 115);
            this.groupBoxCustomCategories.Name = "groupBoxCustomCategories";
            this.groupBoxCustomCategories.Size = new System.Drawing.Size(304, 104);
            this.groupBoxCustomCategories.TabIndex = 8;
            this.groupBoxCustomCategories.TabStop = false;
            this.groupBoxCustomCategories.Text = "Custom Categories";
            // 
            // buttonCategoryOneRename
            // 
            this.buttonCategoryOneRename.Location = new System.Drawing.Point(207, 16);
            this.buttonCategoryOneRename.Name = "buttonCategoryOneRename";
            this.buttonCategoryOneRename.Size = new System.Drawing.Size(88, 23);
            this.buttonCategoryOneRename.TabIndex = 10;
            this.buttonCategoryOneRename.Text = "Change Name";
            this.buttonCategoryOneRename.UseVisualStyleBackColor = true;
            this.buttonCategoryOneRename.Click += new System.EventHandler(this.buttonCategoryOneRename_Click);
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(8, 79);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(64, 13);
            this.label5.TabIndex = 8;
            this.label5.Text = "User Tasks:";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(8, 50);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(99, 13);
            this.label4.TabIndex = 7;
            this.label4.Text = "Custom Category 2:";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(8, 21);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(99, 13);
            this.label3.TabIndex = 6;
            this.label3.Text = "Custom Category 1:";
            // 
            // buttonCategoryTwoAddLink
            // 
            this.buttonCategoryTwoAddLink.Location = new System.Drawing.Point(113, 45);
            this.buttonCategoryTwoAddLink.Name = "buttonCategoryTwoAddLink";
            this.buttonCategoryTwoAddLink.Size = new System.Drawing.Size(88, 23);
            this.buttonCategoryTwoAddLink.TabIndex = 4;
            this.buttonCategoryTwoAddLink.Text = "Add Link";
            this.buttonCategoryTwoAddLink.UseVisualStyleBackColor = true;
            this.buttonCategoryTwoAddLink.Click += new System.EventHandler(this.buttonCategoryTwoAddLink_Click);
            // 
            // buttonCategoryOneAddLink
            // 
            this.buttonCategoryOneAddLink.Location = new System.Drawing.Point(113, 16);
            this.buttonCategoryOneAddLink.Name = "buttonCategoryOneAddLink";
            this.buttonCategoryOneAddLink.Size = new System.Drawing.Size(88, 23);
            this.buttonCategoryOneAddLink.TabIndex = 3;
            this.buttonCategoryOneAddLink.Text = "Add Link";
            this.buttonCategoryOneAddLink.UseVisualStyleBackColor = true;
            this.buttonCategoryOneAddLink.Click += new System.EventHandler(this.buttonCategoryOneAddLink_Click);
            // 
            // buttonUserTasksAddTasks
            // 
            this.buttonUserTasksAddTasks.Location = new System.Drawing.Point(113, 74);
            this.buttonUserTasksAddTasks.Name = "buttonUserTasksAddTasks";
            this.buttonUserTasksAddTasks.Size = new System.Drawing.Size(88, 23);
            this.buttonUserTasksAddTasks.TabIndex = 5;
            this.buttonUserTasksAddTasks.Text = "Add Tasks";
            this.buttonUserTasksAddTasks.UseVisualStyleBackColor = true;
            this.buttonUserTasksAddTasks.Click += new System.EventHandler(this.buttonUserTasksAddTasks_Click);
            // 
            // groupBoxProgressBar
            // 
            this.groupBoxProgressBar.Controls.Add(this.label6);
            this.groupBoxProgressBar.Controls.Add(this.comboBoxProgressBarStates);
            this.groupBoxProgressBar.Controls.Add(this.buttonProgressBarToggle);
            this.groupBoxProgressBar.Controls.Add(this.progressBar1);
            this.groupBoxProgressBar.Location = new System.Drawing.Point(13, 225);
            this.groupBoxProgressBar.Name = "groupBoxProgressBar";
            this.groupBoxProgressBar.Size = new System.Drawing.Size(305, 81);
            this.groupBoxProgressBar.TabIndex = 10;
            this.groupBoxProgressBar.TabStop = false;
            this.groupBoxProgressBar.Text = "Progress Bar";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(6, 25);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(35, 13);
            this.label6.TabIndex = 3;
            this.label6.Text = "State:";
            // 
            // comboBoxProgressBarStates
            // 
            this.comboBoxProgressBarStates.FormattingEnabled = true;
            this.comboBoxProgressBarStates.Location = new System.Drawing.Point(47, 22);
            this.comboBoxProgressBarStates.Name = "comboBoxProgressBarStates";
            this.comboBoxProgressBarStates.Size = new System.Drawing.Size(121, 21);
            this.comboBoxProgressBarStates.TabIndex = 2;
            this.comboBoxProgressBarStates.SelectedIndexChanged += new System.EventHandler(this.comboBoxProgressStates_SelectedIndexChanged);
            // 
            // buttonProgressBarToggle
            // 
            this.buttonProgressBarToggle.Location = new System.Drawing.Point(184, 20);
            this.buttonProgressBarToggle.Name = "buttonProgressBarToggle";
            this.buttonProgressBarToggle.Size = new System.Drawing.Size(115, 23);
            this.buttonProgressBarToggle.TabIndex = 1;
            this.buttonProgressBarToggle.Text = "Start";
            this.buttonProgressBarToggle.UseVisualStyleBackColor = true;
            this.buttonProgressBarToggle.Click += new System.EventHandler(this.buttonProgressBarToggle_Click);
            // 
            // progressBar1
            // 
            this.progressBar1.Location = new System.Drawing.Point(9, 49);
            this.progressBar1.Name = "progressBar1";
            this.progressBar1.Size = new System.Drawing.Size(292, 23);
            this.progressBar1.Step = 5;
            this.progressBar1.TabIndex = 0;
            // 
            // TaskbarDemoMainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(327, 450);
            this.Controls.Add(this.groupBoxKnownCategories);
            this.Controls.Add(this.groupBoxIconOverlay);
            this.Controls.Add(this.groupBoxCustomCategories);
            this.Controls.Add(this.statusStrip1);
            this.Controls.Add(this.groupBoxProgressBar);
            this.Controls.Add(this.menuStrip1);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "TaskbarDemoMainForm";
            this.Text = "Taskbar Demo";
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.groupBoxKnownCategories.ResumeLayout(false);
            this.groupBoxKnownCategories.PerformLayout();
            this.groupBoxIconOverlay.ResumeLayout(false);
            this.groupBoxIconOverlay.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureIconOverlay3)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureIconOverlay2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureIconOverlay1)).EndInit();
            this.groupBoxCustomCategories.ResumeLayout(false);
            this.groupBoxCustomCategories.PerformLayout();
            this.groupBoxProgressBar.ResumeLayout(false);
            this.groupBoxProgressBar.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem fileToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem openToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem saveToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem administrativeToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem registerFileTypeToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem unregisterFileTypeToolStripMenuItem;
        private System.Windows.Forms.StatusStrip statusStrip1;
        private System.Windows.Forms.ToolStripStatusLabel toolStripStatusLabel1;
        private System.Windows.Forms.Timer timerProgressBar;
        private System.Windows.Forms.GroupBox groupBoxKnownCategories;
        private System.Windows.Forms.ComboBox comboBoxKnownCategoryLocation;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.GroupBox groupBoxIconOverlay;
        private System.Windows.Forms.Label labelNoIconOverlay;
        private System.Windows.Forms.PictureBox pictureIconOverlay3;
        private System.Windows.Forms.PictureBox pictureIconOverlay2;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.PictureBox pictureIconOverlay1;
        private System.Windows.Forms.GroupBox groupBoxCustomCategories;
        private System.Windows.Forms.Button buttonCategoryOneRename;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Button buttonCategoryTwoAddLink;
        private System.Windows.Forms.Button buttonCategoryOneAddLink;
        private System.Windows.Forms.Button buttonUserTasksAddTasks;
        private System.Windows.Forms.GroupBox groupBoxProgressBar;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.ComboBox comboBoxProgressBarStates;
        private System.Windows.Forms.Button buttonProgressBarToggle;
        private System.Windows.Forms.ProgressBar progressBar1;
        private System.Windows.Forms.ComboBox comboBoxKnownCategoryType;
        private System.Windows.Forms.ToolStripMenuItem fileToolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem openToolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem saveToolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem administrationToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem registerFileTypeToolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem unregisterFileTypeToolStripMenuItem1;
    }
}

