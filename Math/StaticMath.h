#pragma once

#include "..\Definitions.h"

#define PI 3.1415926535897932384626433832795
#define PI_OVER_180 0.017453292519943295769236907684886
#define PI_OVER_360 0.0087266462599716478846184538424431

namespace NobelLib
{
	namespace Math
	{
		class StaticMath
		{
		public:
			StaticMath(void);

		static double Pythagoras(double First,double Second);
		static LLINT Factorial(LLINT Number);
		};
	}
}