//Copyright (c) Microsoft Corporation.  All rights reserved.

using System;
using System.Diagnostics;
using System.Drawing;
using System.IO;
using System.Runtime.InteropServices;
using System.Text;
using System.Windows;
using System.Windows.Media.Imaging;

namespace Microsoft.WindowsAPICodePack
{
    /// <summary>
    /// Common Helper methods
    /// </summary>
    static public class CoreHelpers
    {
        /// <summary>
        /// Determine the main owner window for the currently running WPF application
        /// </summary>
        /// <returns>Owner window, if one is found. Otherwise, returns null.</returns>
        public static Window GetDefaultOwnerWindow()
        {
            Window defaultWindow = null;

            if (Application.Current != null && Application.Current.MainWindow != null)
            {
                defaultWindow = Application.Current.MainWindow;
            }
            return defaultWindow;
        }

        /// <summary>
        /// Determines if the application is running on Vista
        /// </summary>
        public static bool RunningOnVista
        {
            get
            {
                return Environment.OSVersion.Version.Major >= 6;
            }
        }

        /// <summary>
        /// Determines if the application is running on Windows 7
        /// </summary>
        public static bool RunningOnWin7
        {
            get
            {
                return (Environment.OSVersion.Version.Major > 6) || 
                    (Environment.OSVersion.Version.Major == 6 && Environment.OSVersion.Version.Minor >= 1);
            }
        }

        /// <summary>
        /// Get a string resource given a resource Id
        /// </summary>
        /// <param name="resourceId">The resource Id</param>
        /// <returns>The string resource corresponding to the given resource Id</returns>
        public static string GetStringResource(string resourceId)
        {
            string[] parts;
            string library;
            int index;

            if (String.IsNullOrEmpty(resourceId))
            {
                return String.Empty;
            }
            // Known folder "Recent" has a malformed resource id
            // for its tooltip. This causes the resource id to
            // parse into 3 parts instead of 2 parts if we don't fix.
            resourceId = resourceId.Replace("shell32,dll", "shell32.dll");
            parts = resourceId.Split(new char[] { ',' });

            library = parts[0];
            library = library.Replace(@"@", String.Empty);

            parts[1] = parts[1].Replace("-", String.Empty);
            index = Int32.Parse(parts[1]);

            library = Environment.ExpandEnvironmentVariables(library);
            IntPtr handle = CoreNativeMethods.LoadLibrary(library);
            StringBuilder stringValue = new StringBuilder(255);
            int retval = CoreNativeMethods.LoadString(
                handle, index, stringValue, 255);

            if (retval == 0)
            {
                int error = Marshal.GetLastWin32Error();
                throw new System.ComponentModel.Win32Exception(error);
            }
            return stringValue.ToString();
        }

        /// <summary>
        /// Gets the bitmap of an icon resource given a resource Id
        /// </summary>
        /// <param name="iconResourceId">The resource Id</param>
        /// <returns>A BitmapSource object for this icon, or null if no icon is found for the resource Id</returns>
        public static BitmapSource GetIcon(string iconResourceId)
        {
            string[] parts;
            string library;
            int index;
            BitmapSource bms;

            if (String.IsNullOrEmpty(iconResourceId))
                return null;

            parts = iconResourceId.Split(new char[] { ',' });
            Debug.Assert(parts.Length == 2);
            library = parts[0];
            library = library.Replace("@", "");
            index = Int32.Parse(parts[1]);

            SafeIconHandle hIcon = CoreNativeMethods.ExtractIcon(
                Process.GetCurrentProcess().Handle,
                library,
                index);

            if (hIcon == null)
                throw new FileNotFoundException("Can't find icon.");

            Bitmap bmp = Bitmap.FromHicon(hIcon.DangerousGetHandle());

            using (MemoryStream stream = new MemoryStream())
            {
                bmp.Save(stream, System.Drawing.Imaging.ImageFormat.Png);
                stream.Seek(0, SeekOrigin.Begin);
                // Need to create the frame with OnLoad to 
                // allow the stream to be closed.
                BitmapFrame bf = BitmapFrame.Create(
                    stream,
                    BitmapCreateOptions.None,
                    BitmapCacheOption.OnLoad);

                bms = bf;
            }
            hIcon.SetHandleAsInvalid();
            return bms;
        }
    }
}
