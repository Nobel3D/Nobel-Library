#pragma once

#include "..\Base\NString.h"
#include <GL\glew.h>

using namespace NobelLib;

namespace NobelLib
{
	namespace Graphics
	{
		class NFloat
		{
		private:
			float n;
		public:
			NFloat(float _n);
			NFloat(int _n);
			NFloat(double _n);
			NFloat();

			NString toString();
			float getNative();
			float getRound(int numberfloat);
			float getDecimal();

			operator GLfloat();

			void operator*=(NFloat addMe);
			void operator*=(float addMe);
			void operator/=(NFloat addMe);
			void operator/=(float addMe);
			void operator+=(NFloat addMe);
			void operator+=(float addMe);
			void operator-=(NFloat addMe);
			void operator-=(float addMe);
			void operator=(NFloat addMe);
			void operator=(float addMe);
			NFloat operator+(NFloat addMe);
			NFloat operator+(float addMe);
			NFloat operator-(NFloat addMe);
			NFloat operator-(float addMe);
			NFloat operator*(NFloat addMe);
			NFloat operator*(float addMe);
			NFloat operator/(NFloat addMe);
			NFloat operator/(float addMe);

			bool operator<(NFloat addMe);
			bool operator<(float addMe);
			bool operator>(NFloat addMe);
			bool operator>(float addMe);
			bool operator<=(NFloat addMe);
			bool operator<=(float addMe);
			bool operator>=(NFloat addMe);
			bool operator>=(float addMe);
			bool operator==(NFloat addMe);
			bool operator==(float addMe);
		};
	}
}