#include "AutoPtr.h"

void TestAutoptr()
{
	AutoPtr<int> ap1(new int(1));
	AutoPtr<int> ap2(ap1);
	AutoPtr<int> ap3(new int(3));
	ap3 = ap2;

	AutoPtr<int> auto_pointer (new int);
   int * manual_pointer;

   *auto_pointer=10;

   manual_pointer = auto_pointer.release();

  cout << "manual_pointer points to " << *manual_pointer << "\n";
  // (auto_pointer is now null-pointer auto_ptr)

  delete manual_pointer; 

}

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
	TestAutoptr();
	//TestScopedPtr();
	system("pause");
	return 0;
}