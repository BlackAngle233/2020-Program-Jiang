#include <iostream>
#include <queue>
#include<vector>
#include"Tree.h"
using namespace std;

//优先队列 基于堆实现的

void Pq_test() {
	std::priority_queue<int> pq;
	pq.push(2);
	pq.push(1);
	pq.push(3);
}

template <typename Comparable>
void BinaryHeap::insert(const Comparable& x) {
	array[++currentSize] = x;
	int i = currentSize;
	while (i > 1 and array[i] < array[i / 2]) {//exchange
		exchange(array[i], array[i / 2]);
		i = i / 2;
	}
}

void BinaryHeap::move_down(int i) {
	while (i <= currentSize) {
		int l = 2 * i;
		int smallest = l;
		if (l < currentSize and array[l + 1] < array[l])
			smallest = l + 1;
		if (l<currentSize and array[i] > array[smallest])
			exchange(array[i], array[smallest]);
		else
			break;
		i = smallest;
	}
}

void BinaryHeap::deleteMin() {
	array[1] = array[currentSize];
	currentSize--;
	//下沉
	move_down(1);
	return;
}

void BinaryHeap::deleteMin(Comparable& minItem){
	if (array[1] == minItem) {
		deleteMin();
	}
	else
		return;
}



template <typename Comparable>
BinaryNode* BinarySearchTree::convertToList() {
	if (nullptr == root) return nullptr;
	BinaryNode* head = root;
	BinaryNode* tail = root;
	//中序遍历连接
	convertList(root);
	//头尾相接
	while (head->left) head = head->left;
	while (tail->right) tail = tail->right;
	head->left = tail;
	tail->right = head;
	return head;
}

void BinarySearchTree::print(BinaryNode* head) {
	BinaryNode* t = head;
	while (head) {
		cout << head->element << " ";
		head = head->right;
		if (head == t)
			break;
	}
}

BinaryNode* BinarySearchTree::findSuccessor(BinaryNode* t) {
	if (not t) return nullptr;
	if (t->right) {
		return findMin(t->right);
	}
	BinaryNode* parent = findParent(root, t);

	while (parent and t == parent->right) {
		t = parent;
		parent = findParent(root, parent);
	}
	return parent;
}

BinaryNode* BinarySearchTree::findPredecessor(BinaryNode* t) {
	if (not t) return nullptr;
	if (t->left) {
		return findMax(t->left);
	}
	BinaryNode* parent = findParent(root, t);

	while (parent and t == parent->left) {
		t = parent;
		parent = findParent(root, parent);
	}
	return parent;
}

void BinarySearchTree::insert(const Comparable& x, BinaryNode*& t){
	if (nullptr == t) {
		t = new BinaryNode{ x ,nullptr , nullptr };
	}

	else if (x < t->element) {
		insert(x, t->left);
	}
	else if (x > t->element) {
		insert(x, t->right);
	}
}

void BinarySearchTree::remove(const Comparable& x, BinaryNode*& t) {//删除一个节点
	if (not t) return;
	if (x < t->element) {
		remove(x, t->left);
	}
	else if (x > t->element)
	{
		remove(x, t->right);
	}
	else if (t->left and t->right) {
		t->element = findMin(t->right)->element;
		remove(t->element, t->right);
	}
	else {//只有一个子孩子
		auto oldNode = t;
		t = t->left ? t->left : t->right;
		delete t;
	}
}

bool BinarySearchTree::contains(const Comparable& x, BinaryNode* t) const {
	if (not t) return false;
	if (x < t->element) {
		return contains(x, t->left);
	}
	else if (x > t->element) {
		return contains(x, t->right);
	}
	return true;
}

bool BinarySearchTree::contains(const Comparable& x, BinaryNode* t) {
	if (not t)return false;
	BinaryNode* currNode = root;
	while (currNode) {
		if (currNode->element < t->element)
			currNode = currNode->right;
		else if (currNode->element > t->element)
			currNode = currNode->left;
		else
			return true;
	}
	return false;
}

void BinarySearchTree::clone(BinaryNode& root, BinaryNode* t) {
	if (t == nullptr) return;
	root = new BinaryNode();
	root->element = t->element;
	clone(root->left, t->left);
	clone(root->right, t->left);
}

BinaryNode* BinarySearchTree::findParent(BinaryNode* root, const BinaryNode* child) const {
	static BinaryNode* parent = nullptr;
	if (root) {
		if (root->left == child || root->right == child)
			parent = root;
		findParent(root->left, child);
		findParent(root->right, child);
	}
	return parent;
}

BinaryNode* BinarySearchTree::convertList(BinaryNode* root) {
	if (nullptr == root) return nullptr;
	if (root->left) {
		BinaryNode* list_left = convertList(root->left);
		while (list_left->right) list_left = list_left->right;
		root->left = list_left;
		list_left->right = root;
	}

	if (root->right) {
		BinaryNode* list_right = convertList(root->right);
		root->right = list_right;
		list_right->left = root;
	}
	while (root->left) {
		root = root->left;
	}
	return root;
}