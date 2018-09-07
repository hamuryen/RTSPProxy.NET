/*
* File:   RTSPProxyNET.cpp
* Author: Burak Hamuryen
*
* Created on 07.09.2018
*/

#include "RTSPProxyNET.h"

Proxy::RTSPProxyNET::RTSPProxyNET(RTSPSourceNet% source, RTSPDestinationNet% destination)
{
	RTSPSource s = source.ToNative();
	RTSPDestination d = destination.ToNative();
	m_Proxy = new RTSPProxy(s, d);
}

Proxy::RTSPProxyNET::~RTSPProxyNET()
{
	Destroy();
}

Proxy::RTSPProxyNET::!RTSPProxyNET()
{
	Destroy();
}

Proxy::RTSPStatusNet^ Proxy::RTSPProxyNET::Run()
{
	return RTSPStatusNet::FromNative(m_Proxy->Run());
}

bool Proxy::RTSPProxyNET::Stop()
{
	return m_Proxy->Stop();
}

Proxy::RTSPStatusNet^ Proxy::RTSPProxyNET::RTSPUrl()
{
	return RTSPStatusNet::FromNative(m_Proxy->RTSPUrl());
}

void Proxy::RTSPProxyNET::Destroy()
{
	if (m_Proxy != nullptr)
	{
		m_Proxy->Stop();
		delete m_Proxy;
		m_Proxy = nullptr;
	}
}