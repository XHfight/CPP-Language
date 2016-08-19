/*

利用malloc/free和定位new表达式模拟实现new/delete和new[]/delete[]

*/

#include <iostream>
using namespace std;

class A
{
public:
	A(int a)
		:_a(a)
	{}

	~A()
	{}
private:
	int _a;
};
int main()
{
	//1.malloc/free + 定位操作符new()/显示调用析构函数，模拟 new和delete 的行为

	//new
	A* a1 = (A*)malloc(sizeof(A));
	new(a1) A(10);

	//delete
	a1->~A();
	free(a1);

	//2.malloc/free + 多次调用定位操作符new()/显示调用析构函数，模拟 new[]和delete[] 的行为	
	//new[size]
	A* a2 = (A *)malloc(sizeof(A) * 10+4); //A* a2 = new A[10];
	*(int*)a2 = 10;
	a2 = (A*)((int*)a2+1);
	for(int i = 0; i<10; i++)
	{
		new(a2+i) A(i);
	}
	
	//delete[]
	for(int i = 0; i< *((int*)a2-1); i++)
	{
		(a2+i)->~A();
	}
	free((int*)a2-1);
	return 0;

}