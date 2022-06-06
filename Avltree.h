#pragma once
#include <iostream>


class Node {
public:
	int data, balance;
	Node* left, *right;

	Node(int val) {
		data = val;
		balance = 0;
		right = left = nullptr;
	}

	Node* insert(Node* root, int val) {
		if (!root) {
			return new Node(val);
		}
		if (val <= root->data) {
			if (!root->left) {
				root->left = new Node(val);

				/*root->balance++ ;
				if (root->balance > 1)*/ {
				// #define BALANCE_SOLVED break your head in the wall for 3 hours
				// create findSuccessor and FindPredecessor methods
				// create rotateLeft and rotateRight methods
				}
				return root->left;
			}
			insert(root->left, val);
		}
		else if (val > root->data) {
			if (!root->right) {
				root->right = new Node(val);
				/*	root->balance--;
					if (root->balance < -1)*/ {
					// BALANCE_SOLVED[::-1]
				}
					return root->right;
			}
			insert(root->right, val);
		}
		return root;
	}

	void printNode() {
		std::cout << this->data << std::endl;
	}

	Node* findSor(Node* node) {
		return findMin(node->right);

	}

	Node* deleteNode(Node* root , int val) {
		if (!root)
			return root;
		if (val<root ->data)
		{
			root->left = deleteNode(root->left, val);
		}
		else if (val > root->data) {
			root->right= deleteNode(root->right, val);
		}
		else {
			if (root->left == nullptr && root->right == nullptr)

			{
				delete root;
				return nullptr;
			}
			else if (root->left == nullptr)
			{
				Node* temp = root->right;
				delete root;
				return temp;
			}
			else if (root->right == nullptr)
			{
				Node* temp = root->left;
				delete root;
				return temp;
			}
			else
			{
				Node* temp = findSor(root);
				if (temp)
				{
					root->data = temp->data;
					root->right = deleteNode(root->right, temp->data);
				}
			}
		}	
		return root;
	}

	int findMaxValue(Node* node) {
		if (!node)
			return NULL;
		if (!node->right)
			return node->data;
		return findMaxValue(node->right);

	}

	Node* findMin(Node* node) {
		if (!node)
			return NULL;
		if (!node->left)
			return node;
		return findMin(node->left);

	}

	void freeTree(Node* root) {
		if (!root) return;
		if (root->right) freeTree(root->right);
		if (root->left) freeTree(root->left);
		delete root;
	}

};


