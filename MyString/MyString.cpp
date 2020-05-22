#include"MyString.h"

MyString::MyString() {
	Buf* b = new Buf{ 0,nullptr };
	buff_ = std::shared_ptr<Buf >(b);
}
MyString::MyString(char r) {
	Buf* b = new Buf{ 1,new char(r) };
	buff_ = std::shared_ptr<Buf >(b);
}
MyString::MyString(const char* p) {
	int i = 0,length_=0;
	char* p_;
	while (p + i) {
		*(p_ + i) = *(p + i);
		length_++;
		i++;
	}
	Buf* b = new Buf{ length_,p_ };
	buff_ = std::shared_ptr<Buf >(b);
}
MyString::MyString(const MyString& other) {
	char* p_;
	int i = 0;
	while (other.buff_->p + i) {
		*(p_ + i) = *(other.buff_->p + i);
		i++;
	}
	Buf* b = new Buf{ other.buff_->length,p_ };
	buff_ = std::shared_ptr<Buf >(b);
}
MyString& MyString::operator=(MyString&& other) {
	MyString res;
	char* p_;
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
	char* p_;
	int i = 0, j = 0;
	while (this->buff_->p + i) {
		*(p_ + i) = *(this->buff_->p + i);
		i++;
	}
	while (other.buff_->p + j) {
		*(p_ + i + j) = *(other.buff_->p + j);
		j++;
	}
	Buf* b = new Buf{ this->length + other.length,p_ };
	res.buff_ = std::shared_ptr<Buf >(b);
	return res;
}