#pragma once
#include "..\Base\NString.h"
#include "NFile.h"

namespace NobelLib
{
	namespace IO
	{
		class NFileName
		{
		private:
			void setFile(NString path);
			NString takePath();
		public:
			NFileName(const char* filePath);
			NFileName(NString filePath);
			NFileName();

			/*Only name File*/
			NString txt_sFileName;
			/*Only Extension File*/
			NString txt_sExtension;
			/*Complete name file*/
			NString txt_sFile;
			/*File pointer*/
			NFile* txt_rFile;

			NString getPath();

			operator const char*();
			operator const char*() const;
			NFileName operator=(NFileName file);
		};
	}
}