#include<stdlib.h>
using namespace std;
struct Node
{
	int val;
	Node *left;
	Node *right;
	Node(int v) : val(v), left(NULL), right(NULL) {}
};

void visit(Node *root, Node **left, Node **right)
{
	if (root == NULL)
	{
		*left = NULL;
		*right = NULL;
		return;
	}

	if (root->left)
	{
		Node *p = NULL;
		Node *q = NULL;
		visit(root->left, &p, &q);

		root->left = q;
		q->right = root;
		*left = p;
	}
	else
	{
		*left = root;
	}

	if (root->right)
	{
		Node *p = NULL;
		Node *q = NULL;
		visit(root->right, &p, &q);

		root->right = p;
		p->left = root;
		*right = q;
	}
	else
	{
		*right = root;
	}
}

Node* fun(Node *root)
{
	if (root == NULL)
	{
		return NULL;
	}

	Node *left = NULL;
	Node *right = NULL;
	visit(root, &left, &right);

	return left;
}
