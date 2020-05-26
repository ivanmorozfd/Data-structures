#pragma once
#include "SparseMatrix.h"
#include "HelperBase.h"
class SparseMatrixHelper : public virtual HelperBase {
private:
	SparseMatrixHelper() = default;
	~SparseMatrixHelper() = default;
public:
	template<typename T>
	static void print_matrix(SparseMatrix<T>* matrix) {
		for (int i = 1; i <= matrix->m_nrows; i++) {
			for (int j = 1; j <= matrix->m_ncolumns; j++) {
				if (j != 1) {
					std::cout << " ";
				}
				std::cout<< matrix->get(i, j);
			}
			if (i < matrix->m_nrows) {
				std::cout << std::endl;
			}
		}
	}
	template<typename T>
	static void writeToFile(SparseMatrix<T>* matrix, std::ofstream& outputStream) {
		for (int i = 1; i <= matrix->m_nrows; i++) {
			for (int j = 1; j <= matrix->m_ncolumns; j++) {
				if (j != 1) {
					outputStream << " ";
				}
				outputStream << matrix->get(i, j);
			}
			if (i < matrix->m_nrows) {
				outputStream << std::endl;
			}
		}
	}
	template<typename T>
	static SparseMatrix<T>* readFromFile(std::ifstream& inputStream) {

	}
	template<typename T>
	static std::string findTowns(SparseMatrix<T>* matrix) {

	}
};