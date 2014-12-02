#pragma once

#include "..\System.h"
#include "..\DateTime.h"
#include "..\NString.h"
#include "NCommand.h"
#include "..\Windows\Console.h"

namespace NobelLib
{
	namespace Sys
	{
		namespace NCScript
		{
			class NCScript
			{
			private:

				Array<NCommand*> cmdUploaded;
				NString Header;
				List<NResult> Params;

				Windows::NConsole* Console;

				int checkSyntax(NString strCommand);
				int checkCommand();
				bool WaitCommand();
				void Reset();
			public:
				NCScript(Array<NCommand*>* arrayLibrary, Windows::NConsole* cmdConsole);
				int Start();
			};
		}
	}
}