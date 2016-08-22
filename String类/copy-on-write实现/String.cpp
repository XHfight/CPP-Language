#include "String.h"

int& String::GetCount()
{
	return *(int*)(_str - 4);
}

void String::Release()
{
	if (--GetCount() == 0)
	{
		delete[](_str - 4);
	}
}

ostream& operator<<(ostream& os, const String& s)
{
	os << s._str ;
	return os;
}

char& String::operator[](size_t index)
{
	if (GetCount() > 1)
	{
		GetCount()--;
		char* tmp = new char[strlen(_str) + 1 + 4];
		strcpy(tmp + 4, _str);
		_str = tmp + 4;
		GetCount() = 1;
	}
	return _str[index];

}