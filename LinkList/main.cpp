#include "LinkList.h"
int main()
{
	int a[5] = { 5,4,3,2,1 };
	int n = 5;
	int e;
	LinkListClass<int> l;
	l.CreatListR(a, 5);
	//l.DispList();
	e = l.ListLength();
	//cout << e;
	l.GetElem(5, e);
	//cout<<e;
	e=l.LocateElem(5);
	//cout << e;
	l.ListInsert(3, 2);
	//l.DispList();
	l.ListDelete(1);
	//l.DispList();
}