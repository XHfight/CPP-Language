#pragma once
#include <iostream>
using namespace std;

class Date
{
public:
	friend void PrintCalendar(int year, int month);  //打印日历
	friend istream& operator>>(istream& is, Date& d);
	friend ostream& operator<<(ostream& os, Date& d);
public:
	Date(int year = 1600, int month = 1, int day = 1)
		:_year(year)
		,_month(month)
		, _day(day)
	{
		if (Illegal())
		{
			cout << "输入日期不合法" << endl;
			_year = 1600;
			_month = 1;
			_day = 1;
		}
	}

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	Date& operator=(const Date& d);

public:
	bool operator==(const Date& d);
	bool operator!=(const Date& d);
	bool operator<(const Date& d);
	bool operator<=(const Date& d);
	bool operator>(const Date& d);
	bool operator>=(const Date& d);
	//日期计算器
	Date operator+(int day);
	Date operator+=(int day);
	Date operator-(int day);
	Date operator-=(int day);
	Date& operator++();
	Date operator++(int);
	Date& operator--();
	Date operator--(int);

	int operator-(const Date& d);  //计算两个日期之间相隔的天数

private:
	bool Illegal(); //检查日期是否非法
	void ChangeLegal(Date& date); //将日期化为合法日期
	bool IsLeap(int year);//检查闰年
	int DayOfMonth(int year, int month); //计算该日期中当月的天数

private:
	int _year;
	int _month;
	int _day;

};

void PrintCalendar(int year, int month);  //打印日历
istream& operator>>(istream& is, Date& d);
ostream& operator<<(ostream& os, Date& d);