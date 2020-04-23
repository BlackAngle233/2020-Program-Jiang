#include <string>
using namespace std;

struct Node
{
	int val;
	Node *next;
	Node(int x) :val(x), next(NULL) {}
};

class LinkList
{
public:
	LinkList();
	void Create(int val[5]);
	void Insert(int val, int pos);
	void erase(int val);
	void Remove(int val);
	void Find(int val);
	void Print();
private:
	Node *head;
};