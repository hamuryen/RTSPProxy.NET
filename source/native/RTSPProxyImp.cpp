/*
* File:   RTSPProxyImp.cpp
* Author: Burak Hamuryen
*
* Created on 06.09.2018
*/

#include "RTSPProxyImp.h"

Proxy::RTSPProxyImp::RTSPProxyImp(const RTSPSource& source, const RTSPDestination& destination) :
	m_LoopThread(nullptr),
	m_Auth(nullptr),
	m_RTSPServer(nullptr),
	m_Scheduler(nullptr),
	m_Environment(nullptr),
	m_Session(nullptr),
	m_LoopWatchVariable(1)
{
	m_Source = source;
	m_Destination = destination;
}

Proxy::RTSPProxyImp::~RTSPProxyImp()
{
	Stop();
}

Proxy::RTSPStatus Proxy::RTSPProxyImp::Run()
{
	RTSPStatus status;
	if (m_LoopWatchVariable == 0)
	{
		status.m_Message = "Already running!";
		return status;
	}

	m_Scheduler = BasicTaskScheduler::createNew();
	m_Environment = BasicUsageEnvironment::createNew(*m_Scheduler);

	if (!m_Destination.m_Username.empty() && !m_Destination.m_Password.empty())
	{
		m_Auth = new UserAuthenticationDatabase;
		m_Auth->addUserRecord(m_Destination.m_Username.c_str(), m_Destination.m_Password.c_str());
	}

	m_RTSPServer = RTSPServer::createNew(*m_Environment, m_Destination.m_Port, m_Auth);
	if (m_RTSPServer == nullptr)
	{
		status.m_Message = "Failed to create RTSP server: " + std::string(m_Environment->getResultMsg());
		Stop();
		return status;
	}

	m_Session = ProxyServerMediaSession::createNew(*m_Environment,
		m_RTSPServer,
		m_Source.m_Url.c_str(),
		m_Destination.m_StreamName.c_str(),
		(m_Source.m_SourceUsername.empty() == true ? NULL : m_Source.m_SourceUsername.c_str()),
		(m_Source.m_SourcePassword.empty() == true ? NULL : m_Source.m_SourcePassword.c_str()));

	m_RTSPServer->addServerMediaSession(m_Session);

	char* url = m_RTSPServer->rtspURL(m_Session);
	status.m_Url = std::string(url);
	status.m_IsSuccces = true;
	delete[] url;

	m_LoopThread = new std::thread(&Proxy::RTSPProxyImp::DoLoop, this);

	return status;
}

bool Proxy::RTSPProxyImp::Stop()
{
	if (m_Environment != nullptr && m_LoopWatchVariable == 0 && m_LoopThread != nullptr)
	{
		m_LoopWatchVariable = 1;
		m_LoopThread->join();
	}
	if (m_RTSPServer != nullptr)
	{
		Medium::close(m_RTSPServer);
		m_RTSPServer = nullptr;
	}
	if (m_Auth != nullptr)
	{
		delete m_Auth;
		m_Auth = nullptr;
	}
	if (m_Environment != nullptr)
	{
		m_Environment->reclaim();
		m_Environment = nullptr;
	}
	if (m_Scheduler != nullptr)
	{
		delete m_Scheduler;
		m_Environment = nullptr;
	}
	if (m_LoopThread != nullptr)
	{
		delete m_LoopThread;
		m_LoopThread = nullptr;
	}

	return true;
}

Proxy::RTSPStatus Proxy::RTSPProxyImp::RTSPUrl()
{
	RTSPStatus status;
	if (m_LoopWatchVariable == 0 && m_RTSPServer != nullptr && m_Session != nullptr)
	{
		char* url = m_RTSPServer->rtspURL(m_Session);
		status.m_Url = std::string(url);
		status.m_IsSuccces = true;
		delete[] url;
	}
	else
		status.m_Message = "Not running!";

	return status;
}

void Proxy::RTSPProxyImp::DoLoop()
{
	m_LoopWatchVariable = 0;
	m_Environment->taskScheduler().doEventLoop(&m_LoopWatchVariable);
}