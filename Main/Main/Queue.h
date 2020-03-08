#pragma once
#include "QueueException.h"

template<typename T>
class Queue 
{
private:
	template<typename T>
	class Node
	{
	public:
		T data;
		Node* next;
		Node() :
			data(T()),
			next(nullptr) { }
	};
private:
	Node<T>* pFront;
	Node<T>* pBack;
	unsigned count;
	unsigned getSize() const 
	{ 
		return this->count; 
	}
	T front()
	{
		if (!isEmpty())
			return this->pFront->data;
		else
			throw QueueException("Queue is Empty");
	}
	T back()
	{
		if (!isEmpty())
			return this->pBack->data;
		else
			throw QueueException("Queue is Empty");
	}
public:
	void pop() 
	{
		if (!isEmpty())
		{
			Node<T>* temp = pBack;
			this->pBack = this->pBack->next;
			delete temp;
		}
		else
			throw QueueException("Queue is Empty");
	}
	void push(T item)
	{
		this->count++;

	    Node<T>* node = new Node<T>;
	    node->data = item;

		if (!pBack)
		{
			this->pFront = this->pBack = node;
		}
		else
		{
			this->pFront->next = node;
			this->pFront = node;
		}
	}
	bool isEmpty()
	{
		return this->pFront == this->pBack;
	}
	void clear()
	{
		for (;isEmpty();)
			this->pop();
	}
public:
	Queue():
		count(0),
		pBack(nullptr),
		pFront(nullptr) 
	{ 
		this->pBack = this->pFront;
	}
	Queue(const std::initializer_list<T>& data) 
	{ 
		for (auto i : data)
			this->push(i);
	}
	~Queue() 
	{
		this->clear();
	}
};
