#pragma once
#include "core.h"
#include "Container.h"
#include "StackException.h"
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
	typedef _StackNode& NodeRef;//!< Node reference type
	using valueType = _T;//!< Element type
	using reference = valueType&;//!< Reference element type
	using const_reference = const _T&;
	valueType data;//!< Node value
	NodePtr prev;//!< Pointer to previous Node
public:
	_StackNode(const NodeRef) = delete;
	_StackNode& operator=(const NodeRef) = delete;
public:
	/*!
		Default _StackNode constructor
	*/
	_StackNode() = default;
	/*!
		Parameterized _StackNode constructor
	    \param[in] valueType& Node data
	*/
	_StackNode(const_reference data) :
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
	using const_reference = const _T&;// Const reference element type
	using NodePtr = _StackNode<_T>*;// Pointer node type
	using NodeRef = _StackNode<_T>;// Reference node type
private:
	/*!
		Default stack constructor
	*/
	NodePtr _top; //This structure contains data and pointer to previous node
	size_t count; //number of elements in the stack
public:
	/*!
		Returns the stack size
		\param[out] size Stack size
	*/
	size_t getSize() const {
			return this->count;
	}
	/*!
		Returns the value at the top of the Stack
		\param[out] valueType
	*/
	reference peek() const {
		if (!isEmpty())
			return _top->data;
		else
			throw StackException("Stack is empty");
	}
	/*!
		Checking the Stack for empty space
		\param[out] bool True,if Stack is empty
	*/
	bool isEmpty() const override {
		return !_top;
	}
	/*!
		Push element to the Stack
		\param[in] item Element for push
	*/
	void push(valueType item) {
		//create new stack node
		NodePtr tmp = new NodeRef(item);
		tmp->prev = _top;
		//set new top of the stack
		_top = tmp;
		count++;
	}
	/*!
		Remove element from the Stack
	*/
	void pop() {
		if (!isEmpty()) 
		{
			//set new top
			NodePtr tmp = _top;
			_top = _top->prev;
			//free temp pointer
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
		NodePtr tmp = this->_top;
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
		NodePtr tmp = stack->_top;
		do {
			std::cout << tmp->data << " ";
		} while (tmp = tmp->prev);
	}
public:
	/*!	
		Default Stack constructor
	*/
	Stack(): 
		_top(nullptr),
		count(0) { }
	/*!
		Parameterized Stack constructor
	    \param[in] initializer_list<valueType>list STL init list
	*/
	Stack(const std::initializer_list<valueType>& data): 
		_top(nullptr),
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

