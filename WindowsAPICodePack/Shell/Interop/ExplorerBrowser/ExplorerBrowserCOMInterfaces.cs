//Copyright (c) Microsoft Corporation.  All rights reserved.

using System;
using System.Runtime.InteropServices;
using System.Runtime.InteropServices.CustomMarshalers;
using System.Runtime.InteropServices.ComTypes;
using System.Runtime.CompilerServices;
using Microsoft.WindowsAPICodePack;

namespace Microsoft.WindowsAPICodePack.Shell
{
    internal enum SVGIO : uint
    {
        SVGIO_BACKGROUND = 0x00000000,
        SVGIO_SELECTION = 0x00000001,
        SVGIO_ALLVIEW = 0x00000002,
        SVGIO_CHECKED = 0x00000003,
        SVGIO_TYPE_MASK = 0x0000000F,
        SVGIO_FLAG_VIEWORDER = 0x80000000
    }
    
    internal enum FOLDERFLAGS : uint
    {
        FWF_AUTOARRANGE = 0x00000001,
        FWF_ABBREVIATEDNAMES = 0x00000002,
        FWF_SNAPTOGRID = 0x00000004,
        FWF_OWNERDATA = 0x00000008,
        FWF_BESTFITWINDOW = 0x00000010,
        FWF_DESKTOP = 0x00000020,
        FWF_SINGLESEL = 0x00000040,
        FWF_NOSUBFOLDERS = 0x00000080,
        FWF_TRANSPARENT = 0x00000100,
        FWF_NOCLIENTEDGE = 0x00000200,
        FWF_NOSCROLL = 0x00000400,
        FWF_ALIGNLEFT = 0x00000800,
        FWF_NOICONS = 0x00001000,
        FWF_SHOWSELALWAYS = 0x00002000,
        FWF_NOVISIBLE = 0x00004000,
        FWF_SINGLECLICKACTIVATE = 0x00008000,
        FWF_NOWEBVIEW = 0x00010000,
        FWF_HIDEFILENAMES = 0x00020000,
        FWF_CHECKSELECT = 0x00040000,
        FWF_NOENUMREFRESH = 0x00080000,
        FWF_NOGROUPING = 0x00100000,
        FWF_FULLROWSELECT = 0x00200000,
        FWF_NOFILTERS = 0x00400000,
        FWF_NOCOLUMNHEADER = 0x00800000,
        FWF_NOHEADERINALLVIEWS = 0x01000000,
        FWF_EXTENDEDTILES = 0x02000000,
        FWF_TRICHECKSELECT = 0x04000000,
        FWF_AUTOCHECKSELECT = 0x08000000,
        FWF_NOBROWSERVIEWSTATE = 0x10000000,
        FWF_SUBSETGROUPS = 0x20000000,
        FWF_USESEARCHFOLDER = 0x40000000,
        FWF_ALLOWRTLREADING = 0x80000000
    }

    internal enum FOLDERVIEWMODE
    {
        FVM_AUTO = -1,
        FVM_FIRST = 1,
        FVM_ICON = 1,
        FVM_SMALLICON = 2,
        FVM_LIST = 3,
        FVM_DETAILS = 4,
        FVM_THUMBNAIL = 5,
        FVM_TILE = 6,
        FVM_THUMBSTRIP = 7,
        FVM_CONTENT = 8,
        FVM_LAST = 8
    }

    [StructLayout( LayoutKind.Sequential, Pack = 4 )]
    internal class FOLDERSETTINGS
    {
        public FOLDERVIEWMODE ViewMode;
        public FOLDERFLAGS fFlags;
    }

    internal enum EXPLORER_BROWSER_FILL_FLAGS
    {
        EBF_NODROPTARGET = 0x200,
        EBF_NONE = 0,
        EBF_SELECTFROMDATAOBJECT = 0x100
    }

    internal enum EXPLORER_BROWSER_OPTIONS
    {
        EBO_NAVIGATEONCE = 0x00000001,
        EBO_SHOWFRAMES = 0x00000002,
        EBO_ALWAYSNAVIGATE = 0x00000004,
        EBO_NOTRAVELLOG = 0x00000008,
        EBO_NOWRAPPERWINDOW = 0x00000010,
        EBO_HTMLSHAREPOINTVIEW = 0x00000020
    }

