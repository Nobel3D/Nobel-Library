#include "NError.h"
#include "System.h"


using namespace NobelLib::Sys;
using namespace NobelLib;

NError::NError(NString stringMessage, Windows::NConsole* ptrConsole)
{
	this->Console = ptrConsole;
	strError = stringMessage;
}

void NError::Show()
{
		Console->sendOutput(this->strError);
		Console->Wait();
		exit(-1);
}