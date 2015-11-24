#include "Network.h"
#include "..\Management\Error.h"

using namespace NobelLib;
using namespace NobelLib::Net;
using namespace NobelLib::Management;

bool Network::net_bAbort = false;
WSAData* Network::net_wWSAData;
bool Network::net_bInit;
SOCKET* Network::net_wSocket;

Network::Network()
{
	net_wWSAData = new WSADATA;
	net_wSocket = NULL;
	net_wTarget = new sockaddr_in;
	net_cAddress = NULL;
	int nCode;
	if ((nCode = WSAStartup(MAKEWORD(2, 2), net_wWSAData)) != 0)
	{
		Error("NobelLib::Net::Network::startUp(). Error on WSAStartup with return " + NString::fromInt(nCode) + " Probably Failed to find Winsock 2.2 or better.", 40, false);
	}
}

int Network::net_Abort(int returnConnection)
{
	if (!net_bAbort)
	{
		net_bAbort = true;
	}
	return returnConnection;
}

void Network::net_Port(int port)
{
	net_iPort = port;
}

int Network::Connect(IP target, int port)
{
	net_cAddress = &target;
	net_iPort = port;
	hostent* phe = gethostbyname(target.getIP());
	if (phe == NULL) {
		Error("NobelLib::Net::Network::Connect(" + target.getIP()+ "," + NString::fromInt(port) + ")Failed to get host, operation aborted", 44,false);
		net_Abort(44);
	}

	net_wTarget->sin_family = AF_INET;
	net_wTarget->sin_addr.s_addr = *(ULONG*)phe->h_addr_list[0];
	net_wTarget->sin_port = htons(net_iPort);

	net_wSocket = new SOCKET(socket(AF_INET, SOCK_STREAM, IPPROTO_TCP));
	if (connect(*net_wSocket, (sockaddr*)net_wTarget, sizeof(sockaddr_in)) == 0) {
		return 1;
	}
	Error("Failed to Connect, Check your connection and retry and be sure your IP destination is correct", 45, false);
	net_Abort(45);
	return 0;
}
int Network::Close()
{
	return closesocket(*net_wSocket);
}
int Network::Write()
{
	return send(*net_wSocket, (char*)stmBuffer, stmSize, 0);
}

LLINT Network::Read(void* vpGet, LLINT length, LLINT count)
{
	int res = recv(*net_wSocket, (char*)vpGet, length, 0);
	net_bEOF = (res <= 0) || ((ULONG)res < res);
	return res;
}
