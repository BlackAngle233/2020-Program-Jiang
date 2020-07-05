#pragma once
#include<iostream>
using namespace std;
#define MAXZ 100
#define RES 10
class heap {
	int *T;
	int cap;
	int len;
public:
	heap();
	heap(int);
	~heap();
	void up(int);
	void down(int, int);
	void interts(int);
	int remove(int);
	void show();
	int get_ind(int);
};

