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
    int m[6] = {1,2,4,5,2,2};
    LinkList* link = create(m,6);
    print(link);
    insert(link,12,0);
    print(link);
    remove(link,2);
    print(link);
    find(link,12);
    erase(link);
    print(link);
    getchar();
    return 0;
}