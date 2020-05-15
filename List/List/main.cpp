#include <iostream>
#include "SingleList.h"
using namespace std;

int main()
{
	int num[] = { 1,2,3,4,5 };
	SingleList* list = create(num, 5);
	print(list);
	insert(list, 0);
	print(list);

	SingleList::Node* node = find(list, 4);
	cout << node->value << endl;
	remove(list, node);
	print(list);



	erase(list);
}