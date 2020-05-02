#pragma once
#include <exception>
#include <string>
using std::string;
using std::exception;
/*!
	Exception class for BinaryHeap
	\brief Provide for BinaryHeap throw mechanism
	\author ivanmorozfd
	\version 1.0
	\date April 2020
*/
class BinaryHeapException :exception {
private:
	std::string whatStr;
public:
	const char* what() const noexcept override {
		return this->whatStr.c_str();
	};

public:
	BinaryHeapException(std::string&& whatStr) noexcept : whatStr(std::move(whatStr)) { }
	BinaryHeapException(const std::string& whatStr) noexcept : whatStr(whatStr) { }
	~BinaryHeapException() noexcept = default;
};
