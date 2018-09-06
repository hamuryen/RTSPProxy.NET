/*
* File:   RTSPProxy.cpp
* Author: Burak Hamuryen
*
* Created on 06.09.2018
*/

#include "RTSPProxy.h"
#include "RTSPProxyImp.h"

Proxy::RTSPProxy::RTSPProxy(const RTSPSource& source, const RTSPDestination& destination)
{
	m_Imp = new RTSPProxyImp(source, destination);
}

Proxy::RTSPProxy::~RTSPProxy()
{
	delete m_Imp;
}

Proxy::RTSPStatus Proxy::RTSPProxy::Run()
{
	return m_Imp->Run();
}

bool Proxy::RTSPProxy::Stop()
{
	return m_Imp->Stop();
}

Proxy::RTSPStatus Proxy::RTSPProxy::RTSPUrl()
{
	return m_Imp->RTSPUrl();;
}