    [ComImport,
     TypeLibType( TypeLibTypeFlags.FCanCreate ),
     ClassInterface( ClassInterfaceType.None ),
     Guid( ExplorerBorwserCLSIDGuid.ExplorerBrowser )]
    internal class ExplorerBrowserClass : IExplorerBrowser
    {
        [MethodImpl( MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime )]
        public virtual extern void Advise( [MarshalAs( UnmanagedType.IUnknown )] object psbe, out uint pdwCookie );
        [MethodImpl( MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime )]
        public virtual extern void BrowseToIDList( IntPtr pidl, uint uFlags );
        [MethodImpl( MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime )]
        public virtual extern void BrowseToObject( [MarshalAs( UnmanagedType.IUnknown )] object punk, uint uFlags );
        [MethodImpl( MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime )]
        public virtual extern void Destroy( );
        [MethodImpl( MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime )]
        public virtual extern void FillFromObject( [MarshalAs( UnmanagedType.IUnknown )] object punk, int dwFlags );
        [MethodImpl( MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime )]
        public virtual extern void GetCurrentView( ref Guid riid, [MarshalAs( UnmanagedType.IUnknown )] out object ppv );
        [MethodImpl( MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime )]
        public virtual extern void GetOptions( out EXPLORER_BROWSER_OPTIONS pdwFlag );
        [MethodImpl( MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime )]
        public virtual extern void Initialize( IntPtr hwndParent, [In]ref CoreNativeMethods.RECT prc, [In] FOLDERSETTINGS pfs );
        [MethodImpl( MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime )]
        public virtual extern void RemoveAll( );
        [MethodImpl( MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime )]
        public virtual extern void SetEmptyText( [MarshalAs( UnmanagedType.LPWStr )] string pszEmptyText );
        [MethodImpl( MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime )]
        public virtual extern void SetFolderSettings( FOLDERSETTINGS pfs );
        [MethodImpl( MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime )]
        public virtual extern void SetOptions( [In]EXPLORER_BROWSER_OPTIONS dwFlag );
        [MethodImpl( MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime )]
        public virtual extern void SetPropertyBag( [MarshalAs( UnmanagedType.LPWStr )] string pszPropertyBag );
        [MethodImpl( MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime )]
        public virtual extern void SetRect( [In, Out] ref IntPtr phdwp, CoreNativeMethods.RECT rcBrowser );
        [MethodImpl( MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime )]
        public virtual extern void Unadvise( uint dwCookie );
    }


    [ComImport,
     InterfaceType( ComInterfaceType.InterfaceIsIUnknown ),
     Guid( ExplorerBrowserIIDGuid.IExplorerBrowser )]
    internal interface IExplorerBrowser
    {
        /// <summary>
        /// Prepares the browser to be navigated.
        /// </summary>
        /// <param name="hwndParent">A handle to the owner window or control.</param>
        /// <param name="prc">A pointer to a RECT containing the coordinates of the bounding rectangle 
        /// the browser will occupy. The coordinates are relative to hwndParent. If this parameter is NULL,
        /// then method IExplorerBrowser::SetRect should subsequently be called.</param>
        /// <param name="pfs">A pointer to a FOLDERSETTINGS structure that determines how the folder will be
        /// displayed in the view. If this parameter is NULL, then method IExplorerBrowser::SetFolderSettings
        /// should be called, otherwise, the default view settings for the folder are used.</param>
        /// <returns></returns>
        [MethodImpl( MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime )]
        void Initialize( IntPtr hwndParent, [In] ref CoreNativeMethods.RECT prc, [In] FOLDERSETTINGS pfs );

        /// <summary>
        /// Destroys the browser.
        /// </summary>
        /// <returns></returns>
        [MethodImpl( MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime )]
        void Destroy( );

        /// <summary>
        /// Sets the size and position of the view windows created by the browser.
        /// </summary>
        /// <param name="phdwp">A pointer to a DeferWindowPos handle. This paramater can be NULL.</param>
        /// <param name="rcBrowser">The coordinates that the browser will occupy.</param>
        /// <returns></returns>
        [MethodImpl( MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime )]
        void SetRect( [In, Out] ref IntPtr phdwp, CoreNativeMethods.RECT rcBrowser );

        /// <summary>
        /// Sets the name of the property bag.
        /// </summary>
        /// <param name="pszPropertyBag">A pointer to a constant, null-terminated, Unicode string that contains
        /// the name of the property bag. View state information that is specific to the application of the 
        /// client is stored (persisted) using this name.</param>
        /// <returns></returns>
        [MethodImpl( MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime )]
        void SetPropertyBag( [MarshalAs( UnmanagedType.LPWStr )] string pszPropertyBag );

        /// <summary>
        /// Sets the default empty text.
        /// </summary>
        /// <param name="pszEmptyText">A pointer to a constant, null-terminated, Unicode string that contains 
        /// the empty text.</param>
        /// <returns></returns>
        [MethodImpl( MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime )]
        void SetEmptyText( [MarshalAs( UnmanagedType.LPWStr )] string pszEmptyText );

