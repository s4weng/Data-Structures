#include <iostream>
using namespace std;

struct Node {

	int data;
	Node *next;

};

void initHead(Node *head, int data){

	head->data = data;
	head->next = NULL;

}

void printList(Node *head){

	Node *current = head;
	while (current) {

		cout << current->data << " ";
		current = current->next;
	}

	cout << endl;
	delete current;
}

void insertFront(Node **head, int data){

	Node *newNode = new Node;
	newNode->data = (*head)->data;
	newNode->next = (*head)->next;
	(*head)->data = data;
	(*head)->next = newNode;

}

int main() {

	Node *newNode = new Node;

	initHead(newNode, 5);
	insertFront(&newNode, 1);
	insertFront(&newNode, 3);
	printList(newNode);

	delete newNode;
	
	return 0;

}