/*
* File:   RTSPSourceNET.h
* Author: Burak Hamuryen
*
* Created on 07.09.2018
*/

#ifndef RTSP_SOURCE_NET_LIBRARY_H
#define RTSP_SOURCE_NET_LIBRARY_H

#include "RTSPModelNET.h"
#include "RTSPSource.h"

using namespace System;

namespace Proxy
{
	public ref class RTSPSourceNet : public RTSPModelNet
	{
	public:
		RTSPSourceNet() {};
		RTSPSourceNet(RTSPSourceNet% src)
		{
			m_Url = src.m_Url;
			m_SourceUsername = src.m_SourceUsername;
			m_SourcePassword = src.m_SourcePassword;
		};
		virtual ~RTSPSourceNet() {};
		!RTSPSourceNet() {};

		RTSPSource ToNative()
		{
			RTSPSource native;
			native.m_Url = ToString(m_Url);
			native.m_SourceUsername = ToString(m_SourceUsername);
			native.m_SourcePassword = ToString(m_SourcePassword);
			return native;
		};

		static RTSPSourceNet^ FromNative(RTSPSource native)
		{
			RTSPSourceNet^ res = gcnew RTSPSourceNet;
			res->m_Url = gcnew String(native.m_Url.c_str());
			res->m_SourceUsername = gcnew String(native.m_SourceUsername.c_str());
			res->m_SourcePassword = gcnew String(native.m_SourcePassword.c_str());
			return res;
		};

		String^ m_Url;
		String^ m_SourceUsername;
		String^ m_SourcePassword;
	};
};

#endif // !RTSP_SOURCE_NET_LIBRARY_H