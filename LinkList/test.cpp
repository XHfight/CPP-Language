#include "LinkList.h"

void test1()
{
	LinkList list;
	list.PushBack(1);
	list.PushBack(2);
	list.PushBack(3);
	list.PushBack(4);
	cout << list << endl;
	LinkList l2(list);
	cout << l2 << endl;
	list.PushFront(0);
	cout << list << endl;

}
void test2()
{
	LinkList list;
	list.PushBack(1);
	list.PushBack(2);
	list.PushBack(3);
	list.PushBack(4);
	cout << list << endl;
	list.PopBack();
	cout << list << endl;
	list.PopFront();
	cout << list << endl;

}

void test3()
{
	LinkList list;
	list.PushBack(1);
	list.PushBack(2);
	list.PushBack(3);
	list.PushBack(4);
	cout << list << endl;
	list.Insert(list.Find(1), 2);
	cout << list << endl;
	list.Insert(list.Find(4), 5);
	cout << list << endl;
}

void test4()
{
	LinkList list;
	list.PushBack(4);
	list.PushBack(1);
	list.PushBack(3);
	list.PushBack(2);
	cout << list << endl;
	list.BubbleSort();
	cout << list << endl;

}
int main()
{
	//test1();
	//test2();
	//test3();
	test4();
	system("pause");
	return 0;
}