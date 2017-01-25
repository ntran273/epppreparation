#include <iostream>
using namespace std;

class Node{
public:
	Node() : data(0), next(NULL){};
	~Node(){};
	void setNextLink(Node *nextLink) {next = nextLink;}
	void setData(int theData){data = theData;}
	int getData(){return data;}
	Node* getNextLink() {return next;}


private:
	int data;
	Node* next;

};

class SLL{
public:
	SLL();
	~SLL();
	void insertFront(int data);
	void insertBack(int data);
	void addAtPosition(int data, int position);
	void print();
	int sum(Node*);
	Node* getFirst(){return first;}
	void deleteNode(int data);
	
private:
	Node* first;
	Node* last;
	int count;
};