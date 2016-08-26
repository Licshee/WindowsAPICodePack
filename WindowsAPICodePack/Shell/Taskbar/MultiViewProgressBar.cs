//Copyright (c) Microsoft Corporation.  All rights reserved.

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows;
using System.Windows.Forms;
using System.Windows.Interop;

namespace Microsoft.WindowsAPICodePack.Shell.Taskbar
{
    /// <summary>
    /// Represents the progress bar feature on the Taskbar button for multiple windows 
    /// or window handles.
    /// </summary>
    public class MultiViewProgressBar
    {
        private static ProgressBarStateSettings progressBarSettings = ProgressBarStateSettings.Instance;

        internal MultiViewProgressBar()
        {

        }

        /// <summary>
        /// Sets the current value of the progress bar associated with 
        /// the given window handle (HWND).
        /// </summary>
        /// <param name="hwnd">IntPtr to the window handle for the progress bar</param>
        /// <param name="value">Current progress bar value associated with the given window handle</param>
        public void SetCurrentValue(IntPtr hwnd, int value)
        {
            // Check for range
            if (progressBarSettings.MaxValues.ContainsKey(hwnd) && value > progressBarSettings.MaxValues[hwnd])
                throw new System.ArgumentOutOfRangeException("CurrentValue value provided must be less than or equal to the maximum value", "value");

            // Check for negative numbers
            if (value < 0)
                throw new System.ArgumentOutOfRangeException("CurrentValue value provided must be a positive number", "value");

            if (progressBarSettings.CurrentValues.ContainsKey(hwnd))
            {
                if (progressBarSettings.CurrentValues[hwnd] != value)
                    progressBarSettings.CurrentValues[hwnd] = value;
            }
            else
                progressBarSettings.CurrentValues.Add(hwnd, value);

            // Refresh value
            progressBarSettings.RefreshValue(hwnd, GetCurrentValue(hwnd), GetMaxValue(hwnd));
        }

        /// <summary>
        /// Gets the current value of the progress bar associated 
        /// with the given window handle (HWND).
        /// </summary>
        /// <param name="hwnd">IntPtr to the window handle for the progress bar</param>
        /// <returns>Current progress bar value associated with the given window handle</returns>
        public int GetCurrentValue(IntPtr hwnd)
        {
            return progressBarSettings.CurrentValues[hwnd];
        }

        /// <summary>
        /// Sets the current value of the progress bar associated with 
        /// the given window.
        /// </summary>
        /// <param name="window">Reference to <see cref="System.Windows.Window"/> for the progress bar</param>
        /// <param name="value">Current progress bar value associated with the given window</param>
        public void SetCurrentValue(Window window, int value)
        {
            // Check for null
            if (window == null)
                throw new ArgumentNullException("window");

            WindowInteropHelper helper = new WindowInteropHelper(window);
            IntPtr hwnd = helper.Handle;

            SetCurrentValue(hwnd, value);
        }

        /// <summary>
        /// Gets the current value of the progress bar associated 
        /// with the given window.
        /// </summary>
        /// <param name="window">Reference to <see cref="System.Windows.Window"/> for the progress bar</param>
        /// <returns>Current progress bar value associated with the given window</returns>
        public int GetCurrentValue(Window window)
        {
            if (window == null)
                throw new ArgumentNullException("window");

            WindowInteropHelper helper = new WindowInteropHelper(window);
            IntPtr hwnd = helper.Handle;

            return progressBarSettings.CurrentValues[hwnd];
        }

        /// <summary>
        /// Sets the current value of the progress bar associated with 
        /// the given <see cref="System.Windows.Forms.Form"/>.
        /// </summary>
        /// <param name="form">Reference to <see cref="System.Windows.Forms.Form"/> for the progress bar</param>
        /// <param name="value">Current progress bar value associated with the given form</param>
        public void SetCurrentValue(Form form, int value)
        {
            // Check for null
            if (form == null)
                throw new ArgumentNullException("form");

            IntPtr hwnd = form.Handle;

            SetCurrentValue(hwnd, value);
        }

