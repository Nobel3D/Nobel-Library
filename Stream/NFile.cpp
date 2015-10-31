#pragma once
#include "NFile.h"

using namespace NobelLib::IO;
using namespace NobelLib;

NFile::NFile(NString& _Path) : Stream(_Path)
{
	Path =  _Path;
	Start = false;
}
NFile::NFile(const char* _Path) : Stream(_Path)
{
	Path = NString(_Path);
	Start = false;
}
bool NFile::Open(OpenMode OMode)
{
	if (getModeOpen(OMode) == "r")
	{
		if (IsStarted() == false && CanLoad())
		{
			LinkFile = fopen(Path, "r");
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
			LinkFile = fopen(Path, getModeOpen(OMode));
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
	if (FILE *file = fopen(Path, "r")) {
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

void NFile::Close()
{
//	if (IsStarted())
		fclose(LinkFile);
}

void NFile::Write()
{
	fwrite(stmBuffer, 1, stmSize, LinkFile);
}

bool NFile::Read(void* vpGet, UINT length)
{
	if (Mode == OpenMode::Reading)
	{
		UINT result = fread(vpGet, 1, length, LinkFile);
		if (result != length)
			return false;
		else
			return true;
	}
	else
		vpGet = NULL;
}
