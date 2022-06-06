#include "Avltree.h"

int main() {

	//TreeNode a(3) ;
	//Print(a);
	//AvlTree tree;
	//tree.root = &a;
	//Print(*tree.root);

	
	Node root (0);
	root.insert(&root, 10);
	root.insert(&root, 11);
	root.insert(&root, 5);
	root.insert(&root, 2);
	root.insert(&root, -16);
	root.deleteNode(&root, 5);
	root.deleteNode(&root, 11);
	root.deleteNode(&root, 12);
	root.deleteNode(&root, -16);
	root.insert(&root, -3);
	root.insert(&root, 27);
	root.insert(&root, 14);
	root.insert(&root, 5);
	root.printNode();
	root.left->printNode();
	root.right->printNode();

	root.freeTree(&root);


}