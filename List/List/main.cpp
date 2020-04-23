#include <iostream>
#include "SingleList.h"

int main()
{
	int a[3] = {1, 2, 3};
	SingleList linkList=creat(a, 3);
	SingleList *p = &linkList;
	print(p);
	insert(p, 5);
	print(p);
	remove(p,find(p, 3));
	print(p);
	remove(p, 2);
	print(p);
	erase(p);
	print(p);
	return 0;
}