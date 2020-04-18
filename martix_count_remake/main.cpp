#include "matrix.h"
int main() {
	int a[4][4] = { { 1,1,1,1 } ,{1, 1, 1, 1} ,{1, 1, 1, 1} ,{1, 1, 1, 1} };
	int b[4][4] = { { 2,2,2,2 } ,{2, 2, 2, 2} ,{2, 2, 2, 2} ,{2, 2, 2, 2} };
	int c[4][4];
	martix_add(a, b, c);
	put(c);
	martix_decline(a, b, c);
	put(c);
	martix_mult(a, b, c);
	put(c);
}