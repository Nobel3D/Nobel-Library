#include "Texture.h"
#include <GL\glew.h>
#include "..\Management\Error.h"

using namespace NobelLib::Graphics;
using namespace NobelLib::IO;
using namespace NobelLib::Management;

const int Texture::res_iBMPheader = 54;

Texture::Texture(NFileName bmpTexture)
{
	BYTE header[res_iBMPheader];	// Each BMP file begins by a 54-bytes header
	UINT dataPos;					// Position in the file where the actual data begins
	NFile bmpFile(bmpTexture); bmpFile.Open(Reading);

	if ( bmpFile.Read(header,1,res_iBMPheader) != 54)	// If not 54 bytes read : problem
		Error("NobelLib::Graphics::Texture::Texture( bmpfilepath ) Not a correct BMP file",90, false);

	if (header[0] != 'B' || header[1] != 'M') 
		Error("NobelLib::Graphics::Texture::Texture( bmpfilepath ) This file is without BMP signature, impossible to load", 91 ,false);

	// Read ints from the byte array

	dataPos = *(int*)&(header[0x0A]);
	res_iSize = *(int*)&(header[0x22]);
	res_iWidth = *(int*)&(header[0x12]);
	res_iHeight = *(int*)&(header[0x16]);
	
	// Some BMP files are misformatted, guess missing information
	if (res_iSize == 0)    res_iSize= res_iHeight * res_iWidth * 3; // 3 : one byte for each Red, Green and Blue component
	if (dataPos == 0)      dataPos = 54;							// The BMP header is done that way
																	// Create a buffer

	res_yTexture = new BYTE[res_iSize];
	// Read the actual data from the file into the buffer
	bmpFile.Read(res_yTexture, res_iSize);
	//Everything is in memory now, the file can be closed
	bmpFile.Close();

	// Create one OpenGL texture
	GLuint textureID;

	glGenTextures(1, &textureID);

	// "Bind" the newly created texture : all future texture functions will modify this texture
	glBindTexture(GL_TEXTURE_2D, textureID);
	// Give the image to OpenGL
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, res_iWidth, res_iHeight, 0, GL_BGR, GL_UNSIGNED_BYTE, res_yTexture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
}

BYTE* Texture::getTexture()
{
	return res_yTexture;
}

Texture::operator BYTE *()
{
	return getTexture();
}