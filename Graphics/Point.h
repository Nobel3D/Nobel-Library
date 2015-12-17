#pragma once
#include "NFloat.h"
#include <glm.hpp>

using namespace glm;
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

			bool operator==(Point &addMe);
		};
		class Point3
		{
		public:
			NFloat x;
			NFloat y;
			NFloat z;

			Point3();
			Point3(Point3 &copy);
			Point3(NFloat _x, NFloat _y, NFloat _z);

			Point3 operator=(Point3 &addMe);
			bool operator==(Point3 &addMe);

			vec3 toVec3();
		};
	}
}