#include <iostream>
#include "Main/RBTree.h"
int main() {
	RBTree<int> tree;
	tree.addItem(5);
	tree.addItem(4);
	tree.addItem(3);
	tree.addItem(2);
	tree.addItem(1);
	tree.inorder();
	return 0;
}