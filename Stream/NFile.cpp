#pragma once
#include "NFile.h"
#include "..\Management\Error.h"

using namespace NobelLib::IO;
using namespace NobelLib;
using namespace NobelLib::Management;

NFile::NFile(NFileName Path) 
{
	txt_cPath = Path;
	Start = false;
}
bool NFile::Open(OpenMode OMode, bool isBinary)
{
	res_bBinary = isBinary;
	if (getModeOpen(OMode) == "r")
	{
		if (!IsStarted() && CanLoad())
		{
			LinkFile = fopen(txt_cPath, "r");
			Mode = OMode;
			Start = true;
			return true;
		}
		else
			Error("Impossible to load stream to target file!", 17, false);
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
			Error("Target file is already loaded!", 18, false);
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

LLINT NFile::getLenght()
{
	return ftell(LinkFile);
}

NString NFile::getModeOpen(OpenMode _Mode)
{
	NString TypeOpen = NString();
	if (_Mode == OpenMode::Reading)
	{
		TypeOpen += "r";
	}
	if (_Mode == OpenMode::Writing)
	{
		TypeOpen += "w";
	}
	if (_Mode == OpenMode::Append)
	{
		TypeOpen += "a";
	}
	if (res_bBinary)
	{
		TypeOpen += "b";
	}
	return TypeOpen;
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

LLINT NFile::Read(void* vpGet, LLINT length, LLINT count)
{
	LLINT result = 0;
	if (Mode == OpenMode::Reading)
	{
		if (!res_bBinary)
		{
			result = fread(vpGet, count, length, LinkFile);
			if (result == length)
				return length;
			else
			{
				stm_bEoF = true;
				return 0;
			}
		}
		else
		{
			return fread(vpGet, length, count, LinkFile);
			if (result == length)
				return length;
			else
			{
				stm_bEoF = true;
				return 0;
			}
		}
	}
	else
	{
		Error("NobelLib::IO::NFile::Read(TextFile) Impossible use a writing stream to writing funcions!", 19, false);
		vpGet = NULL;
	}
}



void NFile::Write(BYTE* bin)
{
	if (res_bBinary)
	{
		fwrite(bin, sizeof(bin), 1, LinkFile);
	}
	else
	{
		Error("NobelLib::IO::NFile::Write(BinaryFile) Impossible use binary stream in text stream!", 20, false);
	}
}