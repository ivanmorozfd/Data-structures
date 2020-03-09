#include <iostream>
#include "Main/AvlTree.h"
int main() {
	AvlTree<int> tree;
	tree.insert(5);
	tree.insert(4);
	tree.insert(6);
	tree.display();
	return 0;
}