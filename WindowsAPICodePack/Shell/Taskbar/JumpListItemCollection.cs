//Copyright (c) Microsoft Corporation.  All rights reserved.

using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;

namespace Microsoft.WindowsAPICodePack.Shell.Taskbar
{
    /// <summary>
    /// Represents a colletion of jump list items
    /// </summary>
    /// <typeparam name="T">Type to use for this collection</typeparam>
    public class JumpListItemCollection<T> : ICollection<T>, INotifyCollectionChanged
    {
        private List<T> items = new List<T>();

        /// <summary>
        /// Event that is triggered anytime that a change is made to the underlying collection
        /// </summary>
        public event NotifyCollectionChangedEventHandler CollectionChanged = delegate { };

        /// <summary>
        /// Is this collection read-only
        /// </summary>
        public bool IsReadOnly { get; set; }

        /// <summary>
        /// Count of items currently in this collection
        /// </summary>
        public int Count
        {
            get { return items.Count; }
        }

        /// <summary>
        /// Add the specified item to this collection
        /// </summary>
        /// <param name="item">Item to add</param>
        public void Add(T item)
        {
            items.Add(item);

            // Trigger CollectionChanged event
            CollectionChanged(
                this,
                new NotifyCollectionChangedEventArgs(
                    NotifyCollectionChangedAction.Add,
                    item));
        }

        /// <summary>
        /// Removes the first instance of the specified item
        /// </summary>
        /// <param name="item">Item to remove</param>
        /// <returns>True if an item was removed, false is no items were removed</returns>
        public bool Remove(T item)
        {
            bool removed = items.Remove(item);

            if (removed == true)
            {
                // Trigger CollectionChanged event
                CollectionChanged(
                    this,
                    new NotifyCollectionChangedEventArgs(
                        NotifyCollectionChangedAction.Remove,
                        0));
            }

            return removed;
        }

        /// <summary>
        /// Clears all items from this collection
        /// </summary>
        public void Clear()
        {
            items.Clear();

            // Trigger CollectionChanged event
            CollectionChanged(
                this,
                new NotifyCollectionChangedEventArgs(
                    NotifyCollectionChangedAction.Reset));
        }

        /// <summary>
        /// Determine if this collection contains the specified item
        /// </summary>
        /// <param name="item">Item to search for</param>
        /// <returns>True if item was found</returns>
        public bool Contains(T item)
        {
            return items.Contains(item);
        }

        /// <summary>
        /// Copy this collection to a compatible one-dimensional array,
        /// starting at the specified index of the target array
        /// </summary>
        /// <param name="array"></param>
        /// <param name="index"></param>
        public void CopyTo(T[] array, int index)
        {
            items.CopyTo(array, index);
        }

        /// <summary>
        /// Returns an enumerator that iterates through this collection.
        /// </summary>
        /// <returns>Enumerator to iterate through this collection.</returns>
        IEnumerator IEnumerable.GetEnumerator()
        {
            return items.GetEnumerator();
        }

        /// <summary>
        /// Returns an enumerator that iterates through this collection.
        /// </summary>
        /// <returns>Enumerator to iterate through this collection.</returns>
        IEnumerator<T> IEnumerable<T>.GetEnumerator()
        {
            return items.GetEnumerator();
        }
    }
}