        /// <summary>
        /// Gets the current value of the progress bar associated 
        /// with the given form.
        /// </summary>
        /// <param name="form">Reference to <see cref="System.Windows.Forms.Form"/> for the progress bar</param>
        /// <returns>Current progress bar value associated with the given form</returns>
        public int GetCurrentValue(Form form)
        {
            if (form == null)
                throw new ArgumentNullException("form");

            IntPtr hwnd = form.Handle;

            return progressBarSettings.CurrentValues[hwnd];
        }

        /// <summary>
        /// Sets the maximum value of the progress bar associated with 
        /// the given window handle (HWND).
        /// </summary>
        /// <param name="hwnd">IntPtr to the window handle for the progress bar</param>
        /// <param name="value">Maximum progress bar value associated with the given window handle</param>
        public void SetMaxValue(IntPtr hwnd, int value)
        {
            if (progressBarSettings.MaxValues.ContainsKey(hwnd))
            {
                if (progressBarSettings.MaxValues[hwnd] != value)
                    progressBarSettings.MaxValues[hwnd] = value;
            }
            else
                progressBarSettings.MaxValues.Add(hwnd, value);

            // Refresh value
            progressBarSettings.RefreshValue(hwnd, GetCurrentValue(hwnd), GetMaxValue(hwnd));
        }

        /// <summary>
        /// Gets the maximum value of the progress bar associated 
        /// with the given window handle (HWND).
        /// </summary>
        /// <param name="hwnd">IntPtr to the window handle for the progress bar</param>
        /// <returns>Maximum progress bar value associated with the given window handle</returns>
        public int GetMaxValue(IntPtr hwnd)
        {
            if (!progressBarSettings.MaxValues.ContainsKey(hwnd))
                progressBarSettings.MaxValues.Add(hwnd, progressBarSettings.DefaultMaxValue);

            return progressBarSettings.MaxValues[hwnd];
        }

        /// <summary>
        /// Sets the maximum value of the progress bar associated with 
        /// the given window.
        /// </summary>
        /// <param name="window">Reference to <see cref="System.Windows.Window"/> for the progress bar</param>
        /// <param name="value">Maximum progress bar value associated with the given window</param>
        public void SetMaxValue(Window window, int value)
        {
            if (window == null)
                throw new ArgumentNullException("window");

            WindowInteropHelper helper = new WindowInteropHelper(window);
            IntPtr hwnd = helper.Handle;

            SetMaxValue(hwnd, value);
        }

        /// <summary>
        /// Gets the maximum value of the progress bar associated 
        /// with the given window.
        /// </summary>
        /// <param name="window">Reference to <see cref="System.Windows.Window"/> for the progress bar</param>
        /// <returns>Maximum progress bar value associated with the given window</returns>
        public int GetMaxValue(Window window)
        {
            if (window == null)
                throw new ArgumentNullException("window");

            WindowInteropHelper helper = new WindowInteropHelper(window);
            IntPtr hwnd = helper.Handle;

            if (!progressBarSettings.MaxValues.ContainsKey(hwnd))
                progressBarSettings.MaxValues.Add(hwnd, progressBarSettings.DefaultMaxValue);

            return progressBarSettings.MaxValues[hwnd];

        }

        /// <summary>
        /// Sets the maximum value of the progress bar associated with 
        /// the given <see cref="System.Windows.Forms.Form"/>.
        /// </summary>
        /// <param name="form">Reference to <see cref="System.Windows.Forms.Form"/> for the progress bar</param>
        /// <param name="value">Maximum progress bar value associated with the given form</param>
        public void SetMaxValue(Form form, int value)
        {
            if (form == null)
                throw new ArgumentNullException("form");

            IntPtr hwnd = form.Handle;

            SetMaxValue(hwnd, value);
        }

