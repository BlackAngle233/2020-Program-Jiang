#include <iostream>
#include "SingleList.h"

int main()
{
	Node*List1 = creatList(5);
	insertList(List1, 4, 2);
	removeList(List1, 3);
	findList(List1, 3);
	printList(List1);
	eraseList(List1);
}