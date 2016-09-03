//#include "AutoPtr.h"
//
//void TestAutoptr()
//{
//	AutoPtr<int> ap1(new int(1));
//	AutoPtr<int> ap2(ap1);
//	AutoPtr<int> ap3(new int(3));
//	ap3 = ap2;
//}

//struct A
//{
//	int a;
//};
//
//#include "ScopedPtr.h"
//void TestScopedPtr()
//{
//	
//
//	ScopedPtr<int> sp1(new int(1));
//	//ScopedPtr<int> sp2(sp1);
//	ScopedPtr<A> sp_a(new A);
//	sp_a->a = 10;
//	cout<<*(sp1)<<endl;
//}



int main()
{
	//TestAutoptr();
	//TestScopedPtr();
	system("pause");
	return 0;
}