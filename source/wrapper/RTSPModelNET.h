/*
* File:   RTSPModelNET.h
* Author: Burak Hamuryen
*
* Created on 07.09.2018
*/

#ifndef RTSP_MODEL_NET_LIBRARY_H
#define RTSP_MODEL_NET_LIBRARY_H

#include <string>

using namespace System;
using namespace System::Runtime::InteropServices;

namespace Proxy
{
	public ref class RTSPModelNet
	{
	public:
		RTSPModelNet() {};
		virtual ~RTSPModelNet() {};
		!RTSPModelNet() {};

		std::string ToString(System::String^ source)
		{
			std::string dest = "";
			if (source != nullptr)
			{
				const char* cstr = (const char*)(Marshal::StringToHGlobalAnsi(source)).ToPointer();
				dest = cstr;
				Marshal::FreeHGlobal(System::IntPtr((void*)cstr));
			}
			return dest;
		};
	};
};

#endif // !RTSP_MODEL_NET_LIBRARY_H