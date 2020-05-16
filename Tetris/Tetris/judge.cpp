#include "pch.h"
#include "judge.h"
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
using namespace std;
void judge()
{
	POINT p;
	Type d;
	int a = 0;
	int row;
	int line;
	int minenum;
	bool isclick = false;
	mine1 *mineproduce = new mine1();
	cout << "输入难度 0代表easy 1代表middle 2代表hard，3代表自己设定难度" << endl;
	cin >> a;
	switch (a)
	{
	case(0):d = easy; break;
	case(1): d = middle; break;
	case(2):d = hard; break;
	case(3):d = sellfsetting; break;
	}
	if (d == easy)
	{
		row = 9; line = 9; minenum = 40;
	}
	else if (d == middle)
	{
		row = 16; line = 16; minenum = 160;
	}
	else if(d==hard)
	{
		row = 32; line = 32; minenum = 640;
	}
	else
	{
		cin >> row;
		cin >> line;
		cin >> minenum;
	}
	mineproduce->Spawnmine(row, line, minenum);

	system("cls");

	mineproduce->Born(row, line);
	while (true)
	{



		if (KEY_DOWN(MOUSE_EVENT))
		{

			GetCursorPos(&p);
			HWND h = GetForegroundWindow();
			ScreenToClient(h, &p);
			if (!isclick) 
			{
				mineproduce->mine[p.y / 16][p.x / 16] = false;
				mineproduce->Search(p.x / 16, p.y / 16, row, line);
				mineproduce->isClick[p.y / 16][p.x / 16] = true;
				

				mineproduce->Getnum(row, line);
				isclick = true;
			}

			mineproduce->Search(p.x / 16, p.y / 16, row, line);
			mineproduce->isClick[p.y / 16][p.x / 16] = true;

		
			system("cls");

			mineproduce->Born(row, line);
		
			if (mineproduce->mine[p.y / 16][p.x / 16]) 
			{
				mineproduce->showall(row, line);
				system("cls");
				mineproduce->Born(row, line);
				break;
			}
		}



	}
}
