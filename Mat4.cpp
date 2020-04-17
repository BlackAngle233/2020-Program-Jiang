#include"Mat4.h"

void PrintMatrix(int matrix[4][4]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}
}

void AddMatrix(int mat1[4][4], int mat2[4][4], int out[4][4])
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int a = mat1[i][j];
			int b = mat2[i][j];
			out[i][j] = a + b;
		}
	}
}

void MinusMatrix(int mat1[4][4], int mat2[4][4], int out[4][4])
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int a = mat1[i][j];
			int b = mat2[i][j];
			out[i][j] = a - b;
		}
	}
}

void MultiMatrix(int mat1[4][4], int mat2[4][4], int out[4][4])
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int result = 0;

			for (int k = 0; k < 4; k++) {
				result += mat1[i][k] * mat2[k][j];
			}

			out[i][j] = result;
		}
	}
}

void InputMatrix(int input[4][4])
{
	cout << "请输入16个整数，用空格隔开(行优先)" << endl;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int in;
			cin >> in;
			input[i][j] = in;
		}
	}
}

void Test() {

	int Matrix1[4][4] = {
		{1,2,3,4},
		{5,6,7,8},
		{1,2,3,4},
		{5,6,7,8}
	};

	int Matrix2[4][4] = {
		{5,2,1,4},
		{5,6,2,8},
		{7,1,3,4},
		{5,3,3,8}
	};

	int OutPut[4][4] = {
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0}
	};

	cout << "Test:	" << endl;
	PrintMatrix(Matrix1);
	cout << endl;
	PrintMatrix(Matrix2);
	cout << endl;
	AddMatrix(Matrix1, Matrix2, OutPut);
	cout << "Add:	" << endl;
	PrintMatrix(OutPut);
	cout << endl;
	MinusMatrix(Matrix1, Matrix2, OutPut);
	cout << "Minus:	" << endl;
	PrintMatrix(OutPut);
	cout << endl;
	MultiMatrix(Matrix1, Matrix2, OutPut);
	cout << "Multi:	" << endl;
	PrintMatrix(OutPut);

}

int main() {
	cout << "输入数据" << endl;
	int m1[4][4] = {
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0}
	};
	int m2[4][4] = {
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0}
	};
	int out[4][4] = {
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0}
	};
	InputMatrix(m1);
	InputMatrix(m2);
	cout << "矩阵1：" << endl;
	PrintMatrix(m1);
	cout << "矩阵2：" << endl;
	PrintMatrix(m2);
	cout << "加运算：" << endl;
	AddMatrix(m1, m2, out);
	PrintMatrix(out);
	cout << "减运算：" << endl;
	MinusMatrix(m1, m2, out);
	PrintMatrix(out);
	cout << "乘运算：" << endl;
	MultiMatrix(m1, m2, out);
	PrintMatrix(out);
	getchar();
	getchar();
	return 0;
}