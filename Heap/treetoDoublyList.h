/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution
{
public:
    Node* treeToDoublyList(Node* root) {
        if(root == nullptr) return nullptr;
		Node* head = findMin(root);
        Node* tail = findMax(root);
		Node *prev = nullptr;
		_treeToDoublyList(root, prev);
		head->left = tail;
		tail->right = head;
        return head;
    }

	void  _treeToDoublyList(Node* root, Node*& prev)
	{
		if (root == nullptr) return ;
		_treeToDoublyList(root->left, prev);
		//TODO: do something in the node root

		if (prev != nullptr ) prev->right = root;
		if (prev != nullptr) root-> left = prev;
		if(root != nullptr) prev = root;

		_treeToDoublyList(root->right, prev);
	}


	Node* findMin(Node* root)
	{
		if (root == nullptr) return nullptr;
		if (root->left != nullptr) return findMin(root -> left);
        else return root;
	}

	Node* findMax(Node* root)
	{
		if (root == nullptr) return nullptr;
		if (root->right != nullptr) return findMax(root -> right);
		else return root;
	}

};
