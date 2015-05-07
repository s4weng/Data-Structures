#include <iostream>
using namespace std;

struct Node {

	int data;
	Node *next;
	
};

struct Stack {
	
	int numElements;
	Node *top;
	
	Stack();
	Node *pop();
	void push(int element);
	void print();
	
};

Stack::Stack():numElements(0), top(NULL) {}

Node *Stack::pop(){
	
	if (numElements == 0) return top; //let NULL represent empty stack
	
	else {
		
		Node *returnNode = top;
		top = top->next;
		--numElements;
		return returnNode; //let user decide what to do with the popped Node
	}
}

void Stack::push(int element){
	
	Node *newNode = new Node();
	newNode->data = element;
	newNode->next = top;
	top = newNode;
	++numElements;
	
}

void Stack::print(){
    
    Node *printNode = top;
	
	while (printNode){
		
		std::cout << printNode->data << " ";
		printNode = printNode->next;
	}
	
	std::cout << std::endl;
}

int main() {

	Stack *s = new Stack();
	
	s->push(1);
	s->push(2);
	s->push(3);
	s->print();
	s->pop();
	s->print();
	
	return 0;
}