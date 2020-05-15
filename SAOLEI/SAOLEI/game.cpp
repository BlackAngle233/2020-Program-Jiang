#include "game.h"
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	memset(board, set, rows*cols * sizeof(board[0][0]));
}
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= row; i++)
	{
		cout << i << " ";
	}
	cout << endl;
	for (i = 1; i <= row; i++)
	{
		cout << i<<" ";
		for (j = 1; j <= col; j++)
		{
			cout << board[i][j]<<" ";
		}
		cout << endl;
	}
	cout << endl;
}
void SetMine(char board[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int count = EASY_COUNT;
	while (count)
	{
		x = rand() % 9 + 1;
		y = rand() % 9 + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;

		}
	}


}

int GetMineCount(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] - 8 * '0';
}

void Open(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
	int ret = 0;
	ret = GetMineCount(mine, x, y);
	if (ret == 0)
	{
		show[x][y] = ' ';
		if (x - 1 > 0 && y > 0 && show[x - 1][y] == '*')
			Open(mine, show, x - 1, y);

		if (x - 1 > 0 && y + 1 <= COL && show[x - 1][y + 1] == '*')
			Open(mine, show, x - 1, y + 1);

		if (x > 0 && y + 1 <= COL && show[x][y + 1] == '*')
			Open(mine, show, x, y + 1);

		if (x + 1 < ROW && y + 1 <= COL && show[x + 1][y + 1] == '*')
			Open(mine, show, x + 1, y + 1);

		if (x + 1 <= ROW && y > 0 && show[x + 1][y] == '*')
			Open(mine, show, x + 1, y);

		if (x + 1 <= ROW && y - 1 > 0 && show[x + 1][y - 1] == '*')
			Open(mine, show, x + 1, y - 1);

		if (x > 0 && y - 1 > 0 && show[x][y - 1] == '*')
			Open(mine, show, x, y - 1);

		if (x - 1 > 0 && y - 1 > 0 && show[x - 1][y - 1] == '*')
			Open(mine, show, x - 1, y - 1);

	}
	else
	{
		show[x][y] = GetMineCount(mine, x, y) + '0';

	}

}

int IsWin(char show[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	int c = 0;
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
		{
			if (show[i][j] == '*')
			{
				c++;
			}
		}
	}
	return c;
}

void Safe(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int count = 0;

	int a = 0;
	int b = 0;
	cout << "请输入要排查的坐标:";
	cin >> x >> y;
	a = x;
	b = y;
	if (mine[x][y] == '1')
	{
		mine[x][y] = '0';
		while (1)
		{
			x = rand() % 9 + 1;
			y = rand() % 9 + 1;
			if (mine[x][y] == '0')
			{
				mine[x][y] = '1';
			}
			break;
		}

	}
	Open(mine, show, a, b);
	DisplayBoard(mine, row, col);
	DisplayBoard(show, row, col);
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		cout<<"请输入要排查的坐标:>";
		cin >> x >> y;
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				cout << "你被炸死了!" << endl;
				DisplayBoard(mine, row, col);
				break;
			}
			else
			{
				int count = 0;
				count = GetMineCount(mine, x, y);
				show[x][y] = count + '0';
				Open(mine, show, x, y);
				DisplayBoard(show, row, col);
				if (IsWin(show, row, col) == EASY_COUNT)
				{
					cout<<"恭喜你，排雷成功！"<<endl;
					DisplayBoard(mine, row, col);
					break;
				}
			}
		}
		else
		{
			cout<<"坐标非法" << endl;
		}
	}

}