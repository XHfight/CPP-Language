#include "Date.h"


bool Date::operator==(const Date& d)
{
	return _year==d._year && _month==d._month && _day==d._day;
}

bool Date::operator<(const Date& d)
{
	if (_year < d._year)
	{
		return true;
	}
	else if (_year == d._year)
	{
		if (_month < d._month)
		{
			return true;
		}
		else if (_month == d._month)
		{
			if (_day < d._day)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

bool Date::operator<=(const Date& d)
{
	return  operator==(d) || operator<(d);
}

bool Date::operator>(const Date& d)
{
	if (_year > d._year)
	{
		return true;
	}
	else if (_year == d._year)
	{
		if (_month > d._month)
		{
			return true;
		}
		else if (_month == d._month)
		{
			if (_day > d._day)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
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
			del._day = DayOfMonth(del);

		}
		else
		{
			del._day = del._day-day;
			day = 0;
		}
	}
	return del;
}

Date Date::operator-=(int day)
{
	while (day > 0)
	{
		if (_month == 0)
		{
			_year--;
			_month = 12;
		}
		if (_day - day <= 0)
		{

			_month--;
			day -= _day;
			_day = DayOfMonth(*this);

		}
		else
		{
			_day -= day;
			day = 0;
		}
	}
	return *this;
}

Date& Date::operator++()
{
	if (_day == DayOfMonth(*this))
	{
		if (_month == 12)
		{
			_day = 1;
			_month = 1;
			_year++;
		}
		else
		{
			_month++;
			_day = 1;
		}
	}
	else
	{
		_day++;
	}
	return *this;
}

Date Date::operator++(int)
{
	Date ret(*this);
	if (_day == DayOfMonth(*this))
	{
		if (_month == 12)
		{
			_day = 1;
			_month = 1;
			_year++;
		}
		else
		{
			_month++;
			_day = 1;
		}
	}
	else
	{
		_day++;
	}
	return ret;
}

Date& Date::operator--()
{
	if (_day == 1)
	{
		if (_month == 1)
		{
			_year--;
			_month = 12;
			_day = 31;
		}
		else
		{
			_month--;
			_day = DayOfMonth(*this);
		}
	}
	else
	{
		_day--;
	}
	return *this;
}

Date Date::operator--(int)
{
	Date ret(*this);
	if (_day == 1)
	{
		if (_month == 1)
		{
			_year--;
			_month = 12;
			_day = 31;
		}
		else
		{
			_month--;
			_day = DayOfMonth(*this);
		}
	}
	else
	{
		_day--;
	}
	return ret;
}

int Date::operator-(const Date& d)
{
	int day = 0;

	Date small(d);
	Date big(*this);

	if (*this < d)
	{
		small = *this;
		big = d;
	}

	while (small._year < big._year)
	{
		if (IsLeap(small._year))
		{
			day += 366;
		}
		else
		{
			day += 365;
		}
		small._year++;
		while (small._month > big._month)
		{
			day -= DayOfMonth(small);
			small._month--;
		}
	}

	while (small._month < big._month)
	{
		day += DayOfMonth(small);
		small._month++;
	}
	day += (big._day - small._day);

	if (*this >= d)
		return day;
	else
		return 0-day;
}

bool Date::IsLeap(int year)   //检查该年是否为闰年
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

int Date::DayOfMonth(const Date& d)   //返回该月的天数
{
	int day[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	if(IsLeap(d._year))
	{
		day[2] = 29;
	}
	return day[d._month];
}





