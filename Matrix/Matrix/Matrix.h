#include <iostream>
#include <cstdarg>
#pragma once
using namespace std;

void printMartix4x4(int m[4][4]) {
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			cout << m[i][j] << " ";
		}
	}
}

void inputMartix4x4(int m[4][4]) {
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			cin >> m[i][j];
			cout << " ";
		}
	}
}

void add(int m1[4][4], int m2[4][4]) {
	int result[4][4];
	
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			result[i][j] = m1[i][j] + m2[i][j];
		}
	}

	printMartix4x4(result);
}

void substract(int m1[4][4], int m2[4][4]) {
	int result[4][4];

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			result[i][j] = m1[i][j] - m2[i][j];
		}
	}

	printMartix4x4(result);
}

void multiple(int m1[4][4], int m2[4][4]) {
	int result[4][4];

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int sum = 0;
			for (int x = 0; x < 4; x++) {
				sum += m1[i][x] * m2[x][j];
			}
			result[i][j] = sum;
		}
	}

	printMartix4x4(result);
}

