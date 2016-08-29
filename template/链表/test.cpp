#include "LinkList.hpp"

void test1()
{
	LinkList<int> l1;
	l1.PushBack(2);
	l1.PushBack(3);
	l1.PushBack(4);
	l1.PushFront(1);
	l1.PushBack(5);
	//LinkList<int> l2(l1);
	LinkList<int> l2;
	l2 = l1;
	cout << l1 << endl;
	cout << l2 << endl;
	l1.PopFront();
	cout << l1 << endl;
	l1.PopBack();
	cout << l1 << endl;
}

void test2()
{
	LinkList<int> l1;
	l1.PushBack(2);
	l1.PushBack(3);
	l1.PushBack(4);
	cout << l1.Empty() << endl;
	cout << l1.Front() - l1.Back() << endl;
}

int main()
{
	//test1();
	test2();
	system("pause");
	return 0;
}