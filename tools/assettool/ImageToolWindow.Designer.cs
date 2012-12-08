namespace scott.forge.editor
{
    partial class ImageToolWindow
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose( bool disposing )
        {
            if ( disposing && ( components != null ) )
            {
                components.Dispose();
            }
            base.Dispose( disposing );
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager( typeof( ImageToolWindow ) );
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.fileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.openToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.exportToFormatToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripMenuItem1 = new System.Windows.Forms.ToolStripSeparator();
            this.exitToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.splitContainer = new System.Windows.Forms.SplitContainer();
            this.imageView = new System.Windows.Forms.PictureBox();
            this.imageProperties = new System.Windows.Forms.PropertyGrid();
            this.openImageFileDialog = new System.Windows.Forms.OpenFileDialog();
            this.saveImageDialog = new System.Windows.Forms.SaveFileDialog();
            this.menuStrip1.SuspendLayout();
            ( (System.ComponentModel.ISupportInitialize) ( this.splitContainer ) ).BeginInit();
            this.splitContainer.Panel1.SuspendLayout();
            this.splitContainer.Panel2.SuspendLayout();
            this.splitContainer.SuspendLayout();
            ( (System.ComponentModel.ISupportInitialize) ( this.imageView ) ).BeginInit();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange( new System.Windows.Forms.ToolStripItem[] {
            this.fileToolStripMenuItem} );
            this.menuStrip1.Location = new System.Drawing.Point( 0, 0 );
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size( 572, 24 );
            this.menuStrip1.TabIndex = 0;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // fileToolStripMenuItem
            // 
            this.fileToolStripMenuItem.DropDownItems.AddRange( new System.Windows.Forms.ToolStripItem[] {
            this.openToolStripMenuItem,
            this.exportToFormatToolStripMenuItem,
            this.toolStripMenuItem1,
            this.exitToolStripMenuItem} );
            this.fileToolStripMenuItem.Name = "fileToolStripMenuItem";
            this.fileToolStripMenuItem.Size = new System.Drawing.Size( 37, 20 );
            this.fileToolStripMenuItem.Text = "&File";
            // 
            // openToolStripMenuItem
            // 
            this.openToolStripMenuItem.Name = "openToolStripMenuItem";
            this.openToolStripMenuItem.ShortcutKeyDisplayString = "Ctrl+O";
            this.openToolStripMenuItem.ShortcutKeys = ( (System.Windows.Forms.Keys) ( ( System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.O ) ) );
            this.openToolStripMenuItem.Size = new System.Drawing.Size( 200, 22 );
            this.openToolStripMenuItem.Text = "Open";
            this.openToolStripMenuItem.Click += new System.EventHandler( this.openToolStripMenuItem_Click );
            // 
            // exportToFormatToolStripMenuItem
            // 
            this.exportToFormatToolStripMenuItem.Name = "exportToFormatToolStripMenuItem";
            this.exportToFormatToolStripMenuItem.ShortcutKeys = ( (System.Windows.Forms.Keys) ( ( System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.S ) ) );
            this.exportToFormatToolStripMenuItem.Size = new System.Drawing.Size( 200, 22 );
            this.exportToFormatToolStripMenuItem.Text = "Export to format";
            this.exportToFormatToolStripMenuItem.Click += new System.EventHandler( this.exportToFormatToolStripMenuItem_Click );
            // 
            // toolStripMenuItem1
            // 
            this.toolStripMenuItem1.Name = "toolStripMenuItem1";
            this.toolStripMenuItem1.Size = new System.Drawing.Size( 197, 6 );
            // 
            // exitToolStripMenuItem
            // 
            this.exitToolStripMenuItem.Name = "exitToolStripMenuItem";
            this.exitToolStripMenuItem.ShortcutKeys = ( (System.Windows.Forms.Keys) ( ( System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.Q ) ) );
            this.exitToolStripMenuItem.Size = new System.Drawing.Size( 200, 22 );
            this.exitToolStripMenuItem.Text = "E&xit";
            // 
            // splitContainer
            // 
            this.splitContainer.Dock = System.Windows.Forms.DockStyle.Fill;
            this.splitContainer.Location = new System.Drawing.Point( 0, 24 );
            this.splitContainer.Name = "splitContainer";
            // 
            // splitContainer.Panel1
            // 
            this.splitContainer.Panel1.AutoScroll = true;
            this.splitContainer.Panel1.Controls.Add( this.imageView );
            // 
            // splitContainer.Panel2
            // 
            this.splitContainer.Panel2.Controls.Add( this.imageProperties );
            this.splitContainer.Size = new System.Drawing.Size( 572, 443 );
            this.splitContainer.SplitterDistance = 376;
            this.splitContainer.TabIndex = 1;
            // 
            // imageView
            // 
            this.imageView.BackColor = System.Drawing.SystemColors.ControlDark;
            this.imageView.Location = new System.Drawing.Point( 3, 3 );
            this.imageView.Name = "imageView";
            this.imageView.Size = new System.Drawing.Size( 370, 437 );
            this.imageView.SizeMode = System.Windows.Forms.PictureBoxSizeMode.AutoSize;
            this.imageView.TabIndex = 0;
            this.imageView.TabStop = false;
            // 
            // imageProperties
            // 
            this.imageProperties.Anchor = ( (System.Windows.Forms.AnchorStyles) ( ( ( ( System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom )
                        | System.Windows.Forms.AnchorStyles.Left )
                        | System.Windows.Forms.AnchorStyles.Right ) ) );
            this.imageProperties.Location = new System.Drawing.Point( 3, 3 );
            this.imageProperties.Name = "imageProperties";
            this.imageProperties.Size = new System.Drawing.Size( 186, 437 );
            this.imageProperties.TabIndex = 0;
            // 
            // openImageFileDialog
            // 
            this.openImageFileDialog.Filter = resources.GetString( "openImageFileDialog.Filter" );
            this.openImageFileDialog.Title = "Open Image";
            this.openImageFileDialog.FileOk += new System.ComponentModel.CancelEventHandler( this.openImageFileDialog_FileOk );
            // 
            // saveImageDialog
            // 
            this.saveImageDialog.DefaultExt = "texture";
            this.saveImageDialog.Filter = "Forge Texture (*.texture)|*.texture";
            this.saveImageDialog.Title = "Export to file";
            // 
            // ImageToolWindow
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF( 6F, 13F );
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size( 572, 467 );
            this.Controls.Add( this.splitContainer );
            this.Controls.Add( this.menuStrip1 );
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "ImageToolWindow";
            this.Text = "Image Tool";
            this.menuStrip1.ResumeLayout( false );
            this.menuStrip1.PerformLayout();
            this.splitContainer.Panel1.ResumeLayout( false );
            this.splitContainer.Panel1.PerformLayout();
            this.splitContainer.Panel2.ResumeLayout( false );
            ( (System.ComponentModel.ISupportInitialize) ( this.splitContainer ) ).EndInit();
            this.splitContainer.ResumeLayout( false );
            ( (System.ComponentModel.ISupportInitialize) ( this.imageView ) ).EndInit();
            this.ResumeLayout( false );
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem fileToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem openToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem exportToFormatToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem exitToolStripMenuItem;
        private System.Windows.Forms.SplitContainer splitContainer;
        private System.Windows.Forms.PictureBox imageView;
        private System.Windows.Forms.PropertyGrid imageProperties;
        private System.Windows.Forms.OpenFileDialog openImageFileDialog;
        private System.Windows.Forms.SaveFileDialog saveImageDialog;
    }
}