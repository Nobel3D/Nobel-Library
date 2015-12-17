#include "Triangles.h"
#include "..\..\Management\Error.h"

using namespace NobelLib;
using namespace NobelLib::Graphics;
using namespace NobelLib::Graphics::Geometric;
using namespace NobelLib::Management;

Triangles::Triangles(Point3 _1, Point3 _2, Point3 _3) : GLObject()
{
	if (_1 == _2 || _1 == _3 || _2 == _3)
		Error("Triangle must have 3 different point", 94, false);
	geo_pTriangle1 = new Point3(_1);
	geo_pTriangle2 = new Point3(_2);
	geo_pTriangle3 = new Point3(_3);
}

Triangles::Triangles() : GLObject()
{
	geo_pTriangle1 = new Point3();
	geo_pTriangle2 = new Point3();
	geo_pTriangle3 = new Point3();
}

Triangles::~Triangles()
{
	Destroy();
}


void Triangles::Draw()
{
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, gl_uVbo);

	glVertexAttribPointer(
		0,                           // attribute. No particular reason for 1, but must match the layout in the shader.
		3,                                // size
		GL_FLOAT,                         // type
		GL_FALSE,                         // normalized?
		0,                                // stride
		(void*)0                          // array buffer offset
		);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, gl_uIbo);
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_SHORT, (void*)0);
}

void Triangles::Load(void * null)
{
	const GLfloat triangleVertex[] = {
		geo_pTriangle1->x, geo_pTriangle1->y, geo_pTriangle1->z,
		geo_pTriangle2->x, geo_pTriangle2->y, geo_pTriangle2->z,
		geo_pTriangle3->x, geo_pTriangle3->y, geo_pTriangle3->z
	};
	
	const GLushort triangleIndex[] = {0,1,2};

	gl_aIndex = triangleIndex;
	gl_aVertex = triangleVertex;
	gl_iVertex = 9;
	gl_iIndex = 3;

	gl_genBuffer(TypeBuffer::Vertex);
	gl_genBuffer(TypeBuffer::Index);
	gl_bLoaded = true;
}

void Triangles::Destroy()
{
	glDisableVertexAttribArray(gl_uVao);
	delete[] geo_pTriangle1;
	delete[] geo_pTriangle2;
	delete[] geo_pTriangle3;
}