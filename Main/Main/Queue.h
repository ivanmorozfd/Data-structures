#pragma once
#include <exception>
#include <string>
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
private:
	Node<T>* pFront;
	Node<T>* pBack;
	unsigned count;
	unsigned getSize() const { return this->count; }
	T front()
	{
		if (!isEmpty())
			return pFront->data;
		else
			throw QueueException("Queue is Empty");
	}
	T back()
	{
		if (!isEmpty())
			return pBack->data;
		else
			throw QueueException("Queue is Empty");
	}
public:
	void pop() 
	{
		if (!isEmpty())
		{
			Node<T>* temp = pBack;
			pBack = pBack->next;
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
			pFront = pBack = node;
		}
		else
		{
			pFront->next = node;
			pFront = node;
		}
	}
	bool isEmpty() {
		return pFront == pBack;
	}
public:
	Queue() :count(0),pBack(nullptr),pFront(nullptr) { pBack = pFront; }
	Queue(std::initializer_list<T> data) 
	{ 
		for (auto i : data)
		{
			this->push(i);
		}
	}
	~Queue() { }
};
