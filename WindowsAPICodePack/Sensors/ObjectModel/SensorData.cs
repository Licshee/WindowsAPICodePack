// Copyright (c) Microsoft Corporation.  All rights reserved.

using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;

namespace Microsoft.WindowsAPICodePack.Sensors
{
    /// <summary>
    /// 
    /// </summary>
    public class SensorData : IDictionary<Guid,IList<object>>
    {
        #region implementation 
        internal static SensorData FromNativeReport( ISensor iSensor, ISensorDataReport iReport )
        {
            SensorData data = new SensorData( );

            IPortableDeviceKeyCollection keyCollection;
            IPortableDeviceValues valuesCollection;
            iSensor.GetSupportedDataFields( out keyCollection );
            iReport.GetSensorValues( keyCollection, out valuesCollection );

            uint items = 0;
            keyCollection.GetCount( out items );
            for( uint index = 0; index < items; index++ )
            {
                PropertyKey key;
                PropVariant propValue;
                keyCollection.GetAt( index, out key );
                valuesCollection.GetValue( ref key, out propValue );
                try
                {
                    if( data.ContainsKey( key.FormatId ) )
                    {
                        data[ key.FormatId ].Add( propValue.Value );
                    }
                    else
                    {
                        data.Add( key.FormatId, new List<object> { propValue.Value } );
                    }
                }
                finally
                {
                    propValue.Clear( );
                }
            }

            if( keyCollection != null )
            {
                Marshal.ReleaseComObject( keyCollection );
                keyCollection = null;
            }

            if( valuesCollection != null )
            {
                Marshal.ReleaseComObject( valuesCollection );
                valuesCollection = null;
            }


            return data;
        }
        #endregion

        private Dictionary<Guid, IList<object>> sensorDataDictionary = new Dictionary<Guid, IList<object>>( );

        #region IDictionary<Guid,IList<object>> Members

        /// <summary>
        /// 
        /// </summary>
        /// <param name="key"></param>
        /// <param name="value"></param>
        public void Add( Guid key, IList<object> value )
        {
            sensorDataDictionary.Add( key, value );
        }
        /// <summary>
        /// 
        /// </summary>
        /// <param name="key"></param>
        /// <returns></returns>
        public bool ContainsKey( Guid key )
        {
            return sensorDataDictionary.ContainsKey( key );
        }
        /// <summary>
        /// 
        /// </summary>
        public ICollection<Guid> Keys
        {
            get
            {
                return sensorDataDictionary.Keys;
            }
        }
        /// <summary>
        /// 
        /// </summary>
        /// <param name="key"></param>
        /// <returns></returns>
        public bool Remove( Guid key )
        {
            return sensorDataDictionary.Remove( key );
        }
        /// <summary>
        /// 
        /// </summary>
        /// <param name="key"></param>
        /// <param name="value"></param>
        /// <returns></returns>
        public bool TryGetValue( Guid key, out IList<object> value )
        {
            return sensorDataDictionary.TryGetValue( key, out value );
        }
        /// <summary>
        /// 
        /// </summary>
        public ICollection<IList<object>> Values
        {
            get
            {
                return sensorDataDictionary.Values;
            }
        }
        /// <summary>
        /// 
        /// </summary>
        /// <param name="key"></param>
        /// <returns></returns>
        public IList<object> this[ Guid key ]
        {
            get
            {
                return sensorDataDictionary[ key ];
            }
            set
            {
                sensorDataDictionary[ key ] = value;
            }
        }

        #endregion

        #region ICollection<KeyValuePair<Guid,IList<object>>> Members
        /// <summary>
        /// 
        /// </summary>
        /// <param name="item"></param>
        public void Add( KeyValuePair<Guid, IList<object>> item )
        {
            ICollection<KeyValuePair<Guid, IList<object>>> c = sensorDataDictionary as ICollection<KeyValuePair<Guid, IList<object>>>;
            c.Add( item );
        }
        /// <summary>
        /// 
        /// </summary>
        public void Clear( )
        {
            ICollection<KeyValuePair<Guid, IList<object>>> c = sensorDataDictionary as ICollection<KeyValuePair<Guid, IList<object>>>;
            c.Clear( );
        }
        /// <summary>
        /// 
        /// </summary>
        /// <param name="item"></param>
        /// <returns></returns>
        public bool Contains( KeyValuePair<Guid, IList<object>> item )
        {
            ICollection<KeyValuePair<Guid, IList<object>>> c = sensorDataDictionary as ICollection<KeyValuePair<Guid, IList<object>>>;
            return c.Contains( item );
        }
        /// <summary>
        /// 
        /// </summary>
        /// <param name="array"></param>
        /// <param name="arrayIndex"></param>
        public void CopyTo( KeyValuePair<Guid, IList<object>>[ ] array, int arrayIndex )
        {
            ICollection<KeyValuePair<Guid, IList<object>>> c = sensorDataDictionary as ICollection<KeyValuePair<Guid, IList<object>>>;
            c.CopyTo( array, arrayIndex );
        }
        /// <summary>
        /// 
        /// </summary>
        public int Count
        {
            get
            { 
                ICollection<KeyValuePair<Guid, IList<object>>> c = sensorDataDictionary as ICollection<KeyValuePair<Guid, IList<object>>>;

                return c.Count;
            }
        }
        /// <summary>
        /// 
        /// </summary>
        public bool IsReadOnly
        {
            get
            {
                return true;
            }
        }
        /// <summary>
        /// 
        /// </summary>
        /// <param name="item"></param>
        /// <returns></returns>
        public bool Remove( KeyValuePair<Guid, IList<object>> item )
        {
            ICollection<KeyValuePair<Guid, IList<object>>> c = sensorDataDictionary as ICollection<KeyValuePair<Guid, IList<object>>>;
            
            return c.Remove( item );
        }

        #endregion

        #region IEnumerable<KeyValuePair<Guid,IList<object>>> Members
        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        public IEnumerator<KeyValuePair<Guid, IList<object>>> GetEnumerator( )
        {
            return (sensorDataDictionary as IEnumerator<KeyValuePair<Guid, IList<object>>>);
        }

        #endregion

        #region IEnumerable Members
        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        System.Collections.IEnumerator System.Collections.IEnumerable.GetEnumerator( )
        {
            return sensorDataDictionary as System.Collections.IEnumerator;
        }

        #endregion
    }
}
