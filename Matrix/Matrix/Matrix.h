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
	Matrix(const int& r, const int& c, const vector<double>& values)
	{
		if (r == 0 || c == 0)    throw("wrong input");
		row = r;
		col = c;
		for (int i = 0; i < row; ++i)
		{
			vector<double> tmp;
			for (int j = 0; j < col; ++j)
			{
				tmp.push_back(values[j + i * col]);
			}
			m.push_back(tmp);
		}
	}

	Matrix(const Matrix& m1)
	{
		if (this != &m1)
		{
			row = m1.row;
			col = m1.col;
			for (int i = 0; i < row; ++i)
			{
				vector<double> tmp;
				for (int j = 0; j < col; ++j)
				{
					tmp.push_back(m1.m[i][j]);
				}
				m.push_back(tmp);
			}
		}
	}

	Matrix& operator =(const Matrix& m)
	{
		if (this != &m)
		{
			this->row = m.row;
			this->col = m.col;
			this->m.clear();
			{
				for (int i = 0; i < this->row; ++i)
				{
					vector<double> tmp;
					for (int j = 0; j < this->col; ++j)
					{
						tmp.push_back(m.m[j][i]);
					}
					this->m.push_back(tmp);
				}
			}
		}
		return *this;
	}

	Matrix& operator +(const Matrix& m)
	{
		if (this->col == m.col && this->row == m.row)
		{
			for (int i = 0; i < row; ++i)
			{
				for (int j = 0; j < col; ++j)
				{
					this->m[i][j] += m.m[i][j];
				}
			}
		}
		else    throw("wrong addition");
		return *this;
	}

	Matrix& operator -(const Matrix& m)
	{
		if (this->col == m.col && this->row == m.row)
		{
			for (int i = 0; i < row; ++i)
			{
				for (int j = 0; j < col; ++j)
				{
					this->m[i][j] -= m.m[i][j];
				}
			}
		}
		else    throw("wrong substraction");
		return *this;
	}

	Matrix& operator *(const Matrix& m)
	{
		if (this->col == m.row)
		{
			vector<double> vtmp;
			for (int i = 0; i < this->row; ++i)
			{
				for (int j = 0; j < m.col; ++j)
				{
					double itmp = 0;
					for (int k = 0; k < col; ++k)    itmp += this->m[i][k] * m.m[k][j];
					vtmp.push_back(itmp);
				}
			}
			this->col = m.col;
			this->m.clear();
			for (int i = 0; i < this->row; ++i)
			{
				vector<double> tmp;
				for (int j = 0; j < m.col; ++j)
				{
					tmp.push_back(vtmp[j + i * col]);
				}
				this->m.push_back(tmp);
			}
		}
		else    throw("wrong multiplication");
		return *this;
	}

	void transposition()
	{
		vector<double> values;
		for (int i = 0; i < col; ++i)
		{
			for (int j = 0; j < row; ++j)
			{
				values.push_back(m[j][i]);
			}
		}
		Matrix mtmp(col, row, values);
		row = mtmp.row;
		col = mtmp.col;
		m.clear();
		for (double i = 0; i < row; ++i)
		{
			vector<double> tmp;
			for (int j = 0; j < col; ++j)
			{
				tmp.push_back(mtmp.m[i][j]);
			}
			m.push_back(tmp);
		}
		return;
	}

	void print()
	{
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				cout << setw(10) << m[i][j];
			}
			cout << endl;
		}
	}

	/*double det()
	{
		double det = 0;
		if (col == row)
		{
			double* arr;
			arr = new double(col);
			for (int i = 0; i < col; ++i)
			{
				arr[i] = i;
			}
			do
			{
				int count = 0;
				for (int i = 0; i < col; i++)
				{
					for (int j = i + 1; j < col; j++)
					{
						if (arr[i] > arr[j])
						{
							count += 1;
						}
					}
				}
				if ((count & 1) == 0)
				{
					double temp = 1;
					for (int i = 0; i < row; i++)
						temp *= m[i][arr[i]];
					det += temp;
				}
				else
				{
					double temp = -1;
					for (int i = 0; i < row; i++)
						temp *= m[i][arr[i]];
					det += temp;
				}
			} while (next_permutation(arr, arr + col));
		}
		else
		{
			throw("no det");
		}
		return det;
	}

	Matrix inverse()
	{
		if (det() == 0.0)
		{
			throw("no inverse");
		}
		vector<double> adjoint;
		vector<double> tmp;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				tmp.clear();
				for (int k = 0; k < row; k++)
				{
					for (int l = 0; l < col; l++)
					{
						if (k != i && l != j)    tmp.push_back(m[k][l]);
					}
				}
				try
				{
					Matrix m1(row - 1, col - 1, tmp);
					double n = m1.det() / det();
					if ((i + j) & 1 != 0)    n = -n;
					adjoint.push_back(n);
				}
				catch (const char* e)
				{
					cerr << e << endl;
				}
			}
		}
		Matrix result(col, row, adjoint);
		result.transposition();
		return result;
	}*/
};