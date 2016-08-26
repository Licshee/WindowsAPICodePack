//Copyright (c) Microsoft Corporation.  All rights reserved.

using System;
namespace Microsoft.WindowsAPICodePack.Shell
{
    /// <summary>
    /// A refence to an icon resource 
    /// </summary>
    public struct IconRefernece
    {
        private string moduleName;
        private int resourceId;
        private string refPath;
        static private char[] commaSep = new char[] { ',' };

        /// <summary>
        /// 
        /// </summary>
        /// <param name="moduleName"></param>
        /// <param name="resourceId"></param>
        public IconRefernece(string moduleName, int resourceId)
        {
            this.moduleName = moduleName;
            this.resourceId = resourceId;
            refPath = moduleName + "," + resourceId;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="refPath"></param>
        public IconRefernece(string refPath)
        {
            string [] refParams = refPath.Split(commaSep);
            if (refParams.Length != 2)
            {
                throw new ArgumentException("Reference path is invalid.");
            }
            moduleName = refParams[0];
            resourceId = int.Parse(refParams[1]);

            this.refPath = refPath;
        }

        /// <summary>
        /// 
        /// </summary>
        public string ModuleName
        {
            get
            {
                return moduleName;
            }
        }

        /// <summary>
        /// 
        /// </summary>
        public int ResourceId
        {
            get
            {
                return resourceId;
            }
        }

        /// <summary>
        /// 
        /// </summary>
        public string RefPath
        {
            get
            {
                return refPath;
            }
        }

    }

}
