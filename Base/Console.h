#pragma once

#include "NString.h"
#include "..\Stream\Stream.h"

namespace NobelLib
{

			enum SystemColor {
				DBlack = 0, DBlue = 1, DGreen = 2, DAqua = 3, DRed = 4, DPurple = 5, DYellow = 6, DWhite = 7,
				DGray = 8, LBlue = 9, LGreen = 10, LAqua = 11, LRed = 12, LPurple = 13, LYellow = 14, LWhite = 15 
			};
			class Console : public IO::Stream
			{
			private:

			public:
				Console();
				void Wait();
				void setColor(SystemColor Background, SystemColor Text);
				int Close();

				bool IsStarted();

				int Write();
				LLINT Read(void* vpGet, LLINT length, LLINT count = 1);
			};
	}