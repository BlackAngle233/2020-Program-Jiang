#include<memory>
#include<iostream>
#include"MyString.h"
using namespace std;

int main() {
	MyString ms;
	ms = MyString();
	cout<<"�յ�"<<endl;
	ms.print();

	char c='c';
	ms = MyString(c);
	cout << "����ĸ" << endl;
	ms.print();

	char p[] = "eunice";
	ms = MyString(p);
	cout << "�ַ�����" << endl;
	ms.print();

	MyString ms1;
	ms1 = MyString(ms);
	cout << "��������" << endl;
	ms.print();
	ms1.print();

	MyString ms2;
	ms2 = ms;
	cout << "������ֵ" << endl;
	ms.print();	
	ms2.print();	
	
	//MyString ms3;
	//MyString&& mp = ms1+ms2;
	//ms3 = MyString(mp);
	//cout << "�ƶ�����" << endl;
	//ms.print();	
	//ms3.print();	
	//
	//MyString ms4;
	//ms4 = MyString(ms1);
	//cout << "�ƶ���ֵ" << endl;
	//cout << "ms1" ;
	//ms1.print();
	//ms4.print();


	return 0;
}