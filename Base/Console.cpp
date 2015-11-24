#include "Console.h"
#include <windows.h>
#include <stdio.h>
#include <iostream>


using namespace NobelLib;


Console::Console()
{
}

int Console::Close()
{
	return FreeConsole();
}
LLINT Console::Read(void* vpGet, LLINT length, LLINT count)
{
	LLINT result;
	result = fread(vpGet, count, length, stdin);
	if (result == length)
		return result;
	else
		stm_bEoF = true;
}
int Console::Write()
{
	return stmUsed = fwrite(stmBuffer,1,stmSize, stdout);
}
void Console::Wait()
{
	while (getchar() != '\n')
	{
		continue;
	}
}

void Console::setColor(SystemColor Background, SystemColor Text)
{
	NString* strColor = new NString(NString("COLOR ") + NString::toHex(Background) + NString::toHex(Text));
	system(*strColor);
	delete strColor;
}
