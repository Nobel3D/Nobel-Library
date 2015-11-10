#pragma once

#include "..\NString.h"
#include "..\Console.h"

namespace NobelLib
{
	namespace NCS
	{
		class NError
		{
		private: 
			NString strError;
			Console err_cConsole;
		public:
			NError(NString stringMessage, Console& ptrConsole);
			void Show();
		};
	}
}