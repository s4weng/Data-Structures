#include <iostream>


struct Node {
	
	int data;
	Node *next;
};


struct Queue {
	
	int numElements;
	Node *front, *back;
	
	Queue();
	void enqueue(int data);
	void dequeue();
	void printQueue();
};


Queue::Queue(): numElements(0), front(NULL), back(NULL) {}


void Queue::enqueue(int data) {
	
	Node *newNode = new Node();
	newNode->data = data;

	if(numElements != 0)
		back->next = newNode;

	newNode->next = NULL;
	
	if(numElements == 0)
		front = newNode;
		
	back = newNode;
	++numElements;
}


void Queue::dequeue() {
	
	if (numElements == 0) std::cout << "Queue is empty!" << std::endl;
	
	else {
		
		Node *delNode = front;
		front = front->next;
		delete delNode;
		--numElements;
	}
}


void Queue::printQueue(){
	
	Node *printNode = front;
	
	if (numElements == 0)
		std::cout << "No elements to print, empty!" << std::endl;
	
	else {
		while (printNode){
			
			std::cout << printNode->data << std::endl;
			printNode = printNode->next;
		}
	}
}


int main() {
	Queue *q = new Queue();
	q->enqueue(2);
	q->enqueue(4);
	q->printQueue();
	q->dequeue();
	q->printQueue();
	q->dequeue();
	q->dequeue();
	q->printQueue();
	return 0;
}