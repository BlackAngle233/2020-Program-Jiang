#pragma once
#include <iostream>
#include <queue>
#include<vector>
using namespace std;
template <typename Comparable>
class BinaryHeap {
public:
	explicit BinaryHeap(int capacity = 100)
		: array(capacity + 1), currentSize{ 0 } {}
	explicit BinaryHeap(const vector<Comparable>& items)
		: array(items.size() + 10), currentSize{ items.size() }
	{
		for (int i = 0; i < (int)items.size(); ++i)
			array[i + 1] = items[i];
		buildHeap();
	}
	bool isEmpty() const { return currentSize == 0; }
	const Comparable& findMin() const {
		if (isEmpty()) exit(-1);
		return array[1];
	}
	void insert(const Comparable& x);
	void deleteMin();
	void deleteMin(Comparable& minItem);
	void makeEmpty() {currentSize = 0;}

private:
	vector<Comparable> array;
	size_t currentSize;
	void buildHeap() {
		for (int i = currentSize / 2; i >= 0; i--)
			move_down(i);
	}

	void exchange(Comparable& a, Comparable& b) {
		Comparable t = a;
		a = b;
		b = t;
	}

	//下沉
	void move_down(int i);
};




//二叉搜索数BST

template <typename Comparable>

class BinarySearchTree
{
public:
	BinarySearchTree() : root{ nullptr } {}
	BinarySearchTree(const BinarySearchTree& rhs) : root{ nullptr }
	{
		root = clone(rhs.root);
	}
	~BinarySearchTree() { makeEmpty(); }
	BinarySearchTree& operator=(const BinarySearchTree& rhs) {
		root = rhs;
		return root;
	}

	const Comparable& findMin() const {
		return findMin(root);
	}

	const Comparable& findMax() const {
		return finMax(root);
	}

	bool contains(const Comparable& x) const{
		return contains(x, root);
	}

	bool isEmpty() const { return root == nullptr; }
	void makeEmpty() { makeEmpty(root); }
	void insert(const Comparable& x) { insert(x, root); }
	void insert(Comparable&& x) { insert(std::move(x), root); }
	void remove(const Comparable& x) { remove(x, root); }

	struct BinaryNode
	{
		Comparable element;
		BinaryNode* left;
		BinaryNode* right;
		BinaryNode(const Comparable& theElement, BinaryNode* lt, BinaryNode* rt)
			: element{ theElement }, left{ lt }, right{ rt } { }
		BinaryNode(Comparable&& theElement, BinaryNode* lt, BinaryNode* rt)
			: element{ std::move(theElement) }, left{ lt }, right{ rt } { }
	};

	//BST转换双链表

	BinaryNode* convertToList();
	void print(BinaryNode* head);

	//找BST节点的后继
	BinaryNode* findSuccessor(BinaryNode* t);

	//找BST节点前驱
	BinaryNode* findPredecessor(BinaryNode* t);
	BinaryNode* root;

private:
	//insert 递归 要传指针的引用 这样就改变了t的值
	void insert(const Comparable& x, BinaryNode*& t);
	void remove(const Comparable& x, BinaryNode*& t);

	BinaryNode* findMin(BinaryNode* t) const {//找一个树的最小值
		if (not t) return nullptr;
		if (not t->left) return t;
		return findMin(t->left);
	}

	//recursive version
	BinaryNode* findMax(BinaryNode* t) const {//找一个树的最大值
		if (not t) return nullptr;
		if (not t->right) return t;
		return findMax(t->right);
	}

	bool contains(const Comparable& x, BinaryNode* t) const;

	//nonrecursive version
	bool contains(const Comparable& x, BinaryNode* t);

	void makeEmpty(BinaryNode*& t) {
		if (not t) return;
		makeEmpty(t->left);
		makeEmpty(t->right);
		delete t;
	}

	BinaryNode* clone(BinaryNode* t) const {
		clone(root, t);

	}

	void clone(BinaryNode& root, BinaryNode* t);

	//找节点的父节点

	BinaryNode* findParent(BinaryNode* root, const BinaryNode* child) const;

	//把一个BST转换成一个双链表（in place）中序遍历 
	BinaryNode* convertList(BinaryNode* root);
};