#pragma once
#include <exception>
#include <string>
using std::string;
using std::exception;

class QueueException:exception {
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


template<typename T>
class Node
{
public:
	T data;
	Node* next;
};


template<typename T>
class Queue 
{
private:
	Node<T>* front;
	Node<T>* back;
	unsigned count;
public:
	unsigned getSize() const { return this->count; }
public:
	void pop() 
	{

	}
	void push(T item) 
	{

	}
	bool empty() {
		return front == back;
	}
public:
	Queue() { }
	Queue(std::initializer_list) { }
	~Queue() { }
};
