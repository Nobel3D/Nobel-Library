#include "OpenGL.h"
#include "Point.h"
#include <gtc\matrix_transform.hpp>


using namespace glm;
using namespace NobelLib::Graphics;
using namespace NobelLib::IO;
using namespace NobelLib;
using namespace NobelLib::Management;

int GLObject::gl_iBit = 32;
HDC GLObject::hDC = NULL;
Resolution GLObject::scr_cResolution;

GLObject::GLObject()
{
}

GLObject::~GLObject()
{
	// Cleanup VBO
	glDeleteBuffers(1, &gl_uVbo);
	glDeleteBuffers(1, &gl_uIbo);
	glDeleteVertexArrays(1, &gl_uVao);

	delete[] gl_aVertex;
	delete[] gl_aIndex;
}

bool GLObject::gl_setBit( int bitrate )
{
	gl_iBit = bitrate;
	//restart gl and redraw all object TODO
	return true;
}

bool NobelLib::Graphics::GLObject::Initialize()
{
	glGenVertexArrays(1, &gl_uVao);
	glBindVertexArray(gl_uVao);
	return true;
}

void GLObject::gl_Sleep(LLINT Milliseconds)
{
	Sleep(Milliseconds);

}

void GLObject::Color(NColor color)
{
	glColor3f(color.Red, color.Green, color.Blue);
}

RESULT NobelLib::Graphics::GLObject::gl_genBuffer(TypeBuffer type)
{
	try
	{
		switch (type)
		{
		case Vertex:
		{
			if (gl_aVertex == nullptr)
			{
				Error("Impossible to load a gl_aVertex if it's nullptr value, please create the Vertex Buffer", 95, false);
				return -1;
			}
			//TODO
			glGenBuffers(1, &gl_uVbo);
			glBindBuffer(GL_ARRAY_BUFFER, gl_uVbo);
			glBufferData(GL_ARRAY_BUFFER, sizeof(gl_aVertex[0]) * gl_iVertex, gl_aVertex, GL_STATIC_DRAW);
		}
		case Index:
		{
			if (gl_aIndex == nullptr)
			{
				Error("Impossible to load a gl_aIndex if it's nullptr value, please create the Index Buffer", 96, false);
				return -1;
			}
			glGenBuffers(1, &gl_uIbo);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, gl_uIbo);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(gl_aIndex[0]) * gl_iIndex, gl_aIndex, GL_STATIC_DRAW);
		}
		}
	}
	catch (std::exception exc)
	{
		Error(&exc, 97, false);
		return -2;
	}
	return 1;
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

void GLObject::Rotate(NFloat alpha, Axis _ax)
{
	glPushMatrix();
	switch (_ax)
	{
	case X:
		glRotatef(delta, 1.0f, 0.0f, 0.0f);
	case Y:
		glRotatef(delta, 0.0f, 1.0f, 0.0f);
	case Z:
		glRotatef(delta, 0.0f, 0.0f, 1.0f);
	}
	delta += alpha;
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
/*
bool GLObject::Load(NFileName mesh)
{
	UINT     *pbuffer, *pbuffer;
	UINT    size;
	NFile* loading = new NFile(mesh);
	loading->Open(Reading, true);
	while (!loading->isEoF())
	{
		loading->Read(pbuffer,loading->getLenght());
	}
	

	glGenVertexArrays(1, &gl_uVao);
	glBindVertexArray(gl_uVao);

	glGenBuffers(1, &gl_uVbo);
	glBindBuffer(GL_ARRAY_BUFFER, gl_uVbo);
	glBufferData(GL_ARRAY_BUFFER, m_vcount * sizeof(mesh_vertex_t),
		GL_PVOID(pbuffer), GL_STATIC_DRAW);

	glVertexAttribPointer(VERT_POSITION, 3, GL_FLOAT, GL_FALSE,
		sizeof(mesh_vertex_t), GL_PVOID(0));
	glEnableVertexAttribArray(VERT_POSITION);

	glVertexAttribPointer(VERT_TEXCOORD, 2, GL_FLOAT, GL_FALSE,
		sizeof(mesh_vertex_t), GL_PVOID(sizeof(float3)));
	glEnableVertexAttribArray(VERT_TEXCOORD);

	glVertexAttribPointer(VERT_NORMAL, 3, GL_FLOAT, GL_FALSE,
		sizeof(mesh_vertex_t), GL_PVOID(sizeof(float3) + sizeof(float2)));
	glEnableVertexAttribArray(VERT_NORMAL);

	if (!m_icount)
	{
		delete[] buffer;
		return true;
	}

	pbuffer += m_vcount * sizeof(mesh_vertex_t);

	glGenBuffers(1, &m_ibo);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_vbo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_icount * sizeof(mesh_index_t),
		GL_PVOID(pbuffer), GL_STATIC_DRAW);

	delete[] buffer;
	return true;

}*/
void NobelLib::Graphics::GLObject::Swap()
{
	SwapBuffers(hDC);
}