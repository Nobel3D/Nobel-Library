#pragma once

#include "System.h"
#include "..\..\Management\DateTime.h"
#include "..\NString.h"
#include "NCommand.h"
#include "NError.h"
#include "..\..\Stream\NFile.h"
#include "Console.h"

namespace NobelLib
{
		namespace NCS
		{
			class NCScript
			{
			private:
				IO::NFile* fileLog;
				Array<NCommand*> cmdUploaded;
				NString Header;
				List<NResult> Params;
				List<NResult> Variables;

				NConsole* Console;

				void addLog(NString strMessage);
				int indexVariable(NString nameVariable);
				void logCommands();
				int checkSyntax(NString strCommand);
				int checkCommand();
				bool WaitCommand();
				void Reset();
			public:
				NCScript(Array<NCommand*>* arrayLibrary, NConsole* cmdConsole);
				~NCScript();
				int Start();
			};
		}
}