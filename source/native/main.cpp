/*
* File:   main.cpp
* Author: Burak Hamuryen
*
* Created on 06.09.2018
*/

#include <iostream>
#include <thread>
#include <chrono>

#include "RTSPProxy.h"

int main(int argc, char** argv)
{
	Proxy::RTSPSource source;
	source.m_Url = "rtsp://184.72.239.149/vod/mp4:BigBuckBunny_175k.mov";
	source.m_SourceUsername = "admin";
	source.m_SourcePassword = "admin";

	Proxy::RTSPDestination destination;
	destination.m_Port = 554;
	destination.m_StreamName = "video";
	destination.m_Username = "admin";
	destination.m_Password = "admin";

	Proxy::RTSPProxy proxy(source, destination);
	Proxy::RTSPStatus status = proxy.Run();
	if (status.m_IsSuccces)
		std::cout << "Running on: " << status.m_Url << std::endl;
	else
		std::cerr << "An error occurred\n";

	std::this_thread::sleep_for(std::chrono::seconds(20));
	std::cout << "Check URL: " << proxy.RTSPUrl().m_Url << std::endl;

	std::this_thread::sleep_for(std::chrono::seconds(20));
	std::cout << "Stop: " << proxy.Stop() << std::endl << std::endl;

	return 0;
}