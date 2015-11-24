#pragma once
#include "..\Base\NString.h"
#include "Stream.h"
#include <stdio.h>
#include "NFileName.h"

namespace NobelLib
{
	namespace IO
	{
		
		class NFile : public Stream
		{
		private:
			NFileName txt_cPath;
			FILE* LinkFile;
			OpenMode Mode;
			bool Start;
			bool res_bBinary;

			bool CanLoad();
			NString getModeOpen(OpenMode _Mode);

		public:
			NFile(NFileName path);
			bool Open(OpenMode OMode,bool isBinary = false);
			int Close();

			bool IsStarted();

			int Write();
			LLINT Read(void* vpGet, LLINT length, LLINT count = 1);
			void Write(BYTE* bin);
		};
	}
}