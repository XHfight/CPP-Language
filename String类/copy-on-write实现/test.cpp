#include "String.h"

void test1()
{
	String s1("sda");
	String s2(s1);
	String s3 = s1;
	cout << s1 <<endl;
	cout << s2 << endl;
	cout << s3 << endl;
}

int main()
{
	test1();
	system("pause");
	return 0;
}