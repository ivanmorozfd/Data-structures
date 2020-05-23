#pragma once
#include "SparseMatrix.h"
class SparseMatrixHelper {
private:
	SparseMatrixHelper() = default;
	~SparseMatrixHelper() = default;
public:
	template<typename T>
	static void print_matrix(SparseMatrix<T>* matrix) {

	}
	template<typename T>
	static void writeToFile(SparseMatrix<T>* matrix, std::ofstream& outputStream) {

	}
	template<typename T>
	static SparseMatrix<T>* readFromFile(std::ifstream& inputStream) {

	}
	template<typename T>
	static std::string findTowns(SparseMatrix<T>* matrix) {

	}
};