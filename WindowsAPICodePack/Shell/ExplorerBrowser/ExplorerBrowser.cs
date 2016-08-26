//Copyright (c) Microsoft Corporation.  All rights reserved.

using System;
using System.Windows.Forms;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Runtime.InteropServices;
using System.Diagnostics;

namespace Microsoft.WindowsAPICodePack.Shell
{
    /// <summary>
    /// This class is a wrapper around the Windows Explorer Browser control.
    /// </summary>
    public class ExplorerBrowser : System.Windows.Forms.Control, IDisposable
    {
        #region properties
        /// <summary>
        /// Options that control how the ExplorerBrowser navigates
        /// </summary>
        public readonly ExplorerBrowserControlOptions ControlOptions;

        /// <summary>
        /// Options that control how the content of the ExplorerBorwser looks
        /// </summary>
        public readonly ExplorerBrowserContentOptions ContentOptions;
        
        internal ExplorerBrowserClass explorerBrowserControl = null;
        #endregion

        #region construction/disposal/finialization
        /// <summary>
        /// Initializes the ExplorerBorwser WinForms wrapper.
        /// </summary>
        public ExplorerBrowser( )
        {
            ControlOptions = new ExplorerBrowserControlOptions( this );
            ContentOptions = new ExplorerBrowserContentOptions( this );
        }

        bool isDisposed = false;
        /// <summary>
        /// Standard Dispose pattern
        /// </summary>
        public new void Dispose( )
        {
            Dispose( true );
        }

        /// <summary>
        /// Standard Dispose patterns 
        /// </summary>
        /// <param name="disposing"></param>
        protected override void Dispose( bool disposing )
        {
            if( isDisposed == false )
            {
                if( disposing )
                {
                    // managed cleanup
                }

                // unmanaged cleanup
                if( explorerBrowserControl != null )
                {
                    Marshal.ReleaseComObject( explorerBrowserControl );
                    explorerBrowserControl = null;
                }

                isDisposed = true;
            }

            base.Dispose( disposing );
        }

        /// <summary>
        /// Ensures the native object cleanup occurs
        /// </summary>
        ~ExplorerBrowser( )
        {
            Dispose( false );
        }
        #endregion
       
        #region operations
        /// <summary>
        /// Clears the Explorer Browser of existing content, fills it with
        /// the specified content, and adds a new point to the Travel Log.
        /// </summary>
        /// <param name="shellObject"></param>
        /// <returns></returns>
        public bool Navigate( ShellObject shellObject )
        {
            try
            {
                explorerBrowserControl.BrowseToObject( shellObject.NativeShellItem, 0 );
            }
            catch
            {
                return false;
            }

            return true;
        }

        internal IFolderView2 GetFolderView2()
        {
            Guid iid = new Guid( ExplorerBrowserIIDGuid.IFolderView2 );
            object view = null;
            try
            {
                this.explorerBrowserControl.GetCurrentView( ref iid, out view );
            }
            catch( COMException e )
            {
                // there may be no view 
                if( (long)e.ErrorCode != (long)HRESULT.E_FAIL )
                {
#if LOG_KNOWN_COM_ERRORS
                    Debugger.Log( 2, "ExplorerBrowser", "Unable to obtain view. Error=" + e.ToString( ) );
#endif
                }
                else
                    throw e;
            }

            return (IFolderView2)view;
        }

        internal IShellItemArray GetSelectedItemsArray( )
        {
            IShellItemArray iArray = null;
            IFolderView2 iFV2 = GetFolderView2( );
            if( iFV2 != null )
            {
                try
                {
                    Guid iidShellItemArray = new Guid( ShellIIDGuid.IShellItemArray );
                    object oArray = null;
                    iFV2.Items( (uint)SVGIO.SVGIO_SELECTION, ref iidShellItemArray, out oArray );
                    iArray = oArray as IShellItemArray;
                }
                catch( COMException e )
                {
                    // may be thrown with no items in view
                    if( (long)e.ErrorCode != (long)HRESULT.E_ELEMENTNOTFOUND )
                    {
#if LOG_KNOWN_COM_ERRORS
                        Debugger.Log( 3, "ExplorerBrowser", "Unable to get items array. Error=" + e.ToString( ) );
#endif
                    }
                    else
                        throw e;
                }
                finally
                {
                    Marshal.FinalReleaseComObject( iFV2 );
                    iFV2 = null;
                }
            }
            return iArray;
        }

