/*
* File:   RTSPProxyImp.h
* Author: Burak Hamuryen
*
* Created on 06.09.2018
*/

#ifndef RTSP_PROXY_IMP_LIBRARY_H
#define RTSP_PROXY_IMP_LIBRARY_H

#include <string>
#include <thread>

#include "RTSPSource.h"
#include "RTSPDestination.h"
#include "RTSPStatus.h"

#include "liveMedia.hh"
#include "GroupsockHelper.hh"
#include "BasicUsageEnvironment.hh"

namespace Proxy
{
	class RTSPProxyImp
	{
	public:
		RTSPProxyImp(const RTSPSource& source, const RTSPDestination& destination);
		~RTSPProxyImp();

		RTSPStatus Run();
		bool Stop();
		RTSPStatus RTSPUrl();

	private:
		RTSPSource m_Source;
		RTSPDestination m_Destination;

		char volatile m_LoopWatchVariable;
		std::thread* m_LoopThread;

		UserAuthenticationDatabase* m_Auth;
		RTSPServer* m_RTSPServer;
		TaskScheduler* m_Scheduler;
		UsageEnvironment* m_Environment;
		ServerMediaSession* m_Session;
		
	private:
		void DoLoop();
	};
};

#endif // !RTSP_PROXY_IMP_LIBRARY_H