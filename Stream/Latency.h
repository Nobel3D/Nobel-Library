#pragma once

#include "..\Base\Array.h"
#include "..\Math\NFloat.h"
using namespace NobelLib::Math;

namespace NobelLib
{
	class Latency
	{
		public:
		Array<NFloat> net_aLatency;
		Latency(Array<NFloat>* tried);

		NFloat Average();
		NFloat Maximum();
		NFloat Minimum();
	};
}