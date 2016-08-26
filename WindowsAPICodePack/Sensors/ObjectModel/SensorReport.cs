// Copyright (c) Microsoft Corporation.  All rights reserved.

using System;
using System.Runtime.InteropServices.ComTypes;

namespace Microsoft.WindowsAPICodePack.Sensors
{
    /// <summary>
    /// 
    /// </summary>
    public class SensorReport
    {
        /// <summary>
        /// 
        /// </summary>
        public DateTime TimeStamp
        {
            get
            {
                return timeStamp;
            }
        }
        private DateTime timeStamp = new DateTime();

        /// <summary>
        /// 
        /// </summary>
        public SensorData Values
        {
            get
            {
                return sensorData;
            }
        }
        private SensorData sensorData = null;

        /// <summary>
        /// 
        /// </summary>
        public Sensor Source
        {
            get
            {
                return originator;
            }
        }
        Sensor originator = null; 

        #region implementation 
        /// <summary>
        /// 
        /// </summary>
        /// <param name="originator"></param>
        /// <param name="iReport"></param>
        /// <returns></returns>
        internal static SensorReport FromNativeReport( Sensor originator, ISensorDataReport iReport )
        {

            SYSTEMTIME systemTimeStamp = new SYSTEMTIME( );
            iReport.GetTimestamp( out systemTimeStamp );
            FILETIME ftTimeStamp = new FILETIME( );
            SensorNativeMethods.SystemTimeToFileTime( ref systemTimeStamp, out ftTimeStamp );
            long lTimeStamp = (((long)ftTimeStamp.dwHighDateTime) << 32) + (long)ftTimeStamp.dwLowDateTime;
            DateTime timeStamp = DateTime.FromFileTime( lTimeStamp );

            SensorReport sensorReport = new SensorReport( );
            sensorReport.originator = originator;
            sensorReport.timeStamp = timeStamp;
            sensorReport.sensorData = SensorData.FromNativeReport( originator.internalObject, iReport );            

            return sensorReport;
        }
        #endregion

    }
}
