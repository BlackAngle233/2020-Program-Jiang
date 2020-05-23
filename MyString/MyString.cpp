#include"MyString.h"
#include<iostream>

MyString::MyString() {
	Buf* b = new Buf{ 0,nullptr };
	buff_ = std::shared_ptr<Buf >(b);
}
MyString::MyString(char r) {
	Buf* b = new Buf{ 1,new char(r) };
	buff_ = std::shared_ptr<Buf >(b);
}
MyString::MyString(const char* p) {
	int i = 0;
	size_t length_ = 0;
	char* p_=new char;
	while (p + i) {
		*(p_ + i) = *(p + i);
		length_++;
		i++;
	}
	Buf* b = new Buf{ length_,p_ };
	buff_ = std::shared_ptr<Buf >(b);
}
MyString::MyString(const MyString& other) {
	char* p_=new char;
	int i = 0;
	while (other.buff_->p + i) {
		*(p_ + i) = *(other.buff_->p + i);
		i++;
	}
	Buf* b = new Buf{ other.buff_->length,p_ };
	buff_ = std::shared_ptr<Buf >(b);
}
MyString& MyString::operator = (MyString&& other) {
	std::shared_ptr<Buf > tmp;
	tmp = std::move(buff_);
	buff_ = std::move(other.buff_);
	other.buff_ = std::move(tmp);
	return *this;
}

MyString& MyString::operator = (const MyString& other) {
	MyString res;
	char* p_=new char;
	int i = 0;
	while (other.buff_->p + i) {
		*(p_ + i) = *(other.buff_->p + i);
		i++;
	}
	Buf* b = new Buf{ other.buff_->length,p_ };
	res.buff_ = std::shared_ptr<Buf >(b);
	return res;
}
MyString& MyString::operator+(const MyString& other) {
	MyString res;
	char* p_=new char;
	int i = 0, j = 0;
	while (this->buff_->p + i) {
		*(p_ + i) = *(this->buff_->p + i);
		i++;
	}
	while (other.buff_->p + j) {
		*(p_ + i + j) = *(other.buff_->p + j);
		j++;
	}
	Buf* b = new Buf{ buff_->length+other.buff_->length,p_ };
	res.buff_ = std::shared_ptr<Buf >(b);
	return res;
}
void MyString::print() {
	if (empty()) {
		std::cout << "MyString is empty." << std::endl;
		return;
	}
	int i = 0;
	while (buff_->p + i != end()) {
		std::cout << *(buff_->p + i) << std::endl;
		i++;
	}
}