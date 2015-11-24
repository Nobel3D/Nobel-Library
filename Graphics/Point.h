#pragma once
#include "NFloat.h"

using namespace NobelLib;
namespace NobelLib
{
	namespace Graphics
	{
		class Point
		{
		public:
			NFloat x;
			NFloat y;

			Point();
			Point(NFloat _x, NFloat _y);
		};
		class Point3
		{
		public:
			NFloat x;
			NFloat y;
			NFloat z;

			Point3();
			Point3(NFloat _x, NFloat _y, NFloat _z);
		};
	}
}