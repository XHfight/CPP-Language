//#include "AutoPtr.h"
//
//void TestAutoptr()
//{
//	AutoPtr<int> ap1(new int(1));
//	AutoPtr<int> ap2(ap1);
//	AutoPtr<int> ap3(new int(3));
//	ap3 = ap2;
//
//	AutoPtr<int> auto_pointer (new int);
//   int * manual_pointer;
//
//   *auto_pointer=10;
//
//   manual_pointer = auto_pointer.release();
//
//  cout << "manual_pointer points to " << *manual_pointer << "\n";
//  // (auto_pointer is now null-pointer auto_ptr)
//
//  delete manual_pointer; 
//
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

#include "SharedPtr.h"

struct FClose
{
	void operator()(void* ptr)
	{
		fclose((FILE*) ptr);
	}
};

void TestSharedptr()
{
	//SharedPtr<int> sp1(new int(1));

	//SharedPtr<int> sp2(sp1);
	//SharedPtr<int> sp3;
	//sp3 = sp1;


	SharedPtr<FILE,FClose> spf(fopen("test.txt", "r"), FClose());

}
int main()
{
	//TestAutoptr();
	//TestScopedPtr();
	TestSharedptr();
	system("pause");
	return 0;
}