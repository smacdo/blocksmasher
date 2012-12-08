using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using scott.forge.assets;
using System.IO;

namespace scott.forge.editor
{
    /// <summary>
    /// Image tool GUI
    /// </summary>
    public partial class ImageToolWindow : Form
    {
        /// <summary>
        /// The current image being viewed
        /// </summary>
        public FImage CurrentImage { get; private set; }

        /// <summary>
        /// Constructor
        /// </summary>
        public ImageToolWindow()
        {
            InitializeComponent();
        }

        /// <summary>
        /// Opens an image to view
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void openToolStripMenuItem_Click( object sender, EventArgs e )
        {
            // Let the user pick an image to open up
            if ( openImageFileDialog.ShowDialog() == DialogResult.OK )
            {
                string filePath = openImageFileDialog.FileName;

                // What kind of image are we loading? Either we're loading a forge
                // image (*.texture), or a standard image file format that .NET
                // can handle
                if ( openImageFileDialog.SafeFileName.EndsWith( ".texture" ) )
                {
                    // The user selected a forge texture, which means we'll have
                    // to load it using our custom serialization code
                    try
                    {
                        FImage loadedImage = FImage.Read( new BinaryReader( openImageFileDialog.OpenFile() ) );

                        // Did we unserialize the image successfully?
                        if ( loadedImage != null )
                        {
                            CurrentImage = loadedImage;

                            imageView.Image = CurrentImage.Image;
                            imageView.Width = CurrentImage.Width;
                            imageView.Height = CurrentImage.Height;
                        }
                        else
                        {
                            MessageBox.Show( "Could not load the requested texture file", "Image Tool", MessageBoxButtons.OK, MessageBoxIcon.Error );
                        }
                    }
                    catch ( System.Exception ex )
                    {
                        MessageBox.Show( "Could not load the requested texture file: " + ex.Message, "Image Tool", MessageBoxButtons.OK, MessageBoxIcon.Error );
                    }
                }
                else
                {
                    // Looks like the user selected a standard image file. All we
                    // have to do is ask .NET nicely to load it for us
                    Bitmap bitmap = new Bitmap( filePath );

                    // Assign the image, and then resize the control to fit the
                    // image's dimensions
                    imageView.Image = bitmap;
                    imageView.Width = bitmap.Width;
                    imageView.Height = bitmap.Height;

                    CurrentImage = new FImage( bitmap );
                    CurrentImage.Format = PixelFormat.RGB24;        // safe default I suppose
                }

                // Apply the newly loaded FImage to the property grid for editing
                imageProperties.SelectedObject = CurrentImage;
            }

        }

        /// <summary>
        /// Writes the image out to disk
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void exportToFormatToolStripMenuItem_Click( object sender, EventArgs e )
        {
            // Don't even bother if we don't have an image to export
            if ( CurrentImage == null )
            {
                return;
            }

            // Let the user pick a file to export the image to
            if ( saveImageDialog.ShowDialog() == DialogResult.OK )
            {
                BinaryWriter writer = new BinaryWriter( saveImageDialog.OpenFile() );
                CurrentImage.Write( writer );

                writer.Close();
            }
        }

        private void openImageFileDialog_FileOk( object sender, CancelEventArgs e )
        {

        }
    }
}
