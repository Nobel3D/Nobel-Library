#pragma once

#include "..\Definitions.h"
#include "NString.h"

namespace NobelLib
{
	namespace Sys
	{
		class DateTime
		{
		private:
			int second;
			int Minute;
			int Hour;
			int Day;
			int Month;
			int Year;

			int daysOnMonth(int _Month);
			DateTime& addDate(const DateTime* addme);

		public:
			/*NOW TIME*/
			DateTime();
			DateTime(int _Day, int _Month, int _Year);
			DateTime(int _second, int _Minute, int _Hour, int _Day, int _Month, int _Year);

			static NString NowTime();

			void addSecond(int addme);
			void addMinute(int addme);
			void addHour(int addme);
			void addDay(int addme);
			void addMonth(int addme);
			void addYear(int addme);

			int getSecond();
			int getMinute();
			int getHour();
			int getDay();
			int getMonth();
			int getYear();

			DateTime& operator+ (DateTime date_arg);
		};
	}
}