        /// <summary>
        /// Gets the maximum value of the progress bar associated 
        /// with the given form.
        /// </summary>
        /// <param name="form">Reference to <see cref="System.Windows.Forms.Form"/> for the progress bar</param>
        /// <returns>Maximum progress bar value associated with the given form</returns>
        public int GetMaxValue(Form form)
        {
            if (form == null)
                throw new ArgumentNullException("form");

            IntPtr hwnd = form.Handle;

            if (!progressBarSettings.MaxValues.ContainsKey(hwnd))
                progressBarSettings.MaxValues.Add(hwnd, progressBarSettings.DefaultMaxValue);

            return progressBarSettings.MaxValues[hwnd];
        }

        /// <summary>
        /// Sets the current state of the progress bar associated with 
        /// the given window handle (HWND).
        /// </summary>
        /// <param name="hwnd">IntPtr to the window handle for the progress bar</param>
        /// <param name="state">Current progress bar state associated with the given window handle</param>
        public void SetState(IntPtr hwnd, TaskbarButtonProgressState state)
        {
            if (progressBarSettings.States.ContainsKey(hwnd))
            {
                if (progressBarSettings.States[hwnd] != state)
                    progressBarSettings.States[hwnd] = state;
            }
            else
                progressBarSettings.States.Add(hwnd, state);

            // Refresh state
            progressBarSettings.RefreshState(hwnd, state);
        }

        /// <summary>
        /// Gets the current state of the progress bar associated 
        /// with the given window handle (HWND).
        /// </summary>
        /// <param name="hwnd">IntPtr to the window handle for the progress bar</param>
        /// <returns>Current progress bar state associated with the given window handle</returns>
        public TaskbarButtonProgressState GetState(IntPtr hwnd)
        {
            return progressBarSettings.States[hwnd];
        }

        /// <summary>
        /// Sets the current state of the progress bar associated with 
        /// the given window.
        /// </summary>
        /// <param name="window">Reference to <see cref="System.Windows.Window"/> for the progress bar</param>
        /// <param name="state">Current progress bar state associated with the given window</param>
        public void SetState(Window window, TaskbarButtonProgressState state)
        {
            WindowInteropHelper helper = new WindowInteropHelper(window);
            IntPtr hwnd = helper.Handle;

            SetState(hwnd, state);
        }

        /// <summary>
        /// Gets the current state of the progress bar associated 
        /// with the given window.
        /// </summary>
        /// <param name="window">Reference to <see cref="System.Windows.Window"/> for the progress bar</param>
        /// <returns>Current progress bar state associated with the given window</returns>
        public TaskbarButtonProgressState GetState(Window window)
        {
            if (window == null)
                throw new ArgumentNullException("window");

            WindowInteropHelper helper = new WindowInteropHelper(window);
            IntPtr hwnd = helper.Handle;

            return progressBarSettings.States[hwnd];
        }

        /// <summary>
        /// Sets the current state of the progress bar associated with 
        /// the given <see cref="System.Windows.Forms.Form"/>.
        /// </summary>
        /// <param name="form">Reference to <see cref="System.Windows.Forms.Form"/> for the progress bar</param>
        /// <param name="state">Current progress bar state associated with the given form</param>
        public void SetState(Form form, TaskbarButtonProgressState state)
        {
            if (form == null)
                throw new ArgumentNullException("form");

            IntPtr hwnd = form.Handle;

            SetState(hwnd, state);
        }

        /// <summary>
        /// Gets the current state of the progress bar associated 
        /// with the given form.
        /// </summary>
        /// <param name="form">Reference to <see cref="System.Windows.Forms.Form"/> for the progress bar</param>
        /// <returns>Current progress bar state associated with the given form</returns>
        public TaskbarButtonProgressState GetState(Form form)
        {
            if (form == null)
                throw new ArgumentNullException("form");

            IntPtr hwnd = form.Handle;

            return progressBarSettings.States[hwnd];
        }
    }
}
