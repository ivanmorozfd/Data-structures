#pragma once
#include <string>
#include <exception>

using std::exception;
using std::string;
/*!
	Exception class for RBTree
	\brief Provide for RBTree throw mechanism
	\author ivanmorozfd
	\version 1.0
	\date April 2020
*/
class RBTreeException : exception {
private:
	std::string whatStr;
public:
	const char* what() const noexcept override {
		return this->whatStr.c_str();
	}
public:
	RBTreeException(std::string&& whatStr) noexcept : whatStr(std::move(whatStr)) { }
	RBTreeException(const std::string& whatStr) noexcept : whatStr(whatStr) { }
	~RBTreeException() noexcept = default;
};