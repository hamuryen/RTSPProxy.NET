/*
* File:   RTSPProxyNET.cpp
* Author: Burak Hamuryen
*
* Created on 07.09.2018
*/

#include "RTSPProxyNET.h"

Proxy::RTSPProxyNet::RTSPProxyNet(RTSPSourceNet^ source, RTSPDestinationNet^ destination)
{
	RTSPSource s = source->ToNative();
	RTSPDestination d = destination->ToNative();
	m_Proxy = new RTSPProxy(s, d);
}

Proxy::RTSPProxyNet::~RTSPProxyNet()
{
	Destroy();
}

Proxy::RTSPProxyNet::!RTSPProxyNet()
{
	Destroy();
}

Proxy::RTSPStatusNet^ Proxy::RTSPProxyNet::Run()
{
	return RTSPStatusNet::FromNative(m_Proxy->Run());
}

bool Proxy::RTSPProxyNet::Stop()
{
	return m_Proxy->Stop();
}

Proxy::RTSPStatusNet^ Proxy::RTSPProxyNet::RTSPUrl()
{
	return RTSPStatusNet::FromNative(m_Proxy->RTSPUrl());
}

void Proxy::RTSPProxyNet::Destroy()
{
	if (m_Proxy != nullptr)
	{
		m_Proxy->Stop();
		delete m_Proxy;
		m_Proxy = nullptr;
	}
}