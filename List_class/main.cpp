#include "List.h"
int main()
{
	int a[3] = {1, 2, 3};
	LinkList linkList(a, 3);
    linkList.print();
    linkList.insert(5);
	linkList.print();
	linkList.remove(linkList.find(3));
	linkList.print();
	linkList.remove( 2);
	linkList.print();
    linkList.deleteList();
    linkList.print();
    return 0;
}