#include "Log.h"
#include "Error.h"
#include "..\Management\DateTime.h"

using namespace NobelLib;
using namespace NobelLib::Management;
using namespace NobelLib::IO;

int Log::countFail = 0;

	Log::Log(NFileName filePath)
	{
		txt_rPath = filePath;
	}
	void Log::Write(NString strHandler, NString strLog)
	{
		try
		{
			txt_rPath.txt_rFile->Open(Append);
			txt_rPath.txt_rFile->WriteLine(NString("[") + strHandler + "] " + DateTime::NowTime() + " -> " + strLog);
			txt_rPath.txt_rFile->Close();
		}
		catch (std::exception* logEx)
		{
			if (countFail < MAXTRYLOG)
			{
				Error(logEx,10, false);
				countFail++;
			}
			else
			{
				Error::err_ForceQuit();
			}
		}
	}

	void Log::Write(NString strHandler, NString strLog, NFileName* filelog)
	{
		try
		{
			filelog->txt_rFile->Open(Append);
			filelog->txt_rFile->WriteLine(NString("[") + strHandler + "] " + DateTime::NowTime() + " -> " + strLog);
			filelog->txt_rFile->Close();
		}
		catch (std::exception* logEx)
		{
			if (countFail < MAXTRYLOG)
			{
				Error(logEx, 10, false);
				countFail++;
			}
			else
			{
				Error::err_ForceQuit();
			}
		}
	}