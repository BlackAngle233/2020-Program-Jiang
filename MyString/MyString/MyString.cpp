#include "MyString.h"

MyString::MyString() {
	
}

MyString::~MyString() {

}

MyString::MyString(char c) {
	buff_.reset(new Buf(1, &c));
}

MyString::MyString(const char* p) {
	buff_.reset(new Buf(strlen(p), p));
}

MyString::MyString(const MyString& other) {
	buff_.reset(new Buf(other.buff_->length, other.buff_->p));
}

MyString& MyString::operator= (const MyString& other) {
	buff_->length = other.buff_->length;
	buff_->p = new char[buff_->length];
	strcpy(buff_->p, other.buff_->p);
	return *this;
}

MyString::MyString(MyString&& other) {
	buff_.reset(new Buf(other.buff_->length, other.buff_->p));

}

MyString& MyString::operator= (MyString&& other) {
	buff_->length = other.buff_->length;
	buff_->p = new char[buff_->length];
	strcpy(buff_->p, other.buff_->p);
	return *this;
}

bool MyString::empty() const {
	if (!buff_)
		return true;
	return buff_->length > 0 ? false : true;
}

size_t MyString::length() const {
	return buff_ ? buff_->length : 0;
}

MyString& MyString::operator + (const MyString& other) {
	size_t length = buff_->length + other.buff_->length;
	char* tmp = new char[length];
	strcpy(tmp, buff_->p);
	strcpy(tmp + buff_->length, other.buff_->p);
	return *(new MyString(tmp));
}