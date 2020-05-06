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
	cout << "输入难度 0代表easy 1代表middle 2代表hard" << endl;
	cin >> a;
	switch (a)
	{
	case(0):d = easy; break;
	case(1): d = middle; break;
	case(2):d = hard; break;
	}
	if (d == easy)
	{
		row = 9; line = 9; minenum = 40;
	}
	else if (d == middle)
	{
		row = 16; line = 16; minenum = 160;
	}
	else
	{
		row = 32; line = 32; minenum = 640;
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
			if (!isclick) {
				mineproduce->isClick[p.y / 16][p.x / 16] = true;
				mineproduce->mine[p.y / 16][p.x / 16] = false;
				mineproduce->Getnum(row, line);
				isclick = true;
			}

			mineproduce->Search(p.x / 16, p.y / 16, row, line);
			mineproduce->isClick[p.y / 16][p.x / 16] = true;

			/*Search(p.y / 17, p.x / 16, 8, 8);*/
			cout << p.y / 16 << " " << p.x / 16 << " " << 1 << endl;
			system("cls");

			mineproduce->Born(row, line);

			if (mineproduce->mine[p.y / 16][p.x / 16]) {
				mineproduce->showall(row, line);
				system("cls");
				mineproduce->Born(row, line);
				break;
			}
		}



	}
}
