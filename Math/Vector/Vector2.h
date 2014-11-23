#pragma once

namespace NobelLib
{
	namespace Vectors
	{
		class Vector2
		{
		private:
			float vc2_x;
			float vc2_y;
		public:
			Vector2(float x, float y);
			Vector2(const Vector2* vc2);

		};
	}
}