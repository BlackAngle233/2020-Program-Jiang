#include <iostream>
#include "SingleList.h"

using namespace std;

int main()
{
	int num[] = { 1,2,3,4,5,4,5,1 };
	int size = 8;

	SingleList* test = new SingleList(num, size);
	test->print();

	test->insert(2);
	test->print();

	SingleList::Node* testNode = test->find(3);

	test->remove(testNode);
	test->print();

	test->remove(2);
	test->print();

	test->remove(4);
	test->print();

	test->erase();

	int t;
	cin >> t;
}