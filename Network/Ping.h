#pragma once

#include "Network.h"
#include "..\Stream\Latency.h"

using namespace NobelLib;

namespace NobelLib
{
	namespace Net
	{
		class Ping
		{
			Latency* net_pPing;
			Network* net_cNetwork;

			int exec();
			Ping(Network* connection);
		};
	}
}