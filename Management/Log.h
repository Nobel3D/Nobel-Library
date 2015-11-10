#pragma once

#include "..\Base\NString.h"
#include "..\Stream\NFileName.h"
#include "..\Stream\NFile.h"

#define ENGINEHANDLER "NobelEngine"
#define DEFAULTHANDLER "NobelLibrary"

using namespace NobelLib::IO;

namespace NobelLib
{
	namespace Management
	{
		class Log
		{
		private:
			NFile* txt_rLog;
			static int countFail;
		public:
			/*Constructor of Log, it should be initializate on start of project*/
			Log(NFileName filePath);
			/*Write a log in this format:[strHandler] Date - Time -> strLog*/
			void Write(NString strHandler, NString strLog);
			/*Write a log without constructor in this format:[strHandler] Date - Time -> strLog*/
			static void Write(NString strHandler, NString strLog, NFileName filelog);

		};
	}
}