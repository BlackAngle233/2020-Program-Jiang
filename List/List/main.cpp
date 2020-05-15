#include <iostream>
#include "SingleList.h"
using namespace std;

void test()
{
	int a[5] = { 1,2,3,4,5 };
	LinkList* linklist = new LinkList(a, 5);
	linklist->Print();
	linklist->insert(5);
	linklist->Print();
	Node* p = linklist->find(4);
	cout << p->value << "->" << p->next->value << endl;
	linklist->remove(p);
	linklist->Print();
	linklist->remove(5);
	linklist->Print();

	//int a[5] = { 1,2,3,4,5 };
	//LinkList* linklist = new LinkList(a, 5);
	//Print(linklist);
	//insert(linklist, 5);
	//Print(linklist);
	//LinkList::Node* p = find(linklist, 4);
	//cout << p->value << "->" << p->next->value << endl;
	//remove(linklist, p);
	//Print(linklist);
	//remove(linklist, 5);
	//Print(linklist);
	//erase(linklist);
	//Print(linklist);
}

int main()
{
	test();
	return 0;
}