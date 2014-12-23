#pragma once

#include "..\System.h"
#include "..\DateTime.h"
#include "..\NString.h"
#include "NCommand.h"
#include "..\NError.h"
#include "..\..\Stream\NFile.h"
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
				IO::NFile* fileLog;
				Array<NCommand*> cmdUploaded;
				NString Header;
				List<NResult> Params;
				List<NResult> Variables;

				Windows::NConsole* Console;

				void addLog(NString strMessage);
				int indexVariable(NString nameVariable);
				void logCommands();
				int checkSyntax(NString strCommand);
				int checkCommand();
				bool WaitCommand();
				void Reset();
			public:
				NCScript(Array<NCommand*>* arrayLibrary, Windows::NConsole* cmdConsole);
				~NCScript();
				int Start();
			};
		}
	}
}