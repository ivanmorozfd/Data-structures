#pragma once
#include "DequeExceptions.h"
template<typename _T>
class Node {
public:
	_T value;
	Node<_T>* prev;
	Node<_T>* next;
	Node(const _T& item) : value(item),
		prev(nullptr),
		next(nullptr) { }
};

template<typename _T>
class Deque {
private:
	unsigned int count;
	Node<_T>* pFront;
	Node<_T>* pBack;
public:
	bool is_empty() const {
		return !this->pFront;
	}
	_T front() const {
		if(!is_empty())
			return this->this->pFront->value;
		else
			throw DequeException("Deque is empty");
	}
	_T back() const {
		if(!is_empty())
			return this->pBack->value;
		else
			throw DequeException("Deque is empty");
	}
	void pop_back() {
		if (!is_empty()) {
			Node<_T>* tmp_pBack = this->pBack;
			this->pBack = this->pBack->prev;
			delete tmp_pBack;
		}
		else
			throw DequeException("Deque is empty");
	}
	void  pop_front() {
		if (!is_empty()) {
			Node<_T>* tmp_pFront = this->pFront;
			this->pFront = this->pFront->next;
			delete tmp_pFront;
		}
		else
			throw DequeException("Deque is empty");
	}
	void push_back(const _T& item) {
		Node<_T>* tmp = new Node<_T>(item);
		this->count++;
		if (this->pFront) {
			tmp->prev = this->pBack;
			this->pBack->next = tmp;
			this->pBack = tmp;
		}
		else 
			this->pFront = this->pBack = tmp;
	}
	void push_front(const _T& item) {
		Node<_T>* tmp = new Node<_T>(item);
		this->count++;
		if (this->pFront) {
			tmp->next = this->pFront;
			this->pFront->prev = tmp;
			this->pFront = tmp;
		}
		else 
			this->pFront = this->pBack = tmp;
	}
	void clear()
	{
		for(;!is_empty();)
			pop_front();
	}
public:
	Deque() :
		this->pFront(nullptr),
		this->pBack(nullptr),
		count(0) { }
	Deque(const std::initializer_list<_T>& data) { }
	Deque(const Deque& other) { }
	~Deque() {
		this->clear();
	}
};
