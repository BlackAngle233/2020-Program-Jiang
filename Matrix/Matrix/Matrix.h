#include <iostream>
#pragma once
using namespace std;

void printMartix4x4(int m[4][4]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << m[i][j] << " ";
		}
		cout << endl;
	}
}

void inputMartix4x4(int m[4][4]) {
	cout << "Matrix:" << endl;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> m[i][j];
		}
		cout << endl;
	}
}

void add4x4(int m1[4][4], int m2[4][4]) {
	int result[4][4];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			result[i][j] = m1[i][j] + m2[i][j];
		}
	}
	cout << "addMatrix:" << endl;
	printMartix4x4(result);
}

void minus4x4(int m1[4][4], int m2[4][4]) {
	int result[4][4];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			result[i][j] = m1[i][j] - m2[i][j];
		}
	}
	cout << "minuxMatrix:" << endl;
	printMartix4x4(result);
}

void multiple4x4(int m1[4][4], int m2[4][4]) {
	int result[4][4];
	int sum = 0;
	for (int i = 0; i < 4; i++) {
		for (int k = 0; k < 4; k++) {
			for (int j = 0; j < 4; j++){
				sum += m1[i][j] * m2[j][k];
			}
			result[i][k] = sum;
			sum = 0;
		}
	}
	cout << "multipleMatrix:" << endl;
	printMartix4x4(result);
}