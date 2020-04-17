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
	int result[4][4];
	for (int i = 0;i < 4;i++)
		for (int j = 0;j < 4;j++) {
			result[i][j] = m1[i][j] + m2[i][j];
		}
	printMartix4x4(result);
}

void minus(int m1[4][4], int m2[4][4]) {
	int result[4][4];
	for (int i = 0;i < 4;i++)
		for (int j = 0;j < 4;j++) {
			result[i][j] = m1[i][j] - m2[i][j];
		}
	printMartix4x4(result);
}

void multiple(int m1[4][4], int m2[4][4]) {
	int result[4][4];
	int sum;
	for (int i = 0;i < 4;i++)
		for (int j = 0;j < 4;j++) {
			sum = 0;
			for (int t = 0;t < 4;t++) {
				sum += m1[i][t] * m2[t][j];
			}
			result[i][j] = sum;
		}
	printMartix4x4(result);
}