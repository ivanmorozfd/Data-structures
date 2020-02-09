#pragma once
#include <string>
#include <exception>
#include <iterator>
#include <memory>
#include "DoubleLinkedListIterator.h"
using std::exception;
using std::string;
using std::iterator;

class DoubleLinkedListException : exception
{
private:
	std::string whatStr;
public:
	const char* what() const noexcept override;
public:
	DoubleLinkedListException(std::string&& whatStr) noexcept : whatStr(std::move(whatStr)) { }
	DoubleLinkedListException(const std::string& whatStr) noexcept : whatStr(whatStr) { }
	~DoubleLinkedListException() noexcept = default;
};
inline const char* DoubleLinkedListException::what() const noexcept {
	return this->whatStr.c_str();
}

template<typename T>
class Node
{
public:
	T value = NULL;
	Node<T>* prev = nullptr;
	Node<T>* next = nullptr;
};

template<typename T>
class DoubleLinkedList 
{		
public:
	typedef DoubleLinkedListIterator<T> iterator;
	typedef DoubleLinkedListIterator<const T> const_iterator;
public:
	DoubleLinkedList<T>::iterator begin()
	{
		return iterator(head);
	}
	DoubleLinkedList<T>::iterator end()
	{
		return iterator(tail);
	}
	DoubleLinkedList<T>::const_iterator begin() const
	{
		return const_iterator(begin());
	}
	DoubleLinkedList<T>::const_iterator end() const
	{
		return const_iterator(end());
	}
private:														
	unsigned int count;								
	Node<T>* head;										
	Node<T>* tail;										
	bool is_empty() {
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
			throw DoubleLinkedListException("List is empty");
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
			throw DoubleLinkedListException("List is empty");
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
		Node<T>* iter = head;
		Node<T>* temp = NULL;

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
	void erase(int pos) 
	{
		Node<T>* tmp_tail(tail);
		int tmp_count(count);
		if (pos > tmp_count) 
		{ 
			throw DoubleLinkedListException("Out of range");
		}
		else 
		{
			if (tmp_count == pos) { pop_back(); }
			if (tmp_count == 1) { pop_front(); }
			if (!is_empty())
			{
				while (pos < tmp_count) {
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
				throw DoubleLinkedListException("List is empty");
		}
	}
	void changeEl(int item, int pos) 
	{
		Node<T>* tmp = tail;
		int tmp_c(count);
		if (pos > tmp_c) 
		{ 
			throw DoubleLinkedListException("Out of range"); 
		}
		else 
		{
			if (pos == tmp_c) { tail->value = item; }
			if (pos == 0) { head->value = item; }
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
	void insert(int item, int pos) 
	{
		Node<T>* tmp_1 = tail;
		int tmp_c = count;
		if (pos == tmp_c) { push_back(item); }
		if (pos == 1) { push_front(item); }
		if (pos > tmp_c) { std::cout << "Input error" << std::endl; }
		else 
		{
			if (pos < tmp_c) 
			{
				while (pos < tmp_c) 
				{
					tmp_1 = tmp_1->prev;
					tmp_c--;
				}
				Node<T>* prevIns = tmp_1->prev;
				Node<T>* tmp_2 = new Node<T>();
				tmp_2->value = item;
				tmp_2->next = tmp_1;
				tmp_2->prev = prevIns;
				tmp_1->prev = tmp_2;
				count++;
			}
		}
	}
	void printlist() {
		Node<T>* tmp_tail(tail);
		int tmp_count(count);
		std::cout << tail->value;
		while (tmp_count)
		{
			tmp_tail = tmp_tail->prev;
			if (tmp_tail == nullptr) break;
			std::cout << std::endl;
			std::cout << tmp_tail->value << std::endl;
			tmp_count--;
		}
	}
public:
	DoubleLinkedList():
		head(nullptr),
		tail(nullptr),
		count(0) {}
	~DoubleLinkedList() {}
};