#include <iostream>
#include<vector>
#include <queue>
#include"heap.h"
using namespace std;
int main() {
	BinarySearchTree<int> tree;
	int nums[]{ 8,3,9,1,5,12,4,11 };
	for (int i = 0; i < 8; ++i)
		tree.insert(nums[i]);
	BinarySearchTree<int>::BinaryNode* n = tree.root;
	cout << tree.findPredecessor(n)->element << endl;
	cout << tree.findSuccessor(tree.findPredecessor(n))->element << endl;
	cout << tree.findPredecessor(tree.findSuccessor(n))->element << endl;
	tree.print(tree.convertToList());
	BinaryHeap<int>* minHeap = new BinaryHeap<int>(vector<int>{ 9, 6, 5, 2, 3 });
	cout << minHeap->findMin();
	minHeap->insert(1);
	minHeap->deleteMin();
	minHeap->deleteMin();
}