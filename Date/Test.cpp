#include <iostream>
#include "Date.h"
using namespace std;

void Test1()  // +  +=
{
	Date d1(2000, 2, 29);
	d1.Display();
//	d1+=365;
//	d1.Display();
}

void Test2()  // -   -=
{
	Date d1(1995, 6, 8);
	d1 -= 8;
	d1.Display();
}

void Test3() //++  ++(int)
{
//	Date d(2000, 12, 31);
	Date d(2000, 5, 31);
//	++d;
	d++.Display();
	d.Display();
}

void Test4()   //-- --(int)
{
//	Date d(2016, 1, 1);
//	Date d(2016, 5, 31);
	Date d(2015, 3, 1);

//	--d;
	d--.Display();
	d.Display();
}

void Test5()
{
	int day = 0;

	//Date d1(2016, 2, 16);
	//Date d2(2016, 2, 28);
	//day = d1 - d2;

	//Date d1(2016, 3, 26);
	//Date d2(2016, 2, 28);
	//day = d1 - d2;

	Date d1(2016, 2, 16);
	Date d2(2015, 2, 12);
	day = d1 - d2;

	cout << day << endl;
}

int main()
{
//	Test1();
//	Test2();
//	Test3();
//	Test4();
	Test5();
	system("pause");
	return 0;
}