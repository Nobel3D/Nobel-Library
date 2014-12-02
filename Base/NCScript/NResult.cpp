#include "NResult.h"

using namespace NobelLib::Sys::NCScript;
using namespace NobelLib;

NResult::NResult(NString get)
{
	forceString = false;

	if (get.Find("\""))
		forceString = true;

	value = get;
}
NResult::NResult(double get)
{
	value = NString::fromDouble(get);
}

NResult::NResult(NResult& Other)
{
	this->value = Other.value;
}
NString NResult::getOutput()
{
		return this->value;
}

double NResult::toValue()
{
	return this->value.toDouble();
}
NString NResult::toString()
{
	if (forceString)
		return this->value;
}