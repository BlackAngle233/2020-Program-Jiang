#include <iostream>
#include <algorithm>
#include "Heap.hpp"
using namespace std;

int main()
{
    Heap<int> heap;
    heap.push(4);
    cout << heap.front();
    heap.push(3);
    cout << heap.front();
    heap.push(1);
    cout << heap.front();
    heap.push(2);
    cout << heap.front();
    heap.pop();
    cout << heap.front();
    return 0;
}
