#pragma once
template<typename T>
class SingleLinkedList {
private:
	struct Node
	{
		T data;
		Node* next;
	};
	Node* head;
	Node* tail;
	SingleLinkedList():head(nullptr),tail(nullptr) {

	}
	void push_back(T item) {

	}
	void push_front(T item) {

	}
	T pop_back() {

	}
	void insert(T item, int pos) {

	}
	T pop_front() {

	}
	void at(int pos) {

	}
	T remove(int pos) {

	}
};