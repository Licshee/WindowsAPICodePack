//Copyright (c) Microsoft Corporation.  All rights reserved.

using System;
using System.Drawing;
using System.Runtime.InteropServices;
using System.Windows.Interop;
using System.Windows.Media.Imaging;

namespace Microsoft.WindowsAPICodePack.Shell
{
    /// <summary>
    /// Represents a thumbnail for a ShellFileSystemObject (ShellFile or ShellFolder)
    /// </summary>
    public class ShellObjectThumbnail
    {
        #region Private members

        /// <summary>
        /// Native shellItem
        /// </summary>
        private IShellItem shellItemNative = null;

        /// <summary>
        /// Internal member to keep track of the current size
        /// </summary>
        private Size size = new Size(256, 256);

        /// <summary>
        /// Maximum size for the ShellObjectThumbnail
        /// </summary>
        public Size SizeMaximum = new Size(1024, 1024);

        /// <summary>
        /// Defines a read-only value for small sized thumbnail
        /// </summary>
        public readonly Size SizeSmall = new Size(32, 32);

        /// <summary>
        /// Defines a read-only value for medium sized thumbnail
        /// </summary>
        public readonly Size SizeMedium = new Size(96, 96);

        /// <summary>
        /// Defines a read-only value for large sized thumbnail
        /// </summary>
        public readonly Size SizeLarge = new Size(256, 256);

        /// <summary>
        /// Defines a read-only value for extra large sized thumbnail
        /// </summary>
        public readonly Size SizeExtraLarge = new Size(1024, 1024);


        #endregion

        #region Constructors

        /// <summary>
        /// Internal constructor that takes in a parent IShellItem.
        /// </summary>
        /// <param name="shellItem"></param>
        internal ShellObjectThumbnail(IShellItem shellItem)
        {
            shellItemNative = shellItem;
        }

        /// <summary>
        /// Internal constructor that takes in a parent IShellItem.
        /// </summary>
        /// <param name="shellItem">The parent (native) IShellItem</param>
        /// <param name="defaultSize">The default size for the thumbnail</param>
        internal ShellObjectThumbnail(IShellItem shellItem, Size defaultSize)
        {
            shellItemNative = shellItem;
            this.Size = defaultSize;
        }

        /// <summary>
        /// No public default constructor. User should not be able to create a ShellObjectThumbnail,
        /// only retrive it from an existing ShellFileSystemObject
        /// </summary>
        private ShellObjectThumbnail() { }

        #endregion

        #region Public properties

        /// <summary>
        /// Gets or sets the default size of the thumbnail image. Default is 256x256 pixels. 
        /// If the size specified is larger than the maximum size (1024x1024), 
        /// a <see cref="System.ArgumentException"/> will be thrown.
        /// </summary>
        public Size Size
        {
            get
            {
                return size;
            }
            set
            {
                if (value.Height > SizeMaximum.Height && value.Width > SizeMaximum.Width)
                    throw new System.ArgumentException(string.Format("Size cannot be greater than the maximum size {0}", SizeMaximum.ToString()));
                else
                    size = value;
            }
        }

        /// <summary>
        /// Gets the thumbnail image in <see cref="System.Drawing.Bitmap"/> format. If the ShellFileSystemObject does not 
        /// have any thumbnail, a <see cref="System.InvalidOperationException"/> will be thrown.
        /// </summary>
        public Bitmap Bitmap
        {
            get
            {
                if (shellItemNative != null)
                {
                    IntPtr hbitmap = IntPtr.Zero;

                    // Create a size structure to pass to the native method
                    CoreNativeMethods.SIZE nativeSIZE = new CoreNativeMethods.SIZE();
                    nativeSIZE.cx = size.Width;
                    nativeSIZE.cy = size.Height;

                    try
                    {
                        // Use IShellItemImageFactory to get
                        // Options passed in: Resize to fit, Only return the thumbnail 
                        // (i.e. exception if no thumbnail, even if icon is present)
                        ((IShellItemImageFactory)shellItemNative).GetImage(nativeSIZE, ShellNativeMethods.SIIGBF.SIIGBF_RESIZETOFIT | ShellNativeMethods.SIIGBF.SIIGBF_THUMBNAILONLY, out hbitmap);
                    }
                    catch
                    {
                        // We might get a COMException (HRESULT: 0x8004B200 or 0x80030002) if
                        // there is no thumbnail or if we don't have the thumbnail cached (because of the flag above)

                        // TODO - Expose an exception to the user
                        return null;
                    }

                    // return a System.Drawing.Bitmap from the hBitmap
                    Bitmap returnValue = Bitmap.FromHbitmap(hbitmap);

                    // release COM stuff to avoid memory leaks
                    Marshal.Release(hbitmap);

                    return returnValue;
                }
                else
                    throw new System.InvalidOperationException("The parent ShellFileSystemObject is null");
            }
        }

