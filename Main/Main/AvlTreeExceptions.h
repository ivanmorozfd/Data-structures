#pragma once
#include <exception>
#include <string>
using std::string;
using std::exception;
/*!
	Exception class for AvlTree
	\brief Provide for AvlTree throw mechanism
	\author ivanmorozfd
	\version 1.0
	\date April 2020
*/
class AvlTreeException :exception {
private:
	std::string whatStr;
public:
	const char* what() const noexcept override {
		return this->whatStr.c_str();
	};
public:
	AvlTreeException(std::string&& whatStr) noexcept : whatStr(std::move(whatStr)) { }
	AvlTreeException(const std::string& whatStr) noexcept : whatStr(whatStr) { }
	~AvlTreeException() noexcept = default;
};