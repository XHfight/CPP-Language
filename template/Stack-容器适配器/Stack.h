#pragma once
//#include "SeqList.hpp"
//#include <iostream>
//using namespace std;
#include <string>
template <class T, class Container = SeqList<T>>
class Stack
{
public:
	size_t Size() const
	{
		return _con.GetSize();
	}
	bool Empty()
	{
		if (_con.GetSize() == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	T& Top()
	{
		if (!Empty())
			return _con[_con.GetSize() - 1];

		else
			throw string("Õ»¿Õ");
	}
	void Push(const T& data)
	{
		_con.PushBack(data);
	}
	void Pop()
	{
		if (!Empty())
			_con.PopBack();
	}
protected:
	Container _con;
};