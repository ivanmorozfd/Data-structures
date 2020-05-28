#pragma once
#include <string>
#include <exception>

using std::exception;
using std::string;
/*!
	Exception class for MultiDataList 
	\brief Provide for MultiDataList throw mechanism
	\author ivanmorozfd
	\version 1.0
	\date April 2020
*/
class MultiDataListException : exception {
private:
	std::string whatStr;
public:
	const char* what() const noexcept override {
		return this->whatStr.c_str();
	}
public:
	MultiDataListException(std::string&& whatStr) noexcept : whatStr(std::move(whatStr)) { }
	MultiDataListException(const std::string& whatStr) noexcept : whatStr(whatStr) { }
	~MultiDataListException() noexcept = default;
};