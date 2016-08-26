// Copyright (c) Microsoft Corporation.  All rights reserved.

using System;
using System.Collections.Generic;

namespace Microsoft.WindowsAPICodePack.Sensors
{
    /// <summary>
    /// 
    /// </summary>
    /// <typeparam name="S"></typeparam>
    public class SensorList<S> : IList<S>
        where S : Sensor
    {
        private List<S> sensorList = new List<S>( );

        #region IList<S> Members

        /// <summary>
        /// 
        /// </summary>
        /// <param name="item"></param>
        /// <returns></returns>
        public int IndexOf( S item )
        {
            return sensorList.IndexOf( item );
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="index"></param>
        /// <param name="item"></param>
        public void Insert( int index, S item )
        {
            sensorList.Insert( index, item );
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="index"></param>
        public void RemoveAt( int index )
        {
            sensorList.RemoveAt( index );
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="index"></param>
        /// <returns></returns>
        public S this[ int index ]
        {
            get
            {
                return sensorList[ index ];
            }
            set
            {
                sensorList[ index ] = value;
            }
        }

        #endregion

        #region ICollection<S> Members

        /// <summary>
        /// 
        /// </summary>
        /// <param name="item"></param>
        public void Add( S item )
        {
            sensorList.Add( item );
        }

        /// <summary>
        /// 
        /// </summary>
        public void Clear( )
        {
            sensorList.Clear( );
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="item"></param>
        /// <returns></returns>
        public bool Contains( S item )
        {
            return sensorList.Contains( item );
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="array"></param>
        /// <param name="arrayIndex"></param>
        public void CopyTo( S[ ] array, int arrayIndex )
        {
            sensorList.CopyTo( array, arrayIndex );
        }

        /// <summary>
        /// 
        /// </summary>
        public int Count
        {
            get
            { 
                return sensorList.Count;
            }
        }

        /// <summary>
        /// 
        /// </summary>
        public bool IsReadOnly
        {
            get
            {
                return ( sensorList as ICollection<S> ).IsReadOnly;
            }
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="item"></param>
        /// <returns></returns>
        public bool Remove( S item )
        {
            return sensorList.Remove( item ); ;
        }

        #endregion

        #region IEnumerable<S> Members

        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        public IEnumerator<S> GetEnumerator( )
        {
            return ( sensorList.GetEnumerator() );
        }

        #endregion

        #region IEnumerable Members

        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        System.Collections.IEnumerator System.Collections.IEnumerable.GetEnumerator( )
        {
            return ( sensorList as System.Collections.IEnumerator );
        }

        #endregion
    }
}
