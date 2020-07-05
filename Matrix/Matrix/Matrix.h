#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#pragma once
using namespace std;

class Matrix {
private:
	int row;
	int col;
	vector<vector<double> > m;
public:
	Matrix(const int& r, const int& c, const vector<double>& values);

	Matrix(const Matrix& m1);

	Matrix& operator =(const Matrix& m);

	Matrix& operator +(const Matrix& m);

	Matrix& operator -(const Matrix& m);

	Matrix& operator *(const Matrix& m);

	void transposition();

	void print();

	/*double det();

	Matrix inverse();*/
};