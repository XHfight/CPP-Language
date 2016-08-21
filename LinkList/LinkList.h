#pragma once

#include <iostream>
using namespace std;

typedef int DataType;
struct Node
{
public:
	Node(DataType data = 0)
		:_data(data)
		, _next(NULL)
	{}
public:
	DataType _data;
	Node* _next;
};

class LinkList
{
	friend ostream& operator<< (ostream& os, const LinkList& list);
public:
	LinkList()
		:_head(NULL)
		, _tail(NULL)
	{}
	LinkList(const LinkList& list)
	{
		Node* cur = list._head;
		if (cur == NULL)
		{
			_head = NULL;
			_tail = NULL;
		}
		else
		{
			while (cur)
			{
				PushBack((*cur)._data);
				cur = cur->_next;
			}
		}
	}
	~LinkList()
	{
		if (_head != NULL)
		{
			Node* cur = _head;
			while (cur)
			{
				Node* del = cur;
				cur = cur->_next;
				delete del;
				del = NULL;
			}
			_head = NULL;
			_tail = NULL;
		}
	}
public:
	void PushBack(DataType data);
	void PushFront(DataType data);
	void PopBack();
	void PopFront();
	Node* Find(DataType data);
	void Insert(Node* pos,DataType data);
	void BubbleSort();

private:
	Node* BuyNode(DataType data);

private:
	Node* _head;
	Node* _tail;
};

ostream& operator<< (ostream& os, const LinkList& list);
