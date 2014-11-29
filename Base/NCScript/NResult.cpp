#include "NResult.h"

using namespace NobelLib::Sys::NCScript;
using namespace NobelLib;

NResult::NResult(NString get, Type T)
{
	if (T == Value)
		value = get.toDouble();
	if (T == String)
		string = get;
}
NResult::NResult(double get)
{
	TypeData = Value;
	value = get;
}
NResult::NResult(NString get)
{
	TypeData = String;
		string = get;
}

NString NResult::getOutput()
{
	if (TypeData == String)
	{
		return this->string;
	}
	if (TypeData == Value)
	{
		return NString::fromDouble(this->value);
	}
}
