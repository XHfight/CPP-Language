#pragma once
#include <iostream>
using namespace std;

class Date
{
public:
	friend void PrintCalendar(int year, int month);  //��ӡ����
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
			cout << "�������ڲ��Ϸ�" << endl;
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
	//���ڼ�����
	Date operator+(int day);
	Date operator+=(int day);
	Date operator-(int day);
	Date operator-=(int day);
	Date& operator++();
	Date operator++(int);
	Date& operator--();
	Date operator--(int);

	int operator-(const Date& d);  //������������֮�����������

private:
	bool Illegal(); //��������Ƿ�Ƿ�
	void ChangeLegal(Date& date); //�����ڻ�Ϊ�Ϸ�����
	bool IsLeap(int year);//�������
	int DayOfMonth(int year, int month); //����������е��µ�����

private:
	int _year;
	int _month;
	int _day;

};

void PrintCalendar(int year, int month);  //��ӡ����
istream& operator>>(istream& is, Date& d);
ostream& operator<<(ostream& os, Date& d);