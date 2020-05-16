#include <iostream>
#include "SingleList.h"
using namespace std;
int main() {
	int a[] = { 1,2,3,4,5 };
	int i = 0;
	int len = 1;
	while (a[i] != NULL) {
		i++;
		len++;
	}
	LinkList*list = new LinkList(a, len);
	list->print();
	Node* node = list->find(5);
	list->insert(node, 6);
	list->print();
	list-> erase();
	list->print();
}
