#include "SeqList.hpp"

#include <iostream>
using namespace std;

void test1()
{
	cout << TypeTraits<double>::IsPODType().Get() << endl;
	cout << TypeTraits<int>::IsPODType().Get() << endl;
}


void TestCopy()
{
	/*SeqList<int> s1;
	s1.PushBack(1);
	s1.PushBack(2);
	s1.PushBack(3);
	s1.PushBack(4);
	cout << s1 << endl;
	SeqList<int> s2(s1);
	cout << s2 << endl;
	*/

	SeqList<string> s1;
	s1.PushBack("sa");
	s1.PushBack("df");
	s1.PushBack("fdsg");
	s1.PushBack("gfsgw");
	cout << s1 << endl;
	SeqList<string> s2(s1);
	cout << s2 << endl;

}

int main()
{
	//test1();
	TestCopy();
	system("pause");
	return 0;
}