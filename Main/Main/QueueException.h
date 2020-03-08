#pragma once
#pragma once
#include <exception>
#include <string>
using std::string;
using std::exception;

class QueueException :exception 
{
private:
	std::string whatStr;
public:
	const char* what() const noexcept override;
public:
	QueueException(std::string&& whatStr) noexcept : whatStr(std::move(whatStr)) { }
	QueueException(const std::string& whatStr) noexcept : whatStr(whatStr) { }
	~QueueException() noexcept = default;
};
inline const char* QueueException::what() const noexcept
{
	return this->whatStr.c_str();
};