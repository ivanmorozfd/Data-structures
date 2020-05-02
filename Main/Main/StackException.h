#pragma once
#include <string>
#include <exception>
using std::exception;
using std::string;
/*!
	Exception class for Stack
	\brief Provide for Stack throw mechanism
	\author ivanmorozfd
	\version 1.0
	\date April 2020
*/
class StackException : exception {
private:
	std::string whatStr;
public:
	const char* what() const noexcept override {
		return this->whatStr.c_str();
	}
public:
	StackException(std::string&& whatStr) noexcept : whatStr(std::move(whatStr)) { }
	StackException(const std::string& whatStr) noexcept : whatStr(whatStr) { }
	~StackException() noexcept = default;
};

	