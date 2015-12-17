#pragma once

#include "..\Stream\NFile.h"
#include <GL\glew.h>

namespace NobelLib
{
	namespace Graphics
	{
		class Shader
		{
		private:
			GLuint ShaderID;
		public:
			Shader();
			GLuint Load(IO::NFileName _vertex, IO::NFileName _fragment);
			GLuint ID();
			void Use();
			void Destroy();

			operator GLuint();
		};
	}
}