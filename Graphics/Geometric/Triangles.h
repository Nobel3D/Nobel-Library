#pragma once
#include "..\NFloat.h"
#include "..\Point.h"
#include "..\OpenGL.h"

namespace NobelLib
{
	namespace Graphics
	{
		namespace Geometric
		{
			class Triangles : public GLObject
			{
			private:
				Point3* geo_pTriangle1;
				Point3* geo_pTriangle2;
				Point3* geo_pTriangle3;

			public:
				Triangles();
				Triangles(Point3 _1, Point3 _2, Point3 _3);
				~Triangles();

				void Draw();
				void Load(void* null = nullptr);
				void Destroy();
				void Rotate(NFloat _rotation, Axis _ax);
			};

		}
	}
}