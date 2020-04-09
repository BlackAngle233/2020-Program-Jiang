#include <iostream>
#include<algorithm>
using namespace std;

const int MAX{ 50 };
int a[MAX], b[MAX];
int n{};
#pragma region MergeSort //归并排序基础上加个count统计逆序数
int sum{};
void Merge(int a[], int start, int mid, int end)
{
	int i = start, k = start, j = mid + 1;
	while (i <= mid && j <= end)
	{
		if (a[i] <= a[j])
			b[k++] = a[i++];
		else
		{
			sum += j - k;
			b[k++] = a[j++];
		}
	}

	while (i <= mid)
		b[k++] = a[i++];
	while (j <= end)
		b[k++] = a[j++];

	for (int i = start; i <= end; ++i)
		a[i] = b[i];
}

void MergeSort(int a[], int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		MergeSort(a, start, mid);//对左半边数组排序
		MergeSort(a, mid + 1, end);//对右半边数组排序
		Merge(a, start, mid, end);//合并左右数组
	}
}

#pragma endregion

#pragma region DoubleFor//暴力两边for
int GetReverseOrders(int a[], int length)
{
	int count{};
	for (int i = 0; i < length; ++i)
		for (int j = i + 1; j < length; ++j)
		{
			if (a[i] > a[j])
				count++;
		}
	return count;
}

void PrintPairs(int a[], int length)
{
	int count{};
	for (int i = 0; i < length; ++i)
		for (int j = i + 1; j < length; ++j)
		{
			if (count % 3 == 0)
				cout << endl;
			cout << "( " << a[i] << ", " << a[j] << " )";
			count++;
		}
	cout << endl;
}


#pragma endregion

#pragma region TrieArray//树状数组
struct Node//用order实现离散化,来保证getSum[i]是比i小的个数
{
	int value;
	int order;
}input[MAX];

int LowBit(int i)
{
	return (i & (-i));
}

void Update(int t, int v)//在第t个位置加v
{
	for (int i = t; i <= n; i += LowBit(i))
	{
		b[i] += v;
	}
}

int GetSum(int t)
{
	int temp{};
	for (int i = t; i >= 1; i -= LowBit(i))
	{
		temp += b[i];
	}
	return temp;
}

bool cmp(Node a, Node b)
{
	return a.value < b.value;
}
#pragma endregion
//测试双循环
void test1()
{
	cout << "please input the length of the array :" << endl;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	PrintPairs(a, n);
	cout << "  ——————————O(n^2)——————————" << endl;

	cout << "the number of reverse orders is :" << GetReverseOrders(a, n) << endl;
}
//测试归并
void test2()
{
	//cout << "——————————MergeSort——————————" << endl;
	cout << "please input the length of the array :" << endl;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	PrintPairs(a, n);
	MergeSort(a, 0, n - 1);
	cout << "the number of reverse orders is :" << sum << endl;

}
//测试树状数组
void test3()
{
	cout << "  ——————————TireArray——————————" << endl;
	cout << "please input the length of the array :" << endl;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> input[i].value;
		input[i].order = i;
	}
	sort(input + 1, input + n + 1, cmp);

	for (int i = 1; i <= n; ++i) //离散化
		a[input[i].order] = i;
	memset(b, 0, sizeof(b));

	for (int i = 1; i <= n; ++i)
	{
		Update(a[i], 1);
		sum += i - GetSum(a[i]);
	}

	cout << "the number of reverse orders is :" << sum << endl;
}
int main()
{
	//test1();
	//test3();
	test2();
	
}


