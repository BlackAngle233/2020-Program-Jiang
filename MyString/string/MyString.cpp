#include <iostream>
#include <string.h>
using namespace std;


class MyString{
public:
    MyString(const char* str = NULL);
    char* c_ret();
    ~MyString();
    MyString operator+(const MyString& other);
    bool operator==(const MyString& other);
    char operator[](int index);
private:
    char* _str;
};

MyString::MyString(const char* str){
    if (str == NULL){
        _str = new char[1];
        *_str = '\0';
    }
    else{
        int len = strlen(str);
        _str = new char[len + 1];
        strcpy(_str, str);
    }
}

char* MyString::c_ret(){
    return _str;
}

MyString::~MyString(){
    delete[]_str;
}

MyString MyString::operator+(const MyString& other){
    using std::cout;
    using  std::endl;
    MyString* p = new MyString;
    int len1 = strlen(_str);
    int len2 = strlen(other._str);
    p->_str = new char[len1 + len2 + 1];
    memset(p->_str, 0, len1 + len2 + 1);
    strcat(p->_str, _str);
    strcat(p->_str, other._str);
    return *p;
}

bool MyString::operator==(const MyString& other){
    if (strcmp(_str, other._str) == 0)
        return true;
    else
        return false;
}


char MyString::operator[](int index){
    return this->_str[index];
}
