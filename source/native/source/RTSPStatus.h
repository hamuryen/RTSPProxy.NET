/*
* File:   RTSPStatus.h
* Author: Burak Hamuryen
*
* Created on 06.09.2018
*/

#ifndef RTSP_STATUS_LIBRARY_H
#define RTSP_STATUS_LIBRARY_H

#include <string>

namespace Proxy
{
	class __declspec(dllexport) RTSPStatus
	{
	public:
		RTSPStatus() { m_IsSuccces = false; };
		RTSPStatus(const RTSPStatus &src)
		{
			m_IsSuccces = src.m_IsSuccces;
			m_Url = src.m_Url;
			m_Message = src.m_Message;
		};

		bool m_IsSuccces;
		std::string m_Url;
		std::string m_Message;
	};
};

#endif // !RTSP_STATUS_LIBRARY_H