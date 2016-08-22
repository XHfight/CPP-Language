#include "String.h"

ostream& operator<<(ostream& os, const String& s)
{
	os << s._str;
	return os;
}
