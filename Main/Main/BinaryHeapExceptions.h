#pragma once
#include <exception>
#include <string>
using std::string;
using std::exception;

class BinaryHeapException :exception
{
private:
	std::string whatStr;
public:
	const char* what() const noexcept override;
public:
	BinaryHeap(std::string&& whatStr) noexcept : whatStr(std::move(whatStr)) { }
	BinaryHeap(const std::string& whatStr) noexcept : whatStr(whatStr) { }
	~BinaryHeap() noexcept = default;
};
inline const char* BinaryHeap::what() const noexcept
{
	return this->whatStr.c_str();
};
