#include <iostream>
using namespace std;

void printMartix4x4(int m[4][4]) {
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			cout << m[i][j] << " ";
		}
		cout << endl;
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

void minu(int m1[4][4], int m2[4][4]) {
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
			result[i][j] = m1[i][j] * m2[j][i];
		}
	}

	printMartix4x4(result);
}
void test()
{
	int a[4][4];
	printMartix4x4(a);
}

int main()
{
	int a[4][4] = { 1,2,3,4,5,6,7,8,1,2,3,4,5,6,7,8 };
	int b[4][4] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };

	cout << "test:\n";
	printMartix4x4(a);
	cout << "\n";
	printMartix4x4(b);
	cout << "\n";
	cout << "test(+):\n";
	add(a, b);
	cout << "test(-):\n";
	minu(a, b);
	cout << "test(*):\n";
	multiple(a, b);
	cout << "\n";
}