#include <string>
#include <exception>
using std::exception;
using std::string;
/*!
	Exception class for Deque
	\brief Provide for Deque throw mechanism
	\author ivanmorozfd
	\version 1.0
	\date April 2020
*/
class DequeException : exception {
private:
	std::string whatStr;
public:
	const char* what() const noexcept override {
		return this->whatStr.c_str();
	}
public:
	DequeException(std::string&& whatStr) noexcept : whatStr(std::move(whatStr)) { }
	DequeException(const std::string& whatStr) noexcept : whatStr(whatStr) { }
	~DequeException() noexcept = default;
};