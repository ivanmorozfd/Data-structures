#pragma once
#include "SparseMatrixException.h"
#include <vector>
using std::vector;

template<typename _T>
class SparseMatrix {
private:
	uint32_t m_nrows; // number of matrix rows
	uint32_t m_ncolumns; // number of matrix columns
	vector<_T>* m_data; // this vector contain matrix non-zero values
	vector<int>* m_cols; // this vector contain columns for data elements
	/* this vector contains positions pointers.The description of k-th line is 
	   stored in positions from pointer[k] to (pointer[k+1] - 1) vectors data and cols
	*/
	vector<int>* m_ptrs;	
public:
	//Return's matrix value at (row,column) position
	_T get(int row, int column) const {
		int currentColumn;

		for (int pos = (*(this->m_ptrs))[row - 1] - 1; pos < (*(this->m_ptrs))[row] - 1; ++pos) {
			currentColumn = (*(this->m_cols))[pos];
			if (currentColumn == column) 
				return (*(this->m_data))[pos];
			else if (currentColumn > column)
				break;
		}

		return _T();
	}
	//Set value at position (row,column) in matrix
	void set(_T value, int row, int column) {
		this->validateCoordinates(row, column);

		int pos = (*(this->m_ptrs))[row - 1] - 1;
		int currCol = 0;

		for (; pos < (*(this->m_ptrs))[row] - 1; pos++) {
			currCol = (*(this->m_cols))[pos];
			if (currCol >= column) 
				break;
		}

		if (currCol != column) {
			if (!(value == _T())) 
				this->insert(pos, row, column, value);
		}
		else if (value == _T()) 
			this->remove(pos, row);
		else 
			(*(this->m_data))[pos] = value;

	}
	uint32_t getRows() const { 
		return this->m_nrows; 
	}
	uint32_t getColumns() const {
		return this->m_ncolumns; 
	}
public:
	SparseMatrix<_T>& operator = (const SparseMatrix<_T>& other) {
		if (&other != this) {
			this->destruct();
			this->copy(other);
		}
		return *this;
	}

	vector<_T> multiply(const vector<_T>& other) const {
		if (this->m_ncolumns != other.size()) 
			throw SparseMatrixException("Invalid dimensions");

		vector<_T> result(this->m_nrows, _T());
		if (this->m_data) { // only if any value set
			for (int i = 0; i < this->m_nrows; ++i) {
				_T sum = _T();
				for (int j = (*(this->m_ptrs))[i]; j < (*(this->m_ptrs))[i + 1]; j++) {
					sum+= (*(this->m_data))[j - 1] * other[(*(this->m_cols))[j - 1] - 1];
				}
				result[i] = sum;
			}
		}

		return result;
	}
	vector<_T> operator * (const vector<_T>& other) const {
		return this->multiply(other);
	}

