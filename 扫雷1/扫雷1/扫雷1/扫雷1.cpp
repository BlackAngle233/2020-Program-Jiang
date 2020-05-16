#include "pch.h"

#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;
int map[12][12];    
int derection[3] = { 0, 1, -1 };  
int calculate(int x, int y)
{
	int counter = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (map[x + derection[i]][y + derection[j]] == 9)
				counter++;                
	return counter;
}
void sora(int x, int y)
{
	if (calculate(x, y) == 0)
	{
		map[x][y] = 0;
		for (int i = 0; i < 3; i++)
		{                                 
			for (int j = 0; j < 3; j++)
				if (x + derection[i] <= 9 && y + derection[j] <= 9 && x + derection[i] >= 1 && y + derection[j] >= 1
					&& !(derection[i] == 0 && derection[j] == 0) && map[x + derection[i]][y + derection[j]] == -1)
					sora(x + derection[i], y + derection[j]);

		}                                                    
	}
	else
		map[x][y] = calculate(x, y);
}
void print()
{
	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			if (map[i][j] == -1 || map[i][j] == 9)
				cout << "#";
			else
				cout << map[i][j];
		}
		cout << endl;
	}
}
bool check()
{
	int counter = 0;
	for (int i = 1; i < 10; i++)
		for (int j = 1; j < 10; j++)
			if (map[i][j] != -1)
				counter++;
	if (counter == 10)
		return true;
	else
		return false;
}

int main()
{

	int i, j, x, y;
	char ch;
	srand(time(0));

	do
	{
		memset(map, -1, sizeof(map));  // 将map全部初始化为-1

		for (i = 0; i < 10; )
		{
			x = rand() % 9 + 1;
			y = rand() % 9 + 1;
			if (map[x][y] != 9)
			{
				map[x][y] = 9;
				i++;
			}
		}

		for (i = 1; i < 10; i++)
		{
			for (j = 1; j < 10; j++)
				cout << "#";
			cout << "\n";
		}
		cout << "\n";

		cout << "Please enter a location: ";
		while (cin >> x >> y)
		{
			if (map[x][y] == 9)
			{
				cout << "GAME OVER" << endl;   
				for (i = 1; i < 10; i++)
				{
					for (j = 1; j < 10; j++)
					{
						if (map[i][j] == 9)
							cout << "@";
						else
							cout << "#";
					}
					cout << endl;
				}
				break;
			}

			sora(x, y);
			print();

			if (check())
			{
				cout << "YOU WIN" << endl;
				break;
			}
			cout << "\n\n";
		}

		cout << "Do you want to play again, if true enter Yes, or enter No" << endl;
		cin >> ch;
		cout << "\n\n";
	} while (ch == 'Yes');

	return 0;
}