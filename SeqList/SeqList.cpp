#include "SeqList.h"
#include <cassert>

void SeqList::PushBack(DataType data)
{
	CheckCapacity();
	_data[_size] = data;
	_size++;
}
void SeqList::PushFront(DataType data)
{
	CheckCapacity();
	size_t cp = _size;
	while (cp)
	{
		_data[cp] = _data[cp - 1];
		cp--;
	}
	_data[cp] = data;
	_size++;
}
void SeqList::PopBack()
{
	_size--;
}

void SeqList::PopFront()
{
	for (size_t i = 1; i < _size; ++i)
	{
		_data[i - 1] = _data[i];
	}
	_size--;
}

void SeqList::CheckCapacity()
{
	if (_size >= _capacity)
	{
		size_t newCapacity = _capacity * 2 + 1;
		DataType* tmp = new DataType[newCapacity];
		memcpy(tmp, _data, _size*sizeof(DataType));
		delete[] _data;
		_data = tmp;
		_capacity = newCapacity;
	}
}

ostream& operator<<(ostream& os, const SeqList& list)
{
	for (size_t i = 0; i < list._size; ++i)
	{
		os << list._data[i] << " ";
	}
	return os;
}

void SeqList::Insert(size_t pos, DataType data)  //在pos前插入数据 pos为下标
{
	assert(pos <= _size);
	CheckCapacity();
	if (pos == _size)
	{
		_data[pos] = data;
	}
	else
	{
		for (size_t i = _size; i > pos; --i)
		{
			_data[i] = _data[i - 1];
		}
		_data[pos] = data;
	}
	_size++;
}

size_t SeqList::Find(DataType data)
{
	for (size_t i = 0; i < _size; ++i)
	{
		if (data == _data[i])
		{
			return i;
		}
	}
	return -1;
}

void SeqList::Erase(size_t pos)
{
	assert(pos < _size);
	for (size_t i = pos; i < _size-1; i++)
	{
		_data[i] = _data[i + 1];
	}
	--_size;
}

void SeqList::Remove(DataType data)
{
	size_t pos = Find(data);
	if (pos != -1)
	{
		Erase(pos);
	}
}

void SeqList::RemoveAll(DataType data)
{
	for (size_t i = 0; i < _size; ++i)
	{
		if (_data[i] == data)
		{
			Erase(i);
		}
	}
}

void SeqList::BubbleSort()
{
	for (int i = 0; i < _size - 1; ++i)
	{
		for (int j = 0; j < _size - 1 - i; ++j)
		{
			if (_data[j]>_data[j + 1])
			{
				DataType tmp = _data[j];
				_data[j] = _data[j + 1];
				_data[j + 1] = tmp;
			}
		}
	}
}
