#include <iostream>
#include "SingleList.h"

using namespace std;

int main()
{
	int num[] = { 1,2,3,4,5,4,5,1 };
	int size = 8;

	SingleList* test = create(num, size);
	print(test);

	insert(test, 2);
	print(test);

	SingleList::Node* testNode = find(test, 3);

	remove(test, testNode);
	print(test);

	remove(test, 2);
	print(test);

	remove(test, 4);
	print(test);

	erase(test);

	int t;
	cin >> t;
}