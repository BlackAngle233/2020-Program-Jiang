#include <iostream>
#include "SingleList.h"

int main()
{
	SingleList s;
	s.create();
	s.insert(0, 9);
	s.print();
	system("pause");
}