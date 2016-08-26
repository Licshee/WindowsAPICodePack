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
    /// Represents an ELS service.
    /// A detailed overview of the Extended Linguistic Services platform is available at:
    /// http://msdn.microsoft.com/en-us/library/dd317839(VS.85).aspx
    /// </summary>
    public class MappingService
    {
        private Win32Service _win32Service;
        private IntPtr _service;

        /// <summary>
        /// Constructs a new MappingService object by instanciating an ELS service
        /// by its guid. For Windows 7, the only supported GUIDs are provided as
        /// readonly members of the MappingAvailableServices class.
        ///
        /// If the service
        /// with the specified guid doesn't exist, a LinguisticException is throw.
        /// </summary>
        /// <param name="serviceGuid">The guid of the service to instantiate.</param>
        public MappingService(Guid serviceGuid)
        {
            IntPtr pService;
            UInt32 dwServiceCount = 0;
            UInt32 hResult = 0;

            // First, check to see if we already have the service in the cache:
            pService = ServiceCache.Instance.GetCachedService(ref serviceGuid);
            if (pService != IntPtr.Zero)
            {
                _service = pService;
                InteropTools.Unpack(out _win32Service, _service);
            }
            else // pService is IntPtr.Zero in this case.
            {
                // If we don't, we must find it via MappingGetServices:
                IntPtr ptr = IntPtr.Zero;
                try
                {
                    ptr = Marshal.AllocHGlobal(InteropTools.SizeOfGuid);
                    Win32EnumOptions enumOptions = new Win32EnumOptions();
                    enumOptions._size = InteropTools.SizeOfWin32EnumOptions;
                    Marshal.StructureToPtr(serviceGuid, ptr, false);
                    enumOptions._pGuid = ptr;
                    hResult = Win32Methods.MappingGetServices(ref enumOptions, ref pService, ref dwServiceCount);
                    if (hResult != 0)
                    {
                        throw new LinguisticException(hResult);
                    }
                    if (pService == IntPtr.Zero)
                    {
                        throw new InvalidOperationException();
                    }
                    if (dwServiceCount != 1)
                    {
                        hResult = Win32Methods.MappingFreeServices(pService);
                        if (hResult == 0)
                        {
                            throw new InvalidOperationException();
                        }
                        else
                        {
                            throw new LinguisticException(hResult);
                        }
                    }
                    IntPtr[] services = new IntPtr[1];
                    ServiceCache.Instance.RegisterServices(ref pService, services);
                    _service = services[0];
                    InteropTools.Unpack(out _win32Service, _service);
                }
                finally
                {
                    if (pService != IntPtr.Zero)
                    {
                        // Ignore the result if an exception is being thrown.
                        Win32Methods.MappingFreeServices(pService);
                    }
                    if (ptr != IntPtr.Zero)
                    {
                        Marshal.FreeHGlobal(ptr);
                    }
                }
            }
        }

        private MappingService(IntPtr pService)
        {
            _service = pService;
            InteropTools.Unpack(out _win32Service, _service);
        }

        /// <summary>
        /// Retrieves a list of available ELS platform-supported services, along with associated
        /// information, according to application-specified criteria.
        /// </summary>
        /// <param name="options">Optional. A MappingEnumOptions object containing criteria to use during
        /// enumeration of services. The application specifies null for this parameter to retrieve all
        /// installed services.</param>
        /// <returns>An array of MappingService objects matching the criteria supplied in the options
        /// parameter.</returns>
        public static MappingService[] GetServices(MappingEnumOptions options)
        {
            IntPtr pService = IntPtr.Zero;
            UInt32 dwServiceCount = 0;
            UInt32 hResult = 0;
            IntPtr ptr = IntPtr.Zero;
            try
            {
                if (options != null)
                {
                    Win32EnumOptions enumOptions = options._win32EnumOption;
                    Nullable<Guid> pGuid = options._guid;
                    if (pGuid != null)
                    {
                        Guid guid = (Guid)pGuid;
                        ptr = Marshal.AllocHGlobal(InteropTools.SizeOfGuid);
                        Marshal.StructureToPtr(guid, ptr, false);
                        enumOptions._pGuid = ptr;
                    }
                    hResult = Win32Methods.MappingGetServices(ref enumOptions, ref pService, ref dwServiceCount);
                }
                else
                {
                    hResult = Win32Methods.MappingGetServices(IntPtr.Zero, ref pService, ref dwServiceCount);
                }
                if (hResult != 0)
                {
                    throw new LinguisticException(hResult);
                }
                if ((pService == IntPtr.Zero) != (dwServiceCount == 0))
                {
                    throw new InvalidOperationException();
                }
                IntPtr[] services = new IntPtr[dwServiceCount];
                ServiceCache.Instance.RegisterServices(ref pService, services);
                MappingService[] result = new MappingService[dwServiceCount];
                for (int i = 0; i < dwServiceCount; ++i)
                {
                    result[i] = new MappingService(services[i]);
                }
                return result;
            }
            finally
            {
                if (pService != IntPtr.Zero)
                {
                    // Ignore the result if an exception is being thrown.
                    Win32Methods.MappingFreeServices(pService);
                }
                if (ptr != IntPtr.Zero)
                {
                    Marshal.FreeHGlobal(ptr);
                }
            }
        }

        /// <summary>
        /// Calls an ELS service to recognize text. For example, the Microsoft Language Detection service
        /// will attempt to recognize the language in which the input text is written.
        /// </summary>
        /// <param name="text">The text to recognize. The text must be UTF-16, but some services have additional
        /// requirements for the input format. This parameter cannot be set to null.</param>
        /// <param name="options">Optional. A MappingOptions object containing options that affect the result and
        /// behavior of text recognition. The application does not have to specify values for all object members.
        /// This parameter can be set to null to use the default mapping options.</param>
        /// <returns>A MappingPropertyBag object in which the service has stored its results. The structure is filled
        /// with information produced by the service during text recognition.</returns>
        public MappingPropertyBag RecognizeText(string text, MappingOptions options)
        {
            if (text == null)
            {
                throw new ArgumentNullException();
            }
            return RecognizeText(text, text.Length, 0, options);
        }

        /// <summary>
        /// Calls an ELS service to recognize text. For example, the Microsoft Language Detection service
        /// will attempt to recognize the language in which the input text is written.
        /// </summary>
        /// <param name="text">The text to recognize. The text must be UTF-16, but some services have additional
        /// requirements for the input format. This parameter cannot be set to null.</param>
        /// <param name="length">Length, in characters, of the text specified in text.</param>
        /// <param name="index">Index inside the specified text to be used by the service. This value should be
        /// between 0 and length-1. If the application wants to process the entire text, it should set this
        /// parameter to 0.</param>
        /// <param name="options">Optional. A MappingOptions object containing options that affect the result and
        /// behavior of text recognition. The application does not have to specify values for all object members.
        /// This parameter can be set to null to use the default mapping options.</param>
        /// <returns>A MappingPropertyBag object in which the service has stored its results. The structure is filled
        /// with information produced by the service during text recognition.</returns>
        public MappingPropertyBag RecognizeText(string text, int length, int index, MappingOptions options)
        {
            if (text == null)
            {
                throw new ArgumentNullException();
            }
            if (length > text.Length || length < 0 || index < 0)
            {
                throw new ArgumentOutOfRangeException();
            }
            UInt32 hResult = LinguisticException.E_FAIL;
            MappingPropertyBag bag = new MappingPropertyBag(options, text);
            try
            {
                hResult = Win32Methods.MappingRecognizeText(
                    _service, bag._text, (uint)length, (uint)index, bag._options, ref bag._win32PropertyBag);
                if (hResult != 0)
                {
                    throw new LinguisticException(hResult);
                }
                return bag;
            }
            finally
            {
                if (hResult != 0) // S_OK
                {
                    bag.Dispose();
                }
            }
        }

        private void RunRecognizeText(object threadContext)
        {
            MappingRecognizeAsyncResult asyncResult = (MappingRecognizeAsyncResult)threadContext;
            MappingResultState resultState = new MappingResultState();
            MappingPropertyBag bag = null;
            try
            {
                bag = this.RecognizeText(asyncResult.Text, asyncResult.Length, asyncResult.Index, asyncResult.Options);
            }
            catch (LinguisticException linguisticException)
            {
                resultState = linguisticException.ResultState;
            }
            asyncResult.SetResult(bag, resultState);
            // Don't catch any exceptions.
            try
            {
                asyncResult.AsyncCallback(asyncResult);
            }
            finally
            {
                Thread.MemoryBarrier();
                ((ManualResetEvent)asyncResult.AsyncWaitHandle).Set();
            }
        }

        /// <summary>
        /// Calls an ELS service to recognize text. For example, the Microsoft Language Detection service
        /// will attempt to recognize the language in which the input text is written. The execution will be
        /// handled in a thread from the managed thread pool, and the asynchronous wait handle of the returned
        /// MappingRecognizeAsyncResult object will be notified when the operation completes. The results of
        /// the call will be stored inside the MappingRecognizeAsyncResult object.
        /// </summary>
        /// <param name="text">The text to recognize. The text must be UTF-16, but some services have additional
        /// requirements for the input format. This parameter cannot be set to null.</param>
        /// <param name="options">Optional. A MappingOptions object containing options that affect the result and
        /// behavior of text recognition. The application does not have to specify values for all object members.
        /// This parameter can be set to null to use the default mapping options.</param>
        /// <param name="asyncCallback">An application callback delegate to receive callbacks with the results from
        /// the recognize operation. Cannot be set to null.</param>
        /// <param name="callerData"></param>
        /// <returns>A MappingPropertyBag object in which the service has stored its results. The structure is filled
        /// with information produced by the service during text recognition.</returns>
        public MappingRecognizeAsyncResult BeginRecognizeText(string text, MappingOptions options, AsyncCallback asyncCallback, object callerData)
        {
            if (text == null)
            {
                throw new ArgumentNullException();
            }
            return BeginRecognizeText(text, text.Length, 0, options, asyncCallback, callerData);
        }

        /// <summary>
        /// Calls an ELS service to recognize text. For example, the Microsoft Language Detection service
        /// will attempt to recognize the language in which the input text is written. The execution will be
        /// handled in a thread from the managed thread pool, and the asynchronous wait handle of the returned
        /// MappingRecognizeAsyncResult object will be notified when the operation completes. The results of
        /// the call will be stored inside the MappingRecognizeAsyncResult object.
        /// </summary>
        /// <param name="text">The text to recognize. The text must be UTF-16, but some services have additional
        /// requirements for the input format. This parameter cannot be set to null.</param>
        /// <param name="length">Length, in characters, of the text specified in text.</param>
        /// <param name="index">Index inside the specified text to be used by the service. This value should be
        /// between 0 and length-1. If the application wants to process the entire text, it should set this
        /// parameter to 0.</param>
        /// <param name="options">Optional. A MappingOptions object containing options that affect the result and
        /// behavior of text recognition. The application does not have to specify values for all object members.
        /// This parameter can be set to null to use the default mapping options.</param>
        /// <param name="asyncCallback">An application callback delegate to receive callbacks with the results from
        /// the recognize operation. Cannot be set to null.</param>
        /// <param name="callerData">Optional. Private application object passed to the callback function
        /// by a service after text recognition is complete. The application must set this parameter to null to
        /// indicate no private application data.</param>
        /// <returns>A MappingRecognizeAsyncResult object describing the asynchronous operation.</returns>
        public MappingRecognizeAsyncResult BeginRecognizeText(string text, int length, int index, MappingOptions options, AsyncCallback asyncCallback, object callerData)
        {
            if (asyncCallback == null)
            {
                throw new ArgumentNullException();
            }
            MappingRecognizeAsyncResult result = new MappingRecognizeAsyncResult(callerData, asyncCallback, text, length, index, options);
            ThreadPool.QueueUserWorkItem(this.RunRecognizeText, result);
            return result;
        }

        /// <summary>
        /// Waits for the asynchronous operation to complete.
        /// </summary>
        /// <param name="asyncResult">The MappingRecognizeAsyncResult object associated with the operation.</param>
        public static void EndRecognizeText(MappingRecognizeAsyncResult asyncResult)
        {
            if (!asyncResult.IsCompleted)
            {
                asyncResult.AsyncWaitHandle.WaitOne();
            }
        }

        /// <summary>
        /// Causes an ELS service to perform an action after text recognition has occurred. For example,
        /// a phone dialer service first must recognize phone numbers and then can perform the "action"
        /// of dialing a number.
        /// </summary>
        /// <param name="bag">A MappingPropertyBag object containing the results of a previous call to
        /// MappingRecognizeText. This parameter cannot be set to null.</param>
        /// <param name="rangeIndex">A starting index inside the text recognition results for a recognized
        /// text range. This value should be between 0 and the range count.</param>
        /// <param name="actionID">The identifier of the action to perform.
        /// This parameter cannot be set to null.</param>
        public void DoAction(MappingPropertyBag bag, int rangeIndex, string actionID)
        {
            if (rangeIndex < 0)
            {
                throw new LinguisticException(LinguisticException.E_INVALIDARG);
            }
            UInt32 hResult = Win32Methods.MappingDoAction(ref bag._win32PropertyBag, (uint)rangeIndex, actionID);
            if (hResult != 0)
            {
                throw new LinguisticException(hResult);
            }
        }

        private void RunDoAction(object threadContext)
        {
            MappingActionAsyncResult asyncResult = (MappingActionAsyncResult)threadContext;
            MappingResultState resultState = new MappingResultState();
            try
            {
                this.DoAction(asyncResult.PropertyBag, asyncResult.RangeIndex, asyncResult.ActionID);
            }
            catch (LinguisticException linguisticException)
            {
                resultState = linguisticException.ResultState;
            }
            asyncResult.SetResult(asyncResult.PropertyBag, resultState);
            // Don't catch any exceptions.
            try
            {
                asyncResult.AsyncCallback(asyncResult);
            }
            finally
            {
                Thread.MemoryBarrier();
                ((ManualResetEvent)asyncResult.AsyncWaitHandle).Set();
            }
        }

        /// <summary>
        /// Causes an ELS service to perform an action after text recognition has occurred. For example,
        /// a phone dialer service first must recognize phone numbers and then can perform the "action"
        /// of dialing a number.
        /// </summary>
        /// <param name="bag">A MappingPropertyBag object containing the results of a previous call to
        /// MappingRecognizeText. This parameter cannot be set to null.</param>
        /// <param name="rangeIndex">A starting index inside the text recognition results for a recognized
        /// text range. This value should be between 0 and the range count.</param>
        /// <param name="actionID">The identifier of the action to perform.
        /// This parameter cannot be set to null.</param>
        /// <param name="asyncCallback">An application callback delegate to receive callbacks with the results from
        /// the action operation. Cannot be set to null.</param>
        /// <param name="callerData">Optional. Private application object passed to the callback function
        /// by a service after the action operation is complete. The application must set this parameter to null
        /// to indicate no private application data.</param>
        /// <returns>A MappingActionAsyncResult object describing the asynchronous operation.</returns>
        public MappingActionAsyncResult BeginDoAction(MappingPropertyBag bag, int rangeIndex, string actionID, AsyncCallback asyncCallback, object callerData)
        {
            MappingActionAsyncResult result = new MappingActionAsyncResult(callerData, asyncCallback, bag, rangeIndex, actionID);
            ThreadPool.QueueUserWorkItem(this.RunDoAction, result);
            return result;
        }

        /// <summary>
        /// Waits for the asynchronous operation to complete.
        /// </summary>
        /// <param name="asyncResult">The MappingActionAsyncResult object associated with the operation.</param>
        public static void EndDoAction(MappingActionAsyncResult asyncResult)
        {
            if (!asyncResult.IsCompleted)
            {
                asyncResult.AsyncWaitHandle.WaitOne();
            }
        }

        /// <summary>
        /// Copyright information about the service.
        /// </summary>
        public string Copyright
        {
            get
            {
                return _win32Service._copyright;
            }
        }

        /// <summary>
        /// Major version number that is used to track changes to the service.
        /// </summary>
        public int MajorVersion
        {
            get
            {
                return _win32Service._majorVersion;
            }
        }

        /// <summary>
        /// Minor version number that is used to track changes to the service.
        /// </summary>
        public int MinorVersion
        {
            get
            {
                return _win32Service._minorVersion;
            }
        }

        /// <summary>
        /// Build version that is used to track changes to the service.
        /// </summary>
        public int BuildVersion
        {
            get
            {
                return _win32Service._buildVersion;
            }
        }

        /// <summary>
        /// Step version that is used to track changes to the service.
        /// </summary>
        public int StepVersion
        {
            get
            {
                return _win32Service._stepVersion;
            }
        }

        /// <summary>
        /// Optional. A collection of input content types, following the format of the MIME content types, that
        /// identify the format that the service interprets when the application passes data. Examples of
        /// content types are "text/plain", "text/html" and "text/css".
        /// </summary>
        public IEnumerable<string> InputContentTypes
        {
            get
            {
                return InteropTools.UnpackStringArray(_win32Service._inputContentTypes, _win32Service._inputContentTypesCount);
            }
        }

        /// <summary>
        /// Optional. A collection of output content types, following the format of the MIME content types, that
        /// identify the format in which the service retrieves data.
        /// </summary>
        public IEnumerable<string> OutputContentTypes
        {
            get
            {
                return InteropTools.UnpackStringArray(_win32Service._outputContentTypes, _win32Service._outputContentTypesCount);
            }
        }

        /// <summary>
        /// A collection of the input languages, following the IETF naming convention, that the service accepts. This
        /// member is set to null if the service can work with any input language.
        /// </summary>
        public IEnumerable<string> InputLanguages
        {
            get
            {
                return InteropTools.UnpackStringArray(_win32Service._inputLanguages, _win32Service._inputLanguagesCount);
            }
        }

        /// <summary>
        /// A collection of output languages, following the IETF naming convention, in which the service can retrieve
        /// results. This member is set to null if the service can retrieve results in any language, or if the service
        /// ignores the output language.
        /// </summary>
        public IEnumerable<string> OutputLanguages
        {
            get
            {
                return InteropTools.UnpackStringArray(_win32Service._outputLanguages, _win32Service._outputLanguagesCount);
            }
        }

        /// <summary>
        /// A collection of input scripts, with Unicode standard script names, that are supported by the service.
        /// This member is set to null if the service can work with any scripts, or if the service ignores the
        /// input scripts.
        /// </summary>
        public IEnumerable<string> InputScripts
        {
            get
            {
                return InteropTools.UnpackStringArray(_win32Service._inputScripts, _win32Service._inputScriptsCount);
            }
        }

        /// <summary>
        /// A collection of output scripts supported by the service. This member is set to null if the service can work with
        /// any scripts, or the service ignores the output scripts.
        /// </summary>
        public IEnumerable<string> OutputScripts
        {
            get
            {
                return InteropTools.UnpackStringArray(_win32Service._outputScripts, _win32Service._outputScriptsCount);
            }
        }

        /// <summary>
        /// Globally unique identifier (guid) for the service.
        /// </summary>
        public Guid Guid
        {
            get
            {
                return _win32Service._guid;
            }
        }

        /// <summary>
        /// The service category for the service, for example, "Transliteration".
        /// </summary>
        public string Category
        {
            get
            {
                return _win32Service._category;
            }
        }

        /// <summary>
        /// The service description. This text can be localized.
        /// </summary>
        public string Description
        {
            get
            {
                return _win32Service._description;
            }
        }

        /// <summary>
        /// Flag indicating the language mapping between input language and output language that is supported
        /// by the service. Possible values are shown in the following table.
        /// 0 - The input and output languages are not paired and the service can receive data in any of the
        /// input languages and render data in any of the output languages.
        /// 1 - The arrays of the input and output languages for the service are paired. In other words, given
        /// a particular input language, the service retrieves results in the paired language defined in the
        /// output language array. Use of the language pairing can be useful, for example, in bilingual
        /// dictionary scenarios.
        /// </summary>
        public bool IsOneToOneLanguageMapping
        {
            get
            {
                return (_win32Service._serviceTypes & ServiceTypes.IsOneToOneLanguageMapping)
                    == ServiceTypes.IsOneToOneLanguageMapping;
            }
        }
    }

}
