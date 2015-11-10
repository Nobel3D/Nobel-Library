#include "Log.h"
#include "Error.h"
#include "..\Management\DateTime.h"

using namespace NobelLib;
using namespace NobelLib::Management;
using namespace NobelLib::IO;

int Log::countFail = 0;

	Log::Log(NFileName filePath)
	{
		txt_rLog = new NFile(filePath);
	}
	void Log::Write(NString strHandler, NString strLog)
	{
		try
		{
			txt_rLog->Open(Append);
			txt_rLog->WriteLine(NString("[") + strHandler + "] " + DateTime::NowTime() + " -> " + strLog);
			txt_rLog->Close();
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

	void Log::Write(NString strHandler, NString strLog, NFileName filelog)
	{
		try
		{
			NFile* txtLog = new NFile(filelog);
			txtLog->Open(Append);
			txtLog->WriteLine(NString("[") + strHandler + "] " + DateTime::NowTime() + " -> " + strLog);
			txtLog->Close();
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