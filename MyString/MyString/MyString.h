#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory>

using namespace std;

class MyString
{
public:
	MyString()
	{
		length = 0;
		data = NULL;
	}
	MyString(const char* str)
	{
		if (str == NULL)
		{
			length = 0;
			data = new char[1];
			*data = '\0';
		}
		else
		{
			length = strlen(str);
			data = new char[length + 1];
			strcpy(data, str);
		}
	}
	MyString(const MyString& other)
	{
		length = other.length;
		data = new char[length + 1];
		strcpy(data, other.data);
	}
	MyString& operator=(const MyString& other)
	{
		if (this == &other)
		{
			return *this;
		}
		else
		{
			delete[] data;
			length = other.length;
			data = new char[other.length + 1];
			strcpy(data, other.data);
			return *this;
		}
	}
	MyString operator+(const MyString& str) const
	{
		MyString newString;
		newString.length = length + str.length;
		newString.data = new char[newString.length + 1];
		strcpy(newString.data, data);
		strcat(newString.data, str.data);
		return newString;
	}
	~MyString()
	{
		delete[] data;
		length = 0;
	}
	bool empty() {
		if (data == "" || length == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	int size()const
	{
		return length;
	}
	const char* c_str() const
	{
		return data;
	}
private:
	char* data;
	int length;
};