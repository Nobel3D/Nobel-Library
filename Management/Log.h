#pragma once

#include "..\Base\NString.h"
#include "..\Stream\NFileName.h"

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
			NFileName txt_rPath;
			static int countFail;
		public:
			/*Constructor of Log, it should be initializate on start of project*/
			Log(NFileName filePath);
			/*Write a log in this format:[strHandler] Date - Time -> strLog*/
			void Write(NString strHandler, NString strLog);
			/*Write a log without constructor in this format:[strHandler] Date - Time -> strLog*/
			static void Write(NString strHandler, NString strLog, NFileName* filelog);

		};
	}
}