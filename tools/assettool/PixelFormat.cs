using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace scott.forge.assets
{
    /// <summary>
    /// Pixel layout format for a forge image. The identifiers are important!
    /// </summary>
    public enum PixelFormat : byte
    {
        RGB16 = 0,
        RGB24 = 1,
        RGBA32 = 2,
    }
}
