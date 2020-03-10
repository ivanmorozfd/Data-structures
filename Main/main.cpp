#include <iostream>
#include "Main/RBTree.h"
int main() {
	RBTree<int> tree;
	tree.addItem(5);
	tree.addItem(6);
	tree.addItem(12);
	tree.inorder();
	return 0;
}