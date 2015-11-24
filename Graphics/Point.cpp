#include "Point.h"

using namespace NobelLib::Graphics;

Point::Point()
{
	x = 0.0f;
	y = 0.0f;
}

Point::Point(NFloat _x, NFloat _y)
{
	x = _x;
	y = _y;
}

Point3::Point3()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

Point3::Point3(NFloat _x, NFloat _y, NFloat _z)
{
	x = _x;
	y = _y;
	z = _z;
}