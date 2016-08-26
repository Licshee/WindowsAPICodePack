//Copyright (c) Microsoft Corporation.  All rights reserved.

using System;
using System.Collections.Specialized;
using System.Runtime.InteropServices;
using System.Text;

namespace Microsoft.WindowsAPICodePack.Shell.Taskbar
{
    /// <summary>
    /// Represents an instance of a taskbar button jump list.
    /// </summary>
    public class JumpList
    {
        // Best practice recommends defining a private object to lock on
        private static Object syncLock = new Object();

        // Native implementation of destination list
        private ICustomDestinationList customDestinationList;

        #region Properties

        private CustomCategoryCollection customCategories;
        /// <summary>
        /// Gets the collection of custom categories that have been added to
        /// the taskbar jump list.
        /// </summary>
        public CustomCategoryCollection CustomCategories
        {
            get
            {
                if (customCategories == null)
                {
                    // Make sure that we don't create multiple instances
                    // of this object
                    lock (syncLock)
                    {
                        if (customCategories == null)
                        {
                            customCategories = new CustomCategoryCollection();
                        }
                    }
                }

                return customCategories;
            }
        }

        private JumpListItemCollection<IJumpListTask> userTasks;
        /// <summary>
        /// Collection of user tasks that have been added to the taskbar jump
        /// list. User tasks can only consist of JumpListTask or
        /// JumpListSeparator objects.
        /// </summary>
        public JumpListItemCollection<IJumpListTask> UserTasks
        {
            get
            {
                if (userTasks == null)
                {
                    // Make sure that we don't create multiple instances
                    // of this object
                    lock (syncLock)
                    {
                        if (userTasks == null)
                        {
                            userTasks = new JumpListItemCollection<IJumpListTask>();
                        }
                    }

                }

                return userTasks;
            }
        }

        private uint maxSlotsInList;
        /// <summary>
        /// Recommended number of items to add to the jumplist.  This number doesn’t 
        /// imply or give any hint as to how many items will appear on the list.  
        /// This number should only be used for reference purposes since
        /// the actual number of slots in the jumplist can change after the last
        /// refresh, due to pinning of items, items being removed, resolution changes, etc 
        /// and the jump list can increase in size accordingly.
        /// </summary>
        public uint MaxSlotsInList
        {
            get { return maxSlotsInList; }
        }

        /// <summary>
        /// Gets or sets which known categories to display
        /// </summary>
        public KnownCategoryType KnownCategoryToDisplay { get; set; }

        private int knownCategoryOrdinalPosition = 0;
        /// <summary>
        /// Gets or sets the value for the known category location relative to the 
        /// custom category collection.
        /// </summary>
        public int KnownCategoryOrdinalPosition 
        {
            get
            {
                return knownCategoryOrdinalPosition;
            }
            set
            {
                if (value < 0)
                    throw new ArgumentOutOfRangeException("value", "Negative numbers are not allowed for the ordinal position.");

                knownCategoryOrdinalPosition = value;
            }
        
        }

        /// <summary>
        /// Gets or sets the application ID to use for this jump list
        /// </summary>
        internal string AppID { get; set; }

        #endregion

        /// <summary>
        /// Creates a new instance of the JumpList class with the specified
        /// appId.
        /// </summary>
        /// <param name="appID">Application ID to use for this instace.</param>
        internal JumpList(string appID)
        {
            // Native implementation of destination list
            customDestinationList = (ICustomDestinationList)new CDestinationList();

            // Set application user model ID
            AppID = appID;
        }

        /// <summary>
        /// Event that gets called when items have been removed since the last
        /// refresh on the taskbar's jump list. This event will not be triggered
        /// immediately when a user removes an item from the jump list but rather
        /// when the application refreshes the task bar list directly
        /// </summary>
        public event EventHandler<UserRemovedItemsEventArgs> JumpListItemsRemoved = delegate { };

        /// <summary>
        /// Report document usage to shell.
        /// </summary>
        /// <param name="destination">Full path of file to report usage</param>
        public void AddToRecent(string destination)
        {
            TaskbarNativeMethods.SHAddToRecentDocs(destination);
        }

        /// <summary>
        /// Commits the pending JumpList changes and refreshes the taskbar.
        /// </summary>
        public void RefreshTaskbarList()
        {
            // Begins rendering on the taskbar destination list
            BeginList();

            // Add custom categories
            AppendCustomCategories();

            // Add user tasks
            AppendTaskList();

            // End rendering of the taskbar destination list
            customDestinationList.CommitList();
        }

