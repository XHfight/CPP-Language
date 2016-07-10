#pragma once
#include <iostream>
using namespace std;

class Date
{
	friend void PrintCalendar(int year, int month);
public:
	Date(int year = 1600, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
		if (month > 12 || day > DayOfMonth(*this))
		{
			cout << "�������ڲ��Ϸ�" << endl;
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

	void Display()
	{
		cout<<_year<<"��"<<_month<<"��"<<_day<<"��"<<endl;
	}

private:
	bool IsLeap(int year);//�������
	int DayOfMonth(const Date& d); //����������е��µ�����
private:
	int _year;
	int _month;
	int _day;

};

void PrintCalendar(int year, int month);  //��ӡ����