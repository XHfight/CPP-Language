#pragma once
#include <iostream>
using namespace std;

template <class T>
struct Node
{
	Node(const T& data)
	:_data(data)
	, _next(0)
	{}

	T _data;
	Node<T>* _next;
};

template <class T>
class LinkList
{
	friend ostream& operator<<(ostream& os, const LinkList<T>& l)
	{
		Node<T>* cur = l._head;
		while (cur)
		{
			os << cur->_data << " ";
			cur = cur->_next;
		}
		return os;
	}
public:
	LinkList()
		:_head(0)
		, _tail(0)
	{}

	LinkList(const LinkList& l)
		:_head(0)
		, _tail(0)
	{
		Node<T>* cur = l._head;
		while (cur)
		{
			PushBack(cur->_data);
			cur = cur->_next;
		}
	}

	//�ִ�д�������������ʱ��ѹջ������
	/*LinkList& operator=(LinkList l)
	{
		swap(_head, l._head);
		swap(_tail, l._tail);
		return *this;
	}*/
	LinkList& operator=(const LinkList& l)
	{
		if (this != &l)
		{
			//���ͷ�ԭ������
			Node<T>* cur = _head;
			while (cur)
			{
				Node<T>* del = cur;
				cur = cur->_next;
				delete del;
				del = NULL;
			}
			_head = NULL;
			_tail = NULL;

			//��l����ֵ����ǰ����
			cur = l._head;
			while (cur)
			{
				PushBack(cur->_data);
				cur = cur->_next;
			}
		}
		return *this;
	}

	~LinkList()
	{
		Node<T>* cur = _head;
		while (cur)
		{
			Node<T>* del = cur;
			cur = cur->_next;
			delete del;
			del = NULL;
		}
		_head = NULL;
		_tail = NULL;
	}

public:
	void PushBack(const T& data);
	void PushFront(const T& data);
	void PopBack();
	void PopFront();
	bool Empty();
	const T& Front() const;
	const T& Back() const;

	void Insert(Node<T>* pos, T data);
	void Erase(Node<T>* pos);
	void Swap(LinkList& l);
	void Clear();
	Node<T>* find(const T& data);
private:
	Node<T>* _head;
	Node<T>* _tail;

};

template <class T>
void LinkList<T>::PushBack(const T& data)
{
	Node<T>* newNode = new Node<T>(data);
	if (_head == NULL)
	{
		_head = newNode;
		_tail = newNode;
	}
	else
	{
		_tail->_next = newNode;
		_tail = _tail->_next;
	}
}

template <class T>
void LinkList<T>::PushFront(const T& data)
{
	Node<T>* newNode = new Node<T>(data);
	if (_head == NULL)
	{
		_head = newNode;
		_tail = newNode;
	}
	else
	{
		newNode->_next = _head;
		_head = newNode;
	}
}

template <class T>
void LinkList<T>::PopBack()
{
	if (_head != NULL)
	{
		if (_head->_next == NULL)
		{
			delete _tail;
			_head = NULL;
			_tail = NULL;
		}
		else
		{
			Node<T>* cur = _head;
			while (cur->_next != _tail)
			{
				cur = cur->_next;
			}
			delete _tail;
			_tail = cur;
			_tail->_next = NULL; //βָ���nextָ��һ��Ҫ��Ϊ��
		}
	}
}

template <class T>
void LinkList<T>::PopFront()
{
	if (_head != NULL)
	{
		if (_head->_next == NULL)
		{
			delete _head;
			_head = NULL;
			_tail = NULL;
		}
		else
		{
			Node<T>* del = _head;
			_head = _head->_next;
			delete del;
			del = NULL;
		}
	}
}

template <class T>
bool LinkList<T>::Empty()
{
	return (_head == NULL) ? true : false;
}

template <class T>
const T& LinkList<T>::Front() const
{
	return _head->_data;
}
template <class T>
const T& LinkList<T>::Back() const
{
	return _tail->_data;
}

template <class T>
void LinkList<T>::Insert(Node<T>* pos, T data)
{
	Node<T>* cur = _head;
	while (cur->_next != pos && cur)
	{
		cur = cur->_next;
	}

	if (cur->_next == pos)
	{
		Node<T>* newNode = new T(data);
		newNode->_next = pos;
		cur->_next = newNode;
	}
}

//������
//template<class T>
//void LinkList<T>::Erase(Node<T>* pos)
//{
//	Node<T>* cur = _head;
//	if (pos == _head)//ɾͷ�ڵ�
//	{
//		if (_head->_next == NULL) //ֻ��һ���ڵ�
//		{
//			delete _head;
//			_head = NULL;
//			_tail = NULL;
//		}
//		else  //����ڵ�
//		{
//			Node<T>* del = _head;
//			_head = _head->_next;
//			delete del;
//			del = NULL;
//		}
//	}
//	else
//	{
//		while (cur && cur->_next != pos)
//		{
//			cur = cur->_next;
//		}
//
//		if (cur != NULL)
//		{
//			if (pos->_next == NULL)//ɾβ���
//			{
//				delete pos;
//				pos = NULL;
//				_tail = cur;
//			}
//			else
//			{
//				cur->_next = pos->_next;
//				delete pos;
//				pos = NULL;
//			}
//		}
//	}
//}

template <class T>
void LinkList<T>::Swap(LinkList& l)
{
	swap(_head, l._head);
	swap(_tail, l._tail);

	//�Լ�ʵ��
	/*Node<T>* tmp = l._head;
	l._head = _head;
	_head = tmp;

	tmp = l._tail;
	l._tail = _tail;
	_tail = tmp;*/
}
template <class T>
void LinkList<T>::Clear()
{
	Node<T>* cur = _head;
	while (cur)
	{
		Node<T>* del = cur;
		cur = cur->_next;
		delete del;
		del = NULL;
	}
	_head = NULL;
	_tail = NULL;
}

template <class T>
Node<T>* LinkList<T>::find(const T& data)
{
	Node<T>* cur = _head;
	while (cur)
	{
		if (cur->_data == data)
		{
			return cur;
		}
		cur = cur->_next;
	}
	return NULL;
}
