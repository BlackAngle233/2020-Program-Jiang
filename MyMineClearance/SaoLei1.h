#pragma once
#include<iostream>
#include<stdlib.h>
#include<sstream>
using namespace std;

class SaoLei1
{
private:
	int m[10][10];
	int n[10][10];
	int o[10][10];
public:
	SaoLei1();
	void M();
	void N();
	void O();
	void Start();
	~SaoLei1()
	{

	}
	void Play()
	{
		int i, j;
		cout << "请输入0~9的横坐标和纵坐标";
		cin >> i; cin >> j;
		if (n[i][j] == 0)
		{
			//for循环
			for (int y = i; y < 10; y++)
			{
				o[y][j] = n[y][j];
				if (n[y][j] != 0)
				{
					break;
				}
				for (int a = j; a < 10; a++)
				{
					o[y][a] = n[y][a];
					if (n[y][a] != 0)
					{
						break;
					}
					else
					{
						for (int b = y; b < 10; b++)
						{
							o[b][a] = n[b][a];
							for (int c = a; c < 10; c++)
							{
								o[b][c] = n[b][c];
								if (n[b][c] != 0)
								{
									break;
								}
								else
								{
									for (int d = b; d > -1; d--)
									{
										o[d][c] = n[d][c];
										if (n[d][c] != 0)
										{

											break;
										}
									}
								}
							}
							for (int c = a; c > -1; c--)
							{
								o[b][c] = n[b][c];
								if (n[b][c] != 0)
								{
									break;
								}
								else
								{
									for (int d = b; d > -1; d--)
									{
										o[d][c] = n[d][c];
										if (n[d][c] != 0)
										{
											break;
										}
									}
									for (int d = b; d < 9; d++)
									{
										o[d][c] = n[d][c];
										if (n[d][c] != 0)
										{
											break;
										}
									}
								}
							}
							if (n[b][a] != 0)
							{

								break;
							}
						}
					}
				}
			}
			for (int y = i; y > -1; y--)
			{
				o[y][j] = n[y][j];
				if (n[y][j] != 0)
				{
					break;
				}
				for (int a = j; a < 10; a++)
				{
					o[y][a] = n[y][a];
					if (n[y][a] != 0)
					{
						break;
					}
					else
					{
						for (int b = y; b > -1; b--)
						{
							o[b][a] = n[b][a];
							for (int c = a; c < 10; c++)
							{
								o[b][c] = n[b][c];
								if (n[b][c] != 0)
								{
									break;
								}
								else
								{
									for (int d = b; d > -1; d--)
									{
										o[d][c] = n[d][c];
										if (n[d][c] != 0)
										{

											break;
										}
									}
								}
							}
							for (int c = a; c > -1; c--)
							{
								o[b][c] = n[b][c];
								if (n[b][c] != 0)
								{
									break;
								}
								else
								{
									for (int d = b; d > -1; d--)
									{
										o[d][c] = n[d][c];
										if (n[d][c] != 0)
										{
											break;
										}
									}
									for (int d = b; d < 9; d++)
									{
										o[d][c] = n[d][c];
										if (n[d][c] != 0)
										{
											break;
										}
									}
								}
							}
							if (n[b][a] != 0)
							{

								break;
							}
						}
					}
				}
			}
			for (int y = i; y < 10; y++)
			{
				o[y][j] = n[y][j];
				if (n[y][j] != 0)
				{
					break;
				}
				for (int a = j; a > -1; a--)
				{
					o[y][a] = n[y][a];
					if (n[y][a] != 0)
					{
						break;
					}
					else
					{
						for (int b = y; b < 10; b++)
						{
							o[b][a] = n[b][a];
							if (o[b][a] != 0)
							{

								break;
							}
							for (int c = a; c < 10; c++)
							{
								o[b][c] = n[b][c];
								if (n[b][c] != 0)
								{
									break;
								}
								else
								{
									for (int d = b; d > -1; d--)
									{
										o[d][c] = n[d][c];
										if (n[d][c] != 0)
										{

											break;
										}
									}
								}
							}
							for (int c = a; c > -1; c--)
							{
								o[b][c] = n[b][c];
								if (n[b][c] != 0)
								{
									break;
								}
								else
								{
									for (int d = b; d > -1; d--)
									{
										o[d][c] = n[d][c];
										if (n[d][c] != 0)
										{
											break;
										}
									}
									for (int d = b; d < 9; d++)
									{
										o[d][c] = n[d][c];
										if (n[d][c] != 0)
										{
											break;
										}
									}
								}
							}
						}
					}
				}
			}
			for (int y = i; y > -1; y--)
			{
				o[y][j] = n[y][j];
				if (n[y][j] != 0)
				{
					break;
				}
				for (int a = j; a > -1; a--)
				{
					o[y][a] = n[y][a];
					if (n[y][a] != 0)
					{
						break;
					}
					else
					{
						for (int b = y; b > -1; b--)
						{
							for (int c = a; c < 10; c++)
							{
								o[b][c] = n[b][c];
								if (n[b][c] != 0)
								{
									break;
								}
								else
								{
									for (int d = b; d > -1; d--)
									{
										o[d][c] = n[d][c];
										if (n[d][c] != 0)
										{

											break;
										}
									}
								}
							}
							for (int c = a; c > -1; c--)
							{
								o[b][c] = n[b][c];
								if (n[b][c] != 0)
								{
									break;
								}
								else
								{
									for (int d = b; d > -1; d--)
									{
										o[d][c] = n[d][c];
										if (n[d][c] != 0)
										{
											break;
										}
									}
									for (int d = b; d < 9; d++)
									{
										o[d][c] = n[d][c];
										if (n[d][c] != 0)
										{
											break;
										}
									}
								}
							}
							if (n[b][a] != 0)
							{

								break;
							}
						}
					}
				}
			}
			
		}
		else if (n[i][j] != 0 && n[i][j] != 7)
		{
			o[i][j] = n[i][j];
		}
		else if (n[i][j] == 7)
		{
			for (int i = 0; i < 10; ++i) {
				for (int j = 0; j < 10; ++j) {
					if (n[i][j] == 7)
					{
						o[i][j] = 7;
					}
				}
			}
		}
		for (int i = 0; i < 10; ++i) {
			for (int j = 0; j < 10; ++j) {
				cout << o[i][j] << " ";
			}
			cout << endl;
		}
		if (n[i][j] == 7)
		{
			cout << "游戏结束";
		}

		cout << endl;
		while (n[i][j] == 0)
		{
			int i, j;
			cout << "请输入0~9的横坐标和纵坐标";
			cin >> i; cin >> j;

			if (n[i][j] == 0)
			{
				//for循环
				for (int y = i; y < 10; y++)
				{
					o[y][j] = n[y][j];
					if (n[y][j] != 0)
					{
						break;
					}
					for (int a = j; a < 10; a++)
					{
						o[y][a] = n[y][a];
						if (n[y][a] != 0)
						{
							break;
						}
						else
						{
							for (int b = y; b < 10; b++)
							{
								o[b][a] = n[b][a];
								for (int c = a; c < 10; c++)
								{
									o[b][c] = n[b][c];
									if (n[b][c] != 0)
									{
										break;
									}
									else
									{
										for (int d = b; d > -1; d--)
										{
											o[d][c] = n[d][c];
											if (n[d][c] != 0)
											{

												break;
											}
										}
									}
								}
								for (int c = a; c > -1; c--)
								{
									o[b][c] = n[b][c];
									if (n[b][c] != 0)
									{
										break;
									}
									else
									{
										for (int d = b; d > -1; d--)
										{
											o[d][c] = n[d][c];
											if (n[d][c] != 0)
											{
												break;
											}
										}
										for (int d = b; d < 9; d++)
										{
											o[d][c] = n[d][c];
											if (n[d][c] != 0)
											{
												break;
											}
										}
									}
								}
								if (n[b][a] != 0)
								{

									break;
								}
							}
						}
					}
				}
				for (int y = i; y > -1; y--)
				{
					o[y][j] = n[y][j];
					if (n[y][j] != 0)
					{
						break;
					}
					for (int a = j; a < 10; a++)
					{
						o[y][a] = n[y][a];
						if (n[y][a] != 0)
						{
							break;
						}
						else
						{
							for (int b = y; b > -1; b--)
							{
								o[b][a] = n[b][a];
								for (int c = a; c < 10; c++)
								{
									o[b][c] = n[b][c];
									if (n[b][c] != 0)
									{
										break;
									}
									else
									{
										for (int d = b; d > -1; d--)
										{
											o[d][c] = n[d][c];
											if (n[d][c] != 0)
											{

												break;
											}
										}
									}
								}
								for (int c = a; c > -1; c--)
								{
									o[b][c] = n[b][c];
									if (n[b][c] != 0)
									{
										break;
									}
									else
									{
										for (int d = b; d > -1; d--)
										{
											o[d][c] = n[d][c];
											if (n[d][c] != 0)
											{
												break;
											}
										}
										for (int d = b; d < 9; d++)
										{
											o[d][c] = n[d][c];
											if (n[d][c] != 0)
											{
												break;
											}
										}
									}
								}
								if (n[b][a] != 0)
								{

									break;
								}
							}
						}
					}
				}
				for (int y = i; y < 10; y++)
				{
					o[y][j] = n[y][j];
					if (n[y][j] != 0)
					{
						break;
					}
					for (int a = j; a > -1; a--)
					{
						o[y][a] = n[y][a];
						if (n[y][a] != 0)
						{
							break;
						}
						else
						{
							for (int b = y; b < 10; b++)
							{
								o[b][a] = n[b][a];
								if (o[b][a] != 0)
								{

									break;
								}
								for (int c = a; c < 10; c++)
								{
									o[b][c] = n[b][c];
									if (n[b][c] != 0)
									{
										break;
									}
									else
									{
										for (int d = b; d > -1; d--)
										{
											o[d][c] = n[d][c];
											if (n[d][c] != 0)
											{

												break;
											}
										}
									}
								}
								for (int c = a; c > -1; c--)
								{
									o[b][c] = n[b][c];
									if (n[b][c] != 0)
									{
										break;
									}
									else
									{
										for (int d = b; d > -1; d--)
										{
											o[d][c] = n[d][c];
											if (n[d][c] != 0)
											{
												break;
											}
										}
										for (int d = b; d < 9; d++)
										{
											o[d][c] = n[d][c];
											if (n[d][c] != 0)
											{
												break;
											}
										}
									}
								}
							}
						}
					}
				}
				for (int y = i; y > -1; y--)
				{
					o[y][j] = n[y][j];
					if (n[y][j] != 0)
					{
						break;
					}
					for (int a = j; a > -1; a--)
					{
						o[y][a] = n[y][a];
						if (n[y][a] != 0)
						{
							break;
						}
						else
						{
							for (int b = y; b > -1; b--)
							{
								for (int c = a; c < 10; c++)
								{
									o[b][c] = n[b][c];
									if (n[b][c] != 0)
									{
										break;
									}
									else
									{
										for (int d = b; d > -1; d--)
										{
											o[d][c] = n[d][c];
											if (n[d][c] != 0)
											{

												break;
											}
										}
									}
								}
								for (int c = a; c > -1; c--)
								{
									o[b][c] = n[b][c];
									if (n[b][c] != 0)
									{
										break;
									}
									else
									{
										for (int d = b; d > -1; d--)
										{
											o[d][c] = n[d][c];
											if (n[d][c] != 0)
											{
												break;
											}
										}
										for (int d = b; d < 9; d++)
										{
											o[d][c] = n[d][c];
											if (n[d][c] != 0)
											{
												break;
											}
										}
									}
								}
								if (n[b][a] != 0)
								{

									break;
								}
							}
						}
					}
				}
				
			}
			else if (n[i][j] != 0 && n[i][j] != 7)
			{
				o[i][j] = n[i][j];
			}
			else if (n[i][j] == 7)
			{
				for (int i = 0; i < 10; ++i) {
					for (int j = 0; j < 10; ++j) {
						if (n[i][j] == 7)
						{
							o[i][j] = 7;
						}
					}
				}
			}
			for (int i = 0; i < 10; ++i) {
				for (int j = 0; j < 10; ++j) {
					cout << o[i][j] << " ";
				}
				cout << endl;
			}
			if (n[i][j] == 7)
			{
				cout << "游戏结束";
				break;
			}
			int s = 0;
			for (int i = 0; i < 10; ++i) {
				for (int j = 0; j < 10; ++j) {
					if (o[i][j] == 9)
					{
						s++;
					}
				}
			}
			if (s == 20)
			{
				cout << "游戏胜利";
			}
		}
	}

};
void SaoLei1::Start()
{
	//随机分布地雷
	for (int i = 0; i < 10; i++)
	{
		int s = 0;
		if (i % 2 == 0)
		{
			for (int j = 0; j < 10; j++)
			{
				m[i][j] = rand() % 2;
				s = s + m[i][j];
				if (s > 2)
					m[i][j] = 0;
			}
		}
		if (i % 2 != 0)
		{
			for (int j = 9; j > -1; j--)
			{
				m[i][j] = rand() % 2;
				s = s + m[i][j];
				if (s > 2)
					m[i][j] = 0;
			}
		}
	}
	//每个格子附近的地雷数量
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (i == 0 && j == 0)
			{
				int s = 0;
				if (m[i][j] == 1)
				{
					n[i][j] = 7;
				}
				else
				{
					j++;
					if (m[i][j] == 1)
					{
						s++;
						j--;
					}
					else
					{
						j--;
					}
					i++;
					if (m[i][j] == 1)
					{
						s++;
						i--;
					}
					else
					{
						i--;
					}
					j++; i++;
					if (m[i][j] == 1)
					{
						s++;
						i--; j--;
					}
					else
					{
						i--; j--;
					}
					n[i][j] = s;
				}
			}
			else if (i == 0 && 0 < j && j < 9)
			{
				int s = 0;
				if (m[i][j] == 1)
				{
					n[i][j] = 7;
				}
				else
				{
					j--;
					if (m[i][j] == 1)
					{
						s++;
						j++;
					}
					else
					{
						j++;
					}
					j++;
					if (m[i][j] == 1)
					{
						s++;
						j--;
					}
					else
					{
						j--;
					}
					i++; j--;
					if (m[i][j] == 1)
					{
						s++;
						i--; j++;
					}
					else
					{
						i--; j++;
					}
					i++;
					if (m[i][j] == 1)
					{
						s++;
						i--;
					}
					else
					{
						i--;
					}
					i++; j++;
					if (m[i][j] == 1)
					{
						s++;
						j--; i--;
					}
					else
					{
						j--; i--;
					}
					n[i][j] = s;
				}
			}
			else if (i == 0 && j == 9)
			{
				int s = 0;
				if (m[i][j] == 1)
				{
					n[i][j] = 7;
				}
				else
				{
					j--;
					if (m[i][j] == 1)
					{
						s++;
						j++;
					}
					else
					{
						j++;
					}
					i++;
					if (m[i][j] == 1)
					{
						s++;
						i--;
					}
					else
					{
						i--;
					}
					j--; i++;
					if (m[i][j] == 1)
					{
						s++;
						j++; i--;
					}
					else
					{
						j++; i--;
					}
					n[i][j] = s;
				}

			}
			else if (0 < i && i < 9 && j == 0)
			{
				int s = 0;
				if (m[i][j] == 1)
				{
					n[i][j] = 7;
				}
				else
				{
					i--;
					if (m[i][j] == 1)
					{
						s++;
						i++;
					}
					else
					{
						i++;
					}
					i--; j++;
					if (m[i][j] == 1)
					{
						s++;
						i++; j--;
					}
					else
					{
						i++; j--;
					}
					j++;
					if (m[i][j] == 1)
					{
						s++;
						j--;
					}
					else
					{
						j--;
					}
					i++; j++;
					if (m[i][j] == 1)
					{
						s++;
						i--; j--;
					}
					else
					{
						i--; j--;
					}
					i++;
					if (m[i][j] == 1)
					{
						s++;
						i--;
					}
					else
					{
						i--;
					}
					n[i][j] = s;
				}
			}
			else if (i == 9 && j == 0)
			{
				int s = 0;
				if (m[i][j] == 1)
				{
					n[i][j] = 7;
				}
				else
				{
					i--;
					if (m[i][j] == 1)
					{
						s++;
						i++;
					}
					else
					{
						i++;
					}
					i--; j++;
					if (m[i][j] == 1)
					{
						s++;
						i++; j--;
					}
					else
					{
						i++; j--;
					}
					j++;
					if (m[i][j] == 1)
					{
						s++;
						j--;
					}
					else
					{
						j--;
					}
					n[i][j] = s;
				}
			}
			else if (i == 9 && 0 < j && j < 9)
			{
				int s = 0;
				if (m[i][j] == 1)
				{
					n[i][j] = 7;
				}
				else
				{
					j--;
					if (m[i][j] == 1)
					{
						s++;
						j++;
					}
					else
					{
						j++;
					}
					i--; j--;
					if (m[i][j] == 1)
					{
						s++;
						i++; j++;
					}
					else
					{
						i++; j++;
					}
					i--;
					if (m[i][j] == 1)
					{
						s++;
						i++;
					}
					else
					{
						i++;
					}
					i--; j++;
					if (m[i][j] == 1)
					{
						s++;
						i++; j--;
					}
					else
					{
						i++; j--;
					}
					j++;
					if (m[i][j] == 1)
					{
						s++;
						j--;
					}
					else
					{
						j--;
					}
					n[i][j] = s;
				}
			}
			else if (i == 9 && j == 9)
			{
				int s = 0;
				if (m[i][j] == 1)
				{
					n[i][j] = 7;
				}
				else
				{
					j--;
					if (m[i][j] == 1)
					{
						s++;
						j++;
					}
					else
					{
						j++;
					}
					i--; j--;
					if (m[i][j] == 1)
					{
						s++;
						j++; i++;
					}
					else
					{
						j++; i++;
					}
					i--;
					if (m[i][j] == 1)
					{
						s++;
						i++;
					}
					else
					{
						i++;
					}
					n[i][j] = s;
				}
			}
			else if (0 < i && i < 9 && j == 9)
			{
				int s = 0;
				if (m[i][j] == 1)
				{
					n[i][j] = 7;
				}
				else
				{
					i--;
					if (m[i][j] == 1)
					{
						s++;
						i++;
					}
					else
					{
						i++;
					}
					i--; j--;
					if (m[i][j] == 1)
					{
						s++;
						j++; i++;
					}
					else
					{
						j++; i++;
					}
					j--;
					if (m[i][j] == 1)
					{
						s++;
						j++;
					}
					else
					{
						j++;
					}
					i++; j--;
					if (m[i][j] == 1)
					{
						s++;
						j++; i--;
					}
					else
					{
						j++; i--;
					}
					j++;
					if (m[i][j] == 1)
					{
						s++;
						j--;
					}
					else
					{
						j--;
					}
					n[j][j] = s;
				}
			}
			else if (0 < i && i < 9 && 0 < j && j < 9)
			{
				int s = 0;
				if (m[i][j] == 1)
				{
					n[i][j] = 7;
				}
				else
				{
					i--; j--;
					if (m[i][j] == 1)
					{
						s++;
						i++; j++;
					}
					else
					{
						i++; j++;
					}
					i--;
					if (m[i][j] == 1)
					{
						s++;
						i++;
					}
					else
					{
						i++;
					}
					i--; j++;
					if (m[i][j] == 1)
					{
						s++;
						i++; j--;
					}
					else
					{
						i++; j--;
					}
					j++;
					if (m[i][j] == 1)
					{
						s++;
						j--;
					}
					else
					{
						j--;
					}
					i++; j++;
					if (m[i][j] == 1)
					{
						s++;
						i--; j--;
					}
					else
					{
						i--; j--;
					}
					i++;
					if (m[i][j] == 1)
					{
						s++;
						i--;
					}
					else
					{
						i--;
					}
					i++; j--;
					if (m[i][j] == 1)
					{
						s++;
						i--; j++;
					}
					else
					{
						i--; j++;
					}
					j--;
					if (m[i][j] == 1)
					{
						s++;
						j++;
					}
					else
					{
						j++;
					}
					n[i][j] = s;
				}
			}
		}
	}
	//显示
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			cout << "* ";
		}
		cout << endl;
	}
	cout << "游戏开始" << endl;
}
SaoLei1::SaoLei1()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			m[i][j] = 0;
		}

	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			n[i][j] = 0;
		}

	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			o[i][j] = 9;
		}

	}
}
void SaoLei1::N()
{
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			cout << n[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
void SaoLei1::M()
{
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			cout << m[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
void SaoLei1::O()
{
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			cout << o[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}