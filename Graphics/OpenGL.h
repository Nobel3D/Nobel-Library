#pragma once

#include <GL\glew.h>
#include <windows.h>
#include "..\Definitions.h"
#include "NColor.h"
#include "Texture.h"
#include "..\Stream\NFile.h"
#include "..\Management\Error.h"

using namespace NobelLib;

namespace NobelLib
{
	namespace Graphics
	{
		enum Axis
		{
			X = 0,
			Y = 1,
			Z = -1
		};

		class GLObject
		{
		protected:
			static HDC hDC;
			HGLRC		hRC;
			DEVMODE		nativeMode;
			PIXELFORMATDESCRIPTOR PFD;
			unsigned int PixelFormat;
			static int gl_iBit;

			int gl_iWidth;
			int gl_iHeight;
		public:
			GLObject();
			virtual void Draw() = 0;
			virtual void Destroy() = 0;
			void gl_Sleep(LLINT Milliseconds);
			void gl_Clear();
			bool gl_setBit(int bitrate);
			void Color(NColor color);
			GLuint LoadTexture(Texture bmpTexture);
			void Resize(int w, int h);
			void startOrthogonal();
			void endOrthogonal();
			static GLuint LoadShaders(IO::NFileName vertexFile, IO::NFileName fragmentFile);
		};
	}
}