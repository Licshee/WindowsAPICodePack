//Copyright (c) Microsoft Corporation.  All rights reserved.

using System;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Media;
using System.Windows.Shapes;
using System.Collections.ObjectModel;
using Microsoft.WindowsAPICodePack.Shell;

namespace ShellHierarchyTreeDemo
{
    /// <summary>
    /// This application demonstrates how to navigate the Shell namespace 
    /// starting from the Desktop folder (Shell.Desktop).
    /// </summary>
    public partial class Window1 : Window
    {
        static public KnownFolder DesktopKnownFolder = KnownFolders.GetKnownFolder("Desktop", false);

        public Window1()
        {
            InitializeComponent();
            ShowDesktopData();
        }

        void ShowDesktopData()
        {
            DesktopCollection.ShowObjectData(this, DesktopKnownFolder);
            DesktopCollection.ShowThumbnail(this, DesktopKnownFolder);
            DesktopCollection.ShowProperties(this, DesktopKnownFolder);
        }
    }

    public class DesktopCollection : Collection<object>
    {
        public DesktopCollection()
        {
            ShellFolder desktop = ShellFolder.Desktop;
            foreach (ShellObject obj in desktop)
            {
                TreeViewItem item = new TreeViewItem();
                item.Header = obj;
                if (obj is IShellContainer)
                {                    
                    item.Items.Add(":::");
                    item.Expanded += ExplorerTreeView_Expanded;
                }
                item.Selected += new RoutedEventHandler(item_Selected);
                Add(item);
            }
        }

        internal void ExplorerTreeView_Expanded(object sender, RoutedEventArgs e)
        {
            TreeViewItem sourceItem = sender as TreeViewItem;
            IShellContainer shellContainer = sourceItem.Header as IShellContainer;

            if (sourceItem.Items.Count >= 1 && sourceItem.Items[0].Equals(":::"))
            {
                sourceItem.Items.Clear();
                foreach (ShellObject obj in shellContainer)
                {
                    TreeViewItem item = new TreeViewItem();
                    item.Header = obj;
                    if (obj is IShellContainer)
                    {
                        item.Items.Add(":::");
                        item.Expanded += ExplorerTreeView_Expanded;
                    }
                    item.Selected += new RoutedEventHandler(item_Selected);
                    sourceItem.Items.Add(item);
                }
            }
        }

        internal void item_Selected(object sender, RoutedEventArgs e)
        {
            if (sender is TreeViewItem)
            {
                
                Window1 wnd = (Window1)Application.Current.MainWindow;

                TreeViewItem sourceItem = wnd.ExplorerTreeView.SelectedItem as TreeViewItem;
                if (sourceItem == null)
                    return;

                ShellObject shellObj = sourceItem.Header as ShellObject;

                if (shellObj == null)
                    return;

                ShowObjectData(wnd, shellObj);
                ShowThumbnail(wnd, shellObj);
                ShowProperties(wnd, shellObj);

            }
        }

        internal static void ShowProperties(Window1 wnd, ShellObject shellObj)
        {
            if (shellObj is KnownFolder)
            {
                KnownFolder kf = shellObj as KnownFolder;
                ShowKnownFolderProperties(wnd, kf);
            }
            else if (shellObj is ShellLibrary)
            {
                ShellLibrary lib = shellObj as ShellLibrary;
                ShowLibraryProperties(wnd, lib);
            }
            else if (shellObj is ShellFileSystemObject)
            {
                ShownShellItemProperties(wnd, shellObj);
            }
            else
            {
                HideProperties(wnd);
            }
        }

        private static void HideProperties(Window1 wnd)
        {
            wnd.PropertiesListBox.Visibility = Visibility.Hidden;
            wnd.FolderPropsListBox.Visibility = Visibility.Hidden;
        }

        internal static void ShownShellItemProperties(Window1 wnd, ShellObject shellObj)
        {
            if (wnd.PropertiesListBox.Visibility != Visibility.Visible || wnd.FolderPropsListBox.Visibility != Visibility.Hidden)
            {
                wnd.PropertiesListBox.Visibility = Visibility.Visible;
                wnd.FolderPropsListBox.Visibility = Visibility.Hidden;
            }

            wnd.PropertiesListBox.ItemsSource = (shellObj as ShellFileSystemObject).Properties;
        }

