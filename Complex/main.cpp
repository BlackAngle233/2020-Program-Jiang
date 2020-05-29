#include <iostream>
#include "complex.h"

using namespace std;

int main()
{
    Complex a(1, 2);
    cout << a << endl;
    Complex b = a;
    Complex *c = new Complex(2, 3);
    cout << b + *c << endl;
    cout << a * (*c) << endl;
    cout << a / (*c) << endl;
    getchar();
}