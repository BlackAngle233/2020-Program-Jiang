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
	SingleList* list;
	list = create(a, len);
	print(list);
	SingleList::Node* node = find(list, 5);
	insert(list, node, 6);
	print(list);
	erase(list);
	print(list);
}
