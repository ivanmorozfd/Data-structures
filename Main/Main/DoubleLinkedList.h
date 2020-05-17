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
	using const_reference = const _T&;//!< Const reference element type
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
		return const_iterator(begin());
	}
	/*!
		Returns an const iterator to the end
	*/
	DoubleLinkedList<_T>::const_iterator end() const {
		return const_iterator(end());
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
private:
	void removeNode(NodePtr pNode) {
		//Remove begin item
		if (pBack == pNode) {
			pop_back();
			return;
		}
		//Remove end item
		if (pFront == pNode) {
			pop_front();
			return;
		}
		//catch next and prev item
		NodePtr beforeDel = pNode->prev;
		NodePtr afterDel = pNode->next;
		//remove links
		beforeDel->next = afterDel;
		afterDel->prev = beforeDel;
		//free node memory
		delete pNode;
	}
public:
	size_t getSize() const {
		return this->count;
	}
	/*!
		Checks whether the list is empty
		\param[out] bool True,if DoubleLinkedList is empty,otherwise False
	*/
	bool isEmpty()  const override {
		return !this->pFront ;
	}
	/*!
		Returns the first element
		\param[out] valueType
	*/
	valueType front() const {
		if (!isEmpty())
			return pFront->value;
		else
			throw DoubleLinkedListException("List is empty");
	}
	/*!
		Returns the last element
		\param[out] valueType
	*/
	valueType back() const {
		if (!isEmpty())
			return pBack->value;	
		else
			throw DoubleLinkedListException("List is empty");
	}
	/*!
		Removes the last element
	*/
	void pop_back() {
		if (!isEmpty()) {
			if (this->pFront == this->pBack) {
				this->pFront = nullptr;
			}
			NodePtr tmp = this->pBack;
			this->pBack = this->pBack->prev;
			this->count--;
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
			if (this->pFront == this->pBack)
				this->pBack = nullptr;

			NodePtr tmp = this->pFront;
			this->pFront = this->pFront->next;
			this->count--;
			delete tmp;
		}
		else
			throw DoubleLinkedListException("List is empty");
	}
	/*!
		Adds element to the end
		\param valueType item
	*/
	void push_back(const_reference item) {
		NodePtr tmp = new NodeRef(item);
		this->count++;
		if (this->pBack) { 

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
	void push_front(const_reference item) {
		NodePtr tmp = new NodeRef(item);
		this->count++;
		if (this->pFront) {
			tmp->next = this->pFront;
			this->pFront->prev = tmp;
			this->pFront = tmp;
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
	/*!
		Reverse list content
	*/
	void reverse() {
		//Set temporal varialable for front
		const NodePtr _pFront = pFront;
		//Marker for travesing the array
	    NodePtr _pNode = _pFront;
		for (;;) {
			//swap two pointers
			const NodePtr _pNext = _pNode->next;
			_pNode->next = _pNode->prev;
			_pNode->prev = _pNext;
			//if reach end then swap front and back pointers
			if (_pNode == pBack) {
				std::swap(pBack, pFront);
				break;
			}
			//else move marker
			_pNode = _pNext;
		}
	}
	/*!
		Remove element from list by position
		\param[in] size_t Position in list
	*/
	void erase(size_t pos) {
		NodePtr pNode = this->pFront;

		//Pos must be positive number less than items count
		if (this->count < pos)
			throw DoubleLinkedListException("Out Of range");
		if (pos < 0)
			throw DoubleLinkedListException("Position must be positive number");

		if (this->isEmpty())
			throw DoubleLinkedListException("List is empty");
		//access delete item
		while (pos > 0) {
			pos--;
			pNode = pNode->next;
		}
		//Remove node
		removeNode(pNode);
		count--;
		return;
	}
	/*!
		Remove element from list by positions
		\param[in] beg Begin position
		\param[in] end End  position
	*/
	void erase(size_t beg,size_t end) {
		NodePtr pNode = this->pFront;

		//End position must be positive number less than items count
		if (this->count < end)
			throw DoubleLinkedListException("Out Of range");
		//Begin position must be positive number
		if (beg < 0)
			throw DoubleLinkedListException("Begin position must be positive number");
		//Begin position must be less than end positive
		if (beg > end)
			throw DoubleLinkedListException("End position must be greater than begin position");
		//If begin pos equal to end position call 1 arg method
		if (beg == end) {
			erase(end);
			return;
		}
		if (this->isEmpty())
			throw DoubleLinkedListException("List is empty");
		//access delete items
		size_t i = 0;
		while (i < beg) {
			i++;
			pNode = pNode->next;
		}
		//remove all items in range
		while (beg <= end) {
			NodePtr _remove = pNode;
			pNode = pNode->next;
			beg++;
			removeNode(_remove);
			count--;
		}
	}
	/*!
		Replase element in list
		\param[in] item value
		\param[in] position to replace
	*/
	void replase(const_reference item, size_t pos) {
		NodePtr pNode = pFront;
		//Pos must be positive number less than items count
		if (this->count < pos)
			throw DoubleLinkedListException("Out Of range");
		if (pos < 0)
			throw DoubleLinkedListException("Position must be positive number");

		if (this->isEmpty())
			throw DoubleLinkedListException("List is empty");

		while (pos > 0) {
			pos--;
			pNode = pNode->next;
		}

		pNode->value = item;
	}
	/*!
		Insert item to list
		\param[in] item value
		\param[in] position to insert
	*/
	void insert(const_reference item, size_t pos) {
		NodePtr pNode = pFront;
		//Pos must be positive number less than items count
		if (this->count < pos)
			throw DoubleLinkedListException("Out Of range");
		if (pos < 0)
			throw DoubleLinkedListException("Position must be positive number");

		if (this->isEmpty())
			throw DoubleLinkedListException("List is empty");

		if (this->count == pos + 1) {
			push_back(item);
			return;
		}
		if (pos == 0) {
			push_front(item);
			return;
		}
		while (pos > 0) {
			pos--;
			pNode = pNode->next;
		}
		NodePtr insertSuccessor = pNode->prev;
		NodePtr pCreate = new NodeRef(item);
		
		insertSuccessor->next = pCreate;

		pCreate->next = pNode;
		pCreate->prev = insertSuccessor;
		pNode->prev = pCreate;
		
		this->count++;
	}
	public:
	DoubleLinkedList(): pFront(nullptr),
		pBack(nullptr),
		count(0) {}
	DoubleLinkedList(const std::initializer_list<valueType>& data): count(0),
		pBack(nullptr),
		pFront(nullptr) {
		for (auto i : data)
			this->push_back(i);
	}
	~DoubleLinkedList() {}
};
