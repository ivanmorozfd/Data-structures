#pragma once
#include <exception>
#include <string>
using std::string;
using std::exception;

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