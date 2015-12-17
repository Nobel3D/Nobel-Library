#pragma once

#include <GL\glew.h>
#include <windows.h>
#include "..\Definitions.h"
#include "NColor.h"
#include "Texture.h"
#include "..\Management\Error.h"
#include "Matrix4.h"
#include "VideoMode.h"
#include <glm.hpp>

using namespace NobelLib;
using namespace glm;

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

		enum TypeBuffer
		{
			Vertex = 0,
			Index = 1
		};

		class GLObject
		{
		protected:
			static HDC hDC;
			HGLRC		hRC;
			PIXELFORMATDESCRIPTOR PFD;
			unsigned int PixelFormat;
			static int gl_iBit;

			
			NFloat delta;
			int gl_iWidth;
			int gl_iHeight;
		public:
			static Resolution scr_cResolution;
			// GL Object
			GLuint gl_uVao;
			GLuint	gl_uVbo, gl_uIbo;
			const GLfloat* gl_aVertex;
			const GLushort* gl_aIndex;
			int gl_iVertex;
			int gl_iIndex;

			//flags
			bool gl_bLoaded;
			bool gl_bDrawing;


			GLObject();
			~GLObject();
			virtual void Draw() = 0;
			virtual void Destroy() = 0;
			bool Initialize();
			void gl_Sleep(LLINT Milliseconds);
			bool gl_setBit(int bitrate);
			void Color(NColor color);
			RESULT gl_genBuffer(TypeBuffer type);
			GLuint LoadTexture(Texture bmpTexture);
			void Resize(int w, int h);
			void Rotate(NFloat alpha, Axis _ax);
			void startOrthogonal();
			void endOrthogonal();
			bool Load(NFileName mesh);
			virtual void Load(void* whatyouwant = nullptr) = 0;
			void Swap();
		};
	}
}