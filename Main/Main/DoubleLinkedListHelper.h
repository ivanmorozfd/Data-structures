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
		
	}
	template<class T>
	static void writeToFile(DoubleLinkedList<T> * list, std::ofstream& os) {

	}
	template<class T>
	static DoubleLinkedList<T>* readFromFile(std::ifstream& inputStream) {

	}
	template<class T>
	static void sort_list(DoubleLinkedList<T>* list) {

	}
};