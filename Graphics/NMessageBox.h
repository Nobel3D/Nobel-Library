#pragma once

#include "..\Base\NString.h"

namespace NobelLib
{
	namespace Graphics
	{
		enum NMessageBoxResult 
		{
			ROK = 1,
			RCANCEL = 2,
			RABORT = 3,
			RRETRY = 4,
			RIGNORE = 5,
			RYES = 6,
			RNO = 7,
			RTRYAGAIN = 10,
			RCONTINUE = 11
		};
		enum NMessageBoxIcon
		{
			IEXCLAMATION = 0x00000030L,
			IWARNING = 0x00000030L,
			IINFORMATION = 0x00000040L,
			IASTERISK = 0x00000040L,
			IQUESTION = 0x00000020L,
			ISTOP = 0x00000010L,
			IERROR = 0x00000010L,
			IHAND = 0x00000010L
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