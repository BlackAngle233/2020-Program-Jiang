// leetcode.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<queue>
#include<stack>
using namespace std;
template <typename Comparable>
class BinarySearchTree
{
public:
	BinarySearchTree() : root{ nullptr } {}
	BinarySearchTree(const BinarySearchTree & rhs) : root{ nullptr }
	{
		root = clone(rhs.root);
	}
	~BinarySearchTree() { makeEmpty(); }
	BinarySearchTree & operator=(const BinarySearchTree & rhs) { return root; };
	const Comparable & findMin() { return (findMin(root))->element; } const
	const Comparable & findMax() { return (findMax(root))->element; }const
		bool contains(const Comparable & x) const
	{
		return contains(x, root);
	}

	bool isEmpty() const { return root == nullptr; }
	void makeEmpty() { makeEmpty(root); }
	void insert(const Comparable & x) { insert(x, root); }
	void insert(Comparable && x) { insert(std::move(x), root); }
	void remove(const Comparable & x) { remove(x, root); }
	void read() { read(root); };
	void makelist() { delete list; list = new BinaryNode(0, nullptr, nullptr); list1 = list; makelist(root); list1->right = list; list->left = list1; };

	struct BinaryNode
	{
		Comparable element;
		BinaryNode *left;
		BinaryNode *right;
		BinaryNode(const Comparable & theElement, BinaryNode *lt, BinaryNode *rt)
			: element{ theElement }, left{ lt }, right{ rt } { }
		BinaryNode(Comparable && theElement, BinaryNode *lt, BinaryNode *rt)
			: element{ std::move(theElement) }, left{ lt }, right{ rt } { }
	};
	BinaryNode *root;
	BinaryNode*list;
	BinaryNode*list1 ;
	void makelist(BinaryNode*a) 
	{
		
		if (a == nullptr)return; 
		makelist(a->left);
		list1->right = new BinaryNode(a->element,list1, nullptr);
		list1 = list->right;
		makelist(a->right);
	}
	void read(BinaryNode*a) { if (a == nullptr)return; read(a->left); cout << a->element; read(a->right); }
	void insert(const Comparable & x, BinaryNode * & t) 
	{
		
		if (t == nullptr)
		{
			t = new BinaryNode(x, nullptr, nullptr);
			
			return;
		}
		if (x > t->element)
			insert(x, t->right);
		else
			insert(x, t->left);
	}
	void remove(const Comparable & x, BinaryNode * & t) 
	{
		BinaryNode *a = findNode(t, x);
		BinaryNode *b = findParent(t, x);
		if (a->left == nullptr&&a->right != nullptr)
		{
		

			if (b->element < a->element)
				b->right = a->right;
			else
				b->left = a->right;

			
		}
		else if (a->left != nullptr&&a->right == nullptr)
		{
			
			if (b->element < a->element)
				b->right = a->left;
			else
				b->left = a->left;
		}
		else 
		{
			a->element = (findMin(a->right))->element;
			BinaryNode*b =findMin(a->right);
			remove(b->element, t);
		};
	}
	BinaryNode * findMin(BinaryNode *t) const 
	{
		if (t == nullptr)
			return nullptr;
		if (t->left == nullptr)
			return t;
		else
			return findMin(t->left);
	}
	BinaryNode * findMax(BinaryNode *t) const 
	{
		if (t == nullptr)
			return nullptr;
		if (t->right == nullptr)
			return t;
		else
			return findMax(t->right);
	}
	BinaryNode * findParent(BinaryNode *t, const Comparable & x) const 
	{
	
		if ((t->left!=nullptr&&t->left->element == x )|| (t->right!=nullptr&&t->right->element == x))
			return t;
		if (t->left != nullptr)
			return findParent(t->left, x);
		if (t->right != nullptr)
			return findParent(t->right, x);
	}
	BinaryNode * findNode(BinaryNode *t, const Comparable & x) 
	{
		if (t == nullptr)
			return nullptr;
		if (t->element == x)
			return t;
		else if (t->left != nullptr)
			return findNode(t->left, x);
		else if (t->right != nullptr)
			return findNode(t->right, x);
		return nullptr;
	}
	bool contains(const Comparable & x, BinaryNode *t) const 
	{
		stack<BinaryNode*>stack1;
		stack1.push(t);
		while (!stack1.empty()) {
			if ((stack1.top())->element == x)
				return true;
			BinaryNode *t1 = stack1.top();
			stack1.pop();
			if (t1->left != nullptr)
				stack1.push(t1->left);
			if (t1->right != nullptr)
				stack1.push(t1->right);
		}
		return false;
	}
	/****** NONRECURSIVE VERSION*************************/
	bool contains(const Comparable & x, BinaryNode *t) 
	{
		if (t == nullptr)
			return false;
		if (t->left == nullptr&&t->right == nullptr)
		{
			if (t->element == x)
				return true;
		}
		if (contains(x, t->left) || contains(x, t->right))
			return true;
		else
			return false;
	}
	void makeEmpty(BinaryNode * & t) 
	{
		if (t == nullptr)
			return;
		makeEmpty(t->left);
		makeEmpty(t->right);
		delete t;
	}

	BinaryNode * clone(BinaryNode *t) const { root = t; }
};


int main()
{
	BinarySearchTree<int> *a = new BinarySearchTree<int>;
	a->insert(1);
	a->insert(2);
	a->insert(3);
	a->insert(4);
	a->insert(8);
	a->insert(7);
	a->remove(4);
	a->makelist();
};

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