        /// <summary>
        /// Sets the folder settings for the current view.
        /// </summary>
        /// <param name="pfs">A pointer to a FOLDERSETTINGS structure that contains the folder settings 
        /// to be applied.</param>
        /// <returns></returns>
        [MethodImpl( MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime )]
        void SetFolderSettings( FOLDERSETTINGS pfs );

        /// <summary>
        /// Initiates a connection with IExplorerBrowser for event callbacks.
        /// </summary>
        /// <param name="psbe">A pointer to the IExplorerBrowserEvents interface of the object to be 
        /// advised of IExplorerBrowser events</param>
        /// <param name="pdwCookie">When this method returns, contains a token that uniquely identifies 
        /// the event listener. This allows several event listeners to be subscribed at a time.</param>
        /// <returns></returns>
        [MethodImpl( MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime )]
        void Advise( [MarshalAs( UnmanagedType.IUnknown )] object psbe, out uint pdwCookie );

        /// <summary>
        /// Terminates an advisory connection.
        /// </summary>
        /// <param name="dwCookie">A connection token previously returned from IExplorerBrowser::Advise.
        /// Identifies the connection to be terminated.</param>
        /// <returns></returns>
        [MethodImpl( MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime )]
        void Unadvise( [In] uint dwCookie );

        /// <summary>
        /// Sets the current browser options.
        /// </summary>
        /// <param name="dwFlag">One or more EXPLORER_BROWSER_OPTIONS flags to be set.</param>
        /// <returns></returns>
        [MethodImpl( MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime )]
        void SetOptions( [In]EXPLORER_BROWSER_OPTIONS dwFlag );

        /// <summary>
        /// Gets the current browser options.
        /// </summary>
        /// <param name="pdwFlag">When this method returns, contains the current EXPLORER_BROWSER_OPTIONS 
        /// for the browser.</param>
        /// <returns></returns>
        [MethodImpl( MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime )]
        void GetOptions( out EXPLORER_BROWSER_OPTIONS pdwFlag );

        /// <summary>
        /// Browses to a pointer to an item identifier list (PIDL)
        /// </summary>
        /// <param name="pidl">A pointer to a const ITEMIDLIST (item identifier list) that specifies an object's 
        /// location as the destination to navigate to. This parameter can be NULL.</param>
        /// <param name="uFlags">A flag that specifies the category of the pidl. This affects how 
        /// navigation is accomplished</param>
        /// <returns></returns>
        [MethodImpl( MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime )]
        void BrowseToIDList( IntPtr pidl, uint uFlags );

        /// <summary>
        /// Browse to an object
        /// </summary>
        /// <param name="punk">A pointer to an object to browse to. If the object cannot be browsed, 
        /// an error value is returned.</param>
        /// <param name="uFlags">A flag that specifies the category of the pidl. This affects how 
        /// navigation is accomplished. </param>
        /// <returns></returns>
        [MethodImpl( MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime )]
        void BrowseToObject( [MarshalAs( UnmanagedType.IUnknown )] object punk, uint uFlags );

        /// <summary>
        /// Creates a results folder and fills it with items.
        /// </summary>
        /// <param name="punk">An interface pointer on the source object that will fill the IResultsFolder</param>
        /// <param name="dwFlags">One of the EXPLORER_BROWSER_FILL_FLAGS</param>
        /// <returns></returns>
        [MethodImpl( MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime )]
        void FillFromObject( [MarshalAs( UnmanagedType.IUnknown )] object punk, int dwFlags );

        /// <summary>
        /// Removes all items from the results folder.
        /// </summary>
        /// <returns></returns>
        [MethodImpl( MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime )]
        void RemoveAll( );

        /// <summary>
        /// Gets an interface for the current view of the browser.
        /// </summary>
        /// <param name="riid">A reference to the desired interface ID.</param>
        /// <param name="ppv">When this method returns, contains the interface pointer requested in riid. 
        /// This will typically be IShellView or IShellView2. </param>
        /// <returns></returns>
        [MethodImpl( MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime )]
        void GetCurrentView( ref Guid riid, [MarshalAs( UnmanagedType.IUnknown )] out object ppv );
    }

    [ComImport,
     Guid( ExplorerBrowserIIDGuid.IFolderView ),
     InterfaceType( ComInterfaceType.InterfaceIsIUnknown )]
    internal interface IFolderView
    {
        [MethodImpl( MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime )]
        void GetCurrentViewMode( [Out] out uint pViewMode );

        [MethodImpl( MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime )]
        void SetCurrentViewMode( uint ViewMode );

        [MethodImpl( MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime )]
        void GetFolder( ref Guid riid, [MarshalAs( UnmanagedType.IUnknown )] out object ppv );

