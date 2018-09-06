/*
* File:   RTSPSource.h
* Author: Burak Hamuryen
*
* Created on 06.09.2018
*/

#ifndef RTSP_SOURCE_LIBRARY_H
#define RTSP_SOURCE_LIBRARY_H

#include <string>

namespace Proxy
{
	class RTSPSource
	{
	public:
		RTSPSource() {};
		RTSPSource(const RTSPSource &src)
		{
			m_Url = src.m_Url;
			m_SourceUsername = src.m_SourceUsername;
			m_SourcePassword = src.m_SourcePassword;
		};

		std::string m_Url;
		std::string m_SourceUsername;
		std::string m_SourcePassword;
	};
};

#endif // !RTSP_SOURCE_LIBRARY_H