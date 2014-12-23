#include "NResult.h"

using namespace NobelLib::Sys::NCScript;
using namespace NobelLib;

NResult::NResult(NString get)
{
	forceString = false;
	name = "";
	if (get.Find("\""))
		forceString = true;

	value = get;
}
NResult::NResult(double get)
{
	name = "";
	value = NString::fromDouble(get);
}

NResult::NResult(NResult& Other)
{
	if (!Other.name.Null())
		this->name = Other.name;

	this->value = Other.value;
}

NResult::NResult(NString get, NString strName)
{
	value = get;
	name = strName;
}
NResult::NResult(double get, NString strName)
{
	value = NString::fromDouble(get);
	name = strName;
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

bool NResult::compareName(NString other)
{
	if (this->name == other)
		return true;
	else
		return false;
}

bool NResult::compareValue(NString other)
{
	if (this->value == other)
		return true;
	else
		return false;
}

bool NResult::operator==(NResult& Compare)
{
	if (compareValue(Compare.value) && compareName(Compare.name))
		return true;
	else
		return false;
}

bool NResult::operator!=(NResult& Compare)
{
	if (compareValue(Compare.value) && compareName(Compare.name))
		return false;
	else
		return true;
}