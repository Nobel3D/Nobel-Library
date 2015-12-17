#pragma once
#include "..\OpenGL.h"
#include "..\NFloat.h"
#include "..\Point.h"

namespace NobelLib
{
	namespace Graphics
	{
		namespace Geometric
		{
			class Lines : public GLObject
			{
			private:
				Point3 geo_pLine1, geo_pLine2;
			public:
				Lines();
				Lines(Point3 begin, Point3 end);
				~Lines();
				void Load(void* null = nullptr);
				void Destroy();
				void Draw();

			};
		}
	}
}