#pragma once

#include "..\NString.h"
#include "NResult.h"
#include "..\List.h"

namespace NobelLib
{
	namespace Sys
	{
		namespace NCScript
		{
			class NCommand
			{
			protected:
				NString Header;
				List<NResult> Params;
				bool IsVoid = false;
				bool IsFuncion = false;
				bool IsVarible = false;
			public:
				NCommand();
				NCommand(NCommand& oth);
				virtual NResult exeCommand() = 0;
				void loadParams(List<NResult> listLoad);

				NString getName();

				bool operator==(NString& strHeader);
				bool operator!=(NString& strHeader);
			};
		}
	}
}