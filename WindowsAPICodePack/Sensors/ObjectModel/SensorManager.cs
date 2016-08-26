// Copyright (c) Microsoft Corporation.  All rights reserved.

using System;
using System.Collections.Generic;
using System.Threading;
using System.Reflection;

namespace Microsoft.WindowsAPICodePack.Sensors
{
    /// <summary>
    /// 
    /// </summary>
    public enum SensorAvailabilityChange
    {
        /// <summary>
        /// 
        /// </summary>
        Addition,
        /// <summary>
        /// 
        /// </summary>
        Removal
    }

    /// <summary>
    /// 
    /// </summary>
    public class SensorsChangedEventArgs : EventArgs
    {
        /// <summary>
        /// The type of change 
        /// </summary>
        public SensorAvailabilityChange Change;
        
        /// <summary>
        /// The Id of the sensor that changed
        /// </summary>
        public Guid SensorId;

        /// <summary>
        /// 
        /// </summary>
        /// <param name="SensorId"></param>
        /// <param name="change"></param>
        public SensorsChangedEventArgs( Guid SensorId, SensorAvailabilityChange change )
        {
            this.SensorId = SensorId;
            this.Change = change;
        }
    }
    
    /// <summary>
    /// 
    /// </summary>
    /// <param name="change"></param>
    public delegate void SensorsChangedHandler( SensorsChangedEventArgs change );

    /// <summary>
    /// Manages the sensors conected to the system.
    /// </summary>
    public static class SensorManager
    {
        #region Public Methods
        /// <summary>
        /// Retireves a collection of all sensors
        /// </summary>
        /// <returns></returns>
        public static SensorList<Sensor> GetAllSensors( )
        {
            return GetSensorsByCategoryId( SensorCategories.All );
        }

        /// <summary>
        /// Retrieves a collection of sensors filtered by category Id
        /// </summary>
        /// <param name="catagory"></param>
        /// <returns></returns>
        public static SensorList<Sensor> GetSensorsByCategoryId( Guid catagory )
        {
            ISensorCollection sensorCollection = null;
            sensorManager.GetSensorsByCategory( catagory, out sensorCollection );
            return nativeSensorCollectionToSensorCollection<Sensor>( sensorCollection );
        }

        /// <summary>
        /// Returns a collection of sensors foltered by type Id
        /// </summary>
        /// <param name="typeId"></param>
        /// <returns></returns>
        public static SensorList<Sensor> GetSensorsByTypeId( Guid typeId )
        {
            ISensorCollection sensorCollection = null;
            sensorManager.GetSensorsByType( typeId, out sensorCollection );
            return nativeSensorCollectionToSensorCollection<Sensor>( sensorCollection );
        }

        /// <summary>
        /// Returns a collection specific sensor types
        /// </summary>
        /// <typeparam name="S"></typeparam>
        /// <returns></returns>
        public static SensorList<S> GetSensorsByTypeId<S>( )
            where S: Sensor
        {
            object[ ] attrs = typeof( S ).GetCustomAttributes( typeof( SensorDescriptionAttribute ), true );
            if( attrs != null && attrs.Length > 0 )
            {
                SensorDescriptionAttribute sda = attrs[0] as SensorDescriptionAttribute;

                ISensorCollection nativeSensorCollection = null;
                sensorManager.GetSensorsByType( sda.SensorTypeGuid, out nativeSensorCollection );
                return nativeSensorCollectionToSensorCollection<S>( nativeSensorCollection );
            }
            else
                return new SensorList<S>();
        }

        /// <summary>
        /// Returns a specific sensor by sensorId
        /// </summary>
        /// <typeparam name="S">A strongly typed sensor</typeparam>
        /// <returns>A particular sensor</returns>
        public static S GetSensorBySensorId<S>( Guid sensorId )
            where S: Sensor
        {
            ISensor nativeSensor = null;
            sensorManager.GetSensorByID( sensorId, out nativeSensor );
            if( nativeSensor != null )
            {
                return GetSensorWrapperInstance<S>( nativeSensor );
            }

            return null;
        }
        
        /// <summary>
        /// Opens a system dialog box to request user permission to access sensor data.
        /// </summary>
        /// <param name="parentWindowHandle">The handle to a window that can act as a parent to the permissions dialog box.</param>
        /// <param name="modal">speficifies whether the window should be modal.</param>
        /// <param name="sensors">The sensors for which to request permission.</param>
        public static void RequestPermission( IntPtr parentWindowHandle, bool modal, SensorList<Sensor> sensors )
        {
            if( sensors == null && sensors.Count == 0 )
                throw new ArgumentNullException( "sensors", "Sensors collection must not be null or empty." );

            ISensorCollection sensorCollection = new  SensorCollection( );

            foreach( Sensor sensor in sensors )
            {
                sensorCollection.Add( sensor.internalObject );
            }

            sensorManager.RequestPermissions( parentWindowHandle, sensorCollection, modal );
        }

        #endregion

        #region Public Events
        /// <summary>
        /// 
        /// </summary>
        public static event SensorsChangedHandler SensorsChanged;
        #endregion

        #region implementation
        private static nativeISensorManager sensorManager = null;
        private static nativeSensorManagerEventSink sensorManagerEventSink = null;

