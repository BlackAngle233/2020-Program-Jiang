#include <iostream>
#include "SingleList.h"
using namespace std;
int main()
{
	int a[] = { 2,3,4 };
	SingleList *b = new SingleList();
	*b = create(a);
	print(*b);
	removenum(2, *b);
	print(*b);
	insert(2, 9,*b);
	print(*b);
	removepos(1, *b);
	print(*b);
}