        /// <summary>
        /// Gets the thumbnail image in <see cref="System.Windows.Media.Imaging.BitmapSource"/> format. 
        /// If the ShellFileSystemObject does not have any thumbnail, a <see cref="System.InvalidOperationException"/> 
        /// will be thrown.
        /// </summary>
        public BitmapSource BitmapSource
        {
            get
            {
                if (shellItemNative != null)
                {
                    IntPtr hbitmap = IntPtr.Zero;

                    // Create a size structure to pass to the native method
                    CoreNativeMethods.SIZE nativeSIZE = new CoreNativeMethods.SIZE();
                    nativeSIZE.cx = size.Width;
                    nativeSIZE.cy = size.Height;

                    try
                    {
                        // Use IShellItemImageFactory to get
                        // Options passed in: Resize to fit, Only return the thumbnail 
                        // (i.e. exception if no thumbnail, even if icon is present)
                        ((IShellItemImageFactory)shellItemNative).GetImage(nativeSIZE, ShellNativeMethods.SIIGBF.SIIGBF_RESIZETOFIT | ShellNativeMethods.SIIGBF.SIIGBF_THUMBNAILONLY, out hbitmap);
                    }
                    catch
                    {
                        // We might get a COMException (HRESULT: 0x8004B200 or 0x80030002) if
                        // there is no thumbnail or if we don't have the thumbnail cached (because of the flag above)

                        // TODO - Expose an exception to the user
                        return null;
                    }

                    // Use interop to create a BitmapSource from hBitmap.
                    BitmapSource returnValue = Imaging.CreateBitmapSourceFromHBitmap(hbitmap, IntPtr.Zero, System.Windows.Int32Rect.Empty, BitmapSizeOptions.FromEmptyOptions());

                    // release COM stuff to avoid memory leaks
                    Marshal.Release(hbitmap);

                    return returnValue;
                }
                else
                    throw new System.InvalidOperationException("The parent ShellFileSystemObject is null");
            }
        }

        /// <summary>
        /// Gets the <see cref="Microsoft.WindowsAPICodePack.Shell.ShellObjectThumbnail"/> in small size (32x32).
        /// </summary>
        public ShellObjectThumbnail Small
        {
            get
            {
                return new ShellObjectThumbnail(shellItemNative, SizeSmall);
            }
        }

        /// <summary>
        /// Gets the <see cref="Microsoft.WindowsAPICodePack.Shell.ShellObjectThumbnail"/> in medium size (96x96)
        /// </summary>
        public ShellObjectThumbnail Medium
        {
            get
            {
                return new ShellObjectThumbnail(shellItemNative, SizeMedium);
            }
        }

        /// <summary>
        /// Gets the <see cref="Microsoft.WindowsAPICodePack.Shell.ShellObjectThumbnail"/> in large size (256x256)
        /// </summary>
        public ShellObjectThumbnail Large
        {
            get
            {
                return new ShellObjectThumbnail(shellItemNative, SizeLarge);
            }
        }

        /// <summary>
        /// Gets the <see cref="Microsoft.WindowsAPICodePack.Shell.ShellObjectThumbnail"/> in the maximum 
        /// supported size (1024x1024).
        /// </summary>
        public ShellObjectThumbnail ExtraLarge
        {
            get
            {
                return new ShellObjectThumbnail(shellItemNative, SizeExtraLarge);
            }
        }
        
        #endregion

    }
}
