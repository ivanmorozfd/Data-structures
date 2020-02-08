#pragma once
/* Simple stack implementation with C++
Stack is a linear data structure which follows a particular order in which the operations are performed.
The order may be LIFO(Last In First Out) or FILO(First In Last Out).
*/
/*	Big O-notation
Time complexity
Operation		Average			Worst

Access			O(n)			O(n)
Search			O(n)			O(n)
Insertion		O(1)			O(1)
Deletion		O(1)			O(1)
*/
/*
Usage:
1)Infix to postfix 
2)Prefix to infix Conversion
3)Prefix to postfix Conversion
4)Postfix to prefix conversion
5)Postfix to Infix
6)Convert Infix To Prefix Notation
7)The Stock Span Problem
8)Expression Evaluation
9)Arithmetic Expression Evalution
10)Evaluation of Postfix Expression
*/
template<typename T>
class Stack
{
private:
	//This structure contain data and pointer to previous node
	struct Node
	{
		T data;
		Node* prev;
	};
	Node* m_top;
public:
	Stack() {
		m_top = nullptr;
	}
	T getTop() const {
		return m_top->data;
	}
	bool isEmpty() const {
		return m_top;
	}
	void push(T item){
		Node* tmp = new Node();
		tmp->data = item;
		tmp->prev = m_top;
		m_top = tmp;
	}
	T pop() {
		if (isEmpty()) {
			Node* tmp = new Node();
			int returnData = m_top->data;
			tmp = m_top;
			m_top = m_top->prev;
			delete tmp;
			return returnData;
		}
		else {
			std::cout << "Stack is empty,pop error";
			return -1;
		}
	}
};

