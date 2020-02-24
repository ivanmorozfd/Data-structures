#pragma once
#include <string>
#include <exception>
#include <iterator>

using std::exception;
using std::string;
using std::iterator;
/* Simple stack implementation with C++
Stack is a linear data structure which follows a particular order in which the operations are performed.
The order may be LIFO(Last In First Out) or FILO(First In Last Out).
*/
/*	Big O-notation
Time complexity
Operation		Average			Worst

Access			O(n)			O(n)
Search			O(n)			O(n)
Insertion		O(1)			O(1)
Deletion		O(1)			O(1)
*/
/*
Usage:
1)Infix to postfix 
2)Prefix to infix Conversion
3)Prefix to postfix Conversion
4)Postfix to prefix conversion
5)Postfix to Infix
6)Convert Infix To Prefix Notation
7)The Stock Span Problem
8)Expression Evaluation
9)Arithmetic Expression Evalution
10)Evaluation of Postfix Expression
*/

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
class Stack
{
	template<typename T>
	class Node
	{
	public:
		T data;
		Node* prev;
	};
private:
	Node<T>* m_top;
	unsigned count;
public:
	unsigned getSize() const 
	{ 
		return this->count; 
	}
	T getTop() const 
	{
		if (!isEmpty())
			return m_top->data;
		else
			throw StackException("Stack is empty");
	}
	bool isEmpty() const 
	
{
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
		else 
		{
			throw StackException("Stack is empty");
		}
	}
	void clear()
	{

	}
public:
	Stack() : m_top(nullptr), count(0) 
	{ 

	}

	Stack(std::initializer_list<T>data): 
		m_top(nullptr),
		count(0)
	{
		for (auto i : data) {
			this->push(i);
		}
	}
};


