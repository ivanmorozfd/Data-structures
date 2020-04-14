#pragma once
#include <string>
#include <exception>

using std::exception;
using std::string;

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