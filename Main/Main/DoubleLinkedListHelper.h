#pragma once
#include "DoubleLinkedList.h"
#include "HelperBase.h"
class DoubleLinkedListHelper:public virtual HelperBase {
	DoubleLinkedListHelper() = default;
	~DoubleLinkedListHelper() = default;
public:
	template<class T>
	static void print_list(DoubleLinkedList<T> * list) {
		_ListNode<T>* temp = list->pFront;
		do {
			std::cout << temp->value << " ";
		} while (temp = temp->next);
		std::cout << std::endl;
	}
	template<class T>
	static void writeToFile(DoubleLinkedList<T> * list, std::ofstream& outStream) {
		_ListNode<T>* tmp = list->pFront;
		do {
			outStream << tmp->value << " ";
		} while (tmp = tmp->next);
	}
	template<class T>
	static DoubleLinkedList<T>* readFromFile(std::ifstream& inputStream) {
		DoubleLinkedList<T>* list = new DoubleLinkedList<T>();
		while (!inputStream.eof()) {
			T a;
			inputStream >> a;
			list->push_back(a);
		}
		return list;
	}
};