using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using scott.forge.assets;
using System.Windows.Forms;

namespace scott.forge.editor
{
    /// <summary>
    /// Just a collection of utility methods that don't belong anywhere else
    /// </summary>
    public class Utils
    {
        public static int CalcPixelSizeFor( PixelFormat pixelFormat )
        {
            switch ( pixelFormat )
            {
                case PixelFormat.RGB16:
                    return 2;

                case PixelFormat.RGB24:
                    return 3;

                case PixelFormat.RGBA32:
                    return 4;

                default:
                    MessageBox.Show( "Requested pixel format not supported yet. Using ARGB32", "FImage Export", MessageBoxButtons.OK, MessageBoxIcon.Error );
                    return 4;
            }
        }
    }
}
