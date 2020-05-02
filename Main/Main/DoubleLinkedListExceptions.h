#pragma once
#include <string>
#include <exception>

using std::exception;
using std::string;
/*!
	Exception class for DoubleLinkedList
	\brief Provide for DoubleLinkedList throw mechanism
	\author ivanmorozfd
	\version 1.0
	\date April 2020
*/
class DoubleLinkedListException : exception {
private:
	std::string whatStr;
public:
	const char* what() const noexcept override {
		return this->whatStr.c_str();
	}
public:
	DoubleLinkedListException(std::string&& whatStr) noexcept : whatStr(std::move(whatStr)) { }
	DoubleLinkedListException(const std::string& whatStr) noexcept : whatStr(whatStr) { }
	~DoubleLinkedListException() noexcept = default;
};