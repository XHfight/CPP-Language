#include "SeqList.hpp"
#include <string>

void test1()
{
	/*SeqList<string> list1;
	list1.PushBack("def");
	list1.PushBack("ghi");
	list1.PushFront("abc");
	cout << list1 << endl;
	list1.PopFront();
	cout << list1 << endl;
	list1.PopBack();
	cout << list1 << endl;*/

	SeqList<int> list1;
	list1.PushBack(2);
	list1.PushBack(3);
	list1.PushFront(1);
	cout << list1 << endl;
	list1.PopFront();
	cout << list1 << endl;
	list1.PopBack();
	cout << list1 << endl;
}

void test2()
{
	SeqList<string> list1;
	list1.PushBack("def");
	list1.PushBack("ghi");
	list1.PushFront("abc");
	cout << list1 << endl;
	list1.Insert(3, "jkl");
	cout << list1 << endl;
	list1.Erease(3);
	cout << list1 << endl;
	list1.Erease(2);
	cout << list1 << endl;
//	list1.Erease(0);
//	cout << list1 << endl;
	list1.PushFront("xyz");
	cout << list1 << endl;
	list1.Sort();
	cout << list1 << endl;
	list1.PushFront("abc");
	list1.PushFront("abc");
	cout << list1 << endl;
	//list1.Remove("abc");
	cout << list1 << endl;
	list1.RemoveAll("abc");
	cout << list1 << endl;
	list1.Reserve(50);

}
int main()
{
	test2();

	system("pause");
	return 0;
}