        internal IShellItemArray GetItemsArray( )
        {
            IShellItemArray iArray = null;
            IFolderView2 iFV2 = GetFolderView2( );
            if( iFV2 != null )
            {
                try
                {
                    Guid iidShellItemArray = new Guid( ShellIIDGuid.IShellItemArray );
                    object oArray = null;
                    iFV2.Items( (uint)SVGIO.SVGIO_ALLVIEW, ref iidShellItemArray, out oArray );
                    iArray = oArray as IShellItemArray;
                }
                catch( COMException e )
                {
                    // may be thrown with no items in view
                    if( (long)e.ErrorCode != (long)HRESULT.E_ELEMENTNOTFOUND )
                    {
#if LOG_KNOWN_COM_ERRORS
                        Debugger.Log( 3, "ExplorerBrowser", "Unable to get items array. Error=" + e.ToString( ) );
#endif
                    }
                    else
                        throw e;
                }
                finally
                {
                    Marshal.FinalReleaseComObject( iFV2 );
                    iFV2 = null;
                }
            }
            return iArray;
        }

        internal IFolderView GetFolderView( )
        {
            Guid iid = new Guid( ExplorerBrowserIIDGuid.IFolderView );
            object view = null;
            this.explorerBrowserControl.GetCurrentView( ref iid, out view );

            return (IFolderView)view;
        }
        #endregion

        #region state
        /// <summary>
        /// The set of ShellObjects in the Explorer Browser
        /// </summary>
        public ShellObjectCollection Items
        {
            get
            {
                return new ShellObjectCollection( GetItemsArray( ) );
            }
        }

        /// <summary>
        /// The set of selected ShellObjects in the Explorer Browser
        /// </summary>
        public ShellObjectCollection SelectedItems
        {
            get
            {
                return new ShellObjectCollection( GetSelectedItemsArray() );
            }
        }
        #endregion

        #region message handlers

        /// <summary>
        /// Displays a placeholder for the explorer browser in design mode
        /// </summary>
        /// <param name="e"></param>
        protected override void OnPaint( PaintEventArgs e )
        {
            if( DesignMode )
            {
                LinearGradientBrush linGrBrush = new LinearGradientBrush(
                    ClientRectangle,
                    Color.Aqua,
                    Color.CadetBlue,
                    LinearGradientMode.ForwardDiagonal );
                    

                e.Graphics.FillRectangle( linGrBrush, ClientRectangle );

                StringFormat sf = new StringFormat( );
                sf.Alignment = StringAlignment.Center;
                sf.LineAlignment = StringAlignment.Center;
                e.Graphics.DrawString(
                    "ExplorerBrowserControl",
                    new Font( "Garamond", 30 ),
                    Brushes.White,
                    ClientRectangle,
                    sf);
            }
            
            base.OnPaint( e );
        }

        /// <summary>
        /// Creates and initializes the native ExplorerBrowser control
        /// </summary>
        protected override void OnCreateControl( )
        {
            base.OnCreateControl( );

            if( this.DesignMode == false )
            {
                explorerBrowserControl = new ExplorerBrowserClass( );

                CoreNativeMethods.RECT rect = new CoreNativeMethods.RECT( );
                rect.top = ClientRectangle.Top;
                rect.left = ClientRectangle.Left;
                rect.right = ClientRectangle.Right;
                rect.bottom = ClientRectangle.Bottom;

                explorerBrowserControl.Initialize( this.Handle, ref rect, null );

                ControlOptions.AlwaysNavigate = true;

                // An initial navigation is required for some of the Content options to 
                // not throw an exception.
                ShellFolder initialNav = ShellFolder.FromFolderPath( KnownFolders.Desktop );
                Navigate( initialNav );

                ContentOptions.ViewMode = ExplorerBrowserViewMode.Icon;
            }
        }
        
        /// <summary>
        /// Sizes the native control to match the WinForms control wrapper.
        /// </summary>
        /// <param name="e"></param>
        protected override void OnSizeChanged( EventArgs e )
        {
            if( explorerBrowserControl != null )
            {
                CoreNativeMethods.RECT rect = new CoreNativeMethods.RECT( );
                rect.top = ClientRectangle.Top;
                rect.left = ClientRectangle.Left;
                rect.right = ClientRectangle.Right;
                rect.bottom = ClientRectangle.Bottom;
                IntPtr ptr = IntPtr.Zero;
                explorerBrowserControl.SetRect( ref ptr, rect );
            }

            base.OnSizeChanged( e );
        }
        #endregion
    }



}