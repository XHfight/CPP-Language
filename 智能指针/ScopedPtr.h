#pragma once
#include <iostream>
#include <cassert>
using namespace std;

template <class T>
class ScopedPtr
{
public:
	explicit ScopedPtr(T* ptr = 0)
		:_ptr(ptr)
	{}
	~ScopedPtr()
	{
		delete _ptr;
		_ptr = NULL;
	}
	T& operator*() const
	{
		assert(_ptr);
		return *_ptr;
	}
	T* operator->() const
	{
		assert(_ptr);
		return _ptr;
	}
	T* Get()
	{
		return _ptr;
	}

private:
	ScopedPtr(const ScopedPtr<T>& sp);
	ScopedPtr& operator=(const ScopedPtr<T>& sp);
private:
	T* _ptr;
};