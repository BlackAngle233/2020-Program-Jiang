#include <iostream>
#include <memory>
#include <cstring>
using namespace std;
class MyString {
public : 
    MyString(); 
    MyString(char c); 
    MyString(const char* p);
    ~MyString(); 
    MyString(const MyString& other);
    MyString& operator= (const MyString& other);

    MyString(MyString &&other);
    MyString&  operator= ( MyString&& other);
    bool empty() const;
    size_t length() const; 
    MyString& operator + (const MyString& other );
    char *getData() const;

private : 
    struct Buf {
        size_t length; 
        char* p; 
        Buf()
        {
            length = 0;
            p = nullptr;
        }
    };
    shared_ptr<Buf> buff_;
};

MyString::MyString()
{
    buff_ = make_shared<Buf>(new Buf());
}

MyString::MyString(char c)
{
    buff_ = make_shared<Buf>(new Buf());
    buff_->p = &c;
}

MyString::MyString(const char* p)
{
    buff_ = make_shared<Buf>(new Buf());
    if(p !=nullptr)
    {
        buff_->length = strlen(p);
        buff_->p = new char[buff_->length + 1];
        strcpy(buff_->p, p);
    }
    else
    {
        buff_->p = new char[1];
        *(buff_->p) = '/0';
    }
}

MyString::~MyString()
{
    delete[] buff_->p;
    buff_->length = 0;
}

MyString::MyString(const MyString& other)
{
    if(other.buff_->p == nullptr)
    {
        buff_->length = strlen(buff_->p);
        buff_->p = new char[buff_->length + 1];
        strcpy(buff_->p, other.buff_->p);
    }
    else
    {
        buff_->length = strlen(other.buff_->p);
        buff_->p = new char[buff_->length + 1];
        strcpy(buff_->p, other.buff_->p);
    }
}
MyString& MyString::operator= (const MyString& other)
{
    if(this==&other)
        return *this;
    delete[] buff_->p;
    buff_->length = other.buff_->length;
    buff_->p = new char[buff_->length + 1];
    strcpy(buff_->p, other.buff_->p);
    return *this;
}

MyString::MyString(MyString &&other)
{
    if(other.buff_->p == nullptr)
    {
        buff_->length = strlen(buff_->p);
        buff_->p = new char[buff_->length + 1];
        strcpy(buff_->p, other.buff_->p);
    }
    else
    {
        buff_->length = strlen(other.buff_->p);
        buff_->p = new char[buff_->length + 1];
        strcpy(buff_->p, other.buff_->p);
    }
}
MyString&  MyString::operator= ( MyString&& other)
{
    if(this==&other)
        return *this;
    delete[] buff_->p;
    buff_->length = other.buff_->length;
    buff_->p = new char[buff_->length + 1];
    strcpy(buff_->p, other.buff_->p);
    return *this;
}
bool MyString::empty() const
{
    if(length()==0)
        return true;
    return false;
}
size_t MyString::length() const
{
    return buff_->length;
} 
MyString& MyString::operator + (const MyString& other )
{
    MyString newString;
    newString.buff_->length = buff_->length + other.buff_->length;
    newString.buff_->p = new char[newString.buff_->length + 1];
    strcpy(newString.buff_->p, buff_->p);
    strcat(newString.buff_->p, other.buff_->p);
    return newString;
}
char* MyString::getData() const
{
    return buff_->p;
}

std::ostream& operator<<(std::ostream& os, const MyString &rhs)
{
	os << rhs.getData();
	return os;
}