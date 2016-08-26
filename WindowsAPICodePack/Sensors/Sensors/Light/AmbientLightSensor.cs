// Copyright (c) Microsoft Corporation.  All rights reserved.

using System;
using System.Collections.Generic;
using System.Text;

namespace Microsoft.WindowsAPICodePack.Sensors
{
    /// <summary>
    /// Represents a generic ambient light sensor
    /// </summary>
    [SensorDescription( "97F115C8-599A-4153-8894-D2D12899918A" )]
    public class AmbientLightSensor : Sensor
    {
        /// <summary>
        /// This is a luminous intensity measurement. 
        /// </summary>
        public class LuminousIntensity
        {
            /// <summary>
            /// Evaluates a sensor report to obtain a luminous intensity value.
            /// </summary>
            /// <param name="report"></param>
            /// <returns></returns>
            public LuminousIntensity( SensorReport report )
            {
                if( report.Values.ContainsKey( SensorPropertyKeys.SENSOR_DATA_TYPE_LIGHT_LUX.FormatId ) )
                {
                    this.intensity =
                        (float)report.Values[ SensorPropertyKeys.SENSOR_DATA_TYPE_LIGHT_LUX.FormatId ][ 0 ];
                }
            }
            /// <summary>
            /// 
            /// </summary>
            public float Intensity
            {
                get
                {
                    return intensity;
                }
            }
            float intensity = 0;
        }

        /// <summary>
        /// Gets an array representing the light response curve.
        /// </summary>
        public uint[] LightResponseCurve
        {
            get
            {
                return (uint[])GetProperty( SensorPropertyKeys.SENSOR_PROPERTY_LIGHT_RESPONSE_CURVE );
            }
        }

        /// <summary>
        /// The current luminous intensity of the sensor
        /// </summary>
        public LuminousIntensity CurrentLuminousIntensity
        {
            get
            {
                return new LuminousIntensity( this.DataReport );
            }
        }

    }
}
