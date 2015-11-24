#pragma once

#include "..\Base\NString.h"
#include "Log.h"
#include <exception>

#ifndef NOBELENGINELOG
#define NOBELENGINELOG "NobelEngine.log"
#endif
#ifndef MAXTRYLOG
#define MAXTRYLOG 5
#endif

namespace NobelLib
{
	namespace Management
	{
		class Error
		{
		private:
			/*Show a message box with: strShow = message strCap = Caption*/
			void static errorBox(NString strShow, NString strCap);
		public:
			NString err_sText;
			NString err_sCaption;
			bool err_bFatal;

			/*Default constructor*/
			Error(NString strError, NString strCaption, bool isFatal);
			Error(NString strError, int numError, bool isFatal);
			Error(std::exception* exError, int numError, bool isFatal);
			/*Show message box when error appears with personalizate message and add it on log:
			strError=Message strCaption=Caption isFatal=When appers, will appear the program?*/
			void Show();
			/*The program will quit*/
			static void err_ForceQuit();
		};
	}
}