        [MethodImpl( MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime )]
        void Item( int iItemIndex, out IntPtr ppidl );

        [MethodImpl( MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime )]
        void ItemCount( uint uFlags, out int pcItems );

        [MethodImpl( MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime )]
        void Items( uint uFlags, ref Guid riid, [Out, MarshalAs( UnmanagedType.IUnknown )] out object ppv );

        [MethodImpl( MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime )]
        void GetSelectionMarkedItem( out int piItem );

        [MethodImpl( MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime )]
        void GetFocusedItem( out int piItem );

        [MethodImpl( MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime )]
        void GetItemPosition( IntPtr pidl, out CoreNativeMethods.POINT ppt );

        [MethodImpl( MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime )]
        void GetSpacing( [Out] out CoreNativeMethods.POINT ppt );

        [MethodImpl( MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime )]
        void GetDefaultSpacing( out CoreNativeMethods.POINT ppt );

        [MethodImpl( MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime )]
        void GetAutoArrange( );

        [MethodImpl( MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime )]
        void SelectItem( int iItem, uint dwFlags );

        [MethodImpl( MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime )]
        void SelectAndPositionItems( uint cidl, IntPtr apidl, ref CoreNativeMethods.POINT apt, uint dwFlags );
    }

    [ComImport,
     Guid( ExplorerBrowserIIDGuid.IFolderView2 ),
     InterfaceType( ComInterfaceType.InterfaceIsIUnknown )]
    internal interface IFolderView2 : IFolderView
    {
        // Sets the group by property and starts a grouping operation
        [MethodImpl( MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime )]
        void SetGroupBy( IntPtr key, bool fAscending );

        [MethodImpl( MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime )]
        void GetGroupBy( ref IntPtr pkey, ref bool pfAscending );

        [MethodImpl( MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime )]
        void SetViewProperty( IntPtr pidl, IntPtr propkey, object propvar );

        [MethodImpl( MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime )]
        void GetViewProperty( IntPtr pidl, IntPtr propkey, out object ppropvar );

        [MethodImpl( MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime )]
        void SetTileViewProperties( IntPtr pidl, [MarshalAs( UnmanagedType.LPWStr )] string pszPropList );

        [MethodImpl( MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime )]
        void SetExtendedTileViewProperties( IntPtr pidl, [MarshalAs( UnmanagedType.LPWStr )] string pszPropList );

        [MethodImpl( MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime )]
        void SetText( int iType, [MarshalAs( UnmanagedType.LPWStr )] string pwszText );

        [MethodImpl( MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime )]
        void SetCurrentFolderFlags( uint dwMask, uint dwFlags );

        [MethodImpl( MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime )]
        void GetCurrentFolderFlags( out uint pdwFlags );

        [MethodImpl( MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime )]
        void GetSortColumnCount( out int pcColumns );

        [MethodImpl( MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime )]
        void SetSortColumns( IntPtr rgSortColumns, int cColumns );

        [MethodImpl( MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime )]
        void GetSortColumns( out IntPtr rgSortColumns, int cColumns );

        [MethodImpl( MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime )]
        void GetItem( int iItem, ref Guid riid, [MarshalAs( UnmanagedType.IUnknown )] out object ppv );

        [MethodImpl( MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime )]
        void GetVisibleItem( int iStart, bool fPrevious, out int piItem );

        [MethodImpl( MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime )]
        void GetSelectedItem( int iStart, out int piItem );

        [MethodImpl( MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime )]
        void GetSelection( bool fNoneImpliesFolder, out IShellItemArray ppsia );

        [MethodImpl( MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime )]
        void GetSelectionState( IntPtr pidl, out uint pdwFlags );

        [MethodImpl( MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime )]
        void InvokeVerbOnSelection( [In, MarshalAs( UnmanagedType.LPWStr )] string pszVerb );

        [MethodImpl( MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime )]
        void SetViewModeAndIconSize( int uViewMode, int iImageSize );

        [MethodImpl( MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime )]
        void GetViewModeAndIconSize( out int puViewMode, out int piImageSize );

        [MethodImpl( MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime )]
        void SetGroupSubsetCount( uint cVisibleRows );

        [MethodImpl( MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime )]
        void GetGroupSubsetCount( out uint pcVisibleRows );

        [MethodImpl( MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime )]
        void SetRedraw( bool fRedrawOn );

        [MethodImpl( MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime )]
        void IsMoveInSameFolder( );

        [MethodImpl( MethodImplOptions.InternalCall, MethodCodeType = MethodCodeType.Runtime )]
        void DoRename( );
    }


}
