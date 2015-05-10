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

int max(int a, int b){
	
	return (a > b ? a : b); //if equal we can return either
}

int findHeight(BST *t){
	
	if (t->left && t->right)
		return 1 + max(findHeight(t->left), findHeight(t->right));
	else if (t->left)
		return 1 + findHeight(t->left);
	else if (t->right)
		return 1 + findHeight(t->right);
	else
		return 0; //account for height starting 0
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
	insertNode(t, 1);
	insertNode(t, 5);
	insertNode(t, 4);
	insertNode(t, 6);
	printInOrder(t);
	return 0;
}