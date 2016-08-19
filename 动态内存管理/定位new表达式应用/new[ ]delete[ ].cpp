/*

����malloc/free�Ͷ�λnew���ʽģ��ʵ��new/delete��new[]/delete[]

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
	//1.malloc/free + ��λ������new()/��ʾ��������������ģ�� new��delete ����Ϊ

	//new
	A* a1 = (A*)malloc(sizeof(A));
	new(a1) A(10);

	//delete
	a1->~A();
	free(a1);

	//2.malloc/free + ��ε��ö�λ������new()/��ʾ��������������ģ�� new[]��delete[] ����Ϊ	
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