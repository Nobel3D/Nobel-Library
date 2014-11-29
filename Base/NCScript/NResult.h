#pragma once

#include "..\NString.h"

namespace NobelLib
{
	namespace Sys
	{
		namespace NCScript
		{
			enum Type {Value=0, String=1};
			class NResult
			{
			private:
				Type TypeData;
			public:
				double value;
				NString string;
				NResult(NString get, Type T);
				NResult(double get);
				NResult(NString get);
				NString getOutput();
			};
		}
	}
}