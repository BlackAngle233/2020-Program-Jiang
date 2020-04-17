#pragma once

#ifndef _MAT4_H_
#define _MAT4_H_


void matrixAdd(int** m1, int** m2, int rows, int cols);
void matrixSub(int** m1, int** m2, int rows, int cols);
void matrixMul(int** m1, int** m2, int rows, int cols, int rows2);

void show(int** m, int rows, int cols);


#endif // !_MAT4_H_

