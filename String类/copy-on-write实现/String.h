//写时拷贝：比较常用的写法
//为字符串多开辟一个整型空间用来存储引用计数

#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstring>
using namespace std;

class String
{
	friend ostream& operator<<(ostream& os, const String& s);
public:
	String(const char *str = "")
		:_str(new char[strlen(str)+1+4])
	{
		_str += 4;
		strcpy(_str, str);
		GetCount() = 1;
	}
	String(const String& s)
		:_str(s._str)
	{
		GetCount()++;
	}
	String& operator=(const String& s)
	{
		//自己给自己赋值,如果引用计数为1会出错
		if (this != &s)
		{
			Release();
			_str = s._str;
			GetCount()++;
		}
		return *this;
	}
	~String()
	{
		Release();
	}
public:
	char& operator[](size_t index);
private:
	int& GetCount();
	void Release();
private:
	char* _str;
};

ostream& operator<<(ostream& os, const String& s);
