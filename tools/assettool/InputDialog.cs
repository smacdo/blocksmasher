using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace scott.forge.editor
{
    public partial class InputDialog : Form
    {
        /// <summary>
        /// The message presented to the user
        /// </summary>
        public string Message
        {
            get
            {
                return mInputText.Text;
            }
            set
            {
                mInputText.Text = value;
            }
        }

        /// <summary>
        /// The user's input
        /// </summary>
        public string UserInput
        {
            get
            {
                return mUserInput.Text;
            }
            set
            {
                mUserInput.Text = value;
            }
        }

        /// <summary>
        /// Constructor
        /// </summary>
        /// <param name="title">Title of the input dialog</param>
        /// <param name="message">Message in the input dialog</param>
        public InputDialog( String title, String message )
        {
            InitializeComponent();

            Text = title;
            Message = message;
        }

        private void mMessageText_Click( object sender, EventArgs e )
        {

        }
    }
}
