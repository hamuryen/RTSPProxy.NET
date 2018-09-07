/*
* File:   Program.cs
* Author: Burak Hamuryen
*
* Created on 07.09.2018
*/

using Proxy;
using System;

namespace RTSPProxy.NET.Sample
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Running!\n\n");

            RTSPSourceNet source = new RTSPSourceNet();
            source.m_Url = "rtsp://184.72.239.149/vod/mp4:BigBuckBunny_175k.mov";
            source.m_SourceUsername = "admin";
            source.m_SourcePassword = "admin";

            RTSPDestinationNet destination = new RTSPDestinationNet();
            destination.m_Port = 554;
            destination.m_StreamName = "video";
            destination.m_Username = "admin";
            destination.m_Password = "admin";

            RTSPProxyNet proxy = new RTSPProxyNet(source, destination);
            RTSPStatusNet status = proxy.Run();
            Console.WriteLine(status.m_Url);

            Console.ReadLine();
        }
    }
}