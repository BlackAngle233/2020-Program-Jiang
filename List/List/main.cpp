#include <iostream>
#include "SingleList.h"
using namespace std;

int main()
{
	SingleList l;
	int n;
	cout << "Enter the length of the list" << endl;
	cin >> n;
	l.CreateSingleList(n);  

	cout << "the list is:" << endl;
	l.Print(); 

	int value;
	int index;
	cout << "inesrt value" << endl;
	cin >> value;
	cout << "The location of the insert" << endl;
	cin >> index;
	l.Insert(value, index); 
	cout << "the list is:" << endl;
	l.Print();

	int removevalue;
	cout << "delete value" << endl;
	cin >> removevalue;
	l.Remove(removevalue);  
	cout << "the list is:" << endl;
	l.Print();

	int num;
	cout << "Enter the node number to look for" << endl;
	cin >> num;
	cout << l.Find(num)->value << endl;  

	int i;
	cout << "delete list?" << endl;
	cout << "1.yes  2.no" << endl;
	cin >> i;
	switch (i) {
	case 1:
		l.EraseSingleList();
		break;

	case 2:
		cout << "the list is:" << endl;
		l.Print();
		break;
	}
}