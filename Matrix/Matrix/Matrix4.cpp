#include <iostream>
#include "Matrix4.h"
using namespace std;

void printMartix4x4(const Mat& m1) {
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			cout << m1.m[i][j] << " ";
		}
		cout << endl;
	}
}

void inputMartix4x4(Mat& m1) {
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			cin >> m1.m[i][j];
			cout << " ";
		}
		cout << endl;
	}
}

Mat add(const Mat& m1, const Mat& m2) {
	Mat result;
	
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			result.m[i][j] = m1.m[i][j] + m2.m[i][j];

		}
	}
	return result;
}
Mat minus(const Mat& m1, const Mat& m2) {
	Mat result;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			result.m[i][j] = m1.m[i][j] - m2.m[i][j];

		}
	}
	return result;
}

Mat multiple(const Mat& m1, const Mat& m2) {
	Mat result;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			result.m[i][j] = 0;
			for (int k = 0; k < 4; k++) {
				result.m[i][j] += m1.m[i][k] * m2.m[k][i];
			}

		}
	}
	return result;
}