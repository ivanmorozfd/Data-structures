#pragma once
#include <exception>
#include <string>
#include <vector>
using std::vector;
using std::string;
using std::exception;
/*!
	Exception class for SparseMatrix
	\brief Provide for SparseMatrix throw mechanism
	\author ivanmorozfd
	\version 1.0
	\date April 2020
*/
class SparseMatrixException : exception {
private:
	std::string whatStr;
public:
	const char* what() const noexcept override  { 
		return this->whatStr.c_str(); 
	}
public:
	SparseMatrixException(std::string&& whatStr) noexcept : whatStr(std::move(whatStr)) { }
	SparseMatrixException(const std::string& whatStr) noexcept : whatStr(whatStr) { }
	~SparseMatrixException() noexcept = default;
};