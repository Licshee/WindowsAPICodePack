//Copyright (c) Microsoft Corporation.  All rights reserved.

using System.Drawing;

namespace Microsoft.WindowsAPICodePack.Shell.Taskbar
{
    /// <summary>
    /// Represents an overlay image on the taskbar button.
    /// </summary>
    public class OverlayImage
    {
        /// <summary>
        /// Gets or sets the icon to use for this overlay.
        /// </summary>
        public Icon Icon { get; set; }

        /// <summary>
        /// Gets or sets the alternate text version of the information
        /// conveyed by the overlay, for accessiblity purposes.
        /// </summary>
        public string Text { get; set; }
    
        /// <summary>
        /// Creates a new OverlayImage using the specified icon and alt text.
        /// </summary>
        /// <param name="icon">Icon to use for the overlay</param>
        /// <param name="text">Alternate text for this overlay.</param>
        public OverlayImage(Icon icon, string text)
        {
            Icon = icon;
            Text = text;
        }
    }
}
