#ifndef __DATE_H__
#define __DATE_H__

#include<iostream>
using namespace std;

class Date
{
public:
	Date(int y, int m, int d);

	Date operator+ (int day);
	Date operator+= (int day);

	Date operator- (int day);
	Date operator-= (int day);

	Date operator++ ();
	Date operator++ (int);

	Date operator-- ();
	Date operator-- (int);

	int operator-(const Date& d);
private:
	bool IsLeapYear(int year)
	{
		if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		{
			return true;
		}
		return false;
	}
	int GetMonthDay(int year, int month)
	{
		int MonthArray[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

		if(month == 2 && IsLeapYear(year))
		{
			return 29;
		}
		else
		{
			return MonthArray[month - 1];
		}
	}
private:

	int year;
	int month;
	int day;
}

#endif