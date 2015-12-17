#pragma once

#include "..\Base\Matrix.h"
#include "Vector4.h"
#include "NFloat.h"

#define MATRIXTYPE 4

namespace NobelLib
{
	namespace Graphics
	{
		class Matrix4
		{
		private:
			Matrix<NFloat>* mtx_fObject;
		public:
			Matrix4(NFloat x, NFloat y, NFloat z, NFloat w);

			NFloat getObject(int row, int column);

			Vector4 Translate(Vector4 base);
			Vector4& operator*(Vector4 addMe);
		};
	}
}