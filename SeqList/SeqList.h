#pragma once
#include <iostream>
using namespace std;

typedef int DataType;
class SeqList
{

	friend ostream& operator<<(ostream& os, const SeqList& list);
public:
	SeqList()
		:_data(NULL)
		, _size(0)
		, _capacity(0)
	{}

	SeqList(const SeqList& list)
		:_data(new DataType[list._capacity])
		, _size(list._size)
		, _capacity(list._capacity)
	{
		memcpy(_data, list._data, _size*sizeof(DataType));
	}

	~SeqList()
	{
		if (_data != NULL)
		{
			delete[] _data;
			_data = NULL;
			_size = 0;
			_capacity = 0;
		}
	}
public:
	void PushBack(DataType data);
	void PushFront(DataType data);
	void PopBack();
	void PopFront();
	void Insert(size_t pos, DataType data);
	size_t Find(DataType data);
	void Erase(size_t pos);
	void Remove(DataType data);
	void RemoveAll(DataType data);
	void BubbleSort();
private:
	void CheckCapacity();

private:
	DataType* _data;
	size_t _size;
	size_t _capacity;
};

ostream& operator<<(ostream& os, const SeqList& list);
