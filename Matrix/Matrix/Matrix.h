#include <iostream>
#pragma once
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

void add(int m1[4][4], int m2[4][4]) {
	int c[4][4];
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			c[i][j] = m1[i][j] + m2[i][j];
		}
	}
	printMartix4x4(c);
}

void Minus(int m1[4][4], int m2[4][4]) {
	int d[4][4];
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			d[i][j] = m1[i][j] - m2[i][j];
		}
	}
	printMartix4x4(d);
}

void multiple(int m1[4][4], int m2[4][4]) {
	int f[4][4];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			f[i][j] = 0;
			for (int k = 0; k < 4; k++) {
				f[i][j] += m1[i][k] * m2[k][j];
			}
		}
	}
	printMartix4x4(f);
}
