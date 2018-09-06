/*
* File:   RTSPProxy.h
* Author: Burak Hamuryen
*
* Created on 06.09.2018
*/

#ifndef RTSP_PROXY_LIBRARY_H
#define RTSP_PROXY_LIBRARY_H

#include <string>

#include "RTSPSource.h"
#include "RTSPDestination.h"
#include "RTSPStatus.h"

namespace Proxy
{
	class RTSPProxyImp;

	class RTSPProxy
	{
	public:
		RTSPProxy(const RTSPSource& source, const RTSPDestination& destination);
		~RTSPProxy();

		RTSPStatus Run();
		bool Stop();
		RTSPStatus RTSPUrl();

	private:
		RTSPProxyImp* m_Imp;
	};
};

#endif // !RTSP_PROXY_LIBRARY_H