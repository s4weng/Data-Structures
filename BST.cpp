#include <iostream>

struct BST {
	
	int data;
	BST *left;
	BST *right;
	BST(int);
};

BST::BST(int data):data(data), left(NULL), right(NULL){}

void insertNode(BST *t, int data){
	
	if (data < t->data){
		
		if(!t->left)
			t->left = new BST(data);
		else
			insertNode(t->left, data);
	}
	
	else if (data > t->data){
		
		if (!t->right)
			t->right = new BST(data);
		else
			insertNode(t->right, data);
	}
	
	else
		std::cout << "Element already exists!" << std::endl;
}

void printInOrder(BST *t){
	
	std::cout << t->data << std::endl;
	if (t->left)
		printInOrder(t->left);
	if (t->right)
		printInOrder(t->right);
}


int main() {

	BST *t = new BST(3);
	printInOrder(t);
	insertNode(t, 2);
	insertNode(t, 4);
	printInOrder(t);
	return 0;
}