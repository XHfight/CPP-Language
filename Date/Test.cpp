#include <iostream>
#include "Date.h"

void fun1() //���ڼӼ�����
{
	Date date;
	int day;
	cout << "����������" << endl;
	cin >> date;
	cout << "������Ӽ����������������븺�����ɣ�" << endl;
	cin >> day;
	cout << date+day << endl;
}

void fun2() //�������������������
{
	Date d1;
	Date d2;
	cout << "�������һ������" << endl;
	cin >> d1;
	cout << "������ڶ�������" << endl;
	cin >> d2;
	cout << "�������Ϊ��" << d1-d2 << endl;
}

void fun3()
{
	int year = 0;
	int month = 0;
	cout << "������Ҫ��ӡ����ݺ��·�" << endl;
	cin >> year >> month;
	PrintCalendar(year, month);
}
void Print()
{
	cout << "*****************************" << endl;
	cout << "***��ѡ����Ҫʹ�õĹ��ܣ�" << endl;
	cout << "***1. ���ڼӼ�����" << endl;
	cout << "***2. �������������������" << endl;
	cout << "***3. ��ӡĳ��ĳ�µ�����" << endl;
	cout << "***0. �˳�" << endl;
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
			cout << "������������������" << endl;
			break;
		}
	}
}

int main()
{
	Menu();
	return 0;
}

