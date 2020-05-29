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
	MyString(const MyString& other);//��������
	//MyString& operator=(const MyString& other);//������ֵ

	MyString(MyString&& other);//�ƶ�����
	//MyString& operator=(MyString&& other);//�ƶ���ֵ
	bool empty() const;
	size_t length()const;
	MyString& operator+(const MyString& other);

	void print();//��ӡ

private:
	struct Buf {
		size_t length;
		char* p;
	};
	std::shared_ptr<Buf >buff_;
};