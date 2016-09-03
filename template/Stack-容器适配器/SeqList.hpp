#pragma once
#include <iostream>
#include <cassert>
using namespace std;

template<typename T>
class SeqList
{
	template<typename S> //注意，必须加
	friend ostream& operator<<(ostream& os, const SeqList<S>& list);
public:
	SeqList()
		:_data(new T[2])
		, _capacity(2)
		, _size(0)
	{}
	SeqList(const SeqList& seq)
		:_data(new T[seq._capacity])
		, _capacity(seq._capacity)
		,_size(seq._size)
	{
		//不能用memcpy，对于非内置类型，可能出现浅拷贝问题。
		for (size_t i = 0; i < _size; i++)
		{
			_data[i] = seq._data[i];
		}
	}
	~SeqList()
	{
		if (_data != NULL)
		{
			delete[] _data;
			_data = NULL;
			_capacity = 0;
			_size = 0;
		}
	}
public:
	void PushBack(const T& data);
	void PushFront(const T& data);
	void PopBack();
	void PopFront();
	void Reserve(size_t n);
	void Sort();
	void Insert(size_t pos, const T& data);
	void Remove(const T& data);
	void RemoveAll(const T& data);
	void Erease(size_t pos);
	size_t GetSize() const;
	T& operator[](size_t index) const;
private:
	void CheckCapacity();
private:
	T* _data;
	size_t _capacity;
	size_t _size;
};

template<typename T>
ostream& operator<<(ostream& os, const SeqList<T>& list)
{
	for (size_t i = 0; i < list._size; ++i)
	{
		os << list._data[i] << " ";
	}
	return os;
}

template<typename T>
void SeqList<T>::PushBack(const T& data)
{
	CheckCapacity();
	_data[_size] = data;
	_size++;
}
template <typename T>
void SeqList<T>::PushFront(const T& data)
{
	CheckCapacity();
	int i = _size - 1;
	while (i >= 0)
	{
		_data[i + 1] = _data[i];
		i--;
	}
	_data[0] = data;
	_size++;
}
template<typename T>
void SeqList<T>::PopBack()
{
	_size--;
}
template<typename T>
void SeqList<T>::PopFront()
{
	for (size_t i = 1; i < _size; i++)
	{
		_data[i - 1] = _data[i];
	}
	_size--;
}
template <typename T>
void SeqList<T>::Reserve(size_t n)
{
	if (_capacity < n)
	{
		T* tmp = new T[n];
		for (int i = 0; i < _size; i++)
		{
			tmp[i] = _data[i];
		}
		delete[] _data;
		_data = tmp;
		_capacity = n;
	}
}
template<typename T>
void SeqList<T>::CheckCapacity()
{
	if (_size >= _capacity)
	{
		int newCapacity = _capacity * 2 + 1;
		T* tmp = new T[newCapacity];
		for (size_t i = 0; i < _size; i++)
		{
			tmp[i] = _data[i];
		}
		delete[] _data;
		_data = tmp;
		_capacity = newCapacity;
	}
}
template<typename T>
void SeqList<T>::Sort()
{
	//选择排序

	for (size_t i = 0; i < _size; i++)
	{
		size_t min = i;
		for (size_t j = i; j < _size-1; j++)
		{
			if (_data[j]>_data[j + 1])
				min = j + 1;
		}
		T tmp = _data[i];
		_data[i] = _data[min];
		_data[min] = tmp;
	}
}
template<typename T>
void SeqList<T>::Insert(size_t pos, const T& data)
{
	assert(pos <= _size);
	CheckCapacity();
	for (size_t i = _size - 1; i >= pos; i--)
	{
		_data[i + 1] = _data[i];
	}
	_data[pos] = data;
	_size++;
}
template<typename T>
void SeqList<T>::Remove(const T& data)
{
	for (size_t i = 0; i < _size; ++i)
	{
		if (_data[i] == data)
		{
			Erease(i);
			return;
		}
	}
}
template<typename T>
void SeqList<T>::Erease(size_t pos)
{
	assert(pos < _size);
	if (pos != _size-1)
	{
		for (size_t i = pos + 1; i < _size; i++)
		{
			_data[i - 1] = _data[i];
		}
	}
	--_size;
}

template<typename T>
void SeqList<T>::RemoveAll(const T& data)
{
	for (size_t i = 0; i < _size;)
	{
		//注意：当出现连续的要删除的数据时，下次判断一定要判断刚刚删除的那个下标的元素
		if (_data[i] == data)
		{
			Erease(i);
		}
		else
		{
			i++;
		}
	}
}

template <class T>
size_t SeqList<T>::GetSize() const
{
	return _size;
}
template<class T>
T& SeqList<T>::operator[](size_t index) const
{
	return _data[index];
}
