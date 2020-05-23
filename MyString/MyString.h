#pragma once
#include<memory>
#include<iostream>
using namespace std;
class MyString{
public:
	//using value_type = char;
	using iterator = char*;
	iterator begin() { return buff_ ? buff_->p : nullptr; }
	iterator end() { return buff_ ? buff_->p + buff_->length : nullptr; }

	MyString();
	MyString(char c);
	MyString(const char* p);
	~MyString();

	MyString(const MyString& other);
	MyString& operator= (const MyString& other);

	MyString(MyString&& other);
	MyString& operator= (MyString&& other);
	MyString& operator+=(const MyString& other);

	bool empty() const;
	size_t length() const;

	MyString operator + (const MyString& other);
	char& operator[](size_t index);
	
	

private:
	struct Buf {
		size_t length{};
		char* p{};
		Buf() = default;
		Buf(size_t len = 0, char* p = nullptr):length(len),p(p){}
		~Buf()
		{
			delete p;
		}
	};
	
	std::shared_ptr<Buf> buff_{};
public:
	shared_ptr<Buf> getBuf()
	{
		return buff_;
	}
};

