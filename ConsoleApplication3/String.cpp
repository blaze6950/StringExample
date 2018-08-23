#include "String.h"
#include "string"

String::String()
{
}

String::~String()
{
	_str;
	_str = nullptr;
}

static String Concat(String& str, String &str1)
{
	int a = strlen(str.getStr());
	int b = strlen(str1.getStr());
	a += b;
	char* tmp = new char[a];
	for (size_t i = 0; i < a - b; i++)
	{
		tmp[i] = str.getStr()[i];
	}
	tmp[a - b] = '\0';
	strcat(tmp, str1.getStr());
	return tmp;
}

bool String::Contains(String& str)
{
	cout << "Pomogi! \n";
}

int String::IndexOf(char value)
{
	int a = strlen(_str);
	for (size_t i = 0; i < a; i++)
	{
		if (_str[i] == value)
		{
			return i;
		}
	}
}

int String::IndexOf(String& value)
{
	int a = strlen(_str);
	for (size_t i = 0; i < a; i++)
	{
		if (_str[i] == value.getStr()[1])
		{
			return i;
		}
	}
}

int String::IndexOf(char value, int startIndex)
{
	int a = strlen(_str);
	if (a<startIndex)
	{
		return -1;
	}
	for (size_t i = startIndex; i < a; i++)
	{
		if (_str[i] == value)
		{
			return i;
		}
	}
}

int String::IndexOf(String& value, int startIndex)
{
	int a = strlen(_str);
	if (a<startIndex)
	{
		return -1;
	}
	for (size_t i = startIndex; i < a; i++)
	{
		if (_str[i] == value.getStr()[1])
		{
			return i;
		}
	}
}

int String::LastIndexOf(char value)
{
	int a = strlen(_str);
	for (size_t i = a; i >= 0; i--)
	{
		if (_str[i] == value)
		{
			return i;
		}
	}
}

int String::LastIndexOf(String& value)
{
	int a = strlen(_str);
	for (size_t i = a; i >= 0; i--)
	{
		if (_str[i] == value.getStr()[1])
		{
			return i;
		}
	}
}

int String::LastIndexOf(char value, int startIndex)
{
	int a = strlen(_str);
	if (a<startIndex)
	{
		return -1;
	}
	for (size_t i = startIndex; i >= 0; i--)
	{
		if (_str[i] == value)
		{
			return i;
		}
	}
}

int String::LastIndexOf(String& value, int startIndex)
{
	int a = strlen(_str);
	if (a<startIndex)
	{
		return -1;
	}
	for (size_t i = startIndex; i >= 0; i--)
	{
		if (_str[i] == value.getStr()[1])
		{
			return i;
		}
	}
}

static bool IsNull(String& value)
{
	int a = strlen(value.getStr());
	if (a == 0)
	{
		return 1;
	}
	return 0;
}

int String::CompareTo(String& str)
{
	return strcmp(getStr(), str.getStr());
}

static int Compare(String& str, String &str1)
{
	return strcmp(str.getStr(), str1.getStr());
}

char* String::getStr()
{
	return _str;
}

String operator+(String str1, String str2)
{
	return Concat(str1, str2);
}
String operator+(String str1, char* str)
{
	String str2(str);
	return Concat(str1, str2);
}
String operator+(char* str, String str1)
{
	String str2(str);
	return Concat(str2, str1);
}

String::String(char simbol, int size)
{
	_str = new char[size];
	for (size_t i = 0; i < size; i++)
	{
		_str[i] = char(simbol);
	}
	_str[size] = '\0';
}

String::String(char* str1)
{
	int count = strlen(str1);
	_str = new char[count];
	for (size_t i = 0; i < count; i++)
	{
		_str[i] = str1[i];
	}
	_str[count] = '\0';
}

String::String(const String& str1)
{
	int count = strlen(str1._str);
	_str = new char[count];
	for (size_t i = 0; i < count; i++)
	{
		_str[i] = str1._str[i];
	}
	_str[count] = '\0';
}

void String::printStr()
{
	cout << _str << endl;
}

void String::writeToStr(){
	_str = new char[10];
	for (size_t i= 0; i < 10; i++)
	{
		_str[i] = 'a';
	}
	_str[10] = '\0';
}
