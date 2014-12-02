#include "NError.h"
#include "System.h"

using namespace NobelLib::Sys;
using namespace NobelLib;

NError::NError(NString& stringMessage)
{
	strError = &stringMessage;
}

void NError::Show()
{
	if (SystemType::Console)
	{
		
	}
}