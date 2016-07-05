#include "Date.h"


bool Date::operator==(const Date& d)
{
	return _year==d._year && _month==d._month && _day==d._day;
}

bool Date::operator<(const Date& d)
{
	return _year<d._year || _month<d._month || _day<d._month;
}

bool Date::operator<=(const Date& d)
{
	return  operator==(d) || operator<(d);
}

bool Date::operator>(const Date& d)
{
	return _year>d._year || _month>d._month || _day>d._day;
}

bool Date::operator>=(const Date& d)
{
	return  operator==(d) || operator>(d);	
}

Date& Date::operator=(const Date& d)
{
	if(*this == d)
	{
		return *this;
	}
	_year = d._year;
	_month = d._month;
	_day = d._day;
	return *this;
}

Date Date::operator+(int day)
{
	Date add(*this);
	while(day > 0)
	{
		if(add._month == 13)
		{
			add._year++;
			add._month = 1;
		}
		if(add._day+day>DayOfMonth(*this))
		{
			day = day - (DayOfMonth(add)- add._day);
			add._month++;
			add._day = 0;
		}
		else
		{
			add._day+=day;
			day = 0;
		}
	}
	return add;
}

Date Date::operator+=(int day)
{
	while(day > 0)
	{
		if(_month == 13)
		{
			_year++;
			_month = 1;
		}
		if(_day+day>DayOfMonth(*this))
		{
			day = day - (DayOfMonth(*this)- _day);
			_month++;
			_day = 0;
		}
		else
		{
			_day+=day;
			day = 0;
		}
	}
	return *this;
}

Date Date::operator-(int day)
{
	Date del(*this);
	while(day > 0)
	{
		if(del._month == 0)
		{
			del._year--;
			del._month = 12;
		}
		if(del._day-day <= 0)
		{

			del._month--;
			day-=del._day;
			del._day = DayOfMonth(del._month);

		}
		else
		{
			del._day = del._day-day;
			day = 0;
		}
	}
	return del;
}

bool Date::IsLeap(int year)
{
	if(year%400 == 0)
		return true;
	else 
	{
		if(year%4==0 && year%100!=0)
			return true;
		else
			return false;
	}
}

int Date::DayOfMonth(const Date& d)
{
	int day[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	if(IsLeap(d._year))
	{
		day[2] = 29;
	}
	return day[d._month];
}





