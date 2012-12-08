using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Drawing;
using System.IO;
using System.Windows.Forms;
using System.Drawing.Imaging;
using scott.forge.editor;
using System.Runtime.InteropServices;

namespace scott.forge.assets
{
    /// <summary>
    /// Contains an intermediate representation of a Forge Texture for easy
    /// editing
    /// </summary>
    public class FImage
    {
        /// <summary>
        /// C# representation of the image
        /// </summary>
        [System.ComponentModel.ReadOnlyAttribute(true)]
        public Bitmap Image { get; set; }

        /// <summary>
        /// Pixel format when serialized to disk
        /// </summary>
        public PixelFormat Format { get; set; }

        /// <summary>
        /// Get the image's width
        /// </summary>
        public int Width
        {
            get
            {
                return Image.Width;
            }
        }

        /// <summary>
        /// Get the image's height
        /// </summary>
        public int Height
        {
            get
            {
                return Image.Height;
            }
        }

        /// <summary>
        /// Constructor
        /// </summary>
        /// <param name="image">Image itself</param>
        public FImage( Bitmap image )
        {
            Image = image;
        }

        /// <summary>
        /// Reads a serialized FStream and constructs it
        /// </summary>
        /// <param name="writer"></param>
        /// <returns></returns>
        public static FImage Read( BinaryReader writer )
        {
            // Read the image properties from the stream
            int width  = writer.ReadUInt16();
            int height = writer.ReadUInt16();
            int stride = writer.ReadUInt16();
            int format = writer.ReadByte();

            // Convert the format into our pixel format enumeration. Additionally
            // we will use this to find out how many bytes each pixel requires
            PixelFormat pixelFormat = (PixelFormat) Enum.ToObject( typeof(PixelFormat), format );
            int bytesPerPixel       = Utils.CalcPixelSizeFor( pixelFormat );

            // Read the pixels into a temporary byte buffer
            byte[] pixels = writer.ReadBytes( stride * height );

            // Decide which bitmap pixel format we'll use depending on this image's
            // internal pixel format
            System.Drawing.Imaging.PixelFormat inPixelFormat = GetIdealPixelFormatFor( pixelFormat );

            // All right, use .NET to convert this byte stream into a system bitmap.
            //  Construct a new bitmap, get access to it's pixel buffer and then
            //  copy the unserialized pixels in.
            Bitmap inBitmap = new Bitmap( width, height, inPixelFormat );
            BitmapData data = inBitmap.LockBits( new Rectangle( 0, 0, width, height ),
                                                 ImageLockMode.WriteOnly,
                                                 inPixelFormat );

            Console.Out.WriteLine("FImage.Read: w={0},h={1},s={2},pf={3},inS={4},inPF={5}",
                                   width, height, stride, pixelFormat, data.Stride, data.PixelFormat );

            if ( data.Stride == stride )
            {
                Marshal.Copy( pixels, 0, data.Scan0, stride * height );
            }
            else
            {
                // Stride doesn't match up (weird...), so manually copy those
                // pixels
                int arrayOffset = 0;
                int imageOffset = 0;

                for ( int y = 0; y < height; ++y )
                {
                    Marshal.Copy( pixels, arrayOffset, (IntPtr)(((long) data.Scan0) + imageOffset ), stride );
                    arrayOffset += stride;
                    imageOffset += data.Stride;
                }
            }

            inBitmap.UnlockBits( data );

            // looks like we're done here
            return new FImage( inBitmap );
        }

        /// <summary>
        /// Writes this FImage into a binary stream for serialization
        /// </summary>
        public void Write( BinaryWriter writer )
        {
            // Select the correct image format
            System.Drawing.Imaging.PixelFormat pixelFormat = GetIdealPixelFormatFor( Format );

            // Get ALL THE BYTES from dat image
            BitmapData bitmapData = Image.LockBits( new Rectangle( 0, 0, Width, Height ),
                                                    ImageLockMode.ReadOnly,
                                                    pixelFormat );

            IntPtr scanPtr    = bitmapData.Scan0;
            int byteCount     = bitmapData.Stride * bitmapData.Height;
            byte[] imageBytes = new byte[ byteCount ];

            System.Runtime.InteropServices.Marshal.Copy( scanPtr, imageBytes, 0, byteCount );

            // We're all done touching the image's naughty parts
            Image.UnlockBits( bitmapData );

            // Make sure the stride lines up with the recorded width of the image
            if ( bitmapData.Stride != bitmapData.Width * Utils.CalcPixelSizeFor( Format ) )
            {
                MessageBox.Show( "The image's width does not equal it's stride! This may or may not corrupt the texture", "FImage Export", MessageBoxButtons.OK, MessageBoxIcon.Warning );
            }

            // Now write the image's contents into the binary stream. The format
            // for a serialized FStream is:
            //   uint16 width
            //   uint16 height
            //   uint8 format
            //   byte[] pixels
            writer.Write( (UInt16) Width );
            writer.Write( (UInt16) Height );
            writer.Write( (UInt16) bitmapData.Stride );
            writer.Write( (Byte) Format );
            writer.Write( imageBytes );

            // Write it out
            Console.Out.WriteLine( "FImage.Write: w={0},h={1},s={2},pf={3},outPF={4}",
                                    Width, Height, bitmapData.Stride, Format, pixelFormat );
        }

        /// <summary>
        /// Utility method that finds the most ideal windows bitmap pixel format
        /// depending on the texture's internal format.
        /// </summary>
        /// <param name="pixelFormat"></param>
        /// <returns></returns>
        public static System.Drawing.Imaging.PixelFormat GetIdealPixelFormatFor( scott.forge.assets.PixelFormat pixelFormat )
        {
            switch ( pixelFormat )
            {
                case PixelFormat.RGB16:
                    return System.Drawing.Imaging.PixelFormat.Format16bppRgb565;

                case PixelFormat.RGB24:
                    return System.Drawing.Imaging.PixelFormat.Format24bppRgb;

                case PixelFormat.RGBA32:
                    return System.Drawing.Imaging.PixelFormat.Format32bppArgb;

                default:
                    MessageBox.Show( "Requested pixel format not supported yet. Using ARGB32", "FImage Export", MessageBoxButtons.OK, MessageBoxIcon.Error );
                    return System.Drawing.Imaging.PixelFormat.Format32bppArgb;
            }
        }
    }
}
