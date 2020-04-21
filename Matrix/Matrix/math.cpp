#pragma once
#include <iostream>
#include "Matrix.h"
using namespace std;
void printMartix4x4(int m[4][4]) {
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

void add(int m1[4][4], int m2[4][4], int result[4][4]) {
	
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			result[i][j] = m1[i][j] + m2[i][j];
		}
	}
	
	
}

void minus1(int m1[4][4], int m2[4][4], int result[4][4]) {
	
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			result[i][j] = m1[i][j] - m2[i][j];
		}
	}

}

void multiple(int m1[4][4], int m2[4][4], int result[4][4]) {

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			for (int a = 0; a < 4; a++) {
				result[i][j] += m1[i][a] * m2[a][j];
			}
		}
	}
	
}

void print(Max4&max) {
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			cout << max.a[i][j] << " ";
		}
		cout << endl;
	}
}
Max4 add(Max4&first, Max4&second) {
	Max4 max = {};
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			max.a[i][j] = first.a[i][j] + second.a[i][j];
		}
	}
	return max;
}