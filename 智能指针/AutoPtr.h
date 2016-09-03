#pragma once

#include <iostream>
using namespace std;

template <class T>
class AutoPtr
{
public:
	AutoPtr(T* ptr)
		:_ptr(ptr)
	{}

	AutoPtr(AutoPtr<T>& ap)
		:_ptr(ap._ptr)
	{
		ap._ptr = NULL;
	}

	~AutoPtr()
	{
		delete _ptr;
		_ptr = NULL;
	}

	T* get()
	{
		return _ptr;
	}

	T& operator*()
	{
		return *_ptr;
	}

	AutoPtr& operator=(AutoPtr<T>& ap)
	{
		if(ap._ptr != _ptr)
		{
			delete _ptr;
			_ptr = ap._ptr;
			ap._ptr = NULL;
		}
		return *this;
	}

	void* release()
	{
		return (void*)_ptr;
	}

	void reset(T* ptr)
	{
		_ptr = ptr;
	}

private:
	T* _ptr;
};