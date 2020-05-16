
#include "pch.h"
#include "mine.h"
#include <ctime>
#include<vector>
using namespace std;

void mine1::Search(int x, int y, int maxx, int maxy)
{
	if (x <= maxx && y <= maxy && x >= 0 && y >= 0 && mine1::mine[y][x] == false && mine1::isClick[y][x] == false)
	{

		mine1::isClick[y][x] = true;
		Search(x + 1, y, maxx, maxy);
		Search(x, y + 1, maxx, maxy);
		Search(x - 1, y, maxx, maxy);
		Search(x, y - 1, maxx, maxy);

	}
	else
	{

		return;
	}
};

void mine1::showall(int maxx, int maxy)
{
	for (int a = 0; a < maxx; a++)
		for (int b = 0; b < maxy; b++)
			mine1::isClick[a][b] = true;
};

void mine1::Getnum(int maxx, int maxy)
{
	for (int a = 0; a < maxy; a++) {
		for (int b = 0; b < maxx; b++) {
			for (int x = -1; x <= 1; x++)
				for (int y = -1; y <= 1; y++) {
					if (mine1::mine[a + x][b + y] == true && a + x <= maxx && b + y <= maxy && a + x >= 0 && b + y >= 0)
						mine1::block[a][b]++;
				}
		}
	}
};

void mine1::Spawnmine(int maxx, int maxy, int minenum)
{
	class  point
	{
	public:
		int x;
		int y;
		point(int xx, int yy)
		{
		x = xx;
		y = yy;
		}
	};

	point*points[1500];
	int c = 0;
	for (int a = 0; a < maxx; a++)
		for (int b = 0; b < maxy; b++) {
			points[c] = new point(a, b);
			c++;
		}
	srand((int)time(0));
	
	int all = maxx * maxy - 1;
	while (minenum > 0) 
	{
		
		int e = rand() % (all);


		mine1::mine[points[e]->x][points[e]->y] = true;

		swap(points[e], points[all]);
		all--;
		minenum--;
	}
		
	
};

void mine1::Born(int maxx, int maxy)
{
	for (int a = 0; a < maxx; a++) 
	{
		for (int b = 0; b < maxy; b++) 
		{


			if (!mine1::isClick[a][b])
				cout << "¡ö";
			else if (!mine1::mine[a][b])
				cout << mine1::block[a][b] << " ";
			else
				cout << "*" << " ";

		}
		cout << endl;
	}
};


