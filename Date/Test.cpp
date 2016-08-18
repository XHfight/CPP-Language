#include <iostream>
#include "Date.h"

void fun1() //日期加减天数
{
	Date date;
	int day;
	cout << "请输入日期" << endl;
	cin >> date;
	cout << "请输入加减的天数（减法输入负数即可）" << endl;
	cin >> day;
	cout << date+day << endl;
}

void fun2() //计算两个日期相差天数
{
	Date d1;
	Date d2;
	cout << "请输入第一个日期" << endl;
	cin >> d1;
	cout << "请输入第二个日期" << endl;
	cin >> d2;
	cout << "相差天数为：" << d1-d2 << endl;
}

void fun3()
{
	int year = 0;
	int month = 0;
	cout << "请输入要打印的年份和月份" << endl;
	cin >> year >> month;
	PrintCalendar(year, month);
}
void Print()
{
	cout << "*****************************" << endl;
	cout << "***请选择您要使用的功能：" << endl;
	cout << "***1. 日期加减天数" << endl;
	cout << "***2. 计算两个日期相差天数" << endl;
	cout << "***3. 打印某年某月的日历" << endl;
	cout << "***0. 退出" << endl;
	cout << "*****************************" << endl;

}

void Menu()
{
	while (1)
	{
		Print();
		int choose = 0;
		cin >> choose;
		switch (choose)
		{
		case 1:
			fun1();
			break;
		case 2:
			fun2();
			break;
		case 3:
			fun3();
			break;
		case 0:
			exit(EXIT_SUCCESS);
			break;
		default:
			cout << "输入有误，请重新输入" << endl;
			break;
		}
	}
}

int main()
{
	Menu();
	return 0;
}

