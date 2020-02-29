#pragma once
#include <string>
#include <exception>
using std::exception;
using std::string;

class StackException : exception 
{
private:
	std::string whatStr;
public:
	const char* what() const noexcept override;
public:
	StackException(std::string&& whatStr) noexcept : whatStr(std::move(whatStr)) { }
	StackException(const std::string& whatStr) noexcept : whatStr(whatStr) { }
	~StackException() noexcept = default;
};
inline const char* StackException::what() const noexcept {
	return this->whatStr.c_str();
}


template<typename T>
class Node
{
public:
	T data;
	Node* prev;
};
template<typename T>
class Stack
{
private:
	//This structure contain data and pointer to previous node
	Node<T>* m_top;
	unsigned count;	
public:
	unsigned getSize() const { return this->count; }
	T getTop() const 
	{
		if (!isEmpty())
			return m_top->data;
		else
			throw StackException("Stack is empty");
	}
	bool isEmpty() const {
		return !m_top;
	}
	void push(T item)
	{
		Node<T>* tmp = new Node<T>();
		tmp->data = item;
		tmp->prev = m_top;
		m_top = tmp;
		count++;
	}
	void pop() 
	{
		if (!isEmpty()) 
		{
			Node<T>* tmp = m_top;
			m_top = m_top->prev;
			delete tmp;
			count--;
		}
		else {
			throw StackException("Stack is empty");
		}
	}
	void clear()
	{
		for (; !isEmpty();)
			this->pop();
	}
public:
	Stack() : m_top(nullptr), count(0) { }

	Stack(std::initializer_list<T>data): 
		m_top(nullptr),
		count(0)
	{
		for (auto i : data) {
			this->push(i);
		}
	}
};

