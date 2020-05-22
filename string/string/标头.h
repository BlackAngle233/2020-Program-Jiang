#include <iostream>
#include <string.h>
#include<string.cpp>
using namespace std;


int main()
{
String s("hello");
String s1(s);
String* s2 = new String("world");
String s3(*s2);
cout << s << endl;
cout << s1 << endl;
cout << *s2 << endl;
cout << s3 << endl;
}
