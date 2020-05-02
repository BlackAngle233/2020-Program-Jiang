#pragma once
class LinkList
{
private:
	class Node;
	Node* head{};
public:
	size_t size() const;
	Node* getHead() const ;
	LinkList() = default;
	LinkList(const int[], int);
	~LinkList();
	
	void insert(int);
	void insert(Node*);

	Node* find(int) const;
	Node* findBefore(int v) const;

	void remove(Node*);
	void remove(int);
	void print() const;
	class Node
	{
	public:
		int value{};
		Node* next{};

	};
};
std::ostream& operator<<(std::ostream&, const LinkList&) ;
