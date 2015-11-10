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

			bool CanLoad();
			NString getModeOpen(OpenMode _Mode);

		public:
			NFile(NFileName path);
			bool Open(OpenMode OMode);
			int Close();

			bool IsStarted();

			int Write();
			int Read(void* vpGet, UINT length);
		};
	}
}