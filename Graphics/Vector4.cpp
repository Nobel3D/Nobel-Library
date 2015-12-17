#include "Vector4.h"
#include "..\Management\Error.h"

using namespace NobelLib::Graphics;
using namespace NobelLib;
using namespace NobelLib::Management;

#define VECX 0
#define VECY 1
#define VECZ 2
#define VECW 3
Vector4::Vector4(NFloat x, NFloat y, NFloat z, NFloat w)
{
	vec_fObject = new Array<NFloat>(VECTORTYPE);
	(*vec_fObject)[VECX] = x;
	(*vec_fObject)[VECY] = y;
	(*vec_fObject)[VECZ] = z;
	(*vec_fObject)[VECW] = w;
	
}

NFloat& Vector4::getX()
{
	return (*vec_fObject)[VECX];
}

NFloat& Vector4::getY()
{
	return (*vec_fObject)[VECY];
}
NFloat& Vector4::getZ()
{
	return (*vec_fObject)[VECZ];
}
NFloat& Vector4::getW()
{
	return (*vec_fObject)[VECW];
}

NFloat& Vector4::operator[](const char addMe)
{
	switch (addMe)
	{
	case 'x':
		return getX();
	case 'y':
		return getY();
	case 'z':
		return getZ();
	case 'w':
		return getW();
	default:
		Error("NobelLib::Graphics::Vector4::operator[] (" + NString(&addMe) + ") Wrong parameter in current funcion ", 25, false);
	}
}

NFloat& NobelLib::Graphics::Vector4::operator[](NString addMe)
{
	if (addMe.getLength() > 1)
	{
		Error("NobelLib::Graphics::Vector4::operator[] (" + addMe + ") Wrong parameter in current funcion ", 25, false);
	}
	else
	{
		return (*this)[addMe[0]];
	}
}
NFloat& NobelLib::Graphics::Vector4::operator[](int addMe)
{
	if (addMe > 3)
	{
		Error("NobelLib::Graphics::Vector4::operator[] (" + NString::fromInt(addMe) + ") Wrong parameter in current funcion ", 25, false);
	}
	else
	{
		return (*vec_fObject)[addMe];
	}
}
