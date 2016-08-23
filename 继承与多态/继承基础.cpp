#include <iostream>
using namespace std;

//静态成员与继承
class Base
{
public:
	Base()
	{
		_count++;
	}
	void Show()
	{
		cout << _count << endl;
	}
protected:
	static int _count;
};
int Base::_count = 0;

class Derive:public Base
{
public:
	Derive()
	{
		_count++;
	}
	void Show()
	{
		cout << _count << endl;
	}
};

int main()
{
	Base b;
	Derive d;
	b.Show();
	d.Show();
	system("pause");
	return 0;
}
//虚析构函数
//class Base
//{
//public:
//	Base()
//	{
//		cout << "Base()" << endl;
//
//	}
//	~Base()
//	{
//		cout << "~Base()" << endl;
//	}
//};
//class Derive:public Base
//{
//public:
//	Derive()
//		:_pi(new int(1))
//	{}
//
//	~Derive()
//	{
//		delete _pi;
//		cout << "Derive()" << endl;
//	}
//protected:
//	int* _pi;
//};
//int main()
//{
//	{
//		Derive d;
//		Base* pb = &d;
//	}
//	system("pause");
//	return 0;
//}

//动态多态
//class Book
//{
//public:
//	void ShowPrice()
//	{
//		cout << "全价" << endl;
//	}
//};
//
//class BarginBook :public Book
//{
//public:
//	void ShowPrice()
//	{
//		cout << "半价" << endl;
//	}
//};
//
//int main()
//{
//	BarginBook barginbook;
//	Book* pbook = &barginbook;
//	pbook->ShowPrice();
//
//	Book book;
//	pbook = &book;
//	pbook->ShowPrice();
//
//	system("pause");
//	return 0;
//}

//虚继承
//
//class A
//{
//public:
//	A()
//		:_a(1)
//	{}
//protected:
//	int _a;
//};
//class B : virtual public  A //也可以写为class B:public virtual B
//{
//public:
//	B()
//		:_b(2)
//	{}
//private:
//	int _b;
//};
//class C :  virtual public A
//{
//public:
//	C()
//		:_c(3)
//	{}
//private:
//	int _c;
//};
//class D : public B,  public C
//{
//public:
//	D()
//		:_d(4)
//	{}
//private:
//	int _d;
//};
//int main()
//{
//	D d;
//	system("pause");
//	return 0;
//}