#include "SeqList.hpp"
#include "Stack.h"


#include <stack>
void test_stack()
{
	stack<int> s1;
	s1.push(1);
	s1.push(2);
	s1.push(3);
	s1.push(4);
	cout << s1.size() << endl;
	cout << s1.empty() << endl;
	cout << s1.top()<< endl;

}
void test1()
{
	Stack<int, SeqList<int>> s1;
	s1.Push(1);
	s1.Push(2);
	s1.Push(3);
	s1.Push(4);
	cout << s1.Size() << endl;
	cout << s1.Top() << endl;
	s1.Pop();
	cout << s1.Size() << endl;
	cout << s1.Top() << endl;
	cout << s1.Empty() << endl;

	//s1.Pop();
	//s1.Pop();
	//s1.Pop();
	cout << s1.Empty() << endl;
	Stack<int, SeqList<int>> s2(s1);
	cout << s2.Size() << endl;
	try{
		cout << s2.Top() << endl;
	}
	catch (string e)
	{
		cout << e << endl;
	}

}
int main()
{
	//test_stack();
	test1();
	system("pause");
	return 0;
}