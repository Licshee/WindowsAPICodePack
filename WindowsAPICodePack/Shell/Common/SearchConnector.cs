//Copyright (c) Microsoft Corporation.  All rights reserved.

using System;
using System.Collections.Generic;

namespace Microsoft.WindowsAPICodePack.Shell
{
    /// <summary>
    /// A Serch Connector folder in the Shell Namespace
    /// </summary>
    public sealed class SearchConnector : ShellObject, IShellContainer<ShellFileSystemObject>
    {

        #region Private Constructor

        private SearchConnector() { }

        #endregion

        #region Internal Fields

        internal const string FileExtension = ".searchConnector-ms";

        #endregion

        #region Internal Properties

        internal override IShellItem NativeShellItem
        {
            get 
            {
                return NativeShellItem2;
            }
        }

        internal override IShellItem2 NativeShellItem2
        {
            get
            {
                return nativeShellItem;
            }
        }

        #endregion

        #region Internal Methods

        /// <summary>
        /// Creates a SearchConnector given a native IShellItem interface
        /// </summary>
        /// <param name="nativeShellItem"></param>
        /// <returns>A newly constructed SearchConnector object</returns>
        new internal static SearchConnector FromShellItem(IShellItem nativeShellItem)
        {
            SearchConnector connector = new SearchConnector();
            connector.nativeShellItem = (IShellItem2)nativeShellItem;
            return connector;
        }

        #endregion

        #region Public Methods
        
        /// <summary>
        /// Creates a SearchConnector given a path to the search connector file
        /// </summary>
        /// <param name="path"></param>
        /// <returns>A newly constructed SearchConnector object</returns>
        new static public SearchConnector FromPath(string path)
        {
            if (string.IsNullOrEmpty(path))
                throw new ArgumentNullException("path");

            throw new NotImplementedException();
        }

        #endregion

        #region IEnumerator<ShellFileSystemObject> Members

        /// <summary>
        /// 
        /// </summary>
        public ShellFileSystemObject Current
        {
            get { throw new NotImplementedException(); }
        }

        #endregion

        #region IEnumerable<ShellFileSystemObject> Members

        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        public IEnumerator<ShellFileSystemObject> GetEnumerator()
        {
            throw new NotImplementedException();
        }

        #endregion

        #region IEnumerable Members

        System.Collections.IEnumerator System.Collections.IEnumerable.GetEnumerator()
        {
            throw new NotImplementedException();
        }

        #endregion
    }
}
