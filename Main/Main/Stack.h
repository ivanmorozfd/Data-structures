#pragma once
#include "core.h"
#include "Container.h"
#include <string>
#include "StackException.h"
#include <list>
using std::string;
/*!
	Data representation in Stack
	Contain pointer to previous element,and data
	\brief Stack element wrapper
	\author ivanmorozfd
	\version 1.0
	\date April 2020
*/
template<typename _T>
struct _StackNode {
public:
	typedef _StackNode* NodePtr;//!< Node pointer type
	using valueType = _T;//!< Element type
	using reference = valueType&;//!< Reference element type
	valueType data;//!< Node value
	NodePtr prev;//!< Pointer to previous Node
public:
	_StackNode(const _StackNode&) = delete;
	_StackNode& operator=(const _StackNode&) = delete;
public:
	/*!
		Default _StackNode constructor
	*/
	_StackNode() = default;
	/*!
		Parameterized _StackNode constructor
	    \param[in] valueType& Node data
	*/
	_StackNode(const reference data) :
		data(data),
		prev(nullptr) {}
};


/*!
	Stack class
	\brief Use to store data
	\author ivanmorozfd
	\version 1.0
	\date April 2020
*/
template<typename _T>
class Stack : public Container {
private:
	using valueType = _T;// Element type
	using reference = valueType&;// Reference element type
	using NodePtr = _StackNode<_T>*;// Pointer node type
	using NodeRef = _StackNode<_T>;// Reference node type
private:
	/*!
		Default stack constructor
	*/
	NodePtr m_top; //This structure contains data and pointer to previous node
	size_t count; //number of elements in the stack
public:
	/*!
		Returns the stack size
		\param[out] size_t Stack size
	*/
	size_t getSize() const {
		if (!this->isEmpty())
			return this->count;
		else
			throw StackException("Stack is empty");
	}
	/*!
		Returns the value at the top of the Stack
		\param[out] valueType
	*/
	reference peek() const {
		if (!isEmpty())
			return m_top->data;
		else
			throw StackException("Stack is empty");
	}
	/*!
		Checking the Stack for empty space
		\param[out] bool True,if Stack is empty
	*/
	bool isEmpty() const override {
		return !m_top;
	}
	/*!
		Push element to the Stack
		\param[in] valueType item
	*/
	void push(valueType item) {
		//create new stack node
		NodePtr tmp = new NodeRef(item);
		tmp->prev = m_top;
		//set new top of the stack
		m_top = tmp;
		count++;
	}
	/*!
		Remove element from the Stack
	*/
	void pop() {
		if (!isEmpty()) 
		{
			NodePtr tmp = m_top;
			m_top = m_top->prev;
			delete tmp;
			count--;
		}
		else 
			throw StackException("Stack is empty");
	}
	/*!
		Clear stack
	*/ 
	void clear() {
		for (;!isEmpty();)
			this->pop();
	}
	/*!
		Does the item exist in the Stack
		\param[out] bool True, if elem exist ,otherwise false
		\param[in] const reference Checked value
	*/
	bool contain(const reference value) const {
		NodePtr tmp = this->m_top;
		bool isFound = false;
		do {
			if (tmp->data == value) {
				isFound = true;
				break;
			}
		} while (tmp = tmp->prev);
		return isFound;
	}
	/*!
		Display Stack data
		\brief Friend function,help to print Stack data
	*/
	template<class _T>
	friend void print_stack(Stack<valueType>* stack) {
		NodePtr tmp = stack->m_top;
		do {
			std::cout << tmp->data << " ";
		} while (tmp = tmp->prev);
	}
public:
	/*!
		Default Stack constructor
	*/
	Stack(): 
		m_top(nullptr),
		count(0) { }
	/*!
		Parameterized Stack constructor
	    \param[in] initializer_list<valueType>list STL init list
	*/
	Stack(const std::initializer_list<valueType>& data): 
		m_top(nullptr),
		count(0) {
		for (auto i : data) 
			this->push(i);
	}
	/*!
		Stack destructor
	*/
	~Stack() {
		this->clear();
	}
};	

