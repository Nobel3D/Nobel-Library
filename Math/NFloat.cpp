#include "NFloat.h"
#include <math.h>

using namespace NobelLib::Math;

NFloat::NFloat()
{
	n = 0.00000f;
}

NFloat::NFloat(float _n)
{
	n = _n;
}

NFloat::NFloat(int _n)
{
	n = float(_n);
}

NFloat::NFloat(double _n)
{
	n = float(_n);
}
float NFloat::getNative()
{
	return n;
}
float NFloat::getRound(int numberfloat)
{
	if (numberfloat > 0)
	{
		int nPow = pow(10, numberfloat);
		return static_cast<double>(static_cast<int>(n*nPow)) / nPow;
	}
	//FIXME: ADD ERROR WARNING
}
float NFloat::getDecimal()
{
	return n - (int)n;
}