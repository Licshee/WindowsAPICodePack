//Copyright (c) Microsoft Corporation.  All rights reserved.

using System;

namespace Microsoft.WindowsAPICodePack.Shell.Taskbar
{
    /// <summary>
    /// Represents a taskbar button's progress bar functionality
    /// </summary>
    public class ProgressBar
    {
        #region Properties
        private int currentValue = 0;
        /// <summary>
        /// Gets or sets the current value of the progress bar.
        /// </summary>
        public int CurrentValue
        {
            get { return currentValue; }
            set
            {
                // Update this value only if different
                if (currentValue == value)
                    return;

                currentValue = value;

                RefreshValue();
            }
        }

        private int maxValue = 100;
        /// <summary>
        /// Gets or sets the maximun value of the taskbar. Default value is 100.
        /// </summary>
        public int MaxValue
        {
            get { return maxValue; }
            set
            {
                // Update this value only if different
                if (maxValue == value)
                    return;

                maxValue = value;

                RefreshValue();
            }
        }

        private TaskbarButtonProgressState state = TaskbarButtonProgressState.NoProgress;
        /// <summary>
        /// Gets or sets the current progress bar state.
        /// </summary>
        public TaskbarButtonProgressState State
        {
            get { return state; }
            set
            {
                // Update this value only if different
                if (State == value)
                    return;

                state = value;

                // Refresh taskbar state
                RefreshState();
            }
        }
        #endregion

        internal ProgressBar()
        {
            // Refresh the UI
            RefreshState();
            RefreshValue();
        }

        private void RefreshValue()
        {
            Taskbar.TaskbarList.SetProgressValue(Taskbar.OwnerHandle, (ulong)CurrentValue, (ulong)MaxValue);
        }

        private void RefreshState()
        {
            Taskbar.TaskbarList.SetProgressState(Taskbar.OwnerHandle, (TBPFLAG)state);
        }
    }
}
