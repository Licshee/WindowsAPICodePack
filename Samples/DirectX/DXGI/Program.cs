// Copyright (c) Microsoft Corporation.  All rights reserved.

using System;
using Microsoft.WindowsAPICodePack.DirectX.Direct3DCommon;
using Microsoft.WindowsAPICodePack.DirectX.DXGI;

namespace DXGITest
{
    class Program
    {
        static void Main(string[] args)
        {
            DisplayAdaptersInfo(new DXGIFactory());
        }

        /// <summary>
        /// Display adapter information; using the given DXGI factory
        /// </summary>
        /// <param name="factory">An initialized DXGI factory object</param>
        private static void DisplayAdaptersInfo(DXGIFactory factory)
        {
            foreach (Adapter a in factory.AdaptersCache)
            {
                AdapterDescription desc = a.Description;
                Console.WriteLine("{0}", a.Description.Description);
                Console.WriteLine("Dedicated System Memory: {0} Bytes", a.Description.DedicatedSystemMemory);
                Console.WriteLine("Dedicated Video Memory: {0} Bytes", a.Description.DedicatedVideoMemory);
                Console.WriteLine("Device Id: {0:X}", a.Description.DeviceId);
                Console.WriteLine("Revision: {0:X}", a.Description.Revision);
                Console.WriteLine("Sub Sys Id: {0:X}", a.Description.SubSysId);
                Console.WriteLine("Vendor Id: {0:X}", a.Description.VendorId);

                int verH, verL;
                bool isSupported = a.CheckDeviceSupport(DeviceType.Direct3D_11_0, out verH, out verL);
                Console.WriteLine("D3D 11.1 Device {0} Supported. User Mode Driver Version: {1:X}:{2:X}", isSupported ? "is" : "not", verH, verL);
                isSupported = a.CheckDeviceSupport(DeviceType.Direct3D_10_1, out verH, out verL);
                Console.WriteLine("D3D 10.1 Device {0} Supported. User Mode Driver Version: {1:X}:{2:X}", isSupported ? "is" : "not", verH, verL);
                isSupported = a.CheckDeviceSupport(DeviceType.Direct3D_10_0, out verH, out verL);
                Console.WriteLine("D3D 10.0 Device {0} Supported. User Mode Driver Version: {1:X}:{2:X}", isSupported ? "is" : "not", verH, verL);
                
                int i = 0;
                foreach (Output o in a.OutputsCache)
                {
                    Console.WriteLine("\tMonitor ({0}): {1}{2}", (i++), o.Description.DeviceName, o.Description.Monitor.IsPrimaryMonitor ? " (Primary Monitor)" : "");
                }
            }
        }

    }
}
