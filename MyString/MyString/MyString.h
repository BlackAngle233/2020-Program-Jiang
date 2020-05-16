#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory>

class MyString {
public:
	
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
	bool empty() const;
	size_t length() const;
	MyString& operator + (const MyString& other);

	void print() {
		std::cout << buff_->p << std::endl;
	}
private:
	struct Buf {
		size_t length;
		char* p;

		Buf(size_t l, const char* c) {
			length = l;
			p = new char[l];
			strcpy(p, c);
		}
	};
	std::shared_ptr<Buf> buff_;
};
