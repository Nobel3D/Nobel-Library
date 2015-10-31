#include "NError.h"
#include "System.h"


using namespace NobelLib::NCS;
using namespace NobelLib;

NError::NError(NString stringMessage, NConsole* ptrConsole)
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