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