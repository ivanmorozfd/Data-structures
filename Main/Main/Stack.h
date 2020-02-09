#pragma once
#include <string>
#include <exception>
#include <iterator>
#include <memory>
#include "StackIterator.h"
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
class Node
{
public:
	T data;
	Node* prev;
};
template<typename T>
class Stack
{
public:
	typedef StackIterator<T> iterator;
	typedef StackIterator<const T> const_iterator;
public:
	Stack<T>::iterator rend()
	{
		Node<T>* temp = m_top;
		for (int i = count - 1; i > 0; i--)
		{
			temp = temp->prev;
		}
		return iterator(temp);
	}
	Stack<T>::iterator rbegin()
	{
		return iterator(m_top);
	}
	Stack<T>::const_iterator begin() const	
	{
		return const_iterator(begin());
	}
	Stack<T>::const_iterator end() const
	{
		return const_iterator(end());
	}
public:
	//This structure contain data and pointer to previous node
	Node<T>* m_top;
	unsigned count;
public:
	T getTop() const 
	{
		if (!isEmpty())
			return m_top.get()->data;
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
	T pop() 
	{
		if (!isEmpty()) 
		{
			Node* tmp = m_top;
			T returnData = m_top->data;
			m_top = m_top->prev;
			delete tmp;
			count--;
			return returnData;
		}
		else {
			throw StackException("Stack is empty");
		}
	}
public:
	Stack() : m_top(nullptr), count(0) { }

	Stack(std::initializer_list<T>data): 
		m_top(nullptr),
		count(data.size)
	{
		for (auto i : data) {
			this->push(i);
		}
	}
	void printStack() const {
		Node<T>* tmp = m_top;
		do {
			std::cout << tmp->data;
		} while (tmp = tmp->prev);
		delete tmp;
	}
};

