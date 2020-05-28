#pragma once
#include "core.h"
#include "Container.h"
#include "SparseMatrixException.h"
#include <vector>
using std::vector;

template<typename _T>
/*!
	SparseMatrix  class
	\brief Use to store data in matrix view
	\author ivanmorozfd
	\version 1.0
	\date April 2020
*/
class SparseMatrix : public Container {
	friend class SparseMatrixHelper;
private:
	using valueType = _T;
	using reference = valueType&;
	using valueContainer = vector<_T>*;
	using columnsContainer = vector<int>*;
	using positionsContainer = vector<int>*;
	using self = SparseMatrix<valueType>;
private:
	size_t m_nrows; // number of matrix rows
	size_t m_ncolumns; // number of matrix columns
	valueContainer m_data; // this vector contain matrix non-zero values
	columnsContainer m_cols; // this vector contain columns for data elements
	/* 
		this vector contains positions pointers.The description of k-th line is 
		stored in positions from pointer[k] to (pointer[k+1] - 1) vectors data and cols
	*/
	positionsContainer m_ptrs;	
public:
	/*!
		Checking the SparseMatrix for empty space
		\param[out] bool True,if SparseMatrix is empty , otherwise False
	*/
	bool isEmpty() const override {
		return m_data->empty();
	}
	/*!
		Returns element from the SparseMatrix
		\param[in] size_t Row in SparseMatrix
		\param[in] size_t Column in SparseMatrix
		\param[out] valueType value at (Row,Column) position
	*/
	valueType get(size_t row, size_t column) const {
		size_t currentColumn;
		for (size_t pos = (*(this->m_ptrs))[row - 1] - 1; pos < (*(this->m_ptrs))[row] - 1; ++pos) {
			currentColumn = (*(this->m_cols))[pos];
			if (currentColumn == column) 
				return (*(this->m_data))[pos];
			else if (currentColumn > column)
				break;
		}

		return valueType();
	}
	/*!
		Set an element at a position in the matrix
		\param[in] size_t Row in SparseMatrix
		\param[in] size_t Column in SparseMatrix
		\param[out] reference value
	*/
	void set(valueType value, size_t row, size_t column) {
		this->validateCoordinates(row, column);

		size_t pos = (*(this->m_ptrs))[row - 1] - 1;
		size_t currCol = 0;

		for (; pos < (*(this->m_ptrs))[row] - 1; pos++) {
			currCol = (*(this->m_cols))[pos];
			if (currCol >= column) 
				break;
		}
		if (currCol != column) {
			if (!(value == valueType())) 
				this->insert(pos, row, column, value);
		}
		else if (value == valueType()) 
			this->remove(pos, row);
		else 
			(*(this->m_data))[pos] = value;
	}
	/*!
		Returns rows count in the SparseMatrix
		\param[out] size_t Rows count
	*/
	size_t getRows() const { 
		return this->m_nrows; 
	}
	/*!
		Returns columns count in the SparseMatrix
		\param[out] size_t Columns count
	*/
	size_t getColumns() const {
		return this->m_ncolumns; 
	}
	void clear() {
		this->m_data->clear();
		this->m_cols->clear();
		this->m_ptrs->clear();
	}
public:
	/*!
		Basic assignment operator
		\param[in] SparseMatrix other matrix 
		\param[out] SparseMatrix result matrix
	*/
	self& operator = (const self& other) {
		if (&other != this) {
			this->destruct();
			this->copy(other);
		}
		return *this;
	}
	/*!
		Matrix-Vector multiplication method
		\param[in] vector
		\param[out] vector result vector
	*/
	vector<_T> multiply(const vector<_T>& other) const {
		if (this->m_ncolumns != other.size()) 
			throw SparseMatrixException("Invalid dimensions");

		vector<_T> result(this->m_nrows, _T());
		if (this->m_data) { // only if any value set
			for (int i = 0; i < this->m_nrows; ++i) {
				valueType sum = valueType();
				for (int j = (*(this->m_ptrs))[i]; j < (*(this->m_ptrs))[i + 1]; j++) {
					sum+= (*(this->m_data))[j - 1] * other[(*(this->m_cols))[j - 1] - 1];
				}
				result[i] = sum;
			}
		}
		return result;
	}
	/*!
		Matrix-Vector multiplication operator
		\param[in] vector
		\param[out] vector result vector
	*/
	vector<_T> operator * (const vector<_T>& other) const {
		return this->multiply(other);
	}
	/*!
		Matrix-Matrix multiply multiplication
		\param[in] SparseMatrix other matrix
		\param[out] SparseMatrix result matrix
	*/
	self multiply(const self& other) const {
		if (this->m_ncolumns != other.m_nrows)
			throw SparseMatrixException("Invalid dimensions");

		self* result = new self(this->m_nrows, other.m_ncolumns);
		_T a;
		for (int i = 1; i <= this->m_nrows; i++) {
			for (int j = 1; j <= this->m_ncolumns; j++) {
				a = _T();
				for (int k = 1; k <= this->m_ncolumns; k++) {
					a+= this->get(i, k) * other.get(k, j);
				}
				result->set(a, i, j);
			}
		}
		return result;
	}
	/*!
		Matrix-Matrix multiply operator
		\param[in] SparseMatrix other matrix
		\param[out] SparseMatrix result matrix
	*/
	self operator * (const self& other) const {
		this->multiply(other);
	}
	/*!
		Matrix-Matrix add method
		\param[in] SparseMatrix other matrix
		\param[out] SparseMatrix result matrix
	*/
	self add(const self& other) const {
		if (this->m_nrows != other.m_nrows || this->m_ncolumns != other.m_ncolumns) 
			throw SparseMatrixException("Cannot add: matrices dimensions don't match.");

		self* result = new self(this->m_nrows, this->m_ncolumns);
		for (int i = 1; i <= this->m_nrows; ++i)  {
			for (int j = 1; j <= this->m_ncolumns; ++j) {
				result->set(this->get(i, j) + other.get(i, j), i, j);
			}
		}
		return result;
	}
	/*!
		Matrix-Matrix add operator
		\param[in] SparseMatrix other matrix
		\param[out] SparseMatrix result matrix
	*/
	self operator + (const self& other) const {
		this->add(other);	
	}
	/*!
		Matrix-Matrix subtract method
		\param[in] SparseMatrix other matrix
		\param[out] SparseMatrix result matrix
	*/
	self subtract(const self& other) const {
		if (this->m_nrows != other.m_nrows || this->m_ncolumns != other.m_ncolumns) 
			throw SparseMatrixException("Cannot subtract: matrices dimensions don't match.");
		self* result = new self(this->m_nrows, this->m_ncolumns);
		for (int i = 1; i <= this->m_nrows; i++) {
			for (int j = 1; j <= this->m_ncolumns; j++) {
				result->set(this->get(i, j) - other.get(i, j), i, j);
			}
		}
		return result;
	}
	/*!
		Matrix-Matrix subtract method
		\param[in] SparseMatrix other matrix
		\param[out] SparseMatrix result matrix
	*/
	self operator - (const self& other) const {
		this->subtract(other);
	}
private:
	//construct sparseMatrix 
	void construct(size_t rows, size_t columns) {
		this->validateCoordinates(rows, columns);
		//Initialize dimensions
		this->m_nrows = rows;
		this->m_ncolumns = columns;
		//Initialize data vectors
		this->m_data = new std::vector<_T>();
		this->m_cols = new std::vector<int>();
		this->m_ptrs = new vector<int>(this->m_nrows + 1, 1);
	}
	//destruct sparseMatrix 
	void destruct() {
		if (this->m_data) {
			delete this->m_data;
			delete this->m_cols;
		}
		delete m_ptrs;
	}
	void copy(const self& other) {
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
	bool validateCoordinates(size_t rows, size_t columns) {
			return true;
	}
	//Insert value to matrix	
	void insert(size_t index,
		size_t row,
		size_t column,
		valueType value) {
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
	void remove(size_t index, size_t row) {
		this->m_data->erase(this->m_data->begin() + index);
		this->m_cols->erase(this->m_cols->begin() + index);

		for (int i = row; i <= this->m_nrows; i++) {
			(*(this->m_ptrs))[i]--;
		}
	}
public:
	/*!
		Default SparseMatrix constructor
		\brief Default constructor init matrix with five rows and columns
	*/
	SparseMatrix() {
		this->construct(5, 5);
	}
	/*!
		Default SparseMatrix constructor
		\param[in] size_t Number of rows and columns
		\brief Construct square matrix 
	*/
	SparseMatrix(size_t n) {
		this->construct(n, n);
	}
	/*!
		Default SparseMatrix constructor
		\param[in] size_t rows Number of rows 
		\param[in] size_t columns Number of columns
		\brief Construct matrix with (rows,columns) dimension
	*/
	SparseMatrix(size_t rows, size_t columns) {
		this->construct(rows, columns);
	}
	/*!
		Sparse Matrix copy constructor
		\param[in] SparseMatrix other matrix
	*/
	SparseMatrix(const SparseMatrix<_T>& other) {
		this->copy(other);
	}
	/*!
		SparseMatrix destructor
	*/
	~SparseMatrix() {
		this->destruct();
	}
};
