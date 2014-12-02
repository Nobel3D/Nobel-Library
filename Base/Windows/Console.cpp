#include "Console.h"
#include <iostream>

using namespace NobelLib::Sys::Windows;
using namespace NobelLib;

NConsole::NConsole()
{
	sendOutput(NString("Loading Console..."));
}

void NConsole::sendOutput(NString& Message)
{
	std::cout << Message << std::endl;
}
