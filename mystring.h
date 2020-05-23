#pragma once
#include <memory>
#include <string>
#include <iostream>
#include <xutility>
class mystring
{
public: 
	struct Data
	{
		char str[20];
		int size;
	};
	mystring() : data(std::shared_ptr<Data>(new Data{"", 0})) {}
	mystring(const char* other) :data(std::shared_ptr<Data>{new Data{"", 0}})
	{
		strcpy(data->str, other);
		data->size = strlen(other);
	}

	mystring(const mystring& other) :
		data(other.data) {};


	mystring& operator=(mystring& other)
	{
		if (this == &other)
		{
			return *this;
		}
		data = other.data;
		return *this;
	}

	inline int length() { return data -> size; }

	friend mystring operator+(mystring& a, mystring& b);
	friend std::ostream& operator<<(std::ostream& out, mystring& a);

	char& operator[](int num)
	{
		if (num < 0 || num >= data->size)
			throw "out of bound";
		if (!data.unique())
		{
			auto temp = new Data{ "", 0 };
			strcpy(temp->str, data->str);
			temp->size = data->size;
			data.reset(temp);
		}
		return data->str[num];
	}


	int showlocation()
	{
		return (int)data->str;
	}

private:
	std::shared_ptr<Data> data{nullptr};
};

mystring operator+(mystring& a, mystring& b)
{
	mystring c(a);
	c.data.reset(new mystring::Data{ "",0 });
	strcpy(c.data->str, a.data->str);
	strcat(c.data->str, b.data->str);
	c.data->size = strlen(c.data->str);
	return c;
}

std::ostream & operator <<(std::ostream& out, mystring& string)
{
	out << string.data->str;
	return out;
}
