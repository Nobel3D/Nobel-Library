#pragma once

namespace NobelLib
{
	namespace Vectors
	{
/*Class for Create a Vector1*/
class Vector
{
private:

	float vc1_Modulus;
	float vc1_Position;
	int vc1_Angle;

public:
	Vector(float Modulus, float Position, int Angle);
	Vector(const Vector &vc1);
	~Vector();

	//getter method

	float getModulus();
	float getPosition();
	int getAngle();
	int getCartesianAngle();
	float getFloatAngle();


	//setter method

	void setModulus(float Modulus);

	//main method

	//operator

	bool operator==(Vector* vc1)
	{
		if(vc1->getModulus()==this->getModulus())
			return true;
		else
			return false;
	}

};
	}
}