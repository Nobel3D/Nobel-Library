#include "Latency.h"
#include "..\Definitions.h"

using namespace NobelLib;

Latency::Latency(Array<NFloat>* tried)
{
	net_aLatency = *tried;
}

NFloat Latency::Average()
{
	int num = net_aLatency.SizeArray();
	NFloat ret;
	for (int i = 0; i < num; i++)
	{
		ret += net_aLatency[i].getNative();
	}
	return ret / (float)num;
}

NFloat Latency::Maximum()
{
	int num = net_aLatency.SizeArray();
	NFloat ret = net_aLatency[0];
	for (int i = 0; i < num; i++)
		ret = Max(ret, net_aLatency[i]);
	return ret;
}
NFloat Latency::Minimum()
{
	int num = net_aLatency.SizeArray();
	NFloat ret = net_aLatency[0];
	for (int i = 0; i < num; i++)
		ret = Min(ret,net_aLatency[i]);
	return ret;
}