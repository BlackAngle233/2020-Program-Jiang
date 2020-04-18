#include <iostream>
#pragma once
using namespace std;

struct Mat4 {
	int m[4][4];
};

void initMat4(Mat4& Matrix) {
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			cin >> Matrix.m[i][j];
			cout << " ";
		}
		cout << endl;
	}
}

void print(Mat4& Matrix) {
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			cout << Matrix.m[i][j] << " ";
		}
		cout << endl;
	}
}

Mat4 add(const Mat4& Matrix1, const const Mat4& Matrix2) {
	Mat4 newMatrix;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			newMatrix.m[i][j] = Matrix1.m[i][j] + Matrix2.m[i][j];
		}
	}
	return newMatrix;
}

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

void Add(int m1[4][4], int m2[4][4]) {
	int result[4][4];
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			result[i][j] = m1[i][j] + m2[i][j];
		}
	}
	printMartix4x4(result);
}

void Minus(int m1[4][4], int m2[4][4]) {
	int result[4][4];
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			result[i][j] = m1[i][j] - m2[i][j];
		}
	}
	printMartix4x4(result);
}

void Multiple(int m1[4][4], int m2[4][4]) {
	int result[4][4];
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			result[i][j] = m1[i][0] * m2[0][j] + m1[i][1] * m2[1][j] + m1[i][2] * m2[2][j] + m1[i][3] * m2[3][j];
		}
	}
	printMartix4x4(result);
}