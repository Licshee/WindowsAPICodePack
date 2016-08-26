// Copyright (c) Microsoft Corporation.  All rights reserved.

using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;

namespace Microsoft.WindowsAPICodePack.Sensors
{
    /// <summary>
    /// 
    /// </summary>
    /// <param name="sender"></param>
    /// <param name="e"></param>
    public delegate void DataReportChangedHandler( Sensor sender, EventArgs e );

    /// <summary>
    /// 
    /// </summary>
    /// <param name="sender"></param>
    /// <param name="e"></param>
    public delegate void StateChangedHandler( Sensor sender, EventArgs e );

    /// <summary>
    /// 
    /// </summary>
    public class Sensor : ISensorEvents
    {
        /// <summary>
        /// Fires when the DataReport member changes
        /// </summary>
        public event DataReportChangedHandler DataReportChanged;

        /// <summary>
        /// Fires when the State member changes
        /// </summary>
        public event StateChangedHandler StateChanged;


        #region Public properties

        /// <summary>
        /// The most recent data reported by the sensor
        /// </summary>
        public SensorReport DataReport
        {
            get
            {
                return dataReport;
            }
        }
        SensorReport dataReport = null;

        /// <summary>
        /// Returns the sensor instance GUID.
        /// </summary>
        public Guid? SensorId
        {
            get
            {
                if( sensorId == null )
                {
                    Guid id;
                    HRESULT hr = nativeISensor.GetID( out id );
                    if( hr == HRESULT.S_OK )
                    {
                        sensorId = id;
                    }
                }
                return sensorId;
            }
        }
        private Guid? sensorId = null;

        /// <summary>
        /// Returns the sensor category GUID.
        /// </summary>
        public Guid? CategoryId
        {
            get
            {
                if( categoryId == null )
                {
                    Guid id;
                    HRESULT hr = nativeISensor.GetCategory( out id );
                    if( hr == HRESULT.S_OK )
                    {
                        categoryId = id;
                    }
                }

                return categoryId;
            }
        }
        private Guid? categoryId = null;

        /// <summary>
        /// Returns the sensor type GUID.
        /// </summary>
        public Guid? TypeId
        {
            get
            {
                if( typeId == null )
                {
                    Guid id;
                    HRESULT hr = nativeISensor.GetType( out id );
                    if( hr == HRESULT.S_OK )
                        typeId = id;
                }

                return typeId;
            }
        }
        private Guid? typeId = null;

        /// <summary>
        /// Returns the sensor's friendly name.
        /// </summary>
        public string FriendlyName
        {
            get
            {
                if( friendlyName == null )
                {
                    string name = null;
                    HRESULT hr = nativeISensor.GetFriendlyName( out name );
                    if( hr == HRESULT.S_OK )
                        friendlyName = name;
                }
                return friendlyName;
            }
        }
        private string friendlyName = null;

        /// <summary>
        /// Returns the sensor's current state.
        /// </summary>
        public SensorState State
        {
            get
            {
                NativeSensorState state;
                nativeISensor.GetState( out state );
                return (SensorState)state;
            }
        }

        /// <summary>
        /// Gets or sets the report interval.
        /// </summary>
        public uint ReportInterval
        {
            get
            {
                return (uint)GetProperty( SensorPropertyKeys.SENSOR_PROPERTY_CURRENT_REPORT_INTERVAL );
            }

            set
            {
                SetProperties( new DataFieldInfo[ ] { new DataFieldInfo( SensorPropertyKeys.SENSOR_PROPERTY_CURRENT_REPORT_INTERVAL, value ) } );
            }
        }

        /// <summary>
        /// Gets the minimal report interval.
        /// </summary>
        public uint MinimumReportInterval
        {
            get
            {
                return (uint)GetProperty( SensorPropertyKeys.SENSOR_PROPERTY_MIN_REPORT_INTERVAL );
            }
        }

