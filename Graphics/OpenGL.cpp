#include "OpenGL.h"

using namespace NobelLib::Graphics;
using namespace NobelLib::IO;
using namespace NobelLib;
using namespace NobelLib::Management;

int GLObject::gl_iBit = 32;
HDC GLObject::hDC = NULL;

GLObject::GLObject()
{
	glClearColor(1.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glEnable(GL_TEXTURE_2D);
}

bool GLObject::gl_setBit( int bitrate )
{
	gl_iBit = bitrate;
	//restart gl and redraw all object TODO
	return true;
}

void GLObject::gl_Sleep(LLINT Milliseconds)
{
	Sleep(Milliseconds);

}

void GLObject::gl_Clear()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void GLObject::Color(NColor color)
{
	glColor3f(color.Red, color.Green, color.Blue);
}

GLuint GLObject::LoadTexture(Texture bmpTexture)
{
	GLuint texture = 0;

	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	//even better quality, but this will do for now.
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	//to the edge of our shape. 
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	//Generate the texture
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 2, 2, 0, GL_RGB, GL_UNSIGNED_BYTE, bmpTexture);
	return texture; //return whether it was successful
}

void GLObject::Resize(int w, int h)
{
	gl_iWidth = w;
	gl_iHeight = h;
	glViewport(0, 0, w, h);
}

void GLObject::startOrthogonal() 
{
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, gl_iWidth, 0, gl_iHeight);
	glScalef(1, -1, 1);
	glTranslatef(0, -gl_iWidth, 0);
	glMatrixMode(GL_MODELVIEW);
}

void GLObject::endOrthogonal() 
{
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
}

GLuint GLObject::LoadShaders(IO::NFileName vertexFile, IO::NFileName fragmentFile)
{
		// Create the shaders
		GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
		GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

		// Read the Vertex Shader code from the file
		NString FragmentShaderCode;
		NString VertexShaderCode;
		NString line;

		NFile VertexStream(vertexFile); VertexStream.Open(Reading);

		while (!VertexStream.isEoF())
		{
			VertexStream >> line;
			VertexShaderCode += line;
		}
		VertexStream.Close();

		// Read the Fragment Shader code from the file
		NFile FragmentStream(fragmentFile); FragmentStream.Open(Reading);

		while (!FragmentStream.isEoF())
		{
			FragmentStream >> line;
			FragmentShaderCode += line;
		}
		FragmentStream.Close();

		GLint Result = GL_FALSE;
		int InfoLogLength;

		// Compile Vertex Shader

		Log(NString("Compiling shader vertex : ") + vertexFile);

		char const * VertexSourcePointer = VertexShaderCode;
		VertexShaderCode.Clear();

		glShaderSource(VertexShaderID, 1, &VertexSourcePointer, NULL);
		glCompileShader(VertexShaderID);

		// Check Vertex Shader

		glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &Result);
		glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);

		if (InfoLogLength > 0) 
		{
			Array<char> VertexShaderErrorMessage(InfoLogLength + 1);
			glGetShaderInfoLog(VertexShaderID, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
			if(VertexShaderErrorMessage.SizeArray() != 13) //"No errors.\n" string
				Error(&VertexShaderErrorMessage[0], 92, false);

		}

		// Compile Fragment Shader
		Log(NString("Compiling shader fragment : ") + fragmentFile);

		char const * FragmentSourcePointer = FragmentShaderCode;
		glShaderSource(FragmentShaderID, 1, &FragmentSourcePointer, NULL);
		glCompileShader(FragmentShaderID);



		// Check Fragment Shader
		glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &Result);
		glGetShaderiv(FragmentShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);

		if (InfoLogLength > 0) 
		{
			Array<char> FragmentShaderErrorMessage(InfoLogLength + 1);
			glGetShaderInfoLog(FragmentShaderID, InfoLogLength, NULL, &FragmentShaderErrorMessage[0]);
			if (FragmentShaderErrorMessage.SizeArray() != 13) //"No errors.\n" string
				Error(&FragmentShaderErrorMessage[0], 93, false); 

		}

		// Link the program
		printf("Linking program\n");
		GLuint ProgramID = glCreateProgram();

		glAttachShader(ProgramID, VertexShaderID);
		glAttachShader(ProgramID, FragmentShaderID);
		glLinkProgram(ProgramID);


		// Check the program
		glGetProgramiv(ProgramID, GL_LINK_STATUS, &Result);
		glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength);

		if (InfoLogLength > 0) 
		{
			Array<char> ProgramErrorMessage(InfoLogLength + 1);
			glGetProgramInfoLog(ProgramID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
			printf("%s\n", &ProgramErrorMessage[0]);
		}


		glDetachShader(ProgramID, VertexShaderID);
		glDetachShader(ProgramID, FragmentShaderID);


		glDeleteShader(VertexShaderID);
		glDeleteShader(FragmentShaderID);

		return ProgramID;
}
