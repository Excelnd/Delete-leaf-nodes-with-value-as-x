// Delete leaf nodes with value as x.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Node {
	int data;
	struct Node *left, *right;
};

struct Node* newNode(int data)
{
	struct Node* newNode = new Node;
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return(newNode);

}

Node* deleteLeaves(Node* root, int x)
{
	if (root == NULL)
		return NULL;

	root->left = deleteLeaves(root->left, x);
	root->right = deleteLeaves(root->right, x);

	if (root->data == x && root->left == NULL &&
		root->right == NULL) {
		delete(root);
		return NULL;
	}
	return root;
}

void inorder(Node* root)
{
	if (root == NULL)
		return;
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

int main(void)
{
	struct Node* root = newNode(10);
	root->left = newNode(3);
	root->right = newNode(10);
	root->left->left = newNode(3);
	root->left->right = newNode(1);
	root->right->right = newNode(3);
	root->right->right->left = newNode(3);
	root->right->right->right = newNode(3);
	deleteLeaves(root, 3);
	cout << "Inorder traversal after deletion : ";
	inorder(root);
	return 0;
}

