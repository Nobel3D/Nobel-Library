#include "Vector.h"

using namespace NobelLib::Vectors;

Vector::Vector(float Modulus, float Position, int Angle)
{
	if(Modulus>0.0&&Angle>0&&Angle<361)
	{
		vc1_Modulus=Modulus;
		vc1_Position=Position;
		vc1_Angle=Angle;
	}
}

Vector::Vector(const Vector &vc1)
{
	this->vc1_Angle=vc1.vc1_Angle;
	this->vc1_Modulus=vc1.vc1_Modulus;
	this->vc1_Position=vc1.vc1_Position;
}
Vector::~Vector()
{
	this->vc1_Angle=0;
	this->vc1_Modulus=0;
	this->vc1_Position=0;
}


int Vector::getCartesianAngle()
{
	//NormalAngle : TotNormal = CartesianAngle : TotCartesian (100 for space)
	return (vc1_Angle*400)/360;
}

float Vector::getFloatAngle()
{
	//Angle : TotCartesian = floatAngle : Totfloat
	return (getCartesianAngle()*4)/400;
}

float Vector::getModulus(){ return vc1_Modulus; }
float Vector::getPosition(){ return vc1_Position; }
int Vector::getAngle(){ return vc1_Angle; }

void Vector::setModulus(float Modulus) { vc1_Modulus=Modulus; }