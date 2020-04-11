#include <iostream>
#include "Matrix.h"
using namespace std;

int main()
{
    cout<<"Warning: you should input correct matrix\n";
    matrix a('a');
    matrix b('b');
    matrix c;
    matrix d;
    matrix e;
    c=a+b;
    d=a*b;
    e=a-b;
    cout<<"this is the result of a+b\n";
    c.show();
    cout<<"this is the result of a*b\n";
    d.show();
    cout<<"this is the result of a-b\n";
    e.show();
}

