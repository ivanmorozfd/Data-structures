#include <string>
#include <exception>
using std::exception;
using std::string;

class DequeException : exception
{
private:
	std::string whatStr;
public:
	const char* what() const noexcept override;
public:
	DequeException(std::string&& whatStr) noexcept : whatStr(std::move(whatStr)) { }
	DequeException(const std::string& whatStr) noexcept : whatStr(whatStr) { }
	~DequeException() noexcept = default;
	const char* what() const noexcept {
		return this->whatStr.c_str();
	}
};