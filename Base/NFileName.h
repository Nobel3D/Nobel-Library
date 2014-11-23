#pragma once
#include "NString.h"

namespace NobelLib
{
	class NFileName : public NString
	{
	private:
		/*Only name File*/
		NString* strFileName;
		/*Only Extension File*/
		NString* strExtension;
		/*Complete name file*/
		NString* strFile; 

		NString takePath();
	public:
		NFileName(const char* strName);

		//getter
		NString getAllName();
		NString getExt();
		NString getPath();

		operator const char*();
		operator const char*() const;
	};
}