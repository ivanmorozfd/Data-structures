#include <iostream>
#include "Main/BinarySearchTree.h"
int main() {
	BinarySearchTree<int> bst;
	bst.addLeaf(5);
	bst.addLeaf(7);
	bst.addLeaf(3);
	bst.printInOrder();
	return 0;
}