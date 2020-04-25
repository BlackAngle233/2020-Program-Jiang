#include "matrix.h"
#include <iostream>
using namespace std;

int main()
{
    int a[4][4] {{1,2,3,4},
                    {5,6,7,8},
                    {1,2,3,4},
                    {5,6,7,8}};

    int b[4][4]  {{1,2,3,4},
                    {1,2,3,4},
                    {1,2,2,2},
                    {3,4,3,2}};


    Matrix4d Ma(a);
    Matrix4d Mb(b);

    Matrix4d ansPlus = Ma+Mb;
    Matrix4d ansSubs = Ma-Mb;
    Matrix4d ansMultiply = Ma * Mb;

    cout << "Matrix a is :" << endl;
    Ma.output();

    cout << "Matrix b is :" << endl;
    Mb.output();

    cout << "The answer of a + b is:" << endl;
    ansPlus.output();


    cout << "The answer of a - b is:" << endl;
    ansSubs.output();

    cout << "The answer of a * b is:" << endl;
    ansMultiply.output();



   return 0;
}
