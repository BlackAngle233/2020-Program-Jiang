#include <iostream>
#include "SingleList.h"
using namespace std;

int main()
{
	cout << "Hello World!\n"; 
	SingleList l;
	int n;
	cout << "���������" << endl;
	cin >> n;
	l.CreateSingleList(n);  //��������

	cout << "����Ϊ" << endl;
	l.Print();  //��ӡ����

	int value;
	int index;
	cout << "���������" << endl;
	cin >> value;
	cout << "�����λ��" << endl;
	cin >> index;
	l.Insert(value,index);  //����value
	cout << "����Ϊ" << endl;
	l.Print();

	int removevalue;
	cout << "Ҫɾ������" << endl;
	cin >> removevalue;
	l.Remove(removevalue);  //ɾvalue
	cout << "����Ϊ" << endl;
	l.Print();

	int num;
	cout << "����Ҫ���ҵĽڵ��" << endl;
	cin >> num;
	cout << l.Find(num)->value << endl;  //���ҽڵ������

	int i;
	cout << "�Ƿ�ɾ������" << endl;
	cout << "1.��  2.����" << endl;
	cin >> i;
	switch (i) {
	case 1:
		l.EraseSingleList();
		break;

	case 2:
		cout << "����Ϊ" << endl;
		l.Print();
		break;
	}
}