#pragma once

#include "NFloat.h"

#define	RED		 NColor(1.0f, 0.0f, 0.0f)
#define	GREEN	 NColor(0.0f, 1.0f, 0.0f)
#define	BLUE   	 NColor(0.0f, 0.0f, 1.0f)

namespace NobelLib 
{
	namespace Graphics
	{
		class NColor
		{
		public:
			NFloat Red;
			NFloat Green;
			NFloat Blue;
			NColor(NFloat _red, NFloat _green, NFloat _blue);
			NColor();
		};
	}
}