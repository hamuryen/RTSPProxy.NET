/*
* File:   RTSPDestinationNET.h
* Author: Burak Hamuryen
*
* Created on 07.09.2018
*/

#ifndef RTSP_DESTINATION_NET_LIBRARY_H
#define RTSP_DESTINATION_NET_LIBRARY_H

#include "RTSPModelNET.h"
#include "RTSPDestination.h"

using namespace System;

namespace Proxy
{
	public ref class RTSPDestinationNet : public RTSPModelNet
	{
	public:
		RTSPDestinationNet() {};
		RTSPDestinationNet(RTSPDestinationNet% src)
		{
			m_Port = src.m_Port;
			m_StreamName = src.m_StreamName;
			m_Username = src.m_Username;
			m_Password = src.m_Password;
		};
		virtual ~RTSPDestinationNet() {};
		!RTSPDestinationNet() {};

		RTSPDestination ToNative()
		{
			RTSPDestination native;
			native.m_Port = m_Port;
			native.m_StreamName = ToString(m_StreamName);
			native.m_Username = ToString(m_Username);
			native.m_Password = ToString(m_Password);
			return native;
		};

		static RTSPDestinationNet^ FromNative(RTSPDestination native)
		{
			RTSPDestinationNet^ res = gcnew RTSPDestinationNet;
			res->m_Port = native.m_Port;
			res->m_StreamName = gcnew String(native.m_StreamName.c_str());
			res->m_Username = gcnew String(native.m_Username.c_str());
			res->m_Password = gcnew String(native.m_Password.c_str());
			return res;
		};

		unsigned short m_Port;
		String^ m_StreamName;
		String^ m_Username;
		String^ m_Password;
	};
};

#endif // !RTSP_DESTINATION_NET_LIBRARY_H