//Copyright (c) Microsoft Corporation.  All rights reserved.

using System.Collections.Generic;

namespace Microsoft.WindowsAPICodePack.Shell
{
    interface IShellContainer<T> : IShellContainer, IEnumerable<T>
        where T : ShellObject
    {
    }
}
