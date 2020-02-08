#include "Main/Stack.h"
#include <iostream>
#include "Main/BinarySearchTree.h"
int a() {
	return 0;
}
int main() {
	BinarySearchTree<int> tree;
	tree.addLeaf(5);
	tree.addLeaf(7);
	tree.addLeaf(6);	
	tree.printInOrder();
	return 0;
}