#pragma once
#include "core.h"
#include "Container.h"
#include <iterator>
#include "DoubleLinkedListIterator.h"
#include "DoubleLinkedListExceptions.h"
using std::iterator;
/*!
	Data representation in DoubleLinkedList
	Contain pointer to previous element,next element and data
	\brief DoubleLinkedList element wrapper
	\author ivanmorozfd
	\version 1.0
	\date April 2020
*/
template<typename _T>
struct _ListNode {
	typedef _ListNode* NodePtr;//!< Node pointer
	using valueType = _T;//!< Element type
	using reference = valueType&;//!< Reference element type
	using const_reference = const valueType&;
public:
	valueType value;//!< Node value
	NodePtr prev;//!< Pointer to previous Node
	NodePtr next;//!< Pointer to next Node
public:
	_ListNode(const _ListNode&) = delete;
	_ListNode& operator=(const _ListNode&) = delete;
public:
	/*!
		Default _StackNode constructor
	*/
	_ListNode() = default;
	/*!
		Parameterized _StackNode constructor
		\param[in] valueType& Node data
	*/
	_ListNode(const_reference data) :
		value(data),
		prev(nullptr),
		next(nullptr) {}
};

/*!
	DoubleLinkedList class
	\brief Use to store data
	\author ivanmorozfd
	\version 1.0
	\date April 2020
*/
template<typename _T>
class DoubleLinkedList : public Container {	
private:
	using valueType = _T;// Element type
	using reference = valueType&;// Reference element type
	using NodePtr = _ListNode<_T>*;// Pointer node type
	using NodeRef = _ListNode<_T>;// Reference node type
public:
	friend DoubleLinkedListIterator<_T>;
public:
	typedef DoubleLinkedListIterator<_T> iterator; //!< iterator for DoubleLinkedList
	typedef DoubleLinkedListIterator<const _T> const_iterator; //!< const iterator for DoubleLinkedList
public:
	/*!
		Returns an const iterator to the beginning
	*/		
	DoubleLinkedList<_T>::iterator begin() {
		return iterator(pFront);
	}
	/*!
		Returns an iterator to the end
	*/
	DoubleLinkedList<_T>::iterator end() {
		return iterator(pBack->next);
	}
	/*!
		Returns an const iterator to the beginning
	*/
	DoubleLinkedList<_T>::const_iterator begin() const {
		return const_iterator(pFront);
	}
	/*!
		Returns an const iterator to the end
	*/
	DoubleLinkedList<_T>::const_iterator end() const {
		return const_iterator(pBack->next);
	}
	/*!
		Returns an reversed iterator to the beginning
	*/
	DoubleLinkedList<_T>::iterator rbegin() {
		return iterator(end());
	}
	/*!
		Returns an reversed iterator to the end
	*/
	DoubleLinkedList<_T>::iterator rend() {
		return iterator(begin());
	} 
private:														
	size_t count;//
	NodePtr pFront;//pointer to the list beginning										
	NodePtr pBack;//pointer to the list end
public:
	/*!
		Checks whether the list is empty
		\param[out] bool True,if DoubleLinkedList is empty,otherwise False
	*/
	bool isEmpty()  const override {
		return !this->pFront;
	}
	/*!
		Returns the first element
		\param[out] valueType
	*/
	valueType front() const {
		return pFront->value;
	}
	/*!
		Returns the last element
		\param[out] valueType
	*/
	valueType back() const {
		return pBack->value;	
	}
	/*!
		Removes the last element
	*/
	void pop_back() {
		if (!isEmpty()) {
			NodePtr tmp = this->pBack;
			this->pBack = this->pBack->prev;
			delete tmp;
		}
		else
			throw DoubleLinkedListException("List is empty");
	}
	/*!
		Removes the first element
	*/
	void  pop_front() {
		if (!isEmpty()) {
			NodePtr tmp = this->pFront;
			this->pFront = this->pFront->next;
			delete tmp;
		}
		else
			throw DoubleLinkedListException("List is empty");
	}
	/*!
		Adds element to the end
		\param valueType item
	*/
	void push_back(const _T& item) {
		NodePtr tmp = new NodeRef(item);
		this->count++;
		if (this->pBack){ 
			tmp->prev = this->pBack;
			this->pBack->next = tmp;
			this->pBack = tmp;
		}
		else 
			this->pFront = this->pBack = tmp;
	}
	/*!
		Adds element to the beginning
		\param valueType item
	*/
	void push_front(const _T& item) {
		NodePtr tmp = new NodeRef(item);
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
	/*!
		Clear the contents
	*/
	void clear() {
		while (!this->isEmpty())
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
	DoubleLinkedList(std::initializer_list<valueType>& data) {
		for (auto i : data)
			this->push_back(i);
	}
	~DoubleLinkedList() {}
};
