// SAOLEI.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void menu()
{
	printf("********************************\n");
	printf("*****  1.play      0.exit ******\n");
	printf("********************************\n");

}
void game()
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	SetMine(mine, ROW, COL);
	DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);
	FindMine(mine, show, ROW, COL);

}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		cout<<"请选择:>";
		cin >> input;
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			cout<<"退出游戏"<<endl;
			break;
		default:
			cout<<"选择错误"<<endl;
			break;
		}

	} while (input);

}
int main()
{
	test();
	system("pause");
	return 0;
}