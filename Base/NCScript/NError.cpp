#include "NError.h"
#include <Windows.h>


using namespace NobelLib::NCS;
using namespace NobelLib;

NError::NError(NString stringMessage, Console& ptrConsole)
{
	err_cConsole = ptrConsole;
	strError = stringMessage;
}

void NError::Show()
{
		err_cConsole << this->strError;
		err_cConsole.Wait();
		exit(-1);
}