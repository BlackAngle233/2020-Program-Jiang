#include <iostream>
#include "Matrix.h"

void print(Matrix* m) {
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 4;j++)
			std::cout << (*m).m[i][j] << " ";
		std::cout << std::endl;
	}
}
void input(Matrix* m) {
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 4;j++)
			std::cin >> (*m).m[i][j];
		std::cout << std::endl;
	}
}
Matrix add(Matrix* a, Matrix* b) {
	Matrix result;
	for(int i=0;i<4;i++)
		for (int j = 0;j < 4;j++)
			result.m[i][j] = a->m[i][j] + b->m[i][j];
	return result;
}
Matrix multiple(Matrix* a, Matrix* b) {
	Matrix result;
	int sum;
	for (int i = 0;i < 4;i++)
		for (int j = 0;j < 4;j++) {
			sum = 0;
			for (int t = 0;t < 4;t++)
				sum += a->m[i][t] * b->m[t][j];
			result.m[i][j] = sum;
		}
	return result;
}