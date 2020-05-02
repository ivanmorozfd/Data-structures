#pragma once
#include <exception>
#include <string>
using std::string;
using std::exception;
/*!
	Exception class for Queue
	\brief Provide for Queue throw mechanism
	\author ivanmorozfd
	\version 1.0
	\date April 2020
*/
class QueueException :exception {
private:
	std::string whatStr;
public:
	const char* what() const noexcept override {
		return this->whatStr.c_str();
	};
public:
	QueueException(std::string&& whatStr) noexcept : whatStr(std::move(whatStr)) { }
	QueueException(const std::string& whatStr) noexcept : whatStr(whatStr) { }
	~QueueException() noexcept = default;
};