//写时拷贝实现String类
//将字符串与引用计数分开管理，各自的空间不在一起。
#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

class String
{
	friend ostream& operator<<(ostream& os, const String& s);
public:
	String(const char* str = "")
		:_str(new char[strlen(str)+1])
		,_pcount(new int(1))
	{
		strcpy(_str, str);
	}

	String(const String& s)
		:_str(s._str)
		,_pcount(s._pcount)
	{
		(*_pcount) += 1;
	}

	String& operator=(const String& s)
	{
		if (this != &s)
		{
			if (*_pcount == 1)
			{
				delete _str;
				delete _pcount;
				_str = s._str;
				_pcount = s._pcount;
				(*_pcount)++;
			}
			else
			{
				(*_pcount)--;
				_pcount = s._pcount;
				_str = s._str;
				(*_pcount)++;
			}
		}
		return *this;
	}


	~String()
	{
		if(--(*_pcount) == 0)
		{
			delete[] _str;
			delete _pcount;
			_str = NULL;
			_pcount = NULL;
		}
	}

private:
	char *_str;
	int* _pcount;
};

ostream& operator<<(ostream& os, const String& s);
