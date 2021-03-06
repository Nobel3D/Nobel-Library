#include "NCScript.h"
#include "NCommand.h"
#include "NResult.h"

using namespace NobelLib;
using namespace NobelLib::NCS;

NCommand::NCommand()
{
}
NCommand::NCommand(NCommand& oth)
{
}
bool NCommand::operator==(NString& strHeader)
{
	if (this->Header == strHeader)
		return true;
	else
		return false;
}
bool NCommand::operator!=(NString& strHeader)
{
	if (this->Header != strHeader)
		return true;
	else
		return false;
}
void NCommand::loadParams(List<NResult> listLoad)
{
		this->Params = listLoad;
}

NString NCommand::getName()
{
	return this->Header;
}