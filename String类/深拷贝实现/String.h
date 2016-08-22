//深拷贝实现String类
#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstring>
using namespace std;

class String
{
	friend ostream& operator<<(ostream& os, const String& s);
	friend istream& operator>>(istream& is, String& s);

public:
	String()  //构造空串
		: _size(0)
		, _capacity(10)
		, _str(new char[10])
	{
		_str[0] = '\0';
	}

	String(const char* str)
		: _size(strlen(str))
		, _capacity(strlen(str)+1)
		, _str(new char[strlen(str)+1])
	{
		strcpy(_str, str);
	}

	String(const String& s)
		: _size(s._size)
		, _capacity(s._capacity)
		, _str(new char[s._capacity])
	{
		strcpy(_str, s._str);
	}

	String& operator=(String s)
	{
		if(_str != s._str)
		{
			swap(_str, s._str);
			_size = s._size;
			_capacity = s._capacity;
		}
		return *this;
	}

	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = NULL;
			_size = 0;
			_capacity = 0;
		}
	}

public:
	size_t size() const;
	size_t length() const;
	void push_back(char c);
	String& operator+= ( const String& str );
	String& operator+= ( const char* s );
	String& operator+= ( char c );
	const char *c_str() const;
	String& insert ( size_t pos1, const String& str );
	String& insert ( size_t pos1, const String& str, size_t pos2, size_t n );
	String& insert ( size_t pos1, const char* s, size_t n);
	String& insert ( size_t pos1, const char* s );
	String& insert ( size_t pos1, size_t n, char c );

private:
	void CheckCapacity(size_t size);

private:
	char *_str;
	size_t _size;
	size_t _capacity;
};

ostream& operator<<(ostream& os,const String& s);
istream& operator>>(istream& is,String& s);
