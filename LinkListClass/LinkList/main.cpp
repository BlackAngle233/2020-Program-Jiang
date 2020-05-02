#include <iostream>
#include "LinkList.h"
using namespace std;
void test()
{
	int nums[5]{ 1,2,2,2,2 };
	LinkList list(nums, 5);
	list.print();
	list.insert(2);
	cout << list;
	list.remove(2);
	cout << list;
	LinkList::Node* node = new LinkList::Node();
	node->value = 3;
	list.insert(node);
	cout << list;

}

int main()
{
	test();
}