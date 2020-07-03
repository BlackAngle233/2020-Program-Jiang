// TreeTest.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <queue>
#include<vector>
using namespace std;
//优先队列 基于堆实现的
void Pq_test() {
	std::priority_queue<int> pq;
	pq.push(2);
	pq.push(1);
	pq.push(3);

}

//一棵二叉树来说，n = n0+n2+n1
//				  n0 = n2+1
//
//完全二叉树 n1 = 1或0（n为偶数 n1 = 1, else n1 = 0）
//
//堆 完全二叉树（用数组来做 因为中间都是满的,效率最高）
//高度为h,元素个数再2^h-2^(h+1)-1之间
//含n个元素，高度是[logn]
//叶子节点下标，【n/2】+1，【n/2】+2，。。。
//高度为h的元素个数[n/2^(h+1)]
//左节点2i , 右节点2i+1，找父节点只要除以2（上浮）
//插入Insert（可以放0的位置比较 或者放到数组最后 然后比较）
template <typename Comparable>
class BinaryHeap
{
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
	void insert(const Comparable& x) {
		array[++currentSize] = x;
		int i = currentSize;
		while (i > 1 and array[i] < array[i / 2]) {//exchange
			exchange(array[i], array[i / 2]);
			i = i / 2;
		}
	}
	void deleteMin() {
		array[1] = array[currentSize];
		currentSize--;
		//下沉
		move_down(1);
		return;
	}
	void deleteMin(Comparable& minItem) {
		if (array[1] == minItem) {
			deleteMin();
		}
		else
			return;
	}
	void makeEmpty()
	{
		currentSize = 0;
	}
	
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
	void move_down(int i) {
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
	 
};




//***求无序序列的中位数 面试高频 leetcode295
//1.声明两个堆 最大堆 all < 最小堆啊 all
//2.size of max == size of min or size of max == size of min + 1
//3.总是优先插到最大堆，再比较个数


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
	bool contains(const Comparable& x) const
	{
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
	BinaryNode* convertToList() {
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
	void print(BinaryNode* head) {
		BinaryNode* t = head;
		while (head)
		{
			cout << head->element << " ";
			head = head->right;
			if (head == t)
				break;
		}
	}

	//找BST节点的后继
	BinaryNode* findSuccessor(BinaryNode* t) {
		if (not t) return nullptr;
		//有右子树，返回右子树最小值
		if (t->right) {
			return findMin(t->right);
		}
		//无右子树，（这个节点是右孩子）找到一个父节点当这个父节点是左孩子；这个节点是左孩子，返回父节点
		BinaryNode* parent = findParent(root, t);
		while (parent and t == parent->right) {
			t = parent;
			parent = findParent(root, parent);
		}
		return parent;
	}
	//找BST节点前驱
	BinaryNode* findPredecessor(BinaryNode* t) {
		if (not t) return nullptr;
		//有左子树，返回左子树最大值
		if (t->left) {
			return findMax(t->left);
		}
		//无左子树，（这个节点是左孩子）找到一个父节点当这个父节点是右孩子；这个节点是右孩子，返回父节点
		BinaryNode* parent = findParent(root, t);
		while (parent and t == parent->left) {
			t = parent;
			parent = findParent(root, parent);
		}
		return parent;
	}
	
	BinaryNode* root;
private:
	//insert 递归 要传指针的引用 这样就改变了t的值
	void insert(const Comparable& x, BinaryNode*& t)
	{
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
	void remove(const Comparable& x, BinaryNode*& t) {//删除一个节点
		if (not t) return;
		if (x < t->element) {
			remove(x,t->left);
		}
		else if (x > t->element)
		{
			remove(x, t->right);
		}
		else if (t->left and t->right) {//两个子孩子
			//下面两部可以合成一步，removeMin避免要遍历两次
			t->element = findMin(t->right)->element;//当前这个t替换成右孩子的最左叶子节点
			remove(t->element, t->right);//把最左叶子节点删除
		}
		else{//只有一个子孩子
			auto oldNode = t;
			t = t->left ? t ->left : t->right;
			delete t;
		}
	}

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
	bool contains(const Comparable& x, BinaryNode* t) const {
		if (not t) return false;
		if (x < t->element) {
			return contains(x, t->left);

		}
		else if (x > t->element) {
			return contains(x, t->right);
		}
		return true;
	}
	//nonrecursive version
	bool contains(const Comparable& x, BinaryNode* t) {
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
	void makeEmpty(BinaryNode*& t) {
		if (not t) return;
		makeEmpty(t->left);
		makeEmpty(t->right);
		delete t;
	}
	BinaryNode* clone(BinaryNode* t) const {
		clone(root, t);
	}
	void clone(BinaryNode& root, BinaryNode* t) {
		if (t == nullptr) return;
		root = new BinaryNode();
		root->element = t->element;
		clone(root->left, t->left);
		clone(root->right, t->left);
	}
	//找节点的父节点
	BinaryNode* findParent(BinaryNode* root, const BinaryNode* child) const{
		static BinaryNode* parent = nullptr;
		if (root) {
			if (root->left == child || root->right == child)
				parent = root;
			findParent(root->left, child);
			findParent(root->right, child);
		}
		return parent;
	}

	
	//把一个BST转换成一个双链表（in place）中序遍历 
	BinaryNode* convertList(BinaryNode* root) {
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
};



int main()
{
	
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
	cout<<minHeap->findMin();
	minHeap->insert(1);
	minHeap->deleteMin();
	minHeap->deleteMin();

}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
