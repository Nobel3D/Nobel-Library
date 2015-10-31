#pragma once

#include "..\NString.h"

#define CMDWIN32

namespace NobelLib
{
	namespace NCS
	{
			enum SystemColor {
				Black = 0, Blue = 1, Green = 2, Aqua = 3, Red = 4, Purple = 5, Yellow = 6, White = 7,
				Gray = 8, LBlue = 9, LGreen = 10, LAqua = 11, LRed = 12, LPurple = 13, LYellow = 14, LWhite = 15 
			};
			class NConsole
			{
			private:

			public:
				NConsole();
				void sendOutput(NString& Message);
				NString getInput();
				void Wait();
				void setColor(SystemColor Background, SystemColor Text);
			};
		}
	}