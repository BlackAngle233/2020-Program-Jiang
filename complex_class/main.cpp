#include "complex.h"

int main()
{
    complex a(1, 2);
    complex b(2, 3);
    cout << "a+b=" << a + b << endl;
    cout << "b-a=" << b - a << endl;
    cout << "a*b=" << a * b << endl;
    cout << "a/b=" << a / b << endl;
    cout << "-a=" << -a << endl;

    return 0;
}