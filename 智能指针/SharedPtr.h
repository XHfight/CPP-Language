#pragma once
#include <iostream>
using namespace std;

struct DefaultDel
{
	void operator()(void *ptr)
	{
		delete ptr;
	}
};

template <class T,class D = DefaultDel>
class SharedPtr
{
public:
	SharedPtr(T* ptr = NULL, D& d = DefaultDel())
		:_ptr(ptr)
		,_PCount(new int(1))
		,_del(d)
	{}
	SharedPtr(const SharedPtr<T>& shp)
		:_ptr(shp._ptr)
		,_PCount(shp._PCount)
		,_del(shp._del)
	{
		++GetCount();
	}
	/*SharedPtr& operator=(const SharedPtr<T>& shp)
	{
		if(_ptr != shp._ptr)
		{
			Release();
			_ptr = shp._ptr;
			_PCount = shp._PCount;
			++GetCount();
		}
		return *this;
	}*/

	//现代版写法
	SharedPtr& operator=(SharedPtr sp)
	{
		swap(_ptr,sp._ptr);
		swap(_PCount,sp._PCount);
		return *this;
	}

	~SharedPtr()
	{
		Release();
	}
	T& operator*()const
	{
		assert(_ptr);
		return *_ptr;
	}
	T* operator->()const
	{
		assert(_ptr);
		return _ptr;
	}
	T* Get()const
	{
		return _ptr;
	}
private:
	void Release()
	{
		if(--GetCount() == 0)
		{
			_del(_ptr); //仿函数

			_ptr = NULL;
			delete _PCount;
			_PCount = NULL;
		}
	}
	int& GetCount()
	{
		return *(_PCount);
	}
private:
	T* _ptr;
	int* _PCount;
	D _del;
};