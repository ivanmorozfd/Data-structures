#pragma once
#include <string>
#include "StackException.h"
using std::string;

template<typename _T>
class Stack
{
private:
	template<typename _T>
	class Node
	{
	public:
		_T data;
		Node* prev;
	};
	Node<_T>* m_top;//This structure contains data and pointer to previous node
	unsigned count;	//number of elements in the stack
public:
	//returns the stack size
	unsigned getSize() const 
	{ 
		return this->count;
	}
	//returns the value at the top of the stack
	_T getTop() const 
	{
		if (!isEmpty())
			return m_top->data;
		else
			throw StackException("Stack is empty");
	}
	//checking the stack for empty space
	bool isEmpty() const 
	{
		return !m_top;
	}
	//add element to stack
	void push(const _T& item)
	{
		//create new stack node
		Node<_T>* tmp = new Node<_T>();
		tmp->data = item;
		tmp->prev = m_top;
		//set new top of the stack
		m_top = tmp;

		count++;
	}
	//remove element stack
	void pop() 
	{
		if (!isEmpty()) 
		{
			Node<_T>* tmp = m_top;
			m_top = m_top->prev;
			delete tmp;
			count--;
		}
		else 
			throw StackException("Stack is empty");
		
	}
	//clear stack
	void clear()
	{
		for (;!isEmpty();)
			this->pop();
	}
public:
	Stack(): 
		m_top(nullptr),
		count(0) { }
	Stack(const std::initializer_list<_T>& data): 
		m_top(nullptr),
		count(0)
	{
		for (auto i : data) 
			this->push(i);
	}
	Stack(const Stack& other)
	{

	}
	~Stack()
	{
		this->clear();
	}
};

