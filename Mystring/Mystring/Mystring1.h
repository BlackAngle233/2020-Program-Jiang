#pragma once

#include "pch.h"
#include <iostream>
using namespace std;
class MyString {
public:
	MyString();
	MyString(char c);
	MyString(const char* p);
	~MyString();
	MyString(const MyString& other);
	MyString& operator= (const MyString& other);

	MyString(MyString&& other);
		MyString&  operator= (MyString&& other);
	bool empty() const;
	size_t length() const;
	MyString& operator + (const MyString& other);
	friend ostream& operator<<(ostream &out, MyString &c1); 
private:
	struct Buf {
		size_t length;
		char* p;
	};
	std::shared_ptr<Buf > buff_;
	

};
