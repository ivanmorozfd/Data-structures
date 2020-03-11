#pragma once
#include "DequeExceptions.h"
template<typename _T>
class Node
{
public:
	_T value;
	Node<_T>* prev;
	Node<_T>* next;
};

template<typename _T>
class Deque
{
private:
	unsigned int count;
	Node<_T>* head;
	Node<_T>* tail;
	bool is_empty()
	{
		return !head;
	}
public:
	_T peekHead() const
	{
		if(!is_empty())
			return head->value;
		else
			throw DequeException("Deque is empty");
	}
	_T peekTail() const
	{
		if(!is_empty())
			return tail->value;
		else
			throw DequeException("Deque is empty");
	}
	void pop_back()
	{
		if (!is_empty())
		{
			Node<T>* tmp_tail = tail;
			tail = tail->prev;
			delete tmp_tail;
		}
		else
			throw DequeException("Deque is empty");
	}
	void  pop_front()
	{
		if (!is_empty())
		{
			Node<T>* tmp_head = head;
			head = head->next;
			delete tmp_head;
		}
		else
			throw DequeException("Deque is empty");
	}
	void push_back(const _T& item)
	{
		Node<_T>* tmp = new Node<_T>();
		tmp->next = nullptr;
		tmp->value = item;
		if (head)
		{
			tmp->prev = tail;
			tail->next = tmp;
			tail = tmp;
			count++;
		}
		else
		{
			tmp->prev = nullptr;
			head = tail = tmp;
			count++;
		}
	}
	void push_front(const _T& item)
	{
		Node<_T>* tmp = new Node<_T>();
		tmp->prev = nullptr;
		tmp->value = item;
		if (head)
		{
			tmp->next = head;
			head->prev = tmp;
			head = tmp;
			count++;
		}
		else
		{
			tmp->next = nullptr;
			head = tail = tmp;
			count++;
		};
	}
	void clear()
	{
		for(;!is_empty();)
			pop_front();
	}
public:
	Deque() :
		head(nullptr),
		tail(nullptr),
		count(0) 
		{
			//Init deque
		}
	Deque(const std::initializer_list<_T>& data)
	{
		
	}
	Deque(const Deque& other)
	{
		
	}
	~Deque() 
	{
		this->clear();
	}
};
