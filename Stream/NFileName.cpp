#include "NFileName.h"
#include "..\Management\Error.h"
#include <iostream>

using namespace NobelLib;
using namespace NobelLib::IO;
using namespace NobelLib::Management;

NFileName::NFileName()
{

}

NFileName::NFileName(const char* filePath)
{
	setFile(NString(filePath));
}
NFileName::NFileName(NString filePath)
{
	setFile(NString(filePath));
}

void NFileName::setFile(NString path)
{
		txt_sFile = path;

		if (txt_sFile.Find("."))
		{
			Array<NString> arrayFileName;
			txt_sFile.Split('.', arrayFileName);
			txt_sFileName = arrayFileName[0];
			txt_sExtension = arrayFileName[1];
		}
		else
		{
			Error("Error path into constructor of NFileName!", 16, false);
		}
}

NString NFileName::takePath()
{
	Array<NString> arrayPath;
	NString strPath;
	txt_sFileName.Split('\\', arrayPath);
	for (int i = 0; i < arrayPath.SizeArray() - 1; i++)
		strPath += arrayPath[i];
	return strPath;
}
NString NFileName::getPath()
{

	return takePath();
}

NFileName::operator const char *()
{
	return this->txt_sFile;
}

NFileName::operator const char *() const
{
	return this->txt_sFile;
}

NFileName NFileName::operator=(NFileName file)
{
	this->txt_sExtension = file.txt_sExtension;
	this->txt_sFile = file.txt_sFile;
	this->txt_sFileName = file.txt_sFileName;

	return *this;
}