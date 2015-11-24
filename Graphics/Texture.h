#pragma once

#include "..\Definitions.h"
#include "..\Stream\NFile.h"
#include <GL\glew.h>

namespace NobelLib
{
	namespace Graphics
	{
		class Texture
		{
		private:
			GLuint res_iImage;		// Resource 
			BYTE* res_yTexture;		// Actual RGB data
			UINT res_iWidth;		// Width of texture
			UINT res_iHeight;		// Height of texture
			UINT res_iSize;			// Width*height*3	
			static const int res_iBMPheader;
		public:
			Texture(IO::NFileName bmpTexture);
			BYTE* getTexture();
			
			operator BYTE*();
		};
	}
}
