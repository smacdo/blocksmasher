namespace scott.forge.editor
{
    partial class InputDialog
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose( bool disposing )
        {
            if ( disposing && ( components != null ) )
            {
                components.Dispose();
            }
            base.Dispose( disposing );
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.mOkButton = new System.Windows.Forms.Button();
            this.panel1 = new System.Windows.Forms.Panel();
            this.mCancelButton = new System.Windows.Forms.Button();
            this.mInputText = new System.Windows.Forms.Label();
            this.mUserInput = new System.Windows.Forms.TextBox();
            this.panel1.SuspendLayout();
            this.SuspendLayout();
            // 
            // mOkButton
            // 
            this.mOkButton.Anchor = ( (System.Windows.Forms.AnchorStyles) ( ( System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right ) ) );
            this.mOkButton.DialogResult = System.Windows.Forms.DialogResult.OK;
            this.mOkButton.Location = new System.Drawing.Point( 205, 12 );
            this.mOkButton.Name = "mOkButton";
            this.mOkButton.Size = new System.Drawing.Size( 75, 23 );
            this.mOkButton.TabIndex = 2;
            this.mOkButton.Text = "Ok";
            this.mOkButton.UseVisualStyleBackColor = true;
            // 
            // panel1
            // 
            this.panel1.BackColor = System.Drawing.SystemColors.ControlLight;
            this.panel1.Controls.Add( this.mCancelButton );
            this.panel1.Controls.Add( this.mOkButton );
            this.panel1.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.panel1.Location = new System.Drawing.Point( 0, 84 );
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size( 373, 48 );
            this.panel1.TabIndex = 3;
            // 
            // mCancelButton
            // 
            this.mCancelButton.Anchor = ( (System.Windows.Forms.AnchorStyles) ( ( System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right ) ) );
            this.mCancelButton.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.mCancelButton.Location = new System.Drawing.Point( 286, 12 );
            this.mCancelButton.Name = "mCancelButton";
            this.mCancelButton.Size = new System.Drawing.Size( 75, 23 );
            this.mCancelButton.TabIndex = 3;
            this.mCancelButton.Text = "Cancel";
            this.mCancelButton.UseVisualStyleBackColor = true;
            // 
            // mInputText
            // 
            this.mInputText.Anchor = ( (System.Windows.Forms.AnchorStyles) ( ( System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left ) ) );
            this.mInputText.AutoSize = true;
            this.mInputText.Location = new System.Drawing.Point( 9, 16 );
            this.mInputText.Name = "mInputText";
            this.mInputText.Size = new System.Drawing.Size( 51, 13 );
            this.mInputText.TabIndex = 4;
            this.mInputText.Text = "Input text";
            // 
            // mUserInput
            // 
            this.mUserInput.Anchor = ( (System.Windows.Forms.AnchorStyles) ( ( ( System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left )
                        | System.Windows.Forms.AnchorStyles.Right ) ) );
            this.mUserInput.Location = new System.Drawing.Point( 12, 44 );
            this.mUserInput.Name = "mUserInput";
            this.mUserInput.Size = new System.Drawing.Size( 348, 20 );
            this.mUserInput.TabIndex = 0;
            // 
            // InputDialog
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF( 6F, 13F );
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size( 373, 132 );
            this.Controls.Add( this.mUserInput );
            this.Controls.Add( this.mInputText );
            this.Controls.Add( this.panel1 );
            this.Name = "InputDialog";
            this.Text = "Input Dialog";
            this.panel1.ResumeLayout( false );
            this.ResumeLayout( false );
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button mOkButton;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Button mCancelButton;
        private System.Windows.Forms.Label mInputText;
        private System.Windows.Forms.TextBox mUserInput;
    }
}