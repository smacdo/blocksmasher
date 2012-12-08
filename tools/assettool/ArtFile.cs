using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Xml;

namespace scott.forge.editor
{
    /// <summary>
    /// Contains information on an artfile entry located in the resource
    /// database XML file
    /// </summary>
    public class ArtFile
    {
        /// <summary>
        /// If the art file atlas textures should be a power of two
        /// </summary>
        public bool ForcePowerOfTwo { get; set; }

        /// <summary>
        /// If the art file atlas textures width and height should be the same
        /// </summary>
        public bool ForceSquareSize { get; set; }

        /// <summary>
        /// The maximum width and height of the atlas textures
        /// </summary>
        public int MaxSize { get; set; }

        /// <summary>
        /// Number of pixels between each sprite in the atlas
        /// </summary>
        public int Padding { get; set; }

        public List<SpriteEntry> Sprites { get; private set; }

        /// <summary>
        /// Constructor
        /// </summary>
        public ArtFile()
        {
            ForcePowerOfTwo = true;
            ForceSquareSize = true;
            MaxSize         = 1024;
            Padding         = 0;
            Sprites         = new List<SpriteEntry>();
        }

        /// <summary>
        /// Unserialize this art file entry
        /// </summary>
        /// <param name="bundleNode"></param>
        /// <returns></returns>
        public static ArtFile Read( XmlNode imageNode )
        {
            ArtFile artFileEntry = new ArtFile();

            // Pull build properties
            string forcePow2   = imageNode.SelectSingleNode( "buildproperties/forcepow2" ).InnerText;
            string forceSquare = imageNode.SelectSingleNode( "buildproperties/forcesquare" ).InnerText;
            string maxSize     = imageNode.SelectSingleNode( "buildproperties/maxsize" ).InnerText;
            string padding     = imageNode.SelectSingleNode( "buildproperties/padding" ).InnerText;

            // TODO: Error check

            // Start reading sprites
            XmlNodeList spriteNodes = imageNode.SelectNodes( "sprites/sprite" );

            foreach ( XmlNode spriteNode in spriteNodes )
            {
                artFileEntry.Sprites.Add( SpriteEntry.Read( spriteNode, true ) );
            }

            // Reading static sprites
            XmlNodeList staticSpriteNodes = imageNode.SelectNodes( "sprites/static_sprite" );

            foreach ( XmlNode spriteNode in staticSpriteNodes )
            {
                artFileEntry.Sprites.Add( SpriteEntry.Read( spriteNode, false ) );
            }

            return artFileEntry;
        }
    }
}
