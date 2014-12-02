#pragma once

#include "NString.h"

namespace NobelLib
{
	namespace Sys
	{
		class NError
		{
		private: 
			NString* strError;
		public:
			NError(NString& stringMessage);
			void Show();
		};
	}
}