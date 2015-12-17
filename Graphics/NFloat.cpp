#include "NFloat.h"
#include "..\Management\Error.h"
#include <math.h>

using namespace NobelLib;
using namespace NobelLib::Graphics;
using namespace NobelLib::Management;

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
NobelLib::Graphics::NFloat::NFloat(const NFloat & copy)
{
	this->n = copy.n;
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
	else
	{
		Error("NobelLib::Math::NFloat::getRound(" + NString::fromInt(numberfloat) + "). number of float cannot be negative!", 36, false);
	}
}
float NFloat::getDecimal()
{
	return n - (int)n;
}

NString NFloat::toString()
{
	NString str = NString::fromDouble(this->n);
	if (str[str.getLength()-1] == '.')
		str.Replace(".", "");

	return str;
}

NFloat::operator GLfloat()
{
	return getNative();
}

void NFloat::operator*=(NFloat addMe)
{
	this->n = this->getNative() * addMe.getNative();
}
void NFloat::operator*=(float addMe)
{
	this->n = this->getNative() * addMe;
}
void NFloat::operator/=(NFloat addMe)
{
	this->n = this->getNative() / addMe.getNative();
}
void NFloat::operator/=(float addMe)
{
	this->n = this->getNative() / addMe;
}
void NFloat::operator+=(NFloat addMe)
{
	this->n = this->getNative() + addMe.getNative();
}
void NFloat::operator+=(float addMe)
{
	this->n = this->getNative() + addMe;
}
void NFloat::operator-=(NFloat addMe)
{
	this->n = this->getNative() - addMe.getNative();
}
void NFloat::operator-=(float addMe)
{
	this->n = this->getNative() - addMe;
}
void NFloat::operator=(NFloat addMe)
{
	this->n = addMe.getNative();
}
void NFloat::operator=(float addMe)
{
	this->n = addMe;
}
NFloat NFloat::operator+(NFloat addMe)
{
	return this->getNative() + addMe.getNative();
}
NFloat NFloat::operator+(float addMe)
{
	return this->getNative() + addMe;
}
NFloat NFloat::operator-(NFloat addMe)
{
	return this->getNative() - addMe.getNative();
}
NFloat NFloat::operator-(float addMe)
{
	return this->getNative() - addMe;
}
NFloat NFloat::operator*(NFloat addMe)
{
	return this->getNative() * addMe.getNative();
}
NFloat NFloat::operator*(float addMe)
{
	return this->getNative() * addMe;
}
NFloat NFloat::operator/(NFloat addMe)
{
	return this->getNative() / addMe.getNative();
}
NFloat NFloat::operator/(float addMe)
{
	return this->getNative() / addMe;
}

bool NFloat::operator<(NFloat addMe) 
{
	return this->getNative() < addMe.getNative();
}
bool NFloat::operator<(float addMe)
{
	return this->getNative() < addMe;
}
bool NFloat::operator>(NFloat addMe)
{
	return this->getNative() > addMe.getNative();
}
bool NFloat::operator>(float addMe)
{
	return this->getNative() < addMe;
}
bool NFloat::operator<=(NFloat addMe)
{
	return this->getNative() <= addMe.getNative();
}
bool NFloat::operator<=(float addMe)
{
	return this->getNative() <= addMe;
}
bool NFloat::operator>=(NFloat addMe)
{
	return this->getNative() >= addMe.getNative();
}
bool NFloat::operator>=(float addMe)
{
	return this->getNative() >= addMe;
}
bool NFloat::operator==(NFloat addMe)
{
	return this->getNative() == addMe.getNative();
}
bool NFloat::operator==(float addMe)
{
	return this->getNative() == addMe;
}