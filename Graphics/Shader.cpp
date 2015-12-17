#include "Shader.h"
#include <GL\Glew.h>
#include "..\Management\Error.h"

using namespace NobelLib;
using namespace NobelLib::IO;
using namespace NobelLib::Graphics;
using namespace NobelLib::Management;

Shader::Shader()
{
}


GLuint Shader::Load(NFileName vertexFile, NFileName fragmentFile)
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
		if (VertexShaderErrorMessage.SizeArray() != 13) //"No errors.\n" string
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

	return ShaderID = ProgramID;
}

void Shader::Destroy()
{
	glDeleteProgram(ShaderID);
}

GLuint Shader::ID()
{
	return ShaderID;
}

void NobelLib::Graphics::Shader::Use()
{
	glUseProgram(ShaderID);
}

Shader::operator GLuint()
{
	return ShaderID;
}
