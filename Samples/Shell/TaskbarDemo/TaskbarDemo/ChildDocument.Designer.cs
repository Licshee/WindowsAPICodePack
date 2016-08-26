namespace TaskbarDemo
{
    partial class ChildDocument
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
            this.groupBoxProgressBar = new System.Windows.Forms.GroupBox();
            this.label6 = new System.Windows.Forms.Label();
            this.comboBoxProgressBarStates = new System.Windows.Forms.ComboBox();
            this.buttonProgressBarToggle = new System.Windows.Forms.Button();
            this.progressBar1 = new System.Windows.Forms.ProgressBar();
            this.timerProgressBar = new System.Windows.Forms.Timer(this.components);
            this.groupBoxProgressBar.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBoxProgressBar
            // 
            this.groupBoxProgressBar.Controls.Add(this.label6);
            this.groupBoxProgressBar.Controls.Add(this.comboBoxProgressBarStates);
            this.groupBoxProgressBar.Controls.Add(this.buttonProgressBarToggle);
            this.groupBoxProgressBar.Controls.Add(this.progressBar1);
            this.groupBoxProgressBar.Location = new System.Drawing.Point(12, 12);
            this.groupBoxProgressBar.Name = "groupBoxProgressBar";
            this.groupBoxProgressBar.Size = new System.Drawing.Size(305, 81);
            this.groupBoxProgressBar.TabIndex = 11;
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
            this.comboBoxProgressBarStates.SelectedIndexChanged += new System.EventHandler(this.comboBoxProgressBarStates_SelectedIndexChanged);
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
            // timerProgressBar
            // 
            this.timerProgressBar.Interval = 500;
            this.timerProgressBar.Tick += new System.EventHandler(this.timerProgressBar_Tick);
            // 
            // ChildDocument
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(322, 108);
            this.Controls.Add(this.groupBoxProgressBar);
            this.Name = "ChildDocument";
            this.Text = "Child Document Window";
            this.groupBoxProgressBar.ResumeLayout(false);
            this.groupBoxProgressBar.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBoxProgressBar;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.ComboBox comboBoxProgressBarStates;
        private System.Windows.Forms.Button buttonProgressBarToggle;
        private System.Windows.Forms.ProgressBar progressBar1;
        private System.Windows.Forms.Timer timerProgressBar;
    }
}