using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using scott.forge.assets;
using System.Xml;

namespace scott.forge.editor
{
    /// <summary>
    /// Information on a source image in the resource database
    /// </summary>
    public class SourceImageEntry
    {
        /// <summary>
        /// Unique identifier for the source image
        /// </summary>
        public string Id { get; set; }

        /// <summary>
        /// The pixel format that we should use when importing this image
        /// </summary>
        public PixelFormat Format { get; set; }

        /// <summary>
        /// Path to the image on disk (relative to the root of the resources
        /// database)
        /// </summary>
        public string FilePath { get; set; }

        /// <summary>
        /// Constructor
        /// </summary>
        /// <param name="id">Id used to reference this source image</param>
        public SourceImageEntry( string id )
        {
            Id = id;
        }

        /// <summary>
        /// Unserialize this source image entry
        /// </summary>
        /// <param name="bundleNode"></param>
        /// <returns></returns>
        public static SourceImageEntry Read( XmlNode imageNode )
        {
            // Extract attribute properties for this bundle
            string id       = imageNode.Attributes["id"].Value;
            string attrId   = imageNode.Attributes["attribution"].Value;
            string format   = imageNode.Attributes["format"].Value;
            string filepath = imageNode.InnerText;

            // TODO: Error check

            // Return the generated source image
            SourceImageEntry image = new SourceImageEntry( id );

            image.Format   = (PixelFormat) Enum.Parse( typeof(PixelFormat), format );
            image.FilePath = filepath;

            return image;
        }
    }
}
