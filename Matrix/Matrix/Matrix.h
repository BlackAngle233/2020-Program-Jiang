#include <iostream>
#pragma once
#ifndef MATRIX
#define MATRIX
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
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> m[i][j];
			cout << " ";
		}
		cout << endl;
	}
}

void Add(int m1[4][4], int m2[4][4],int r1[4][4]) {
	cout << "the rusult of A add B is:" << endl;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			r1[i][j] = m1[i][j] + m2[i][j];
		}
		cout << endl;
	}
	printMartix4x4(r1);
	cout << endl;
}

void Minus(int m1[4][4], int m2[4][4], int r2[4][4]) {
	cout << "the rusult of A Minus B is:" << endl;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			r2[i][j] = m1[i][j] - m2[i][j];
		}
		cout << endl;
	}
	printMartix4x4(r2);
	cout << endl;
}

void Multiple(int m1[4][4], int m2[4][4], int r3[4][4]) {
	cout << "the rusult of A Multiple B is:" << endl;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			r3[i][j] = m1[i][j] * m2[i][j];
		}
		cout << endl;
	}
	printMartix4x4(r3);
	cout << endl;
}
#endif //MAT4_H