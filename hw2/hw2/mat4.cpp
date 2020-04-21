#include "pch.h"
#include "mat4.h"
#include <iostream>

using namespace std;

void ShowMat4(Mat4 a) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << a.data[i][j] << '\t';
		}
		cout << endl;
	}
}

Mat4 AddMat4(Mat4 a, Mat4 b) {
	Mat4 c;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			c.data[i][j] = a.data[i][j] + b.data[i][j];
		}
	}

	return c;
}

Mat4 SubMat4(Mat4 a, Mat4 b) {
	Mat4 c;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			c.data[i][j] = a.data[i][j] - b.data[i][j];
		}
	}

	return c;
}

Mat4 MulMat4(Mat4 a, Mat4 b) {
	Mat4 c;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			c.data[i][j] = a.data[i][0] * b.data[0][j] + a.data[i][1] * b.data[1][j] + a.data[i][2] * b.data[2][j] + a.data[i][3] * b.data[3][j];
		}
	}

	return c;
}

