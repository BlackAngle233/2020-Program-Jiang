#include <iostream>
#include "Matrix.h"

void test() 
{
	Matrix test;
    test.setNums();
    Matrix a;
    a.setNums();
    Matrix ans;
    ans=a*test;
	cout<<"Answer is:"<<endl;
    ans.printNums();
}

int main()
{
    std::cout << "test:\n";
	test();
}