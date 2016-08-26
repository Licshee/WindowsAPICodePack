//Copyright (c) Microsoft Corporation.  All rights reserved.

using System;
using System.Windows.Forms;

namespace Microsoft.WindowsAPICodePack.Shell.Taskbar
{
    /// <summary>
    /// Represents an instance of the Windows 7 taskbar
    /// </summary>
    public static class Taskbar
    {
        // Best practice recommends defining a private object to lock on
        private static Object syncLock = new Object();

        // Internal implemenation of ITaskbarList3 interface
        private static ITaskbarList3 taskbarList;
        internal static ITaskbarList3 TaskbarList
        {
            get
            {
                if (taskbarList == null)
                {
                    // Create a new instance of ITaskbarList3
                    lock (syncLock)
                    {
                        if (taskbarList == null)
                        {
                            taskbarList = (ITaskbarList3)new CTaskbarList();
                            taskbarList.HrInit();
                        }
                    }
                }

                return taskbarList;
            }
        }

        private static JumpList jumpList;
        /// <summary>
        /// Represents a taskbar's jumplist.
        /// </summary>
        public static JumpList JumpList
        {
            get
            {
                if (jumpList == null)
                {
                    lock (syncLock)
                    {
                        if (jumpList == null)
                        {
                            jumpList = new JumpList(AppID);
                        }
                    }
                }

                return jumpList;
            }
        }
        
        private static ProgressBar progressBar;
        /// <summary>
        /// Represents a taskbar button's progress bar feature.
        /// </summary>
        public static ProgressBar ProgressBar
        {
            get
            {
                if (progressBar == null)
                {
                    lock (syncLock)
                    {
                        if (progressBar == null)
                            progressBar = new ProgressBar();
                    }
                }

                return progressBar;
            }
        }

        private static OverlayImage overlayImage;
        /// <summary>
        /// Gets or sets the OverlayImage that is used to render an overlay
        /// image on the button-right hand corner of this application's
        /// taskbar button.
        /// </summary>
        public static OverlayImage OverlayImage
        {
            get
            {
                return overlayImage;
            }
            set
            {
                overlayImage = value;

                if (overlayImage == null || overlayImage.Icon == null)
                {
                    TaskbarList.SetOverlayIcon(OwnerHandle, IntPtr.Zero, string.Empty);
                }
                else
                {
                    TaskbarList.SetOverlayIcon(OwnerHandle, overlayImage.Icon.Handle, overlayImage.Text);
                }
            }
        }

        /// <summary>
        /// Gets or sets the application user model id. Use this to explicitly
        /// set the application id when generating custom jump lists.
        /// </summary>
        public static string AppID
        {
            get
            {
                return GetCurrentProcessAppId();
            }
            set
            {
                SetCurrentProcessAppId(value);
            }
        }

        private static IntPtr ownerHandle;
        /// <summary>
        /// Sets the handle of the window whose taskbar button will be used
        /// to display progress.
        /// </summary>
        internal static IntPtr OwnerHandle
        {
            get
            {
                if (ownerHandle == IntPtr.Zero)
                {
                    if (Application.OpenForms.Count > 0)
                        ownerHandle = Application.OpenForms[0].Handle;
                }

                return ownerHandle;
            }
        }

        /// <summary>
        /// Sets the current process' explicit application user model id.
        /// </summary>
        /// <param name="appId">The application id.</param>
        private static void SetCurrentProcessAppId(string appId)
        {
            TaskbarNativeMethods.SetCurrentProcessExplicitAppUserModelID(appId);
        }

        /// <summary>
        /// Gets the current process' explicit application user model id.
        /// </summary>
        /// <returns>The app id or null if no app id has been defined.</returns>
        private static string GetCurrentProcessAppId()
        {
            string appId = string.Empty;
            TaskbarNativeMethods.GetCurrentProcessExplicitAppUserModelID(out appId);
            return appId;
        }
    }
}
