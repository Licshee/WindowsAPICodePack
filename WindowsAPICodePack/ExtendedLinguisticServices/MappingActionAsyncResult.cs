// Copyright (c) Microsoft Corporation.  All rights reserved.

using System;
using System.ComponentModel;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading;
using System.Runtime.ConstrainedExecution;
using System.Collections.Generic;

namespace Microsoft.WindowsAPICodePack.ExtendedLinguisticServices
{

    /// <summary>
    /// A MappingAsyncResult subclass to be used only for asynchronous calls to service actions.
    /// (MappingService.BeginDoAction).
    /// </summary>
    public class MappingActionAsyncResult : MappingAsyncResult
    {
        private int _rangeIndex;
        private string _actionID;

        internal MappingActionAsyncResult(
            object callerData,
            AsyncCallback asyncCallback,
            MappingPropertyBag bag,
            int rangeIndex,
            string actionID)
        : base(callerData, asyncCallback)
        {
            base.SetResult(bag, new MappingResultState());
            _rangeIndex = rangeIndex;
            _actionID = actionID;
        }

        /// <summary>
        /// Gets the range index parameter for MappingService.DoAction or MappingService.BeginDoAction.
        /// </summary>
        public int RangeIndex
        {
            get
            {
                return _rangeIndex;
            }
        }

        /// <summary>
        /// Gets the action ID parameter for MappingService.DoAction or MappingService.BeginDoAction.
        /// </summary>
        public string ActionID
        {
            get
            {
                return _actionID;
            }
        }
    }

}
