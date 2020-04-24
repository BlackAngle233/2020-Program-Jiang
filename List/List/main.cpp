#include <iostream>
#include "SingleList.h"
using namespace std;

int main()
{
	int m[4] = { 1,2,3,4 };
	SingleList* s;
	s= Create(m, 4);
	Print(s);
	Insert(s, 5, 5);
	Remove(s, 4);
	Find(s, 3); 
	Erase(s);
}