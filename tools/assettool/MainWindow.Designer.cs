namespace scott.forge.editor
{
    partial class MainWindow
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
            this.components = new System.ComponentModel.Container();
            this.appMainMenu = new System.Windows.Forms.MenuStrip();
            this.fileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.newToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripMenuItem1 = new System.Windows.Forms.ToolStripSeparator();
            this.openAssetDatabaseToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.saveAssetDatabaseToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.saveCopyToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripMenuItem2 = new System.Windows.Forms.ToolStripSeparator();
            this.exitToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.editToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.undoToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.redoToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripMenuItem3 = new System.Windows.Forms.ToolStripSeparator();
            this.cutToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.copyToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.pasteToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.deleteToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripMenuItem4 = new System.Windows.Forms.ToolStripSeparator();
            this.selectAllToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.imageToolToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.helpToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.viewHelpToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripMenuItem5 = new System.Windows.Forms.ToolStripSeparator();
            this.aboutToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.statusStrip1 = new System.Windows.Forms.StatusStrip();
            this.appResourcesSplitPanel = new System.Windows.Forms.SplitContainer();
            this.appPropertyGrid = new System.Windows.Forms.PropertyGrid();
            this.appBundleRootMenu = new System.Windows.Forms.ContextMenuStrip( this.components );
            this.newBundleToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.newAttributionToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripMenuItem6 = new System.Windows.Forms.ToolStripSeparator();
            this.editItemToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripMenuItem7 = new System.Windows.Forms.ToolStripSeparator();
            this.deleteToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripMenuItem8 = new System.Windows.Forms.ToolStripSeparator();
            this.refreshViewToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.resourceSaveDialog = new System.Windows.Forms.SaveFileDialog();
            this.resourceOpenDialog = new System.Windows.Forms.OpenFileDialog();
            this.appStausLabel = new System.Windows.Forms.Label();
            this.mEditorTabs = new System.Windows.Forms.TabControl();
            this.mResourcesTabPage = new System.Windows.Forms.TabPage();
            this.mBundlesTabPage = new System.Windows.Forms.TabPage();
            this.mAttributionsTabPage = new System.Windows.Forms.TabPage();
            this.mResourcesListView = new System.Windows.Forms.ListView();
            this.mBundlesListView = new System.Windows.Forms.ListView();
            this.appMainMenu.SuspendLayout();
            ( (System.ComponentModel.ISupportInitialize) ( this.appResourcesSplitPanel ) ).BeginInit();
            this.appResourcesSplitPanel.Panel1.SuspendLayout();
            this.appResourcesSplitPanel.Panel2.SuspendLayout();
            this.appResourcesSplitPanel.SuspendLayout();
            this.appBundleRootMenu.SuspendLayout();
            this.mEditorTabs.SuspendLayout();
            this.mResourcesTabPage.SuspendLayout();
            this.mBundlesTabPage.SuspendLayout();
            this.SuspendLayout();
            // 
            // appMainMenu
            // 
            this.appMainMenu.Items.AddRange( new System.Windows.Forms.ToolStripItem[] {
            this.fileToolStripMenuItem,
            this.editToolStripMenuItem,
            this.toolsToolStripMenuItem,
            this.helpToolStripMenuItem} );
            this.appMainMenu.Location = new System.Drawing.Point( 0, 0 );
            this.appMainMenu.Name = "appMainMenu";
            this.appMainMenu.Size = new System.Drawing.Size( 623, 24 );
            this.appMainMenu.TabIndex = 0;
            this.appMainMenu.Text = "menuStrip1";
            // 
            // fileToolStripMenuItem
            // 
            this.fileToolStripMenuItem.DropDownItems.AddRange( new System.Windows.Forms.ToolStripItem[] {
            this.newToolStripMenuItem,
            this.toolStripMenuItem1,
            this.openAssetDatabaseToolStripMenuItem,
            this.saveAssetDatabaseToolStripMenuItem,
            this.saveCopyToolStripMenuItem,
            this.toolStripMenuItem2,
            this.exitToolStripMenuItem} );
            this.fileToolStripMenuItem.Name = "fileToolStripMenuItem";
            this.fileToolStripMenuItem.Size = new System.Drawing.Size( 37, 20 );
            this.fileToolStripMenuItem.Text = "&File";
            // 
            // newToolStripMenuItem
            // 
            this.newToolStripMenuItem.Name = "newToolStripMenuItem";
            this.newToolStripMenuItem.ShortcutKeys = ( (System.Windows.Forms.Keys) ( ( System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.N ) ) );
            this.newToolStripMenuItem.Size = new System.Drawing.Size( 152, 22 );
            this.newToolStripMenuItem.Text = "New";
            // 
            // toolStripMenuItem1
            // 
            this.toolStripMenuItem1.Name = "toolStripMenuItem1";
            this.toolStripMenuItem1.Size = new System.Drawing.Size( 149, 6 );
            // 
            // openAssetDatabaseToolStripMenuItem
            // 
            this.openAssetDatabaseToolStripMenuItem.Name = "openAssetDatabaseToolStripMenuItem";
            this.openAssetDatabaseToolStripMenuItem.ShortcutKeys = ( (System.Windows.Forms.Keys) ( ( System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.O ) ) );
            this.openAssetDatabaseToolStripMenuItem.Size = new System.Drawing.Size( 152, 22 );
            this.openAssetDatabaseToolStripMenuItem.Text = "Open";
            this.openAssetDatabaseToolStripMenuItem.Click += new System.EventHandler( this.openAssetDatabaseToolStripMenuItem_Click );
            // 
            // saveAssetDatabaseToolStripMenuItem
            // 
            this.saveAssetDatabaseToolStripMenuItem.Name = "saveAssetDatabaseToolStripMenuItem";
            this.saveAssetDatabaseToolStripMenuItem.ShortcutKeys = ( (System.Windows.Forms.Keys) ( ( System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.S ) ) );
            this.saveAssetDatabaseToolStripMenuItem.Size = new System.Drawing.Size( 152, 22 );
            this.saveAssetDatabaseToolStripMenuItem.Text = "Save";
            this.saveAssetDatabaseToolStripMenuItem.Click += new System.EventHandler( this.saveAssetDatabaseToolStripMenuItem_Click );
            // 
            // saveCopyToolStripMenuItem
            // 
            this.saveCopyToolStripMenuItem.Name = "saveCopyToolStripMenuItem";
            this.saveCopyToolStripMenuItem.Size = new System.Drawing.Size( 152, 22 );
            this.saveCopyToolStripMenuItem.Text = "Save Copy";
            // 
            // toolStripMenuItem2
            // 
            this.toolStripMenuItem2.Name = "toolStripMenuItem2";
            this.toolStripMenuItem2.Size = new System.Drawing.Size( 149, 6 );
            // 
            // exitToolStripMenuItem
            // 
            this.exitToolStripMenuItem.Name = "exitToolStripMenuItem";
            this.exitToolStripMenuItem.Size = new System.Drawing.Size( 152, 22 );
            this.exitToolStripMenuItem.Text = "E&xit";
            this.exitToolStripMenuItem.Click += new System.EventHandler( this.exitToolStripMenuItem_Click );
            // 
            // editToolStripMenuItem
            // 
            this.editToolStripMenuItem.DropDownItems.AddRange( new System.Windows.Forms.ToolStripItem[] {
            this.undoToolStripMenuItem,
            this.redoToolStripMenuItem,
            this.toolStripMenuItem3,
            this.cutToolStripMenuItem,
            this.copyToolStripMenuItem,
            this.pasteToolStripMenuItem,
            this.deleteToolStripMenuItem,
            this.toolStripMenuItem4,
            this.selectAllToolStripMenuItem} );
            this.editToolStripMenuItem.Name = "editToolStripMenuItem";
            this.editToolStripMenuItem.Size = new System.Drawing.Size( 39, 20 );
            this.editToolStripMenuItem.Text = "&Edit";
            // 
            // undoToolStripMenuItem
            // 
            this.undoToolStripMenuItem.Name = "undoToolStripMenuItem";
            this.undoToolStripMenuItem.ShortcutKeys = ( (System.Windows.Forms.Keys) ( ( System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.Z ) ) );
            this.undoToolStripMenuItem.Size = new System.Drawing.Size( 164, 22 );
            this.undoToolStripMenuItem.Text = "&Undo";
            // 
            // redoToolStripMenuItem
            // 
            this.redoToolStripMenuItem.Name = "redoToolStripMenuItem";
            this.redoToolStripMenuItem.ShortcutKeys = ( (System.Windows.Forms.Keys) ( ( System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.Y ) ) );
            this.redoToolStripMenuItem.Size = new System.Drawing.Size( 164, 22 );
            this.redoToolStripMenuItem.Text = "&Redo";
            // 
            // toolStripMenuItem3
            // 
            this.toolStripMenuItem3.Name = "toolStripMenuItem3";
            this.toolStripMenuItem3.Size = new System.Drawing.Size( 161, 6 );
            // 
            // cutToolStripMenuItem
            // 
            this.cutToolStripMenuItem.Name = "cutToolStripMenuItem";
            this.cutToolStripMenuItem.ShortcutKeys = ( (System.Windows.Forms.Keys) ( ( System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.X ) ) );
            this.cutToolStripMenuItem.Size = new System.Drawing.Size( 164, 22 );
            this.cutToolStripMenuItem.Text = "C&ut";
            // 
            // copyToolStripMenuItem
            // 
            this.copyToolStripMenuItem.Name = "copyToolStripMenuItem";
            this.copyToolStripMenuItem.ShortcutKeys = ( (System.Windows.Forms.Keys) ( ( System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.C ) ) );
            this.copyToolStripMenuItem.Size = new System.Drawing.Size( 164, 22 );
            this.copyToolStripMenuItem.Text = "&Copy";
            // 
            // pasteToolStripMenuItem
            // 
            this.pasteToolStripMenuItem.Name = "pasteToolStripMenuItem";
            this.pasteToolStripMenuItem.ShortcutKeys = ( (System.Windows.Forms.Keys) ( ( System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.V ) ) );
            this.pasteToolStripMenuItem.Size = new System.Drawing.Size( 164, 22 );
            this.pasteToolStripMenuItem.Text = "&Paste";
            // 
            // deleteToolStripMenuItem
            // 
            this.deleteToolStripMenuItem.Name = "deleteToolStripMenuItem";
            this.deleteToolStripMenuItem.ShortcutKeys = System.Windows.Forms.Keys.Delete;
            this.deleteToolStripMenuItem.Size = new System.Drawing.Size( 164, 22 );
            this.deleteToolStripMenuItem.Text = "&Delete";
            // 
            // toolStripMenuItem4
            // 
            this.toolStripMenuItem4.Name = "toolStripMenuItem4";
            this.toolStripMenuItem4.Size = new System.Drawing.Size( 161, 6 );
            // 
            // selectAllToolStripMenuItem
            // 
            this.selectAllToolStripMenuItem.Name = "selectAllToolStripMenuItem";
            this.selectAllToolStripMenuItem.ShortcutKeys = ( (System.Windows.Forms.Keys) ( ( System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.A ) ) );
            this.selectAllToolStripMenuItem.Size = new System.Drawing.Size( 164, 22 );
            this.selectAllToolStripMenuItem.Text = "Select &All";
            // 
            // toolsToolStripMenuItem
            // 
            this.toolsToolStripMenuItem.DropDownItems.AddRange( new System.Windows.Forms.ToolStripItem[] {
            this.imageToolToolStripMenuItem} );
            this.toolsToolStripMenuItem.Name = "toolsToolStripMenuItem";
            this.toolsToolStripMenuItem.Size = new System.Drawing.Size( 48, 20 );
            this.toolsToolStripMenuItem.Text = "&Tools";
            // 
            // imageToolToolStripMenuItem
            // 
            this.imageToolToolStripMenuItem.Name = "imageToolToolStripMenuItem";
            this.imageToolToolStripMenuItem.ShortcutKeyDisplayString = "F2";
            this.imageToolToolStripMenuItem.ShortcutKeys = System.Windows.Forms.Keys.F2;
            this.imageToolToolStripMenuItem.Size = new System.Drawing.Size( 153, 22 );
            this.imageToolToolStripMenuItem.Text = "Image Tool";
            this.imageToolToolStripMenuItem.Click += new System.EventHandler( this.imageToolToolStripMenuItem_Click );
            // 
            // helpToolStripMenuItem
            // 
            this.helpToolStripMenuItem.DropDownItems.AddRange( new System.Windows.Forms.ToolStripItem[] {
            this.viewHelpToolStripMenuItem,
            this.toolStripMenuItem5,
            this.aboutToolStripMenuItem} );
            this.helpToolStripMenuItem.Name = "helpToolStripMenuItem";
            this.helpToolStripMenuItem.Size = new System.Drawing.Size( 44, 20 );
            this.helpToolStripMenuItem.Text = "&Help";
            // 
            // viewHelpToolStripMenuItem
            // 
            this.viewHelpToolStripMenuItem.Name = "viewHelpToolStripMenuItem";
            this.viewHelpToolStripMenuItem.ShortcutKeys = System.Windows.Forms.Keys.F1;
            this.viewHelpToolStripMenuItem.Size = new System.Drawing.Size( 146, 22 );
            this.viewHelpToolStripMenuItem.Text = "View Help";
            // 
            // toolStripMenuItem5
            // 
            this.toolStripMenuItem5.Name = "toolStripMenuItem5";
            this.toolStripMenuItem5.Size = new System.Drawing.Size( 143, 6 );
            // 
            // aboutToolStripMenuItem
            // 
            this.aboutToolStripMenuItem.Name = "aboutToolStripMenuItem";
            this.aboutToolStripMenuItem.Size = new System.Drawing.Size( 146, 22 );
            this.aboutToolStripMenuItem.Text = "About";
            // 
            // statusStrip1
            // 
            this.statusStrip1.Location = new System.Drawing.Point( 0, 586 );
            this.statusStrip1.Name = "statusStrip1";
            this.statusStrip1.Size = new System.Drawing.Size( 623, 22 );
            this.statusStrip1.TabIndex = 1;
            this.statusStrip1.Text = "appStatusStrip";
            // 
            // appResourcesSplitPanel
            // 
            this.appResourcesSplitPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.appResourcesSplitPanel.Location = new System.Drawing.Point( 0, 24 );
            this.appResourcesSplitPanel.Name = "appResourcesSplitPanel";
            // 
            // appResourcesSplitPanel.Panel1
            // 
            this.appResourcesSplitPanel.Panel1.Controls.Add( this.mEditorTabs );
            // 
            // appResourcesSplitPanel.Panel2
            // 
            this.appResourcesSplitPanel.Panel2.Controls.Add( this.appPropertyGrid );
            this.appResourcesSplitPanel.Size = new System.Drawing.Size( 623, 562 );
            this.appResourcesSplitPanel.SplitterDistance = 392;
            this.appResourcesSplitPanel.TabIndex = 2;
            // 
            // appPropertyGrid
            // 
            this.appPropertyGrid.Anchor = ( (System.Windows.Forms.AnchorStyles) ( ( ( ( System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom )
                        | System.Windows.Forms.AnchorStyles.Left )
                        | System.Windows.Forms.AnchorStyles.Right ) ) );
            this.appPropertyGrid.Location = new System.Drawing.Point( 3, 3 );
            this.appPropertyGrid.Name = "appPropertyGrid";
            this.appPropertyGrid.Size = new System.Drawing.Size( 221, 556 );
            this.appPropertyGrid.TabIndex = 0;
            this.appPropertyGrid.Leave += new System.EventHandler( this.RefreshViewIfDirty );
            // 
            // appBundleRootMenu
            // 
            this.appBundleRootMenu.Items.AddRange( new System.Windows.Forms.ToolStripItem[] {
            this.newBundleToolStripMenuItem,
            this.newAttributionToolStripMenuItem,
            this.toolStripMenuItem6,
            this.editItemToolStripMenuItem,
            this.toolStripMenuItem7,
            this.deleteToolStripMenuItem1,
            this.toolStripMenuItem8,
            this.refreshViewToolStripMenuItem} );
            this.appBundleRootMenu.Name = "appBundleRootMenu";
            this.appBundleRootMenu.Size = new System.Drawing.Size( 158, 132 );
            // 
            // newBundleToolStripMenuItem
            // 
            this.newBundleToolStripMenuItem.Name = "newBundleToolStripMenuItem";
            this.newBundleToolStripMenuItem.Size = new System.Drawing.Size( 157, 22 );
            this.newBundleToolStripMenuItem.Text = "New bundle";
            this.newBundleToolStripMenuItem.Click += new System.EventHandler( this.newBundleToolStripMenuItem_Click );
            // 
            // newAttributionToolStripMenuItem
            // 
            this.newAttributionToolStripMenuItem.Name = "newAttributionToolStripMenuItem";
            this.newAttributionToolStripMenuItem.Size = new System.Drawing.Size( 157, 22 );
            this.newAttributionToolStripMenuItem.Text = "New attribution";
            this.newAttributionToolStripMenuItem.Click += new System.EventHandler( this.newAttributionToolStripMenuItem_Click );
            // 
            // toolStripMenuItem6
            // 
            this.toolStripMenuItem6.Name = "toolStripMenuItem6";
            this.toolStripMenuItem6.Size = new System.Drawing.Size( 154, 6 );
            // 
            // editItemToolStripMenuItem
            // 
            this.editItemToolStripMenuItem.Name = "editItemToolStripMenuItem";
            this.editItemToolStripMenuItem.Size = new System.Drawing.Size( 157, 22 );
            this.editItemToolStripMenuItem.Text = "Edit item";
            // 
            // toolStripMenuItem7
            // 
            this.toolStripMenuItem7.Name = "toolStripMenuItem7";
            this.toolStripMenuItem7.Size = new System.Drawing.Size( 154, 6 );
            // 
            // deleteToolStripMenuItem1
            // 
            this.deleteToolStripMenuItem1.Name = "deleteToolStripMenuItem1";
            this.deleteToolStripMenuItem1.Size = new System.Drawing.Size( 157, 22 );
            this.deleteToolStripMenuItem1.Text = "Delete";
            // 
            // toolStripMenuItem8
            // 
            this.toolStripMenuItem8.Name = "toolStripMenuItem8";
            this.toolStripMenuItem8.Size = new System.Drawing.Size( 154, 6 );
            // 
            // refreshViewToolStripMenuItem
            // 
            this.refreshViewToolStripMenuItem.Name = "refreshViewToolStripMenuItem";
            this.refreshViewToolStripMenuItem.Size = new System.Drawing.Size( 157, 22 );
            this.refreshViewToolStripMenuItem.Text = "Refresh view";
            this.refreshViewToolStripMenuItem.Click += new System.EventHandler( this.refreshViewToolStripMenuItem_Click );
            // 
            // resourceSaveDialog
            // 
            this.resourceSaveDialog.DefaultExt = "resources.xml";
            this.resourceSaveDialog.Filter = "Forge Resources Database (*.resources.xml)|*.resources.xml";
            this.resourceSaveDialog.Title = "Save Resources Database";
            // 
            // resourceOpenDialog
            // 
            this.resourceOpenDialog.DefaultExt = "resdb.xml";
            this.resourceOpenDialog.Filter = "Resource Database (*.resdb.xml)|*.resdb.xml";
            this.resourceOpenDialog.Title = "Open resource database";
            // 
            // appStausLabel
            // 
            this.appStausLabel.AutoSize = true;
            this.appStausLabel.Location = new System.Drawing.Point( 3, 590 );
            this.appStausLabel.Name = "appStausLabel";
            this.appStausLabel.Size = new System.Drawing.Size( 38, 13 );
            this.appStausLabel.TabIndex = 3;
            this.appStausLabel.Text = "Ready";
            // 
            // mEditorTabs
            // 
            this.mEditorTabs.Anchor = ( (System.Windows.Forms.AnchorStyles) ( ( ( ( System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom )
                        | System.Windows.Forms.AnchorStyles.Left )
                        | System.Windows.Forms.AnchorStyles.Right ) ) );
            this.mEditorTabs.Controls.Add( this.mResourcesTabPage );
            this.mEditorTabs.Controls.Add( this.mBundlesTabPage );
            this.mEditorTabs.Controls.Add( this.mAttributionsTabPage );
            this.mEditorTabs.Location = new System.Drawing.Point( 6, 3 );
            this.mEditorTabs.Name = "mEditorTabs";
            this.mEditorTabs.SelectedIndex = 0;
            this.mEditorTabs.Size = new System.Drawing.Size( 383, 556 );
            this.mEditorTabs.TabIndex = 0;
            // 
            // mResourcesTabPage
            // 
            this.mResourcesTabPage.Controls.Add( this.mResourcesListView );
            this.mResourcesTabPage.Location = new System.Drawing.Point( 4, 22 );
            this.mResourcesTabPage.Name = "mResourcesTabPage";
            this.mResourcesTabPage.Padding = new System.Windows.Forms.Padding( 3 );
            this.mResourcesTabPage.Size = new System.Drawing.Size( 375, 530 );
            this.mResourcesTabPage.TabIndex = 0;
            this.mResourcesTabPage.Text = "Resources";
            this.mResourcesTabPage.UseVisualStyleBackColor = true;
            // 
            // mBundlesTabPage
            // 
            this.mBundlesTabPage.Controls.Add( this.mBundlesListView );
            this.mBundlesTabPage.Location = new System.Drawing.Point( 4, 22 );
            this.mBundlesTabPage.Name = "mBundlesTabPage";
            this.mBundlesTabPage.Padding = new System.Windows.Forms.Padding( 3 );
            this.mBundlesTabPage.Size = new System.Drawing.Size( 375, 530 );
            this.mBundlesTabPage.TabIndex = 1;
            this.mBundlesTabPage.Text = "Bundles";
            this.mBundlesTabPage.UseVisualStyleBackColor = true;
            // 
            // mAttributionsTabPage
            // 
            this.mAttributionsTabPage.Location = new System.Drawing.Point( 4, 22 );
            this.mAttributionsTabPage.Name = "mAttributionsTabPage";
            this.mAttributionsTabPage.Size = new System.Drawing.Size( 375, 530 );
            this.mAttributionsTabPage.TabIndex = 2;
            this.mAttributionsTabPage.Text = "Attributions";
            this.mAttributionsTabPage.UseVisualStyleBackColor = true;
            // 
            // mResourcesListView
            // 
            this.mResourcesListView.Location = new System.Drawing.Point( 7, 7 );
            this.mResourcesListView.Name = "mResourcesListView";
            this.mResourcesListView.Size = new System.Drawing.Size( 362, 517 );
            this.mResourcesListView.TabIndex = 0;
            this.mResourcesListView.UseCompatibleStateImageBehavior = false;
            // 
            // mBundlesListView
            // 
            this.mBundlesListView.Location = new System.Drawing.Point( 7, 7 );
            this.mBundlesListView.Name = "mBundlesListView";
            this.mBundlesListView.Size = new System.Drawing.Size( 362, 517 );
            this.mBundlesListView.TabIndex = 0;
            this.mBundlesListView.UseCompatibleStateImageBehavior = false;
            // 
            // MainWindow
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF( 6F, 13F );
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size( 623, 608 );
            this.Controls.Add( this.appStausLabel );
            this.Controls.Add( this.appResourcesSplitPanel );
            this.Controls.Add( this.statusStrip1 );
            this.Controls.Add( this.appMainMenu );
            this.Font = new System.Drawing.Font( "Segoe UI", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ( (byte) ( 0 ) ) );
            this.MainMenuStrip = this.appMainMenu;
            this.Name = "MainWindow";
            this.Text = "Forge Asset Tool";
            this.Load += new System.EventHandler( this.MainWindow_Load );
            this.appMainMenu.ResumeLayout( false );
            this.appMainMenu.PerformLayout();
            this.appResourcesSplitPanel.Panel1.ResumeLayout( false );
            this.appResourcesSplitPanel.Panel2.ResumeLayout( false );
            ( (System.ComponentModel.ISupportInitialize) ( this.appResourcesSplitPanel ) ).EndInit();
            this.appResourcesSplitPanel.ResumeLayout( false );
            this.appBundleRootMenu.ResumeLayout( false );
            this.mEditorTabs.ResumeLayout( false );
            this.mResourcesTabPage.ResumeLayout( false );
            this.mBundlesTabPage.ResumeLayout( false );
            this.ResumeLayout( false );
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip appMainMenu;
        private System.Windows.Forms.ToolStripMenuItem fileToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem editToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem toolsToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem imageToolToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem newToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem openAssetDatabaseToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem saveAssetDatabaseToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem saveCopyToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripMenuItem2;
        private System.Windows.Forms.ToolStripMenuItem exitToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem helpToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem undoToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem redoToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripMenuItem3;
        private System.Windows.Forms.ToolStripMenuItem cutToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem copyToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem pasteToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem deleteToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripMenuItem4;
        private System.Windows.Forms.ToolStripMenuItem selectAllToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem viewHelpToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripMenuItem5;
        private System.Windows.Forms.ToolStripMenuItem aboutToolStripMenuItem;
        private System.Windows.Forms.StatusStrip statusStrip1;
        private System.Windows.Forms.SplitContainer appResourcesSplitPanel;
        private System.Windows.Forms.PropertyGrid appPropertyGrid;
        private System.Windows.Forms.ContextMenuStrip appBundleRootMenu;
        private System.Windows.Forms.ToolStripMenuItem newBundleToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem newAttributionToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripMenuItem6;
        private System.Windows.Forms.ToolStripMenuItem editItemToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripMenuItem7;
        private System.Windows.Forms.ToolStripMenuItem deleteToolStripMenuItem1;
        private System.Windows.Forms.ToolStripSeparator toolStripMenuItem8;
        private System.Windows.Forms.ToolStripMenuItem refreshViewToolStripMenuItem;
        private System.Windows.Forms.SaveFileDialog resourceSaveDialog;
        private System.Windows.Forms.OpenFileDialog resourceOpenDialog;
        private System.Windows.Forms.Label appStausLabel;
        private System.Windows.Forms.TabControl mEditorTabs;
        private System.Windows.Forms.TabPage mResourcesTabPage;
        private System.Windows.Forms.TabPage mBundlesTabPage;
        private System.Windows.Forms.TabPage mAttributionsTabPage;
        private System.Windows.Forms.ListView mResourcesListView;
        private System.Windows.Forms.ListView mBundlesListView;
    }
}

