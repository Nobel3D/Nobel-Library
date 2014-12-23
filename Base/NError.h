#pragma once

#include "NString.h"
#include "Windows\Console.h"

namespace NobelLib
{
	namespace Sys
	{
		class NError
		{
		private: 
			NString strError;
			Sys::Windows::NConsole* Console;
		public:
			NError(NString stringMessage, NobelLib::Sys::Windows::NConsole* ptrConsole);
			void Show();
		};
	}
}