        /// <summary>
        /// Gets the manufacturer of the sensor.
        /// </summary>
        public string Manufacturer
        {
            get
            {
                if( manufacturer == null )
                {
                    manufacturer = (string)GetProperty( SensorPropertyKeys.SENSOR_PROPERTY_MANUFACTURER );
                }
                return manufacturer;
            }
        }
        private string manufacturer = null;

        /// <summary>
        /// Gets the sensor model.
        /// </summary>
        public string Model
        {
            get
            {
                if( model == null )
                {
                    model = (string)GetProperty( SensorPropertyKeys.SENSOR_PROPERTY_MODEL );
                }
                return model;
            }
        }
        private string model = null;

        /// <summary>
        /// Gets the sensor's serial number.
        /// </summary>
        public string SerialNumber
        {
            get
            {
                if( serialNumber== null )
                {
                    serialNumber = (string)GetProperty( SensorPropertyKeys.SENSOR_PROPERTY_SERIAL_NUMBER );
                }
                return serialNumber;
            }
        }
        private string serialNumber = null;

        /// <summary>
        /// Gets the sensor's description.
        /// </summary>
        public string Description
        {
            get
            {
                if( description == null )
                {
                    description = (string)GetProperty( SensorPropertyKeys.SENSOR_PROPERTY_DESCRIPTION );
                }

                return description;
            }
        }
        private string description = null;

        /// <summary>
        /// Gets the sensor's connection type.
        /// </summary>
        public SensorConnectionType? ConnectionType
        {
            get
            {
                if( connectionType == null )
                {
                    connectionType = (SensorConnectionType)GetProperty( SensorPropertyKeys.SENSOR_PROPERTY_CONNECTION_TYPE );
                }
                return connectionType;
            }
        }
        private SensorConnectionType? connectionType = null;

        /// <summary>
        /// Gets the sensor device path
        /// </summary>
        public string DevicePath
        {
            get
            {
                if( devicePath == null )
                {
                    devicePath = (string)GetProperty( SensorPropertyKeys.SENSOR_PROPERTY_DEVICE_ID );
                }

                return devicePath;
            }
        }
        private string devicePath = null;

        /// <summary>
        /// If set automatically updates the DataReport. Otherwise TryUpdateDataReport/UpdateDataReport 
        /// will need to be called to update the DataReport member.
        /// </summary>
        public bool AutoUpdateDataReport
        {
            get
            {
                return IsEventInterestSet( EventInterestTypes.DataUpdated );
            }
            set
            {
                if( value )
                    SetEventInterest( EventInterestTypes.DataUpdated );
                else
                    ClearEventInterest( EventInterestTypes.DataUpdated );
            }
        }

        #endregion

        #region public methods
        /// <summary>
        /// Trys to force a synchronous data update from the sensor.
        /// </summary>
        /// <returns></returns>
        public bool TryUpdateData( )
        {
            HRESULT hr = InternalUpdateData( );
            return (hr == HRESULT.S_OK);
        }

        /// <summary>
        /// Forces a synchronous data update from the sensor. Throws on error.
        /// </summary>
        public void UpdateData( )
        {
            HRESULT hr = InternalUpdateData( );
            if( hr != HRESULT.S_OK )
            {
                throw new SensorPlatformException( "Unable to get report from sensor", Marshal.GetExceptionForHR((int)hr) );
            }
        }

