#include "mat4.h"
#include <iostream>

void matrixAdd(int** m1, int** m2, int rows, int cols)
{
	int** matrixResult = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		matrixResult[i] = new int[cols]();
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			matrixResult[i][j] = ((int*)m1 + 1 * i)[j] + ((int*)m2 + 1 * i)[j];
		}
	}
	show(matrixResult, rows, cols);
}
void matrixSub(int** m1, int** m2, int rows, int cols)
{
	int** matrixResult = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		matrixResult[i] = new int[cols]();
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			matrixResult[i][j] = ((int*)m1 + 1 * i)[j] - ((int*)m2 + 1 * i)[j];
		}
	}
	show(matrixResult, rows, cols);
}
void matrixMul(int** m1, int** m2, int rows, int cols, int rows2)
{
	int** matrixResult = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		matrixResult[i] = new int[cols]();
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			for (int k = 0; k < rows2; k++)
			{
				matrixResult[i][j] += ((int*)m1 + 1 * i)[k] * ((int*)m2 + 1 * k)[j];
			}
		}
	}
	show(matrixResult, rows, cols);
}

void show(int** m, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cout << m[i][j] << "  " << std::ends;
		}
		std::cout << std::endl;
	}
}