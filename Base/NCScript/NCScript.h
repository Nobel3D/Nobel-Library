#pragma once

#include "..\System.h"
#include "..\DateTime.h"
#include "..\NString.h"
#include "NCommand.h"

namespace NobelLib
{
	namespace Sys
	{
		namespace NCScript
		{
			class NCScript
			{
			private:

				Array<NCommand> cmdUploaded;
				NString Header;
				List<NString> Params;

				bool IsVoid;
				bool IsFuncion;
				bool IsVarible;
				bool IsString;
				bool IsValue;

				int checkSyntax(NString strCommand);
				int checkCommand();
			public:
				NCScript(Array<NCommand>* arrayLibrary);
				void sendOutput(NString& Message);
				bool WaitCommand();
			};
		}
	}
}