        internal static void ShowKnownFolderProperties(Window1 wnd, KnownFolder kf)
        {
            if (wnd.FolderPropsListBox.Visibility != Visibility.Visible || wnd.PropertiesListBox.Visibility != Visibility.Hidden)
            {
                wnd.PropertiesListBox.Visibility = Visibility.Hidden;
                wnd.FolderPropsListBox.Visibility = Visibility.Visible;
            }

            Collection<KnownFolderProperty> properties = new Collection<KnownFolderProperty>();

            properties.Add(new KnownFolderProperty { Property = "Canonical Name", Value = kf.CanonicalName });
            properties.Add(new KnownFolderProperty { Property = "Category", Value = kf.Category });
            properties.Add(new KnownFolderProperty { Property = "Definition Options", Value = kf.DefinitionOptions });
            properties.Add(new KnownFolderProperty { Property = "Description", Value = kf.Description });
            properties.Add(new KnownFolderProperty { Property = "File Attributes", Value = kf.FileAttributes });
            properties.Add(new KnownFolderProperty { Property = "Folder Id", Value = kf.FolderId });
            properties.Add(new KnownFolderProperty { Property = "Folder Type", Value = kf.FolderType });
            properties.Add(new KnownFolderProperty { Property = "Folder Type Id", Value = kf.FolderTypeId });
            properties.Add(new KnownFolderProperty { Property = "Name", Value = kf.Name });
            properties.Add(new KnownFolderProperty { Property = "Parent", Value = kf.Parent });
            properties.Add(new KnownFolderProperty { Property = "Path", Value = kf.Path });
            properties.Add(new KnownFolderProperty { Property = "Relative Path", Value = kf.RelativePath });
            properties.Add(new KnownFolderProperty { Property = "Security", Value = kf.Security });
            properties.Add(new KnownFolderProperty { Property = "Tooltip", Value = kf.Tooltip });

            wnd.FolderPropsListBox.ItemsSource = properties;
        }

        internal static void ShowLibraryProperties(Window1 wnd, ShellLibrary lib)
        {
            if (wnd.FolderPropsListBox.Visibility != Visibility.Visible || wnd.PropertiesListBox.Visibility != Visibility.Hidden)
            {
                wnd.PropertiesListBox.Visibility = Visibility.Hidden;
                wnd.FolderPropsListBox.Visibility = Visibility.Visible;
            }

            Collection<KnownFolderProperty> properties = new Collection<KnownFolderProperty>();

            properties.Add(new KnownFolderProperty { Property = "Name", Value = lib.Name});
            object value = null;
            
            try
            {
                value = lib.LibraryType;
            }
            catch  
            {}
            properties.Add(new KnownFolderProperty { Property = "Library Type", Value = value });


            try
            {
                value = lib.LibraryTypeId;
            }
            catch
            { }
            properties.Add(new KnownFolderProperty { Property = "Library Type Id", Value = value });
            
            properties.Add(new KnownFolderProperty { Property = "Path", Value = lib.Path});
            properties.Add(new KnownFolderProperty { Property = "Is Pinned To NavigationPane", Value = lib.IsPinnedToNavigationPane });

            wnd.FolderPropsListBox.ItemsSource = properties;
        }

        internal static void ShowObjectData(Window1 wnd, ShellObject shellObj)
        {
            wnd.PropertiesTextBox.Text =
                String.Format(
                    "Nam= {0}{1}Path= {2}{1}Type= {3}{4} ({5}File System)",
                    shellObj.Name,
                    Environment.NewLine,
                    shellObj.Path,
                    shellObj.GetType().Name,
                    shellObj.IsLink ? " (Shortcut)" : "",
                    shellObj.IsFileSystemObject ? "" : "Non ");
        }

        internal static void ShowThumbnail(Window1 wnd, ShellObject shellObj)
        {
            try
            {
                if (shellObj is ShellLibrary)
                {
                    wnd.ThumbnailPreview.Source = (shellObj as ShellLibrary).Icon;
                }
                else if (shellObj is ShellFileSystemObject)
                {
                    wnd.ThumbnailPreview.Source = (shellObj as ShellFileSystemObject).Thumbnail.Large.BitmapSource;
                }
                else if (shellObj is KnownFolder)
                {
                    wnd.ThumbnailPreview.Source = (shellObj as KnownFolder).Icon;
                }
                else
                {
                    wnd.ThumbnailPreview.Source = null; // Othe types are not supported
                }
            }
            catch
            {
                wnd.ThumbnailPreview.Source = null;
            }
        }

    }

    struct KnownFolderProperty
    {
        public string Property { set; get; }
        public object Value { set; get; }
    }
}
