This release of Windows API Code Pack contains managed wrappers for DXGI 1.0/1.1 and Direct3D 11.0 
APIs.
These managed wrappers are provided as a “technical preview” of what’s coming in the next releases 
of the Windows API Code Pack for DirectX technologies. 
 
The subfolder “WindowsAPICodepack/DirectX” contains the required sources in the form of a Visual 
Studio 2008 solution. To build the solution, you’ll also need either "Microsoft Windows SDK for 
Windows 7 – RC release" or "DirectX SDK - March 2009 release". Each of those SDKs contains the 
required headers and binaries necessary to build the wrappers. Links to each are provided at the end 
of this document.
 
The DirectX Visual C++ “project” contains various configurations to build using each of the SDKs 
mentioned; both for x86 and x64. Make sure to select the configuration AND platform that meet your 
build needs. To build for DirectX SDK make sure to select “(DirectX SDK)” configurations. All other 
configurations target Windows SDK.

On Vista, you won’t be able to run any samples built using the library, except when you install and 
build using DirectX SDK. The DirectX SDK provides beta versions of D3D11 and DXGI libraries that 
otherwise ship on Window 7 only. 

In addition, DirectX SDK provides additional utilities that aid in the development of DirectX applications 
that are not provided with Windows SDK. For information on those utilities, please refer to DirectX SDK 
documentation.

64-bit Considerations:
If you build a managed (C# or VB.Net) app referencing this library and run this app on a 64-bit machine, 
then you have one of two options:
- Build the library as a 64-bit one, and let the .Net app target platform be "Any CPU" (the default), or
- Build using an x86 configuration of the library, but make sure your C# or VB.Net app targets "x86" as 
well. 
 
To build a 64-bit version of the library, you'll also need to have a compatible version of Visual Studio 
2008; i.e. you must have selected the support for 64-bit option when Visual Studio 2008 was installed. 
Please refer to the links at the end of this readme for additional information on how to install 64-bit 
components.

Finally, the current release of the DirectX managed APIs is still in preview stage, and there are no 
demos or samples provided at this time. Additional sources demonstrating the use of the library, 
together with additional managed APIs will be part of future releases.
 
Links:
Microsoft Windows SDK for Windows 7 – RC release, web Setup: 
http://www.microsoft.com/downloads/details.aspx?FamilyID=f75f2ca8-c1e4-4801-9281-2f5f28f12dbd

Microsoft Windows SDK for Windows 7 – RC release, ISO Setup: 
http://www.microsoft.com/downloads/details.aspx?FamilyID=6db1f17f-5f1e-4e54-a331-c32285cdde0c

DirectX Software Development Kit (Requires Validation): 
http://www.microsoft.com/downloads/details.aspx?FamilyID=24a541d6-0486-4453-8641-1eee9e21b282
 
How to install Visual studio 64-bit components: http://msdn.microsoft.com/en-us/library/ms246588.aspx

