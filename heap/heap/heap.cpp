// heap.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<vector>
using namespace std;
template <typename Comparable>
class BinaryHeap
{
public:
	explicit BinaryHeap(int capacity = 100)
		: array(capacity + 1), currentSize{ 0 } {}
	explicit BinaryHeap(const vector<Comparable> & items)
		: array(items.size() + 1), currentSize{ items.size()+1 }
	{
		for (int i = 0; i < items.size(); ++i)
			array[i + 1] = items[i];
		buildHeap();
	}
	bool isEmpty() const { return currentSize == 0; }
	const Comparable & findMin() const { if (currentSize > 1)return array[1]; else return -1; };
	void insert(const Comparable & x) { 
		array.resize(array.size() + 1);
		array[currentSize++] = x; buildHeap(); };
	void deleteMin() { if (currentSize > 1) { array[currentSize] = array[1]; buildHeap(); currentSize-- } };
	void deleteMin(Comparable & minItem);
	void makeEmpty()
	{
		currentSize = 0;
	}
public:
	vector<Comparable> array;
	size_t currentSize;
	const Comparable & findMin() { return array[0]; };
	void buildHeap() 
	{
		for (int e = currentSize / 2; e >= 1; e--)
		for (int i = currentSize / 2; i >= 1; i--)
		{
			int a = 0;
			if (i*2< currentSize&&array[i * 2] < array[i])
			{
				a = array[i * 2];
				array[i * 2] = array[i];
				array[i] = a;
				cout << i << '\t' << 2 * i << endl;
			}
			if (i * 2+1 < currentSize && array[i * 2 + 1] < array[i])
			{
				a = array[i * 2 + 1];
				array[i * 2 + 1] = array[i];
				array[i] = a;
				cout << i << '\t' << 2 * i+1 << endl;
			}
		}
	};
};
int main()
{
	int e[9] = { 5,4,3,2,1,7,8,9};
	vector<int>a(e,e+8);
	BinaryHeap<int>*a1 = new BinaryHeap<int>(a);
	a1->insert(10);
	for (int a = 0; a < 10; a++)
		cout << a1->array[a] << '\t';
    
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
