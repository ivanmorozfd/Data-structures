#pragma once
#include <exception>
#include <string>
#include <vector>
using std::vector;
using std::string;
using std::exception;

class SparseMatrixException : exception 
{
private:
	std::string whatStr;
public:
	const char* what() const noexcept { return this->whatStr.c_str(); }
public:
	SparseMatrixException(std::string&& whatStr) noexcept : whatStr(std::move(whatStr)) { }
	SparseMatrixException(const std::string& whatStr) noexcept : whatStr(whatStr) { }
	~SparseMatrixException() noexcept = default;
};
template<typename _T>
class SparseMatrix
{
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
	_T get(int row, int column) const
	{
		this->validateCoordinates(row, column);

		int currentColumn;

		for (int pos = (*(this->m_ptrs))[row - 1] - 1; pos < (*(this->m_ptrs))[row] - 1; ++pos) 
		{
			currentColumn = (*(this->cols))[pos];
			if (currentColumn == column) 
				return (*(this->vals))[pos];
			else if (currCol > col) 
				break;
		}

		return _T();
	}
	//Set value at position (row,column) in matrix
	void set(_T value, int row, int column)
	{
		this->validateCoordinates(row, column);

		int pos = (*(this->m_ptrs))[row - 1] - 1;
		int currCol = 0;

		for (; pos < (*(this->m_ptrs))[row] - 1; pos++) 
		{
			currCol = (*(this->m_cols))[pos];
			if (currCol >= column) 
				break;
		}

		if (currCol != col) {
			if (!(value == T())) {
				this->insert(pos, row, col, val);
			}

		}
		else if (value == T()) {
			this->remove(pos, row);

		}
		else {
			(*(this->m_data))[pos] = val;
		}

		return *this;
	}
	uint32_t getRows() const 
	{ 
		return this->m_nrows; 
	}
	uint32_t getColumns() const 
	{
		return this->m_ncolumns; 
	}
public:
	SparseMatrix<_T>& operator = (const SparseMatrix<_T>& other)
	{
		if (&other != this) 
		{
			this->destruct();
			this->copy(other);
		}
		return *this;
	}

	vector<_T> multiply(const vector<_T>& other) const
	{
		//TODO
	}
	vector<_T> operator * (const vector<_T>& other) const
	{
		//TODO
	}

	SparseMatrix<_T> multiply(const SparseMatrix<_T>& other) const
	{

	}
	SparseMatrix<_T> operator * (const SparseMatrix<_T>& other) const
	{

	}
	SparseMatrix<_T> add(const SparseMatrix<_T>& other) const
	{

	}
	SparseMatrix<_T> operator + (const SparseMatrix<_T>& other) const
	{

	}
	SparseMatrix<_T> subtract(const SparseMatrix<_T>& other) const
	{

	}
	SparseMatrix<_T> operator - (const SparseMatrix<_T>& other) const
	{

	}
private:
	void construct(uint32_t rows, uint32_t columns)
	{
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
	void destruct()
	{
		if (this->m_data)
		{
			delete this->m_data;
			delete this->m_cols;
		}
		delete m_ptrs;
	}
	void copy(const SparseMatrix<_T>& other)
	{
		//Copy dimensions and ptrs vector from other matrix
		this->m_nrows = other.m_nrows;
		this->m_ncolumns = other.m_ncolumns;
		this->m_ptrs = new vector<int>(*(other.m_ptrs));
		//If other matrix have non-zero values,copy it
		if (other.m_data)
		{
			this->m_cols = new vector<int>(*(other.m_cols));
			this->m_data = new vector<_T>(*(other.m_data));
		}
	}
	bool validateCoordinates(uint32_t rows, uint32_t columns)
	{
		if ( rows < 1 || columns < 1 || rows > this->m_nrows || columns > this->m_ncolumns) 
		{
			throw SparseMatrixException("Invalid coordinates");
		}
	}
	//Insert value to matrix
	void insert(uint32_t index, uint32_t row, uint32_t column, _T value)
	{
		if (!this->m_data)
		{
			this->m_cols = new vector<int>(1, column);
			this->m_data = new vector<_T>(1, value);
		}
		else 
		{
			this->m_cols->insert(this->m_cols->begin() + index, column);
			this->m_data->insert(this->m_data->begin() + index, value);
		}
		for (int i = row; i <= this->m_nrows; i++) 
		{
			(*(this->m_ptrs))[i]++;
		}
	}
	//Remove value from matrix
	void remove(uint32_t index, uint32_t row)
	{
		this->m_data->erase(this->m_data->begin() + index);
		this->m_cols->erase(this->m_cols->begin() + index);

		for (int i = row; i <= this->m_nrows; i++)	
		{
			(*(this->m_ptrs))[i]--;
		}
	}
public:
	//The default constructor create matrix with 5 rows and 5 columns
	SparseMatrix()
	{
		this->construct(5, 5);
	}
	//Square matrix n x n
	SparseMatrix(uint32_t n)
	{
		this->construct(n, n);
	}
	//Create matrix with rows x columns dimension
	SparseMatrix(uint32_t rows, uint32_t columns)
	{
		this->construct(rows, columns);
	}
	//Copy constructor
	SparseMatrix(const SparseMatrix<_T>& other)
	{
		this->copy(other);
	}
	//Matrix destructor
	~SparseMatrix()
	{
		this->destruct();
	}
};
