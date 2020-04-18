#pragma once 
#include <iostream>
#include "mat4.h"
using namespace std;

void print(int m[4][4]) {
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			cout << m[i][j] << " ";
		}
		cout << endl;
	}
}

void inputMartix4x4(int m[4][4]) {
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			cin >> m[i][j];
			cout << " ";
		}
		cout << endl;
	}
}

void add4x4(int m1[4][4], int m2[4][4], int result[4][4]) {
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			result[i][j] = m1[i][j] + m2[i][j];
		}
	}
}

void minus4x4(int m1[4][4], int m2[4][4], int result[4][4]) {
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			result[i][j] = m1[i][j] - m2[i][j];
		}
	}
}

void multiple4x4(int m1[4][4], int m2[4][4], int result[4][4]) {
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			int sum = 0;
			for (int n = 0; n < 4; ++n) {
				sum += m1[i][n] * m2[n][j];
			}
			result[i][j] = sum;
		}
	}
}