#pragma once
#include <iostream>
using namespace std;

class String
{
public:
	String();
	String(const String& str1);
	String(char simbol, int size);
	String(char* str1);
	~String();
	void writeToStr();
	static int Compare(String& str, String &str1);
	static String Concat(String& str, String &str1);
	bool Contains(String& str);
	int IndexOf(char value);
	int IndexOf(String& value);
	int IndexOf(char value, int startIndex);
	int IndexOf(String& value, int startIndex);
	int LastIndexOf(char value);
	int LastIndexOf(String& value);
	int LastIndexOf(char value, int startIndex);
	int LastIndexOf(String& value, int startIndex);
	static bool IsNull(String& value);
	void printStr();
	char* getStr();
	int CompareTo(String& str);
	friend String operator+(String, String);
	friend String operator+(String, char* str);
	friend String operator+(char* str, String);
	String operator=(const String& str)
	{
		if (this == &str)
		{
			return *this;
		}

		int count = strlen(str._str);
		
		this->_str = new char[count];
		for (size_t i = 0; i < count; i++)
		{
			this->_str[i] = str._str[i];
		}
		this->_str[count] = '\0';

		return *this;
	}

private:
	char* _str;
public:
	template<typename T>
	class iterator : public std::iterator<std::forward_iterator_tag, T>
	{
		T* _p;
		int _size;
		int _count = 0;
	public:
		iterator()
		{
			_p = nullptr;
			_size = 0;
		}

		iterator(T* p, int size)
		{
			_p = p;
			_size = size;
		}

		iterator& operator++ ()
		{
			_count++;
			if (_count == _size)
				_p = nullptr;
			else
			{
				_p++;
			}

			return *this;
		}

		iterator operator++(int)
		{
			iterator tmp = *this;
			_count++;
			if (_count == _size)
				_p = nullptr;
			else
			{
				_p++;

			}
			return tmp;
		}

		T& operator* ()
		{
			return *_p;
		}

		bool operator != (iterator& it)
		{
			return _p != it._p;
		}

		bool operator == (iterator& it)
		{
			return _p == it._p;
		}

		iterator begin()
		{
			return iterator(p, size);
		}

		iterator end()
		{
			return iterator();
		}
	};

	
};

