/*
* File:   RTSPDestination.h
* Author: Burak Hamuryen
*
* Created on 06.09.2018
*/

#ifndef RTSP_DESTINATION_LIBRARY_H
#define RTSP_DESTINATION_LIBRARY_H

#include <string>

namespace Proxy
{
	class __declspec(dllexport) RTSPDestination
	{
	public:
		RTSPDestination() {};
		RTSPDestination(const RTSPDestination &src)
		{
			m_Port = src.m_Port;
			m_StreamName = src.m_StreamName;
			m_Username = src.m_Username;
			m_Password = src.m_Password;
		};

		unsigned short m_Port;
		std::string m_StreamName;
		std::string m_Username;
		std::string m_Password;
	};
};

#endif // !RTSP_DESTINATION_LIBRARY_H