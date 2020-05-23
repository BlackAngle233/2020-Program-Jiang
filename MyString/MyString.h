#pragma once
#include<memory>

class MyString {
	struct Buf{
		size_t length;
		char* p;
	};
	std::shared_ptr<Buf > buff_;
public:
	using iterator = char*;
	iterator begin() { return buff_ ? buff_->p : nullptr; }
	iterator end() {
		return buff_ ? buff_->p + buff_->length : nullptr;
	}
	MyString();
	MyString(char r);
	MyString(const char* p);
	MyString(const MyString& other);	//���ƹ��캯��
	MyString(MyString&& other) :buff_(other.buff_) { other.buff_->length = 0;other.buff_->p = nullptr; }
	MyString& operator = (MyString&& other);	//�ƶ����캯��
	MyString& operator = (const MyString& other);
	~MyString(){}
	bool empty() const { if (buff_->length == 0)return true;else return false; }
	size_t length() const { return buff_->length; }
	MyString& operator +(const MyString& other);
	void print();
};