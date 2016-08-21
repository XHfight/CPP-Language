#include "LinkList.h"

void LinkList::PushBack(DataType data)
{
	Node* node = BuyNode(data);
	if (_tail == NULL)
	{
		_head = node;
		_tail = node;
	}
	else
	{
		_tail->_next = node;
		_tail = _tail->_next;
	}
}


void LinkList::PushFront(DataType data)
{
	Node* node = BuyNode(data);
	if (_head == NULL)
	{
		_head = node;
		_tail = node;
	}
	else
	{
		node->_next = _head;
		_head = node;
	}
}
void LinkList::PopBack()
{
	if (_head != NULL)  //链表不空
	{
		if (_head == _tail) //只有一个结点
		{
			delete _head;
			_head = NULL;
			_tail = NULL;
		}
		else
		{
			Node* prev = _head;
			while (prev->_next != _tail)
			{
				prev = prev->_next;
			}
			delete _tail;
			_tail = prev;
			_tail->_next = NULL;
		}
	}
}
void LinkList::PopFront()
{
	if (_head != NULL)
	{
		if (_head == _tail)
		{
			delete _head;
			_head = NULL;
			_tail = NULL;
		}
		else
		{
			Node* del = _head;
			_head = _head->_next;
			delete del;
			del = NULL;
		}
	}
}

Node* LinkList::BuyNode(DataType data)
{
	return new Node(data);
}

ostream& operator<< (ostream& os, const LinkList& list)
{
	Node* cur = list._head;
	while (cur)
	{
		os << (*cur)._data << " ";
		cur = cur->_next;
	}
	return os;
}

Node* LinkList::Find(DataType data)
{
	Node* cur = _head;
	while (cur)
	{
		if ((*cur)._data == data)
		{
			return cur;
		}
		cur = cur->_next;
	}
	return NULL;
}

void LinkList::Insert(Node* pos, DataType data)
{
	Node* node = BuyNode(data);

	if (pos != NULL)
	{
		Node* tmp = pos->_next;
		pos->_next = node;
		node->_next = tmp;
		if (tmp == NULL) //最后一个节点后插入
		{
			_tail = node;
		}

	}
	else
	{
		_head = node;
		_tail = node;
	}
}
void LinkList::BubbleSort()
{
	Node* cur = _head;
	while (cur != _tail)
	{
		Node* cp = cur;
		while (cp->_next != NULL)
		{
			if (cp->_data > cp->_next->_data)
			{
				DataType tmp = cp->_data;
				cp->_data = cp->_next->_data;
				cp->_next->_data = tmp;
			}
			cp = cp->_next;
		}
		cur = cur->_next;
	}
}