        private void BeginList()
        {
            // Get list of removed items from native code
            object removedItems;

            // Native call to start adding items to the taskbar destination list
            customDestinationList.BeginList(
                out maxSlotsInList,
                ref TaskbarNativeMethods.IID_IObjectArray,
                out removedItems);

            // Process deleted items
            ProcessDeletedItems((IObjectArray)removedItems);
        }

        private void ProcessDeletedItems(IObjectArray removedItems)
        {
            uint count;
            removedItems.GetCount(out count);

            if (count == 0)
                return;

            // String array passed to the user via the JumpListItemsRemoved
            // event
            string[] removedItemsArray = new string[count];

            // Process each removed item based on it's type
            for (uint i = 0; i < count; i++)
            {
                // Native call to retrieve objects from IObjectArray
                object item;
                removedItems.GetAt(i,
                    ref TaskbarNativeMethods.IID_IUnknown,
                    out item);

                // Process item
                if (item is IShellItem)
                {
                    removedItemsArray[i] = RemoveCustomCategoryItem((IShellItem)item);
                }
                else if (item is IShellLinkW)
                {
                    removedItemsArray[i] = RemoveCustomCategoryLink((IShellLinkW)item);
                }
            }

            // Event to notify user of removed items
            JumpListItemsRemoved(this, new UserRemovedItemsEventArgs(removedItemsArray));
        }

        private string RemoveCustomCategoryItem(IShellItem item)
        {
            string path = null;
            IntPtr pszString = IntPtr.Zero;
            HRESULT hr = item.GetDisplayName(ShellNativeMethods.SIGDN.SIGDN_FILESYSPATH, out pszString);
            if (hr == HRESULT.S_OK || pszString != IntPtr.Zero)
                path = Marshal.PtrToStringAuto(pszString);

            // Remove this item from each category
            foreach (CustomCategory category in this.CustomCategories)
                category.RemoveJumpListItem(path);

            return path;
        }


        private string RemoveCustomCategoryLink(IShellLinkW link)
        {
            StringBuilder sb = new StringBuilder(256);
            link.GetPath(sb, sb.Capacity, IntPtr.Zero, 2);

            string path = sb.ToString();

            // Remove this item from each category
            foreach (CustomCategory category in CustomCategories)
                category.RemoveJumpListItem(path);

            return path;
        }

        private void AppendCustomCategories()
        {
            // Initialize our current index in the custom categories list
            int currentIndex = 0;

            // Keep track whether we add the Known Categories to our list
            bool knownCategoriesAdded = false;

            // Append each category to list
            foreach (CustomCategory category in CustomCategories)
            {
                // If our current index is same as the KnownCategory OrdinalPosition,
                // append the Known Categories
                if (!knownCategoriesAdded && currentIndex == KnownCategoryOrdinalPosition)
                {
                    AppendKnownCategories();
                    knownCategoriesAdded = true;
                }

                // Don't process empty categories
                if (category.JumpListItems.Count == 0)
                    continue;

                IObjectCollection categoryContent =
                    (IObjectCollection)new CEnumerableObjectCollection();

                // Add each link's shell representation to the object array
                foreach (IJumpListItem link in category.JumpListItems)
                    categoryContent.AddObject(link.GetShellRepresentation());

                // Add current category to destination list
                customDestinationList.AppendCategory(
                    category.Name,
                    (IObjectArray)categoryContent);

                // Increase our current index
                currentIndex++;
            }

            // If the ordinal position was out of range, append the Known Categories
            // at the end
            if (!knownCategoriesAdded)
                AppendKnownCategories();
        }

        private void AppendTaskList()
        {
            if (UserTasks.Count == 0)
                return;

            IObjectCollection taskContent =
                    (IObjectCollection)new CEnumerableObjectCollection();

            // Add each task's shell representation to the object array
            foreach (IJumpListTask task in UserTasks)
                taskContent.AddObject(task.GetShellRepresentation());

            // Add tasks to the taskbar
            customDestinationList.AddUserTasks((IObjectArray)taskContent);
        }

        private void AppendKnownCategories()
        {
            if (KnownCategoryToDisplay == KnownCategoryType.Recent)
                customDestinationList.AppendKnownCategory(KNOWNDESTCATEGORY.KDC_RECENT);
            else if (KnownCategoryToDisplay == KnownCategoryType.Frequent)
                customDestinationList.AppendKnownCategory(KNOWNDESTCATEGORY.KDC_FREQUENT);
        }
    }
}
