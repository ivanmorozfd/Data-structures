#pragma once
#include <iterator>
#include "DoubleLinkedListIterator.h"
#include "DoubleLinkedListExceptions.h"
using std::iterator;
template<typename _T>
class DoubleLinkedList {
	friend DoubleLinkedListIterator<_T>;
	template<typename _T>
	class Node {
	public:
		_T value;
		Node<_T>* prev;
		Node<_T>* next;
		Node(const _T& item) : value(item),
			prev(nullptr),
			next(nullptr) {}
	};
public:
	typedef DoubleLinkedListIterator<_T> iterator;
	typedef DoubleLinkedListIterator<const _T> const_iterator;
public:
	DoubleLinkedList<_T>::iterator begin() {
		return iterator(begin());
	}
	DoubleLinkedList<_T>::iterator end() {
		return iterator(end());
	}
	DoubleLinkedList<_T>::const_iterator begin() const {
		return const_iterator(begin());
	}
	DoubleLinkedList<_T>::const_iterator end() const {
		return const_iterator(end());
	}
private:														
	unsigned int count;								
	Node<_T>* pFront;										
	Node<_T>* pBack;										
public:
	bool is_empty()  const {
		return !this->pFront;
	}
	_T front() const {
		return pFront->value;
	}
	_T back() const {
		return pBack->value;	
	}
	void pop_back() {
		if (!is_empty()) {
			Node<_T>* tmp = this->pBack;
			this->pBack = this->pBack->prev;
			delete tmp;
		}
		else
			throw DoubleLinkedListException("List is empty");
	}
	void  pop_front() {
		if (!is_empty()) {
			Node<_T>* tmp = this->pFront;
			this->pFront = this->pFront->next;
			delete tmp;
		}
		else
			throw DoubleLinkedListException("List is empty");
	}
	void push_back(const _T& item) {
		Node<_T>* tmp = new Node<_T>(item);
		this->count++;
		if (this->pFront){ 
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
			count++;
		}
		else
			this->pFront = this->pBack = tmp;
	}
	void clear() {
		while (!this->is_empty())
			this->pop_back();
	}
	void reverse() 
	{
		//TODO REWORK WITH ITERATORS
	//	Node<_T>* iter = this->pFront;
	//	Node<_T>* temp;
	//	while (iter)
	//	{
	//		// Swap the prev/next pointer
	//		temp = iter->prev;
	//		iter->prev = iter->next;
	//		iter->next = temp;
	//		// Increment the iter, use prev since the pointers have been reversed
	//		iter = iter->prev;
	//	}
	//	// After swapping all the links, need to reverse the this->pFront and this->pBack
	//	temp = this->pFront;
	//	this->pFront = this->pBack;
	//	this->pBack = temp;
	}
	void erase(const int& pos) 
	{
		//REWORK WITH ITERATORS
		//	Node<_T>* tmp_tail = this->pBack;
		//	int tmp_count = count;
		//	if (pos > tmp_count) 
		//		throw DoubleLinkedListException("Out of range");
		//	else 
		//	{
		//		if (tmp_count == pos) 
		//			pop_back();
		//		if (tmp_count == 1)  
		//			pop_front(); 
		//		if (!is_empty())
		//		{
		//			while (pos < tmp_count) 
		//			{
		//				tmp_tail = tmp_tail->prev;
		//				tmp_count--;
		//			}
		//			Node<_T>* beforeDel = tmp_tail->prev;
		//			Node<_T>* afterDel = tmp_tail->next;
		//			beforeDel->next = afterDel;
		//			afterDel->prev = beforeDel;
		//			count--;
		//			delete tmp_tail;
		//		}
		//		else
		//			throw DoubleLinkedListException("List is empty");
		//	}
	}
	void changeEl(const _T& item, int pos) 
	{
		//REPLASE ITERATORS NEED
		//Node<_T>* tmp = this->pBack;
		//int tmp_c(count);
		//if (pos > tmp_c) 
		//	throw DoubleLinkedListException("Out of range"); 

		//else 
		//{
		//	if (pos == tmp_c) 
		//		this->pBack->value = item; 
		//	if (pos == 0) 
		//		this->pFront->value = item; 
		//	if (pos < tmp_c) 
		//	{
		//		while (pos < tmp_c) 
		//		{
		//			tmp = tmp->prev;
		//			tmp_c--;
		//		}
		//		tmp->value = item;
		//	}
		//}
	}
	void insert(const _T& item, int pos) 
	{
		//INSERT ITERATORS IMPLEMENTATION
		//Node<_T>* tmp_1 = this->pBack;
		//int tmp_c = count;
		//if (pos == tmp_c) { push_back(item); }
		//if (pos == 1) { push_front(item); }
		//if (pos > tmp_c)
		//	throw DoubleLinkedListException("Out of range");
		//else 
		//{
		//	if (pos < tmp_c) 
		//	{
		//		while (pos < tmp_c) 
		//		{
		//			tmp_1 = tmp_1->prev;
		//			tmp_c--;
		//		}
		//		Node<_T>* prevIns = tmp_1->prev;
		//		Node<_T>* tmp_2 = new Node<_T>();
		//		tmp_2->value = item;
		//		tmp_2->next = tmp_1;
		//		tmp_2->prev = prevIns;
		//		tmp_1->prev = tmp_2;
		//		count++;
		//	}
		//}
	}
	public:
	DoubleLinkedList():
		pFront(nullptr),
		pBack(nullptr),
		count(0) {}
	~DoubleLinkedList() {}
};
