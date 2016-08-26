//Copyright (c) Microsoft Corporation.  All rights reserved.

using System.Collections.Generic;

namespace Microsoft.WindowsAPICodePack.Shell
{
    internal class PropertyDescriptionsCache
    {
        private PropertyDescriptionsCache() { propsDictionary = new Dictionary<PropertyKey, PropertyDescription>(); }
        private IDictionary<PropertyKey, PropertyDescription> propsDictionary = null;
        
        private static PropertyDescriptionsCache cacheInstance = null;

        public static PropertyDescriptionsCache Cache
        {
            get
            {
                if (cacheInstance == null)
                {
                    cacheInstance = new PropertyDescriptionsCache();
                }
                return cacheInstance;
            }        
        }

        public PropertyDescription GetPropertyDescription(PropertyKey key)
        {
            if (!propsDictionary.ContainsKey(key))
            {
                propsDictionary.Add(key, new PropertyDescription(key));
            }
            return propsDictionary[key];
        }
    }
}