        internal HRESULT InternalUpdateData()
        {
            
            ISensorDataReport iReport = null;
            HRESULT hr = nativeISensor.GetData( out iReport );
            if( hr == HRESULT.S_OK )
            {
                try
                {
                    this.dataReport = SensorReport.FromNativeReport( this, iReport );
                    if( DataReportChanged != null )
                    {
                        DataReportChanged.Invoke( this, EventArgs.Empty );
                    }
                }
                finally
                {
                    Marshal.ReleaseComObject( iReport );
                }
            }
            return hr;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        public override string ToString( )
        {
            return String.Format(
                "Sensor id='{0}' type='{1}' category='{2}' name='{3}'.",
                this.SensorId,
                this.TypeId,
                this.CategoryId,
                this.FriendlyName );
        }

        
        /// <summary>
        /// Retrieves a property value by property key.
        /// </summary>
        /// <param name="propKey">Property key.</param>
        /// <returns>Property's value.</returns>
        public object GetProperty( PropertyKey propKey )
        {
            PropVariant pv = new PropVariant( );
            try
            {
                nativeISensor.GetProperty( ref propKey, pv );
                return pv.Value;
            }
            finally
            {
                pv.Clear( );
            }
        }

        /// <summary>
        /// Retrieves a property value by property inex.
        /// Assumes the GUID component in the property key takes the sensor's type GUID.
        /// </summary>
        /// <param name="propIdx">Property index.</param>
        /// <returns>Property's value.</returns>
        public object GetProperty( int propIdx )
        {
            PropertyKey propKey = new PropertyKey( TypeId.Value, propIdx );
            return GetProperty( propKey );
        }

        /// <summary>
        /// Retrives the values of multiple properties.
        /// </summary>
        /// <param name="propKeys">Properties to retrieve.</param>
        /// <returns>A dictionary containing the property keys and values.</returns>
        public IDictionary<PropertyKey, object> GetProperties( PropertyKey[ ] propKeys )
        {
            if( propKeys == null || propKeys.Length == 0 )
                throw new ArgumentNullException( "propKeys", "Property keys array must not be null or empty." );

            IPortableDeviceKeyCollection keyCollection = new PortableDeviceKeyCollection( );
            try
            {
                IPortableDeviceValues valuesCollection;

                for( int i = 0; i < propKeys.Length; i++ )
                {
                    PropertyKey propKey = propKeys[ i ];
                    keyCollection.Add( ref propKey );
                }

                Dictionary<PropertyKey, object> data = new Dictionary<PropertyKey, object>( );
                HRESULT hr = nativeISensor.GetProperties( keyCollection, out valuesCollection );
                if( hr == HRESULT.S_OK )
                {
                    try
                    {

                        uint count = 0;
                        valuesCollection.GetCount( ref count );

                        for( uint i = 0; i < count; i++ )
                        {
                            PropertyKey propKey = new PropertyKey( );
                            PropVariant propVal = new PropVariant( );
                            valuesCollection.GetAt( i, ref propKey, ref propVal );

                            try
                            {
                                data.Add( propKey, propVal.Value );
                            }
                            finally
                            {
                                propVal.Clear( );
                            }
                        }
                    }
                    finally
                    {
                        Marshal.ReleaseComObject( valuesCollection );
                        valuesCollection = null;
                    }
                }

                return data;
            }
            finally
            {
                Marshal.ReleaseComObject( keyCollection );
                keyCollection = null;
            }
        }

        /// <summary>
        /// Gets the list of supported properties for the sensor
        /// </summary>
        /// <returns>A list of of suported properties.</returns>
        public IList<PropertyKey> GetSupportedProperties( )
        {
            if( nativeISensor == null )
                throw new SensorPlatformException( "Sensor not initialized." );

            List<PropertyKey> list = new List<PropertyKey>( );
            IPortableDeviceKeyCollection collection;
            HRESULT hr = nativeISensor.GetSupportedDataFields( out collection );
            if( hr == HRESULT.S_OK )
            {
                try
                {
                    uint elements = 0;
                    collection.GetCount( out elements );
                    if( elements == 0 )
                        return null;

                    for( uint element = 0; element < elements; element++ )
                    {
                        PropertyKey key;
                        hr = collection.GetAt( element, out key );
                        if( hr == HRESULT.S_OK )
                        {
                            list.Add( key );
                        }
                    }
                }
                finally
                {
                    Marshal.ReleaseComObject( collection );
                    collection = null;
                }
            }
            return list;
        }


        /// <summary>
        /// Retrives the values of multiple properties by their indices.
        /// Assues that the GUID component of property keys is the sensor's type GUID.
        /// </summary>
        /// <param name="propIndices">Indices of properties to retrieve.</param>
        /// <returns>An array containing the property values.</returns>
        /// <remarks>
        /// If the values of some properties could not be retrieved, then the returned array will contain null values in the corresponding positions.
        /// </remarks>
        public object[ ] GetProperties( params int[ ] propIndices )
        {
            if( propIndices == null || propIndices.Length == 0 )
                throw new ArgumentNullException( "propIndices", "Property keys array must not be null or empty." );

            IPortableDeviceKeyCollection keyCollection = new PortableDeviceKeyCollection( );
            try
            {
                IPortableDeviceValues valuesCollection;
                Dictionary<PropertyKey, int> propKeyToIdx = new Dictionary<PropertyKey, int>( );

                for( int i = 0; i < propIndices.Length; i++ )
                {
                    PropertyKey propKey = new PropertyKey( TypeId.Value, propIndices[ i ] );
                    keyCollection.Add( ref propKey );
                    propKeyToIdx.Add( propKey, i );
                }

                object[ ] data = new object[ propIndices.Length ];
                HRESULT hr = nativeISensor.GetProperties( keyCollection, out valuesCollection );
                if( hr == HRESULT.S_OK )
                {
                    try
                    {
                        if( valuesCollection == null )
                            return data;

                        uint count = 0;
                        valuesCollection.GetCount( ref count );

                        for( uint i = 0; i < count; i++ )
                        {
                            PropertyKey propKey = new PropertyKey( );
                            PropVariant propVal = new PropVariant( );
                            valuesCollection.GetAt( i, ref propKey, ref propVal );

                            try
                            {
                                int idx = propKeyToIdx[ propKey ];
                                data[ idx ] = propVal.Value;
                            }
                            finally
                            {
                                propVal.Clear( );
                            }
                        }
                    }
                    finally
                    {
                        Marshal.ReleaseComObject( valuesCollection );
                        valuesCollection = null;
                    }
                }
                return data;
            }
            finally
            {
                Marshal.ReleaseComObject( keyCollection );
            }
        }

        /// <summary>
        /// Sets the values of multiple properties.
        /// </summary>
        /// <param name="data">The keys and values of properties to set.</param>
        /// <returns>The new values of the properties. Actual values may not match requested values.</returns>
        public IDictionary<PropertyKey, object> SetProperties( DataFieldInfo[ ] data )
        {
            if( data == null || data.Length == 0 )
                throw new ArgumentNullException( "data", "Data field array must not be null or empty." );

            IPortableDeviceValues pdv = new PortableDeviceValues( );

            for( int i = 0; i < data.Length; i++ )
            {
                PropertyKey propKey = data[ i ].Key;
                object value = data[ i ].Value;
                if( value == null )
                    throw new ArgumentNullException( "data", String.Format( "Data contains a null value at index {0}", i ) );

                if( value is string )
                    pdv.SetStringValue( ref propKey, (string)value );
                else if( value is uint )
                    pdv.SetUnsignedIntegerValue( ref propKey, (uint)value );
                else if( value is int )
                    pdv.SetSignedIntegerValue( ref propKey, (int)value );
                else if( value is ulong )
                    pdv.SetUnsignedLargeIntegerValue( ref propKey, (ulong)value );
                else if( value is long )
                    pdv.SetSignedLargeIntegerValue( ref propKey, (long)value );
                else if( value is float || value is double )
                    pdv.SetFloatValue( ref propKey, (float)value );
                else if( value is bool )
                    pdv.SetBoolValue( ref propKey, ( (bool)value ) ? 1 : 0 );
                else if( value is Guid )
                {
                    Guid guid = (Guid)value;
                    pdv.SetGuidValue( ref propKey, ref guid );
                }
                else if( value is byte[ ] )
                {
                    byte[ ] buffer = (byte[ ])value;
                    pdv.SetBufferValue( ref propKey, buffer, (uint)buffer.Length );
                }
                else
                {
                    pdv.SetIUnknownValue( ref propKey, value );
                }
            }

            Dictionary<PropertyKey, object> results = new Dictionary<PropertyKey, object>( );
            IPortableDeviceValues pdv2 = null;
            HRESULT hr = nativeISensor.SetProperties( pdv, out pdv2 );
            if( hr == HRESULT.S_OK )
            {
                try
                {

                    uint count = 0;
                    pdv2.GetCount( ref count );

                    for( uint i = 0; i < count; i++ )
                    {
                        PropertyKey propKey = new PropertyKey( );
                        PropVariant propVal = new PropVariant( );
                        try
                        {
                            pdv2.GetAt( i, ref propKey, ref propVal );
                            results.Add( propKey, propVal.Value );
                        }
                        finally
                        {
                            propVal.Clear( );
                        }
                    }
                }
                finally
                {
                    Marshal.ReleaseComObject( pdv2 );
                    pdv2 = null;
                }
            }

            return results;
        }
        #endregion

        #region overridable methods
        /// <summary>
        /// This is called when the Sensor wrapper has been bound to the native ISensor interface
        /// and is ready for subsequent initialization.
        /// </summary>
        protected virtual void Initialize( )
        {
        }
        #endregion

        #region ISensorEvents Members

        void ISensorEvents.OnStateChanged( ISensor sensor, NativeSensorState state )
        {
            if( this.StateChanged != null )
            {
                StateChanged.Invoke( this, EventArgs.Empty );
            }
        }

        void ISensorEvents.OnDataUpdated( ISensor sensor, ISensorDataReport newData )
        {
            this.dataReport = SensorReport.FromNativeReport( this, newData );
            if( DataReportChanged != null )
            {
                DataReportChanged.Invoke( this, EventArgs.Empty );
            }
        }

        void ISensorEvents.OnEvent( ISensor sensor, Guid eventID, ISensorDataReport newData )
        {
        }

        void ISensorEvents.OnLeave( Guid sensorId )
        {
            SensorManager.OnSensorsChanged( sensorId, SensorAvailabilityChange.Removal );
        }

        #endregion

        #region Implementation
        private ISensor nativeISensor;
        internal ISensor internalObject
        {
            get
            {
                return nativeISensor;
            }
            set
            {
                nativeISensor = value;
                SetEventInterest( EventInterestTypes.StateChanged );
                nativeISensor.SetEventSink( this );
                Initialize( );
            }
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="eventType"></param>
        protected void SetEventInterest( Guid eventType )
        {
            if( this.nativeISensor == null )
                throw new SensorPlatformException( "Sensor not initialized" );

            Guid[ ] interestingEvents = GetInterestingEvents( );
            int interestCount = interestingEvents.Length;

            foreach( Guid g in interestingEvents )
            {
                if( g.CompareTo( eventType ) == 0 )
                    return;
            }

            Guid[ ] newEventInterest = new Guid[ interestCount + 1 ];
            interestingEvents.CopyTo( newEventInterest, 0 );
            newEventInterest[ interestCount ] = eventType;
            HRESULT hr = this.nativeISensor.SetEventInterest( newEventInterest, (uint)( interestCount + 1 ) );
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="eventType"></param>
        protected void ClearEventInterest( Guid eventType )
        {
            if( this.nativeISensor == null )
                throw new SensorPlatformException( "Sensor not initialized" );

            if( IsEventInterestSet( eventType ) )
            {
                Guid[ ] interestingEvents = GetInterestingEvents( );
                int interestCount = interestingEvents.Length;

                Guid[ ] newEventInterest = new Guid[ interestCount - 1 ];

                int eventIndex = 0;
                foreach( Guid g in interestingEvents )
                {
                    if( g.CompareTo( eventType ) == 0 )
                    {
                        continue;
                    }
                    else
                    {
                        newEventInterest[ eventIndex ] = g;
                        eventIndex++;
                    }
                }

                this.nativeISensor.SetEventInterest( newEventInterest, (uint)( interestCount - 1 ) );
            }

        }
        /// <summary>
        /// 
        /// </summary>
        /// <param name="eventType"></param>
        /// <returns></returns>
        protected bool IsEventInterestSet( Guid eventType )
        {
            if( this.nativeISensor == null )
                throw new SensorPlatformException( "Sensor not initialized" );

            Guid[ ] interestingEvents = GetInterestingEvents( );

            foreach( Guid g in interestingEvents )
            {
                if( g.CompareTo( eventType ) == 0 )
                {
                    return true;
                }
            }
            return false;
        }

        private Guid[ ] GetInterestingEvents( )
        {
            IntPtr values;
            uint interestCount;
            this.nativeISensor.GetEventInterest( out values, out interestCount );
            Guid[ ] interestingEvents = new Guid[ interestCount ];
            for( int index = 0; index < interestCount; index++ )
            {
                interestingEvents[ index ] = (Guid)Marshal.PtrToStructure( values, typeof( Guid ) );
                values = IncrementIntPtr( values, Marshal.SizeOf( typeof( Guid ) ) );
            }
            return interestingEvents;
        }

        private IntPtr IncrementIntPtr( IntPtr source, int increment )
        {
            if( IntPtr.Size == 8 )
            {
                Int64 p = source.ToInt64( );
                p += increment;
                return new IntPtr( p );
            }
            else if( IntPtr.Size == 4 )
            {
                Int32 p = source.ToInt32( );
                p += increment;
                return new IntPtr( p );
            }
            else
            {
                throw new SensorPlatformException( "Expected pointer size" );
            }
        }

        #endregion
    }

    #region Helper types

    /// <summary>
    /// Structure containing the property ID (key) and value.
    /// </summary>
    public struct DataFieldInfo : IEquatable<DataFieldInfo>
    {
        private PropertyKey _propKey;
        private object _value;

        /// <summary>
        /// Constructs the structure.
        /// </summary>
        /// <param name="propKey">Property ID (key).</param>
        /// <param name="value">Property value. Type must be valid for the ID.</param>
        public DataFieldInfo( PropertyKey propKey, object value )
        {
            _propKey = propKey;
            _value = value;
        }

        /// <summary>
        /// Returns the property key.
        /// </summary>
        public PropertyKey Key
        {
            get { return _propKey; }
        }

        /// <summary>
        /// Returns property's value.
        /// </summary>
        public object Value
        {
            get { return _value; }
        }

        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        public override int GetHashCode( )
        {
            int valHashCode = _value != null ? _value.GetHashCode( ) : 0;
            return _propKey.GetHashCode( ) ^ valHashCode;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="obj"></param>
        /// <returns></returns>
        public override bool Equals( object obj )
        {
            if( obj == null )
                return false;

            if( !( obj is DataFieldInfo ) )
                return false;

            DataFieldInfo other = (DataFieldInfo)obj;
            return _value.Equals( other._value ) && _propKey.Equals( other._propKey );
        }



        #region IEquatable<DataFieldInfo> Members

        /// <summary>
        /// 
        /// </summary>
        /// <param name="other"></param>
        /// <returns></returns>
        public bool Equals( DataFieldInfo other )
        {
            return _value.Equals( other._value ) && _propKey.Equals( other._propKey );
        }

        #endregion

        /// <summary>
        /// 
        /// </summary>
        /// <param name="a"></param>
        /// <param name="b"></param>
        /// <returns></returns>
        public static bool operator ==( DataFieldInfo a, DataFieldInfo b )
        {
            return a.Equals( b );
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="a"></param>
        /// <param name="b"></param>
        /// <returns></returns>
        public static bool operator !=( DataFieldInfo a, DataFieldInfo b )
        {
            return !a.Equals( b );
        }
    }

    #endregion

}
