#include "String.h"

void test1()
{
	String s1;
	String s2("abcdef");
	String s3(s2);
	String s4;
	s4 = s2;
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;

}
void test2()
{
	String s1("hello worl");
	s1.push_back('d');
	cout << s1 <<endl;
}

void test3()
{
	//String& String::operator+= ( const String& str );
	String s2("hello");
	String s3(" world");
	s2 += s3;
	cout << s2 <<endl;
	//String& String::operator+= ( const char* s )
	String s4("hello");
	s4 += " world";
	cout << s4 << endl;
	//String& String::operator+= ( char c )
	s4 += 'a';
	cout << s4 << endl;

}


int main()
{
	test3();
	system("pause");
	return 0;
}