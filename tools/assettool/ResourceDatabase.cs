using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Xml;

namespace scott.forge.editor
{
    /// <summary>
    /// Holds all the information contained in a game's resource database, and
    /// the methods to edit it
    /// </summary>
    public class ResourceDatabase
    {
        /// <summary>
        /// List of the bundles contained in this resource database
        /// </summary>
        public List<BundleBuilderInfo> Bundles { get; private set; }

        /// <summary>
        /// List of attributions in the resource database
        /// </summary>
        public List<Attribution> Attributions { get; private set; }

        /// <summary>
        /// List of included images
        /// </summary>
        public List<ImageResource> Images { get; private set; }

        /// <summary>
        /// List of art files
        /// </summary>
        public List<ArtFileResource> ArtFiles { get; private set; }

        /// <summary>
        /// Constructor
        /// </summary>
        public ResourceDatabase()
        {
            Bundles = new List<BundleBuilderInfo>();
            Attributions = new List<Attribution>();
            Images = new List<ImageResource>();
        }

        /// <summary>
        /// Creates a new bundle in the resource database
        /// </summary>
        /// <param name="bundleName"></param>
        public void CreateBundle( string bundleName )
        {
            Bundles.Add( new BundleBuilderInfo( bundleName, "", false, 1 ) );
        }

        /// <summary>
        /// Creates a new attribution
        /// </summary>
        /// <param name="id"></param>
        public void CreateAttribution( string id )
        {
            
        }

        /// <summary>
        /// Reads a resource database from an XML document, and returns it
        /// </summary>
        /// <param name="xml"></param>
        /// <returns></returns>
        public static ResourceDatabase Read( XmlDocument xml )
        {
            ResourceDatabase database = new ResourceDatabase();

            // Populate the attributions database

            // Process all of the resource files being referenced in the art database
            XmlNode resourcesRoot = xml.SelectSingleNode( "resourcedatabase/resources" );

            // Process all of the resources files included within
            foreach ( XmlNode resourceNode in resourcesRoot.ChildNodes )
            {
                // What kind of resource is this? It will dictate how we load it
                switch ( resourceNode.Name )
                {
                    case "image":
                        database.Images.Add( ImageResource.Read( resourceNode ) );
                        break;

                    case "art":
                        database.ArtFiles.Add( ArtFileResource.Read( resourceNode ) );
                        break;

                    default:
                        throw new ResourceDatabaseImportException( "Unsupported resource type " + resourceNode.Name, "", "" );
                }
            }

            // Find all of the bundles listed in the resource database
            XmlNode bundleRootNode  = xml.SelectSingleNode( "resourcedatabase/bundles" );
            XmlNodeList bundleNodes = bundleRootNode.SelectNodes( "bundle" );

            foreach ( XmlNode bundleNode in bundleNodes )
            {
                database.Bundles.Add( BundleBuilderInfo.Read( bundleNode ) );
            }

            return database;
        }

        /// <summary>
        /// Exports the resource database to disk
        /// </summary>
        /// <param name="output">Output stream</param>
        public void Write( Stream output )
        {
 /*           // Create the Xml writer that we'll use to write the database out
            XmlWriterSettings settings = new XmlWriterSettings();
            settings.Indent = true;
            settings.IndentChars = "\t";
            settings.OmitXmlDeclaration = false;

            XmlWriter xml = XmlWriter.Create( output, settings );

            // Root node
            xml.WriteStartElement( "gameresources" );

            // Export attributions
            xml.WriteStartElement( "attributions" );

            foreach ( Attribution attribution in Attributions )
            {
                attribution.Write( xml );
            }

            xml.WriteEndElement();

            // Export bundles
            foreach ( BundleInfo bundle in Bundles )
            {
                bundle.Write( xml );
            }

            xml.WriteEndElement();
            xml.Flush();*/
        }
    }
}
