#pragma once
#include <exception>
#include <string>
#include "SingleLinkedListIterator.h"
using std::string;
using std::exception;

class SingleLinkedListException :exception {
private:
	std::string whatStr;
public:
	const char* what() const noexcept override;
public:
	SingleLinkedListException(std::string&& whatStr) noexcept : whatStr(std::move(whatStr)) { }
	SingleLinkedListException(const std::string& whatStr) noexcept : whatStr(whatStr) { }
	~SingleLinkedListException() noexcept = default;
};
inline const char* SingleLinkedListException::what() const noexcept
{
	return this->whatStr.c_str();
};


template<typename T>
class Node
{
public:
	T data;
	Node* next;
	Node() :data(NULL), next(nullptr) { }
};


template<typename T>
class SingleLinkedList
{
	typedef SingleLinkedListIterator<T> iterator;
	typedef SingleLinkedListIterator<const T> const_iterator;
private:
	Node<T>* pFront;
	Node<T>* pBack;
	unsigned count;
public:
	SingleLinkedList<T>::iterator begin()
	{
		return iterator(pBack);
	}
	SingleLinkedList<T>::iterator end()
	{
		return iterator(pFront->next);
	}
	SingleLinkedList<T>::const_iterator begin() const
	{
		return const_iterator(begin());
	}
	SingleLinkedList<T>::const_iterator end() const
	{
		return const_iterator(end());
	}
public:
	unsigned getSize() const { return this->count; }
	T front()
	{
		if (!isEmpty())
			return pFront->data;
		else
			throw SingleLinkedListException("List is Empty");
	}
	T back()
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
			Node<T>* temp = pBack;
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
			Node<T>* temp = pFront;
			pFront = pFront->prev;
			delete temp;
		}
		else
			throw SingleLinkedListException("List is Empty");
	}
	void push_front(T item)
	{
		this->count++;

		Node<T>* node = new Node<T>;
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
	void push_back(T item)
	{
		this->count++;

		Node<T>* node = new Node<T>;
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
	bool isEmpty() {
		return pFront == pBack;
	}
public:
	SingleLinkedList() :count(0), pBack(nullptr), pFront(nullptr) { pBack = pFront; }
	SingleLinkedList(std::initializer_list<T> data)
	{
		for (auto i : data)
		{
			this->push(i);
		}
	}
	~SingleLinkedList() { }
};
