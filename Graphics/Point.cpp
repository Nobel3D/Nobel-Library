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

bool Point::operator==(Point &addMe)
{
	return this->x == addMe.x && this->y == addMe.y;
}


Point3::Point3()
{
}

Point3::Point3(Point3 & copy)
{
	x = copy.x;
	y = copy.y;
	z = copy.z;
}

Point3::Point3(NFloat _x, NFloat _y, NFloat _z)
{
	x = _x;
	y = _y;
	z = _z;
}



vec3 NobelLib::Graphics::Point3::toVec3()
{
	return vec3((float)x,(float)y,(float)z);
}

Point3 Point3::operator=(Point3 &addMe)
{
	this->x = addMe.x;
	this->y = addMe.y;
	this->z = addMe.z;

	return *this;
}
bool Point3::operator==(Point3 &addMe)
{
	return this->x == addMe.x && this->y == addMe.y && this->z == addMe.z;
}