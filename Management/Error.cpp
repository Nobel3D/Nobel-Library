#include "Error.h"
#include "Log.h"
#include "..\Graphics\NMessageBox.h"

using namespace NobelLib;
using namespace NobelLib::Management; 

	Error::Error(NString strError, NString strCaption, bool isFatal)
	{
		err_sText = strError;
		err_sCaption = strCaption;
		err_bFatal = isFatal;

		Show();
	}

	void Error::Show()
	{
		errorBox(err_sText, err_sCaption);
		Log::Write(err_sCaption,err_sText, new NFileName(NOBELENGINELOG));
		if (err_bFatal)
			err_ForceQuit();
	}

	Error::Error(NString strError, int numError, bool isFatal)
	{
		err_sText = strError;
		err_sCaption = NString("Error N.") + NString::fromInt(numError);
		err_bFatal = isFatal;

		Show();
	}
	Error::Error(std::exception* excError,int numError, bool isFatal)
	{
		err_sText = excError->what();
		err_sCaption = NString("Error N.") + NString::fromInt(numError);
		err_bFatal = isFatal;

		Show();
	}

	void Error::errorBox(NString strShow, NString strCap)
	{
		Graphics::NMessageBox::Show(strShow, strCap, Graphics::ButtonOK, Graphics::EXCLAMATION);
	}

	void Error::err_ForceQuit()
	{
		exit(-1);
	}