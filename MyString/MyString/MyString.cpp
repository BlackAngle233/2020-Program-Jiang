#include"MyString.h"
#include<iostream>
#include<memory>
using namespace std;

MyString::MyString() {
	Buf* b = new Buf{0,nullptr};
	buff_ = std::shared_ptr<Buf >(b);
}

MyString::MyString(char c) {
	Buf* b = new Buf{ 1,&c };
	buff_ = std::shared_ptr<Buf >(b);
}

MyString::MyString(const char* p) {
	int i = 0;
	char* pe=new char();
	while (p[i]!=NULL) {
		pe[i] = p[i];
		i++;
	}
	Buf* b = new Buf{ (size_t)i, pe };
	buff_.reset(b);
}

MyString::MyString(const MyString& other) {
	char* pe = new char();
	int i = 0;
	while (other.buff_->p+i) {
		*(pe + i )= *(other.buff_->p + i);
		i++;
	}
	Buf* b = new Buf{ (size_t)i, pe };
	buff_.reset(b);
}

//MyString& MyString::operator=(const MyString& other) {
//	char* pe = new char();
//	int i = 0;
//	while (other.buff_->p + i) {
//		*(pe + i) = *(other.buff_->p + i);
//		i++;
//	}
//	buff_->length = i;
//	buff_->p = pe;
//	return *this;
//}

MyString::~MyString() {

}

MyString::MyString(MyString&& other)
	:buff_{other.buff_}
{
	other.buff_->length = 0;
	other.buff_->p = nullptr;
}

//MyString& MyString::operator=(MyString&& other) {
//	cout << *(other.buff_->p);
//	std::shared_ptr<Buf > tmp;
//	tmp = std::move(buff_);
//	buff_ = std::move(other.buff_);
//	other.buff_ = std::move(tmp);
//	return *this;
//}

MyString& MyString::operator +(const MyString& other) {
	buff_->length = buff_->length + other.buff_->length;
	int i = 0;
	while (other.buff_->p + i) {
		*(buff_->p + buff_->length+ i) = *(other.buff_->p + i);
		i++;
	}
	return *this;
}

bool MyString::empty() const {
	if (!buff_||buff_->p)
		return true;
	else
		return buff_->length > 0 ? false : true;
}

size_t MyString::length()const {
	return buff_ ? buff_->length : 0;
}

void MyString::print() {
	if (empty()) {
		cout << "MyString对象为空" << endl;
	}
	else {
		int i = 0;
		cout << "长度：" << buff_->length<<endl;
		while (buff_->p+i!=nullptr) {
			cout << *(buff_->p + i) << endl;
			i++;
		}
	}
}