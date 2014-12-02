#pragma once

#include "..\NString.h"

namespace NobelLib
{
	namespace Sys
	{
		namespace NCScript
		{
			class NResult
			{
			private:
				NString name;
				NString value;
			public:
				bool forceString = false;
			
				NResult(NString get);
				NResult(double get);
				NResult(NResult& Other);

				NString getOutput();
				double toValue();
				NString toString();
			};
		}
	}
}