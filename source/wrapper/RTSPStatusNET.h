/*
* File:   RTSPStatusNET.h
* Author: Burak Hamuryen
*
* Created on 07.09.2018
*/

#ifndef RTSP_STATUS_NET_LIBRARY_H
#define RTSP_STATUS_NET_LIBRARY_H

#include "RTSPModelNET.h"
#include "RTSPStatus.h"

using namespace System;

namespace Proxy
{
	public ref class RTSPStatusNet : public RTSPModelNet
	{
	public:
		RTSPStatusNet() { m_IsSuccces = false; }
		RTSPStatusNet(RTSPStatusNet% src)
		{
			m_IsSuccces = src.m_IsSuccces;
			m_Url = src.m_Url;
			m_Message = src.m_Message;
		};
		virtual ~RTSPStatusNet() {};
		!RTSPStatusNet() {};

		RTSPStatus ToNative()
		{
			RTSPStatus native;
			native.m_IsSuccces = m_IsSuccces;
			native.m_Url = ToString(m_Url);
			native.m_Message = ToString(m_Message);
			return native;
		};

		static RTSPStatusNet^ FromNative(RTSPStatus native)
		{
			RTSPStatusNet^ res = gcnew RTSPStatusNet;
			res->m_IsSuccces = native.m_IsSuccces;
			res->m_Url = gcnew String(native.m_Url.c_str());
			res->m_Message = gcnew String(native.m_Message.c_str());
			return res;
		};

		bool m_IsSuccces;
		String^ m_Url;
		String^ m_Message;
	};
};

#endif // !RTSP_STATUS_NET_LIBRARY_H