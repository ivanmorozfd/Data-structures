#pragma once
#include "core.h"
#include "Container.h"
#include "QueueException.h"

/*!
	Data representation in queue
	Contain pointer to next element,and data
	\brief Queue element wrapper
	\author ivanmorozfd
	\version 1.0
	\date April 2020
*/
template<typename _T>
struct _QueueNode {
public:
	typedef _QueueNode* NodePtr;//!< Node pointer
	using valueType = _T;//!< Element type
	using reference = valueType&;//!< Reference element type
	valueType data;//!< Node value
	NodePtr next;//!< Pointer to previous Node
public:
	_QueueNode(const _QueueNode&) = delete;
	_QueueNode& operator=(const _QueueNode&) = delete;
public:
	/*!
		Default _QueueNode constructor
	*/
	_QueueNode() = default;
	/*!
		Parameterized _QueueNode constructor
		\param[in] valueType& Node data
	*/
	_QueueNode(valueType data) :
		data(data),
		next(nullptr) { }
};

/*!
	Queue class
	\brief Use to store data
	\author ivanmorozfd
	\version 1.0
	\date April 2020
*/
template<typename _T>
class Queue : public Container{
	using valueType = _T;// Element Type
	using reference = valueType&;// Reference element type
	using NodePtr = _QueueNode<_T>*;// Node pointer type
	using NodeRef = _QueueNode<_T>;// Node reference type
private:
	NodePtr pFront;// pointer to the begin of the queue
	NodePtr pBack;// pointer to the end of the queue
	size_t count;// number of elements in queue
public:
	/*!
		Returns the Queue size
		\param[out] size_t Queue size
	*/
	size_t getLenght() const {
		if (!isEmpty())
			return this->count;
		else
			throw QueueException("Queue is Empty");
	}
	/*!
		Remove item from the queue
	*/
	void pop() {
		if (!isEmpty()) {
			NodePtr temp = pFront;
			this->pFront = this->pFront->next;
			delete temp;
		}
		else
			throw QueueException("Queue is Empty");
	}
	/*!
		Add item to the queue
		\param[in] valueType item 
	*/
	void push(valueType item) {
		this->count++;
		NodePtr node = new NodeRef(item);
		
		if (!pBack)
			this->pFront = this->pBack = node;
		else {
			this->pBack->next = node;
			this->pBack = node;
		}
	}
	/*!
		Checking the Queue for empty space
		\param[out] bool True,if Queue is empty
	*/
	bool isEmpty() const override {
		return this->pFront == this->pBack;
	}
	/*!
		Remove all elements from the Queue
	*/
	void clear() {
		for (;isEmpty();)
			this->pop();
	}
	/*!
		Returns an element at the beginning of the Queue
		\param[out] valueType
	*/
	valueType peek() {
		if (!isEmpty())
			return this->pFront->data;
		else
			throw QueueException("Queue is Empty");
	}
	/*!
		Does the item exist in the Queue,otherwise false
		\param[out] bool True, if elem exist
		\param[in] valueType Checked value
	*/
	bool contain(const reference item) const {
		NodePtr tmp = this->pFront;
		bool isFound = false;

		do {
			if (tmp->data == item) {
				isFound = true;
				break;
			}
		} while (tmp = tmp->next);
		return isFound;
	}
	/*!
		Display Queue data
		\brief Friend function,help to print Queue data
	*/
	template<class _T>
	friend void print_queue(Queue<_T>* queue) {
		NodePtr tmp = queue->pFront;
		do {
			std::cout << tmp->data << " ";
		} while (tmp = tmp->next);
	}
public:
	/*!
		Default Queue constructor
	*/
	Queue():
		count(0),
		pBack(nullptr),
		pFront(nullptr) { 
		this->pBack = this->pFront;
	}
	/*!
		Parameterized Queue constructor
		\param[in] initializer_list<valueType>list STL init list
	*/
	Queue(const std::initializer_list<_T>& data) { 
		for (auto i : data)
			this->push(i);
	}
	/*!
		Queue destructor
	*/
	~Queue() {
		this->clear();
	}
};
