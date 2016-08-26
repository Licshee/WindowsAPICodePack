// Copyright (c) Microsoft Corporation.  All rights reserved.

using System;

namespace Microsoft.WindowsAPICodePack.Sensors
{
    /// <summary>
    /// 
    /// </summary>
    public class SensorPlatformException : Exception
    {
        /// <summary>
        /// 
        /// </summary>
        /// <param name="message"></param>
        public SensorPlatformException( string message )
            : base( message )
        {
        }
        /// <summary>
        /// 
        /// </summary>
        public SensorPlatformException(  )
            : base(  )
        {
        }
        /// <summary>
        /// 
        /// </summary>
        /// <param name="message"></param>
        /// <param name="innerException"></param>
        public SensorPlatformException( string message, Exception innerException )
            : base( message, innerException )
        {
        }
    }
}