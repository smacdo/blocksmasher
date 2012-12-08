using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Xml;

namespace scott.forge.editor
{
    public enum AttributionType
    {
        PublicDomain,
        GPL2,
        GPL3,
        LGPL2,
        LGPL3,
        CCSA
    }

    /// <summary>
    /// Information on attributions
    /// </summary>
    public class Attribution
    {
        public string Id { get; set; }
        public string Author { get; set; }
        public string Email { get; set; }
        public string Website { get; set; }
        public AttributionType License { get; set; }

        /// <summary>
        /// Exports the attribution
        /// </summary>
        /// <param name="output">Output stream</param>
        public void Write( XmlWriter xml )
        {
            xml.WriteStartElement( "attribution" );
            xml.WriteAttributeString( "id", Id );

            xml.WriteElementString( "author", Author );
            xml.WriteElementString( "email", Email );
            xml.WriteElementString( "website", Website );
            xml.WriteElementString( "license", License.ToString() );

            xml.WriteEndElement();
        }
    }
}
