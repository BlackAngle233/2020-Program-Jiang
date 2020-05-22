#include <iostream>
#include <string.h>
using namespace std;

class String{
public:
	explicit String(const char* str = "");
	explicit String(const String& other);
	String& operator=(const String& assign);
	~String() { delete[] m_data; }
	operator char* () { return m_data; }
private:
	char* m_data;
};

String::String(const char* str) {
	if (str == NULL) {
		m_data = new char[1];
		*m_data = '/0';
	}
	else {
		m_data = new char[strlen(str) + 1];
	}
}

String::String(const String& other){
	m_data = new char[strlen(other.m_data) + 1];

}

String& String::operator=(const String& assign){
	if (this != &assign){
		delete[] m_data;
		char* temp = new char[strlen(assign.m_data) + 1];
		m_data = temp;
	}
	return *this;
}

int main(){
	String s("hahahaha");
	String s1(s);
	String* s2 = new String("xixixixi");
	String s3(*s2);
	cout << s << endl;
	cout << s1 << endl;
	cout << *s2 << endl;
	cout << s3 << endl;
}
