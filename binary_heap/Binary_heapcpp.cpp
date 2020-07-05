#include"Binary_heap.h"
heap::heap()
{
	len = 0;
	cap = MAXZ;
	T = new int[cap];
}
heap::heap(int n)
{
	len = 0;
	cap = n + MAXZ;
	T = new int[cap];
}
heap::~heap()
{
	len = 0;
	cap = 0;
	delete[] T;
}
int heap::get_ind(int e)
{
	int i;
	for (i = 1; i <= len; ++i)
		if (T[i] == e)
			return i;
	if (i > len)
		return -1;
}
void heap::up(int e)
{
	int tmp = T[e];
	int now = e;
	int f = (e / 2);
	while (now > 1)
	{
		if (T[f] > tmp)
			break;
		else
		{
			T[now] = T[f];
			now = f;
			f = (f / 2);
		}
	}
	T[now] = tmp;
}
void heap::down(int s, int t)
{
	int tmp = T[s];
	int now = s;
	int l = s * 2;
	while (l <= t)
	{
		if (l < t&&T[l] < T[l + 1])
			l += 1;
		if (tmp > T[l])
			break;
		else
		{
			T[now] = T[l];
			now = l;
			l = l * 2;
		}
	}
	T[now] = tmp;
}
void heap::interts(int e)
{
	if (len != cap)
		T[len + 1] = e;
	else
		throw"error:out of range!\n";
	up(len + 1);
	++len;

}
int heap::remove(int e)
{
	int ind = get_ind(e);
	if (ind == -1)
		return -1;
	else
	{
		T[ind] = T[len];
		down(ind, len - 1);
	}
	--len;
	return 0;
}
void heap::show()
{
	for (int i = 1; i <= len; ++i)
		cout << T[i] << " ";
	cout << endl;
}