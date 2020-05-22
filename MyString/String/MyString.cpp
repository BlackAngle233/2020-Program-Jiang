#include"MyString.h"
#include<memory>
#include<cassert>
MyString::MyString()
{
	buff_ = std::make_shared<Buf>(1, new char('\0'));
}
MyString::MyString(char p)
{
	buff_ = std::make_shared<Buf>(2,&p);
	*(buff_->p + 1) = '\0';
}
MyString::MyString(const char* p)
{
	if (!p)
	{
		buff_ = std::make_shared<Buf>(1, new char('\0'));
	}
	else
	{
		buff_ = std::make_shared<Buf>(strlen(p) + 1, new char[strlen(p) + 1]);
		strcpy_s(buff_->p,buff_->length ,p);
	}
}

MyString::~MyString()
{
	buff_.~shared_ptr();
}

MyString::MyString(const MyString& other):buff_(other.buff_)
{
}

MyString& MyString::operator=(const MyString& other)
{
	if (this == &other)
	{
		return *this;
	}
	if(buff_->p == nullptr)
		delete[] buff_->p;
	buff_->p = nullptr;
	buff_.~shared_ptr();
	buff_ = other.buff_;
	return *this;
}

bool MyString::empty() const
{
	return buff_->p == nullptr;
}

size_t MyString::length() const
{
	return buff_->length;
}

MyString::MyString(MyString&& other) :buff_(other.buff_)
{
	other.buff_ = nullptr;
}

MyString& MyString::operator=(MyString&& other)
{
	//buff_->length = std::move(other.buff_->length);
	//buff_->p = std::move(other.buff_->p);
	buff_ = std::move(other.buff_);
	return *this;
}
MyString MyString::operator+(const MyString& other)
{
	MyString temp;
	if (empty() && other.empty())
	{
		return temp;
	}
	else if (!empty() && other.empty())
	{
		temp.buff_->length = buff_->length;
		temp.buff_->p = new char[buff_->length];
		strcpy_s(temp.buff_->p,buff_->length ,buff_->p);

		return temp;
	}
	else if (empty() && !other.empty())
	{
		temp.buff_->length = other.buff_->length;
		temp.buff_->p = new char[other.buff_->length];
		strcpy_s(temp.buff_->p,other.buff_->length ,other.buff_->p);

		return temp;
	}
	else if(!empty() && !other.empty())
	{
		MyString t1(buff_->p);
		MyString t2(other.buff_->p);
		temp.buff_->length = t1.buff_->length + t2.buff_->length - 1;
		temp.buff_->p = new char[temp.buff_->length];
		strcpy_s(temp.buff_->p,buff_->length ,buff_->p);
		char* index = temp.buff_->p;
		while(1)
		{
			if (*index == 0)
				break;
			++index;
		}
		strcpy_s(index,t2.buff_->length ,t2.buff_->p);
	}

	
	return temp;
}

char& MyString::operator[](size_t index)
{
	if (index <0 || index > buff_->length)
		assert(index);
	if (buff_.use_count() == 1)
		return buff_->p[index-1];
	char* t = new char[buff_->length];
	strcpy_s(t, buff_->length, buff_->p);
	this->buff_ = make_shared<Buf>(strlen(t)+1);
	this->buff_->p = new char[buff_->length];
	
	strcpy_s(this->buff_->p, strlen(t)+1, t);
	return this->buff_->p[index-1];
}

