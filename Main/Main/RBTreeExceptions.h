#pragma once
#include <string>
#include <exception>

using std::exception;
using std::string;

class RBTreeException : exception
{
private:
	std::string whatStr;
public:
	const char* what() const noexcept override;
public:
	RBTreeException(std::string&& whatStr) noexcept : whatStr(std::move(whatStr)) { }
	RBTreeException(const std::string& whatStr) noexcept : whatStr(whatStr) { }
	~RBTreeException() noexcept = default;
};
inline const char* RBTreeException::what() const noexcept {
	return this->whatStr.c_str();
}