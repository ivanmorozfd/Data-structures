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
			
				(j > 1)
					? outputStream << " "
					: outputStream << "[ ";
				
				outputStream << matrix->get(i, j);
			}
			if (i < matrix->m_nrows) {
				outputStream << " ]" << std::endl;
			}
		}
		outputStream << " ]";
	}
	template<typename T>
	static SparseMatrix<T>* readFromFile(std::ifstream& inputStream) {
		std::string str{ };

		std::vector<T>* data = new std::vector<T>();
		std::vector<int>* columns = new std::vector<T>();
		std::vector<int>* pointers = new std::vector<T>();

		int iter = 0;
		size_t colCounter = 0;
		size_t ptrCounter = 0;
		size_t marker = 0;
		pointers->push_back(1);
		while (!inputStream.eof()) {
			//get data from file
			inputStream >> str;
			//cut brackets
			if (str == "[")
				continue;
			if (str == "]") {
				iter++;
					pointers->push_back(ptrCounter + 1);
				continue;
			}
			if (marker == colCounter && iter > 0 )
				marker = 0;
			//count columns at first loop
			if (iter == 0) {
				marker++;
				colCounter++;
			}
			else
				marker++;	

			if (str != "0") {	
				data->push_back(std::stoi(str));
				ptrCounter++;
				columns->push_back(marker);
			}
		}
		
		SparseMatrix<T>* matrix = new SparseMatrix<T>(iter, colCounter);
		matrix->m_cols = columns;
		matrix->m_data = data;
		matrix->m_ptrs = pointers;
		return matrix;
	}	
	template<typename T>
	static std::string findTowns(SparseMatrix<T>* matrix) {

	}
};