//дʱ�������Ƚϳ��õ�д��
//Ϊ�ַ����࿪��һ�����Ϳռ������洢���ü���

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
		//�Լ����Լ���ֵ,������ü���Ϊ1�����
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
