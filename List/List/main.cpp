#include <iostream>
#include "SingleList.h"


int main()
{
	int num[] = { 1,2,3,4,5 };
	SingleList* list = create(num, 5);
	print(list);
}