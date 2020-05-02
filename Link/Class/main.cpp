#include "LinkList.h"
#include<iostream>
using namespace std;

void checkBit(int a,int n)
{
    a = a>>n;
    cout<<(a&1);
}

int main()
{
    int m[9] = {1,2,4,5,2,2,5,7,8};
    LinkList link(m,9);
    link.print();
    link.insert(12,0);
    link.print();
    link.remove(link.find(12));
    link.print();
    link.find(12);
    link.remove(2);
    link.print();
    link.erase();
    link.print();
    getchar();
    return 0;
}