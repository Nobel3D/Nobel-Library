#pragma once

namespace NobelLib
{
	namespace Math
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

			float getNative();
			float getRound(int numberfloat);
			float getDecimal();
		};
	}
}