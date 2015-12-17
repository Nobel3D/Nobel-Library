#include "Render.h"

RESULT NobelLib::Graphics::Render::Load(Array<GLObject>* &obj)
{
	glGenBuffers(1, &gl_uVbo);
	glBindBuffer(GL_ARRAY_BUFFER, gl_uVbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof((&obj)[0]) * obj->SizeArray(), 0, GL_STATIC_DRAW);
//	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(gl_aVertex), gl_aVertex);

	glGenBuffers(1, &gl_uIbo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, gl_uIbo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(gl_aIndex) * sizeof(unsigned short), gl_aIndex, GL_STATIC_DRAW);
	return RESULT();
}

RESULT NobelLib::Graphics::Render::Draw()
{
	return RESULT();
}
