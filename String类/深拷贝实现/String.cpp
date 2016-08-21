#include "String.h"

ostream& operator<<(ostream& os, const String& s)
{
	os << s._str;
	return os;
}

//   >>ÓÐÎÊÌâ
istream& operator>>(istream& is, String& s)
{
	is >> s._str;
	return is;
}

size_t String::size()const
{
	return _size;
}

size_t String::length()const
{
	return strlen(_str);
}

void String::push_back(char c)
{
	CheckCapacity(1);
	_str[_size++] = c;
	_str[_size] ='\0';
}

void String::CheckCapacity(size_t size)
{
	if( _capacity <= (_size+size) )
	{
		int newCapacity = (_capacity*2+1)>(_size+size) ?
			_capacity*2+1:_size+size+1;
		char *newstr = new char[newCapacity];
		strcpy(newstr, _str);
		delete[] _str;
		_str = newstr;
		_capacity = newCapacity;
	}
}


String& String::operator+= ( const String& str )
{
	CheckCapacity(strlen(str._str));
	char *tmp = str._str;
	while(*tmp)
	{
		_str[_size] = *tmp;
		_size++;
		tmp++;
	}
	_str[_size] = '\0';
	
	return *this;
}

String& String::operator+= ( const char* s )
{
	CheckCapacity(strlen(s));
	while(*s)
	{
		_str[_size++] = *s;
		s++;
	}
	_str[_size] = '\0';
	return *this;
}

String& String::operator+= ( char c )
{
	CheckCapacity(1);
	_str[_size++] = c;
	_str[_size] = '\0';
	return *this;
}

const char *String::c_str() const
{
	return _str;
}


