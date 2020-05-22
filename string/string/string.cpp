#include <iostream>
#include <string.h>
using namespace std;

class String{
public:
	explicit String(const char* str = "");
	explicit String(const String& other);
	String& operator=(const String& assign);
	~String() { delete[] data; }
	operator char* () { return data; }
private:
	char* data;
};

String::String(const char* str) {
	if (str == NULL) {
		data = new char[1];
		*data = '/0';
	}
	else {
		data = new char[strlen(str) + 1];
	}
}

String::String(const String& other){
	data = new char[strlen(other.data) + 1];

}

String& String::operator=(const String& assign){
	if (this != &assign){
		delete[] data;
		char* temp = new char[strlen(assign.data) + 1];
		data = temp;
	}
	return *this;
}

bool empty() {
	string str;
	if (str == "") {
		return 0;
	}
	else {
		return 1;
	}
}
