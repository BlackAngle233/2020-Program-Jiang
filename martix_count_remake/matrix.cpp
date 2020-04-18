#include <iostream>
#include "matrix.h"
using namespace std;
void martix_add(int a[][4], int b[][4],int(&c)[4][4]) {
	for(int i=0;i<4;i++)
		for (int j = 0; j < 4; j++)
		{
			c[i][j] = a[i][j] + b[i][j];
		}
}
void martix_decline(int a[][4], int b[][4], int(&c)[4][4]) {
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			c[i][j] = a[i][j] - b[i][j];
		}
}
void martix_mult(int a[][4], int b[][4], int(&c)[4][4]) {
	int temp ;
	for (int x = 0; x < 4; x++)
	{
		for (int i = 0; i < 4; i++)
		{
			temp = 0;
			for (int j = 0; j < 4; j++)
			{
				temp = temp + a[i][j] * b[j][i];
			}
			c[i][x] = temp;
		}
	}
}
void put(int c[4][4]) {


	int z = 1;//¼ÆÊý
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (z % 4 != 0)
			{
				cout << c[i][j] << " ";
				z++;
			}
			else
			{
				cout << c[i][j] << endl;
				z++;
			}
}
