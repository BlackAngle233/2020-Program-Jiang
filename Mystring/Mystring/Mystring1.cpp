#include "pch.h"
#include "Mystring1.h"
#include<string>
#include <cstring>

MyString::MyString(char c)
{
	*(buff_->p) = c;
	buff_->length = 1;
}
 
MyString::MyString(const char * p)
{
	if (p == nullptr) 
	{
		buff_->p = nullptr;
		buff_->length = 0;
	}
	else
	{
		buff_ = make_shared<Buf>( Buf{0,nullptr});
		buff_->length = strlen(p) + 1;
		buff_->p = new char[strlen(p) + 1];
		strcpy_s(buff_->p,sizeof(buff_->p), p);
	
	}
}

MyString::~MyString()
{
	buff_.~shared_ptr();
}

MyString::MyString(const MyString & other)
{
	if(other.buff_->length==0)
	{
		buff_->p = nullptr;
		buff_->length = 0;
	}
	else 
	{
		buff_ = make_shared<Buf>(Buf{ 0,nullptr });
		buff_->length = strlen(other.buff_->p) + 1;
		buff_->p = new char[strlen(other.buff_->p) + 1];
		strcpy_s(buff_->p, sizeof(buff_->p),other.buff_->p);
	}
}

MyString & MyString::operator=(const MyString & other)
{
	if (other.buff_->length == 0)
	{
		delete[] buff_->p;
		buff_->p = nullptr;
		buff_->length = 0;
		
	}
	else
	{
		if (this == &other)
			return*this;
		delete[] buff_->p;
		buff_ = make_shared<Buf>(Buf{ 0,nullptr });
		buff_->length = strlen(other.buff_->p) + 1;
		buff_->p = new char[strlen(other.buff_->p) + 1];
		strcpy_s(buff_->p, sizeof(buff_->p),other.buff_->p);
	}
	return*this;
}

MyString::MyString(MyString && other)
{
	buff_->p = move(other.buff_->p);
}

MyString & MyString::operator=(MyString && other)
{
	
	buff_->p = move(other.buff_->p);
	return *this;
	
}

bool MyString::empty() const
{
	if (buff_->length == 0)
		return true;
	else
		return false;
}

size_t MyString::length() const
{
	return buff_->length;
}

MyString & MyString::operator+(const MyString & other)
{
	MyString e = *this;
	e.buff_ = make_shared<Buf>(Buf{ 0,nullptr });
	e.buff_->p = buff_->p;
	e.buff_->p = new char[buff_->length + other.buff_->length+2];	
	strcpy_s(e.buff_->p, sizeof(e.buff_->p), buff_->p);
	
	strcat_s(e.buff_->p, buff_->length + other.buff_->length + 2,other.buff_->p);
	
	buff_->length += other.buff_->length;
	
	buff_->p = e.buff_->p;
	
	
	return *this;
}

ostream & operator<<(ostream & out, MyString & c1)
{
	for (int a = 0; a <c1.buff_->length; a++)
		cout << c1.buff_->p[a];
	return out;
}
