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
	SparseMatrix<int>* matrix;

	std::ifstream fin("matrix.txt");
	matrix = SparseMatrixHelper::readFromFile<int>(fin);
	SparseMatrixHelper::print_matrix<int>(matrix);
	return 0;
}