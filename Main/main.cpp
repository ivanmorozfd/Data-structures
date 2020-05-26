#include <iostream>
#include <fstream>
#include "Main/RBTree.h"
#include "Main/RBTreeHelper.h"
#include <vector>
int main() {
	RBTree<int> tree;
	tree.addItem(5);
	tree.addItem(6);
	tree.addItem(4);
	tree.addItem(3);
	std::cout << RBTreeHelper::serialize(&tree);
	return 0;
}