#pragma once
#include <iostream>
using namespace std;

template <class T>
class SharedPtr
{
public:
	SharedPtr(T* ptr)
		:_ptr(ptr)
		:_PCount(new int(1))
	{}
	SharedPtr(const SharedPtr<T>& shp)
		:_ptr(shp._ptr)
		,_PCount(shp._PCount)
	{
		++GetCount();
	}
	SharedPtr& operator=(const SharedPtr<T>& shp)
	{
		if(_ptr != shp._ptr)
		{
			Release();
			_ptr = shp._ptr;
			_PCount = shp._PCount;
			++GetCount();
		}
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
			delete _ptr;
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
};