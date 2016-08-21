#include "SeqList.h"

void test1()
{
	SeqList list1;
	list1.PushBack(1);
	list1.PushBack(2);
	list1.PushBack(3);
	list1.PushBack(4);
	list1.PushFront(0);
	list1.PopBack();
	list1.PopFront();
	SeqList list2(list1);
	cout << list1 << endl;
	cout << list2 << endl;
}

void test2()
{
	SeqList list1;
	list1.PushBack(1);
	list1.PushBack(2);
	list1.PushBack(3);
	list1.PushBack(4);
	list1.Insert(0, 0);//第一个参数为下标
	list1.Insert(5, 5);
	list1.Insert(2, 6);
	cout << list1 << endl;

}

void test3()
{
	SeqList list1;
	list1.PushBack(1);
	list1.PushBack(2);
	list1.PushBack(3);
	list1.PushBack(4);
	//int f = list1.Find(5);

	int f = list1.Find(4);
	if (f == -1)
	{
		cout << "No find" << endl;
	}
	else
	{
		cout << "find" << endl;
	}
	cout << list1 << endl;
	list1.Erase(0);  //参数为下标
	cout << list1 << endl;
	list1.Erase(2);
	cout << list1 << endl;

}

void test4()
{
	SeqList list1;
	list1.PushBack(2);
	list1.PushBack(1);
	list1.PushBack(2);
	list1.PushBack(3);
	list1.PushBack(2);
	list1.PushBack(4);
	list1.PushBack(2);

	cout << list1 << endl;
	list1.Remove(2);
	cout << list1 << endl;
	list1.RemoveAll(2);
	cout << list1 << endl;
}

void test5()
{
	SeqList list1;
	list1.PushBack(10);
	list1.PushBack(7);
	list1.PushBack(8);
	list1.PushBack(2);
	list1.PushBack(4);
	list1.PushBack(9);
	list1.PushBack(6);
	list1.PushBack(1);
	list1.PushBack(5);
	cout << list1 << endl;
	list1.BubbleSort();
	cout << list1 << endl;

}
int main()
{
//	test1();
//	test2();
//	test3();
//	test4();
	test5();
	system("pause");
	return 0;
}