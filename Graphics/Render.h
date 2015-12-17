#pragma once

#include "OpenGL.h"

namespace NobelLib
{
	namespace Graphics
	{
		class Render
		{
		private:
			static GLuint	gl_uVbo, gl_uIbo;
			static GLushort* gl_aIndex;
			static int gl_iVertex;
		public:
			Render();
			RESULT Load(Array<GLObject>* &obj);
			RESULT Draw();
		};
	}
}