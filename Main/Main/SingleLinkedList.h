#pragma once
#include "SingleLinkedListIterator.h"
#include "SingleLinkedListException.h"
using std::initializer_list;
template<typename _T>
class SingleLinkedList
{
	template<typename _T>
	class Node
	{
	public:
		_T data;
		Node* next;
		Node() :data(_T()), next(nullptr) { }
	};
	typedef SingleLinkedListIterator<_T> iterator;
	typedef SingleLinkedListIterator<const _T> const_iterator;
private:
	Node<_T>* pFront;
	Node<_T>* pBack;
	unsigned count;
public:
	SingleLinkedList<_T>::iterator begin()
	{
		return iterator(pBack);
	}
	SingleLinkedList<_T>::iterator end()
	{
		return iterator(pFront->next);
	}
	SingleLinkedList<_T>::const_iterator begin() const
	{
		return const_iterator(begin());
	}
	SingleLinkedList<_T>::const_iterator end() const
	{
		return const_iterator(end());
	}
public:
	unsigned getSize() const 
	{ 
		return this->count;
	}
	_T front()
	{
		if (!isEmpty())
			return pFront->data;
		else
			throw SingleLinkedListException("List is Empty");
	}
	_T back()
	{
		if (!isEmpty())
			return pBack->data;
		else
			throw SingleLinkedListException("List is Empty");
	}
public:
	void pop_back()
	{
		if (!isEmpty())
		{
			Node<_T>* temp = pBack;
			pBack = pBack->next;
			delete temp;
		}
		else
			throw SingleLinkedListException("List is Empty");
	}
	void pop_front()
	{
		if (!isEmpty())
		{
			Node<_T>* temp = pFront;
			pFront = pFront->prev;
			delete temp;
		}
		else
			throw SingleLinkedListException("List is Empty");
	}
	void push_front(const _T& item)
	{
		this->count++;

		Node<_T>* node = new Node<_T>;
		node->data = item;
		if (!pFront)
		{
			pFront = pBack = node;
		}
		else
		{
			pFront->next = node;
			pFront = node;
		}
	}
	void push_back(const _T& item)
	{
		this->count++;

		Node<_T>* node = new Node<_T>;
		node->data = item;
		if (!pBack)
		{
			pFront = pBack = node;
		}
		else
		{
			node->next = pBack;
			pBack = node;
		}
	}
	bool isEmpty() 
	{
		return pFront == pBack;
	}
public:
	SingleLinkedList() :
		count(0),
		pBack(nullptr),
		pFront(nullptr) 
	{ 
		pBack = pFront;
	}
	SingleLinkedList(const std::initializer_list<_T>& data)
	{
		for (auto i : data)
			this->push(i);
	}
	~SingleLinkedList() { }
};
