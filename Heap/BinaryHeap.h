#include <iostream>
#include <vector>
using namespace std;

class Node {
public :
    int value;
public :
    Node(int v = 0) : value(v) {}
};

class Heap {
    vector<Node> heap;
    int heap_size;

    int Left(int i) {return (i << 1) + 1;}
    int Right(int i) {return Left(i) + 1;}
    int Parent(int i) {return (i - 1) >> 1;}
    void MaxHeapify(int i);  //使结点i维持最大堆性质(向下维护)
    void MinHeapify(int i);  //使结点i维持最小堆性质(向下维护)
    void IncreaseKey(int i, int k);  //将结点i的value上升到k(向上维护)
public :
    Heap() : heap_size(0) {}
    Heap(vector<Node> &t) : heap(t), heap_size(t.size()) {}
    void BuildMaxHeap();     //建立最大堆，时间复杂度O(n);
    void BuildMinHeap();     //建立最小堆，时间复杂度O(n);
    void MinHeapSort();     //从小到大排序，时间复杂度O(nlgn);
    void MaxHeapSort();     //从大到小排序，时间复杂度O(nlgn);
    //以下函数仅在最大堆下进行
    void Insert(int k); //插入一个元素（最大堆）
    void Delete(int i);    //删除一个元素（最大堆）
    Node Maximum();         //返回value最大的元素
    Node ExtractMax();     //去掉并返回value最大的元素
    //union two heap:union the vector of the two heaps, and call BuildMaxHeap()
    int Size() {return heap.size();} //返回vector的元素个数
    void PrintAll() {
        for (auto i : heap)
            cout << i.value << ends;
        cout << endl;
    }
};

void Heap::MaxHeapify(const int i) {
    int largest;
    if (Left(i) < heap_size && heap[Left(i)].value > heap[i].value)
        largest = Left(i);
    else
        largest = i;
    if (Right(i) < heap_size && heap[Right(i)].value > heap[largest].value)
        largest = Right(i);
    if (largest != i) {
        swap(heap[i], heap[largest]);
        MaxHeapify(largest);
    }
}

void Heap::MinHeapify(const int i) {
    int least;
    if (Left(i) < heap_size && heap[Left(i)].value < heap[i].value)
        least = Left(i);
    else
        least = i;
    if (Right(i) < heap_size && heap[Right(i)].value < heap[least].value)
        least = Right(i);
    if (least != i) {
        swap(heap[i], heap[least]);
        MinHeapify(least);
    }
}

void Heap::BuildMaxHeap() {
    heap_size = heap.size();
    for (int i = Parent(heap_size - 1); i >= 0; --i)
        MaxHeapify(i);
}

void Heap::BuildMinHeap() {
    heap_size = heap.size();
    for (int i = Parent(heap_size - 1); i >= 0; --i)
        MinHeapify(i);
}

void Heap::MinHeapSort() {
    BuildMaxHeap();
    for (int i = heap.size() - 1; i > 0; --i) {
        swap(heap[i], heap[0]);
        --heap_size;
        MaxHeapify(0);
    }
}

void Heap::MaxHeapSort() {
    BuildMinHeap();
    for (int i = heap.size() - 1; i > 0; --i) {
        swap(heap[i], heap[0]);
        --heap_size;
        MinHeapify(0);
    }
}

void Heap::Insert(int k) {
    heap.push_back(INT_MIN);
    IncreaseKey(heap.size() - 1, k);
}

void Heap::Delete(int i) {
    if (heap[heap.size() - 1].value > heap[i].value) {
        IncreaseKey(i, heap[heap.size() - 1].value);
        heap.pop_back();
    } else {
        heap[i] = heap[heap.size() - 1];
        heap.pop_back();
        heap_size = heap.size();
        MaxHeapify(i);
    }
}

Node Heap::Maximum() {
    return heap[0];
}

Node Heap::ExtractMax() {
    Node max = heap[0];
    heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    MaxHeapify(0);
    return max;
}

void Heap::IncreaseKey(int i, int k) {
    if (k <= heap[i].value)
        return ;
    while (i > 0 && heap[Parent(i)].value < k) {
        heap[i] = heap[Parent(i)];
        i = Parent(i);
    }
    heap[i].value = k;
}