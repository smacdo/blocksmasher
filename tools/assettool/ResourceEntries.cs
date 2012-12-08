using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using scott.forge.assets;
using System.IO;
using System.Xml;

namespace scott.forge.editor
{
    /// <summary>
    /// Represents an image resource definition in the resource database
    /// </summary>
    public class ImageResource
    {
        public string Id { get; set; }
        public PixelFormat Format { get; set; }
        public string Filepath { get; set; }

        /// <summary>
        /// Constructor
        /// </summary>
        /// <param name="id"></param>
        /// <param name="format"></param>
        /// <param name="path"></param>
        public ImageResource( string id, PixelFormat format, string path )
        {
            Id = id;
            Format = format;
            Filepath = path;
        }

        /// <summary>
        /// Unserialize this source image entry
        /// </summary>
        /// <param name="imageNode"></param>
        /// <returns></returns>
        public static ImageResource Read( XmlNode imageNode )
        {
            // Extract attribute properties for this bundle
            string id           = imageNode.Attributes["id"].Value;
            string attrIdText   = imageNode.Attributes["attribution"].Value;
            string formatText   = imageNode.Attributes["format"].Value;
            string filepathText = imageNode.InnerText;

            // Convert the extracted properties into the types we will actually
            // use for this class
            //   TODO: Error check
            PixelFormat format = (PixelFormat) Enum.Parse( typeof( PixelFormat ), formatText ); 
            string filepath    = Path.GetFullPath( filepathText );
            
            if ( !File.Exists( filepath ) )
            {
                throw new ResourceDatabaseImportException( "File does not exist: " + filepath, "", "" );
            }

            return new ImageResource( id, format, filepath );
        }
    }

    /// <summary>
    /// Represents an art file listed in the art database
    /// </summary>
    public class ArtFileResource
    {
        public string Id { get; set; }
        public string Filepath { get; set; }

        /// <summary>
        /// Constructor
        /// </summary>
        /// <param name="id"></param>
        /// <param name="filepath"></param>
        public ArtFileResource( string id, string filepath )
        {
            Id = id;
            Filepath = filepath;
        }

        /// <summary>
        /// Unserialize this art file entry
        /// </summary>
        public static ArtFileResource Read( XmlNode imageNode )
        {
            string id = imageNode.Attributes["id"].Value;
            string filepath = imageNode.InnerText;

            // Do some error checking
            if ( !File.Exists( filepath ) )
            {
                throw new ResourceDatabaseImportException( "File does not exist: " + filepath, "", "" );
            }

            // All done (that was simple!)
            return new ArtFileResource( id, filepath );
        }
    }
}
