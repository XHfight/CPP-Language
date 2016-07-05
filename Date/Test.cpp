#include <iostream>
#include "Date.h"
using namespace std;

int main()
{
	Date d1(1995, 6, 8);
	/*d1.Display();
	d1+=365;
	d1.Display();*/
	d1.Display();
	Date del = d1-8;
	del.Display();
	system("pause");
	return 0;
}