#include "InternetProtocol.h"
#include "..\Management\Error.h"
#include "Network.h"

using namespace NobelLib;
using namespace NobelLib::Net;
using namespace NobelLib::Management;

IP::IP(NString stringIp)
{
	if (stringIp.Find("."))
	{
		Array<NString> splitAddress;
		splitAddress = stringIp.Split('.', splitAddress);
		if (splitAddress.SizeArray() == 4)
		{
			net_sIP = stringIp;
		}
		else
		{
			Error(NString("NOBELLIB::MANAGEMENT::IP::IP() Error to construction. NString(" + stringIp + ") is not a IP Address!"), 51, false);
			Network::net_bAbort = true;
		}
	}
	else
	{
		Error("NOBELLIB::MANAGEMENT::IP::IP() Error to construction. NString(" + stringIp + ") is not a IP Address!", 51, false);
		Network::net_bAbort = true;
	}
}
IP::IP(char* class4, char* class3, char* class2, char* class1)
{
	net_sIP = NString(class4) + "." + class3 + "." + class2 + "." + class1;
	if (!chk_bIP())
		Error("NOBELLIB::MANAGEMENT::IP::IP() Error to construction. NString(" + net_sIP + ") Failed checkin!", 51, false);
}
IP::IP(int class4, int class3, int class2, int class1) 
{
	net_sIP = NString::fromInt(class4) + "." + NString::fromInt(class3) + "." + NString::fromInt(class2) + "." + NString::fromInt(class1);
}

NString IP::getIP()
{
	if (!Network::net_bAbort)
		return net_sIP;
	else
	{
		Error("NOBELLIB::MANAGEMENT::IP::IP() Impossible get this IP Address!", 52, false);
		return NString::Zero();
	}
}

IP IP::localhost()
{
	return IP("127.0.0.1");
}

bool IP::chk_bIP()
{
	for (int i = 0;i < net_sIP.getLength(); i++)
	{
		if (net_sIP[i] != '0' && net_sIP[i] != '1' &&
			net_sIP[i] != '2' && net_sIP[i] != '3' &&
			net_sIP[i] != '4' && net_sIP[i] != '5' &&
			net_sIP[i] != '6' && net_sIP[i] != '7' &&
			net_sIP[i] != '8' && net_sIP[i] != '9' && 
			net_sIP[i] != '.')
				return false;
	}
	return true;
}