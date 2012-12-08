using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using scott.forge.assets;
using System.Xml;

namespace scott.forge.editor
{
    public partial class MainWindow : Form
    {
        /// <summary>
        /// The resource database being edited
        /// </summary>
        private ResourceDatabase mResourceDatabase;
        private static MainWindow mInstance;

        /// <summary>
        /// Constructor
        /// </summary>
        public MainWindow()
        {
            InitializeComponent();
            mInstance = this;
            mResourceDatabase = new ResourceDatabase();
        }

        /// <summary>
        /// Initialization
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void MainWindow_Load( object sender, EventArgs e )
        {
            RefreshView();
        }

        /// <summary>
        /// Refreshes the GUI with the current state of the resource database
        /// </summary>
        public void RefreshView()
        {
            //appResourcesTreeView.Nodes.Clear();

            // Root node for the game resources
  /*          TreeNode rootNode = appResourcesTreeView.Nodes.Add( Constants.GAME_RESOURCES_NAME );

            // Add all attributions
            TreeNode attributionsNode = rootNode.Nodes.Add( Constants.ATTRIBUTIONS_NAME );

            // Add all of the bundles
            TreeNode bundleRootNode = rootNode.Nodes.Add( Constants.BUNDLES_NAME );

            foreach ( BundleInfo bundle in mResourceDatabase.Bundles )
            {
                // Construct and set up a tree node representing this bundle
                TreeNode bundleNode = bundleRootNode.Nodes.Add( bundle.Name );

                bundleNode.Tag = bundle;
            }

            // Make sure all of the nodes are expanded
            rootNode.ExpandAll();*/
        }

        private void label2_Click( object sender, EventArgs e )
        {

        }

        /// <summary>
        /// Launch the image tool
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void imageToolToolStripMenuItem_Click( object sender, EventArgs e )
        {
            ImageToolWindow imageToolWindow = new ImageToolWindow();
            imageToolWindow.Show();
        }

        /// <summary>
        /// Quit the application
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void exitToolStripMenuItem_Click( object sender, EventArgs e )
        {
            Application.Exit();
        }

        /// <summary>
        /// Context menus and whatnot
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void appResourcesTreeView_MouseDown( object sender, MouseEventArgs e )
        {
            // Is this the right mouse button? Show the context menu
            if ( e.Button.HasFlag( MouseButtons.Right ) )
            {
                //appBundleRootMenu.Show( appResourcesTreeView, e.Location );
            }
        }

        /// <summary>
        /// Menu item to create a new bundle
        /// </summary>
        private void newBundleToolStripMenuItem_Click( object sender, EventArgs e )
        {
            InputDialog inputDialog = new InputDialog( "New Bundle", "Specify a name for the new bundle" );
            
            if ( inputDialog.ShowDialog() == DialogResult.OK && inputDialog.Name != String.Empty )
            {
                string bundleName = inputDialog.UserInput;
                
                mResourceDatabase.CreateBundle( bundleName );
                RefreshView();
            }
        }

        /// <summary>
        /// Create a new attribution item
        /// </summary>
        private void newAttributionToolStripMenuItem_Click( object sender, EventArgs e )
        {
            InputDialog inputDialog = new InputDialog( "New Attribution", "Specify a ID for the attribution" );

            if ( inputDialog.ShowDialog() == DialogResult.OK && inputDialog.Name != String.Empty )
            {
                string bundleName = inputDialog.UserInput;

                mResourceDatabase.CreateBundle( bundleName );
                RefreshView();
            }
        }

        /// <summary>
        /// Updates when a new item is selected
        /// </summary>
        private void appResourcesTreeView_AfterSelect( object sender, TreeViewEventArgs e )
        {
            // What object is selected?
            appPropertyGrid.SelectedObject = e.Node.Tag;
        }

        /// <summary>
        /// Refreshes the tree view
        /// </summary>
        private void refreshViewToolStripMenuItem_Click( object sender, EventArgs e )
        {
            RefreshView();
        }

        private void RefreshViewIfDirty( object sender, EventArgs e )
        {
//            RefreshView();
        }

        /// <summary>
        /// Saves the asset database
        /// </summary>
        private void saveAssetDatabaseToolStripMenuItem_Click( object sender, EventArgs e )
        {
            // Should we save it?
            if ( resourceSaveDialog.ShowDialog() == DialogResult.OK )
            {
                System.IO.Stream stream = resourceSaveDialog.OpenFile();

                mResourceDatabase.Write( stream );
                stream.Close();
            }
        }

        /// <summary>
        /// Opens an asset database
        /// </summary>>
        private void openAssetDatabaseToolStripMenuItem_Click( object sender, EventArgs e )
        {
            // Should we open it?
            if ( resourceOpenDialog.ShowDialog() == DialogResult.OK )
            {
                System.IO.Stream stream = null;

                try
                {
                    // Load the XML resource database into an XML document and proceed to
                    // import it's contents into memory
                    stream = resourceOpenDialog.OpenFile();

                    XmlDocument xmlDocument = new XmlDocument();
                    xmlDocument.Load( stream );

                    ResourceDatabase database = ResourceDatabase.Read( xmlDocument );

                    // Add the elements in the resource database to the GUI
                    mBundlesListView.DataSource
                }
                catch ( ResourceDatabaseImportException ex )
                {
                    MessageBox.Show( "Failed to open the resource database: " + ex.Message,
                                     "Asset Tool",
                                     MessageBoxButtons.OK,
                                     MessageBoxIcon.Error );
                }
                catch ( System.Exception ex )
                {
                    // We got an error! Time to freak  out :O
                	MessageBox.Show( "Failed to open the resource database: " + ex.Message,
                                     "Asset Tool",
                                     MessageBoxButtons.OK,
                                     MessageBoxIcon.Error );
                }
                finally
                {
                    stream.Close();
                }
            }
        }

        /// <summary>
        /// Writes a status message to the status bar and the console
        /// </summary>
        public static void PostStatusMessage( String message )
        {
            // TODO: Add a console of some sort
            if ( mInstance != null )
            {
                mInstance.appStausLabel.Text = message;
            }
            
            Console.Out.WriteLine( message );
        }

    }
}
