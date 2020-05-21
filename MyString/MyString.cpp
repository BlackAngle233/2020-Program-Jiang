#include <iostream>
#include <memory>
#include "MyString.h"
using namespace std;

MyString::MyString()
{
    buff_ = shared_ptr<Buf>(new Buf);
    buff_->length = 0;
    buff_->p = new char[1];
    buff_->p[0] = '\0';
}
// MyString::MyString(char c)
// {

// }
MyString::MyString(const char *p)
{
    int len = 0;
    while (p[len] != '\0')
    {
        len++;
    }
    buff_ = shared_ptr<Buf>(new Buf);
    buff_->length = len;
    buff_->p = new char[len + 1];
    for (int i = 0; i < len; i++)
    {
        buff_->p[i] = p[i];
    }
    buff_->p[len] = '\0';
}
MyString::~MyString()
{
    delete[] buff_->p;
}
MyString::MyString(const MyString &other)
{
    buff_ = shared_ptr<Buf>(new Buf);
    int len = other.buff_->length;
    buff_->length = len;
    buff_->p = new char[buff_->length + 1];
    for (int i = 0; i < len; i++)
    {
        buff_->p[i] = other.buff_->p[i];
    }
    buff_->p[len] = '\0';
}
MyString &MyString::operator=(const MyString &other)
{
    int len = other.buff_->length;
    char *lstr = other.buff_->p;
    buff_->length = len;
    delete[] buff_->p;
    buff_->p = new char[len + 1];
    for (int i = 0; i < len; i++)
    {
        buff_->p[i] = lstr[i];
    }
    buff_->p[len] = '\0';
    return *this;
}

MyString::MyString(MyString &&other)
{
    buff_ = shared_ptr<Buf>(new Buf);
    buff_->length = other.buff_->length;
    buff_->p = other.buff_->p;
    other.buff_->p = nullptr;
}
MyString &MyString::operator=(MyString &&other)
{
    buff_->p = other.buff_->p;
    buff_->length = other.buff_->length;
    other.buff_->p = nullptr;
}
bool MyString::empty() const
{
    if (buff_->length == 0)
        return true;
    else
        return false;
}
size_t MyString::length() const
{
    return buff_->length;
}
MyString MyString::operator+(const MyString &other)
{
    int llen = buff_->length;
    int rlen = other.buff_->length;
    char *lstr = buff_->p;
    char *rstr = other.buff_->p;
    char *res = new char[llen + rlen + 1];
    for (int i = 0; i < llen; i++)
    {
        res[i] = lstr[i];
    }
    for (int i = 0; i < rlen; i++)
    {
        res[llen + i] = rstr[i];
    }
    res[llen + rlen] = '\0';
    MyString str(res);
    return str;
}

ostream &operator<<(ostream &os, const MyString &str)
{
    os << str.buff_->p;
    return os;
}