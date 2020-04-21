#pragma once
#include <exception>
#include <string>
using std::string;
using std::exception;

class SingleLinkedListException :exception {
private:
	std::string whatStr;
public:
	const char* what() const noexcept override {
		return this->whatStr.c_str();
	}
public:
	SingleLinkedListException(std::string&& whatStr) noexcept : whatStr(std::move(whatStr)) { }
	SingleLinkedListException(const std::string& whatStr) noexcept : whatStr(whatStr) { }
	~SingleLinkedListException() noexcept = default;
};