#include "NFileName.h"
#include <stdexcept>
#include <iostream>

using namespace NobelLib;

NFileName::NFileName(const char* strName)
{
	try
	{
		strFile = new NString(strName);
		if (strFile->Find("."))
		{
			Array<NString> arrayFileName;
			strFile->Split('.', arrayFileName);
			strFileName = &arrayFileName[0];
			strExtension = &arrayFileName[1];
		}
		else
		{
			throw std::invalid_argument("Error path into constructor of NFileName!");
		}
	}
	catch (std::invalid_argument& e)
	{
		std::cout << e.what();
	}
}

NString NFileName::getAllName()
{
	return *strFileName;
}

NString NFileName::getExt()
{
	return *strExtension;
}

NString NFileName::takePath()
{
	Array<NString> arrayPath;
	NString strPath;
	strFileName->Split('\\', arrayPath);
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
	return *this->strFile;
}

NFileName::operator const char *() const
{
	return *this->strFile;
}