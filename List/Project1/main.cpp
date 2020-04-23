#include <iostream>
#include "Linklist.h"

int main()
{
	LinkList head;
	int val[5] = { 2,3,4,4,5 };

	cout << "creat:"<<endl;
	head.Create(val);
	head.Print();

	cout << "remove:(4)" << endl;
	head.Remove(4);
	head.Print();
	head.Create(val);

	cout << "erase:(4)" << endl;
	head.erase(4);
	head.Print();	
	head.Create(val);

	cout << "insert:(3)-after-pos-(3)" << endl;
	head.Insert(3,3);
	head.Print();
	head.Create(val);

	cout << "find:pos-of-(4)" << endl;
	cout << "pos-of-(4) is ";
	head.Find(4);
	head.Create(val);
}