#include <iostream>
#include<iostream>
using namespace std;
float A[100], B[100];
char c;
int m = 0, n = 0, k = 0, p = 0, i = 0, j, a, u, v;
float C[10][10];
int main()
{
	cout << "please enter matrixA:" << endl;
	cin >> A[i];
	while ((c = getchar()) != '\n')
	{
		cin >> A[++i];
		if (c == ';')m++;
	}
	m++;
	i++;
	n = i / m;
	cout << "please enter matrixB:" << endl;
	cin >> B[j];
	while ((c = getchar()) != '\n')
	{
		cin >> B[++j];
		if (c == ';')k++;
	}
	k++;
	j++;
	p = j / k;
	if (n != k)
	{
		cout << "error";
		return 0;
	}
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < p; j++)
		{
			for (a = 1; a <= n; a++)
			{
				C[i][j] += A[i * n + a - 1] * B[(a - 1) * p + j];
			}
		}
	}
	cout << "A*B=" << endl;
	for (u = 0; u < m; u++)
	{
		for (v = 0; v < p; v++)
		{
			if (v != p - 1) {
				cout << C[u][v] << ",";
			}
			else {
				cout << C[u][v] << endl;
			}
		}
	}
	system("pause");
	return 0;
}