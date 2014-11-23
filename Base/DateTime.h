#pragma once

#include "..\Definitions.h"

namespace NobelLib
{
	namespace Systems
	{
		class DateTime
		{
		private:
			LLINT millisecond;
			LLINT second;
			int Minute;
			int Day;
			int Month;
			int Year;

			int daysOnMonth(int _Month);
			DateTime& addDate(const DateTime* addme);

		public:
			DateTime(int _Day, int _Month, int _Year);
			DateTime(LLINT _millisecond, LLINT _second, int _Minute);

			int getDay();
			int getMonth();
			int getYears();

			DateTime& operator+ (DateTime date_arg);
		};
	}
}