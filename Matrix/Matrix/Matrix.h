#include <iostream>
#pragma once
using namespace std;

void print_number(int a[4][4]) 
{
	for (int i = 0; i < 4; i++) {
		cout << "[";
		for (int j = 0; j < 4; j++) {
			cout << a[i][j]<<" ";
		}
		cout << "]";
		cout << endl;
		
	}
}

void input_number(int m[4][4]) 
{
	
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> m[i][j];
			
			
		}  
		
	}
}

void add(int l_number[4][4], int r_number[4][4]) 
{
	int result[4][4];
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++) 
		{
			result[i][j] = l_number[i][j] + r_number[i][j];
		}
	}
	print_number(result);
}

void substract(int l_number[4][4], int r_number[4][4]) 
{
	int result[4][4];
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			result[i][j] = l_number[i][j] - r_number[i][j];
		}
	}
	print_number(result);
}

void multiple(int l_number[4][4], int r_number[4][4]) 
{
	int result[4][4];
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			result[i][j] = l_number[i][j] * r_number[j][i];
		}
	}
	print_number(result);
}