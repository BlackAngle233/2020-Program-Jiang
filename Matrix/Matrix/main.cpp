#include<iostream>
#include"Matrix.h"

void test() {
	Matrix a = { {{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}} };
	Matrix b = { {{1,2,3,4},{2,2,3,4},{3,3,4,4},{1,2,3,4}} };
	Matrix res;
	std::cout << "Matrix1:" << std::endl;
	print(&a);
	std::cout << "Matrix2:" << std::endl;
	print(&b);
	res = add(&a, &b);
	std::cout << "Matrix1+Matrix2=" << std::endl;
	print(&res);
	res = multiple(&a, &b);
	std::cout << "Matrix1*Matrix2=" << std::endl;
	print(&res);
}

int main() {
	test();
	return 0;
}