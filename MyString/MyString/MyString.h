#pragma once
#include<memory>
class MyString {
public:
	using iterator = char*;
	iterator begin() { 
		return buff_ ? buff_->p : nullptr; 
	}
	iterator end() {
		return buff_ ? buff_->p + buff_->length : nullptr;
	}
	MyString();
	MyString(char c);
	MyString(const char* p);
	~MyString();
	MyString(const MyString& other);//拷贝构造
	//MyString& operator=(const MyString& other);//拷贝赋值

	MyString(MyString&& other);//移动构造
	//MyString& operator=(MyString&& other);//移动赋值
	bool empty() const;
	size_t length()const;
	MyString& operator+(const MyString& other);

	void print();//打印

private:
	struct Buf {
		size_t length;
		char* p;
	};
	std::shared_ptr<Buf >buff_;
};