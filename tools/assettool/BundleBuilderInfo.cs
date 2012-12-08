using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Xml;
using System.IO;
using scott.forge.assets;

namespace scott.forge.editor
{
    /// <summary>
    /// A file included in the bundle builder set
    /// </summary>
    public struct BundledFileEntry
    {
        public ResourceType Type;
        public string ResourceName;
    }

    /// <summary>
    /// Holds all the data in a game's bundle file
    /// </summary>
    public class BundleBuilderInfo
    {
        /// <summary>
        /// Name of the bundle
        /// </summary>
        public string Name { get; set; }

        /// <summary>
        /// Relative directory to place the bundle into
        /// </summary>
        public string DestinationDir { get; set; }

        /// <summary>
        /// If we should compress the bundle when writing it to disk
        /// </summary>
        public bool Compressed { get; set; }

        /// <summary>
        /// The game version for this bundle
        /// </summary>
        public int Version { get; set; }

        /// <summary>
        /// List of files included in this bundle
        /// </summary>
        public List<BundledFileEntry> Files { get; private set; }

        /// <summary>
        /// Constructor
        /// </summary>
        /// <param name="name">Name of the bundle</param>
        /// <param name="destdir">Output directory</param>
        /// <param name="compress">If we should compress the bundle</param>
        /// <param name="version">The version of this bundle to emit</param>
        public BundleBuilderInfo( string name, string destdir, bool compress, int version )
        {
            Name = name;
            DestinationDir = destdir;
            Compressed = compress;
            Version = version;
            Files = new List<BundledFileEntry>();
        }

        /// <summary>
        /// Read a bundle description from an XML node
        /// </summary>
        /// <param name="bundleNode"></param>
        /// <returns></returns>
        public static BundleBuilderInfo Read( XmlNode bundleNode )
        {
            // Extract attribute properties for this bundle
            string name         = bundleNode.Attributes["name"].Value;
            string destdir      = bundleNode.Attributes["destdir"].Value;
            string compressText = bundleNode.Attributes["compress"].Value;
            string versionText  = bundleNode.Attributes["version"].Value;

            // Convert properties to final format
            bool compress = Convert.ToBoolean( compressText );
            int version   = Convert.ToByte( versionText );
            
            if ( !Directory.Exists( destdir ) )
            {
                throw new ResourceDatabaseImportException( "Could not locate output directory: " + destdir, "", "" );
            }

            // Create the bundle builder info
            BundleBuilderInfo bundle = new BundleBuilderInfo( name, destdir, compress, version );

            // Add all the resources inside
            foreach ( XmlNode assetNode in bundleNode.ChildNodes )
            {
                BundledFileEntry entry = new BundledFileEntry();

                // Load attributes
                entry.ResourceName = assetNode.InnerText;

                // What kind of art resource is this?
                switch ( assetNode.Name )
                {
                    case "art":
                        entry.Type = ResourceType.Art;
                        break;

                    default:
                        throw new ResourceDatabaseImportException( "There is no type of art asset called " + assetNode.Name, "", "" );
                }

                // Add it!
                bundle.Files.Add( entry );
            }

            // All done!
            return bundle;
        }

        /// <summary>
        /// Exports the contents of this bundle into an xml description field
        /// </summary>
        /// <param name="output">Output stream</param>
        public void Write( XmlWriter xml )
        {
            xml.WriteStartElement( "bundle" );
            xml.WriteAttributeString( "name", Name );
            xml.WriteAttributeString( "destdir", "" );
            xml.WriteAttributeString( "compress", "false" );
            xml.WriteAttributeString( "version", "1" );
            xml.WriteEndElement();
        }
    }
}
