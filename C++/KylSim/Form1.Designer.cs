namespace KylSim
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
            this.components = new System.ComponentModel.Container();
            this.Update_Dynamik_Summaflode = new System.Windows.Forms.Timer(this.components);
            this.contextMenuStrip1 = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.öppnaToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.stängToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.contextMenuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // Update_Dynamik_Summaflode
            // 
            this.Update_Dynamik_Summaflode.Enabled = true;
            this.Update_Dynamik_Summaflode.Interval = 500;
            this.Update_Dynamik_Summaflode.Tick += new System.EventHandler(this.Update_Dynamik_Summaflode_Tick);
            // 
            // contextMenuStrip1
            // 
            this.contextMenuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.öppnaToolStripMenuItem,
            this.stängToolStripMenuItem});
            this.contextMenuStrip1.Name = "contextMenuStrip1";
            this.contextMenuStrip1.Size = new System.Drawing.Size(153, 70);
            this.contextMenuStrip1.Opening += new System.ComponentModel.CancelEventHandler(this.contextMenuStrip1_Opening);
            // 
            // öppnaToolStripMenuItem
            // 
            this.öppnaToolStripMenuItem.Name = "öppnaToolStripMenuItem";
            this.öppnaToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.öppnaToolStripMenuItem.Text = "Öppna";
            this.öppnaToolStripMenuItem.Click += new System.EventHandler(this.öppnaToolStripMenuItem_Click);
            // 
            // stängToolStripMenuItem
            // 
            this.stängToolStripMenuItem.Name = "stängToolStripMenuItem";
            this.stängToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.stängToolStripMenuItem.Text = "Stäng";
            this.stängToolStripMenuItem.Click += new System.EventHandler(this.stängToolStripMenuItem_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.Gainsboro;
            this.ClientSize = new System.Drawing.Size(624, 442);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Name = "Form1";
            this.Text = "Kylsystem av Simon Berntsson";
            this.Paint += new System.Windows.Forms.PaintEventHandler(this.Form1_Paint);
            this.MouseDown += new System.Windows.Forms.MouseEventHandler(this.Form1_MouseDown);
            this.contextMenuStrip1.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Timer Update_Dynamik_Summaflode;
        private System.Windows.Forms.ContextMenuStrip contextMenuStrip1;
        private System.Windows.Forms.ToolStripMenuItem öppnaToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem stängToolStripMenuItem;
    }
}

