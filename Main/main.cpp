#include <iostream>
#include <fstream>
#include "Main/BinarySearchTree.h"
#include "Main/BinarySearchTreeHelper.h"
#include <vector>
int main() {
	BinarySearchTree<int>* tree;
	std::ifstream in("OutTree.txt");
	tree = BinarySearchTreeHelper::readFromFile<int>(in);
	BinarySearchTreeHelper::printInOrder(tree);
	return 0;
}