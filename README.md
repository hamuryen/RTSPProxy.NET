# RTSPProxy.NET
A .NET RTSP Proxy framework with live555.

## Getting Started
These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See deployment for notes on how to deploy the project on a live system.

### Prerequisites
```
CMake version 3.0 or later
Visual Studio
```

### Build

```
Run CMake in source folder
Type to build binary location as ./source/build
Chose your machian target archietecture
Generate Visual Studio solution file
Build the generated solution, than you will have two dll file("RTSPProxy.dll" and "RTSPProxy.NET.dll").
  - "./source/build/native/source/{Debug or Release}/RTSPProxy.dll" is the native binary
  - "./source/build/wrapper/{Debug or Release}/RTSPProxy.NET.dll" is the wrapper(CLI/CLR) for .NET
You can test the native output with "RTSPProxySample" project in same solution
Also you can test the wrapper with "./sample/RTSPProxy.NET.Sample/RTSPProxy.NET.Sample"
```

If you do not want to build native code, you can find the dlls that are built(Visual Studio 2015) in different configurations in the bin folder

```
Add RTSPProxy.NET.dll as a reference to your .NET project
Copy RTSPProxy.dll to the folder where your .NET project output(exe) is located
```

### Usage

An input for the proxy should be given, the input can be created as follows
```C#
            RTSPSourceNet source = new RTSPSourceNet();
            source.m_Url = "rtsp://ip:port/uri";
            source.m_SourceUsername = "admin";
            source.m_SourcePassword = "admin";
```

An output configuration must be specified, the output can be specified as follows
```C#
            RTSPDestinationNet destination = new RTSPDestinationNet();
            destination.m_Port = 554;
            destination.m_StreamName = "video";
            destination.m_Username = "admin";
            destination.m_Password = "admin";
```

The proxy is created as follows
```C#
            RTSPProxyNet proxy = new RTSPProxyNet(source, destination);
            RTSPStatusNet status = proxy.Run();
```

With RTSPStatusNet, the status of the proxy can be checked.
