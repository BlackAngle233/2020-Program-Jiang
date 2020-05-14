#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<time.h>

HWND hwnd;

void drawmap(int map[][12], IMAGE *img);
void swap(int map[][12], int mi, int mj);
int mousedown(int map[][12]);


void initGame()
{
	initgraph(500, 500);

	srand((unsigned int)time(NULL));

	int map[12][12] = { 0 };

	int m, n, i, j;
	for (n = 0; n < 10;)
	{
		i = rand() % 10 + 1;
		j = rand() % 10 + 1;

		if (map[i][j] == 0)
		{
			map[i][j] = -1;
			n++;
		}
	}

	for (i = 1; i <= 10; i++)
	{
		for (j = 1; j <= 10; j++)
		{
			if (map[i][j] != -1)
			{
				for (m = i - 1; m <= i + 1; m++)
				{
					for (n = j - 1; n <= j + 1; n++)
					{
						if (map[m][n] == -1)
						{
							map[i][j]++;
						}
					}
				}
			}
		}
	}

	IMAGE img[12];
	loadimage(&img[0],"F:\\saolei\\Project1\\0.jpg",50,50);
	loadimage(&img[1], "F:\\saolei\\Project1\\1.jpg", 50, 50);
	loadimage(&img[2], "F:\\saolei\\Project1\\2.jpg", 50, 50);
	loadimage(&img[3], "F:\\saolei\\Project1\\3.jpg", 50, 50);
	loadimage(&img[4], "F:\\saolei\\Project1\\4.jpg", 50, 50);
	loadimage(&img[5], "F:\\saolei\\Project1\\5.jpg", 50, 50);
	loadimage(&img[6], "F:\\saolei\\Project1\\6.jpg", 50, 50);
	loadimage(&img[7], "F:\\saolei\\Project1\\7.jpg", 50, 50);
	loadimage(&img[8], "F:\\saolei\\Project1\\8.jpg", 50, 50);
	loadimage(&img[9], "F:\\saolei\\Project1\\mine.jpg", 50, 50);
	loadimage(&img[10], "F:\\saolei\\Project1\\map.jpg", 50, 50);
	loadimage(&img[11], "F:\\saolei\\Project1\\flag.jpg", 50, 50);

	while (1)
	{
		drawmap(map, img);

		if (mousedown(map) == 9)
		{
			drawmap(map, img);
			MessageBox(hwnd, "ohhh", "boom", MB_OK);
			return;
		}
	}
}

void drawmap(int map[][12],IMAGE *img)
{
	int i, j;
	for (i = 1; i <= 10; i++)
		{
			for (j = 1; j <= 10; j++)
			{
				int x = 50 * (j - 1);
				int y = 50 * (i - 1);

				switch (map[i][j])
				{
				case 9:
					putimage(x, y, &img[9]);
					break;
				case 10:
					putimage(x, y, &img[0]);
					break;
				case 11:
					putimage(x, y, &img[1]);
					break;
				case 12:
					putimage(x, y, &img[2]);
					break;
				case 13:
					putimage(x, y, &img[3]);
					break;
				case 14:
					putimage(x, y, &img[4]);
					break;
				case 15:
					putimage(x, y, &img[5]);
					break;
				case 16:
					putimage(x, y, &img[6]);
					break;
				case 17:
					putimage(x, y, &img[7]);
					break;
				case 18:
					putimage(x, y, &img[8]);
					break;

				default:
					putimage(x, y, &img[10]);
					break;
				}
			}
		}
}



int mousedown(int map[][12])
{ 
	MOUSEMSG m;
	while (1)
	{
		m = GetMouseMsg();

		int mi = m.y / 50 + 1;
		int mj = m.x / 50 + 1;

		switch (m.uMsg)
		{
		case WM_LBUTTONDOWN:
			if (map[mi][mj] > 9)
			{
				continue;
			}
			if (map[mi][mj] == 0)
			{
				swap(map, mi, mj);
			}
			else
			{
				map[mi][mj] += 10;
			}

			return map[mi][mj];
			break;
		
		case WM_RBUTTONDOWN:
			map[mi][mj] = 100;
			break;
		}
	}
}

void swap(int map[][12], int mi, int mj)
{
	map[mi][mj] = 10;
	for (int i = mi - 1; i <= mi + 1; i++)
	{
		for (int j = mj - 1; j <= mj + 1; j++)
		{
			if (i >= 1 && i <= 10 && j >= 1 && j <= 10)
			{
				if (map[i][j] < 9)
				{
					if (map[i][j] == 0)
					{
						swap(map, i, j);
					}
					else
					{
						map[i][j] += 10;
					}
				}
			}
		}
	}

}
int main()
{
	while (1)
	{
		initGame();
		if (MessageBox(hwnd, "again?", "end", MB_YESNO) == IDNO)
			break;
	}

	_getch();
	closegraph();
	return 0;
}