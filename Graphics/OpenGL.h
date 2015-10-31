#pragma once

#include <GL\glew.h>
#include <windows.h>

namespace NobelLib
{
	namespace Graphics
	{
		class GLClass
		{
		protected:
			static HDC hDC;
			HGLRC		hRC;
			DEVMODE		nativeMode;
			PIXELFORMATDESCRIPTOR pfd;
			unsigned int PixelFormat;

			int gl_iBit;
		public:
			static void DrawTriangles();
			void destroyGL();
		};
	}
}