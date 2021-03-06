#pragma once

#include "..\Base\Array.h"
#include "..\Graphics\NFloat.h"
using namespace NobelLib::Graphics;

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