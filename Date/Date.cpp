#include "Date.h"

bool Date::operator==(const Date& d)
{
	return _year==d._year && _month==d._month && _day==d._day;
}
bool Date::operator!=(const Date& d)
{
	return !(*this == d);
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
	add._day += day;

	ChangeLegal(add);
	return add;
}

Date Date::operator+=(int day)
{
	_day += day;
	ChangeLegal(*this);
	return *this;
}

Date Date::operator-(int day)
{
	Date del(*this);
	del._day -= day;
	ChangeLegal(del);
	return del;
}

Date Date::operator-=(int day)
{
	_day -= day;
	ChangeLegal(*this);
	return *this;
}

Date& Date::operator++()
{
	_day++;
	ChangeLegal(*this);
	return *this;
}

Date Date::operator++(int)  //后置++，返回值没+1，其实本身已经+1
{
	Date ret(*this);
	_day++;
	ChangeLegal(*this);
	return ret;
}

Date& Date::operator--()
{
	_day--;
	ChangeLegal(*this);
	return *this;
}

Date Date::operator--(int)
{
	Date ret(*this);
	_day--;
	ChangeLegal(*this);
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
	else
	{
		small = d;
		big = *this;
	}

	while (small != big)
	{
		small++;
		day++;
	}
	return day;
}

bool Date::Illegal() //检查日期是否非法
{
	if ((_year<0) ||
		(_month<0 || _month>12) ||
		(_day<0 || _day>DayOfMonth(_year, _month)))
	{
		return true;
	}
	else
	{
		return false;
	}
}
void Date::ChangeLegal(Date& date) //将日期转为合法日期
{
	if (date._day < 1)
	{
		while (date._day < 1)
		{
			date._month--;
			date._day += DayOfMonth(date._year, date._month);
			if (date._month < 1)
			{
				date._year--;
				date._month = 12;
			}
		}
	}
	else if (date._day > DayOfMonth(date._year, date._month))
	{
		while (date._day > DayOfMonth(date._year, date._month))
		{
			date._day -= DayOfMonth(date._year, date._month);
			date._month++;
			if (date._month > 12)
			{
				date._year++;
				date._month = 1;
			}
		}
	}
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

int Date::DayOfMonth(int year, int month)   //返回该月的天数
{
	static int day[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	if(IsLeap(year) && month==2)
	{
		return 29;
	}
	return day[month];
}

int MonthOfOneDay(int year, int month) //计算当前月的第一天为星期几
{
	if ( (year > 1 ) && (month > 1 && month <12) )
	{
		int week = 1;//1.1.1  为周一
		int day = 0;
		Date d1(1,1,1);
		Date d2(year, month, 1);
		day = d2 - d1;
		week = day % 7 + week;
		if (week > 7)
		{
			week -= 7;
		}
		return week;
	}

}

void PrintCalendar(int year, int month) //打印当前月的日历
{
	cout << year << "年" << month << "月" << endl;
	cout << "日 " << "一 " << "二 " << "三 " << "四 " << "五 " << "六 " << endl;
	int week = MonthOfOneDay(year, month);
	if (week != -1)
	{
		Date d(year, month, 1);
		int day = 1;
		int i = 0;
		for (i = 0; i < week; i++)
		{
			cout << "   ";
		}
		for (int j = 0; j < 6; j++)
		{

			for (; i < 7; i++)
			{
				if (day <= d.DayOfMonth(d._year, d._month))
				{
					printf("%2d ", day);
					day++;
				}
				else
				{
					break;
				}
			}
			i = 0;
			cout << endl;
		}
	}
}

istream& operator>>(istream& is, Date& d)
{
	is >> d._year >> d._month >> d._day;
	return is;
}

ostream& operator<<(ostream& os, Date& d)
{
	os << d._year << "-" << d._month << "-" << d._day;
	return os;
}