        /// <summary>
        /// Sensor type GUID -> .NET Type + report type
        /// </summary>
        private static Dictionary<Guid, SensorTypeData> guidToSensorDescr = new Dictionary<Guid, SensorTypeData>( );

        /// <summary>
        /// .NET type -> type GUID.
        /// </summary>      
        private static Dictionary<Type, Guid> sensorTypeToGuid = new Dictionary<Type, Guid>( );
        /// <summary>
        /// 
        /// </summary>
        static SensorManager( )
        {
            if( !CoreHelpers.RunningOnWin7 )
            {
                throw new PlatformNotSupportedException( "Only supported on Windows 7." );
            }

            BuildSensorTypeMap( );
            sensorManager = new NativeSensorManager( );
            sensorManagerEventSink = new nativeSensorManagerEventSink( );
            Thread.MemoryBarrier( );
            sensorManager.SetEventSink( sensorManagerEventSink );
        }

        internal static SensorList<S> nativeSensorCollectionToSensorCollection<S>( ISensorCollection nativeCollection ) where S: Sensor
        {
            SensorList<S> sensors = new SensorList<S>( );

            if( nativeCollection != null )
            {
                uint sensorCount = 0;
                nativeCollection.GetCount( out sensorCount );

                for( uint i = 0; i < sensorCount; i++ )
                {
                    ISensor iSensor = null;
                    nativeCollection.GetAt( i, out iSensor );
                    S sensor = GetSensorWrapperInstance<S>( iSensor );
                    sensor.internalObject = iSensor;
                    sensors.Add( sensor );
                }
            }

            return sensors;
        }

        /// <summary>
        /// Notification that the list of sensors has changed
        /// </summary>
        internal static void OnSensorsChanged( Guid sensorId, SensorAvailabilityChange change )
        {
            if( SensorsChanged != null )
            {
                SensorsChanged.Invoke( new SensorsChangedEventArgs( sensorId, change ) );
            }
        }

        /// <summary>
        /// Interrogates assemblies currently loaded into the AppDomain for classes deriving from <see cref="Sensor"/>.
        /// Builds data structures which map those types to sensor type GUIDs. 
        /// </summary>
        private static void BuildSensorTypeMap( )
        {
            Assembly[ ] loadedAssemblies = AppDomain.CurrentDomain.GetAssemblies( );

            foreach( Assembly asm in loadedAssemblies )
            {
                Type[ ] exportedTypes = asm.GetExportedTypes( );
                foreach( Type t in exportedTypes )
                {
                    if( t.IsSubclassOf( typeof( Sensor ) ) && t.IsPublic && !t.IsAbstract && !t.IsGenericType )
                    {
                        object[ ] attrs = t.GetCustomAttributes( typeof( SensorDescriptionAttribute ), true );
                        if( attrs != null && attrs.Length > 0 )
                        {
                            SensorDescriptionAttribute sda = (SensorDescriptionAttribute)attrs[ 0 ];
                            SensorTypeData stm = new SensorTypeData( t, sda );
                            
                            guidToSensorDescr.Add( sda.SensorTypeGuid, stm );
                            sensorTypeToGuid.Add( t, sda.SensorTypeGuid );
                        }
                    }
                }
            }
        }

        /// <summary>
        /// Returns an instance of a sensor wrapper appropritate for the given sensor COM interface.
        /// If no appropriate sensor wrapper type could be found, the object created will be of the base-class type <see cref="Sensor"/>.
        /// </summary>
        /// <param name="nativeISensor">The underlying sensor COM interface.</param>
        /// <returns>A wrapper instance.</returns>
        private static S GetSensorWrapperInstance<S>( ISensor nativeISensor ) where S: Sensor
        {
            Guid sensorTypeGuid;
            nativeISensor.GetType( out sensorTypeGuid );

            SensorTypeData stm;
            Type sensorClassType = 
                guidToSensorDescr.TryGetValue( sensorTypeGuid, out stm ) ? stm.SensorType : typeof( UnknownSensor );

            S sensor = (S)Activator.CreateInstance( sensorClassType );
            sensor.internalObject = nativeISensor;
            
            return sensor;
        }

        #endregion
    }

    #region helper classes
    /// <summary>
    /// Data associated with a sensor type GUID.
    /// </summary>
    internal struct SensorTypeData
    {
        private Type sensorType;
        private SensorDescriptionAttribute sda;

        public SensorTypeData( Type sensorClassType, SensorDescriptionAttribute sda )
        {
            this.sensorType = sensorClassType;
            this.sda = sda;
        }

        public Type SensorType
        {
            get { return this.sensorType; }
        }


        public SensorDescriptionAttribute Attr
        {
            get { return this.sda; }
        }
    }

    internal class nativeSensorManagerEventSink : ISensorManagerEvents
    {
        #region nativeISensorManagerEvents Members

        public void OnSensorEnter( ISensor nativeSensor, NativeSensorState state )
        {
            if( state == NativeSensorState.Ready )
            {
                Guid sensorId;
                HRESULT hr = nativeSensor.GetID( out sensorId );
                if( hr == HRESULT.S_OK )
                    SensorManager.OnSensorsChanged( sensorId, SensorAvailabilityChange.Addition );
            }
        }

        #endregion
    }
    #endregion
}
