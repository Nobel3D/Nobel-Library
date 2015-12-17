#include "Matrix4.h"
#include "..\Management\Error.h"

using namespace NobelLib::Graphics;
using namespace NobelLib;

#define VECX 0
#define VECY 1
#define VECZ 2
#define VECW 3

Matrix4::Matrix4(NFloat x, NFloat y, NFloat z, NFloat w)
{
	mtx_fObject = new Matrix<NFloat>(MATRIXTYPE, MATRIXTYPE);
	mtx_fObject->getElement(0, 0) = 1;
	mtx_fObject->getElement(1, 1) = 1;
	mtx_fObject->getElement(2, 2) = 1;
	mtx_fObject->getElement(VECX, 3) = x;
	mtx_fObject->getElement(VECY, 3) = y;
	mtx_fObject->getElement(VECZ, 3) = z;
	mtx_fObject->getElement(VECW, 3) = w;
}

NFloat NobelLib::Graphics::Matrix4::getObject(int row, int column)
{
	return mtx_fObject->getElement(row,column);
}

Vector4 NobelLib::Graphics::Matrix4::Translate(Vector4 base)
{
	return (*this) * base;
}

Vector4 & NobelLib::Graphics::Matrix4::operator*(Vector4 addMe)
{
	Vector4 ret(0, 0, 0, 0);
	for (int i = 0; i < MATRIXTYPE; i++)
	{
		ret[i] = (getObject(i, VECX) * addMe.getX()) +
			   	 (getObject(i, VECY) * addMe.getY()) +
				 (getObject(i, VECZ) * addMe.getZ()) +
				 (getObject(i, VECW) * addMe.getW());
	}
	return ret;
}
