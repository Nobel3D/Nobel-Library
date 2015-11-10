#pragma once
#include "NFile.h"

using namespace NobelLib::IO;
using namespace NobelLib;

NFile::NFile(NFileName Path) 
{
	txt_cPath = Path;
	Start = false;
}
bool NFile::Open(OpenMode OMode)
{
	if (getModeOpen(OMode) == "r")
	{
		if (IsStarted() == false && CanLoad())
		{
			LinkFile = fopen(txt_cPath, "r");
			Mode = OMode;
			Start = true;
			return true;
		}
		else
			return false;
	}
	else
	{
		if (IsStarted() == false)
		{
			LinkFile = fopen(txt_cPath, getModeOpen(OMode));
			Mode = OMode;
			Start = true;
			return true;
		}
		else
			return false;
	}
}
bool NFile::CanLoad()
{
	if (FILE *file = fopen(txt_cPath, "r")) {
		fclose(file);
		return true;
	}
	else {
		return false;
	}
}
bool NFile::IsStarted()
{
	return Start;
}

NString NFile::getModeOpen(OpenMode _Mode)
{
	NString TypeOpen;
	if (_Mode == OpenMode::Reading)
	{
		TypeOpen = "r";
	}
	if (_Mode == OpenMode::Writing)
	{
		TypeOpen = "w";
	}
	if (_Mode == OpenMode::Append)
	{
		TypeOpen = "a";
	}
	return NString(TypeOpen);
}

int NFile::Close()
{
	if (IsStarted())
		return fclose(LinkFile);
}

int NFile::Write()
{
	return fwrite(stmBuffer, 1, stmSize, LinkFile);
}

int NFile::Read(void* vpGet, UINT length)
{
	if (Mode == OpenMode::Reading)
	{
		UINT result = fread(vpGet, 1, length, LinkFile);
		if (result != length)
			return 0;
		else
			return 1;
	}
	else
		vpGet = NULL;
}
