#pragma once
#include "QueueException.h"

template<typename _T>
class Queue {
private:
	//data representation in queue
	//contain pointer to previous element,and data
	template<typename _T>
	class Node {
	public:
		_T data;
		Node* next;
		Node(const _T& data) :
			data(data),
			next(nullptr) { }
	};
private:
	Node<_T>* pFront;//pointer to the begin of the queue
	Node<_T>* pBack;//pointer to the end of the queue
	unsigned count;//number of elements in queue
public:
	//returns the queue length
	unsigned getLenght() const {
		if (!isEmpty())
			return this->count;
		else
			throw QueueException("Queue is Empty");
	}
	//delete an item from the beginning of the queue
	void pop() {
		if (!isEmpty()) {
			Node<_T>* temp = pFront;

			this->pFront = this->pFront->next;
			delete temp;
		}
		else
			throw QueueException("Queue is Empty");
	}
	//add item to the queue
	void push(const _T& item) {
		this->count++;

	    Node<_T>* node = new Node<_T>(item);

		if (!pBack)
			this->pFront = this->pBack = node;
		else {
			this->pBack->next = node;
			this->pBack = node;
		}
	}
	//does the queue contain elements
	bool isEmpty() const {
		return this->pFront == this->pBack;
	}
	//clear the queue
	void clear() {
		for (;isEmpty();)
			this->pop();
	}
	//returns an element at the beginning of the queue
	_T peek() {
		if (!isEmpty())
			return this->pFront->data;
		else
			throw QueueException("Queue is Empty");
	}
	//does the item exist in the queue
	bool contain(const _T& item) const {
		Node<_T>* tmp = this->pFront;

		bool isFound = false;

		do {
			if (tmp->data == item) {
				isFound = true;
				break;
			}
		} while (tmp = tmp->next);
		return isFound;
	}
	//display the contents of a queue
	template<class _T>
	friend void print_queue(Queue<_T>* queue) {
		Node<_T> tmp = queue->pFront;

		do {
			std::cout << tmp.data << " ";
		} while (tmp = tmp->next);
	}
public:
	Queue():
		count(0),
		pBack(nullptr),
		pFront(nullptr) { 
		this->pBack = this->pFront;
	}
	Queue(const std::initializer_list<_T>& data) { 
		for (auto i : data)
			this->push(i);
	}
	~Queue() {
		this->clear();
	}
};