	SparseMatrix<_T> multiply(const SparseMatrix<_T>& other) const {
		if (this->m_ncolumns != other.m_nrows)
			throw SparseMatrixException("Invalid dimensions");
		
		SparseMatrix<_T> result(this->m_nrows, other.m_ncolumns);

		_T a;
		for (int i = 1; i <= this->m_nrows; i++) {
			for (int j = 1; j <= this->m_ncolumns; j++) {
				a = _T();
				for (int k = 1; k <= this->m_ncolumns; k++) {
					a+= this->get(i, k) * other.get(k, j);
				}
				result.set(a, i, j);
			}
		}
		return result;
	}
	SparseMatrix<_T> operator * (const SparseMatrix<_T>& other) const {
		this->multiply(other);
	}
	SparseMatrix<_T> add(const SparseMatrix<_T>& other) const {
		if (this->m_nrows != other.m_nrows || this->m_ncolumns != other.m_ncolumns) 
			throw SparseMatrixException("Cannot add: matrices dimensions don't match.");

		SparseMatrix<_T> result(this->m_nrows, this->m_ncolumns);
		for (int i = 1; i <= this->m_nrows; ++i)  {
			for (int j = 1; j <= this->m_ncolumns; ++j) {
				result.set(this->get(i, j) + other.get(i, j), i, j);
			}
		}
		return result;
	}
	SparseMatrix<_T> operator + (const SparseMatrix<_T>& other) const {
		this->add(other);	
	}
	SparseMatrix<_T> subtract(const SparseMatrix<_T>& other) const {
		if (this->m_nrows != other.m_nrows || this->m_ncolumns != other.m_ncolumns) 
			throw SparseMatrixException("Cannot subtract: matrices dimensions don't match.");
		SparseMatrix<_T> result(this->m_nrows, this->m_ncolumns);
		for (int i = 1; i <= this->m_nrows; i++) {
			for (int j = 1; j <= this->m_ncolumns; j++) {
				result.set(this->get(i, j) - other.get(i, j), i, j);
			}
		}
		return result;
	}
	SparseMatrix<_T> operator - (const SparseMatrix<_T>& other) const {
		this->subtract(other);
	}
private:
	void construct(uint32_t rows, uint32_t columns) {
		if (rows < 1 || columns < 1)
			throw SparseMatrixException("Matrix dimensions cannot be zero or negative");
		//Initialize dimensions
		this->m_nrows = rows;
		this->m_ncolumns = columns;
		//Initialize data vectors
		this->m_data = nullptr;
		this->m_cols = nullptr;
		this->m_ptrs = new vector<int>(this->m_nrows + 1, 1);
	}
	void destruct() {
		if (this->m_data) {
			delete this->m_data;
			delete this->m_cols;
		}
		delete m_ptrs;
	}
	void copy(const SparseMatrix<_T>& other) {
		//Copy dimensions and ptrs vector from other matrix
		this->m_nrows = other.m_nrows;
		this->m_ncolumns = other.m_ncolumns;
		this->m_ptrs = new vector<int>(*(other.m_ptrs));
		//If other matrix have non-zero values,copy it
		if (other.m_data) {
			this->m_cols = new vector<int>(*(other.m_cols));
			this->m_data = new vector<_T>(*(other.m_data));
		}
	}
	bool validateCoordinates(uint32_t rows, uint32_t columns) {
		if ( rows < 1 || columns < 1 || rows > this->m_nrows || columns > this->m_ncolumns) 
			throw SparseMatrixException("Invalid coordinates");
	}
	//Insert value to matrix	
	void insert(uint32_t index, uint32_t row, uint32_t column, _T value) {
		if (!this->m_data) {
			this->m_cols = new vector<int>(1, column);
			this->m_data = new vector<_T>(1, value);
		}
		else {
			this->m_cols->insert(this->m_cols->begin() + index, column);
			this->m_data->insert(this->m_data->begin() + index, value);
		}
		for (int i = row; i <= this->m_nrows; i++) 
			(*(this->m_ptrs))[i]++;
	}
	//Remove value from matrix
	void remove(uint32_t index, uint32_t row) {
		this->m_data->erase(this->m_data->begin() + index);
		this->m_cols->erase(this->m_cols->begin() + index);

		for (int i = row; i <= this->m_nrows; i++) {
			(*(this->m_ptrs))[i]--;
		}
	}
public:
	//The default constructor create matrix with 5 rows and 5 columns
	SparseMatrix() {
		this->construct(5, 5);
	}
	//Square matrix n x n
	SparseMatrix(uint32_t n) {
		this->construct(n, n);
	}
	//Create matrix with rows x columns dimension
	SparseMatrix(uint32_t rows, uint32_t columns) {
		this->construct(rows, columns);
	}
	//Copy constructor
	SparseMatrix(const SparseMatrix<_T>& other) {
		this->copy(other);
	}
	//Matrix destructor
	~SparseMatrix() {
		this->destruct();
	}
};
