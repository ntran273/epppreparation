#include <iostream>
#include "LinkList.h"

SLL::SLL(){
	first = NULL;
	last = NULL;
	count = 0;
}

SLL::~SLL(){
	Node *temp = first;

	while (first)
	{
		first = first->getNextLink();
		delete temp;
		temp = first;
	}

	count = 0;
}
void SLL::insertFront(int data){
	Node *newNode = new Node();
	newNode->setData(data);

	if(first == NULL){
		first = newNode;
		last = newNode;
	}
	else{
		newNode->setNextLink(first);
		first = newNode;
	}
}

void SLL::addAtPosition(int data, int position){
	Node *newNode = new Node();
	newNode->setData(data);

	if(position == 0){
		newNode->setNextLink(first);
		first = newNode;
	}
	else{
		Node* temp = first;
		for(int i = 0; i < position - 1; i++){
			temp = temp->getNextLink();
		}
		newNode->setNextLink(temp->getNextLink());
		temp->setNextLink(newNode);
	}
	count++;
}

void SLL::deleteNode(int theData){
	if(count == 0){
		cout << "Cannot delete from an empty list.\n";
	}
	else
	{
		Node* current = first;
		bool found = false;

		if(first->getData() == theData){
			first = first->getNextLink();
			delete current;
			current = NULL;
			found = true;
			count--;
		}
		else{
			Node *temp = first;
			while((current != NULL) && (!found)){
				if(current->getData() == theData){
					temp->setNextLink(current->getNextLink());
					delete current;
					current = NULL;
					found = true;
					--count;
				}
				else{
					temp = current;
					current = current->getNextLink();
				}
			}
		}

		if(!found){
			cout << "Item to be delted is not in the list. " << endl;
		}
	}

}
void SLL::insertBack(int data){
	Node *newNode = new Node();
	newNode->setData(data);

	if(last == NULL){
		first = newNode;
		last = newNode;
	}
	else{
		last->setNextLink(newNode);
		last = newNode;
	}
}

void SLL::print(){
	Node* current = first;
	while(current){
		cout << current->getData() << " ";
		current = current->getNextLink();
	}
}

/*int SLL::sum(Node* current){
	int sum = 0;
	if(current == NULL){
		return 0;
	}
	return (current->getData() + sum(current->getNextLink())) ;
}*/

int main(){
	SLL listNode;
	listNode.addAtPosition(2,0);
	listNode.addAtPosition(5,1);
	listNode.addAtPosition(8,2);
	listNode.addAtPosition(3,3);
	listNode.addAtPosition(6,2);

	listNode.print();
	listNode.deleteNode(5);
	cout << "\n";
	listNode.print();

	//cout << "Sum : " << listNode.sum(getFirst()) << endl;


	return 0;
}