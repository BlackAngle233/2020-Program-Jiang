#include <iostream>
#include <queue>
#include<vector>
#include"Tree.h"
using namespace std;
int main() {
	BinarySearchTree<int> t;
	int nums[]{ 8,3,9,1,5,12,4,11 };
	for (int i = 0; i < 8; ++i)
		t.insert(nums[i]);
	BinarySearchTree<int>::BinaryNode* n = t.root;
	cout << t.findPredecessor(n)->element << endl;
	cout << t.findSuccessor(t.findPredecessor(n))->element << endl;
	cout << t.findPredecessor(t.findSuccessor(n))->element << endl;
	t.print(t.convertToList());
	BinaryHeap<int>* minHeap = new BinaryHeap<int>(vector<int>{ 9, 6, 5, 2, 3 });
	cout << minHeap->findMin();
	minHeap->insert(1);
	minHeap->deleteMin();
	minHeap->deleteMin();
}