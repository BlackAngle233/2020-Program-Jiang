#pragma once
#include <vector>
using namespace std;

//¶ÑµÄÊµÏÖ C++
template<typename Comparable>
class BinaryHeap
{
public:
	explicit BinaryHeap(int capacity = 100)
		:array_(capacity + 1), currentSize{ 0 } {}
	~BinaryHeap() { delete array; }
	explicit BinaryHeap(const vector<Comparable>& items)
		:array_(items.size() + 10), currentSize{ items.size() }
	{
		for (int i = 0; i < items.size(); i++)
			array_[i + 1] = items[i];
		buildHeap();
	}
	bool isEmpty() const { return currentSize == 0; }
	const Comparable& findMin() const
	{
		if (currentSize == 0)
			return nullptr;
		return array_[0];
	}
	void insert(const Comparable& x)
	{
		currentSize = currentSize + 1;
		int i = currentSize;
		array_[i] = x;
		while (i > 1 and array_[i / 2] > array_[i])
		{
			exchange(array_[i], array_[i / 2]);
			i = i / 2;
		}
	}
	void deleteMin()
	{
		if (isEmpty()) return;
		swap(array_[0], array_[currentSize - 1]);
		int index = 1;
		while (2 * index <= currentSize)
		{
			int child = 2 * index;
			if (child < currentSize && array[child + 1] < array_[child]) child--;
			if (array_[index] > array_[child])
			{
				swap(array_[index], array_[child]);
				index = child;
			}
			else break;
		}
	}
	void deleteMin(Comparable& minItem);
	void makeEmpty()
	{
		currentSize = 0;
	}
	void buildHeap(vector<Comparable> array_, size_t currentSize)
	{
		int temp = 0, index = 0;
		for (int i = currentSize / 2; i >= 1; i--)
		{
			temp = array_[i];
			index = 2 * i;
			while (index <= currentSize)
			{
				if (index < currentSize && array_[index + 1] < array_[index]) index++;
				if (array_[index] > temp) break;
				array_[index / 2] = array_[index];
				index *= 2;
			}
			array_[index / 2] = temp;
		}
	}
private:
	vector<Comparable> array_;
	size_t currentSize;
};
