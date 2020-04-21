#pragma once
#include <iostream>

using namespace std;

struct Max4 {
	int a[4][4];
};
void print(Max4&max);
Max4 add(Max4&first, Max4&second);
void printMartix4x4(int m[4][4]);


void inputMartix4x4(int m[4][4]);

void add(int m1[4][4], int m2[4][4],int result[4][4]);

void minus1(int m1[4][4], int m2[4][4], int result[4][4]);

void multiple(int m1[4][4], int m2[4][4], int result[4][4]);