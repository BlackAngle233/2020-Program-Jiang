#include<memory>
#include<iostream>
#include"MyString.h"
using namespace std;

int main() {
	MyString ms;
	ms = MyString();
	cout<<"空的"<<endl;
	ms.print();

	char c='c';
	ms = MyString(c);
	cout << "单字母" << endl;
	ms.print();

	char p[] = "eunice";
	ms = MyString(p);
	cout << "字符数组" << endl;
	ms.print();

	MyString ms1;
	ms1 = MyString(ms);
	cout << "拷贝构造" << endl;
	ms.print();
	ms1.print();

	MyString ms2;
	ms2 = ms;
	cout << "拷贝赋值" << endl;
	ms.print();	
	ms2.print();	
	
	//MyString ms3;
	//MyString&& mp = ms1+ms2;
	//ms3 = MyString(mp);
	//cout << "移动构造" << endl;
	//ms.print();	
	//ms3.print();	
	//
	//MyString ms4;
	//ms4 = MyString(ms1);
	//cout << "移动赋值" << endl;
	//cout << "ms1" ;
	//ms1.print();
	//ms4.print();


	return 0;
}