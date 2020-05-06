// Tetris.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include<windows.h>
#include <ctime>
#include"mine.h"
#include"judge.h"
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
using namespace std;
//int block[32][32] = {0};
//bool mine[32][32] = {false};
//bool isClick[32][32] = {false};
//enum Type { easy, middle, hard };
//void Search(int x, int y, int maxx, int maxy) {
//	if (x <= maxx&&y <= maxy&&x >= 0 && y >= 0 && mine[y][x] == false&&isClick[y][x]==false) 
//	{
//		
//		isClick[y][x] = true;
//		Search(x + 1, y, maxx, maxy);
//		Search(x, y + 1, maxx, maxy);
//		Search(x - 1, y, maxx, maxy);
//		Search(x, y - 1, maxx, maxy);
//		
//	}
//	else
//	{
//
//		return;
//	}
//}
//void showall(int maxx, int maxy) {
//	for (int a = 0; a < maxx; a++)
//		for (int b = 0; b < maxy; b++)
//			isClick[a][b] = true;
//}
//void Getnum(int maxx, int maxy) {
//	for (int a = 0; a < maxy; a++) {
//		for (int b = 0; b < maxx; b++) {
//			for (int x = -1; x <= 1; x++)
//				for (int y = -1; y <= 1; y++) {
//					if (mine[a + x][b + y] == true&& a+x <= maxx && b+y <= maxy && a+x >= 0 && b+y >= 0)
//						block[a][b]++;
//				}
//		}
//	}
//}
//
//void Spawnmine(int maxx,int maxy,int minenum) {
//	srand((int)time(0));
//	for (int a = 0; a < minenum; a++) {
//		int e = rand() % (maxx-1);
//		int f = rand() % (maxy-1);
//		mine[e][f] = true;
//	};
//}
//void Born(int maxx,int maxy) {
//	
//	for (int a = 0; a < maxx; a++) {
//		for (int b = 0; b < maxy; b++) {
//			
//				
//			if (!isClick[a][b])
//				cout << "■";
//			else if (!mine[a][b])
//				cout << block[a][b]<<" ";
//			else
//				cout << "*"<<" ";
//
//		}
//		cout << endl;
//	}
//	
//}
int main()
{
	//POINT p;
	//Type d;
	//int a = 0;
	//int row;
	//int line;
	//int minenum;
	//bool isclick = false;
	//mine1 *mineproduce = new mine1();
	//cout << "输入难度 0代表easy 1代表middle 2代表hard"<< endl;
	//cin >> a;
	//switch (a) 
	//{
	//case(0):d = easy; break;
	//case(1): d = middle; break;
	//case(2):d = hard; break;
	//}
	//if(d==easy)
	//{
	//	row = 9; line = 9; minenum = 40;
	//}
	//else if(d==middle)
	//{
	//	row = 16; line = 16; minenum = 160;
	//}
	//else
	//{
	//	row = 32; line = 32; minenum = 640;
	//}
	//mineproduce->Spawnmine(row,line,minenum);

	//system("cls");
	//
	//mineproduce->Born(row, line);
	//while (true)
	//{
	//	

	//	
	//		if (KEY_DOWN(MOUSE_EVENT))
	//		{
	//			
	//			GetCursorPos(&p);
	//			HWND h = GetForegroundWindow();
	//			ScreenToClient(h, &p);
	//			if (!isclick) {
	//				mineproduce->isClick[p.y / 16][p.x / 16] = true;
	//				mineproduce->mine[p.y / 16][p.x / 16] = false;
	//				mineproduce->Getnum(row, line);
	//				isclick = true;
	//			}

	//			mineproduce->Search(p.x / 16, p.y / 16, row, line);
	//			mineproduce->isClick[p.y / 16][p.x / 16] = true;
	//			
	//			/*Search(p.y / 17, p.x / 16, 8, 8);*/
	//			cout << p.y / 16 << " " << p.x / 16 << " "<< 1<<endl;
	//			system("cls");
	//			
	//			mineproduce->Born(row,line);
	//			
	//			if (mineproduce->mine[p.y / 16][p.x / 16]) {
	//				mineproduce->showall(row, line);
	//				system("cls");
	//				mineproduce->Born(row, line);
	//				break;
	//			}
	//		}

	//	
	//
	//}
	judge();
	
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
