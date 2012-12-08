using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Xml;

namespace scott.forge.editor
{
    /// <summary>
    /// Info on a sprite animation
    /// </summary>
    public class SpriteAnimationEntry
    {
        public String Name { get; set; }
        public float SecondsPerFrame { get; set; }
        public List<SourceImageEntry> Images { get; set; }

        /// <summary>
        /// Constructor
        /// </summary>
        public SpriteAnimationEntry( string name )
        {
            Name = name;
            SecondsPerFrame = 1.0f;
            Images = new List<SourceImageEntry>();
        }
    }

    /// <summary>
    /// Represents a SpriteEntry from the resource database
    /// </summary>
    public class SpriteEntry
    {
        public string Name { get; set; }
        public List<SpriteAnimationEntry> Animations { get; private set; }

        public SpriteEntry( string name )
        {
            Name       = name;
            Animations = new List<SpriteAnimationEntry>();
        }

        /// <summary>
        /// Unserialize this sprite
        /// </summary>
        /// <param name="bundleNode"></param>
        /// <returns></returns>
        public static SpriteEntry Read( XmlNode spriteNode, bool isStaticSprite )
        {
            List<SpriteAnimationEntry> animations = new List<SpriteAnimationEntry>();

            // Pull properties
            string name = spriteNode.Attributes["name"].Value;

            // Read all of the animations
            if ( isStaticSprite )
            {
                // This is a static_sprite, meaning it only has a single image
                // inside of it
                XmlNode imageNode      = spriteNode.SelectSingleNode( "static_sprite" );
                SourceImageEntry image = SourceImageEntry.Read( imageNode );

                // Create a single animation called "DEFAULT" with only one frame
                SpriteAnimationEntry animation = new SpriteAnimationEntry( Constants.DEFAULT_ANIMATION_NAME );
                animation.Images.Add( image );

                // Now register the animation
                animations.Add( animation );
            }
            else
            {
                // Read all of the animations in
                XmlNodeList animationNodes = spriteNode.SelectNodes( "animation" );

                foreach ( XmlNode animationNode in animationNodes )
                {
                    string animationName           = animationNode.Attributes["name"].Value;
                    List<SourceImageEntry> images  = ReadAnimationList( animationNode );
                    SpriteAnimationEntry animation = new SpriteAnimationEntry( animationName );
                    
                    animation.Images = images;
                    animations.Add( animation );
                }
            }

            // Create the sprite entry before returning it
            SpriteEntry sprite = new SpriteEntry( name );
            sprite.Animations  = animations;

            return sprite;
        }

        /// <summary>
        /// Reads an animation list
        /// </summary>
        /// <param name="animationNode"></param>
        /// <returns></returns>
        public static List<SourceImageEntry> ReadAnimationList( XmlNode animationNode )
        {
            List<SourceImageEntry> animations = new List<SourceImageEntry>();
            XmlNodeList imageNodes = animationNode.SelectNodes( "image" );

            foreach ( XmlNode imageNode in imageNodes )
            {
                SourceImageEntry image = SourceImageEntry.Read( imageNode );
                animations.Add( image );
            }

            return animations;
        }
    }    
}
