#include <iostream>
#include "SingleList.h"
using namespace std;
int main()
{
	int a[] = { 2,3,4 };
	SingleList *b = new SingleList();
	*b = b->create(a);
	b->print(*b);
	b->removenum(2, *b);
	b->print(*b);
	b->insert(2, 9,*b);
	b->print(*b);
	b->removepos(1, *b);
	b->print(*b);
}