#pragma once
#include <iterator>
#include "DoubleLinkedListIterator.h"
#include "DoubleLinkedListExceptions.h"
using std::iterator;
template<typename _T>
class DoubleLinkedList 
{		
	template<typename _T>
	class Node
	{
	public:
		_T value;
		Node<_T>* prev;
		Node<_T>* next;
	};
public:
	typedef DoubleLinkedListIterator<_T> iterator;
	typedef DoubleLinkedListIterator<const _T> const_iterator;
public:
	DoubleLinkedList<_T>::iterator begin()
	{
		return iterator(head);
	}
	DoubleLinkedList<_T>::iterator end()
	{
		return iterator(tail->next);
	}
	DoubleLinkedList<_T>::const_iterator begin() const
	{
		return const_iterator(begin());
	}
	DoubleLinkedList<_T>::const_iterator end() const
	{
		return const_iterator(end());
	}
private:														
	unsigned int count;								
	Node<_T>* head;										
	Node<_T>* tail;										
	bool is_empty() 
	{
		return !head;
	}
public:
	_T pop_back() 
	{
		if (!is_empty()) 
		{
			int returnValue = tail->value;
			Node<_T>* tmp_tail = tail;
			tail = tail->prev;
			delete tmp_tail;
			return returnValue;
		}
		else
			throw DoubleLinkedListException("List is empty");
	}
	_T  pop_front() 
	{
		if (!is_empty()) 
		{
			int returnValue = head->value;
			Node<_T>* tmp_head = head;
			head = head->next;
			delete tmp_head;
			return returnValue;
		}
		else
			throw DoubleLinkedListException("List is empty");
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
			count++; }
		else 
		{ 
			tmp->next = nullptr;
			head = tail = tmp;
			count++; 
		};
	}
	void reverse() 
	{
		Node<_T>* iter = head;
		Node<_T>* temp;
		while (iter)
		{
			// Swap the prev/next pointer
			temp = iter->prev;
			iter->prev = iter->next;
			iter->next = temp;
			// Increment the iter, use prev since the pointers have been reversed
			iter = iter->prev;
		}
		// After swapping all the links, need to reverse the head and tail
		temp = head;
		head = tail;
		tail = temp;
	}
	void erase(const int& pos) 
	{
		Node<_T>* tmp_tail = tail;
		int tmp_count = count;
		if (pos > tmp_count) 
			throw DoubleLinkedListException("Out of range");
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
				Node<_T>* beforeDel = tmp_tail->prev;
				Node<_T>* afterDel = tmp_tail->next;
				beforeDel->next = afterDel;
				afterDel->prev = beforeDel;
				count--;
				delete tmp_tail;
			}
			else
				throw DoubleLinkedListException("List is empty");
		}
	}
	void changeEl(const _T& item, int pos) 
	{
		Node<_T>* tmp = tail;
		int tmp_c(count);
		if (pos > tmp_c) 
			throw DoubleLinkedListException("Out of range"); 

		else 
		{
			if (pos == tmp_c) 
				tail->value = item; 
			if (pos == 0) 
				head->value = item; 
			if (pos < tmp_c) 
			{
				while (pos < tmp_c) 
				{
					tmp = tmp->prev;
					tmp_c--;
				}
				tmp->value = item;
			}
		}
	}
	void insert(const _T& item, int pos) 
	{
		Node<_T>* tmp_1 = tail;
		int tmp_c = count;
		if (pos == tmp_c) { push_back(item); }
		if (pos == 1) { push_front(item); }
		if (pos > tmp_c)
			throw DoubleLinkedListException("Out of range");
		else 
		{
			if (pos < tmp_c) 
			{
				while (pos < tmp_c) 
				{
					tmp_1 = tmp_1->prev;
					tmp_c--;
				}
				Node<_T>* prevIns = tmp_1->prev;
				Node<_T>* tmp_2 = new Node<_T>();
				tmp_2->value = item;
				tmp_2->next = tmp_1;
				tmp_2->prev = prevIns;
				tmp_1->prev = tmp_2;
				count++;
			}
		}
	}
	public:
	DoubleLinkedList():
		head(nullptr),
		tail(nullptr),
		count(0) {}
	~DoubleLinkedList() {}
};
