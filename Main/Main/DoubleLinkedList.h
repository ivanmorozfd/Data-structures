#pragma once
#include <iostream>
#include<Windows.h>
template<typename T>
class DoubleLinkedLIst {							
													
private:											
	struct Node {									
		T value = NULL;							
		Node* prev = nullptr;					
		Node* next = nullptr;					
	};												
	unsigned int count;								
	Node* head;										
	Node* tail;										
	bool is_empty() {
		return !head;
	}
public:
	DoubleLinkedLIst() :head(nullptr), tail(nullptr), count(0) {}
	~DoubleLinkedLIst() {}
	T* pop_back() {
		if (!is_empty()) {
			int* tmp_val = new int(tail->value);
			Node* tmp_tail(tail);
			tail = tail->prev;
			delete tmp_tail;
			return tmp_val;
		}
		return nullptr;
	}
	T* pop_front() {
		if (!is_empty()) {
			int* tmp_val = new int(head->value);
			Node* tmp_head = head;
			head = head->next;
			delete tmp_head;
			return tmp_val;
		}
	}
	void push_back(int item) {
		Node* tmp = new Node();
		tmp->next = nullptr;
		tmp->value = item;
		if (head != nullptr) { tmp->prev = tail; tail->next = tmp; tail = tmp; count++; }
		else { tmp->prev = nullptr; head = tail = tmp; count++; }
	}
	void push_front(int item) {
		Node* tmp = new Node();
		tmp->prev = nullptr;
		tmp->value = item;
		if (head != nullptr) { tmp->next = head; head->prev = tmp; head = tmp; count++; }
		else { tmp->next = nullptr; head = tail = tmp; count++; };
	}
	void reverse() {
		Node* iter = head;
		Node* temp = NULL;

		while (iter != NULL)
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
	void erase(int pos) {
		Node* tmp_tail(tail);
		int tmp_count(count);
		if (pos > tmp_count) { std::cout << "Input error" << std::endl; }
		else {
			if (tmp_count == pos) { pop_back(); }
			if (tmp_count == 1) { pop_front(); }
			if (!is_empty()) {
				while (pos < tmp_count) {
					tmp_tail = tmp_tail->prev;
					tmp_count--;
				}
				Node* beforeDel = tmp_tail->prev;
				Node* afterDel = tmp_tail->next;
				beforeDel->next = afterDel;
				afterDel->prev = beforeDel;
				count--;
				delete tmp_tail;
			}
		}
	}
	void changeEl(int item, int pos) {
		Node* tmp(tail);
		int tmp_c(count);
		if (pos > tmp_c) { std::cout << "Input error" << std::endl; }
		else {
			if (pos == tmp_c) { tail->value = item; }
			if (pos == 0) { head->value = item; }
			if (pos < tmp_c) {
				while (pos < tmp_c) {
					tmp = tmp->prev;
					tmp_c--;
				}
				tmp->value = item;
			}
		}
	}
	void insert(int item, int pos) {
		Node* tmp_1 = tail;
		int tmp_c = count;
		if (pos == tmp_c) { push_back(item); }
		if (pos == 1) { push_front(item); }
		if (pos > tmp_c) { std::cout << "Input error" << std::endl; }
		else {
			if (pos < tmp_c) {
				while (pos < tmp_c) {
					tmp_1 = tmp_1->prev;
					tmp_c--;
				}
				Node* prevIns = tmp_1->prev;
				Node* tmp_2 = new Node();
				tmp_2->value = item;
				tmp_2->next = tmp_1;
				tmp_2->prev = prevIns;
				tmp_1->prev = tmp_2;
				count++;
			}
		}
	}
	void printlist() {
		Node* tmp_tail(tail);
		int tmp_count(count);
		std::cout << tail->value;
		while (tmp_count != 0)
		{
			tmp_tail = tmp_tail->prev;
			if (tmp_tail == nullptr) break;
			std::cout << std::endl;
			std::cout << tmp_tail->value << std::endl;
			tmp_count--;
		}
	}
};