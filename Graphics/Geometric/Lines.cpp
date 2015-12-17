#include "Lines.h"

using namespace NobelLib;
using namespace NobelLib::Graphics;
using namespace NobelLib::Graphics::Geometric;

Lines::Lines(Point3 begin, Point3 end)
{
	geo_pLine1 = begin;
	geo_pLine2 = end;
}
NobelLib::Graphics::Geometric::Lines::~Lines()
{
}

Lines::Lines()
{
	geo_pLine1 = Point3();
	geo_pLine2 = Point3();
}

void Lines::Load(void * null)
{
	GLfloat gl_aVertex[] = {
		geo_pLine1.x, geo_pLine1.y, geo_pLine1.z,
		geo_pLine2.x, geo_pLine2.y, geo_pLine2.z
	};
	GLushort gl_aIndex[] = { 0,1 };
	glGenBuffers(1, &gl_uVbo);
	glBindBuffer(GL_ARRAY_BUFFER, gl_uVbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(gl_aVertex), gl_aVertex, GL_STATIC_DRAW);

	glGenBuffers(1, &gl_uIbo);
	glBindBuffer(GL_ARRAY_BUFFER,gl_uIbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(gl_aIndex)*sizeof(unsigned short), &gl_aIndex[0], GL_STATIC_DRAW);

}
void Lines::Draw()
{
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, gl_uVbo);

	glVertexAttribPointer(
		0,                           // attribute. No particular reason for 1, but must match the layout in the shader.
		2,                                // size
		GL_FLOAT,                         // type
		GL_FALSE,                         // normalized?
		0,                                // stride
		(void*)0                          // array buffer offset
		);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, gl_uIbo);
	glDrawElements(GL_LINE, 2, GL_UNSIGNED_SHORT, 0);
}

void Lines::Destroy()
{
}