#pragma once

#include "..\NString.h"

namespace NobelLib
{
	namespace Sys
	{

		namespace Windows
		{
			class NConsole
			{
			private:

			public:
				NConsole();
				void sendOutput(NString& Message);
			};
		}
	}
}