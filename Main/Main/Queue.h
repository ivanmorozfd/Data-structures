#pragma once
#include <exception>
#include <string>
#include <queue>
#include "QueueIterator.h"
using std::queue;
using std::string;
using std::exception;

class QueueException:exception {
private:
	std::string whatStr;
public:
	const char* what() const noexcept override;
public:
	QueueException(std::string&& whatStr) noexcept : whatStr(std::move(whatStr)) { }
	QueueException(const std::string& whatStr) noexcept : whatStr(whatStr) { }
	~QueueException() noexcept = default;
};
inline const char* QueueException::what() const noexcept 
{
	return this->whatStr.c_str();
};


template<typename T>
class Node
{
public:
	T data;
	Node* next;
	Node() :data(NULL), next(nullptr){ }
};


template<typename T>
class Queue 
{
	typedef QueueIterator<T> iterator;
	typedef QueueIterator<const T> const_iterator;
private:
	Node<T>* pFront;
	Node<T>* pBack;
	unsigned count;
public:
	Queue<T>::iterator begin()
	{
		return iterator(pBack);
	}
	Queue<T>::iterator end()
	{
		return iterator(pFront->next);
	}
	Queue<T>::const_iterator begin() const
	{
		return const_iterator(begin());
	}
	Queue<T>::const_iterator end() const
	{
		return const_iterator(end());
	}
public:
	unsigned getSize() const { return this->count; }
	T front()
	{
		if (!empty())
			return pFront->data;
		else
			throw QueueException("Queue is empty");
	}
	T back()
	{
		if (!empty())
			return pBack->data;
		else
			throw QueueException("Queue is empty");
	}
public:
	void pop() 
	{
		if (!empty())
		{
			Node<T>* temp = pBack;
			pBack = pBack->next;
			delete temp;
		}
		else
			throw QueueException("Queue is empty");
	}
	void push(T item)
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
			pFront->next = node;
			pFront = node;
		}
	}
	bool empty() {
		return pFront == pBack;
	}
public:
	Queue() { pBack = pFront; }
	Queue(std::initializer_list<T> data) 
	{ 
		for (auto i : data)
		{
			this->push(i);
		}
	}
	~Queue() { }
};
