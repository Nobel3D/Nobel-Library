#pragma once

#include "..\Base\NString.h"

namespace NobelLib
{
	namespace Graphics
	{
		enum NMessageBoxResult 
		{
			OK = 1,
			CANCEL = 2,
			ABORT = 3,
			RETRY = 4,
			IGNORE = 5,
			YES = 6,
			NO = 7,
			TRYAGAIN = 10,
			CONTINUE = 11
		};
		enum NMessageBoxIcon
		{
			EXCLAMATION = 0x00000030L,
			WARNING = 0x00000030L,
			INFORMATION = 0x00000040L,
			ASTERISK = 0x00000040L,
			QUESTION = 0x00000020L,
			STOP = 0x00000010L,
			ERROR = 0x00000010L,
			HAND = 0x00000010L
		};
		enum NMessageBoxButton
		{

			ButtonABORTRETRYIGNORE = 0x00000002L,
			ButtonCANCELTRYCONTINUE =	0x00000006L,
			ButtonHELP = 0x00004000L,
			ButtonOK = 0x00000000L,
			ButtonOKCANCEL = 0x00000001L,
			ButtonRETRYCANCEL = 0x00000005L,
			ButtonYESNO = 0x00000004L,
			ButtonYESNOCANCEL = 0x00000003L

		};
		class NMessageBox
		{
		private:
		public:
			NMessageBox();
			~NMessageBox();
			static NMessageBoxResult Show(NString msgb_sText, NString msgb_sCaption, NMessageBoxButton msgb_nButton, NMessageBoxIcon msgb_nIcon);
		};
	}
}