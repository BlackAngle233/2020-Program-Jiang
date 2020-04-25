#include <iostream>
#include<string>
#include"LinkList.h"
using namespace std;

int main() {
	Linklist list;
	Linklist *plist = &list;
	int lsize;
	int num;
	cout << "Input the size of Linklist:";
	cin >> lsize;
	plist->createList(lsize);
	plist->printList();
	Node pnode;
	Node *inNode = &pnode;
	cout << "Input the data of Node inserting:";
	//cin >> pnode.data;
	//pnode.next = NULL;
	cin >> inNode->data;
	inNode->next = NULL;
	cout << "Input the number of Node inserting after:";
	cin >> num;
	//plist->insertNode(&pnode, num);
	plist->insertNode(inNode, num);
	plist->printList();
	cout << "Input the number of Node deleting:";
	cin >> num;
	plist->deleteNode(num);
	plist->printList();
	return 0;
}