/*
* File:   RTSPProxyNET.h
* Author: Burak Hamuryen
*
* Created on 07.09.2018
*/

#ifndef RTSP_PROXY_NET_LIBRARY_H
#define RTSP_PROXY_NET_LIBRARY_H

#include "RTSPProxy.h"

#include "RTSPSourceNET.h"
#include "RTSPDestinationNET.h"
#include "RTSPStatusNET.h"

using namespace System;

namespace Proxy
{
	public ref class RTSPProxyNet
	{
	public:
		RTSPProxyNet(RTSPSourceNet^ source, RTSPDestinationNet^ destination);
		~RTSPProxyNet();
		!RTSPProxyNet();

		RTSPStatusNet^ Run();
		bool Stop();
		RTSPStatusNet^ RTSPUrl();

	private:
		void Destroy();

	private:
		RTSPProxy* m_Proxy;
	};
};

#endif // !RTSP_PROXY_NET_LIBRARY_H