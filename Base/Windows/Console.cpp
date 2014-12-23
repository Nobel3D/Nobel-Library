#include "Console.h"
#include <iostream>

using namespace NobelLib::Sys::Windows;
using namespace NobelLib;

#define MAX_SUPPORT_STRING 100


NConsole::NConsole()
{
	sendOutput(NString(">>>NConsole<<< by Nobel3D V.1.0"));
}

void NConsole::sendOutput(NString& Message)
{
	std::cout << Message << std::endl;
}
NString NConsole::getInput()
{
	NString strRet;
	do {
		char strInput[MAX_SUPPORT_STRING];
		std::cin >> strInput;
		strRet += strInput;
		strRet += " ";
	} while (getchar() != '\n');

	return strRet;
}
void NConsole::Wait()
{
	while (getchar() != '\n')
	{
		continue;
	}
}

void NConsole::setColor(SystemColor Background, SystemColor Text)
{
	NString* strColor = new NString(NString("COLOR ") + NString::toHex(Background) + NString::toHex(Text));
	system(*strColor);
	delete strColor;
}