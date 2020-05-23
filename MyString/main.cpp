/*
main
MyString s1;
MySting::iterator it = s1.begin();
for....
*/
#include"MyString.h"
#include<iostream>
using namespace std;

int main()
{
	MyString s1("abc");
	MyString s2("a");
	MyString s3(s1 + s2);
	MyString s4 = s3;
	cout<<s1[2]<<endl;
	cout<<s2[1]<<endl;
	cout << s3.getBuf()->p << endl;
	if(s3.getBuf() == s4.getBuf())
	cout << "s3.buff_ == s4.buff_ "<<endl;
	s4[3] = 't';
	cout << s4[3]<<endl;
	if (s3.getBuf() != s4.getBuf())
	cout << "s3.buff_ != s4.buff_ " << endl;
	cout << s3[3];
	return 0;
}