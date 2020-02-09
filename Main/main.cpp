#include <iostream>
#include "Main/DoubleLinkedList.h"
int main() {
	DoubleLinkedList<int> list;
	list.push_back(5);
	list.push_back(7);
	DoubleLinkedList<int>::iterator it1 = list.begin();
	std::cout << *it1;
	return 0;
}