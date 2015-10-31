#pragma once

#include "..\NString.h"
#include "Console.h"

namespace NobelLib
{
	namespace NCS
	{
		class NError
		{
		private: 
			NString strError;
			NConsole* Console;
		public:
			NError(NString stringMessage, NConsole* ptrConsole);
			void Show();
		};
	}
}