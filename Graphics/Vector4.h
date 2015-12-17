#pragma once

#include "..\Base\Array.h"
#include "NFloat.h"

#define VECTORTYPE 4

namespace NobelLib
{
	namespace Graphics
	{
		class Vector4
		{
		private:
			Array<NFloat>* vec_fObject;
		public:
			Vector4(NFloat x, NFloat y, NFloat z, NFloat w);

			NFloat& getX();
			NFloat& getY();
			NFloat& getZ();
			NFloat& getW();

			NFloat& operator[](const char addMe);
			NFloat& operator[](NString addMe);
			NFloat& operator[](int addMe);
		};
	}
}