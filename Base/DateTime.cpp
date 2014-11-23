#include "DateTime.h"

using namespace NobelLib::Systems;

DateTime::DateTime(int _Day, int _Month, int _Year)
{
	if (_Month<13 && _Month>0)
	{
		if (_Day <= daysOnMonth(_Month))
		{
			this->Day = _Day;
			this->Month = _Month;
			this->Year = _Year;
		}
	}
}

int DateTime::daysOnMonth(int month)
{
	//Puoi mettere una cosa tipo:
	switch (month)
	{
	case 4: case 6: case 9: case 11: return 30;
	case 2: return 28;
	default: return 31;
	}
}

DateTime& DateTime::addDate(const DateTime* addme)
{
	int dateDay;
	int dateMonth;
	int dateYear;

	dateDay = this->Day + addme->Day;
	dateMonth = this->Month + addme->Month;
	dateYear = this->Year + addme->Year;

	if (dateMonth>12)
	{
		dateMonth -= 12;
		dateYear++;
	}

	if (dateDay > daysOnMonth(dateMonth))
	{
		dateDay -= daysOnMonth(dateMonth);
		dateMonth++;

		if (dateMonth < 12)
		{
			this->Month -= 12;
			this->Year++;
		}
	}
	DateTime date_ret(dateDay, dateMonth, dateYear);

	return date_ret;
}

DateTime& DateTime::operator+(DateTime date_arg)
{
	return addDate(&date_arg);
}

int DateTime::getDay() { return Day; }
int DateTime::getMonth() { return Month; }
int DateTime::getYears() { return Year; }
