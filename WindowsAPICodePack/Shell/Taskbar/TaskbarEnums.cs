//Copyright (c) Microsoft Corporation.  All rights reserved.

namespace Microsoft.WindowsAPICodePack.Shell.Taskbar
{
    /// <summary>
    /// Known category to display
    /// </summary>
    public enum KnownCategoryType
    {
        /// <summary>
        /// Don't display either known category. You must have at least one
        /// user task or custom category link in order to not see the
        /// default 'Recent' known category
        /// </summary>
        Neither = 0,

        /// <summary>
        /// Display the 'Recent' known category
        /// </summary>
        Recent,

        /// <summary>
        /// Display the 'Frequent' known category
        /// </summary>
        Frequent,

        /// <summary>
        /// Display both the 'Recent' and 'Frequent' known categories
        /// </summary>
        Both
    }

    /// <summary>
    /// Location to place known category or categories
    /// </summary>
    public enum KnownCategoryLocationType
    {
        /// <summary>
        /// Display the known categories on the top of the taskbar list
        /// </summary>
        Top = 1,

        /// <summary>
        /// Display the known categories on the bottom of the taskbar
        /// destination list. User tasks always appear at the bottom
        /// of the taskbar list.
        /// </summary>
        Bottom
    }

    /// <summary>
    /// Flags controlling the appearance of a window
    /// </summary>
    public enum WindowShowCommand : uint
    {
        /// <summary>
        /// Hides the window and activates another window.
        /// </summary>
        Hide = 0,

        /// <summary>
        /// Activates and displays the window (including restoring
        /// it to its original size and position).
        /// </summary>
        Normal = 1,
        
        /// <summary>
        /// Minimizes the window.
        /// </summary>
        Minimized = 2,
        
        /// <summary>
        /// Maximizes the window.
        /// </summary>
        Maximized = 3,
        
        /// <summary>
        /// Similar to <see cref="Normal"/>, except that the window
        /// is not activated.
        /// </summary>
        ShowNoActivate = 4,
        
        /// <summary>
        /// Activates the window and displays it in its current size
        /// and position.
        /// </summary>
        Show = 5,
        
        /// <summary>
        /// Minimizes the window and activates the next top-level window.
        /// </summary>
        Minimize = 6,
        
        /// <summary>
        /// Minimizes the window and does not activate it.
        /// </summary>
        ShowMinimizedNoActivate = 7,
        
        /// <summary>
        /// Similar to <see cref="Normal"/>, except that the window is not
        /// activated.
        /// </summary>
        ShowNA = 8,
        
        /// <summary>
        /// Activates and displays the window, restoring it to its original
        /// size and position.
        /// </summary>
        Restore = 9,
        
        /// <summary>
        /// Sets the show state based on the initial value specified when
        /// the process was created.
        /// </summary>
        Default = 10,
        
        /// <summary>
        /// Minimizes a window, even if the thread owning the window is not
        /// responding.  Use this only to minimize windows from a different
        /// thread.
        /// </summary>
        ForceMinimize = 11
    }

    /// <summary>
    /// Represents the thumbnail progress bar state.
    /// </summary>
    public enum TaskbarButtonProgressState
    {
        /// <summary>
        /// No progress is displayed.
        /// </summary>
        NoProgress = 0,

        /// <summary>
        /// The progress is indeterminate (marquee).
        /// </summary>
        Indeterminate = 0x1,

        /// <summary>
        /// Normal progress is displayed.
        /// </summary>
        Normal = 0x2,

        /// <summary>
        /// An error occurred (red).
        /// </summary>
        Error = 0x4,

        /// <summary>
        /// The operation is paused (yellow).
        /// </summary>
        Paused = 0x8
    }
}
