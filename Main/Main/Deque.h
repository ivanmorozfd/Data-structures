#pragma once
#include "DequeExceptions.h"
template<typename T>
class Node
{
public:
	T value;
	Node<T>* prev;
	Node<T>* next;
};

template<typename T>
class Deque
{
private:
	unsigned int count;
	Node<T>* head;
	Node<T>* tail;
	bool is_empty()
	{
		return !head;
	}
public:
	T pop_back()
	{
		if (!is_empty())
		{
			int returnValue = tail->value;
			Node<T>* tmp_tail = tail;
			tail = tail->prev;
			delete tmp_tail;
			return returnValue;
		}
		else
			throw DequeException("List is empty");
	}
	T  pop_front()
	{
		if (!is_empty())
		{
			int returnValue = head->value;
			Node<T>* tmp_head = head;
			head = head->next;
			delete tmp_head;
			return returnValue;
		}
		else
			throw DequeException("List is empty");
	}
	void push_back(int item)
	{
		Node<T>* tmp = new Node<T>();
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
	void push_front(int item)
	{
		Node<T>* tmp = new Node<T>();
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
	void erase(int pos)
	{
		Node<T>* tmp_tail = tail;
		int tmp_count = count;
		if (pos > tmp_count)
			throw DequeException("Out of range");
		else
		{
			if (tmp_count == pos)
				pop_back();
			if (tmp_count == 1)
				pop_front();
			if (!is_empty())
			{
				while (pos < tmp_count)
				{
					tmp_tail = tmp_tail->prev;
					tmp_count--;
				}
				Node<T>* beforeDel = tmp_tail->prev;
				Node<T>* afterDel = tmp_tail->next;
				beforeDel->next = afterDel;
				afterDel->prev = beforeDel;
				count--;
				delete tmp_tail;
			}
			else
				throw DequeException("List is empty");
		}
	}
public:
	Deque() :
		head(nullptr),
		tail(nullptr),
		count(0) {}
	~Deque() {}
};