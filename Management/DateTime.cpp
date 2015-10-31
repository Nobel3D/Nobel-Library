#include "DateTime.h"
#include <ctime>

using namespace NobelLib::Management;
using namespace NobelLib;

DateTime::DateTime()
{
	time_t t = time(0);   // get time now
	struct tm * now = localtime(&t);
	this->Year = now->tm_year + 1900;
	this->Month = now->tm_mon + 1;
	this->Day = now->tm_mday;
	this->Hour = now->tm_hour + 1;
	this->Minute = now->tm_min;
	this->second = now->tm_sec;
}
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
DateTime::DateTime(int _second, int _Minute, int _Hour, int _Day, int _Month, int _Year)
{
	if (_Month<13 && _Month>0)
	{
		if (_Day <= daysOnMonth(_Month))
		{
			if (_Hour < 25 && _Hour > 0)
			{
				if (_Minute < 60 && _Minute > -1)
				{
					if (_second < 60 && _second > -1)
					{
						this->second = _second;
						this->Minute = _Minute;
						this->Hour = _Hour;
						this->Day = _Day;
						this->Month = _Month;
						this->Year = _Year;
					}
					/*I could report the errors mmh...*/
				}
			}
		}
	}
}
NobelLib::NString DateTime::NowTime()
{
	DateTime* Now = new DateTime();
	NString strRet(NString(NString::fromInt(Now->Day) + "/" +
		NString::fromInt(Now->Month) + "/" + NString::fromInt(Now->Year) +
		" <" + NString::fromInt(Now->Hour) + ":" + NString::fromInt(Now->Minute) +
		":" + NString::fromInt(Now->second) + "> "));
	delete[] Now;
	return strRet;
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
	addSecond(addme->second);
	addMinute(addme->Minute);
	addHour(addme->Hour);
	addDay(addme->Day);
	addMonth(addme->Month);
	addYear(addme->Year);

	return *this;
}

DateTime& DateTime::operator+(DateTime date_arg)
{
	return addDate(&date_arg);
}

void DateTime::addSecond(int addme)
{ 
	second + addme;

	if (second > 60)
	{
		this->second -= 60;
		addMinute(1);
	}
}
void DateTime::addMinute(int addme)
{
	Minute += addme;

	if (Minute > 60)
	{
		this->Minute -= 60;
		addHour(1);
	}
}
void DateTime::addHour(int addme) 
{
	Hour += addme;

	if (Hour > 25)
	{
		this->Hour -= 24;
		addDay(1);
	}
}
void DateTime::addDay(int addme) 
{
	Day += addme;

	if (Day > daysOnMonth(Month))
	{
		this->Day -= daysOnMonth(Month);
		addMonth(1);
	}
}

void DateTime::addMonth(int addme) 
{
	Month+= addme;

	if (Month > 12)
	{
		this->Month -= 12;
		addYear(1);
	}
}
void DateTime::addYear(int addme) 
{ 
	Year+=addme; 
}

int DateTime::getSecond() { return second; }
int DateTime::getMinute() { return Minute; }
int DateTime::getHour()   { return Hour; }
int DateTime::getDay()    { return Day; }
int DateTime::getMonth()  { return Month; }
int DateTime::getYear()   { return Year; }
