#pragma once
#include<iostream>
#include<stdlib.h>
#include<sstream>
using namespace std;

class SaoLei3
{
private:
	int m[20][20];
	int n[20][20];
	int o[20][20];
public:
	SaoLei3();
	void M();
	void N();
	void O();
	void Start();	
	~SaoLei3()
	{
		
	}
	void Play()
	{
		int i, j;
		cout << "请输入0~19的横坐标和纵坐标";
		cin >> i; cin >> j;	
		if (n[i][j] == 0)
			{
				//for循环
				for (int y=i; y < 20; y++)
				{
					o[y][j] = n[y][j];
					if (n[y][j] != 0)
					{
						break;
					}
					for (int a=j; a < 20; a++)
					{
						o[y][a] = n[y][a];
						if (n[y][a] != 0)
						{
							break;
						}
						else
						{
							for (int b = y; b < 20; b++)
							{
								o[b][a] = n[b][a];								
								for (int c=a; c < 20; c++)
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
								for (int c = a; c >-1; c--)
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
										for (int d = b; d <19; d++)
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
				for (int y=i; y > -1; y--)
				{
					o[y][j] = n[y][j];
					if (n[y][j] != 0)
					{
						break;
					}
					for (int a = j; a < 20; a++)
					{
						o[y][a] = n[y][a];
						if (n[y][a] != 0)
						{
							break;
						}
						else
						{
							for (int b = y; b  >-1; b--)
							{
								o[b][a] = n[b][a];
								for (int c = a; c < 20; c++)
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
										for (int d = b; d < 19; d++)
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
				for (int y=i; y < 20; y++)
				{
					o[y][j] = n[y][j];
					if (n[y][j] != 0)
					{
						break;
					}
					for (int a = j; a> -1; a--)
					{
						o[y][a] = n[y][a];
						if (n[y][a] != 0)
						{
							break;
						}
						else
						{
							for (int b = y; b < 20; b++)
							{
								o[b][a] = n[b][a];
								if (o[b][a] != 0)
								{

									break;
								}
								for (int c = a; c < 20; c++)
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
										for (int d = b; d < 19; d++)
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
				for (int y=i; y > -1; y--)
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
								for (int c = a; c < 20; c++)
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
										for (int d = b; d < 19; d++)
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
				//while循环
				/*while (n[i][j] == 0)
				{
					i--;
					while (n[i][j] == 0)
					{
						j++;
						while (n[i][j] == 0)
						{
							i++;
							while (n[i][j] == 0)
							{
								i++;
								while (n[i][j] == 0)
								{
									j--;
									while (n[i][j] == 0)
									{
										j--;
										while (n[i][j] == 0)
										{
											i--;
											while (n[i][j] == 0)
											{
												i--;
											}
										}
									}
								}
							}
						}
					}
				}*/
				/*int a = i; int b = j;
				while (n[a][b] != 0)
				{
					int d = 1;
					for (int c = 0; c < d; c++)
					{
						if (d % 2 != 0)
						{
							a--;
							if (n[a][b] == 0)
							{
								o[a][b] = "0";
							}
							else
								break;
						}
						if (d % 2 == 0)
						{
							a++;
							if (n[a][b] == 0)
							{
								o[a][b] = "0";
							}
							else
								break;
						}
					}
					if (n[a][b] != 0)
						break;
					for (int c = 0; c < d; c++)
					{
						if (d % 2 != 0)
						{
							b++;
							if (n[a][b] == 0)
							{
								o[a][b] = "0";
							}
							else
								break;
						}
						if (d % 2 == 0)
						{
							b--;
							if (n[a][b] == 0)
							{
								o[a][b] = "0";
							}
							else
								break;
						}
					}
					if (n[a][b] != 0)
						break;
					d++;
				}*/
			}
		else if (n[i][j] != 0 && n[i][j] != 7)
			{
				o[i][j] = n[i][j];
			}
		else if (n[i][j] == 7)
			{
				for (int i = 0; i < 20; ++i) {
					for (int j = 0; j < 20; ++j) {
						if (n[i][j] == 7)
						{
							o[i][j] = 7;
						}
					}
				}
			}
		for (int i = 0; i < 20; ++i) {
				for (int j = 0; j < 20; ++j) {
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
				cout << "请输入0~19的横坐标和纵坐标";
				cin >> i; cin >> j;

				if (n[i][j] == 0)
				{
					//for循环
					for (int y = i; y < 20; y++)
					{
						o[y][j] = n[y][j];
						if (n[y][j] != 0)
						{
							break;
						}
						for (int a = j; a < 20; a++)
						{
							o[y][a] = n[y][a];
							if (n[y][a] != 0)
							{
								break;
							}
							else
							{
								for (int b = y; b < 20; b++)
								{
									o[b][a] = n[b][a];
									for (int c = a; c < 20; c++)
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
											for (int d = b; d < 19; d++)
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
						for (int a = j; a < 20; a++)
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
									for (int c = a; c < 20; c++)
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
											for (int d = b; d < 19; d++)
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
					for (int y = i; y < 20; y++)
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
								for (int b = y; b < 20; b++)
								{
									o[b][a] = n[b][a];
									if (o[b][a] != 0)
									{

										break;
									}
									for (int c = a; c < 20; c++)
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
											for (int d = b; d < 19; d++)
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
									for (int c = a; c < 20; c++)
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
											for (int d = b; d < 19; d++)
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
					for (int i = 0; i < 20; ++i) {
						for (int j = 0; j < 20; ++j) {
							if (n[i][j] == 7)
							{
								o[i][j] = 7;
							}
						}
					}
				}
				for (int i = 0; i < 20; ++i) {
					for (int j = 0; j < 20; ++j) {
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
				for (int i = 0; i < 20; ++i) {
					for (int j = 0; j < 20; ++j) {
						if (o[i][j] == 9)
						{
							s++;
						}
					}
				}
				if (s == 80)
				{
					cout << "游戏胜利";
				}
		}
	}
	
};
void SaoLei3::Start()
{
	//随机分布地雷
	for (int i = 0; i < 20; i++)
	{
		int s = 0;
		if (i % 2 == 0)
		{
			for (int j = 0; j < 20; j++)
			{
				m[i][j] = rand() % 2;
				s = s + m[i][j];
				if (s > 4)
					m[i][j] = 0;
			}
		}
		if (i % 2 != 0)
		{
			for (int j = 19; j > -1; j--)
			{
				m[i][j] = rand() % 2;
				s = s + m[i][j];
				if (s > 4)
					m[i][j] = 0;
			}
		}
	}
	//每个格子附近的地雷数量
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
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
			else if (i == 0 && 0 < j && j < 19)
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
			else if (i == 0 && j == 19)
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
			else if (0 < i && i < 19 && j == 0)
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
			else if (i == 19 && j == 0)
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
			else if (i == 19 && 0 < j && j < 19)
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
			else if (i == 19 && j == 19)
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
			else if (0 < i && i < 19 && j == 19)
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
			else if (0 < i && i < 19 && 0 < j && j < 19)
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
	for (int i = 0; i < 20; ++i)
	{
		for (int j = 0; j < 20; ++j)
		{
			cout << "* ";
		}
		cout << endl;
	}
	cout << "游戏开始" << endl;
}
SaoLei3::SaoLei3()
{
	for (int i = 0; i < 20; i++)
	{
			for (int j = 0; j < 20; j++)
			{
				m[i][j] = 0;
			}

	}
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			n[i][j] = 0;
		}

	}
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			o[i][j] =9;
		}

	}
}
void SaoLei3::N()
{
	for (int i = 0; i < 20; ++i)
	{
		for (int j = 0; j < 20; ++j)
		{
			cout << n[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
void SaoLei3::M()
{
	for (int i = 0; i < 20; ++i) {
		for (int j = 0; j < 20; ++j) {
			cout << m[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
void SaoLei3::O()
{
	for (int i = 0; i < 20; ++i) {
		for (int j = 0; j < 20; ++j) {
			cout << o[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}