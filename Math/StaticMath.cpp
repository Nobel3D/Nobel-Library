#pragma once
#include "StaticMath.h"
#include <cmath>

using namespace NobelLib::Math;

StaticMath::StaticMath(void)
{
}


double StaticMath::Pythagoras(double First, double Second)
{
	return sqrt(pow(First,2)+pow(Second,2));
}

LLINT StaticMath::Factorial(LLINT Number)
{
		LLINT nfatt = 1;

		if (Number == 0)
			return 1;
		else
		{
			for (int i = 1; i <= Number;i++)
				nfatt *= i;
		}
		return nfatt;
}