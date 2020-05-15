#include <iostream>
using namespace std;
struct Node 
{
    Node* next ;
	int value;
	Node()
	{
		next = nullptr;
	}
};
class LinkList
{
    private:
    	Node *head;
		int length;

    public:
		LinkList(int a[], int len);

		~LinkList();

		void deleteList();

		void insert(int v);

		Node *find(int v);

		void remove(Node *node);

		void remove(int v);

		void print();

};