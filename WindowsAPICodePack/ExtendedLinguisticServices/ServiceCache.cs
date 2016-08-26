// Copyright (c) Microsoft Corporation.  All rights reserved.

using System;
using System.Runtime.InteropServices;
using System.Threading;
using System.Collections;
using System.Runtime.ConstrainedExecution;
using System.Collections.Generic;

namespace Microsoft.WindowsAPICodePack.ExtendedLinguisticServices
{

    // This singleton object is correctly finalized on appdomain unload.
    internal class ServiceCache : CriticalFinalizerObject
    {
        private static ServiceCache staticInstance = null;

        // Guid -> IntPtr
        private Dictionary<Guid, IntPtr> _guidToService = new Dictionary<Guid, IntPtr>();
        // IntPtr -> this (serves as a set)
        private List<IntPtr> _servicePointers = new List<IntPtr>();
        // The lock
        private object _mutex = new object();
        // Active resources refcount, signed 64-bit
        private Int64 _resourceRefCount = 0;
        // Specifies if the object has been finalized:
        private int _finalized = 0;

        private ServiceCache()
        {
        }

        ~ServiceCache()
        {
            ReleaseHandle();
        }

        internal IntPtr GetCachedService(ref Guid guid)
        {
            if (_guidToService.ContainsKey(guid))
            {
                return _guidToService[guid];
            }
            return IntPtr.Zero;
        }

        internal void RegisterServices(ref IntPtr originalPtr, IntPtr[] services)
        {
            IntPtr pServices = originalPtr;
            int count = 0;
            for (int i = 0; i < services.Length; ++i)
            {
                Guid guid = (Guid)Marshal.PtrToStructure(
                    (IntPtr)((UInt64)pServices + InteropTools.OffsetOfGuidInService), InteropTools.TypeOfGuid);
                IntPtr cachedValue = IntPtr.Zero;
                if (!_guidToService.ContainsKey(guid))
                {
                    lock (_mutex)
                    {
                        if (!_guidToService.ContainsKey(guid))
                        {
                            _guidToService.Add(guid, pServices);
                            cachedValue = pServices;
                        }
                    }
                }
                if (cachedValue == IntPtr.Zero)
                {
                    cachedValue = _guidToService[guid];
                }
                else
                {
                    ++count;
                }
                services[i] = cachedValue;
                pServices = (IntPtr)((UInt64)pServices + InteropTools.SizeOfService);
            }
            if (count > 0)
            {
                lock (_mutex)
                {
                    _servicePointers.Add(originalPtr);
                }
                originalPtr = IntPtr.Zero;
            }
            else
            {
                UInt32 hResult = Win32Methods.MappingFreeServices(originalPtr);
                originalPtr = IntPtr.Zero;
                if (hResult != 0)
                {
                    throw new LinguisticException(hResult);
                }
            }
        }

        internal bool RegisterResource()
        {
            // The correctness of this code relies on the
            // fact that there can be no Int64.MaxValue / 2
            // executing this code at the same time.
            if (Interlocked.Increment(ref _resourceRefCount) > Int64.MaxValue / 2)
            {
                Interlocked.Decrement(ref _resourceRefCount);
                return false;
            }
            return true;
        }

        internal void UnregisterResource()
        {
            if (Interlocked.Decrement(ref _resourceRefCount) == 0 && IsInvalid)
            {
                FreeAllServices();
            }
        }

        private bool IsInvalid
        {
            get
            {
                return Interlocked.CompareExchange(ref _finalized, 1, 1) != 0;
            }
        }

        private void ReleaseHandle()
        {
            if (!IsInvalid)
            {
                if (Interlocked.Read(ref _resourceRefCount) == 0)
                {
                    FreeAllServices();
                }
                Interlocked.CompareExchange(ref _finalized, 1, 0);
            }
        }

        private void FreeAllServices()
        {
            lock (_mutex)
            {
                if (_servicePointers != null)
                {
                    foreach (IntPtr servicePtr in _servicePointers)
                    {
                        // Ignore the result, we need to continue anyway.
                        Win32Methods.MappingFreeServices(servicePtr);
                    }
                    _servicePointers = null;
                    _guidToService = null;
                }
            }
        }

        internal static ServiceCache Instance
        {
            get
            {
                if (Interlocked.CompareExchange(ref staticInstance, null, null) == null)
                {
                    ServiceCache cache = new ServiceCache();
                    ServiceCache previousValue = Interlocked.CompareExchange(ref staticInstance, cache, null);
                    if (previousValue != null)
                    {
                        System.GC.SuppressFinalize(cache);
                    }
                }
                return Interlocked.CompareExchange(ref staticInstance, null, null);
            }
        }

    }

}
