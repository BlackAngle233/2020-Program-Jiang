#pragma once
#include <iostream>

struct Matrix {
	int m[4][4];
};
void print(Matrix* m);
void input(Matrix* m);
Matrix add(Matrix* a, Matrix* b);
Matrix multiple(Matrix* a, Matrix* b);