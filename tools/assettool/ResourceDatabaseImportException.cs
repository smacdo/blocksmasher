using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace scott.forge.editor
{
    /// <summary>
    /// Contains information on errors encountered when importing a resource
    /// database
    /// </summary>
    [Serializable]
    public class ResourceDatabaseImportException : Exception
    {
        public string File { get; private set; }
        public string XmlSource { get; private set; }

        /// <summary>
        /// Constructor
        /// </summary>
        /// <param name="message">The error message</param>
        /// <param name="file">Asset file causing the issue</param>
        /// <param name="source">Offending line of text (if available)</param>
        public ResourceDatabaseImportException( string message, string file, string source )
            : base( message )
        {
            File = file;
            XmlSource = source;
        }
    }
}
