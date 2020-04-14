#include <string>
#include <exception>
using std::exception;
using std::string;

class BinarySearchTreeException : exception
{
private:
	std::string whatStr;
public:
	const char* what() const noexcept override {
		return this->whatStr.c_str();
	}
public:
	BinarySearchTreeException(std::string&& whatStr) noexcept : whatStr(std::move(whatStr)) { }
	BinarySearchTreeException(const std::string& whatStr) noexcept : whatStr(whatStr) { }
	~BinarySearchTreeException() noexcept = default;
};