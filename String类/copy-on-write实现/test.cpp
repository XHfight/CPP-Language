#include "String.h"

void test1()
{
	String s1("dsfad");
	String s2(s1);
	String s3;
	s3 = s1;
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
}

void test2()
{
	String s1("hello ");
	String s2(s1);

	cout << "s1:" << s1 << endl;
	s1[5] = 'a';
	cout << "s1:" << s1 << endl;

	cout << "s2:"<<s2 << endl;
	s2[5] = 'a';
	cout << "s2:"<<s2 << endl;
}

int main()
{
	//test1();
	test2();
	system("pause");
	return 0;
}