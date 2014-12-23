#pragma once
#include "..\Base\NString.h"
#include "..\Base\NFileName.h"
#include "Stream.h"
#include <stdio.h>

namespace NobelLib
{
	namespace IO
	{
		
		class NFile : public Stream
		{
		private:
			NFileName* Path;
			FILE* LinkFile;
			OpenMode Mode;
			bool Start;

			bool CanLoad();
			NString getModeOpen(OpenMode _Mode);

		public:
			NFile(NString& _Path);
			NFile(const char* _Path);
			bool Open(OpenMode OMode);
			void Close();

			bool IsStarted();

			void Write();
			bool Read(void* vpGet, UINT length);
		};
	}
}