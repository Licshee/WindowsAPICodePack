//Copyright (c) Microsoft Corporation.  All rights reserved.

using System;
using System.IO;
using System.Runtime.InteropServices;
namespace Microsoft.WindowsAPICodePack.Shell
{
    /// <summary>
    /// A helper class for Shell Objects
    /// </summary>
    internal sealed class ShellHelper
    {
        /// <summary>
        /// Checks if this item is a library
        /// </summary>
        /// <param name="shellItem"></param>
        /// <returns></returns>
        internal static bool IsLibrary(IShellItem shellItem) 
        {
            string path;

            path = GetParsingName(shellItem);

            return ShellHelper.IsLibrary(path);
        }

        /// <summary>
        /// Checks if this item is a folder
        /// </summary>
        /// <param name="shellItem"></param>
        /// <returns></returns>
        internal static bool IsFolder(IShellItem shellItem)
        {
            ShellNativeMethods.SFGAO sfgao;
            shellItem.GetAttributes(ShellNativeMethods.SFGAO.SFGAO_FOLDER, out sfgao);
            return (sfgao & ShellNativeMethods.SFGAO.SFGAO_FOLDER) != 0;
        }

        internal static string GetParsingName(IShellItem shellItem)
        {
            string path = null;
            try
            {
                shellItem.GetDisplayName(ShellNativeMethods.SIGDN.SIGDN_FILESYSPATH, out path);
            }
            catch (COMException) { }
            catch (ArgumentException) { }

            if (path == null)
            {
                shellItem.GetDisplayName(ShellNativeMethods.SIGDN.SIGDN_DESKTOPABSOLUTEPARSING, out path);
            }
            return path;
        }

        /// <summary>
        /// Checks if this path is that of a library (XML) file
        /// </summary>
        /// <param name="filePath"></param>
        /// <returns></returns>
        internal static bool IsLibrary(string filePath) 
        {
            return (Path.GetExtension(filePath) == ShellLibrary.FileExtension);
        }

        internal static IntPtr PidlFromParsingName(string name)
        {
            IntPtr pidl;

            ShellNativeMethods.SFGAO sfgao;
            int retCode = ShellNativeMethods.SHParseDisplayName(name, IntPtr.Zero, out pidl, (ShellNativeMethods.SFGAO)0,
                out sfgao);

            return (CoreErrorHelper.Succeeded(retCode) ? pidl : IntPtr.Zero);
        }

        internal static IntPtr PidlFromShellItem(IShellItem nativeShellItem)
        {
            return ShellHelper.PidlFromParsingName(GetParsingName(nativeShellItem));
        }

        /// <summary>
        /// Checks if this item is a Known folder
        /// </summary>
        /// <param name="shellItem"></param>
        /// <returns></returns>
        internal static bool IsKnownFolder(IShellItem shellItem)
        {
            ShellNativeMethods.SFGAO sfgao;
            shellItem.GetAttributes(ShellNativeMethods.SFGAO.SFGAO_FOLDER, out sfgao);

            string path = GetParsingName(shellItem);

            if (((sfgao & ShellNativeMethods.SFGAO.SFGAO_FOLDER) != 0) && path.StartsWith("::"))
            {
                // It's probably a special folder, do one more test
                IntPtr pidl = ShellHelper.PidlFromParsingName(path);
                
                if (pidl == IntPtr.Zero)
                {
                    return false;
                }

                try
                {
                    return KnownFolderManager.GetKnownFolderFromPIDL(pidl) != null;
                }
                catch (COMException)
                {
                    return false;
                }
            }
            // Get shellItem's IDList, then use IKnownFolder FindFolderFromIDList method
            return false;
        }

        /// <summary>
        /// Checks if this item is a Search Connector
        /// </summary>
        /// <param name="shellItem"></param>
        /// <returns></returns>
        internal static bool IsSearchConnector(IShellItem shellItem)
        {
            string path = GetParsingName(shellItem);

            return IsSearchConnector(path);
        }

        /// <summary>
        /// Checks if this path is that of a Search Connector (XML) file
        /// </summary>
        /// <param name="filePath"></param>
        /// <returns></returns>
        internal static bool IsSearchConnector(string filePath)
        {
            return (Path.GetExtension(filePath) == SearchConnector.FileExtension);
        }


        internal static void ThrowIfNotWin7()
        {
            if (!CoreHelpers.RunningOnVista)
            {
                throw new PlatformNotSupportedException("Only supported on Windows 7.");
            }
        }

    }
}
