#include <iostream>
#include <fstream>
#include "Main/AvlTree.h"
#include "Main/RBTree.h"
#include "Main/RBTreeHelper.h"
#include "Main/AvlTreeHelper.h"
#include "Main/SparseMatrix.h"
#include "Main/SparseMatrixHelper.h"
#include <vector>
int main() {
	RBTree<int> tree;
	tree.addItem(5);
	tree.addItem(4);
	tree.addItem(6);
	tree.addItem(3);
	std::ofstream out("rb.txt");
	RBTreeHelper::writeToFile<int>(&tree, out);
	return 0;
}