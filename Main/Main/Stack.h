#pragma once
#include <string>
#include "StackException.h"
using std::string;

template<typename _T>
class Stack {
private:
	//data representation in stack
	//contain pointer to previous element,and data
	template<typename _T>
	class Node {
	public:
		_T data;
		Node* prev;
		Node(const _T& data): 
			data(data),
			prev(nullptr) {}
	};
	Node<_T>* m_top;//This structure contains data and pointer to previous node
	unsigned count;	//number of elements in the stack
public:
	//returns the stack size
	unsigned getSize() const { 
		return this->count;
	}
	//returns the value at the top of the stack
	_T peek() const {
		if (!isEmpty())
			return m_top->data;
		else
			throw StackException("Stack is empty");
	}
	//checking the stack for empty space
	bool isEmpty() const {
		return !m_top;
	}
	//add element to stack
	void push(const _T& item) {
		//create new stack node
		Node<_T>* tmp = new Node<_T>(item);
		tmp->prev = m_top;
		//set new top of the stack
		m_top = tmp;
		count++;
	}
	//remove element from stack
	void pop() {
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
	void clear() {
		for (;!isEmpty();)
			this->pop();
	}
	//return is value avialable in stack
	bool contain(_T value) const {
		Node<_T>* tmp = this->m_top;
		bool isFound = false;
		do {
			if (tmp->data == value) {
				isFound = true;
				break;
			}
		} while (tmp = tmp->prev);
		return isFound;
	}
	//display stack data
	template<class _T>
	friend void print_stack(Stack<_T>* stack) {
		Node<_T>* tmp = stack->m_top;
		do {
			std::cout << tmp->data << " ";
		} while (tmp = tmp->prev);
	}
public:
	Stack(): 
		m_top(nullptr),
		count(0) { }
	Stack(const std::initializer_list<_T>& data): 
		m_top(nullptr),
		count(0) {
		for (auto i : data) 
			this->push(i);
	}
	~Stack() {
		this->clear();
	}
};	

