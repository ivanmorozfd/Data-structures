#pragma once
#include "SingleLinkedListIterator.h"
#include "SingleLinkedListException.h"
using std::initializer_list;
template<typename _T>
class SingleLinkedList {
private:
	friend SingleLinkedListIterator<_T>;
	template<typename _T>
	class Node {
	public:
		_T data;
		Node* next;
		Node(const _T data) :
			data(data),
			next(nullptr) { }
	};
	typedef SingleLinkedListIterator<_T> iterator;
	typedef SingleLinkedListIterator<const _T> const_iterator;
private:
	Node<_T>* pFront;//pointer at the begin of the list
	Node<_T>* pBack;//pointer at the end of the list
	unsigned count;
public:
	SingleLinkedList<_T>::iterator begin() {
		return iterator(pFront);
	}
	SingleLinkedList<_T>::iterator end() {
		return iterator(pBack->next);
	}
	SingleLinkedList<_T>::const_iterator begin() const {
		return const_iterator(begin());
	}
	SingleLinkedList<_T>::const_iterator end() const {
		return const_iterator(end());
	}
public:
	//return element at the begin of the list
	_T front() {
		if (!isEmpty())
			return pFront->data;
		else
			throw SingleLinkedListException("List is Empty");
	}
	//return element at the end of the list
	_T back() {
		if (!isEmpty())
			return pBack->data;
		else
			throw SingleLinkedListException("List is Empty");
	}
public:
	//delete an item from the top of the list
	void pop_front() {
		if (!isEmpty()) {
			Node<_T>* temp = pFront;
			pFront = pFront->next;
			delete temp;
		}
		else
			throw SingleLinkedListException("List is Empty");
	}
	//add an item to the end of the list
	void push_back(const _T& item) {
		this->count++;

		Node<_T>* node = new Node<_T>(item);
		if (!pBack)
			pFront = pBack = node;
		else {
			pBack->next = node;
			pBack = node;
		}
	}
	//add an item to the begin of the list
	void push_front(const _T& item) {
		this->count++;

		Node<_T>* node = new Node<_T>(item);

		if (!pFront)
			pFront = pBack = node;
		else {
			node->next = pFront;
			pFront = node;
		}
	}
	//does the list contain elements
	bool isEmpty() const {
		return pFront == pBack;
	}
	//clear the list
	void clear() {
		for (; !this->isEmpty() ;)
			this->pop_front();
	}
	//does the item exist in the list
	bool contain(const _T& item) const {
		Node<_T>* temp = pFront;
		bool isFound = false;
		
		while (temp = temp->next) {
			if (temp->data == item) {
				isFound = true;
				break;
			}
		}
		return isFound;
	}
public:
	SingleLinkedList() :
		count(0),
		pBack(nullptr),
		pFront(nullptr) { }
	SingleLinkedList(const std::initializer_list<_T>& data)
	{
		for (auto i : data)
			this->push_back(i);
	}
	~SingleLinkedList() { }
};
