#pragma once
#include <string>
#include <exception>

using std::exception;
using std::string;

class DoubleLinkedListException : exception
{
private:
	std::string whatStr;
public:
	const char* what() const noexcept override;
public:
	DoubleLinkedListException(std::string&& whatStr) noexcept : whatStr(std::move(whatStr)) { }
	DoubleLinkedListException(const std::string& whatStr) noexcept : whatStr(whatStr) { }
	~DoubleLinkedListException() noexcept = default;
};
inline const char* DoubleLinkedListException::what() const noexcept {
	return this->whatStr.c_str();
}