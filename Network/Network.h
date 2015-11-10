#pragma once
#include "..\Stream\Stream.h"
#include <WinSock2.h>
#include "InternetProtocol.h"

#pragma comment(lib, "Ws2_32.lib")

namespace NobelLib
{
	namespace Net
	{
		class Network : public IO::Stream
		{
		private:
			static WSAData* net_wWSAData;
			IP* net_cAddress;
			int net_iPort;
			static bool net_bInit;
			static SOCKET* net_wSocket;
			bool net_bEOF;
			sockaddr_in* net_wTarget;
		public:
			Network();
			//state connection
			static bool net_bAbort;
			int net_Abort(int returnConnection);

			int Connect(IP target, int port);
			int Close();
		//	int Connect(IP target, int ttl); Add time to live

			int Write();
			int Read(void* vpGet, UINT length);

			void net_Port(int port);
		};
	}
}