#include "NCScript.h"
#include "NCommand.h"
#include "NResult.h"

using namespace NobelLib;
using namespace NobelLib::Sys::NCScript;

NCommand::NCommand()
{
}
NCommand::NCommand(NCommand& oth)
{
}
bool NCommand::operator==(NString& strHeader)
{
	if (this->Header == Header)
		return true;
	else
		return false;
}
bool NCommand::operator!=(NString& strHeader)
{
	if (this->Header != Header)
		return true;
	else
		return false;
}